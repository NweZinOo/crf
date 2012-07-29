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
function crf_case_validate_zq2_1($form, &$form_state) {
  $s = array('e_zq2_1_2_2','e_zq2_1_3_2','e_zq2_1_4_2','e_zq2_1_5_2','e_zq2_1_6_2','e_zq2_1_7_2','e_zq2_1_8_2','e_zq2_1_9_2','e_zq2_1_10_2','e_zq2_1_11_2','e_zq2_1_12_2',
      'e_zq2_1_13_2','e_zq2_1_14_2','e_zq2_1_15_2','e_zq2_1_16_2','e_zq2_1_17_2','e_zq2_1_18_2','e_zq2_1_19_2','e_zq2_1_20_2','e_zq2_1_21_2','e_zq2_1_22_2','e_zq2_1_23_2',
      'e_zq2_1_24_2','e_zq2_1_25_2','e_zq2_1_26_2','e_zq2_1_27_3','e_zq2_1_28_3','e_zq2_1_29_3');
  $t = array('e_zq2_1_2_3','e_zq2_1_3_3','e_zq2_1_4_3','e_zq2_1_5_3','e_zq2_1_6_3','e_zq2_1_7_3','e_zq2_1_8_3','e_zq2_1_9_3','e_zq2_1_10_3','e_zq2_1_11_3','e_zq2_1_12_3',
      'e_zq2_1_13_3','e_zq2_1_14_3','e_zq2_1_15_3','e_zq2_1_16_3','e_zq2_1_17_3','e_zq2_1_18_3','e_zq2_1_19_3','e_zq2_1_20_3','e_zq2_1_21_3','e_zq2_1_22_3','e_zq2_1_23_3',
      'e_zq2_1_24_3','e_zq2_1_25_3','e_zq2_1_26_3','e_zq2_1_27_4','e_zq2_1_28_4','e_zq2_1_29_4');
  $t2 = array('e_zq2_1_2_4','e_zq2_1_3_4','e_zq2_1_4_4','e_zq2_1_5_4','e_zq2_1_6_4','e_zq2_1_7_4','e_zq2_1_8_4','e_zq2_1_9_4','e_zq2_1_10_4','e_zq2_1_11_4','e_zq2_1_12_4',
      'e_zq2_1_13_4','e_zq2_1_14_4','e_zq2_1_15_4','e_zq2_1_16_4','e_zq2_1_17_4','e_zq2_1_18_4','e_zq2_1_19_4','e_zq2_1_20_4','e_zq2_1_21_4','e_zq2_1_22_4','e_zq2_1_23_4',
      'e_zq2_1_24_4','e_zq2_1_25_4','e_zq2_1_26_4','e_zq2_1_27_4','e_zq2_1_28_4','e_zq2_1_29_4');
  crf_case_zq_clcs($form_state, $s, $t, $t2);
}
function crf_case_validate_zq3_1($form, &$form_state) {
  $s = array('e_zq3_1_2_2','e_zq3_1_3_2','e_zq3_1_4_2','e_zq3_1_5_2','e_zq3_1_6_2','e_zq3_1_7_2','e_zq3_1_8_2','e_zq3_1_9_2','e_zq3_1_10_2','e_zq3_1_11_2','e_zq3_1_12_2',
      'e_zq3_1_13_2','e_zq3_1_14_2','e_zq3_1_15_2','e_zq3_1_16_2','e_zq3_1_17_2','e_zq3_1_18_2','e_zq3_1_19_2','e_zq3_1_20_2','e_zq3_1_21_2','e_zq3_1_22_2','e_zq3_1_23_2',
      'e_zq3_1_24_2','e_zq3_1_25_2','e_zq3_1_26_2','e_zq3_1_27_3','e_zq3_1_28_3','e_zq3_1_29_3');
  $t = array('e_zq3_1_2_3','e_zq3_1_3_3','e_zq3_1_4_3','e_zq3_1_5_3','e_zq3_1_6_3','e_zq3_1_7_3','e_zq3_1_8_3','e_zq3_1_9_3','e_zq3_1_10_3','e_zq3_1_11_3','e_zq3_1_12_3',
      'e_zq3_1_13_3','e_zq3_1_14_3','e_zq3_1_15_3','e_zq3_1_16_3','e_zq3_1_17_3','e_zq3_1_18_3','e_zq3_1_19_3','e_zq3_1_20_3','e_zq3_1_21_3','e_zq3_1_22_3','e_zq3_1_23_3',
      'e_zq3_1_24_3','e_zq3_1_25_3','e_zq3_1_26_3','e_zq3_1_27_4','e_zq3_1_28_4','e_zq3_1_29_4');
  $t2 = array('e_zq3_1_2_4','e_zq3_1_3_4','e_zq3_1_4_4','e_zq3_1_5_4','e_zq3_1_6_4','e_zq3_1_7_4','e_zq3_1_8_4','e_zq3_1_9_4','e_zq3_1_10_4','e_zq3_1_11_4','e_zq3_1_12_4',
      'e_zq3_1_13_4','e_zq3_1_14_4','e_zq3_1_15_4','e_zq3_1_16_4','e_zq3_1_17_4','e_zq3_1_18_4','e_zq3_1_19_4','e_zq3_1_20_4','e_zq3_1_21_4','e_zq3_1_22_4','e_zq3_1_23_4',
      'e_zq3_1_24_4','e_zq3_1_25_4','e_zq3_1_26_4','e_zq3_1_27_4','e_zq3_1_28_4','e_zq3_1_29_4');
  crf_case_zq_clcs($form_state, $s, $t, $t2);
}
function crf_case_validate_zq4_1($form, &$form_state) {
  $s = array('e_zq4_1_2_2','e_zq4_1_3_2','e_zq4_1_4_2','e_zq4_1_5_2','e_zq4_1_6_2','e_zq4_1_7_2','e_zq4_1_8_2','e_zq4_1_9_2','e_zq4_1_10_2','e_zq4_1_11_2','e_zq4_1_12_2',
      'e_zq4_1_13_2','e_zq4_1_14_2','e_zq4_1_15_2','e_zq4_1_16_2','e_zq4_1_17_2','e_zq4_1_18_2','e_zq4_1_19_2','e_zq4_1_20_2','e_zq4_1_21_2','e_zq4_1_22_2','e_zq4_1_23_2',
      'e_zq4_1_24_2','e_zq4_1_25_2','e_zq4_1_26_2','e_zq4_1_27_3','e_zq4_1_28_3','e_zq4_1_29_3');
  $t = array('e_zq4_1_2_3','e_zq4_1_3_3','e_zq4_1_4_3','e_zq4_1_5_3','e_zq4_1_6_3','e_zq4_1_7_3','e_zq4_1_8_3','e_zq4_1_9_3','e_zq4_1_10_3','e_zq4_1_11_3','e_zq4_1_12_3',
      'e_zq4_1_13_3','e_zq4_1_14_3','e_zq4_1_15_3','e_zq4_1_16_3','e_zq4_1_17_3','e_zq4_1_18_3','e_zq4_1_19_3','e_zq4_1_20_3','e_zq4_1_21_3','e_zq4_1_22_3','e_zq4_1_23_3',
      'e_zq4_1_24_3','e_zq4_1_25_3','e_zq4_1_26_3','e_zq4_1_27_4','e_zq4_1_28_4','e_zq4_1_29_4');
  $t2 = array('e_zq4_1_2_4','e_zq4_1_3_4','e_zq4_1_4_4','e_zq4_1_5_4','e_zq4_1_6_4','e_zq4_1_7_4','e_zq4_1_8_4','e_zq4_1_9_4','e_zq4_1_10_4','e_zq4_1_11_4','e_zq4_1_12_4',
      'e_zq4_1_13_4','e_zq4_1_14_4','e_zq4_1_15_4','e_zq4_1_16_4','e_zq4_1_17_4','e_zq4_1_18_4','e_zq4_1_19_4','e_zq4_1_20_4','e_zq4_1_21_4','e_zq4_1_22_4','e_zq4_1_23_4',
      'e_zq4_1_24_4','e_zq4_1_25_4','e_zq4_1_26_4','e_zq4_1_27_4','e_zq4_1_28_4','e_zq4_1_29_4');
  crf_case_zq_clcs($form_state, $s, $t, $t2);
}
function crf_case_validate_zq5_1($form, &$form_state) {
  $s = array('e_zq5_1_2_2','e_zq5_1_3_2','e_zq5_1_4_2','e_zq5_1_5_2','e_zq5_1_6_2','e_zq5_1_7_2','e_zq5_1_8_2','e_zq5_1_9_2','e_zq5_1_10_2','e_zq5_1_11_2','e_zq5_1_12_2',
      'e_zq5_1_13_2','e_zq5_1_14_2','e_zq5_1_15_2','e_zq5_1_16_2','e_zq5_1_17_2','e_zq5_1_18_2','e_zq5_1_19_2','e_zq5_1_20_2','e_zq5_1_21_2','e_zq5_1_22_2','e_zq5_1_23_2',
      'e_zq5_1_24_2','e_zq5_1_25_2','e_zq5_1_26_2','e_zq5_1_27_3','e_zq5_1_28_3','e_zq5_1_29_3');
  $t = array('e_zq5_1_2_3','e_zq5_1_3_3','e_zq5_1_4_3','e_zq5_1_5_3','e_zq5_1_6_3','e_zq5_1_7_3','e_zq5_1_8_3','e_zq5_1_9_3','e_zq5_1_10_3','e_zq5_1_11_3','e_zq5_1_12_3',
      'e_zq5_1_13_3','e_zq5_1_14_3','e_zq5_1_15_3','e_zq5_1_16_3','e_zq5_1_17_3','e_zq5_1_18_3','e_zq5_1_19_3','e_zq5_1_20_3','e_zq5_1_21_3','e_zq5_1_22_3','e_zq5_1_23_3',
      'e_zq5_1_24_3','e_zq5_1_25_3','e_zq5_1_26_3','e_zq5_1_27_4','e_zq5_1_28_4','e_zq5_1_29_4');
  $t2 = array('e_zq5_1_2_4','e_zq5_1_3_4','e_zq5_1_4_4','e_zq5_1_5_4','e_zq5_1_6_4','e_zq5_1_7_4','e_zq5_1_8_4','e_zq5_1_9_4','e_zq5_1_10_4','e_zq5_1_11_4','e_zq5_1_12_4',
      'e_zq5_1_13_4','e_zq5_1_14_4','e_zq5_1_15_4','e_zq5_1_16_4','e_zq5_1_17_4','e_zq5_1_18_4','e_zq5_1_19_4','e_zq5_1_20_4','e_zq5_1_21_4','e_zq5_1_22_4','e_zq5_1_23_4',
      'e_zq5_1_24_4','e_zq5_1_25_4','e_zq5_1_26_4','e_zq5_1_27_4','e_zq5_1_28_4','e_zq5_1_29_4');
  crf_case_zq_clcs($form_state, $s, $t, $t2);
}
function crf_case_validate_zq6_1($form, &$form_state) {
  $s = array('e_zq6_1_2_2','e_zq6_1_3_2','e_zq6_1_4_2','e_zq6_1_5_2','e_zq6_1_6_2','e_zq6_1_7_2','e_zq6_1_8_2','e_zq6_1_9_2','e_zq6_1_10_2','e_zq6_1_11_2','e_zq6_1_12_2',
      'e_zq6_1_13_2','e_zq6_1_14_2','e_zq6_1_15_2','e_zq6_1_16_2','e_zq6_1_17_2','e_zq6_1_18_2','e_zq6_1_19_2','e_zq6_1_20_2','e_zq6_1_21_2','e_zq6_1_22_2','e_zq6_1_23_2',
      'e_zq6_1_24_2','e_zq6_1_25_2','e_zq6_1_26_2','e_zq6_1_27_3','e_zq6_1_28_3','e_zq6_1_29_3');
  $t = array('e_zq6_1_2_3','e_zq6_1_3_3','e_zq6_1_4_3','e_zq6_1_5_3','e_zq6_1_6_3','e_zq6_1_7_3','e_zq6_1_8_3','e_zq6_1_9_3','e_zq6_1_10_3','e_zq6_1_11_3','e_zq6_1_12_3',
      'e_zq6_1_13_3','e_zq6_1_14_3','e_zq6_1_15_3','e_zq6_1_16_3','e_zq6_1_17_3','e_zq6_1_18_3','e_zq6_1_19_3','e_zq6_1_20_3','e_zq6_1_21_3','e_zq6_1_22_3','e_zq6_1_23_3',
      'e_zq6_1_24_3','e_zq6_1_25_3','e_zq6_1_26_3','e_zq6_1_27_4','e_zq6_1_28_4','e_zq6_1_29_4');
  $t2 = array('e_zq6_1_2_4','e_zq6_1_3_4','e_zq6_1_4_4','e_zq6_1_5_4','e_zq6_1_6_4','e_zq6_1_7_4','e_zq6_1_8_4','e_zq6_1_9_4','e_zq6_1_10_4','e_zq6_1_11_4','e_zq6_1_12_4',
      'e_zq6_1_13_4','e_zq6_1_14_4','e_zq6_1_15_4','e_zq6_1_16_4','e_zq6_1_17_4','e_zq6_1_18_4','e_zq6_1_19_4','e_zq6_1_20_4','e_zq6_1_21_4','e_zq6_1_22_4','e_zq6_1_23_4',
      'e_zq6_1_24_4','e_zq6_1_25_4','e_zq6_1_26_4','e_zq6_1_27_4','e_zq6_1_28_4','e_zq6_1_29_4');
  crf_case_zq_clcs($form_state, $s, $t, $t2);
}
function crf_case_validate_zq7_1($form, &$form_state) {
  $s = array('e_zq7_1_2_2','e_zq7_1_3_2','e_zq7_1_4_2','e_zq7_1_5_2','e_zq7_1_6_2','e_zq7_1_7_2','e_zq7_1_8_2','e_zq7_1_9_2','e_zq7_1_10_2','e_zq7_1_11_2','e_zq7_1_12_2',
      'e_zq7_1_13_2','e_zq7_1_14_2','e_zq7_1_15_2','e_zq7_1_16_2','e_zq7_1_17_2','e_zq7_1_18_2','e_zq7_1_19_2','e_zq7_1_20_2','e_zq7_1_21_2','e_zq7_1_22_2','e_zq7_1_23_2',
      'e_zq7_1_24_2','e_zq7_1_25_2','e_zq7_1_26_2','e_zq7_1_27_3','e_zq7_1_28_3','e_zq7_1_29_3');
  $t = array('e_zq7_1_2_3','e_zq7_1_3_3','e_zq7_1_4_3','e_zq7_1_5_3','e_zq7_1_6_3','e_zq7_1_7_3','e_zq7_1_8_3','e_zq7_1_9_3','e_zq7_1_10_3','e_zq7_1_11_3','e_zq7_1_12_3',
      'e_zq7_1_13_3','e_zq7_1_14_3','e_zq7_1_15_3','e_zq7_1_16_3','e_zq7_1_17_3','e_zq7_1_18_3','e_zq7_1_19_3','e_zq7_1_20_3','e_zq7_1_21_3','e_zq7_1_22_3','e_zq7_1_23_3',
      'e_zq7_1_24_3','e_zq7_1_25_3','e_zq7_1_26_3','e_zq7_1_27_4','e_zq7_1_28_4','e_zq7_1_29_4');
  $t2 = array('e_zq7_1_2_4','e_zq7_1_3_4','e_zq7_1_4_4','e_zq7_1_5_4','e_zq7_1_6_4','e_zq7_1_7_4','e_zq7_1_8_4','e_zq7_1_9_4','e_zq7_1_10_4','e_zq7_1_11_4','e_zq7_1_12_4',
      'e_zq7_1_13_4','e_zq7_1_14_4','e_zq7_1_15_4','e_zq7_1_16_4','e_zq7_1_17_4','e_zq7_1_18_4','e_zq7_1_19_4','e_zq7_1_20_4','e_zq7_1_21_4','e_zq7_1_22_4','e_zq7_1_23_4',
      'e_zq7_1_24_4','e_zq7_1_25_4','e_zq7_1_26_4','e_zq7_1_27_4','e_zq7_1_28_4','e_zq7_1_29_4');
  crf_case_zq_clcs($form_state, $s, $t, $t2);
}
function crf_case_validate_zq8_1($form, &$form_state) {
  $s = array('e_zq8_1_2_2','e_zq8_1_3_2','e_zq8_1_4_2','e_zq8_1_5_2','e_zq8_1_6_2','e_zq8_1_7_2','e_zq8_1_8_2','e_zq8_1_9_2','e_zq8_1_10_2','e_zq8_1_11_2','e_zq8_1_12_2',
      'e_zq8_1_13_2','e_zq8_1_14_2','e_zq8_1_15_2','e_zq8_1_16_2','e_zq8_1_17_2','e_zq8_1_18_2','e_zq8_1_19_2','e_zq8_1_20_2','e_zq8_1_21_2','e_zq8_1_22_2','e_zq8_1_23_2',
      'e_zq8_1_24_2','e_zq8_1_25_2','e_zq8_1_26_2','e_zq8_1_27_3','e_zq8_1_28_3','e_zq8_1_29_3');
  $t = array('e_zq8_1_2_3','e_zq8_1_3_3','e_zq8_1_4_3','e_zq8_1_5_3','e_zq8_1_6_3','e_zq8_1_7_3','e_zq8_1_8_3','e_zq8_1_9_3','e_zq8_1_10_3','e_zq8_1_11_3','e_zq8_1_12_3',
      'e_zq8_1_13_3','e_zq8_1_14_3','e_zq8_1_15_3','e_zq8_1_16_3','e_zq8_1_17_3','e_zq8_1_18_3','e_zq8_1_19_3','e_zq8_1_20_3','e_zq8_1_21_3','e_zq8_1_22_3','e_zq8_1_23_3',
      'e_zq8_1_24_3','e_zq8_1_25_3','e_zq8_1_26_3','e_zq8_1_27_4','e_zq8_1_28_4','e_zq8_1_29_4');
  $t2 = array('e_zq8_1_2_4','e_zq8_1_3_4','e_zq8_1_4_4','e_zq8_1_5_4','e_zq8_1_6_4','e_zq8_1_7_4','e_zq8_1_8_4','e_zq8_1_9_4','e_zq8_1_10_4','e_zq8_1_11_4','e_zq8_1_12_4',
      'e_zq8_1_13_4','e_zq8_1_14_4','e_zq8_1_15_4','e_zq8_1_16_4','e_zq8_1_17_4','e_zq8_1_18_4','e_zq8_1_19_4','e_zq8_1_20_4','e_zq8_1_21_4','e_zq8_1_22_4','e_zq8_1_23_4',
      'e_zq8_1_24_4','e_zq8_1_25_4','e_zq8_1_26_4','e_zq8_1_27_4','e_zq8_1_28_4','e_zq8_1_29_4');
  crf_case_zq_clcs($form_state, $s, $t, $t2);
}
function crf_case_validate_zq9_1($form, &$form_state) {
  $s = array('e_zq9_1_2_2','e_zq9_1_3_2','e_zq9_1_4_2','e_zq9_1_5_2','e_zq9_1_6_2','e_zq9_1_7_2','e_zq9_1_8_2','e_zq9_1_9_2','e_zq9_1_10_2','e_zq9_1_11_2','e_zq9_1_12_2',
      'e_zq9_1_13_2','e_zq9_1_14_2','e_zq9_1_15_2','e_zq9_1_16_2','e_zq9_1_17_2','e_zq9_1_18_2','e_zq9_1_19_2','e_zq9_1_20_2','e_zq9_1_21_2','e_zq9_1_22_2','e_zq9_1_23_2',
      'e_zq9_1_24_2','e_zq9_1_25_2','e_zq9_1_26_2','e_zq9_1_27_3','e_zq9_1_28_3','e_zq9_1_29_3');
  $t = array('e_zq9_1_2_3','e_zq9_1_3_3','e_zq9_1_4_3','e_zq9_1_5_3','e_zq9_1_6_3','e_zq9_1_7_3','e_zq9_1_8_3','e_zq9_1_9_3','e_zq9_1_10_3','e_zq9_1_11_3','e_zq9_1_12_3',
      'e_zq9_1_13_3','e_zq9_1_14_3','e_zq9_1_15_3','e_zq9_1_16_3','e_zq9_1_17_3','e_zq9_1_18_3','e_zq9_1_19_3','e_zq9_1_20_3','e_zq9_1_21_3','e_zq9_1_22_3','e_zq9_1_23_3',
      'e_zq9_1_24_3','e_zq9_1_25_3','e_zq9_1_26_3','e_zq9_1_27_4','e_zq9_1_28_4','e_zq9_1_29_4');
  $t2 = array('e_zq9_1_2_4','e_zq9_1_3_4','e_zq9_1_4_4','e_zq9_1_5_4','e_zq9_1_6_4','e_zq9_1_7_4','e_zq9_1_8_4','e_zq9_1_9_4','e_zq9_1_10_4','e_zq9_1_11_4','e_zq9_1_12_4',
      'e_zq9_1_13_4','e_zq9_1_14_4','e_zq9_1_15_4','e_zq9_1_16_4','e_zq9_1_17_4','e_zq9_1_18_4','e_zq9_1_19_4','e_zq9_1_20_4','e_zq9_1_21_4','e_zq9_1_22_4','e_zq9_1_23_4',
      'e_zq9_1_24_4','e_zq9_1_25_4','e_zq9_1_26_4','e_zq9_1_27_4','e_zq9_1_28_4','e_zq9_1_29_4');
  crf_case_zq_clcs($form_state, $s, $t, $t2);
}
function crf_case_validate_zq10_1($form, &$form_state) {
  $s = array('e_zq10_1_2_2','e_zq10_1_3_2','e_zq10_1_4_2','e_zq10_1_5_2','e_zq10_1_6_2','e_zq10_1_7_2','e_zq10_1_8_2','e_zq10_1_9_2','e_zq10_1_10_2','e_zq10_1_11_2','e_zq10_1_12_2',
      'e_zq10_1_13_2','e_zq10_1_14_2','e_zq10_1_15_2','e_zq10_1_16_2','e_zq10_1_17_2','e_zq10_1_18_2','e_zq10_1_19_2','e_zq10_1_20_2','e_zq10_1_21_2','e_zq10_1_22_2','e_zq10_1_23_2',
      'e_zq10_1_24_2','e_zq10_1_25_2','e_zq10_1_26_2','e_zq10_1_27_3','e_zq10_1_28_3','e_zq10_1_29_3');
  $t = array('e_zq10_1_2_3','e_zq10_1_3_3','e_zq10_1_4_3','e_zq10_1_5_3','e_zq10_1_6_3','e_zq10_1_7_3','e_zq10_1_8_3','e_zq10_1_9_3','e_zq10_1_10_3','e_zq10_1_11_3','e_zq10_1_12_3',
      'e_zq10_1_13_3','e_zq10_1_14_3','e_zq10_1_15_3','e_zq10_1_16_3','e_zq10_1_17_3','e_zq10_1_18_3','e_zq10_1_19_3','e_zq10_1_20_3','e_zq10_1_21_3','e_zq10_1_22_3','e_zq10_1_23_3',
      'e_zq10_1_24_3','e_zq10_1_25_3','e_zq10_1_26_3','e_zq10_1_27_4','e_zq10_1_28_4','e_zq10_1_29_4');
  $t2 = array('e_zq10_1_2_4','e_zq10_1_3_4','e_zq10_1_4_4','e_zq10_1_5_4','e_zq10_1_6_4','e_zq10_1_7_4','e_zq10_1_8_4','e_zq10_1_9_4','e_zq10_1_10_4','e_zq10_1_11_4','e_zq10_1_12_4',
      'e_zq10_1_13_4','e_zq10_1_14_4','e_zq10_1_15_4','e_zq10_1_16_4','e_zq10_1_17_4','e_zq10_1_18_4','e_zq10_1_19_4','e_zq10_1_20_4','e_zq10_1_21_4','e_zq10_1_22_4','e_zq10_1_23_4',
      'e_zq10_1_24_4','e_zq10_1_25_4','e_zq10_1_26_4','e_zq10_1_27_4','e_zq10_1_28_4','e_zq10_1_29_4');
  crf_case_zq_clcs($form_state, $s, $t, $t2);
}
function crf_case_validate_zq11_1($form, &$form_state) {
  $s = array('e_zq11_1_2_2','e_zq11_1_3_2','e_zq11_1_4_2','e_zq11_1_5_2','e_zq11_1_6_2','e_zq11_1_7_2','e_zq11_1_8_2','e_zq11_1_9_2','e_zq11_1_10_2','e_zq11_1_11_2','e_zq11_1_12_2',
      'e_zq11_1_13_2','e_zq11_1_14_2','e_zq11_1_15_2','e_zq11_1_16_2','e_zq11_1_17_2','e_zq11_1_18_2','e_zq11_1_19_2','e_zq11_1_20_2','e_zq11_1_21_2','e_zq11_1_22_2','e_zq11_1_23_2',
      'e_zq11_1_24_2','e_zq11_1_25_2','e_zq11_1_26_2','e_zq11_1_27_3','e_zq11_1_28_3','e_zq11_1_29_3');
  $t = array('e_zq11_1_2_3','e_zq11_1_3_3','e_zq11_1_4_3','e_zq11_1_5_3','e_zq11_1_6_3','e_zq11_1_7_3','e_zq11_1_8_3','e_zq11_1_9_3','e_zq11_1_10_3','e_zq11_1_11_3','e_zq11_1_12_3',
      'e_zq11_1_13_3','e_zq11_1_14_3','e_zq11_1_15_3','e_zq11_1_16_3','e_zq11_1_17_3','e_zq11_1_18_3','e_zq11_1_19_3','e_zq11_1_20_3','e_zq11_1_21_3','e_zq11_1_22_3','e_zq11_1_23_3',
      'e_zq11_1_24_3','e_zq11_1_25_3','e_zq11_1_26_3','e_zq11_1_27_4','e_zq11_1_28_4','e_zq11_1_29_4');
  $t2 = array('e_zq11_1_2_4','e_zq11_1_3_4','e_zq11_1_4_4','e_zq11_1_5_4','e_zq11_1_6_4','e_zq11_1_7_4','e_zq11_1_8_4','e_zq11_1_9_4','e_zq11_1_10_4','e_zq11_1_11_4','e_zq11_1_12_4',
      'e_zq11_1_13_4','e_zq11_1_14_4','e_zq11_1_15_4','e_zq11_1_16_4','e_zq11_1_17_4','e_zq11_1_18_4','e_zq11_1_19_4','e_zq11_1_20_4','e_zq11_1_21_4','e_zq11_1_22_4','e_zq11_1_23_4',
      'e_zq11_1_24_4','e_zq11_1_25_4','e_zq11_1_26_4','e_zq11_1_27_4','e_zq11_1_28_4','e_zq11_1_29_4');
  crf_case_zq_clcs($form_state, $s, $t, $t2);
}
function crf_case_validate_zq12_1($form, &$form_state) {
  $s = array('e_zq12_1_2_2','e_zq12_1_3_2','e_zq12_1_4_2','e_zq12_1_5_2','e_zq12_1_6_2','e_zq12_1_7_2','e_zq12_1_8_2','e_zq12_1_9_2','e_zq12_1_10_2','e_zq12_1_11_2','e_zq12_1_12_2',
      'e_zq12_1_13_2','e_zq12_1_14_2','e_zq12_1_15_2','e_zq12_1_16_2','e_zq12_1_17_2','e_zq12_1_18_2','e_zq12_1_19_2','e_zq12_1_20_2','e_zq12_1_21_2','e_zq12_1_22_2','e_zq12_1_23_2',
      'e_zq12_1_24_2','e_zq12_1_25_2','e_zq12_1_26_2','e_zq12_1_27_3','e_zq12_1_28_3','e_zq12_1_29_3');
  $t = array('e_zq12_1_2_3','e_zq12_1_3_3','e_zq12_1_4_3','e_zq12_1_5_3','e_zq12_1_6_3','e_zq12_1_7_3','e_zq12_1_8_3','e_zq12_1_9_3','e_zq12_1_10_3','e_zq12_1_11_3','e_zq12_1_12_3',
      'e_zq12_1_13_3','e_zq12_1_14_3','e_zq12_1_15_3','e_zq12_1_16_3','e_zq12_1_17_3','e_zq12_1_18_3','e_zq12_1_19_3','e_zq12_1_20_3','e_zq12_1_21_3','e_zq12_1_22_3','e_zq12_1_23_3',
      'e_zq12_1_24_3','e_zq12_1_25_3','e_zq12_1_26_3','e_zq12_1_27_4','e_zq12_1_28_4','e_zq12_1_29_4');
  $t2 = array('e_zq12_1_2_4','e_zq12_1_3_4','e_zq12_1_4_4','e_zq12_1_5_4','e_zq12_1_6_4','e_zq12_1_7_4','e_zq12_1_8_4','e_zq12_1_9_4','e_zq12_1_10_4','e_zq12_1_11_4','e_zq12_1_12_4',
      'e_zq12_1_13_4','e_zq12_1_14_4','e_zq12_1_15_4','e_zq12_1_16_4','e_zq12_1_17_4','e_zq12_1_18_4','e_zq12_1_19_4','e_zq12_1_20_4','e_zq12_1_21_4','e_zq12_1_22_4','e_zq12_1_23_4',
      'e_zq12_1_24_4','e_zq12_1_25_4','e_zq12_1_26_4','e_zq12_1_27_4','e_zq12_1_28_4','e_zq12_1_29_4');
  crf_case_zq_clcs($form_state, $s, $t, $t2);
}
function crf_case_validate_zq13_1($form, &$form_state) {
  $s = array('e_zq13_1_2_2','e_zq13_1_3_2','e_zq13_1_4_2','e_zq13_1_5_2','e_zq13_1_6_2','e_zq13_1_7_2','e_zq13_1_8_2','e_zq13_1_9_2','e_zq13_1_10_2','e_zq13_1_11_2','e_zq13_1_12_2',
      'e_zq13_1_13_2','e_zq13_1_14_2','e_zq13_1_15_2','e_zq13_1_16_2','e_zq13_1_17_2','e_zq13_1_18_2','e_zq13_1_19_2','e_zq13_1_20_2','e_zq13_1_21_2','e_zq13_1_22_2','e_zq13_1_23_2',
      'e_zq13_1_24_2','e_zq13_1_25_2','e_zq13_1_26_2','e_zq13_1_27_3','e_zq13_1_28_3','e_zq13_1_29_3');
  $t = array('e_zq13_1_2_3','e_zq13_1_3_3','e_zq13_1_4_3','e_zq13_1_5_3','e_zq13_1_6_3','e_zq13_1_7_3','e_zq13_1_8_3','e_zq13_1_9_3','e_zq13_1_10_3','e_zq13_1_11_3','e_zq13_1_12_3',
      'e_zq13_1_13_3','e_zq13_1_14_3','e_zq13_1_15_3','e_zq13_1_16_3','e_zq13_1_17_3','e_zq13_1_18_3','e_zq13_1_19_3','e_zq13_1_20_3','e_zq13_1_21_3','e_zq13_1_22_3','e_zq13_1_23_3',
      'e_zq13_1_24_3','e_zq13_1_25_3','e_zq13_1_26_3','e_zq13_1_27_4','e_zq13_1_28_4','e_zq13_1_29_4');
  $t2 = array('e_zq13_1_2_4','e_zq13_1_3_4','e_zq13_1_4_4','e_zq13_1_5_4','e_zq13_1_6_4','e_zq13_1_7_4','e_zq13_1_8_4','e_zq13_1_9_4','e_zq13_1_10_4','e_zq13_1_11_4','e_zq13_1_12_4',
      'e_zq13_1_13_4','e_zq13_1_14_4','e_zq13_1_15_4','e_zq13_1_16_4','e_zq13_1_17_4','e_zq13_1_18_4','e_zq13_1_19_4','e_zq13_1_20_4','e_zq13_1_21_4','e_zq13_1_22_4','e_zq13_1_23_4',
      'e_zq13_1_24_4','e_zq13_1_25_4','e_zq13_1_26_4','e_zq13_1_27_4','e_zq13_1_28_4','e_zq13_1_29_4');
  crf_case_zq_clcs($form_state, $s, $t, $t2);
}
function crf_case_validate_zq14_1($form, &$form_state) {
  $s = array('e_zq14_1_2_2','e_zq14_1_3_2','e_zq14_1_4_2','e_zq14_1_5_2','e_zq14_1_6_2','e_zq14_1_7_2','e_zq14_1_8_2','e_zq14_1_9_2','e_zq14_1_10_2','e_zq14_1_11_2','e_zq14_1_12_2',
      'e_zq14_1_13_2','e_zq14_1_14_2','e_zq14_1_15_2','e_zq14_1_16_2','e_zq14_1_17_2','e_zq14_1_18_2','e_zq14_1_19_2','e_zq14_1_20_2','e_zq14_1_21_2','e_zq14_1_22_2','e_zq14_1_23_2',
      'e_zq14_1_24_2','e_zq14_1_25_2','e_zq14_1_26_2','e_zq14_1_27_3','e_zq14_1_28_3','e_zq14_1_29_3');
  $t = array('e_zq14_1_2_3','e_zq14_1_3_3','e_zq14_1_4_3','e_zq14_1_5_3','e_zq14_1_6_3','e_zq14_1_7_3','e_zq14_1_8_3','e_zq14_1_9_3','e_zq14_1_10_3','e_zq14_1_11_3','e_zq14_1_12_3',
      'e_zq14_1_13_3','e_zq14_1_14_3','e_zq14_1_15_3','e_zq14_1_16_3','e_zq14_1_17_3','e_zq14_1_18_3','e_zq14_1_19_3','e_zq14_1_20_3','e_zq14_1_21_3','e_zq14_1_22_3','e_zq14_1_23_3',
      'e_zq14_1_24_3','e_zq14_1_25_3','e_zq14_1_26_3','e_zq14_1_27_4','e_zq14_1_28_4','e_zq14_1_29_4');
  $t2 = array('e_zq14_1_2_4','e_zq14_1_3_4','e_zq14_1_4_4','e_zq14_1_5_4','e_zq14_1_6_4','e_zq14_1_7_4','e_zq14_1_8_4','e_zq14_1_9_4','e_zq14_1_10_4','e_zq14_1_11_4','e_zq14_1_12_4',
      'e_zq14_1_13_4','e_zq14_1_14_4','e_zq14_1_15_4','e_zq14_1_16_4','e_zq14_1_17_4','e_zq14_1_18_4','e_zq14_1_19_4','e_zq14_1_20_4','e_zq14_1_21_4','e_zq14_1_22_4','e_zq14_1_23_4',
      'e_zq14_1_24_4','e_zq14_1_25_4','e_zq14_1_26_4','e_zq14_1_27_4','e_zq14_1_28_4','e_zq14_1_29_4');
  crf_case_zq_clcs($form_state, $s, $t, $t2);
}
function crf_case_validate_zq15_1($form, &$form_state) {
  $s = array('e_zq15_1_2_2','e_zq15_1_3_2','e_zq15_1_4_2','e_zq15_1_5_2','e_zq15_1_6_2','e_zq15_1_7_2','e_zq15_1_8_2','e_zq15_1_9_2','e_zq15_1_10_2','e_zq15_1_11_2','e_zq15_1_12_2',
      'e_zq15_1_13_2','e_zq15_1_14_2','e_zq15_1_15_2','e_zq15_1_16_2','e_zq15_1_17_2','e_zq15_1_18_2','e_zq15_1_19_2','e_zq15_1_20_2','e_zq15_1_21_2','e_zq15_1_22_2','e_zq15_1_23_2',
      'e_zq15_1_24_2','e_zq15_1_25_2','e_zq15_1_26_2','e_zq15_1_27_3','e_zq15_1_28_3','e_zq15_1_29_3');
  $t = array('e_zq15_1_2_3','e_zq15_1_3_3','e_zq15_1_4_3','e_zq15_1_5_3','e_zq15_1_6_3','e_zq15_1_7_3','e_zq15_1_8_3','e_zq15_1_9_3','e_zq15_1_10_3','e_zq15_1_11_3','e_zq15_1_12_3',
      'e_zq15_1_13_3','e_zq15_1_14_3','e_zq15_1_15_3','e_zq15_1_16_3','e_zq15_1_17_3','e_zq15_1_18_3','e_zq15_1_19_3','e_zq15_1_20_3','e_zq15_1_21_3','e_zq15_1_22_3','e_zq15_1_23_3',
      'e_zq15_1_24_3','e_zq15_1_25_3','e_zq15_1_26_3','e_zq15_1_27_4','e_zq15_1_28_4','e_zq15_1_29_4');
  $t2 = array('e_zq15_1_2_4','e_zq15_1_3_4','e_zq15_1_4_4','e_zq15_1_5_4','e_zq15_1_6_4','e_zq15_1_7_4','e_zq15_1_8_4','e_zq15_1_9_4','e_zq15_1_10_4','e_zq15_1_11_4','e_zq15_1_12_4',
      'e_zq15_1_13_4','e_zq15_1_14_4','e_zq15_1_15_4','e_zq15_1_16_4','e_zq15_1_17_4','e_zq15_1_18_4','e_zq15_1_19_4','e_zq15_1_20_4','e_zq15_1_21_4','e_zq15_1_22_4','e_zq15_1_23_4',
      'e_zq15_1_24_4','e_zq15_1_25_4','e_zq15_1_26_4','e_zq15_1_27_4','e_zq15_1_28_4','e_zq15_1_29_4');
  crf_case_zq_clcs($form_state, $s, $t, $t2);
}
function crf_case_validate_zq16_1($form, &$form_state) {
  $s = array('e_zq16_1_2_2','e_zq16_1_3_2','e_zq16_1_4_2','e_zq16_1_5_2','e_zq16_1_6_2','e_zq16_1_7_2','e_zq16_1_8_2','e_zq16_1_9_2','e_zq16_1_10_2','e_zq16_1_11_2','e_zq16_1_12_2',
      'e_zq16_1_13_2','e_zq16_1_14_2','e_zq16_1_15_2','e_zq16_1_16_2','e_zq16_1_17_2','e_zq16_1_18_2','e_zq16_1_19_2','e_zq16_1_20_2','e_zq16_1_21_2','e_zq16_1_22_2','e_zq16_1_23_2',
      'e_zq16_1_24_2','e_zq16_1_25_2','e_zq16_1_26_2','e_zq16_1_27_3','e_zq16_1_28_3','e_zq16_1_29_3');
  $t = array('e_zq16_1_2_3','e_zq16_1_3_3','e_zq16_1_4_3','e_zq16_1_5_3','e_zq16_1_6_3','e_zq16_1_7_3','e_zq16_1_8_3','e_zq16_1_9_3','e_zq16_1_10_3','e_zq16_1_11_3','e_zq16_1_12_3',
      'e_zq16_1_13_3','e_zq16_1_14_3','e_zq16_1_15_3','e_zq16_1_16_3','e_zq16_1_17_3','e_zq16_1_18_3','e_zq16_1_19_3','e_zq16_1_20_3','e_zq16_1_21_3','e_zq16_1_22_3','e_zq16_1_23_3',
      'e_zq16_1_24_3','e_zq16_1_25_3','e_zq16_1_26_3','e_zq16_1_27_4','e_zq16_1_28_4','e_zq16_1_29_4');
  $t2 = array('e_zq16_1_2_4','e_zq16_1_3_4','e_zq16_1_4_4','e_zq16_1_5_4','e_zq16_1_6_4','e_zq16_1_7_4','e_zq16_1_8_4','e_zq16_1_9_4','e_zq16_1_10_4','e_zq16_1_11_4','e_zq16_1_12_4',
      'e_zq16_1_13_4','e_zq16_1_14_4','e_zq16_1_15_4','e_zq16_1_16_4','e_zq16_1_17_4','e_zq16_1_18_4','e_zq16_1_19_4','e_zq16_1_20_4','e_zq16_1_21_4','e_zq16_1_22_4','e_zq16_1_23_4',
      'e_zq16_1_24_4','e_zq16_1_25_4','e_zq16_1_26_4','e_zq16_1_27_4','e_zq16_1_28_4','e_zq16_1_29_4');
  crf_case_zq_clcs($form_state, $s, $t, $t2);
}
function crf_case_zq_clcs($form_state, $s, $t, $t2) {
  foreach ($s as $k => $v) {
    if ($form_state['values'][$v] == '5') {
      if (empty($form_state['values'][$t[$k]])) {
        form_set_error($t[$k], "处理措施如选择其它须填写说明！");
      }
    }
    if ($form_state['values'][$v] == '4') {
      if (empty($form_state['values'][$t2[$k]])) {
        form_set_error($t2[$k], "处理措施如选择停药须填写药物名称！");
      }
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
  $arr_i1 = array('e_zq2_3_2_1', 'e_zq2_3_2_2', 'e_zq2_3_2_3', 'e_zq2_3_2_4');
  $arr_i2 = array('e_zq2_3_3_1', 'e_zq2_3_3_2', 'e_zq2_3_3_3', 'e_zq2_3_3_4');
  $arr_i3 = array('e_zq2_3_4_1', 'e_zq2_3_4_2', 'e_zq2_3_4_4', 'e_zq2_3_4_5');
  _zqx_i3($form_state, $arr_i1);
  _zqx_i3($form_state, $arr_i2);
  _zqx_i3($form_state, $arr_i3);
  $arr_i4 = array('e_zq2_3_5_1','e_zq2_3_5_2', 'e_zq2_3_5_3', 'e_zq2_3_5_4', 'e_zq2_3_5_5');
  $arr_i5 = array('e_zq2_3_6_1','e_zq2_3_6_2', 'e_zq2_3_6_3', 'e_zq2_3_6_4', 'e_zq2_3_6_5');
  $arr_i6 = array('e_zq2_3_7_1','e_zq2_3_7_2', 'e_zq2_3_7_3', 'e_zq2_3_7_4', 'e_zq2_3_7_5');
  _zqx_i3_1($form_state, $arr_i4);
  _zqx_i3_1($form_state, $arr_i5);
  _zqx_i3_1($form_state, $arr_i6);
  _other_no_empty($form_state, 'e_zq2_3_4_2', 1 ,'e_zq2_3_4_3');
}
function crf_case_validate_zq3_3($form, &$form_state) {
  $arr_i1 = array('e_zq3_3_2_1', 'e_zq3_3_2_2', 'e_zq3_3_2_3', 'e_zq3_3_2_4');
  $arr_i2 = array('e_zq3_3_3_1', 'e_zq3_3_3_2', 'e_zq3_3_3_3', 'e_zq3_3_3_4');
  $arr_i3 = array('e_zq3_3_4_1', 'e_zq3_3_4_2', 'e_zq3_3_4_4', 'e_zq3_3_4_5');
  _zqx_i3($form_state, $arr_i1);
  _zqx_i3($form_state, $arr_i2);
  _zqx_i3($form_state, $arr_i3);
  $arr_i4 = array('e_zq3_3_5_1','e_zq3_3_5_2', 'e_zq3_3_5_3', 'e_zq3_3_5_4', 'e_zq3_3_5_5');
  $arr_i5 = array('e_zq3_3_6_1','e_zq3_3_6_2', 'e_zq3_3_6_3', 'e_zq3_3_6_4', 'e_zq3_3_6_5');
  $arr_i6 = array('e_zq3_3_7_1','e_zq3_3_7_2', 'e_zq3_3_7_3', 'e_zq3_3_7_4', 'e_zq3_3_7_5');
  _zqx_i3_1($form_state, $arr_i4);
  _zqx_i3_1($form_state, $arr_i5);
  _zqx_i3_1($form_state, $arr_i6);
  _other_no_empty($form_state, 'e_zq3_3_4_2', 1 ,'e_zq3_3_4_3');
}
function crf_case_validate_zq4_3($form, &$form_state) {
  $arr_i1 = array('e_zq4_3_2_1', 'e_zq4_3_2_2', 'e_zq4_3_2_3', 'e_zq4_3_2_4');
  $arr_i2 = array('e_zq4_3_3_1', 'e_zq4_3_3_2', 'e_zq4_3_3_3', 'e_zq4_3_3_4');
  $arr_i3 = array('e_zq4_3_4_1', 'e_zq4_3_4_2', 'e_zq4_3_4_4', 'e_zq4_3_4_5');
  _zqx_i3($form_state, $arr_i1);
  _zqx_i3($form_state, $arr_i2);
  _zqx_i3($form_state, $arr_i3);
  $arr_i4 = array('e_zq4_3_5_1','e_zq4_3_5_2', 'e_zq4_3_5_3', 'e_zq4_3_5_4', 'e_zq4_3_5_5');
  $arr_i5 = array('e_zq4_3_6_1','e_zq4_3_6_2', 'e_zq4_3_6_3', 'e_zq4_3_6_4', 'e_zq4_3_6_5');
  $arr_i6 = array('e_zq4_3_7_1','e_zq4_3_7_2', 'e_zq4_3_7_3', 'e_zq4_3_7_4', 'e_zq4_3_7_5');
  _zqx_i3_1($form_state, $arr_i4);
  _zqx_i3_1($form_state, $arr_i5);
  _zqx_i3_1($form_state, $arr_i6);
  _other_no_empty($form_state, 'e_zq4_3_4_2', 1 ,'e_zq4_3_4_3');
}
function crf_case_validate_zq5_3($form, &$form_state) {
  $arr_i1 = array('e_zq5_3_2_1', 'e_zq5_3_2_2', 'e_zq5_3_2_3', 'e_zq5_3_2_4');
  $arr_i2 = array('e_zq5_3_3_1', 'e_zq5_3_3_2', 'e_zq5_3_3_3', 'e_zq5_3_3_4');
  $arr_i3 = array('e_zq5_3_4_1', 'e_zq5_3_4_2', 'e_zq5_3_4_4', 'e_zq5_3_4_5');
  _zqx_i3($form_state, $arr_i1);
  _zqx_i3($form_state, $arr_i2);
  _zqx_i3($form_state, $arr_i3);
  $arr_i4 = array('e_zq5_3_5_1','e_zq5_3_5_2', 'e_zq5_3_5_3', 'e_zq5_3_5_4', 'e_zq5_3_5_5');
  $arr_i5 = array('e_zq5_3_6_1','e_zq5_3_6_2', 'e_zq5_3_6_3', 'e_zq5_3_6_4', 'e_zq5_3_6_5');
  $arr_i6 = array('e_zq5_3_7_1','e_zq5_3_7_2', 'e_zq5_3_7_3', 'e_zq5_3_7_4', 'e_zq5_3_7_5');
  _zqx_i3_1($form_state, $arr_i4);
  _zqx_i3_1($form_state, $arr_i5);
  _zqx_i3_1($form_state, $arr_i6);
  _other_no_empty($form_state, 'e_zq5_3_4_2', 1 ,'e_zq5_3_4_3');
}
function crf_case_validate_zq6_3($form, &$form_state) {
  $arr_i1 = array('e_zq6_3_2_1', 'e_zq6_3_2_2', 'e_zq6_3_2_3', 'e_zq6_3_2_4');
  $arr_i2 = array('e_zq6_3_3_1', 'e_zq6_3_3_2', 'e_zq6_3_3_3', 'e_zq6_3_3_4');
  $arr_i3 = array('e_zq6_3_4_1', 'e_zq6_3_4_2', 'e_zq6_3_4_4', 'e_zq6_3_4_5');
  _zqx_i3($form_state, $arr_i1);
  _zqx_i3($form_state, $arr_i2);
  _zqx_i3($form_state, $arr_i3);
  $arr_i4 = array('e_zq6_3_5_1','e_zq6_3_5_2', 'e_zq6_3_5_3', 'e_zq6_3_5_4', 'e_zq6_3_5_5');
  $arr_i5 = array('e_zq6_3_6_1','e_zq6_3_6_2', 'e_zq6_3_6_3', 'e_zq6_3_6_4', 'e_zq6_3_6_5');
  $arr_i6 = array('e_zq6_3_7_1','e_zq6_3_7_2', 'e_zq6_3_7_3', 'e_zq6_3_7_4', 'e_zq6_3_7_5');
  _zqx_i3_1($form_state, $arr_i4);
  _zqx_i3_1($form_state, $arr_i5);
  _zqx_i3_1($form_state, $arr_i6);
  _other_no_empty($form_state, 'e_zq6_3_4_2', 1 ,'e_zq6_3_4_3');
}
function crf_case_validate_zq7_3($form, &$form_state) {
  $arr_i1 = array('e_zq7_3_2_1', 'e_zq7_3_2_2', 'e_zq7_3_2_3', 'e_zq7_3_2_4');
  $arr_i2 = array('e_zq7_3_3_1', 'e_zq7_3_3_2', 'e_zq7_3_3_3', 'e_zq7_3_3_4');
  $arr_i3 = array('e_zq7_3_4_1', 'e_zq7_3_4_2', 'e_zq7_3_4_4', 'e_zq7_3_4_5');
  _zqx_i3($form_state, $arr_i1);
  _zqx_i3($form_state, $arr_i2);
  _zqx_i3($form_state, $arr_i3);
  $arr_i4 = array('e_zq7_3_5_1','e_zq7_3_5_2', 'e_zq7_3_5_3', 'e_zq7_3_5_4', 'e_zq7_3_5_5');
  $arr_i5 = array('e_zq7_3_6_1','e_zq7_3_6_2', 'e_zq7_3_6_3', 'e_zq7_3_6_4', 'e_zq7_3_6_5');
  $arr_i6 = array('e_zq7_3_7_1','e_zq7_3_7_2', 'e_zq7_3_7_3', 'e_zq7_3_7_4', 'e_zq7_3_7_5');
  _zqx_i3_1($form_state, $arr_i4);
  _zqx_i3_1($form_state, $arr_i5);
  _zqx_i3_1($form_state, $arr_i6);
  _other_no_empty($form_state, 'e_zq7_3_4_2', 1 ,'e_zq7_3_4_3');
}
function crf_case_validate_zq8_2($form, &$form_state) {
  $arr_i1 = array('e_zq8_2_2_1', 'e_zq8_2_2_2', 'e_zq8_2_2_3', 'e_zq8_2_2_4');
  $arr_i2 = array('e_zq8_2_3_1', 'e_zq8_2_3_2', 'e_zq8_2_3_3', 'e_zq8_2_3_4');
  $arr_i3 = array('e_zq8_2_4_1', 'e_zq8_2_4_2', 'e_zq8_2_4_4', 'e_zq8_2_4_5');
  _zqx_i3($form_state, $arr_i1);
  _zqx_i3($form_state, $arr_i2);
  _zqx_i3($form_state, $arr_i3);
  $arr_i4 = array('e_zq8_2_5_1','e_zq8_2_5_2', 'e_zq8_2_5_3', 'e_zq8_2_5_4', 'e_zq8_2_5_5');
  $arr_i5 = array('e_zq8_2_6_1','e_zq8_2_6_2', 'e_zq8_2_6_3', 'e_zq8_2_6_4', 'e_zq8_2_6_5');
  $arr_i6 = array('e_zq8_2_7_1','e_zq8_2_7_2', 'e_zq8_2_7_3', 'e_zq8_2_7_4', 'e_zq8_2_7_5');
  _zqx_i3_1($form_state, $arr_i4);
  _zqx_i3_1($form_state, $arr_i5);
  _zqx_i3_1($form_state, $arr_i6);
  _other_no_empty($form_state, 'e_zq8_2_4_2', 1 ,'e_zq8_2_4_3');
}
function crf_case_validate_zq9_2($form, &$form_state) {
  $arr_i1 = array('e_zq9_2_2_1', 'e_zq9_2_2_2', 'e_zq9_2_2_3', 'e_zq9_2_2_4');
  $arr_i2 = array('e_zq9_2_3_1', 'e_zq9_2_3_2', 'e_zq9_2_3_3', 'e_zq9_2_3_4');
  $arr_i3 = array('e_zq9_2_4_1', 'e_zq9_2_4_2', 'e_zq9_2_4_4', 'e_zq9_2_4_5');
  _zqx_i3($form_state, $arr_i1);
  _zqx_i3($form_state, $arr_i2);
  _zqx_i3($form_state, $arr_i3);
  $arr_i4 = array('e_zq9_2_5_1','e_zq9_2_5_2', 'e_zq9_2_5_3', 'e_zq9_2_5_4', 'e_zq9_2_5_5');
  $arr_i5 = array('e_zq9_2_6_1','e_zq9_2_6_2', 'e_zq9_2_6_3', 'e_zq9_2_6_4', 'e_zq9_2_6_5');
  $arr_i6 = array('e_zq9_2_7_1','e_zq9_2_7_2', 'e_zq9_2_7_3', 'e_zq9_2_7_4', 'e_zq9_2_7_5');
  _zqx_i3_1($form_state, $arr_i4);
  _zqx_i3_1($form_state, $arr_i5);
  _zqx_i3_1($form_state, $arr_i6);
  _other_no_empty($form_state, 'e_zq9_2_4_2', 1 ,'e_zq9_2_4_3');
}
function crf_case_validate_zq10_2($form, &$form_state) {
  $arr_i1 = array('e_zq10_2_2_1', 'e_zq10_2_2_2', 'e_zq10_2_2_3', 'e_zq10_2_2_4');
  $arr_i2 = array('e_zq10_2_3_1', 'e_zq10_2_3_2', 'e_zq10_2_3_3', 'e_zq10_2_3_4');
  $arr_i3 = array('e_zq10_2_4_1', 'e_zq10_2_4_2', 'e_zq10_2_4_4', 'e_zq10_2_4_5');
  _zqx_i3($form_state, $arr_i1);
  _zqx_i3($form_state, $arr_i2);
  _zqx_i3($form_state, $arr_i3);
  $arr_i4 = array('e_zq10_2_5_1','e_zq10_2_5_2', 'e_zq10_2_5_3', 'e_zq10_2_5_4', 'e_zq10_2_5_5');
  $arr_i5 = array('e_zq10_2_6_1','e_zq10_2_6_2', 'e_zq10_2_6_3', 'e_zq10_2_6_4', 'e_zq10_2_6_5');
  $arr_i6 = array('e_zq10_2_7_1','e_zq10_2_7_2', 'e_zq10_2_7_3', 'e_zq10_2_7_4', 'e_zq10_2_7_5');
  _zqx_i3_1($form_state, $arr_i4);
  _zqx_i3_1($form_state, $arr_i5);
  _zqx_i3_1($form_state, $arr_i6);
  _other_no_empty($form_state, 'e_zq10_2_4_2', 1 ,'e_zq10_2_4_3');
}
function crf_case_validate_zq11_2($form, &$form_state) {
  $arr_i1 = array('e_zq11_2_2_1', 'e_zq11_2_2_2', 'e_zq11_2_2_3', 'e_zq11_2_2_4');
  $arr_i2 = array('e_zq11_2_3_1', 'e_zq11_2_3_2', 'e_zq11_2_3_3', 'e_zq11_2_3_4');
  $arr_i3 = array('e_zq11_2_4_1', 'e_zq11_2_4_2', 'e_zq11_2_4_4', 'e_zq11_2_4_5');
  _zqx_i3($form_state, $arr_i1);
  _zqx_i3($form_state, $arr_i2);
  _zqx_i3($form_state, $arr_i3);
  $arr_i4 = array('e_zq11_2_5_1','e_zq11_2_5_2', 'e_zq11_2_5_3', 'e_zq11_2_5_4', 'e_zq11_2_5_5');
  $arr_i5 = array('e_zq11_2_6_1','e_zq11_2_6_2', 'e_zq11_2_6_3', 'e_zq11_2_6_4', 'e_zq11_2_6_5');
  $arr_i6 = array('e_zq11_2_7_1','e_zq11_2_7_2', 'e_zq11_2_7_3', 'e_zq11_2_7_4', 'e_zq11_2_7_5');
  _zqx_i3_1($form_state, $arr_i4);
  _zqx_i3_1($form_state, $arr_i5);
  _zqx_i3_1($form_state, $arr_i6);
  _other_no_empty($form_state, 'e_zq11_2_4_2', 1 ,'e_zq11_2_4_3');
}
function crf_case_validate_zq12_2($form, &$form_state) {
  $arr_i1 = array('e_zq12_2_2_1', 'e_zq12_2_2_2', 'e_zq12_2_2_3', 'e_zq12_2_2_4');
  $arr_i2 = array('e_zq12_2_3_1', 'e_zq12_2_3_2', 'e_zq12_2_3_3', 'e_zq12_2_3_4');
  $arr_i3 = array('e_zq12_2_4_1', 'e_zq12_2_4_2', 'e_zq12_2_4_4', 'e_zq12_2_4_5');
  _zqx_i3($form_state, $arr_i1);
  _zqx_i3($form_state, $arr_i2);
  _zqx_i3($form_state, $arr_i3);
  $arr_i4 = array('e_zq12_2_5_1','e_zq12_2_5_2', 'e_zq12_2_5_3', 'e_zq12_2_5_4', 'e_zq12_2_5_5');
  $arr_i5 = array('e_zq12_2_6_1','e_zq12_2_6_2', 'e_zq12_2_6_3', 'e_zq12_2_6_4', 'e_zq12_2_6_5');
  $arr_i6 = array('e_zq12_2_7_1','e_zq12_2_7_2', 'e_zq12_2_7_3', 'e_zq12_2_7_4', 'e_zq12_2_7_5');
  _zqx_i3_1($form_state, $arr_i4);
  _zqx_i3_1($form_state, $arr_i5);
  _zqx_i3_1($form_state, $arr_i6);
  _other_no_empty($form_state, 'e_zq12_2_4_2', 1 ,'e_zq12_2_4_3');
}
function crf_case_validate_zq13_2($form, &$form_state) {
  $arr_i1 = array('e_zq13_2_2_1', 'e_zq13_2_2_2', 'e_zq13_2_2_3', 'e_zq13_2_2_4');
  $arr_i2 = array('e_zq13_2_3_1', 'e_zq13_2_3_2', 'e_zq13_2_3_3', 'e_zq13_2_3_4');
  $arr_i3 = array('e_zq13_2_4_1', 'e_zq13_2_4_2', 'e_zq13_2_4_4', 'e_zq13_2_4_5');
  _zqx_i3($form_state, $arr_i1);
  _zqx_i3($form_state, $arr_i2);
  _zqx_i3($form_state, $arr_i3);
  $arr_i4 = array('e_zq13_2_5_1','e_zq13_2_5_2', 'e_zq13_2_5_3', 'e_zq13_2_5_4', 'e_zq13_2_5_5');
  $arr_i5 = array('e_zq13_2_6_1','e_zq13_2_6_2', 'e_zq13_2_6_3', 'e_zq13_2_6_4', 'e_zq13_2_6_5');
  $arr_i6 = array('e_zq13_2_7_1','e_zq13_2_7_2', 'e_zq13_2_7_3', 'e_zq13_2_7_4', 'e_zq13_2_7_5');
  _zqx_i3_1($form_state, $arr_i4);
  _zqx_i3_1($form_state, $arr_i5);
  _zqx_i3_1($form_state, $arr_i6);
  _other_no_empty($form_state, 'e_zq13_2_4_2', 1 ,'e_zq13_2_4_3');
}
function crf_case_validate_zq14_2($form, &$form_state) {
  $arr_i1 = array('e_zq14_2_2_1', 'e_zq14_2_2_2', 'e_zq14_2_2_3', 'e_zq14_2_2_4');
  $arr_i2 = array('e_zq14_2_3_1', 'e_zq14_2_3_2', 'e_zq14_2_3_3', 'e_zq14_2_3_4');
  $arr_i3 = array('e_zq14_2_4_1', 'e_zq14_2_4_2', 'e_zq14_2_4_4', 'e_zq14_2_4_5');
  _zqx_i3($form_state, $arr_i1);
  _zqx_i3($form_state, $arr_i2);
  _zqx_i3($form_state, $arr_i3);
  $arr_i4 = array('e_zq14_2_5_1','e_zq14_2_5_2', 'e_zq14_2_5_3', 'e_zq14_2_5_4', 'e_zq14_2_5_5');
  $arr_i5 = array('e_zq14_2_6_1','e_zq14_2_6_2', 'e_zq14_2_6_3', 'e_zq14_2_6_4', 'e_zq14_2_6_5');
  $arr_i6 = array('e_zq14_2_7_1','e_zq14_2_7_2', 'e_zq14_2_7_3', 'e_zq14_2_7_4', 'e_zq14_2_7_5');
  _zqx_i3_1($form_state, $arr_i4);
  _zqx_i3_1($form_state, $arr_i5);
  _zqx_i3_1($form_state, $arr_i6);
  _other_no_empty($form_state, 'e_zq14_2_4_2', 1 ,'e_zq14_2_4_3');
}
function crf_case_validate_zq15_2($form, &$form_state) {
  $arr_i1 = array('e_zq15_2_2_1', 'e_zq15_2_2_2', 'e_zq15_2_2_3', 'e_zq15_2_2_4');
  $arr_i2 = array('e_zq15_2_3_1', 'e_zq15_2_3_2', 'e_zq15_2_3_3', 'e_zq15_2_3_4');
  $arr_i3 = array('e_zq15_2_4_1', 'e_zq15_2_4_2', 'e_zq15_2_4_4', 'e_zq15_2_4_5');
  _zqx_i3($form_state, $arr_i1);
  _zqx_i3($form_state, $arr_i2);
  _zqx_i3($form_state, $arr_i3);
  $arr_i4 = array('e_zq15_2_5_1','e_zq15_2_5_2', 'e_zq15_2_5_3', 'e_zq15_2_5_4', 'e_zq15_2_5_5');
  $arr_i5 = array('e_zq15_2_6_1','e_zq15_2_6_2', 'e_zq15_2_6_3', 'e_zq15_2_6_4', 'e_zq15_2_6_5');
  $arr_i6 = array('e_zq15_2_7_1','e_zq15_2_7_2', 'e_zq15_2_7_3', 'e_zq15_2_7_4', 'e_zq15_2_7_5');
  _zqx_i3_1($form_state, $arr_i4);
  _zqx_i3_1($form_state, $arr_i5);
  _zqx_i3_1($form_state, $arr_i6);
  _other_no_empty($form_state, 'e_zq15_2_4_2', 1 ,'e_zq15_2_4_3');
}
function crf_case_validate_zq16_2($form, &$form_state) {
  $arr_i1 = array('e_zq16_2_2_1', 'e_zq16_2_2_2', 'e_zq16_2_2_3', 'e_zq16_2_2_4');
  $arr_i2 = array('e_zq16_2_3_1', 'e_zq16_2_3_2', 'e_zq16_2_3_3', 'e_zq16_2_3_4');
  $arr_i3 = array('e_zq16_2_4_1', 'e_zq16_2_4_2', 'e_zq16_2_4_4', 'e_zq16_2_4_5');
  _zqx_i3($form_state, $arr_i1);
  _zqx_i3($form_state, $arr_i2);
  _zqx_i3($form_state, $arr_i3);
  $arr_i4 = array('e_zq16_2_5_1','e_zq16_2_5_2', 'e_zq16_2_5_3', 'e_zq16_2_5_4', 'e_zq16_2_5_5');
  $arr_i5 = array('e_zq16_2_6_1','e_zq16_2_6_2', 'e_zq16_2_6_3', 'e_zq16_2_6_4', 'e_zq16_2_6_5');
  $arr_i6 = array('e_zq16_2_7_1','e_zq16_2_7_2', 'e_zq16_2_7_3', 'e_zq16_2_7_4', 'e_zq16_2_7_5');
  _zqx_i3_1($form_state, $arr_i4);
  _zqx_i3_1($form_state, $arr_i5);
  _zqx_i3_1($form_state, $arr_i6);
  _other_no_empty($form_state, 'e_zq16_2_4_2', 1 ,'e_zq16_2_4_3');
}
function _zqx_i3($form_state, $arr) {
  $c = count($arr);
  $arr_text = array('', '单位','是否有临床意义','取样日期');
  if (!empty($form_state['values'][$arr[0]])) {
    for($i=1;$i<$c;$i++) {
      if ($form_state['values'][$arr[$i]] == "") {
        form_set_error($arr[$i], "填写数值后，". $arr_text[$i] ."必须填写");
      }
    }
  }
}
function _zqx_i3_1($form_state, $arr) {
  $c = count($arr);
  $arr_text = array('', '数值', '单位','是否有临床意义','取样日期');
  if (!empty($form_state['values'][$arr[0]])) {
    for($i=1;$i<$c;$i++) {
      if ($form_state['values'][$arr[$i]] == "") {
        form_set_error($arr[$i], "填写其它后，". $arr_text[$i] ."必须填写");
      }
    }
  }
}
function _other_no_empty($form_state, $e1, $v ,$e2) {
  if ($form_state['values'][$e1] == $v) {
    if (empty($form_state['values'][$e2])) {
      form_set_error($e2, "填写其它单位后必须填写其它单位！");
    }
  }
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
function crf_case_validate_zq10_3($form, &$form_state) {
  _check_zq_date_2($form_state, 'zq9_3', 'e_zq10_3_3_1', 'e_zq10_3_3_2', '第九周期');
}
function crf_case_validate_zq11_3($form, &$form_state) {
  _check_zq_date_2($form_state, 'zq10_3', 'e_zq11_3_3_1', 'e_zq11_3_3_2', '第十周期');
}
function crf_case_validate_zq12_3($form, &$form_state) {
  _check_zq_date_2($form_state, 'zq11_3', 'e_zq12_3_3_1', 'e_zq12_3_3_2', '第十一周期');
}
function crf_case_validate_zq13_3($form, &$form_state) {
  _check_zq_date_2($form_state, 'zq12_3', 'e_zq13_3_3_1', 'e_zq13_3_3_2', '第十二周期');
}
function crf_case_validate_zq14_3($form, &$form_state) {
  _check_zq_date_2($form_state, 'zq13_3', 'e_zq14_3_3_1', 'e_zq14_3_3_2', '第十三周期');
}
function crf_case_validate_zq15_3($form, &$form_state) {
  _check_zq_date_2($form_state, 'zq14_3', 'e_zq15_3_3_1', 'e_zq15_3_3_2', '第十四周期');
}
function crf_case_validate_zq16_3($form, &$form_state) {
  _check_zq_date_2($form_state, 'zq15_3', 'e_zq16_3_3_1', 'e_zq16_3_3_2', '第十五周期');
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
  if ($form_state['values']['e_weiai_ssyzdqk_4_1'][8] != 0 && empty($form_state['values']['e_weiai_ssyzdqk_4_2'])) {
    form_set_error('e_weiai_ssyzdqk_4_2', "选择其它需要写说明！"); 
  }
  if ($form_state['values']['e_weiai_ssyzdqk_5_1'][5] != 0 && empty($form_state['values']['e_weiai_ssyzdqk_5_2'])) {
    form_set_error('e_weiai_ssyzdqk_5_2', "选择其它需要写说明！"); 
  }
  if (!empty($form_state['values']['e_weiai_ssyzdqk_1_1']) && ($form_state['values']['e_weiai_ssyzdqk_1_1'] < $_SESSION['crf']['p_arr']['p_birthday'])) {
    form_set_error('e_weiai_ssyzdqk_1_1', '首次诊断日期不能小于出生日期！');
  }
  if (!empty($form_state['values']['e_weiai_ssyzdqk_2_1']) && $form_state['values']['e_weiai_ssyzdqk_2_1'] < $_SESSION['crf']['p_arr']['p_birthday']) {
    form_set_error('e_weiai_ssyzdqk_2_1', '手术日期不能小于出生日期！');
  }
}
 
function crf_case_validate_sf2_1($form, &$form_state) {
   _sf_did($form_state, 'sf1_1', 'e_sf2_1_1_1');
}
function crf_case_validate_sf3_1($form, &$form_state) {
   _sf_did($form_state, 'sf2_1', 'e_sf3_1_1_1');
}
function crf_case_validate_sf4_1($form, &$form_state) {
   _sf_did($form_state, 'sf3_1', 'e_sf4_1_1_1');
}
function crf_case_validate_sf5_1($form, &$form_state) {
   _sf_did($form_state, 'sf4_1', 'e_sf5_1_1_1');
}
function crf_case_validate_sf6_1($form, &$form_state) {
   _sf_did($form_state, 'sf5_1', 'e_sf6_1_1_1');
}
function crf_case_validate_sf7_1($form, &$form_state) {
   _sf_did($form_state, 'sf6_1', 'e_sf7_1_1_1');
}
function crf_case_validate_sf8_1($form, &$form_state) {
   _sf_did($form_state, 'sf7_1', 'e_sf8_1_1_1');
}
function crf_case_validate_sf9_1($form, &$form_state) {
   _sf_did($form_state, 'sf8_1', 'e_sf9_1_1_1');
}

function _sf_did($form_state, $last_table, $e) {
  if (!empty($form_state['values'][$e])) {
    $p_uid = crf_ds_s_data('p_uid');
    $data = json_to_array(crf_ds_load($last_table, $p_uid));
    if ($form_state['values'][$e] <= $data[1][1]) {
      form_set_error($e, "随访日期需大于上一个随访日期！");
    }
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
  if (!empty($form_state['values']['e_xueqing_zlbzwjc_2_2']) || !empty($form_state['values']['e_xueqing_zlbzwjc_3_2']) || !empty($form_state['values']['e_xueqing_zlbzwjc_4_2'])) {
    if (empty($form_state['values']['e_xueqing_zlbzwjc_1_1'])) {
      form_set_error('e_xueqing_zlbzwjc_1_1', '取样日期不能为空！');
    }
  }
//  if (!empty($form_state['values']['e_xueqing_zlbzwjc_2_3']) || !empty($form_state['values']['e_xueqing_zlbzwjc_3_3']) || !empty($form_state['values']['e_xueqing_zlbzwjc_4_3'])) {
//    if (empty($form_state['values']['e_xueqing_zlbzwjc_1_1'])) {
//      form_set_error('e_xueqing_zlbzwjc_1_1', '取样日期不能为空！');
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
  
  if (!empty($form_state['values']['e_shiyan_sjc_2_1']) || !empty($form_state['values']['e_shiyan_sjc_3_1'])
          || !empty($form_state['values']['e_shiyan_sjc_4_1']) || !empty($form_state['values']['e_shiyan_sjc_5_1']) 
          || !empty($form_state['values']['e_shiyan_sjc_6_1']) || !empty($form_state['values']['e_shiyan_sjc_7_1'])) {
    if (empty($form_state['values']['e_shiyan_sjc_1_1'])) {
      form_set_error('e_shiyan_sjc_1_1', '血常规 取样日期不能为空！');
    }
  }
  if (!empty($form_state['values']['e_shiyan_sjc_9_1'])) {
    if (!empty($form_state['values']['e_shiyan_sjc_8_1'])) {
      form_set_error('e_shiyan_sjc_8_1', '凝血功能 取样日期不能为空！');
    }
  }
  if (!empty($form_state['values']['e_shiyan_sjc_11_1']) || !empty($form_state['values']['e_shiyan_sjc_12_1'])
          || !empty($form_state['values']['e_shiyan_sjc_13_1']) || !empty($form_state['values']['e_shiyan_sjc_14_1']) 
          || !empty($form_state['values']['e_shiyan_sjc_15_1']) || !empty($form_state['values']['e_shiyan_sjc_16_1'])
          || !empty($form_state['values']['e_shiyan_sjc_17_1']) || !empty($form_state['values']['e_shiyan_sjc_18_1']) 
          || !empty($form_state['values']['e_shiyan_sjc_19_1']) || !empty($form_state['values']['e_shiyan_sjc_20_1'])
          || !empty($form_state['values']['e_shiyan_sjc_21_1']) || !empty($form_state['values']['e_shiyan_sjc_22_1']) 
          || !empty($form_state['values']['e_shiyan_sjc_23_1']) || !empty($form_state['values']['e_shiyan_sjc_24_1'])) {
    if (empty($form_state['values']['e_shiyan_sjc_10_1'])) {
      form_set_error('e_shiyan_sjc_10_1', '血生化 取样日期不能为空！');
    }
  }
  if (!empty($form_state['values']['e_shiyan_sjc_26_1'])) {
    if (empty($form_state['values']['e_shiyan_sjc_25_1'])) {
      form_set_error('e_shiyan_sjc_25_1', '尿常规 取样日期不能为空！');
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
  _pg_did($form_state, array('e_pg2_1_2_1','e_pg2_1_3_2','e_pg2_1_3_3','e_pg2_1_4_1','e_pg2_1_4_2','e_pg2_1_5_1','e_pg2_1_5_2','e_pg2_1_7_1','e_pg2_1_7_2','pg1_1','e_pg2_1_1_1'));
}
function crf_case_validate_pg3_1($form, &$form_state) {
  _pg_did($form_state, array('e_pg3_1_2_1','e_pg3_1_3_2','e_pg3_1_3_3','e_pg3_1_4_1','e_pg3_1_4_2','e_pg3_1_5_1','e_pg3_1_5_2','e_pg3_1_7_1','e_pg3_1_7_2','pg2_1','e_pg3_1_1_1'));
}
function crf_case_validate_pg4_1($form, &$form_state) {
  _pg_did($form_state, array('e_pg4_1_2_1','e_pg4_1_3_2','e_pg4_1_3_3','e_pg4_1_4_1','e_pg4_1_4_2','e_pg4_1_5_1','e_pg4_1_5_2','e_pg4_1_7_1','e_pg4_1_7_2','pg3_1','e_pg4_1_1_1'));
}
function crf_case_validate_pg5_1($form, &$form_state) {
  _pg_did($form_state, array('e_pg5_1_2_1','e_pg5_1_3_2','e_pg5_1_3_3','e_pg5_1_4_1','e_pg5_1_4_2','e_pg5_1_5_1','e_pg5_1_5_2','e_pg5_1_7_1','e_pg5_1_7_2','pg4_1','e_pg5_1_1_1'));
}

function _pg_did(&$form_state,$arr) {
  if ($arr[9] != '') {
    $p_uid = crf_ds_s_data('p_uid');
    $data = json_to_array(crf_ds_load($arr[9], $p_uid));
    if ($form_state['values'][$arr[10]] <= $data[1][1]) {
      form_set_error($arr[10], "检查日期需大于上一次临床评估的检查时间！");  
    }
  }
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

function crf_case_validate_pg2_2($form, &$form_state) {
  _pg_did_1($form_state, array('pg1_2', 'e_pg2_2_2_1'));
}
function crf_case_validate_pg3_2($form, &$form_state) {
  _pg_did_1($form_state, array('pg2_2', 'e_pg3_2_2_1'));
}
function crf_case_validate_pg4_2($form, &$form_state) {
  _pg_did_1($form_state, array('pg3_2', 'e_pg4_2_2_1'));
}
function crf_case_validate_pg5_2($form, &$form_state) {
  _pg_did_1($form_state, array('pg4_2', 'e_pg5_2_2_1'));
}
function _pg_did_1(&$form_state,$arr) {
  $p_uid = crf_ds_s_data('p_uid');
  $data = json_to_array(crf_ds_load($arr[0], $p_uid));
  if ($form_state['values'][$arr[1]] <= $data[2][1]) {
    form_set_error($arr[1], "心电图检查检查日期需大于上一次心电图检查的检查时间！");  
  }  
}

function crf_case_validate_pg1_4($form, &$form_state) {
  _t_did($form_state, array('e_pg1_4_2_3', 1, 'e_pg1_4_2_4','选择其它单位不能为空！'));
}
function crf_case_validate_pg2_4($form, &$form_state) {
  _t_did($form_state, array('e_pg2_4_2_3', 1, 'e_pg2_4_2_4','选择其它单位不能为空！'));
}
function crf_case_validate_pg3_4($form, &$form_state) {
  _t_did($form_state, array('e_pg3_4_2_3', 1, 'e_pg3_4_2_4','选择其它单位不能为空！'));
}
function crf_case_validate_pg4_4($form, &$form_state) {
  _t_did($form_state, array('e_pg4_4_2_3', 1, 'e_pg4_4_2_4','选择其它单位不能为空！'));
}
function crf_case_validate_pg5_4($form, &$form_state) {
  _t_did($form_state, array('e_pg5_4_2_3', 1, 'e_pg5_4_2_4','选择其它单位不能为空！'));
}
function crf_case_validate_pg1_6($form, &$form_state) {
  _t_did($form_state, array('e_pg1_6_11_2', 2, 'e_pg1_6_11_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg1_6_12_2', 2, 'e_pg1_6_12_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg1_6_13_2', 2, 'e_pg1_6_13_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg1_6_14_2', 2, 'e_pg1_6_14_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg1_6_15_2', 2, 'e_pg1_6_15_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg1_6_16_2', 2, 'e_pg1_6_16_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg1_6_17_2', 2, 'e_pg1_6_17_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg1_6_18_2', 2, 'e_pg1_6_18_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg1_6_19_2', 2, 'e_pg1_6_19_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg1_6_20_2', 2, 'e_pg1_6_20_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg1_6_21_2', 1, 'e_pg1_6_21_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg1_6_22_2', 1, 'e_pg1_6_22_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg1_6_23_2', 1, 'e_pg1_6_23_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg1_6_24_2', 1, 'e_pg1_6_24_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg1_6_26_2', 1, 'e_pg1_6_26_3','选择其它单位不能为空！'));
}
function crf_case_validate_pg2_6($form, &$form_state) {
  _t_did($form_state, array('e_pg2_6_11_2', 2, 'e_pg2_6_11_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg2_6_12_2', 2, 'e_pg2_6_12_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg2_6_13_2', 2, 'e_pg2_6_13_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg2_6_14_2', 2, 'e_pg2_6_14_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg2_6_15_2', 2, 'e_pg2_6_15_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg2_6_16_2', 2, 'e_pg2_6_16_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg2_6_17_2', 2, 'e_pg2_6_17_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg2_6_18_2', 2, 'e_pg2_6_18_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg2_6_19_2', 2, 'e_pg2_6_19_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg2_6_20_2', 2, 'e_pg2_6_20_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg2_6_21_2', 1, 'e_pg2_6_21_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg2_6_22_2', 1, 'e_pg2_6_22_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg2_6_23_2', 1, 'e_pg2_6_23_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg2_6_24_2', 1, 'e_pg2_6_24_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg2_6_26_2', 1, 'e_pg2_6_26_3','选择其它单位不能为空！'));
}
function crf_case_validate_pg3_6($form, &$form_state) {
  _t_did($form_state, array('e_pg3_6_11_2', 2, 'e_pg3_6_11_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg3_6_12_2', 2, 'e_pg3_6_12_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg3_6_13_2', 2, 'e_pg3_6_13_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg3_6_14_2', 2, 'e_pg3_6_14_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg3_6_15_2', 2, 'e_pg3_6_15_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg3_6_16_2', 2, 'e_pg3_6_16_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg3_6_17_2', 2, 'e_pg3_6_17_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg3_6_18_2', 2, 'e_pg3_6_18_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg3_6_19_2', 2, 'e_pg3_6_19_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg3_6_20_2', 2, 'e_pg3_6_20_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg3_6_21_2', 1, 'e_pg3_6_21_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg3_6_22_2', 1, 'e_pg3_6_22_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg3_6_23_2', 1, 'e_pg3_6_23_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg3_6_24_2', 1, 'e_pg3_6_24_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg3_6_26_2', 1, 'e_pg3_6_26_3','选择其它单位不能为空！'));
}
function crf_case_validate_pg4_6($form, &$form_state) {
  _t_did($form_state, array('e_pg4_6_11_2', 2, 'e_pg4_6_11_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg4_6_12_2', 2, 'e_pg4_6_12_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg4_6_13_2', 2, 'e_pg4_6_13_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg4_6_14_2', 2, 'e_pg4_6_14_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg4_6_15_2', 2, 'e_pg4_6_15_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg4_6_16_2', 2, 'e_pg4_6_16_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg4_6_17_2', 2, 'e_pg4_6_17_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg4_6_18_2', 2, 'e_pg4_6_18_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg4_6_19_2', 2, 'e_pg4_6_19_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg4_6_20_2', 2, 'e_pg4_6_20_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg4_6_21_2', 1, 'e_pg4_6_21_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg4_6_22_2', 1, 'e_pg4_6_22_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg4_6_23_2', 1, 'e_pg4_6_23_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg4_6_24_2', 1, 'e_pg4_6_24_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg4_6_26_2', 1, 'e_pg4_6_26_3','选择其它单位不能为空！'));
}
function crf_case_validate_pg5_6($form, &$form_state) {
  _t_did($form_state, array('e_pg5_6_11_2', 2, 'e_pg5_6_11_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg5_6_12_2', 2, 'e_pg5_6_12_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg5_6_13_2', 2, 'e_pg5_6_13_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg5_6_14_2', 2, 'e_pg5_6_14_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg5_6_15_2', 2, 'e_pg5_6_15_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg5_6_16_2', 2, 'e_pg5_6_16_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg5_6_17_2', 2, 'e_pg5_6_17_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg5_6_18_2', 2, 'e_pg5_6_18_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg5_6_19_2', 2, 'e_pg5_6_19_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg5_6_20_2', 2, 'e_pg5_6_20_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg5_6_21_2', 1, 'e_pg5_6_21_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg5_6_22_2', 1, 'e_pg5_6_22_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg5_6_23_2', 1, 'e_pg5_6_23_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg5_6_24_2', 1, 'e_pg5_6_24_3','选择其它单位不能为空！'));
  _t_did($form_state, array('e_pg5_6_26_2', 1, 'e_pg5_6_26_3','选择其它单位不能为空！'));
}
function _t_did(&$form_state,$arr) {
  if ($form_state['values'][$arr[0]] == $arr[1]) {
    form_set_error($arr[2], $arr[3]);  
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
