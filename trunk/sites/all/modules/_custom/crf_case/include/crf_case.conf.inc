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
  1 => array(1 => type_date_popup(), 2 => type_radios(array('男','女'))),
);

$crf_el['weiai_ssyzdqk'] = array(
  '#name' => '胃癌手术与诊断情况',
    1 => array(1 => type_date_popup()),
    2 => array(1 => type_date_popup()),
    3 => array(1 => type_checkboxs(array('T','N','M')),2 => type_checkboxs(array('II','ⅢA','ⅢB','ⅢC'))),
    4 => array(1 => type_checkboxs(array('腺癌','高分化','中分化','低分化','未知','印戒细胞癌','黏液腺癌','其它')),2 => type_textfield()),
    5 => array(1 => type_checkboxs(array('胃窦','胃小弯','贲门','胃体','其它')),2 => type_textfield()),
    6 => array(1 => type_textfield('', 5),2 => type_textfield('', 5),3 => type_textfield('', 5),4 => type_textfield('', 5),5 => type_textfield('', 5),6 => type_textfield('', 5)),
    7 => array(1 => type_radios(array('－、＋、＋/－','＋＋','＋＋＋')), 2=>type_radios(array('阳性','阴性')), 3=>type_textfield(), 4=>type_radios(array('阳性','阴性'))),
);

$crf_el['jiwang_hxhjb'] = array(
  '#name' => '既往或现患疾病',
    1 => array(1 => type_checkboxs(array('无'))),
    2 => array(1 => type_textfield(),2 => type_radios(),3 => type_date_popup()),
    3 => array(1 => type_textfield(),2 => type_radios(),3 => type_date_popup()),
    4 => array(1 => type_textfield(),2 => type_radios(),3 => type_date_popup()),
);

$crf_el['huaiyun_knx'] = array(
  '#name' => '怀孕可能性',
    1 => array(1 => type_radios(array('是','否','不适用')), 2 => type_textfield('',5)),
    2 => array(1 => type_radios(array('阴性','阳性')))
);

$crf_el['teshu_jc'] = array(
  '#name' => '特殊检查',
    1 => array(1 => type_date_popup(), 2 => type_checkboxs(array('未作')), 3 => type_radios(), 4 => type_textfield()),
    2 => array(1 => type_date_popup(), 2 => type_checkboxs(array('未作')), 3 => type_radios(), 4 => type_textfield()),
    3 => array(1 => type_date_popup(), 2 => type_checkboxs(array('未作')), 3 => type_radios(), 4 => type_textfield()),
    4 => array(1 => type_date_popup(), 2 => type_checkboxs(array('未作')), 3 => type_radios(), 4 => type_textfield()),
    5 => array(1 => type_date_popup(), 2 => type_checkboxs(array('未作')), 3 => type_radios(), 4 => type_textfield()),
    6 => array(1 => type_date_popup(), 2 => type_checkboxs(array('未作')), 3 => type_radios(), 4 => type_textfield()),
    7 => array(1 => type_date_popup(), 2 => type_checkboxs(array('未作')), 3 => type_radios(), 4 => type_textfield()),
    8 => array(1 => type_date_popup(), 2 => type_checkboxs(array('未作')), 3 => type_radios(), 4 => type_textfield()),
    9 => array(1 => type_date_popup(), 2 => type_checkboxs(array('未作')), 3 => type_radios(), 4 => type_textfield()),
    10 => array(1 => type_date_popup(), 2 => type_checkboxs(array('未作')), 3 => type_radios(), 4 => type_textfield()),
    11 => array(1 => type_date_popup(), 2 => type_checkboxs(array('未作')), 3 => type_radios(), 4 => type_textfield()),
    12 => array(1 => type_textfield(), 2 => type_date_popup(), 3 => type_checkboxs(array('未作')), 4 => type_radios(), 5 => type_textfield()),
    13 => array(1 => type_textfield(), 2 => type_date_popup(), 3 => type_checkboxs(array('未作')), 4 => type_radios(), 5 => type_textfield()),
    14 => array(1 => type_textfield(), 2 => type_date_popup(), 3 => type_checkboxs(array('未作')), 4 => type_radios(), 5 => type_textfield()),
);

$crf_el['xindian_tjc'] = array(
  '#name' => '心电图检查',
    1 => array(1 => type_date_popup()),
    2 => array(1 => type_radios(array('正常','异常')), 2 => type_textfield()),
);

