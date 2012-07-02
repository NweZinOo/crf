<?php
  $key_pre = "e_{$table}";
?>
<div class="big-title"><?php print $table_name?></div>
<table class="<?php print $class?>" border="1">
  <tr>
    <td>标记物名称</td>
    <td>结果</td>
    <td>单位</td>
    <td>取样日期</td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_1_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_1_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_1_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_1_4"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_2_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_4"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_3_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_3_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_3_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_3_4"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_4_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_4_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_4_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_4_4"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_5_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_5_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_5_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_5_4"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_6_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_6_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_6_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_6_4"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_7_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_7_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_7_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_7_4"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_8_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_8_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_8_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_8_4"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_9_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_9_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_9_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_9_4"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_10_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_10_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_10_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_10_4"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_11_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_11_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_11_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_11_4"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_12_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_12_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_12_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_12_4"]);?></td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>