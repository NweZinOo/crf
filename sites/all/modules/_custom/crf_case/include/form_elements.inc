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

function type_textfield($default_value = NULL, $size = NULL) {
  if (empty($size)) {
    $size = 20;
  }
  return array('#type'=>'textfield', '#default_value' => $default_value, '#size' => $size,);
}

function type_date_popup($default_value = NULL, $title = NULL) {
  return array('#type'=>'date_popup', '#date_format'=>'Y-m-d', '#date_year_range'=>'-5:+5', '#title' => $title, '#default_value' => $default_value);
}

function type_radios($options = NULL, $default_value = NULL, $title = NULL) {
  if (empty($options)) {
    $options = array('1'=>'是','0'=>'否');
  }
  return array('#type'=>'radios', '#options' => $options, '#title' => $title, '#default_value' => $default_value);
}
function type_checkboxs($options, $default_value = array()) {
  return array('#type'=>'checkboxes', '#options' => $options, '#default_value' => $default_value);
}