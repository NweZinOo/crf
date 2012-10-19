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
    form_set_error('e_dyxx_1_2', '患者年龄不能为空!');
  }
  else {
    if (!is_numeric($values['e_dyxx_1_2'])) {
      form_set_error('e_dyxx_1_2', "患者年龄必须数字！");
    }
    if ($values['e_dyxx_1_2'] <= 0 || $values['e_dyxx_1_2'] > 150) {
      form_set_error('e_dyxx_1_2', "请输入正确的患者年龄！");
    }
    
  }
  if ($values['e_dyxx_1_3'] == '') {
    form_set_error('e_dyxx_1_3', '患者性别需要选择一项!');
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
  if ($values['e_dyxx_35_1'] == '') {
    form_set_error('e_dyxx_35_1', '是否接受统一随访需要选择一项!');
  }
  if (empty($values['e_dyxx_36_1'])) {
    form_set_error('e_dyxx_36_1', '医生签名不能为空!');
  }
  else {
    if (!preg_match("/[\x{4e00}-\x{9fa5}]+/u", $values['e_dyxx_36_1'], $match)) {
      form_set_error('e_dyxx_36_1', '医生签名必须为汉字!');
    }
  }
  if (empty($values['e_dyxx_36_2'])) {
    form_set_error('e_dyxx_36_2', '填表日期不能为空!');
  }
  // other
  if ($values['e_dyxx_8_2'][1] == 1) {
    if (empty($values['e_dyxx_8_3'])) {
      form_set_error('e_dyxx_8_3', '基础疾病诊断信息的诊断结果如选择了其他需要说明!');
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
  
//  print_r($values);
  if ($values['e_dyxx_5_1'][1] == 1) {
    if ($values['e_dyxx_6_1'][1] == 0 && $values['e_dyxx_6_2'][1] == 0 && $values['e_dyxx_6_3'][1] == 0 && $values['e_dyxx_6_4'][1] == 0 && $values['e_dyxx_6_5'][1] == 0 && $values['e_dyxx_6_6'][1] == 0 && $values['e_dyxx_6_7'][1] == 0) {
      form_set_error('e_dyxx_6_1', '当诊断为骨髓增生异常综合征，其WHO(2008)分型必须要选择至少一项!');
    }
  }
  if ($values['e_dyxx_16_1'][1] == 0) {
    if (empty($values['e_dyxx_17_1'])) {
      form_set_error('e_dyxx_17_1', '输血治疗的开始日期必须填写!');
    }
    if (empty($values['e_dyxx_18_1'])) {
      form_set_error('e_dyxx_18_1', '既往RBC输注总量为必须填写!');
    }
  }
  if (empty($values['e_dyxx_19_1'])) {
    form_set_error('e_dyxx_19_1', '血铁五项中的血清铁蛋白(SF)的取样日期 为必填写项!');
  }
  if (empty($values['e_dyxx_20_1'])) {
    form_set_error('e_dyxx_20_1', '血铁五项中的血清铁蛋白(SF) 为必填写项!');
  }
  if (empty($values['e_dyxx_23_1'])) {
    form_set_error('e_dyxx_23_1', '血常规取样日期 为必填写项!');
  }
  if (empty($values['e_dyxx_24_1'])) {
    form_set_error('e_dyxx_24_1', '血常规中的HB 为必填写项!');
  }
  if (empty($values['e_dyxx_24_4'])) {
    form_set_error('e_dyxx_24_4', '血常规中的PLT 为必填写项!');
  }
  if ($values['e_dyxx_26_1'] == 1) {
    if (empty($values['e_dyxx_26_2'])) {
      form_set_error('e_dyxx_26_2', '肝功能有异常须填写谷草转氨酶(SGOT)!');
    }
    if (empty($values['e_dyxx_26_3'])) {
      form_set_error('e_dyxx_26_3', '肝功能有异常须填写谷丙转氨酶(SGPT)!');
    }
  }
  if ($values['e_dyxx_27_1'] == 1) {
    if (empty($values['e_dyxx_27_2'])) {
      form_set_error('e_dyxx_27_2', '血糖有异常须填写空腹血糖(FBS)!');
    }
    if (empty($values['e_dyxx_27_3'])) {
      form_set_error('e_dyxx_27_3', '血糖有异常须填写餐后两小时血糖!');
    }
  }
  if ($values['e_dyxx_34_1'] == '') {
    form_set_error('e_dyxx_34_1', '治疗决定需要选择一项!');
  }
}

function crf_case_validate_zlcl($form, &$form_state){
  $values = $form_state['values'];
  if ($values['e_zlcl_1_1'][1] == 1) {
    if ($values['e_zlcl_2_1'][1] == 0 && $values['e_zlcl_2_2'][1] == 0 && $values['e_zlcl_2_3'][1] == 0 && $values['e_zlcl_2_4'][1] == 0 && $values['e_zlcl_2_5'][1] == 0) {
      form_set_error('e_zlcl_2_1', '支持治疗的子项必须填写一项!');
    }
  }
  if ($values['e_zlcl_3_1'][1] == 1) {
    if ($values['e_zlcl_4_1'][1] == 0 && $values['e_zlcl_5_1'][1] == 0 && $values['e_zlcl_6_1'][1] == 0 && $values['e_zlcl_7_1'][1] == 0 && $values['e_zlcl_8_1'][1] == 0 && $values['e_zlcl_9_1'][1] == 0) {
      form_set_error('e_zlcl_4_1', '治疗药物的子项必须填写一项!');
    }
  }
  if ($values['e_zlcl_10_1'][1] == 1) {
    if ($values['e_zlcl_11_1'][1] == 0 && $values['e_zlcl_12_1'][1] == 0 && $values['e_zlcl_13_1'][1] == 0) {
      form_set_error('e_zlcl_11_1', '免疫抑制治疗的子项必须填写一项!');
    }
  }
  if ($values['e_zlcl_4_1'][1] == 1) {
    if ($values['e_zlcl_4_2'][1] == 0 && $values['e_zlcl_4_3'][1] == 0 && $values['e_zlcl_4_4'][1] == 0) {
      form_set_error('e_zlcl_4_2', '去甲基化药物的子项必须填写一项!');
    }
  }
  if ($values['e_zlcl_6_1'][1] == 1) {
    if ($values['e_zlcl_6_2'][1] == 0 && $values['e_zlcl_6_3'][1] == 0 && $values['e_zlcl_6_4'][1] == 0) {
      form_set_error('e_zlcl_6_2', '免疫调节治疗的子项必须填写一项!');
    }
  }
  if ($values['e_zlcl_7_1'][1] == 1) {
    if ($values['e_zlcl_7_2'][1] == 0 && $values['e_zlcl_7_3'][1] == 0) {
      form_set_error('e_zlcl_7_2', '免疫抑制治疗的子项必须填写一项!');
    }
  }
  if ($values['e_zlcl_4_4'][1] == 1 && empty($values['e_zlcl_4_5'])) {
    form_set_error('e_zlcl_4_5', '选择其它须注明理由!');
  }  
  if ($values['e_zlcl_6_4'][1] == 1 && empty($values['e_zlcl_6_5'])) {
    form_set_error('e_zlcl_6_5', '选择其它须注明理由!');
  }  
  if ($values['e_zlcl_7_3'][1] == 1 && empty($values['e_zlcl_7_4'])) {
    form_set_error('e_zlcl_7_4', '选择其它须注明理由!');
  }  
  if ($values['e_zlcl_9_1'][1] == 1 && empty($values['e_zlcl_9_2'])) {
    form_set_error('e_zlcl_9_2', '选择其它须注明理由!');
  }  
  if ($values['e_zlcl_11_2'][1] == 1 && empty($values['e_zlcl_11_3'])) {
    form_set_error('e_zlcl_11_3', '选择其它须注明理由!');
  }  
  if ($values['e_zlcl_13_1'][1] == 1 && empty($values['e_zlcl_13_2'])) {
    form_set_error('e_zlcl_13_2', '选择其它须注明理由!');
  }  
}

function crf_case_validate_dhsf($form, &$form_state){
  $values = $form_state['values'];
  if(empty($values['e_dhsf_1_1'])) {
    form_set_error('e_dhsf_1_1', '诊断必须填写!');
  }
  if(empty($values['e_dhsf_1_2'])) {
    form_set_error('e_dhsf_1_2', '电话随访时间必须填写!');
  }
}

function crf_case_validate_sf_1($form, &$form_state){
  $values = $form_state['values'];
  if(empty($values['e_sf_1_1_1'])) {
    form_set_error('e_sf_1_1_1', '随访日期必须填写!');
  }
  if(empty($values['e_sf_1_2_1'])) {
    form_set_error('e_sf_1_2_1', '祛铁治疗记录的药物名称必须填写!');
  }
  if(empty($values['e_sf_1_3_1'])) {
    form_set_error('e_sf_1_3_1', '祛铁治疗记录的第一个月剂量必须填写!');
  }
  if(empty($values['e_sf_1_4_1'])) {
    form_set_error('e_sf_1_4_1', '祛铁治疗记录的第一个月治疗时间必须填写!');
  }
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
