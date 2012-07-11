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
    3 => array(1 => type_textfield('',1), 2 => type_textfield('',1), 3 => type_textfield('',1), 4 => type_textfield('',1), 5 => type_textfield('',1), 6 => type_textfield('',1), 7 => type_textfield('',1)),
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

$crf_el['zq1_1'] = array(
  '#name' => '研究给药',
    1 => array(1 => type_date_popup(), 2 => type_date_popup(), 3 => type_checkboxs(array('40mg','50mg','60mg')), 4 => type_textfield()),
    2 => array(1 => type_checkboxs(array('不适用')), 2 => type_date_popup(), 3 => type_textfield(), 4 => type_textfield()),
);

$crf_el['zq1_2'] = array(
    '#name' => '伴随治疗',
    1 => array(1 => type_checkboxs(array('无'))),
    2 => array(1 => type_textfield('',10), 2 => type_textfield('',10), 3 => type_textfield('',10), 4 => type_radios(array('','')), 5 => type_textfield('',10), 6 => type_date_popup(), 7 => type_date_popup(), 8 => type_checkboxs(array(''))),
    3 => array(1 => type_textfield('',10), 2 => type_textfield('',10), 3 => type_textfield('',10), 4 => type_radios(array('','')), 5 => type_textfield('',10), 6 => type_date_popup(), 7 => type_date_popup(), 8 => type_checkboxs(array(''))),
    4 => array(1 => type_textfield('',10), 2 => type_textfield('',10), 3 => type_textfield('',10), 4 => type_radios(array('','')), 5 => type_textfield('',10), 6 => type_date_popup(), 7 => type_date_popup(), 8 => type_checkboxs(array(''))),
    5 => array(1 => type_textfield('',10), 2 => type_textfield('',10), 3 => type_textfield('',10), 4 => type_radios(array('','')), 5 => type_textfield('',10), 6 => type_date_popup(), 7 => type_date_popup(), 8 => type_checkboxs(array(''))),
    6 => array(1 => type_textfield('',10), 2 => type_textfield('',10), 3 => type_textfield('',10), 4 => type_radios(array('','')), 5 => type_textfield('',10), 6 => type_date_popup(), 7 => type_date_popup(), 8 => type_checkboxs(array(''))),
    7 => array(1 => type_textfield('',10), 2 => type_textfield('',10), 3 => type_textfield('',10), 4 => type_radios(array('','')), 5 => type_textfield('',10), 6 => type_date_popup(), 7 => type_date_popup(), 8 => type_checkboxs(array(''))),
    8 => array(1 => type_textfield('',10), 2 => type_textfield('',10), 3 => type_textfield('',10), 4 => type_radios(array('','')), 5 => type_textfield('',10), 6 => type_date_popup(), 7 => type_date_popup(), 8 => type_checkboxs(array(''))),
    9 => array(1 => type_textfield('',10), 2 => type_textfield('',10), 3 => type_textfield('',10), 4 => type_radios(array('','')), 5 => type_textfield('',10), 6 => type_date_popup(), 7 => type_date_popup(), 8 => type_checkboxs(array(''))),
    10 => array(1 => type_textfield('',10), 2 => type_textfield('',10), 3 => type_textfield('',10), 4 => type_radios(array('','')), 5 => type_textfield('',10), 6 => type_date_popup(), 7 => type_date_popup(), 8 => type_checkboxs(array(''))),
    11 => array(1 => type_textfield('',10), 2 => type_textfield('',10), 3 => type_textfield('',10), 4 => type_radios(array('','')), 5 => type_textfield('',10), 6 => type_date_popup(), 7 => type_date_popup(), 8 => type_checkboxs(array(''))),
);

$crf_el['zq2_1'] = array(
    '#name' => '第一周期化疗不良事件',
    1 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    2 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    3 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    4 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    5 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    6 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    7 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    8 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    9 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    10 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    11 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    12 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    13 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    14 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    15 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    16 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    17 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    18 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    19 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    20 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    21 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    22 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    23 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    24 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    25 => array(1 => type_textfield('', 3), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield(), 6 => type_textfield('',6), 7 => type_textfield()),
    26 => array(1 => type_textfield('',6), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield('', 3), 6 => type_textfield(), 7 => type_textfield('',6), 8 => type_textfield()),
    27 => array(1 => type_textfield('',6), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield('', 3), 6 => type_textfield(), 7 => type_textfield('',6), 8 => type_textfield()),
    28 => array(1 => type_textfield('',6), 2 => type_textfield('', 3), 3 => type_textfield('', 3), 4 => type_textfield('', 3), 5 => type_textfield('', 3), 6 => type_textfield(), 7 => type_textfield('',6), 8 => type_textfield()),
);

