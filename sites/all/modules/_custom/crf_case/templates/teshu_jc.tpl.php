<?php
  $key_pre = "e_{$table}";
?>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="4"><h2><?php print $table_name?></h2><div> 在首次给药前15天内进行</div>
    </td>
  </tr>
  <tr>
    <td>评估类型</td><td>评估日期</td><td>是否涉及肿瘤<br/>是/否</td><td>说明(仅当必要时)</td>
  </tr>
  <tr>
    <td>胸部X线检查</td>
    <td><?php print drupal_render($form[$key_pre ."_1_1"]);?><?php print drupal_render($form[$key_pre ."_1_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_1_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_1_4"]);?></td>
  </tr>
  <tr>
    <td>腹部CT检查</td>
    <td><?php print drupal_render($form[$key_pre ."_2_1"]);?><?php print drupal_render($form[$key_pre ."_2_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_4"]);?></td>
  </tr>
  <tr>
    <td>腹部MRI</td>
    <td><?php print drupal_render($form[$key_pre ."_3_1"]);?><?php print drupal_render($form[$key_pre ."_3_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_3_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_3_4"]);?></td>
  </tr>
  <tr>
    <td>盆腔CT检查</td>
    <td><?php print drupal_render($form[$key_pre ."_4_1"]);?><?php print drupal_render($form[$key_pre ."_4_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_4_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_4_4"]);?></td>
  </tr>
  <tr>
    <td>盆腔MRI</td>
    <td><?php print drupal_render($form[$key_pre ."_5_1"]);?><?php print drupal_render($form[$key_pre ."_5_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_5_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_5_4"]);?></td>
  </tr>
  <tr>
    <td>胸部CT检查</td>
    <td><?php print drupal_render($form[$key_pre ."_6_1"]);?><?php print drupal_render($form[$key_pre ."_6_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_6_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_6_4"]);?></td>
  </tr>
  <tr>
    <td>胸部MRI</td>
    <td><?php print drupal_render($form[$key_pre ."_7_1"]);?><?php print drupal_render($form[$key_pre ."_7_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_7_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_7_4"]);?></td>
  </tr>
  <tr>
    <td>头颅CT检查</td>
    <td><?php print drupal_render($form[$key_pre ."_8_1"]);?><?php print drupal_render($form[$key_pre ."_8_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_8_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_8_4"]);?></td>
  </tr>
  <tr>
    <td>头颅MRI</td>
    <td><?php print drupal_render($form[$key_pre ."_9_1"]);?><?php print drupal_render($form[$key_pre ."_9_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_9_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_9_4"]);?></td>
  </tr>
  <tr>
    <td>骨扫描</td>
    <td><?php print drupal_render($form[$key_pre ."_10_1"]);?><?php print drupal_render($form[$key_pre ."_10_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_10_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_10_4"]);?></td>
  </tr>
  <tr>
    <td>全身PET/CT</td>
    <td><?php print drupal_render($form[$key_pre ."_11_1"]);?><?php print drupal_render($form[$key_pre ."_11_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_11_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_11_4"]);?></td>
  </tr>
  <tr>
    <td>其它，详细说明：<br/><?php print drupal_render($form[$key_pre ."_12_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_12_2"]);?><?php print drupal_render($form[$key_pre ."_12_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_12_4"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_12_5"]);?></td>
  </tr>
  <tr>
    <td>其它，详细说明：<br/><?php print drupal_render($form[$key_pre ."_13_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_13_2"]);?><?php print drupal_render($form[$key_pre ."_13_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_13_4"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_13_5"]);?></td>
  </tr>
  <tr>
    <td>其它，详细说明：<br/><?php print drupal_render($form[$key_pre ."_14_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_14_2"]);?><?php print drupal_render($form[$key_pre ."_14_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_14_4"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_14_5"]);?></td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>