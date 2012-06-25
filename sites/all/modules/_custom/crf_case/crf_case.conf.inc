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

$crf_el['paichu_bz'] = array(
  '#name' => '排除标准',
  1 => array(1 => type_radios(),2 => type_radios()),
  2 => array(1 => type_radios(),2 => type_radios()),
  3 => array(1 => type_radios(),2 => type_radios()),
  4 => array(1 => type_radios(),2 => type_radios()),
  5 => array(1 => type_radios(),2 => type_radios()),
);

$crf_el['weiai_ssyzdqk'] = array(
  '#name' => '胃癌手术与诊断情况',
  1 => array(1 => type_date_popup(),2 => type_radios('gender')),
);

$crf_el['renkou_tjx'] = array(
  '#name' => '人口统计学',
  1 => array(1 => type_date_popup()),
  2 => array(1 => type_date_popup()),
  3 => array(1 => type_checkboxs(array('T','N','M'))),
);