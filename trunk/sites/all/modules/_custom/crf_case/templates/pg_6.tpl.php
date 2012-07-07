<?php
  $key_pre = "e_{$table}";
?>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="4"><h2><?php print $table_name?></h2>
    </td>
  </tr>
  <tr>
    <td>参数</td>
    <td>数值</td>
    <td>单位</td>
    <td>是否有临床意义</td>
  </tr>
  <tr><td colspan="4"><b>血常规</b>  取样日期：<?php print drupal_render($form[$key_pre ."_1_1"]);?></td></tr>
  <tr>
    <td>白细胞计数WBC</td>
    <td><?php print drupal_render($form[$key_pre ."_2_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_3"]);?></td>
  </tr>
  <tr>
    <td>中性粒细胞计数ANC</td>
    <td><?php print drupal_render($form[$key_pre ."_3_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_3_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_3_3"]);?></td>
  </tr>
  <tr>
    <td>血红蛋白HBG</td>
    <td><?php print drupal_render($form[$key_pre ."_4_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_4_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_4_3"]);?></td>
  </tr>
  <tr>
    <td>红细胞计数RBC</td>
    <td><?php print drupal_render($form[$key_pre ."_5_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_5_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_5_3"]);?></td>
  </tr>
  <tr>
    <td>红细胞比积</td>
    <td><?php print drupal_render($form[$key_pre ."_6_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_6_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_6_3"]);?></td>
  </tr>
  <tr>
    <td>血小板计数PLT</td>
    <td><?php print drupal_render($form[$key_pre ."_7_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_7_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_7_3"]);?></td>
  </tr>
  <tr><td colspan="4"><b>凝血功能</b>  取样日期：<?php print drupal_render($form[$key_pre ."_8_1"]);?></td></tr>
  <tr><td>INR(华法令治疗者须查)</td><td colspan="2"><?php print drupal_render($form[$key_pre ."_9_1"]);?></td><td><?php print drupal_render($form[$key_pre ."_9_2"]);?></td></tr>
  <tr><td colspan="4"><b>血生化</b>  取样日期：<?php print drupal_render($form[$key_pre ."_10_1"]);?></td></tr>
  <td>总胆红素TBIL</td>
    <td><?php print drupal_render($form[$key_pre ."_11_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_11_2"]);?><?php print drupal_render($form[$key_pre ."_11_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_11_4"]);?></td>
  </tr>
  <td>结合胆红素CB</td>
    <td><?php print drupal_render($form[$key_pre ."_12_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_12_2"]);?><?php print drupal_render($form[$key_pre ."_12_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_12_4"]);?></td>
  </tr>
  <td>谷丙转氨酶ALT</td>
    <td><?php print drupal_render($form[$key_pre ."_13_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_13_2"]);?><?php print drupal_render($form[$key_pre ."_13_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_13_4"]);?></td>
  </tr>
  <td>谷草转氨酶AST</td>
    <td><?php print drupal_render($form[$key_pre ."_14_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_14_2"]);?><?php print drupal_render($form[$key_pre ."_14_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_14_4"]);?></td>
  </tr>
  <td>总蛋白TP</td>
    <td><?php print drupal_render($form[$key_pre ."_15_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_15_2"]);?><?php print drupal_render($form[$key_pre ."_15_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_15_4"]);?></td>
  </tr>
  <td>白蛋白ALB</td>
    <td><?php print drupal_render($form[$key_pre ."_16_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_16_2"]);?><?php print drupal_render($form[$key_pre ."_16_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_16_4"]);?></td>
  </tr>
  <td>碱性磷酸酶ALP</td>
    <td><?php print drupal_render($form[$key_pre ."_17_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_17_2"]);?><?php print drupal_render($form[$key_pre ."_17_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_17_4"]);?></td>
  </tr>
  <td>乳酸脱氢酶LDH</td>
    <td><?php print drupal_render($form[$key_pre ."_18_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_18_2"]);?><?php print drupal_render($form[$key_pre ."_18_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_18_4"]);?></td>
  </tr>
  <td>尿素BUN</td>
    <td><?php print drupal_render($form[$key_pre ."_19_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_19_2"]);?><?php print drupal_render($form[$key_pre ."_19_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_19_4"]);?></td>
  </tr>
  <td>肌酐CRE</td>
    <td><?php print drupal_render($form[$key_pre ."_20_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_20_2"]);?><?php print drupal_render($form[$key_pre ."_20_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_20_4"]);?></td>
  </tr>
  <td>肌酐清除率Ccr</td>
    <td><?php print drupal_render($form[$key_pre ."_21_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_21_2"]);?><?php print drupal_render($form[$key_pre ."_21_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_21_4"]);?></td>
  </tr>
  <td>钾K<sup>+</sup></td>
    <td><?php print drupal_render($form[$key_pre ."_22_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_22_2"]);?><?php print drupal_render($form[$key_pre ."_22_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_22_4"]);?></td>
  </tr>
  <td>钠Na<sup>+</sup></td>
    <td><?php print drupal_render($form[$key_pre ."_23_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_23_2"]);?><?php print drupal_render($form[$key_pre ."_23_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_23_4"]);?></td>
  </tr>
  <td>钙Ca<sup>2+</sup></td>
    <td><?php print drupal_render($form[$key_pre ."_24_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_24_2"]);?><?php print drupal_render($form[$key_pre ."_24_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_24_4"]);?></td>
  </tr>
  <tr><td colspan="4"><b>尿常规</b>  取样日期：<?php print drupal_render($form[$key_pre ."_25_1"]);?></td></tr>
  <td>尿蛋白</td>
    <td><?php print drupal_render($form[$key_pre ."_26_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_26_2"]);?><?php print drupal_render($form[$key_pre ."_26_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_26_4"]);?></td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>
