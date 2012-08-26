<?php

function crf_case_validate_dyxx($form, &$form_state){
  $values = $form_state['values'];
  if (empty($values['e_dyxx_1_1'])) {
    form_set_error('e_dyxx_1_1', '患者姓名不能为空!');
  }
  else {
    if (!preg_match("/[\x{4e00}-\x{9fa5}]+/u", $values['e_dyxx_1_1'], $match)) {
      form_set_error('e_dyxx_1_1', '患者姓名必须为汉字!');
    }
  }
  if (empty($values['e_dyxx_1_2'])) {
    form_set_error('e_dyxx_1_2', '患者姓名缩写不能为空!');
  }
  else if (4 != mb_strlen($values['e_dyxx_1_2']) || !ctype_alpha($values['e_dyxx_1_2'])){
    form_set_error('e_dyxx_1_2', '受试者姓名缩写请用四个字母表示，两字姓名分填两字前两个字母，三字姓名填前两字首字母与第三字前两个字母，四字姓名填每字首字母！');
  }
  if (empty($values['e_dyxx_1_3'])) {
    form_set_error('e_dyxx_1_3', '患者年龄不能为空!');
  }
  else {
    if (!is_numeric($values['e_dyxx_1_3'])) {
    form_set_error('e_dyxx_1_3', "患者年龄必须数字！");
  }
  }
  if ($values['e_dyxx_1_4'] == '') {
    form_set_error('e_dyxx_1_4', '患者性别需要选择一项!');
  }
  if (empty($values['e_dyxx_2_1'])) {
    form_set_error('e_dyxx_2_1', '患者家庭住址不能为空!');
  }
  if (empty($values['e_dyxx_2_2'])) {
    form_set_error('e_dyxx_2_2', '患者联系电话不能为空!');
  }
  else if (11 != mb_strlen($values['e_dyxx_2_2']) || !is_numeric($values['e_dyxx_2_2'])){
    form_set_error('e_dyxx_2_2', '受试者手机号必须为11位数字!');
  }
  if (empty($values['e_dyxx_3_1'])) {
    form_set_error('e_dyxx_3_1', '患者身份证号码不能为空!');
  }
  else if (18 != mb_strlen($values['e_dyxx_3_1'])){
    form_set_error('e_dyxx_3_1', '受试者身份证号必须为18位!');
  }
  if (empty($values['e_dyxx_3_2'])) {
    form_set_error('e_dyxx_3_2', '患者体重不能为空!');
  }
  else {
    if (!is_numeric($values['e_dyxx_3_2'])) {
      form_set_error('e_dyxx_3_2', "患者体重必须数字！");
    }
    if (strlen($values['e_dyxx_3_2']) != 3 && strlen($values['e_dyxx_3_2']) != 2) {
      form_set_error('e_dyxx_3_2', "患者体重必须为2位或者3位！");
    }
    if ($values['e_dyxx_3_2'] > 150) {
      form_set_error('e_dyxx_3_2', "患者体重请输入合理的体重！");
    }
  }
  if ($values['e_dyxx_31_1'] == '') {
    form_set_error('e_dyxx_31_1', '是否接受统一随访需要选择一项!');
  }
  if (empty($values['e_dyxx_32_1'])) {
    form_set_error('e_dyxx_32_1', '医生签名不能为空!');
  }
  else {
    if (!preg_match("/[\x{4e00}-\x{9fa5}]+/u", $values['e_dyxx_32_1'], $match)) {
      form_set_error('e_dyxx_32_1', '医生签名必须为汉字!');
    }
  }
  if (empty($values['e_dyxx_32_2'])) {
    form_set_error('e_dyxx_32_2', '填表日期不能为空!');
  }
  // other
  if ($values['e_dyxx_9_2'][1] == 1) {
    if (empty($values['e_dyxx_9_3'])) {
      form_set_error('e_dyxx_9_3', '基础疾病诊断信息的诊断结果如选择了其他需要说明!');
    }
  }

  if ($values['e_dyxx_16_1'][1] == 1) {
    if (!empty($values['e_dyxx_17_1'])) {
      form_set_error('e_dyxx_17_1', '输血治疗史未做无需填写日期!');
    }
    if (!empty($values['e_dyxx_18_1'])) {
      form_set_error('e_dyxx_18_1', '输血治疗史未做无需填写既往RBC输注总量!');
    }
  }
}

