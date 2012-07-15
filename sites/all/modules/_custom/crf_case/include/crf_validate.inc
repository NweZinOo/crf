<?php

function crf_case_validate_ruxuan_bz($form, &$form_state){
  $star_el = 'e_ruxuan_bz';
  _crf_validate_yes($star_el, $form_state);
}

function crf_case_validate_paichu_bz($form, &$form_state){
  $star_el = 'e_paichu_bz';
  _crf_validate_yes($star_el, $form_state);
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

function crf_case_validate_xindian_tjc($form, &$form_state) {
  if (empty($form_state['values']['e_xindian_tjc_1_1'])) {
    form_set_error('form', "检查日期不能为空！");
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

function _crf_validate_yes($star_el, &$form_state) {
  $values = $form_state['values'];
  foreach ($values as $k => $v) {
    if (preg_match("/^$star_el/", $k)) {
      if (strlen($v) == 0 || $v != '1'  ) {
        form_set_error('form', "所有选项必须选：是。否则请核实后再填写！");
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
