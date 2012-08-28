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
  return array('#type'=>'textfield', '#default_value' => $default_value, '#size' => $size);
}

function type_item($default_value = NULL, $size = NULL) {
  if (empty($size)) {
    $size = 20;
  }
  return array('#type'=>'item', '#value' => $default_value, '#size' => $size);
}

function type_date_popup($default_value = NULL, $title = NULL, $date_year_range = NULL) {
  if (empty($date_year_range)) {
    $date_year_range = '-50:+5';
  }
  return array('#type'=>'date_popup', '#date_format'=>'Y-m-d', '#date_year_range'=>$date_year_range, '#title' => $title, '#default_value' => $default_value);
}

function type_radios($options = NULL, $default_value = NULL, $title = NULL) {
  if (empty($options)) {
    $options = array('1'=>'是','0'=>'否');
  }
  return array('#type'=>'radios', '#options' => $options, '#title' => $title, '#default_value' => $default_value);
}

function type_select($options = NULL, $default_value = 0, $title = NULL) {
  if (empty($options)) {
    $options = array(1, 2, 3, 4, 5);
  }
  return array('#type'=>'select', '#options' => $options, '#title' => $title, '#default_value' => $default_value);
}

function type_checkboxs($options, $default_value = array()) {
  if (isset($options[0])) {
    //start with 0, we need start with 1
    
    $new_opt = array();
    $i = 1;
    foreach ($options as $v) {
      $new_opt[$i++] = $v;
    }
  }
  else {
    $new_opt = $options;
  }
  return array('#type'=>'checkboxes', '#options' => $new_opt, '#default_value' => $default_value);
}