$crf_el['zq2_2'] = array(
  '#name' => '第一周期研究治疗是否发生减量/或延迟用药？',
  1 => array(1 => type_checkboxs(array('否，请跳过本表'))),  
  2 => array(1 => type_checkboxs(array('奥沙利铂')), 2 => type_checkboxs(array('减量','延迟')), 3 => type_textfield()),
  3 => array(1 => type_checkboxs(array('S-1')), 2 => type_checkboxs(array('减量','延迟')), 3 => type_textfield()),
);

$crf_el['zq2_3'] = array(
  '#name' => '第一周期研究治疗是否发生减量/或延迟用药？',
  1 => array(1 => type_checkboxs(array('未做'))),
  2 => array(1 => type_textfield(), 2 => type_radios(array('x10<sup>3</sup>/mm<sup>3</sup>','x10<sup>9</sup>/L')), 3 => type_radios(), 4 => type_date_popup()),  
  3 => array(1 => type_textfield(), 2 => type_radios(array('x10<sup>3</sup>/mm<sup>3</sup>','x10<sup>9</sup>/L')), 3 => type_radios(), 4 => type_date_popup()),  
  4 => array(1 => type_textfield(), 2 => type_radios(array('ml/min','其它')), 3 => type_textfield(), 4 => type_radios(), 5 => type_date_popup()),
  5 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_radios(), 5 => type_date_popup()),
  6 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_radios(), 5 => type_date_popup()),
  7 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_radios(), 5 => type_date_popup()),
);

$crf_el['zq2_4'] = array(
  '#name' => '研究给药',
    1 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_date_popup(), 4 => type_date_popup(), 5 => type_checkboxs(array('40mg','50mg','60mg')), 6 => type_textfield()),
    2 => array(1 => type_checkboxs(array('不适用')), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup(), 5 => type_textfield('',8), 6 => type_textfield()),
);

$crf_el['zq2_5'] = $crf_el['zq1_2'];

//3 4 5 6 7表 = 2表
for($i=3; $i++; $i<8) {
  $crf_el["zq{$i}_1"] = $crf_el['zq2_1'];
  $crf_el["zq{$i}_2"] = $crf_el['zq2_2'];
  $crf_el["zq{$i}_3"] = $crf_el['zq2_3'];
  $crf_el["zq{$i}_4"] = $crf_el['zq2_4'];
  $crf_el["zq{$i}_5"] = $crf_el['zq2_5'];
}

//8为4个表
$crf_el['zq8_1'] = $crf_el['zq2_1'];
$crf_el['zq8_2'] = $crf_el['zq2_3'];

$crf_el['zq8_3'] = array(
  '#name' => '研究给药',
    1 => array(1 => type_textfield(), 2 => type_textfield()),
    2 => array(1 => type_radios(), 2 => type_textfield()),
    3 => array(1 => type_date_popup(), 2 => type_date_popup()),
    4 => array(1 => type_textfield(), 2 => type_textfield()),
); 

$crf_el['zq8_4'] = array(
    '#name' => '伴随治疗',
    1 => array(1 => type_checkboxs(array('无'))),
    2 => array(1 => type_textfield('',10), 2 => type_textfield('',10), 3 => type_textfield('',10), 4 => type_radios(array('','')), 5 => type_textfield('',10), 6 => type_date_popup(), 7 => type_date_popup(), 8 => type_checkboxs(array(''))),
    3 => array(1 => type_textfield('',10), 2 => type_textfield('',10), 3 => type_textfield('',10), 4 => type_radios(array('','')), 5 => type_textfield('',10), 6 => type_date_popup(), 7 => type_date_popup(), 8 => type_checkboxs(array(''))),
    4 => array(1 => type_textfield('',10), 2 => type_textfield('',10), 3 => type_textfield('',10), 4 => type_radios(array('','')), 5 => type_textfield('',10), 6 => type_date_popup(), 7 => type_date_popup(), 8 => type_checkboxs(array(''))),
);

