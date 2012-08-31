<?php

function crf_ds_parse($name, $values, $form) {
  $pattern = "/e_{$name}_(\d+)_(\d+)/i";

  $dataset = array();
  foreach ($values as $key => $val) {
    if(preg_match($pattern, $key, $matches)) {
      $row = $matches[1];
      $col = $matches[2];
      
      $element_key = "e_{$name}_{$row}_{$col}";
      
      switch ($form[$element_key]['#type']) {
        case 'radios':
          if(strlen($val) == 0) {
            $val = FALSE;
          }
          break;
      }
      
      if ($val !== FALSE) {
        $dataset[$row][$col] = $val;
      }
      
    }
  }
  return $dataset;
}

function crf_ds_save($dataset, $name, $p_uid = NULL) {
  if (!$p_uid) {
    $p_uid = crf_common_session('p_uid');
  }
  
  $data  = drupal_to_js($dataset);
  $table = CRF_DS_TABLE;
  $table_original = CRF_DS_TABLE_ORIG;
  
  $id = db_result(db_query("SELECT id FROM $table WHERE uid = %d AND name = '%s'", $p_uid, $name));
  //var_dump($id); exit;
  if ($id) {
    db_query("UPDATE $table SET data = '%s', updated = %d WHERE id = %d",  $data, time(), $id);
  }
  else {
    db_query("INSERT INTO $table (uid, name, data, updated) VALUES (%d, '%s', '%s', %d)", $p_uid, $name, $data, time());
    db_query("INSERT INTO $table_original (uid, name, data, updated) VALUES (%d, '%s', '%s', %d)", $p_uid, $name, $data, time());
  }
}


function crf_ds_load($name, $p_uid = NULL, $table = CRF_DS_TABLE) {
  if (!$p_uid) {
    $p_uid = crf_common_session('p_uid');
  }
  $data  = db_result(db_query("SELECT data FROM $table WHERE uid = %d AND name = '%s'", $p_uid, $name));

  if ($data && is_string($data)) {
    return json_decode($data);
  }
  else {
    return FALSE;
  }
}

function crf_ds_s_data($name) {
  return $_SESSION['crf']['p_arr'][$name];
}

function crf_ds_delete($name, $p_uid = NULL) {
   if (!$p_uid) {
    $p_uid = crf_common_session('p_uid');
  }
  
  $table = CRF_DS_TABLE;
  $table_o = CRF_DS_TABLE_ORIG;
  $sql = sprintf("DELETE FROM $table WHERE uid = %d AND name = '%s'", $p_uid, $name);
  $sql = sprintf("DELETE FROM $table WHERE uid = %d AND name = '%s'", $p_uid, $name);
  //var_dump($sql); exit;
  return db_query($sql);
}

function crf_ds_s_time($t) {
  return substr($t, 0, 10);
}



