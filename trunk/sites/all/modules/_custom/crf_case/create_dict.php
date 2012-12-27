<?php
include_once dirname(__FILE__) . '/dict.php';

$str = "代码,名称,变量类型,取值说明\n\r";

foreach($data_basic as $k => $v) {
  $str.= $v[0].','.$v[1].','.$v[2].','.$v[3]."\n\r";
}

print $str;