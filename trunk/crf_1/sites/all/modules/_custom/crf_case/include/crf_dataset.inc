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
    if ($p_uid == "") {
      $p_uid = crf_create_p_uid() + 1;
    }
  }
  global $user;
  $profile =  profile_load_profile($user);
  $hospital_no = $user->profile_hospital_no;
  
  $data  = drupal_to_js($dataset);
  $table =  CRF_DS_TABLE;
  $id = db_result(db_query("SELECT id FROM $table WHERE uid = %d AND name = '%s'", $p_uid, $name));
  if ($id) {
    db_query("UPDATE $table SET data = '%s', updated = %d WHERE id = %d",  $data, time(), $id);
  }
  else {
//    print 'abc';exit;
    db_query("INSERT INTO $table (uid, name, data, updated, hospital_no) VALUES (%d, '%s', '%s', %d, '%s')", $p_uid, $name, $data, time(), $hospital_no);
    crf_common_session('p_uid', $p_uid);
  }
}


function crf_ds_load($name, $p_uid = NULL) {
  if (!$p_uid) {
    $p_uid = crf_common_session('p_uid');
  }
  
  $table =  CRF_DS_TABLE;
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

function crf_ds_s_time($t) {
  return substr($t, 0, 10);
}

function crf_create_p_uid() {
  $query = "select max(uid) from crf_case_data";
  return db_result(db_query($query));
}