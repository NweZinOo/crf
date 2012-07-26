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

function crf_case_validate_teshu_jc($form, &$form_state) {
  $p_uid = crf_ds_s_data('p_uid');
  $data = json_to_array(crf_ds_load('zq1_1', $p_uid));
//  print_r($data);exit;
  $check_arr = array('e_teshu_jc_1_1', 'e_teshu_jc_2_1', 'e_teshu_jc_3_1', 'e_teshu_jc_4_1', 'e_teshu_jc_5_1', 'e_teshu_jc_6_1', 
      'e_teshu_jc_7_1', 'e_teshu_jc_8_1', 'e_teshu_jc_9_1', 'e_teshu_jc_10_1', 'e_teshu_jc_11_1', 'e_teshu_jc_12_2', 'e_teshu_jc_13_2', 'e_teshu_jc_14_2');
  $check_name = array('胸部X线检查','腹部CT检查','腹部MRI','盆腔CT检查','盆腔MRI','胸部CT检查','胸部MRI','头颅CT检查','头颅MRI','骨扫描','全身PET/CT','详细说明','详细说明','详细说明');
  foreach ($check_arr as $k => $v) {
    if (!empty($form_state['values'][$v])) {
      if (crf_ds_s_time($form_state['values'][$v]) > $_SESSION['crf']['p_arr']['approved_time']) {
        print 'x'.crf_ds_s_time($form_state['values'][$v]).'x';
        print 'y'.$_SESSION['crf']['p_arr']['approved_time'].'y';
        form_set_error($v, $check_name[$k] ."的评估日期不能大于知情同意书的日期(". $_SESSION['crf']['p_arr']['approved_time'] .")！");
      }
    }
    if (!empty($form_state['values'][$v]) && (!empty($data[1][1]) || !empty($data[2][2]))) {
      if ($form_state['values'][$v] > $data[1][1] || $form_state['values'][$v] > $data[2][2]) {
        form_set_error($v, $check_name[$k] ."的评估日期不能大于第一周期给药的日期！");
      }
    }
  }  
}

