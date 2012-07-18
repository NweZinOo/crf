<?php

function crf_case_validate_ruxuan_bz($form, &$form_state){
  $star_el = 'e_ruxuan_bz';
  _crf_validate_yes($star_el, $form_state);
}

function crf_case_validate_paichu_bz($form, &$form_state){
  $star_el = 'e_paichu_bz';
  _crf_validate_yes($star_el, $form_state, '0', '否');
}

function crf_case_validate_huaiyun_knx($form, &$form_state) {
  $values = $form_state['values'];
  $yin    = $values['e_huaiyun_knx_2_1'];
  if ($yin == '1') {
    form_set_error('form', "必须为阴性，否则请核实后再填写！");
  }
}

function crf_case_validate_zq2_2($form, &$form_state) {
}

function crf_case_validate_zq2_3($form, &$form_state) {
}

function crf_case_validate_weiai_ssyzdqk($form, &$form_state) {
  if (!is_numeric($form_state['values']['e_weiai_ssyzdqk_6_1']) ||
      !is_numeric($form_state['values']['e_weiai_ssyzdqk_6_2']) ||
      !is_numeric($form_state['values']['e_weiai_ssyzdqk_6_3']) ||
      !is_numeric($form_state['values']['e_weiai_ssyzdqk_6_4']) ||
      !is_numeric($form_state['values']['e_weiai_ssyzdqk_6_5']) ||
      !is_numeric($form_state['values']['e_weiai_ssyzdqk_6_6'])
      ) {
    form_set_error('form', "淋巴结转移情况的所有选项必须为数字！");
  }
}

function crf_case_validate_xueqing_zlbzwjc($form, &$form_state) {
  $check_field = array('e_xueqing_zlbzwjc_2_2', 'e_xueqing_zlbzwjc_3_2', 'e_xueqing_zlbzwjc_4_2');
  $field_name = array('CEA数值', 'CA19-9数值', 'CA724数值');
  
  foreach($check_field as $k => $v) {
    if (!empty($form_state['values'][$v])) {
      if (!is_numeric($form_state['values'][$v])) {
        form_set_error($v, "请检查\"{$field_name[$k]}\"的内容，必须为数字！");
      }
    }
  }
  
  $check_arr = array('e_xueqing_zlbzwjc_2_3', 'e_xueqing_zlbzwjc_3_3', 'e_xueqing_zlbzwjc_4_3');
  $field_name = array('e_xueqing_zlbzwjc_2_4', 'e_xueqing_zlbzwjc_3_4', 'e_xueqing_zlbzwjc_4_4');
  foreach($check_arr as $k => $v) {
    if ($form_state['values'][$v] == 1) {
      if (empty($form_state['values'][$field_name[$k]])) {
        form_set_error($field_name[$k], "选择了其它单位，请填写！");
      }
    }    
  }
}

function crf_case_validate_shiyan_sjc($form, &$form_state) {
  $check_field = array('e_shiyan_sjc_2_1', 'e_shiyan_sjc_3_1', 'e_shiyan_sjc_4_1', 'e_shiyan_sjc_5_1', 'e_shiyan_sjc_6_1', 'e_shiyan_sjc_7_1', 
      'e_shiyan_sjc_9_1', 'e_shiyan_sjc_11_1', 'e_shiyan_sjc_12_1', 'e_shiyan_sjc_13_1', 'e_shiyan_sjc_14_1', 'e_shiyan_sjc_15_1', 'e_shiyan_sjc_16_1',
      'e_shiyan_sjc_17_1', 'e_shiyan_sjc_18_1', 'e_shiyan_sjc_19_1', 'e_shiyan_sjc_20_1', 'e_shiyan_sjc_21_1', 'e_shiyan_sjc_22_1', 'e_shiyan_sjc_23_1',
      'e_shiyan_sjc_24_1', 'e_shiyan_sjc_26_1');
  $field_name = array('白细胞计数WBC', '中性粒细胞计数ANC', '血红蛋白HBG', '红细胞计数RBC', '红细胞压积', '血小板计数PLT', 'INR(华法令治疗者须查)',
      '总胆红素TBIL', '直接胆红素CB', '谷丙转氨酶ALT', '谷草转氨酶AST', '总蛋白TP', '白蛋白ALB', '碱性磷酸酶ALP', '乳酸脱氢酶LDH', '尿素BUN', '肌酐CRE', 
      '肌酐清除率Ccr', '钾K<sup>+</sup>', '钠Na<sup>+</sup>', '钙Ca<sup>2+</sup>', '尿蛋白');
  $field_radio = array('e_shiyan_sjc_2_3', 'e_shiyan_sjc_3_3', 'e_shiyan_sjc_4_3', 'e_shiyan_sjc_5_3', 'e_shiyan_sjc_6_3', 'e_shiyan_sjc_7_3', 
      'e_shiyan_sjc_9_3', 'e_shiyan_sjc_11_3', 'e_shiyan_sjc_12_3', 'e_shiyan_sjc_13_3', 'e_shiyan_sjc_14_3', 'e_shiyan_sjc_15_3', 'e_shiyan_sjc_16_3',
      'e_shiyan_sjc_17_3', 'e_shiyan_sjc_18_3', 'e_shiyan_sjc_19_3', 'e_shiyan_sjc_20_3', 'e_shiyan_sjc_21_3', 'e_shiyan_sjc_22_3', 'e_shiyan_sjc_23_3',
      'e_shiyan_sjc_24_3', 'e_shiyan_sjc_26_3');
  
  
  foreach($check_field as $k => $v) {
    if (!empty($form_state['values'][$v])) {
      if (!is_numeric($form_state['values'][$v])) {
        form_set_error($v, "请检查\"{$field_name[$k]}\"的内容，必须为数字！");
      }
      $current_radio = $field_radio[$k];
      if ($form_state['values'][$current_radio] == '') {
//        print $form_state['values'][$current_radio];
        form_set_error($current_radio, "请确定\"{$field_name[$k]}\"是否有临床意义！");
      }
    }
  }

}

