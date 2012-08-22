<?php
/**
 * 所有case表的定义
 */

global $crf_el;
//print_r($_SESSION);

$genders[0] = "男";
$genders[1] = "女";

$crf_el['dyxx'] = array(
  '#name'  => '调研数据录入',
  1 => array(1 => type_date_popup()),
  2 => array(1 => type_checkboxs(array('1骨髓增生异常综合征(MDS)，（原发/  继发/  治疗相关）其WHO(2008)分型为:'))),
  3 => array(1 => type_checkboxs(array('1.1难治性贫血（RA）','1.2难治性血细胞减少伴多系发育异常（RCMD）','1.3 RARS','1.4 RAEB-1','1.5 RAEB-2','1.6 MDS-U','1.7 5q-综合征'))),
  4 => array(1 => type_item('WPSS 评分：very low  /  low  /  intermediate  /  high  /  very high')),
  5 => array(1 => type_checkboxs(array('2再生障碍性贫血(AA)')), 2 => type_checkboxs(array('3纯红细胞再生障碍性贫血'))),
  6 => array(1 => type_checkboxs(array('4骨髓纤维化')), 2 => type_checkboxs(array('5其它')), 3 => type_textfield()),
  7 => array(1 => type_date_popup()),
  8 => array(1 => type_textfield('',100)),
  9 => array(1 => type_date_popup()),
  10 => array(1 => type_textfield('',100)),
  11 => array(1 => type_date_popup()),
  12 => array(1 => type_textfield('',100)),
  13 => array(1 => type_checkboxs(array('无'))),
  14 => array(1 => type_date_popup()),
  15 => array(1 => type_textfield()),
  16 => array(1 => type_date_popup(),2 => type_date_popup()),
  17 => array(1 => type_textfield(),2 => type_textfield()),
  18 => array(1 => type_textfield(),2 => type_textfield()),
  19 => array(1 => type_textfield(),2 => type_textfield()),
  20 => array(1 => type_date_popup()),
  21 => array(1 => type_textfield(),2 => type_textfield(),3 => type_textfield(),4 => type_textfield(),5 => type_textfield()),
  22 => array(1 => type_date_popup()),
  23 => array(1 => type_textfield(),2 => type_textfield()),
  24 => array(1 => type_textfield()),
  25 => array(1 => type_date_popup()),
  26 => array(1 => type_date_popup()),
  27 => array(1 => type_radios(array('不进行祛铁治疗','进行祛铁治疗,请继续填写访视记录(每3个月随访一次)'))),
  28 => array(1 => type_checkboxs(array(''))),
  29 => array(1 => type_textfield(),2 => type_date_popup()),
);

for ($i=1; $i<=5; $i++) {
  $crf_el["sf_{$i}"] = array(
    '#name' => "第{$i}次随访",
    1 => array(1 => type_date_popup()),
    2 => array(1 => type_textfield()), 
    3 => array(1 => type_textfield(),2 => type_textfield(),3 => type_textfield()),
    4 => array(1 => type_date_popup(),2 => type_date_popup(),3 => type_date_popup()),
    5 => array(1 => type_date_popup(),2 => type_date_popup(),3 => type_date_popup()),
    6 => array(1 => type_textfield(),2 => type_textfield(),3 => type_textfield()),
    7 => array(1 => type_date_popup()),
    8 => array(1 => type_textfield(),2 => type_textfield(),3 => type_textfield(),4 => type_textfield()),
    9 => array(1 => type_textfield()),
    10 => array(1 => type_date_popup()),
    11 => array(1 => type_textfield(),2 => type_textfield()),
    12 => array(1 => type_textfield()),
    13 => array(1 => type_textfield(),2 => type_textfield(),3 => type_date_popup(),4 => type_date_popup()),
    14 => array(1 => type_textfield(),2 => type_textfield(),3 => type_date_popup(),4 => type_date_popup()),
    15 => array(1 => type_textfield(),2 => type_textfield(),3 => type_date_popup(),4 => type_date_popup()),
    16 => array(1 => type_textfield(),2 => type_textfield(),3 => type_date_popup(),4 => type_date_popup()),
    17 => array(1 => type_date_popup()),
    18 => array(1 => type_textfield('',100)),
  );
}