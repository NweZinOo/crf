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
