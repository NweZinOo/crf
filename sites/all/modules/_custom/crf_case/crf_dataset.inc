<?php

function crf_ds_parse($name, $values) {
  $pattern = "/e_{$name}_(\d+)_(\d+)/i";

  $dataset = array();
  foreach ($values as $key => $val) {
    if(preg_match($pattern, $key, $matches)) {
      $row = $matches[1];
      $col = $matches[2];
      $dataset[$row][$col] = $val;
    }
  }
  
  return $dataset;
}

function crf_ds_save($dataset, $name, $p_uid = NULL) {
  if (!$p_uid) {
    $p_uid = crf_common_session('p_uid');
  }
  
  $data  = drupal_to_js($dataset);
  $table =  CRF_DS_TABLE;
  
  $id = db_result(db_query("SELECT id FROM $table WHERE uid = %d AND name = '%s'", $p_uid, $name));
  if ($id) {
    db_query("UPDATE $table SET data = '%s', updated = %d WHERE id = %d",  $data, time(), $id);
  }
  else {
    db_query("INSERT INTO $table (uid, name, data, updated) VALUES (%d, '%s', '%s', %d)", $p_uid, $name, $data, time());
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