//9-16 table
//$crf_el['zq9_1'] = $crf_el['zq10_1'] = $crf_el['zq11_1'] = $crf_el['zq12_1'] = $crf_el['zq13_1'] = $crf_el['zq14_1'] = $crf_el['zq15_1'] = $crf_el['zq16_1'] = $crf_el['zq8_1'];
for($i=9; $i++; $i<17) {
  $crf_el["zq{$i}_1"] = $crf_el['zq8_1'];
  $crf_el["zq{$i}_2"] = $crf_el['zq8_2'];
  $crf_el["zq{$i}_3"] = $crf_el['zq8_3'];
  $crf_el["zq{$i}_4"] = $crf_el['zq8_4'];

}

$crf_el['zhiliao_js'] = array(
  '#name' => '治疗结束',
    1 => array(1 => type_date_popup()),
    2 => array(1 => type_radios(), 2 => type_textfield()),
    3 => array(1 => type_date_popup()),
    4 => array(1 => type_checkboxs(array('同时应用研究方案之外的抗肿瘤治疗','未按方案规定剂量和疗程用药','受试者出现病情进展','经剂量调整和药物暂停后受试者毒性仍然无法耐受者','受试者主动要求退出试验','研究者认为受试者有必要停止试验','院外治疗失访','死亡'))),
);

$crf_el['xueye_zlbjwjcjghzb'] = array(
  '#name' => '血液肿瘤标记物检测结果汇总表',
    1 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    2 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    3 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    4 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    5 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    6 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    7 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    8 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    9 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    10 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    11 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    12 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
);

$crf_el['yanzhong_blsjjl'] = array(
  '#name' => '严重不良事件记录',
    1 => array(1 => type_date_popup()),
    2 => array(1 => type_checkboxs(array('1患者','2家属','3研究者','4其它')), 2 => type_textfield()),
    3 => array(1 => type_textfield(), 2 => type_textfield()),
    4 => array(1 => type_textfield(), 2 => type_textfield()),
    5 => array(1 => type_textfield(), 2 => type_textfield('', 5), 3 => type_radios(array('男','女'))),
    6 => array(1 => type_textfield()),
    7 => array(1 => type_date_popup()),
    8 => array(1 => type_checkboxs(array('1医院','2诊所','3家庭','4工作单位','5其它')), 2 => type_textfield()),
    9 => array(1 => type_checkboxs(array('1必须住院治疗或者延长住院时间','2致畸/出生缺陷','3危及生命','4永久性的或严重的残疾/功能障碍','5重大医疗事故','6死亡')), 2 => type_date_popup()),
    10 => array(1 => type_checkboxs(array('1医师','2技师','3护士','4其它')), 2 => type_textfield()),
    11 => array(1 => type_textfield()),
    12 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_textfield(), 5 => type_textfield(), 6 => type_textfield()),
    13 => array(1 => type_date_popup(), 2 => type_date_popup()),
    14 => array(1 => type_textfield()),
    15 => array(1 => type_textfield()),
    16 => array(1 => type_checkboxs(array('1已通知医院','2已通知企业','3已通知本地药监分局'))),
    17 => array(1 => type_checkboxs(array('1肯定有关','2很可能有关','3可能有关','4可能无关','5无关'))),
    18 => array(1 => type_textfield(), 2 => type_date_popup()),
);

$crf_el['yanzhong_blsjjl_1'] = $crf_el['yanzhong_blsjjl'];

// the second file
$crf_el['pg1_1'] = $crf_el['pg2_1'] = $crf_el['pg3_1'] = $crf_el['pg4_1'] = $crf_el['pg5_1'] = array(
  '#name' => '体格检查',
    1 => array(1 => type_date_popup()),
    2 => array(1 => type_textfield(), 2 => type_textfield()),
    3 => array(1 => type_textfield(), 2 => type_textfield()),
    4 => array(1 => type_radios(array('未做','正常','异常无临床意义','异常有临床意义')), 2 => type_textfield()),
    5 => array(1 => type_radios(array('未做','正常','异常无临床意义','异常有临床意义')), 2 => type_textfield()),
    6 => array(1 => type_radios(array('很差','差','尚可','较好','良好'))),
    7 => array(1 => type_radios(array('未做','正常','异常无临床意义','异常有临床意义')), 2 => type_textfield()),
);

$crf_el['pg1_2'] = $crf_el['pg2_2'] = $crf_el['pg3_2'] = $crf_el['pg4_2'] = $crf_el['pg5_2'] = array(
  '#name' => '心电图检查',
    1 => array(1 => type_checkboxs(array('未做，则跳过本表'))),
    2 => array(1 => type_date_popup()),
    3 => array(1 => type_radios(array('正常','异常')), 2 => type_textfield()),
);