function crf_case_validate_xindian_tjc($form, &$form_state) {
//  print $form_state['values']['e_xindian_tjc_2_1'];
  if ($form_state['values']['e_xindian_tjc_2_1'] != '') {
    if (empty($form_state['values']['e_xindian_tjc_1_1'])) {
      form_set_error('e_xindian_tjc_1_1', "检查日期不能为空！");
    }
  }
  if ($form_state['values']['e_xindian_tjc_2_1'] == 1) {
    if (empty($form_state['values']['e_xindian_tjc_2_2'])) {
      form_set_error('e_xindian_tjc_2_2', "如有异常，请填写说明！");
    }
  }  
}

function crf_case_validate_quanshen_tgjc($form, &$form_state) {
  if (strlen($form_state['values']['e_quanshen_tgjc_2_2']) != 3) {
    form_set_error('e_quanshen_tgjc_2_2', "身高必须为3位！");
  }
  if ($form_state['values']['e_quanshen_tgjc_2_2'] > 220) {
    form_set_error('e_quanshen_tgjc_2_2', "请输入合理的身高！");
  }
  if (strlen($form_state['values']['e_quanshen_tgjc_2_1']) != 3) {
    form_set_error('e_quanshen_tgjc_2_1', "体重必须为3位！");
  }
  if ($form_state['values']['e_quanshen_tgjc_2_1'] > 150) {
    form_set_error('e_quanshen_tgjc_2_1', "请输入合理的体重！");
  }
  if (!is_numeric($form_state['values']['e_quanshen_tgjc_4_1'])) {
     form_set_error('e_quanshen_tgjc_4_1', "血压必须为数字！");
  }
  if (!is_numeric($form_state['values']['e_quanshen_tgjc_4_2'])) {
     form_set_error('e_quanshen_tgjc_4_2', "血压必须为数字！");
  }
  if (!empty($form_state['values']['e_quanshen_tgjc_2_1']) && !empty($form_state['values']['e_quanshen_tgjc_2_2'])) {
    //体表面积：0.0061 * 身高 + 0.0128 * 体重 - 0.1529
    $mianji = 0.0061 * $form_state['values']['e_quanshen_tgjc_2_2'] + 0.0128 * $form_state['values']['e_quanshen_tgjc_2_1'] - 0.1529;
    if ($form_state['values']['e_quanshen_tgjc_3_2'] != $mianji) {
      $form_state['values']['e_quanshen_tgjc_3_2'] = $mianji;
      drupal_set_message('根据您输入的体重和身高，体表面积自动更正为'. $mianji, 'warning');
    }
  }
  
  $check_arr = array('e_quanshen_tgjc_5_1', 'e_quanshen_tgjc_6_1', 'e_quanshen_tgjc_7_1', 'e_quanshen_tgjc_8_1', 'e_quanshen_tgjc_9_1', 'e_quanshen_tgjc_10_1', 
          'e_quanshen_tgjc_11_1', 'e_quanshen_tgjc_12_1', 'e_quanshen_tgjc_13_1', 'e_quanshen_tgjc_14_1', 'e_quanshen_tgjc_15_1', 'e_quanshen_tgjc_16_1', );
  $field_name = array('e_quanshen_tgjc_5_2', 'e_quanshen_tgjc_6_2', 'e_quanshen_tgjc_7_2', 'e_quanshen_tgjc_8_2', 'e_quanshen_tgjc_9_2', 'e_quanshen_tgjc_10_2', 
          'e_quanshen_tgjc_11_2', 'e_quanshen_tgjc_12_2', 'e_quanshen_tgjc_13_2', 'e_quanshen_tgjc_14_2', 'e_quanshen_tgjc_15_2', 'e_quanshen_tgjc_16_2', );
  foreach($check_arr as $k => $v) {
    if ($form_state['values'][$v] == 1) {
      if (empty($form_state['values'][$field_name[$k]])) {
        form_set_error($field_name[$k], "选择异常的项，请填写说明！");
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
