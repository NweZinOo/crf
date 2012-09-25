<?php
/**
 * 所有case表的定义
 */

global $crf_el, $crf_el_name;
//print_r($_SESSION);

$genders[0] = "男";
$genders[1] = "女";
//global $user;
//$profile =  profile_load_profile($user);
//print_r($user);
$crf_el['dyxx'] = array(
  '#name'  => '调研数据录入',
  1 => array(1 => type_textfield(), 2 => type_textfield('',10), 3 => type_textfield('',10), 4 => type_radios(array('男','女'))),
  2 => array(1 => type_textfield('',80), 2 => type_textfield()),
  3 => array(1 => type_textfield('',80), 2 => type_textfield()),
  4 => array(1 => type_date_popup()),
  5 => array(1 => type_checkboxs(array('1骨髓增生异常综合征(MDS)，（原发/  继发/  治疗相关）其WHO(2008)分型为:'))),
//  6 => array(1 => type_checkboxs(array('1.1难治性贫血（RA）','1.2难治性血细胞减少伴多系发育异常（RCMD）','1.3 RARS','1.4 RAEB-1','1.5 RAEB-2','1.6 MDS-U','1.7 5q-综合征'))),
  6 => array(1 => type_checkboxs(array('1.1难治性贫血（RA）')), 2 => type_checkboxs(array('1.2难治性血细胞减少伴多系发育异常（RCMD）')), 3 => type_checkboxs(array('1.3 RARS')), 4 => type_checkboxs(array('1.4 RAEB-1')), 5 => type_checkboxs(array('1.5 RAEB-2')), 6 => type_checkboxs(array('1.6 MDS-U')), 7 => type_checkboxs(array('1.7 5q-综合征'))),
  7 => array(1 => type_checkboxs(array('2再生障碍性贫血(AA)')), 2 => type_checkboxs(array('3纯红细胞再生障碍性贫血'))),
  8 => array(1 => type_checkboxs(array('4骨髓纤维化')), 2 => type_checkboxs(array('5其它')), 3 => type_textfield()),
  9 => array(1 => type_radios(array('极低危组','低危组','中危组','高危组','极高危组'))),
  10 => array(1 => type_date_popup()),
  11 => array(1 => type_textfield('',100)),
  12 => array(1 => type_date_popup()),
  13 => array(1 => type_textfield('',100)),
  14 => array(1 => type_date_popup()),
  15 => array(1 => type_textfield('',100)),
  16 => array(1 => type_checkboxs(array('无'))),
  17 => array(1 => type_date_popup()),
  18 => array(1 => type_textfield()),
  19 => array(1 => type_date_popup(),2 => type_date_popup()),
  20 => array(1 => type_textfield(),2 => type_textfield()),
  21 => array(1 => type_textfield(),2 => type_textfield()),
  22 => array(1 => type_textfield(),2 => type_textfield()),
  23 => array(1 => type_date_popup()),
  24 => array(1 => type_textfield(),2 => type_textfield(),3 => type_textfield(),4 => type_textfield(),5 => type_textfield()),
  25 => array(1 => type_date_popup()),
  26 => array(1 => type_textfield(),2 => type_textfield()),
  27 => array(1 => type_textfield(),2 => type_textfield()),
  28 => array(1 => type_date_popup()),
  29 => array(1 => type_radios(array('轻度','中度','重度'))),
  30 => array(1 => type_textfield(),2 => type_textfield()),
  31 => array(1 => type_date_popup()),
  32 => array(1 => type_textfield()),
  33 => array(1 => type_textfield()),
  34 => array(1 => type_radios(array('不进行祛铁治疗','进行祛铁治疗,请继续填写访视记录(每3个月随访一次)'))),
  35 => array(1 => type_radios(array('是','否'))),
  36 => array(1 => type_textfield(),2 => type_date_popup()),
//  33 => array(1 => type_textfield($user->profile_hospital_no)),
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

$crf_el_name['dyxx'] = array(
  '#name'  => '调研数据录入',
  1 => array(
      1 => array("name" => "患者姓名"), 
      2 => array("name" => "姓名缩写"),  
      3 => array("name" => "年龄(岁)"), 
      4 => array("name" => "性别", 
          "value" => array("男" => 0, "女" => 1)
      )
  ),
  2 => array(
      1 => array("name" => "家庭住址"), 
      2 => array("name" => "联系电话")
  ),
  3 => array(
      1 => array("name" => "身份证号码"), 
      2 => array("name" => "体重(kg)")
  ),
  4 => array(
      1 => array("name" => "诊断日期")
  ),
  5 => array(
      1 => array("name" => "1骨髓增生异常综合征(MDS)，（原发/  继发/  治疗相关）其WHO(2008)分型为")
  ),
  6 => array(
      1 => array("name" => "1.1难治性贫血（RA）", "value" => 1), 
      2 => array("name" => "1.2难治性血细胞减少伴多系发育异常（RCMD）", "value" => 1),
      3 => array("name" => "1.3 RARS"), 
      4 => array("name" => "1.4 RAEB-1", "value" => 1), 
      5 => array("name" => "1.5 RAEB-2", "value" => 1), 
      6 => array("name" => "1.6 MDS-U", "value" => 1), 
      7 => array("name" => "1.7 5q-综合征", "value" => 1)
  ),
  7 => array(1 => array("name"=>"2再生障碍性贫血(AA)"), 2 =>array("name" =>"3纯红细胞再生障碍性贫血")),
  8 => array(1 => array("name"=>"4骨髓纤维化"), 2 => array("name"=>"5其它"), 3 => array("name"=>"5其它")),
  9 => array(1 => array("name"=>"WPSS 评分","value"=>array('极低危组'=>0,'低危组'=>1,'中危组'=>2,'高危组'=>3,'极高危组'=>4))),
  10 => array(1 => array("name" => "骨髓穿刺日期")),
  11 => array(1 => array("name" => "骨髓穿刺结果")),
  12 => array(1 => array("name" => "染色体检查日期")),
  13 => array(1 => array("name" => "染色体检查结果")),
  14 => array(1 => array("name" => "基因检测日期")),
  15 => array(1 => array("name" => "基因检测结果")),
  16 => array(1 => array("name" => "输血治疗史", "value" => 1)),
  17 => array(1 => array("name" => "输血治疗的开始日期")),
  18 => array(1 => array("name" => "既往RBC输注总量")),
  19 => array(1 => array("name" => "血铁五项取样日期"), 2 => array("name" => "血铁五项取样日期")),
  20 => array(1 => array("name" => "血清铁蛋白"), 2 => array("name" => "血清铁蛋白")),
  21 => array(1 => array("name" => "转铁蛋白饱和度"), 2 => array("name" => "转铁蛋白饱和度")),
  22 => array(1 => array("name" => "总铁结合力"), 2 => array("name" => "总铁结合力")),
  23 => array(1 => array("name" => "血常规取样日期")),
  24 => array(1 => array("name" => "Hb"),2 => array("name" => "WBC"),3 => array("name" => "ANC"),4 => array("name" => "PLT"),5 => array("name" => "Ret")),
  25 => array(1 => array("name" => "血生化取样日期")),
  26 => array(1 => array("name" => "谷草转氨酶(SGOT)"), 2 => array("name" => "谷丙转氨酶(SGPT)")),
  27 => array(1 => array("name" => "空腹血糖(FBS)"), 2 => array("name" => "餐后两小时血糖")),
  28 => array(1 => array("name" => "MRI肝脏检测日期")),
  29 => array(1 => array("name"=>"MRI肝脏","value"=>array('轻度'=>0,'中度'=>1,'重度'=>2))),
  30 => array(1 => array("name" => "T2"), 2 => array("name" => "LIC")),
  31 => array(1 => array("name" => "MRI心脏检测日期")),
  32 => array(1 => array("name" => "T2")),
  33 => array(1 => array("name" => "LIC")),
  34 => array(1 => array("name"=>"祛铁治疗","value"=>array('不进行祛铁治疗'=>0,'进行祛铁治疗'=>1))),
//  35 => array(1 => type_radios(array('是','否'))),
//  36 => array(1 => array("name" => "T2"), 2 => array("name" => "LIC")),
);

for ($i=1; $i<=5; $i++) {
  $crf_el_name["sf_{$i}"] = array(
    '#name' => "第{$i}次随访",
//    1 => array(1 => type_date_popup()),
    2 => array(1 => array("name" => "药物名称")),
    3 => array(1 => array("name" => "剂量第一个月"),2 => array("name" => "剂量第二个月"),3 => array("name" => "剂量第三个月")),
    4 => array(1 => array("name" => "治疗时间第一个月"),2 => array("name" => "治疗时间第二个月"),3 => array("name" => "治疗时间第三个月")),
    5 => array(1 => array(1 => array("name" => "血铁五项取样日期第一个月"),2 => array("name" => "血铁五项取样日期第二个月"),3 => array("name" => "血铁五项取样日期第三个月"))),
    6 => array(1 => array(1 => array("name" => "血清铁蛋白"))),
    7 => array(1 => array("name" => "血常规取样日期")),
    8 => array(1 => array("name" => "血常规Hb"),2 => array("name" => "血常规WBC"),3 => array("name" => "血常规ANC"),4 => array("name" => "血常规PLT")),
//    9 => array(1 => array("name" => "其它")),
    10 => array(1 => array("name" => "血生化取样日期")),
    11 => array(1 => array(1 => array("name" => "谷草转氨酶(SGOT)"),2 => array("name" => "谷丙转氨酶(SGPT)"))),
    12 => array(1 => array("name" => "空腹血糖(FBS)")),
//    13 => array(1 => type_textfield(),2 => type_textfield(),3 => type_date_popup(),4 => type_date_popup()),
//    14 => array(1 => type_textfield(),2 => type_textfield(),3 => type_date_popup(),4 => type_date_popup()),
//    15 => array(1 => type_textfield(),2 => type_textfield(),3 => type_date_popup(),4 => type_date_popup()),
//    16 => array(1 => type_textfield(),2 => type_textfield(),3 => type_date_popup(),4 => type_date_popup()),
//    17 => array(1 => type_date_popup()),
//    18 => array(1 => type_textfield('',100)),
  );
}