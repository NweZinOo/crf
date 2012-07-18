<?php

function crf_form_save_renkou_tjx($dataset, $form_state) {
  $sex = $dataset[1][2];
  $disabled = crf_common_session('disable_item');
  if (!is_array($disabled)) {
     $disabled = array();
  }
  
  if ($sex == '0'){
    $disabled[] = 'huaiyun_knx';
    crf_common_session('disable_item', $disabled);
  }
  else {
    $disabled = array_diff($disabled, array('huaiyun_knx'));
    crf_common_session('disable_item', $disabled);
  }
}

//function crf_form_save_shiyan_sjc($dataset, $form_state) {
//  crf_common_session('all_doable', 1);
//}