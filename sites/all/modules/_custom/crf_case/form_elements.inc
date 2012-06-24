<?php
/**
 * All form array put here
 */
function get_form_elements_arr($no) {
  $form_elements_arr = array();
  
  $form_elements_arr[1] = array(
    1 => array(
      1 => type_date_popup()
    )
  );
  $form_elements_arr[2] = array(
    1 => array(1 => type_radios(),2 => type_radios()),
    2 => array(1 => type_radios(),2 => type_radios()),
    3 => array(1 => type_radios(),2 => type_radios()),
    4 => array(1 => type_radios(),2 => type_radios()),
    5 => array(1 => type_radios(),2 => type_radios()),
    6 => array(1 => type_radios(),2 => type_radios()),
    7 => array(1 => type_radios(),2 => type_radios()),
    8 => array(1 => type_radios(),2 => type_radios()),
    9 => array(1 => type_radios(),2 => type_radios()),
    10 => array(1 => type_radios(),2 => type_radios()),
    11 => array(1 => type_radios(),2 => type_radios()),
    12 => array(1 => type_radios(),2 => type_radios()),
  );
  $form_elements_arr[3] = array(
    1 => array(1 => type_radios(),2 => type_radios()),
    2 => array(1 => type_radios(),2 => type_radios()),
    3 => array(1 => type_radios(),2 => type_radios()),
    4 => array(1 => type_radios(),2 => type_radios()),
    5 => array(1 => type_radios(),2 => type_radios()),
  );
  $form_elements_arr[4] = array(
    1 => array(1 => type_date_popup(),2 => type_radios('gender')),
  );
  $form_elements_arr[5] = array(
    1 => array(1 => type_date_popup()),
    2 => array(1 => type_date_popup()),
    3 => array(1 => type_checkboxs(array('T','N','M'))),
  );
  if (empty($form_elements_arr[$no])) {
    drupal_set_message('未建立的数组元素,请联系管理员！');
    drupal_goto('crf_case_edit');
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