$crf_el['pg1_3'] = $crf_el['pg2_3'] = $crf_el['pg3_3'] = $crf_el['pg4_3'] = $crf_el['pg5_3'] = array(
  '#name' => '肿瘤评估',
    1 => array(1 => type_checkboxs(array('未做，请跳过本表'))),
    2 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    3 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    4 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    5 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    6 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    7 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    8 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    9 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    10 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
);

$crf_el['pg1_4'] = $crf_el['pg2_4'] = $crf_el['pg3_4'] = $crf_el['pg4_4'] = $crf_el['pg5_4'] = array(
  '#name' => '血液肿瘤标记物检测',
    1 => array(1 => type_checkboxs(array('未做，请跳过本表'))),
    2 => array(1 => type_checkboxs(array('未做')), 2 => type_textfield(), 3 => type_radios(array('ng/ml','其它')), 4 => type_textfield(), 5 => type_date_popup()),
    3 => array(1 => type_checkboxs(array('未做')), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    4 => array(1 => type_checkboxs(array('未做')), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
);

$crf_el['pg1_5'] = $crf_el['pg2_5'] = $crf_el['pg3_5'] = $crf_el['pg4_5'] = $crf_el['pg5_5'] = array(
  '#name' => '肿瘤是否进展/复发/转移？',
    1 => array(1 =>  type_radios(array('否','是，请确认已将诊断肿瘤进展的相关检查填入上述表中。'))),
);

$crf_el['pg1_6'] = $crf_el['pg2_6'] = $crf_el['pg3_6'] = $crf_el['pg4_6'] = $crf_el['pg5_6'] = $crf_el['shiyan_sjc'];

$crf_el['sf1_1'] = $crf_el['sf2_1'] = $crf_el['sf3_1'] = $crf_el['sf4_1'] = $crf_el['sf5_1'] = $crf_el['sf6_1'] = $crf_el['sf7_1'] = $crf_el['sf8_1'] = $crf_el['sf9_1'] = array(
  '#name' => '患者状态',
    1 => array(1 => type_date_popup()),
    2 => array(1 =>  type_radios(array('办公室/医院随访','电话/写信或其它联系方式'))),
    3 => array(1 =>  type_radios(array('存活','死亡，请填写<b>死亡报告表</b>','失访'))),
);

$crf_el['sf1_2'] = $crf_el['sf2_2'] = $crf_el['sf3_2'] = $crf_el['sf4_2'] = $crf_el['sf5_2'] = $crf_el['sf6_2'] = $crf_el['sf7_2'] = $crf_el['sf8_2'] = $crf_el['sf9_2'] = array(
  '#name' => '疾病状况',
    1 => array(1 => type_checkboxs(array('已报告疾病进展','本次随访时发现疾病进展（请填写下<b>述肿瘤评估表</b>）','没有进展','未知/不适用'))),
);

$crf_el['sf1_3'] = $crf_el['sf2_3'] = $crf_el['sf3_3'] = $crf_el['sf4_3'] = $crf_el['sf5_3'] = $crf_el['sf6_3'] = $crf_el['sf7_3'] = $crf_el['sf8_3'] = $crf_el['sf9_3'] = array(
  '#name' => '肿瘤评估',
    1 => array(1 => type_checkboxs(array('未做，请跳过本表'))),
    2 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    3 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    4 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    5 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    6 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    7 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    8 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
    9 => array(1 => type_textfield(), 2 => type_textfield(), 3 => type_textfield(), 4 => type_date_popup()),
);

$crf_el['siwang_jl'] = array(
  '#name' => '死亡记录',
    1 => array(1 => type_date_popup()),
    2 => array(1 => type_checkboxs(array('原发肿瘤'))),
    3 => array(1 => type_checkboxs(array('其它疾病')), 2 => type_textfield()),
    4 => array(1 => type_checkboxs(array('其它原因')), 2 => type_textfield()),
    5 => array(1 => type_checkboxs(array('原因不明')), 2 => type_textfield()),
);

$crf_el['yanjiu_js'] = array(
  '#name' => '研究结束',
    1 => array(1 => type_date_popup()),
    2 => array(1 => type_checkboxs(array('完成研究随访'))),
    3 => array(1 => type_checkboxs(array('撤回知情同意'))),
    4 => array(1 => type_checkboxs(array('由于搬迁、转院、繁忙等原因难以继续进行研究'))),
    5 => array(1 => type_checkboxs(array('死亡'))),
    6 => array(1 => type_checkboxs(array('其它')), 2 => type_textfield()),
    7 => array(1 => type_textfield()),
    8 => array(1 => type_date_popup()),
);