function crf_case_validate_sf_1($form, &$form_state){
  _check_zq_date($form_state, 'sf_1', 'e_sf_2_1_1', '第一次随访', 'e_sf_1_13_3', 'e_sf_1_13_4');
  _check_zq_date_1(&$form_state, 1);
}
function crf_case_validate_sf_2($form, &$form_state){
  _check_zq_date($form_state, 'sf_1', 'e_sf_2_1_1', '第一次随访', 'e_sf_1_13_3', 'e_sf_1_13_4');
  _check_zq_date_1(&$form_state, 2);
}
function crf_case_validate_sf_3($form, &$form_state){
  _check_zq_date($form_state, 'sf_2', 'e_sf_3_1_1', '第二次随访', 'e_sf_2_13_3', 'e_sf_2_13_4');
  _check_zq_date_1(&$form_state, 3);
}
function crf_case_validate_sf_4($form, &$form_state){
  _check_zq_date($form_state, 'sf_3', 'e_sf_4_1_1', '第三次随访', 'e_sf_3_13_3', 'e_sf_3_13_4');
  _check_zq_date_1(&$form_state, 4);
}
function crf_case_validate_sf_5($form, &$form_state){
  _check_zq_date($form_state, 'sf_4', 'e_sf_5_1_1', '第四次随访', 'e_sf_4_13_3', 'e_sf_4_13_4');
  _check_zq_date_1(&$form_state, 5);
}

function _check_zq_date(&$form_state, $last_table, $e, $last_zq_name, $e_2, $e_1) {
  $p_uid = crf_ds_s_data('p_uid');
  $data = json_to_array(crf_ds_load($last_table, $p_uid));
  if (!empty($form_state['values'][$e])) {
    if (crf_ds_s_time($form_state['values'][$e]) < $data[1][1]) {
      form_set_error($e, "随访日期要大于{$last_zq_name}的日期！");
    }
  }  
}

function _check_zq_date_1(&$form_state, $sf_no) {
  for($i = 13;$i<=16;$i++) {
    if (!empty($form_state['values']['e_sf_'.$sf_no.'_'.$i.'_3']) && !empty($form_state['values']['e_sf_'.$sf_no.'_'.$i.'_4'])) {
      if (crf_ds_s_time($form_state['values']['e_sf_'.$sf_no.'_'.$i.'_3']) >= crf_ds_s_time($form_state['values']['e_sf_'.$sf_no.'_'.$i.'_4'])) {
        form_set_error('e_sf_'.$sf_no.'_'.$i.'_3', "原发病治疗情况的截止用药时间要大于起始时间！");
      }
    }
  }
}

function _crf_validate_did(&$form_state, $key, $val = '1') {
  $v = $form_state['values'][$key];
  if (is_array($v)) {
    $v = array_shift($v);
  }
  if ($v == $val) {
    $clone = $form_state['values'];    
    //var_dump($clone);exit;

    unset($clone[$key]);
    unset($clone['op']);
    unset($clone['submit']);
    unset($clone['form_build_id']);
    unset($clone['form_token']);
    unset($clone['form_id']);
    
    //var_dump($clone);exit;
    if (!_crf_empty($clone)) {
      form_set_error('form', "您选择了 [没有] 或 [未做]，所以请不要填写表格里面的任何选项！");
    }
  }
}

function _crf_validate_yes($star_el, &$form_state, $yes = '1', $yes_label = '是') {
  $values = $form_state['values'];
  foreach ($values as $k => $v) {
    if (preg_match("/^$star_el/", $k)) {
      if (strlen($v) == 0 || $v != $yes  ) {
        form_set_error('form', "所有选项必须选：{$yes_label}。否则请核实后再填写！");
        break;
      }
    }
  }
}

function _crf_empty(&$array) {
  foreach ($array as $k => $v) {
    if (is_array($v)) {
      $return = _crf_empty($v);
    }
    else {
      if (is_string($v) && $v === '0') {
        $return = FALSE;
      }
      else {
        $return = empty($v);
      }
    }
    
    if ($return === FALSE) {
      return $return;
    }
  }
  return TRUE;
}
