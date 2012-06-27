<?php
/**
 * 所有case表的定义
 */

global $crf_el;

$crf_el['zhiqing_tys'] = array(
  '#name' => '知情同意书',
  1 => array(
    1 => type_date_popup()
  ),
    
);

$crf_el['ruxuan_bz'] = array(
  '#name' => '入选标准',
  1 => array(1 => type_radios()),
  2 => array(1 => type_radios()),
  3 => array(1 => type_radios()),
  4 => array(1 => type_radios()),
  5 => array(1 => type_radios()),
  6 => array(1 => type_radios()),
  7 => array(1 => type_radios()),
  8 => array(1 => type_radios()),
  9 => array(1 => type_radios()),
  10 => array(1 => type_radios()),
  11 => array(1 => type_radios()),
  12 => array(1 => type_radios()),
);

$crf_el['paichu_bz'] = array(
  '#name' => '排除标准',
  1 => array(1 => type_radios()),
  2 => array(1 => type_radios()),
  3 => array(1 => type_radios()),
  4 => array(1 => type_radios()),
  5 => array(1 => type_radios()),
);

$crf_el['renkou_tjx'] = array(
  '#name' => '人口统计学',
  1 => array(1 => type_date_popup(), 2 => type_radios(array('1'=>'男','0'=>'女'))),
);

$crf_el['weiai_ssyzdqk'] = array(
  '#name' => '胃癌手术与诊断情况',
    1 => array(1 => type_date_popup()),
    2 => array(1 => type_date_popup()),
    3 => array(1 => type_checkboxs(array('T','N','M')),2 => type_checkboxs(array('II','ⅢA','ⅢB','ⅢC'))),
    4 => array(1 => type_checkboxs(array('腺癌','高分化','中分化','低分化','未知','印戒细胞癌','黏液腺癌','其它')),2 => type_textfield()),
    5 => array(1 => type_checkboxs(array('胃窦','胃小弯','中分化','低分化','未知','印戒细胞癌','黏液腺癌','其它')),2 => type_textfield()),
    6 => array(1 => type_textfield(),2 => type_textfield(),3 => type_textfield(),4 => type_textfield(),5 => type_textfield(),6 => type_textfield()),
    7 => array(1 => type_textfield(),2 => type_textfield(),3 => type_textfield(),4 => type_textfield(),5 => type_textfield(),6 => type_textfield()),
    8 => array(1 => type_radios(array('－、＋、＋/－','＋＋','＋＋＋')), 2 =>type_textfield(), 3=>type_radios(array('阳性','阴性'))),
);

$crf_el['jiwang_hxhjb'] = array(
  '#name' => '既往或现患疾病',
    1 => array(1 => type_checkboxs(array('无'))),
    2 => array(1 => type_textfield(),2 => type_radios(),3=>type_date_popup()),
    3 => array(1 => type_textfield(),2 => type_radios(),3=>type_date_popup()),
    4 => array(1 => type_textfield(),2 => type_radios(),3=>type_date_popup()),
);