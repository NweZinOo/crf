<?php
  $key_pre = "e_{$table}";
?>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="5"><h2><?php print $table_name?></h2> <div><?php print drupal_render($form[$key_pre ."_1_1"]);?></div>
    </td>
  </tr>
  <tr>
    <td rowspan="2" width="20%">项目</td>
    <td width="20%">最严重时分级#</td>
    <td rowspan="2" width="25%">处理措施*</td>
    <td rowspan="2" width="10%">转归**</td>
    <td rowspan="2" width="15%">与研究药物关系***</td>
  </tr>
  <tr>
    <td width="15%">I/II/III/IV</td>
  </tr>
  <tr>
    <td>血红蛋白（g/L）</td>
    <td><?php print drupal_render($form[$key_pre ."_2_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_2_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_2_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_2_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_6"]);?></td>
  </tr>
  <tr>
    <td>白细胞（10<sup>9</sup>/L）</td>
    <td><?php print drupal_render($form[$key_pre ."_3_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_3_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_3_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_3_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_3_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_3_6"]);?></td>
  </tr>
  <tr>
    <td>粒细胞（10<sup>9</sup>/L）</td>
    <td><?php print drupal_render($form[$key_pre ."_4_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_4_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_4_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_4_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_4_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_4_6"]);?></td>
  </tr>
  <tr>
    <td>血小板（10<sup>9</sup>/L）</td>
    <td><?php print drupal_render($form[$key_pre ."_5_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_5_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_5_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_5_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_5_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_5_6"]);?></td>
  </tr>
  <tr>
    <td>胆红素（mg/dL）</td>
    <td><?php print drupal_render($form[$key_pre ."_6_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_6_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_6_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_6_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_6_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_6_6"]);?></td>
  </tr>
  <tr>
    <td>ALT（IU/L）</td>
    <td><?php print drupal_render($form[$key_pre ."_7_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_7_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_7_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_7_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_7_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_7_6"]);?></td>
  </tr>
  <tr>
    <td>AST（IU/L）</td>
    <td><?php print drupal_render($form[$key_pre ."_8_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_8_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_8_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_8_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_8_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_8_6"]);?></td>
  </tr>
  <tr>
    <td>ALP（IU/L）</td>
    <td><?php print drupal_render($form[$key_pre ."_9_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_9_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_9_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_9_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_9_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_9_6"]);?></td>
  </tr>
  <tr>
    <td>BUN（mmol/L）</td>
    <td><?php print drupal_render($form[$key_pre ."_10_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_10_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_10_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_10_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_10_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_10_6"]);?></td>
  </tr>
  <tr>
    <td>Cr（µmol/L）</td>
    <td><?php print drupal_render($form[$key_pre ."_11_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_11_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_11_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_11_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_11_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_11_6"]);?></td>
  </tr>
  <tr>
    <td>出血</td>
    <td><?php print drupal_render($form[$key_pre ."_12_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_12_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_12_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_12_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_12_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_12_6"]);?></td>
  </tr>
  <tr>
    <td>血尿</td>
    <td><?php print drupal_render($form[$key_pre ."_13_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_13_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_13_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_13_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_13_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_13_6"]);?></td>
  </tr>
  <tr>
    <td>口腔炎</td>
    <td><?php print drupal_render($form[$key_pre ."_14_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_14_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_14_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_14_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_14_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_14_6"]);?></td>
  </tr>
  <tr>
    <td>恶心、呕吐</td>
    <td><?php print drupal_render($form[$key_pre ."_15_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_15_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_15_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_15_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_15_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_15_6"]);?></td>
  </tr>
  <tr>
    <td>腹泻</td>
    <td><?php print drupal_render($form[$key_pre ."_16_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_16_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_16_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_16_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_16_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_16_6"]);?></td>
  </tr>
  <tr>
    <td>药物致发热</td>
    <td><?php print drupal_render($form[$key_pre ."_17_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_17_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_17_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_17_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_17_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_17_6"]);?></td>
  </tr>
  <tr>
    <td>脱发</td>
    <td><?php print drupal_render($form[$key_pre ."_18_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_18_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_18_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_18_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_18_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_18_6"]);?></td>
  </tr>
  <tr>
    <td>过敏</td>
    <td><?php print drupal_render($form[$key_pre ."_19_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_19_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_19_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_19_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_19_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_19_6"]);?></td>
  </tr>
  <tr>
    <td>皮肤</td>
    <td><?php print drupal_render($form[$key_pre ."_20_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_20_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_20_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_20_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_20_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_20_6"]);?></td>
  </tr>  
  <tr>
    <td>肺部</td>
    <td><?php print drupal_render($form[$key_pre ."_21_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_21_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_21_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_21_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_21_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_21_6"]);?></td>
  </tr>  
  <tr>
    <td>心脏</td>
    <td><?php print drupal_render($form[$key_pre ."_22_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_22_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_22_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_22_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_22_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_22_6"]);?></td>
  </tr>
  <tr>
    <td>神志</td>
    <td><?php print drupal_render($form[$key_pre ."_23_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_23_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_23_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_23_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_23_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_23_6"]);?></td>
  </tr>
  <tr>
    <td>周围神经</td>
    <td><?php print drupal_render($form[$key_pre ."_24_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_24_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_24_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_24_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_24_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_24_6"]);?></td>
  </tr>
  <tr>
    <td>便秘</td>
    <td><?php print drupal_render($form[$key_pre ."_25_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_25_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_25_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_25_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_25_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_25_6"]);?></td>
  </tr>
  <tr>
    <td>局部静脉</td>
    <td><?php print drupal_render($form[$key_pre ."_26_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_26_2"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_26_3"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_26_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_26_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_26_6"]);?></td>
  </tr>
  <tr>
    <td>其它，<?php print drupal_render($form[$key_pre ."_27_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_27_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_27_3"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_27_4"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_27_5"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_27_6"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_27_7"]);?></td>
  </tr>
  <tr>
    <td>其它，<?php print drupal_render($form[$key_pre ."_28_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_28_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_28_3"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_28_4"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_28_5"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_28_6"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_28_7"]);?></td>
  </tr>
  <tr>
    <td>其它，<?php print drupal_render($form[$key_pre ."_29_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_29_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_29_3"]);?><br/>选其它，请说明其它处理措施<?php print drupal_render($form[$key_pre ."_29_4"]);?>
    <br/>选停药，请说明药物名称<?php print drupal_render($form[$key_pre ."_29_5"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_29_6"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_29_7"]);?></td>
  </tr>
</table>
<table>
<tr>
    <td>
      #如在CTCAE分级中无此项目，则分级为：I＝轻度；Ⅱ＝中度；Ⅲ＝重度；Ⅳ＝危及生命<br/>
      *对受试药采取措施分为①继续用药②减少用量③暂停后继续用药④停药⑤其它请详细说明。对减量、暂停后继续用药、停药者，请具体说明药物名称。<br/>
      **转归分为①消失②改善③无改善④加重<br/>
      ***与用药的关系分为：1肯定有关 2很可能有关 3可能有关 4可能无关 5肯定无关。
    </td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>