$crf_el['quanshen_tgjc'] = array(
  '#name' => '全身体格检查',
    1 => array(1 => type_date_popup()),
    2 => array(1 => type_textfield(), 2 => type_textfield()),
    3 => array(1 => type_textfield(), 2 => type_textfield()),
    4 => array(1 => type_textfield(), 2 => type_textfield()),
    5 => array(1 => type_radios(array('正常','异常')), 2 => type_textfield()),
    6 => array(1 => type_radios(array('正常','异常')), 2 => type_textfield()),
    7 => array(1 => type_radios(array('正常','异常')), 2 => type_textfield()),
    8 => array(1 => type_radios(array('正常','异常')), 2 => type_textfield()),
    9 => array(1 => type_radios(array('正常','异常')), 2 => type_textfield()),
    10 => array(1 => type_radios(array('正常','异常')), 2 => type_textfield()),
    11 => array(1 => type_radios(array('正常','异常')), 2 => type_textfield()),
    12 => array(1 => type_radios(array('正常','异常')), 2 => type_textfield()),
    13 => array(1 => type_radios(array('正常','异常')), 2 => type_textfield()),
    14 => array(1 => type_radios(array('正常','异常')), 2 => type_textfield()),
    15 => array(1 => type_radios(array('正常','异常')), 2 => type_textfield()),
    16 => array(1 => type_radios(array('正常','异常')), 2 => type_textfield()),
);

$crf_el['xueqing_zlbzwjc'] = array(
  '#name' => '血清肿瘤标志物检测',
    1 => array(1 => type_date_popup()),
    2 => array(1 => type_textfield(), 2 => type_checkboxs(array('未作')), 3 => type_radios(array('ng/ml','其它')), 4 => type_textfield()),
    3 => array(1 => type_textfield(), 2 => type_checkboxs(array('未作')), 3 => type_radios(array('ng/ml','其它')), 4 => type_textfield()),
    4 => array(1 => type_textfield(), 2 => type_checkboxs(array('未作')), 3 => type_radios(array('ng/ml','其它')), 4 => type_textfield()),
);

$crf_el['shiyan_sjc'] = array(
  '#name' => '实验室检查',
    1 => array(1 => type_date_popup()),
    2 => array(1 => type_textfield(), 2 => type_radios(array('x10<sup>3</sup>/mm<sup>3</sup>','x10<sup>9</sup>/L')), 3 => type_radios()),
    3 => array(1 => type_textfield(), 2 => type_radios(array('x10<sup>3</sup>/mm<sup>3</sup>','x10<sup>9</sup>/L')), 3 => type_radios()),
    4 => array(1 => type_textfield(), 2 => type_radios(array('mg/dl','g/L')), 3 => type_radios()),
    5 => array(1 => type_textfield(), 2 => type_radios(array('x10<sup>3</sup>/mm<sup>3</sup>','x10<sup>12</sup>/L')), 3 => type_radios()),
    6 => array(1 => type_textfield(), 2 => type_radios()),
    7 => array(1 => type_textfield(), 2 => type_radios(array('x10<sup>3</sup>/mm<sup>3</sup>','x10<sup>9</sup>/L')), 3 => type_radios()),
    8 => array(1 => type_date_popup()),
    9 => array(1 => type_textfield(), 2 => type_radios()),
    10 => array(1 => type_date_popup()),
    11 => array(1 => type_textfield(), 2 => type_radios(array('μmol/L','mg/dL','其它')), 3 => type_textfield(), 4 => type_radios()),
    12 => array(1 => type_textfield(), 2 => type_radios(array('μmol/L','mg/dL','其它')), 3 => type_textfield(), 4 => type_radios()),
    13 => array(1 => type_textfield(), 2 => type_radios(array('U/L','μkat/L','其它')), 3 => type_textfield(), 4 => type_radios()),
    14 => array(1 => type_textfield(), 2 => type_radios(array('U/L','μkat/L','其它')), 3 => type_textfield(), 4 => type_radios()),
    15 => array(1 => type_textfield(), 2 => type_radios(array('mg/dL','g/L','其它')), 3 => type_textfield(), 4 => type_radios()),
    16 => array(1 => type_textfield(), 2 => type_radios(array('mg/dL','g/L','其它')), 3 => type_textfield(), 4 => type_radios()),
    17 => array(1 => type_textfield(), 2 => type_radios(array('U/L','μkat/L','其它')), 3 => type_textfield(), 4 => type_radios()),
    18 => array(1 => type_textfield(), 2 => type_radios(array('U/L','μkat/L','其它')), 3 => type_textfield(), 4 => type_radios()),
    19 => array(1 => type_textfield(), 2 => type_radios(array('mmol/L','mg/L','其它')), 3 => type_textfield(), 4 => type_radios()),
    20 => array(1 => type_textfield(), 2 => type_radios(array('μmol/L','mg/dL','其它')), 3 => type_textfield(), 4 => type_radios()),
    21 => array(1 => type_textfield(), 2 => type_radios(array('ml/min','其它')), 3 => type_textfield(), 4 => type_radios()),
    22 => array(1 => type_textfield(), 2 => type_radios(array('mmol/L','其它')), 3 => type_textfield(), 4 => type_radios()),
    23 => array(1 => type_textfield(), 2 => type_radios(array('mmol/L','其它')), 3 => type_textfield(), 4 => type_radios()),
    24 => array(1 => type_textfield(), 2 => type_radios(array('mmol/L','其它')), 3 => type_textfield(), 4 => type_radios()),
    25 => array(1 => type_date_popup()),
    26 => array(1 => type_textfield(), 2 => type_radios(array('mg/L','其它')), 3 => type_textfield(), 4 => type_radios()),
);

