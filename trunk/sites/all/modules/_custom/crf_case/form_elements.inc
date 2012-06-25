<?php

/**
 * All form array put here
 */
function get_form_elements_arr($no) {
  global $crf_el;
  $form_elements_arr = $crf_el;
  
  if (empty($form_elements_arr[$no])) {
    return FALSE;
  }
  return $form_elements_arr[$no];
}

function type_date_popup($default_value = NULL) {
  return array('#type'=>'date_popup', '#date_format'=>'Y-m-d', '#date_year_range'=>'-5:+5', '#default_value' => $default_value);
}

function type_radios($type = NULL, $default_value = NULL) {
  if ($type == 'gender') {
    $options_arr = array('1'=>'男','0'=>'女');
  }
  else {
    $options_arr = array('1'=>'是','0'=>'否');
  }
  return array('#type'=>'radios', '#options' => $options_arr, '#default_value' => $default_value);
}
function type_checkboxs($options, $default_value = array()) {
  return array('#type'=>'checkboxes', '#options' => $options, '#default_value' => $default_value);
}