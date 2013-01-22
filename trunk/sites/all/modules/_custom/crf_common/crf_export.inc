<?php
 

function crf_common_export() {
  //header("Content-type:application/csv"); 
  //header("Content-Disposition:\"inline;filename=data.csv\""); 
  
  header('Content-Encoding: UTF-8');
  header('Content-type: text/csv; charset=UTF-8');
  header("Content-Disposition: attachment; filename=export.csv");
  echo "\xEF\xBB\xBF"; // UTF-8 BOM

  crf_common_export_do();
}

function crf_common_export_do() {
  $tmp = file_directory_temp();
  $cache_file = $tmp . '/export.csv';
  
  if (!isset($_GET['flush']) && file_exists($cache_file)) {
    echo $cache_file;
    exit;
  }
  
  include_once drupal_get_path('module', 'crf_case') . '/include/crf_dict_source.php';
  //$crf_el_name['dyxx'];
  
  $header = array(
      'p_uid', 'hospital_no',	'sift', 'p_name',	'p_birthday',	
      'case_history_no', 'approved', 'approved_time',	'team',	'apply_time',	'editor',	'phone');
  
  $sql = 'SELECT * FROM apply';
  $res = db_query($sql);
  while ($row = db_fetch_array($res)) {
    $data[$row['p_uid']] = $row;
  }
  //var_dump($data);
  foreach ($data_crf as $ds_key => $ds_layout) {
    _export_set_header($ds_key, $ds_layout, $header);
    _export_add_data($ds_key, $ds_layout, $header, $data);
  }
  
  //var_dump($header);
  //array_unshift($body, $header);
  $csv =  array_to_scv($data, $header);
  file_put_contents($cache_file, $csv);
  
  echo $csv;
}

function _export_add_data($ds_key, $ds_layout, &$header, &$data) {
  foreach ($data as $uid => &$row) {
    
    $raw_data = json_to_array(crf_ds_load($ds_key, $uid));
    _export_set_row_data($row, $raw_data, $ds_key, $header);
  }
}

function _export_set_row_data(&$row, $raw_data, $ds_key, &$header) {
  foreach ($raw_data as $k => $v) {
    foreach ($v as $m => $n) {
      $el  = "e_{$ds_key}_{$k}_{$m}";
      $pos = array_search($el, $header);
      $row[$pos] = $n;
      //var_dump($el, $pos,  $n);
    }
  }
}

function _export_set_header($ds_key, $ds_layout, &$header) {
  foreach ($ds_layout as $k => $v) {
    foreach ($v as $m => $n) {
      if ($m == '#name') {
        continue;
      }
      $header[] = "e_{$ds_key}_{$k}_{$m}";
    }
  }
}

function crf_common_set_data(&$header, &$item, &$row, &$header_data) {
  $data = json_to_array(json_decode($row['data']));
  $uid  = $row['uid'];
  
  $all  = array(
    'dyxx' => $data, 
    'sf_1' => json_to_array(crf_ds_load('sf_1', $uid)), 
    'sf_2' => json_to_array(crf_ds_load('sf_2', $uid)), 
    'sf_3' => json_to_array(crf_ds_load('sf_3', $uid)), 
    'sf_4' => json_to_array(crf_ds_load('sf_4', $uid)), 
    'sf_5' => json_to_array(crf_ds_load('sf_5', $uid)), 
  );
          
  foreach ($header as $pos => $h) {
    if (in_array($h, array('uid')))      
      continue;
    
    list ($no, $field) = explode('-', $h, 2);
    $keys = crf_search_name_to_key($field, $no);
    if (isset($all[$keys[0]])) {
      $current = $all[$keys[0]];
    //var_dump($keys, $h, $data[$keys[1]][$keys[2]]);
      $current_val = $current[$keys[1]][$keys[2]];
      
      $item[$pos] = _export_deal_value($field, $current_val, $keys, $header_data[$h]);
    }
  }
}

function _export_deal_value($field, $val, $keys, $header_data) {
  global $crf_el;
  
  
  switch ($field) {
    case '是否接受统一随访':
      if ($val == '1') 
        return '否';
      else if ($val === '0' || $val === 0) {
        return '是';
      }
      else return '';
    case '性别':
      return $val == 0 ?  '男' : '女';
    case '姓名缩写':
        return strtoupper($val);
  }
  
  if ($keys) {
    if (   isset($crf_el[$keys[0]])
        && isset($crf_el[$keys[0]][$keys[1]])
        && isset($crf_el[$keys[0]][$keys[1]][$keys[2]])
       ) {
      $el = $crf_el[$keys[0]][$keys[1]][$keys[2]];
      if ($el['#type'] == 'checkboxes') {
        $val = _export_deal_get_checkbox($header_data, $val);
        //if (empty($val)) $val = '无';
      }
      if ($el['#type'] == 'radios') {
        $val = _export_deal_get_radios($header_data, $val);
        //if (empty($val)) $val = '无';
      }
    }
  }
  return $val;
}

function _export_deal_get_radios($header_data, $val) {
  $r = array();
  if (is_null($val)) return $r;
  
  $header_data = array_flip($header_data);
  
  if (is_array($val)) {
    foreach($val as $k => $v) {
      $r[] = $header_data[$val];
    }
  }
  else {
    $r[] = $header_data[$val];
  }
  
  return $r;
}

function _export_deal_get_checkbox($header_data, $val) {
  $r = array();
  if (is_null($val)) return $r;
  
  $header_data = array_flip($header_data);
  
  if (is_array($val)) {
    foreach($val as $k => $v) {
      $r[] = $header_data[$val];
    }
  }
  else {
    $r[] = $header_data[$val];
  }
  
  return $r;
}
/**
* Generatting CSV formatted string from an array.
* By Sergey Gurevich.
*/
function array_to_scv(&$array, &$header_row = null, $col_sep = ",", $row_sep = "\n", $qut = '"')
{
  
	if (!is_array($array)) return false;
	//Header row.
	if ($header_row)
	{
		foreach ($header_row as $key => $val)
		{
      $val = str_replace('dyxx-', '', $val);
      $val = str_replace('sf', '随访', $val);
			//Escaping quotes.
			$key = str_replace($qut, "'", $val);
			$output .= "$col_sep$qut$key$qut";
		}
		$output = substr($output, 1)."\n";
	}
  
	//Data rows.
	foreach ($array as $key => $val)
	{
		$tmp = '';
		foreach ($val as $cell_key => $cell_val)
		{
      if (is_array($cell_val)) $cell_val = join(' ', $cell_val);
			//Escaping quotes.
			$cell_val = str_replace($qut, "'", $cell_val);
			$tmp .= "$col_sep$qut$cell_val$qut";
		}
		$output .= substr($tmp, 1) . $row_sep;
	}
	
	return $output;
}