function crf_case_validate_zq1_1($form, &$form_state) {
  $p_uid = crf_ds_s_data('p_uid');
  if (!empty($form_state['values']['e_zq1_1_1_2']) && !empty($form_state['values']['e_zq1_1_1_1']) && ($form_state['values']['e_zq1_1_1_2'] <= $form_state['values']['e_zq1_1_1_1'])) {
    form_set_error('e_zq1_1_1_2', "S-1结束时间不能小于或等于起始时间！");
  }
  if (!empty($form_state['values']['e_zq1_1_1_1'])) {
    $data = json_to_array(crf_ds_load('zhiqing_tys', $p_uid));
    if ($form_state['values']['e_zq1_1_1_1'] < $data[1][1]) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于知情同意书时间！");
    }
    if ($form_state['values']['e_zq1_1_2_2'] < $data[1][1]) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于知情同意书时间！");
    }
    $data = json_to_array(crf_ds_load('renkou_tjx', $p_uid));
    if (!empty($data[1][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[1][1])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于出生日期！");
    }
    if (!empty($data[1][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[1][1])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于出生日期！");
    }
    $data = json_to_array(crf_ds_load('weiai_ssyzdqk', $p_uid));
    if (!empty($data[1][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[1][1])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于胃癌手术与诊断情况中的首次诊断日期！");
    }
    if (!empty($data[1][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[1][1])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于胃癌手术与诊断情况中的首次诊断日期！");
    }
    if (!empty($data[2][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[2][1])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于胃癌手术与诊断情况中的手术日期！");
    }
    if (!empty($data[2][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[2][1])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于胃癌手术与诊断情况中的手术日期！");
    }
    $data = json_to_array(crf_ds_load('jiwang_hxhjb', $p_uid));
    if (!empty($data[2][3]) && ($form_state['values']['e_zq1_1_1_1'] < $data[2][3])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于既往或现患疾病中的诊断日期！");
    }
    if (!empty($data[3][3]) && ($form_state['values']['e_zq1_1_1_1'] < $data[3][3])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于既往或现患疾病中的诊断日期！");
    }
    if (!empty($data[4][3]) && ($form_state['values']['e_zq1_1_1_1'] < $data[4][3])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于既往或现患疾病中的诊断日期！");
    }
    if (!empty($data[2][3]) && ($form_state['values']['e_zq1_1_2_2'] < $data[2][3])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于既往或现患疾病中的诊断日期！");
    }
    if (!empty($data[3][3]) && ($form_state['values']['e_zq1_1_2_2'] < $data[3][3])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于既往或现患疾病中的诊断日期！");
    }
    if (!empty($data[4][3]) && ($form_state['values']['e_zq1_1_2_2'] < $data[4][3])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于既往或现患疾病中的诊断日期！");
    }
    $data = json_to_array(crf_ds_load('teshu_jc', $p_uid));
    if (!empty($data[1][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[1][1])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于特殊检查中的胸部X线检查评估日期！");
    }
    if (!empty($data[2][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[2][1])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于特殊检查中的腹部CT检查评估日期！");
    }
    if (!empty($data[3][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[3][1])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于特殊检查中的腹部MRI评估日期！");
    }
    if (!empty($data[4][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[4][1])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于特殊检查中的盆腔CT检查评估日期！");
    }
    if (!empty($data[5][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[5][1])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于特殊检查中的盆腔MRI评估日期！");
    }
    if (!empty($data[6][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[6][1])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于特殊检查中的胸部CT检查评估日期！");
    }
    if (!empty($data[7][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[7][1])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于特殊检查中的胸部MRI评估日期！");
    }
    if (!empty($data[8][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[8][1])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于特殊检查中的头颅CT评估日期！");
    }
    if (!empty($data[9][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[9][1])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于特殊检查中的头颅MRI评估日期！");
    }
    if (!empty($data[10][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[10][1])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于特殊检查中的骨扫描评估日期！");
    }
    if (!empty($data[11][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[11][1])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于特殊检查中的全身PET/CT评估日期！");
    }
    if (!empty($data[11][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[12][2])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于特殊检查中的其它的评估日期！");
    }
    if (!empty($data[11][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[13][2])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于特殊检查中的其它的评估日期！");
    }
    if (!empty($data[11][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[14][2])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于特殊检查中的其它的评估日期！");
    }
    if (!empty($data[1][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[1][1])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于特殊检查中的胸部X线检查评估日期！");
    }
    if (!empty($data[2][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[2][1])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于特殊检查中的腹部CT检查评估日期！");
    }
    if (!empty($data[3][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[3][1])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于特殊检查中的腹部MRI评估日期！");
    }
    if (!empty($data[4][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[4][1])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于特殊检查中的盆腔CT检查评估日期！");
    }
    if (!empty($data[5][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[5][1])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于特殊检查中的盆腔MRI评估日期！");
    }
    if (!empty($data[6][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[6][1])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于特殊检查中的胸部CT检查评估日期！");
    }
    if (!empty($data[7][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[7][1])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于特殊检查中的胸部MRI评估日期！");
    }
    if (!empty($data[8][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[8][1])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于特殊检查中的头颅CT评估日期！");
    }
    if (!empty($data[9][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[9][1])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于特殊检查中的头颅MRI评估日期！");
    }
    if (!empty($data[10][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[10][1])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于特殊检查中的骨扫描评估日期！");
    }
    if (!empty($data[11][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[11][1])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于特殊检查中的全身PET/CT评估日期！");
    }
    if (!empty($data[11][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[12][2])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于特殊检查中的其它的评估日期！");
    }
    if (!empty($data[11][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[13][2])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于特殊检查中的其它的评估日期！");
    }
    if (!empty($data[11][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[14][2])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于特殊检查中的其它的评估日期！");
    }
    $data = json_to_array(crf_ds_load('xindian_tjc', $p_uid));
    if (!empty($data[1][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[1][1])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于心电图检查中的检查日期！");
    }
    if (!empty($data[1][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[1][1])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于心电图检查中的检查日期！");
    }
    $data = json_to_array(crf_ds_load('quanshen_tgjc', $p_uid));
    if (!empty($data[1][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[1][1])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于全身体格检查中的检查日期！");
    }
    if (!empty($data[1][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[1][1])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于全身体格检查中的检查日期！");
    }
    $data = json_to_array(crf_ds_load('xueqing_zlbzwjc', $p_uid));
    if (!empty($data[1][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[1][1])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于血清肿瘤标志物检测中的取样日期！");
    }
    if (!empty($data[1][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[1][1])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于血清肿瘤标志物检测中的取样日期！");
    }
    $data = json_to_array(crf_ds_load('shiyan_sjc', $p_uid));
    if (!empty($data[1][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[1][1])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于实验室检查中的血常规-取样日期！");
    }
    if (!empty($data[1][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[8][1])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于实验室检查中的凝血功能-取样日期！");
    }
    if (!empty($data[1][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[10][1])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于实验室检查中的血生化-取样日期！");
    }
    if (!empty($data[1][1]) && ($form_state['values']['e_zq1_1_1_1'] < $data[25][1])) {
      form_set_error('e_zq1_1_1_1', "S-1起始给药日期不能小于实验室检查中的尿常规-取样日期！");
    }
    if (!empty($data[1][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[1][1])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于实验室检查中的血常规-取样日期！");
    }
    if (!empty($data[1][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[8][1])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于实验室检查中的凝血功能-取样日期！");
    }
    if (!empty($data[1][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[10][1])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于实验室检查中的血生化-取样日期！");
    }
    if (!empty($data[1][1]) && ($form_state['values']['e_zq1_1_2_2'] < $data[25][1])) {
      form_set_error('e_zq1_1_2_2', "奥沙利铂给药日期不能小于实验室检查中的尿常规-取样日期！");
    }
  }
}

function crf_case_validate_zq2_2($form, &$form_state) {
  _check_zq_jianliang($form_state, 'e_zq2_2_2_2', 'e_zq2_2_2_3');
  _check_zq_jianliang($form_state, 'e_zq2_2_3_2', 'e_zq2_2_3_3');
}
function crf_case_validate_zq3_2($form, &$form_state) {
  _check_zq_jianliang($form_state, 'e_zq3_2_2_2', 'e_zq3_2_2_3');
  _check_zq_jianliang($form_state, 'e_zq3_2_3_2', 'e_zq3_2_3_3');
}
function crf_case_validate_zq4_2($form, &$form_state) {
  _check_zq_jianliang($form_state, 'e_zq4_2_2_2', 'e_zq4_2_2_3');
  _check_zq_jianliang($form_state, 'e_zq4_2_3_2', 'e_zq4_2_3_3');
}
function crf_case_validate_zq5_2($form, &$form_state) {
  _check_zq_jianliang($form_state, 'e_zq5_2_2_2', 'e_zq5_2_2_3');
  _check_zq_jianliang($form_state, 'e_zq5_2_3_2', 'e_zq5_2_3_3');
}
function crf_case_validate_zq6_2($form, &$form_state) {
  _check_zq_jianliang($form_state, 'e_zq6_2_2_2', 'e_zq6_2_2_3');
  _check_zq_jianliang($form_state, 'e_zq6_2_3_2', 'e_zq6_2_3_3');
}
function crf_case_validate_zq7_2($form, &$form_state) {
  _check_zq_jianliang($form_state, 'e_zq7_2_2_2', 'e_zq7_2_2_3');
  _check_zq_jianliang($form_state, 'e_zq7_2_3_2', 'e_zq7_2_3_3');
}

function crf_case_validate_zq2_3($form, &$form_state) {
}
//周期给药时间大于上一周期给药时间
function crf_case_validate_zq2_4($form, &$form_state) {
  $p_uid = crf_ds_s_data('p_uid');
  $data = json_to_array(crf_ds_load('zq1_1', $p_uid));
  if (!empty($form_state['values']['e_zq2_4_1_3'])) {
    if (crf_ds_s_time($form_state['values']['e_zq2_4_1_3']) < $data[1][1]) {
      form_set_error('e_zq2_4_1_3', "给药日期不能小于第一周期给药的日期！");
    }
    if (crf_ds_s_time($form_state['values']['e_zq2_4_1_3']) >= crf_ds_s_time($form_state['values']['e_zq2_4_1_4'])) {
      form_set_error('e_zq2_4_1_4', "结束日期应大于起始日期！");
    }
  }
  if (!empty($form_state['values']['e_zq2_4_2_4'])) {
    if (crf_ds_s_time($form_state['values']['e_zq2_4_2_4']) < $data[2][2]) {
      form_set_error('e_zq2_4_2_4', "给药日期不能小于第一周期给药的日期！");
    }
  }
}
function crf_case_validate_zq3_4($form, &$form_state) {
  _check_zq_date($form_state, 'zq2_4', 'e_zq3_4_1_3', 'e_zq3_4_1_4', 'e_zq3_4_2_4', '第二周期');
}
function crf_case_validate_zq4_4($form, &$form_state) {
  _check_zq_date($form_state, 'zq3_4', 'e_zq4_4_1_3', 'e_zq4_4_1_4', 'e_zq4_4_2_4', '第三周期');
}
function crf_case_validate_zq5_4($form, &$form_state) {
  _check_zq_date($form_state, 'zq4_4', 'e_zq5_4_1_3', 'e_zq5_4_1_4', 'e_zq5_4_2_4', '第四周期');
}
function crf_case_validate_zq6_4($form, &$form_state) {
  _check_zq_date($form_state, 'zq5_4', 'e_zq6_4_1_3', 'e_zq6_4_1_4', 'e_zq6_4_2_4', '第五周期');
}
function crf_case_validate_zq7_4($form, &$form_state) {
  _check_zq_date($form_state, 'zq6_4', 'e_zq7_4_1_3', 'e_zq7_4_1_4', 'e_zq7_4_2_4', '第六周期');
}
function crf_case_validate_zq8_3($form, &$form_state) {
  _check_zq_date_1($form_state, 'zq7_4', 'e_zq8_3_3_1', 'e_zq8_3_3_2', '第七周期');
}
function crf_case_validate_zq9_3($form, &$form_state) {
  _check_zq_date_2($form_state, 'zq8_3', 'e_zq9_3_3_1', 'e_zq9_3_3_2', '第八周期');
}
function _check_zq_date(&$form_state, $last_table, $e1_1, $e1_2, $e2, $last_zq_name) {
  $p_uid = crf_ds_s_data('p_uid');
  $data = json_to_array(crf_ds_load($last_table, $p_uid));
//  print_r($data);exit;
  if (!empty($form_state['values'][$e1_1])) {
    if (crf_ds_s_time($form_state['values'][$e1_1]) < $data[1][4]) {
      form_set_error($e1_1, "给药日期要大于{$last_zq_name}给药的日期！");
    }
    if (crf_ds_s_time($form_state['values'][$e1_1]) >= crf_ds_s_time($form_state['values'][$e1_2])) {
      form_set_error($e1_2, "结束日期应大于起始日期！");
    }
  }  
  if (!empty($form_state['values'][$e2])) {
    if (crf_ds_s_time($form_state['values'][$e2]) < $data[2][4]) {
      form_set_error($e2, "给药日期要大于{$last_zq_name}给药的日期！");
    }
  }  
}

function _check_zq_date_1(&$form_state, $last_table, $e1_1, $e1_2, $last_zq_name) {
  $p_uid = crf_ds_s_data('p_uid');
  $data = json_to_array(crf_ds_load($last_table, $p_uid));
//  print_r($data);exit;
  if (!empty($form_state['values'][$e1_1])) {
    if (crf_ds_s_time($form_state['values'][$e1_1]) < $data[1][4]) {
      form_set_error($e1_1, "给药日期要大于{$last_zq_name}给药的日期！");
    }
    if (crf_ds_s_time($form_state['values'][$e1_1]) >= crf_ds_s_time($form_state['values'][$e1_2])) {
      form_set_error($e1_2, "结束日期应大于起始日期！");
    }
  }  
}

function _check_zq_date_2(&$form_state, $last_table, $e1_1, $e1_2, $last_zq_name) {
  $p_uid = crf_ds_s_data('p_uid');
  $data = json_to_array(crf_ds_load($last_table, $p_uid));
//  print_r($data);exit;
  if (!empty($form_state['values'][$e1_1])) {
    if (crf_ds_s_time($form_state['values'][$e1_1]) < $data[3][2]) {
      form_set_error($e1_1, "给药日期要大于{$last_zq_name}给药的日期！");
    }
    if (crf_ds_s_time($form_state['values'][$e1_1]) >= crf_ds_s_time($form_state['values'][$e1_2])) {
      form_set_error($e1_2, "结束日期应大于起始日期！");
    }
  }  
}

function _check_zq_jianliang(&$form_state, $check_field, $text_field) {
  if ($form_state['values'][$check_field][1] != 0 || $form_state['values'][$check_field][2] != 0) {
    if (empty($form_state['values'][$text_field]))
    form_set_error($text_field, "如果选择了减量或延迟，必须填写主要原因！");
  }
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
  $p_uid = crf_ds_s_data('p_uid');
  $data = json_to_array(crf_ds_load('zq1_1', $p_uid));
//  if (!empty($form_state['values']['e_xueqing_zlbzwjc_1_1']) && (!empty($data[1][1]) || !empty($data[2][2]))) {
//    if ($form_state['values']['e_xueqing_zlbzwjc_1_1'] > $data[1][1] || $form_state['values']['e_xueqing_zlbzwjc_1_1'] > $data[2][2]) {
//      form_set_error('e_xueqing_zlbzwjc_1_1', "检查日期不能大于第一周期给药的日期！");
//    }
//  }
  
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
  $p_uid = crf_ds_s_data('p_uid');
  $data = json_to_array(crf_ds_load('zq1_1', $p_uid));
//  if (!empty($form_state['values']['e_shiyan_sjc_1_1']) && (!empty($data[1][1]) || !empty($data[2][2]))) {
//    if ($form_state['values']['e_shiyan_sjc_1_1'] > $data[1][1] || $form_state['values']['e_shiyan_sjc_1_1'] > $data[2][2]) {
//      form_set_error('e_shiyan_sjc_1_1', "检查日期不能大于第一周期给药的日期！");
//    }
//  }
  $check_field = array('e_shiyan_sjc_2_1', 'e_shiyan_sjc_3_1', 'e_shiyan_sjc_4_1', 'e_shiyan_sjc_5_1', 'e_shiyan_sjc_6_1', 'e_shiyan_sjc_7_1', 
      'e_shiyan_sjc_9_1', 'e_shiyan_sjc_11_1', 'e_shiyan_sjc_12_1', 'e_shiyan_sjc_13_1', 'e_shiyan_sjc_14_1', 'e_shiyan_sjc_15_1', 'e_shiyan_sjc_16_1',
      'e_shiyan_sjc_17_1', 'e_shiyan_sjc_18_1', 'e_shiyan_sjc_19_1', 'e_shiyan_sjc_20_1', 'e_shiyan_sjc_21_1', 'e_shiyan_sjc_22_1', 'e_shiyan_sjc_23_1',
      'e_shiyan_sjc_24_1', 'e_shiyan_sjc_26_1');
  $field_name = array('白细胞计数WBC', '中性粒细胞计数ANC', '血红蛋白HBG', '红细胞计数RBC', '红细胞压积', '血小板计数PLT', 'INR(华法令治疗者须查)',
      '总胆红素TBIL', '直接胆红素CB', '谷丙转氨酶ALT', '谷草转氨酶AST', '总蛋白TP', '白蛋白ALB', '碱性磷酸酶ALP', '乳酸脱氢酶LDH', '尿素BUN', '肌酐CRE', 
      '肌酐清除率Ccr', '钾K<sup>+</sup>', '钠Na<sup>+</sup>', '钙Ca<sup>2+</sup>', '尿蛋白');
  $field_radio = array('e_shiyan_sjc_2_3', 'e_shiyan_sjc_3_3', 'e_shiyan_sjc_4_3', 'e_shiyan_sjc_5_3', 'e_shiyan_sjc_6_2', 'e_shiyan_sjc_7_3', 
      'e_shiyan_sjc_9_2', 'e_shiyan_sjc_11_4', 'e_shiyan_sjc_12_4', 'e_shiyan_sjc_13_4', 'e_shiyan_sjc_14_4', 'e_shiyan_sjc_15_4', 'e_shiyan_sjc_16_4',
      'e_shiyan_sjc_17_4', 'e_shiyan_sjc_18_4', 'e_shiyan_sjc_19_4', 'e_shiyan_sjc_20_4', 'e_shiyan_sjc_21_4', 'e_shiyan_sjc_22_4', 'e_shiyan_sjc_23_4',
      'e_shiyan_sjc_24_4', 'e_shiyan_sjc_26_4');
  
  
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
  $p_uid = crf_ds_s_data('p_uid');
  $data = json_to_array(crf_ds_load('zq1_1', $p_uid));
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
  if (!empty($form_state['values']['e_xindian_tjc_1_1']) && (!empty($data[1][1]) || !empty($data[2][2]))) {
    if ($form_state['values']['e_xindian_tjc_1_1'] > $data[1][1] || $form_state['values']['e_xindian_tjc_1_1'] > $data[2][2]) {
      form_set_error('e_xindian_tjc_1_1', "检查日期不能大于第一周期给药的日期！");
    }
  }
}

function crf_case_validate_quanshen_tgjc($form, &$form_state) {
  $p_uid = crf_ds_s_data('p_uid');
  $data = json_to_array(crf_ds_load('zq1_1', $p_uid));
//  if (!empty($form_state['values']['e_quanshen_tgjc_1_1']) && (!empty($data[1][1]) || !empty($data[2][2]))) {
//    if ($form_state['values']['e_quanshen_tgjc_1_1'] > $data[1][1] || $form_state['values']['e_quanshen_tgjc_1_1'] > $data[2][2]) {
//      form_set_error('e_quanshen_tgjc_1_1', "检查日期不能大于第一周期给药的日期！");
//    }
//  }
  if (strlen($form_state['values']['e_quanshen_tgjc_2_2']) != 3) {
    form_set_error('e_quanshen_tgjc_2_2', "身高必须为3位！");
  }
  if ($form_state['values']['e_quanshen_tgjc_2_2'] > 220) {
    form_set_error('e_quanshen_tgjc_2_2', "请输入合理的身高！");
  }
  if (strlen($form_state['values']['e_quanshen_tgjc_2_1']) != 3 && strlen($form_state['values']['e_quanshen_tgjc_2_1']) != 2) {
    form_set_error('e_quanshen_tgjc_2_1', "体重必须为2位或者3位！");
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

function crf_case_validate_pg1_1($form, &$form_state) {
  _pg_did($form_state, array('e_pg1_1_2_1','e_pg1_1_3_2','e_pg1_1_3_3','e_pg1_1_4_1','e_pg1_1_4_2','e_pg1_1_5_1','e_pg1_1_5_2','e_pg1_1_7_1','e_pg1_1_7_2'));
}
function crf_case_validate_pg2_1($form, &$form_state) {
  _pg_did($form_state, array('e_pg2_1_2_1','e_pg2_1_3_2','e_pg2_1_3_3','e_pg2_1_4_1','e_pg2_1_4_2','e_pg2_1_5_1','e_pg2_1_5_2','e_pg2_1_7_1','e_pg2_1_7_2'));
}
function crf_case_validate_pg3_1($form, &$form_state) {
  _pg_did($form_state, array('e_pg3_1_2_1','e_pg3_1_3_2','e_pg3_1_3_3','e_pg3_1_4_1','e_pg3_1_4_2','e_pg3_1_5_1','e_pg3_1_5_2','e_pg3_1_7_1','e_pg3_1_7_2'));
}
function crf_case_validate_pg4_1($form, &$form_state) {
  _pg_did($form_state, array('e_pg4_1_2_1','e_pg4_1_3_2','e_pg4_1_3_3','e_pg4_1_4_1','e_pg4_1_4_2','e_pg4_1_5_1','e_pg4_1_5_2','e_pg4_1_7_1','e_pg4_1_7_2'));
}
function crf_case_validate_pg5_1($form, &$form_state) {
  _pg_did($form_state, array('e_pg5_1_2_1','e_pg5_1_3_2','e_pg5_1_3_3','e_pg5_1_4_1','e_pg5_1_4_2','e_pg5_1_5_1','e_pg5_1_5_2','e_pg5_1_7_1','e_pg5_1_7_2'));
}

function _pg_did(&$form_state,$arr) {
  if (strlen($form_state['values'][$arr[0]]) != 3 && strlen($form_state['values'][$arr[0]]) != 2) {
    form_set_error($arr[0], "体重必须为2位或者3位！");
  }
  if ($form_state['values'][$arr[0]] > 150) {
    form_set_error($arr[0], "请输入合理的体重！");
  }  
  if (!is_numeric($form_state['values'][$arr[1]])) {
     form_set_error($arr[1], "血压必须为数字！");
  }
  if (!is_numeric($form_state['values'][$arr[2]])) {
     form_set_error($arr[2], "血压必须为数字！");
  }  
  if ($form_state['values'][$arr[3]] == '3') {
    if (empty($form_state['values'][$arr[4]])) {
      form_set_error($arr[4], "必须填写说明！");
    }
  }
  if ($form_state['values'][$arr[5]] == '3') {
    if (empty($form_state['values'][$arr[6]])) {
      form_set_error($arr[6], "必须填写说明！");
    }
  }
  if ($form_state['values'][$arr[7]] == '3') {
    if (empty($form_state['values'][$arr[8]])) {
      form_set_error($arr[8], "必须填写说明！");
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