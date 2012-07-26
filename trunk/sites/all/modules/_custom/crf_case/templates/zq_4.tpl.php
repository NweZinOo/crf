<?php
  $key_pre = "e_{$table}";
?>
<table class="<?php print $class?>" border="1">
  <tr>
    <td rowspan="2">研究药物</td>
    <td colspan="2"><?php print $no_1;?></td>
    <td colspan="3"><?php print $no_2;?></td>
  </tr>
  <tr>
    <td>实际总量<br/>（mg）</td>
    <td>剂量<br/>强度</td>
    <td>给药日期</td>
    <td width="10%">计划剂量<br/>(mg)</td>
    <td>计划总量<br/>(mg)</td>
  </tr>
  <tr>
    <td>S-1</td>
    <td><?php print drupal_render($form[$key_pre ."_1_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_1_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_1_3"]);?><br/>至<br/><?php print drupal_render($form[$key_pre ."_1_4"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_1_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_1_6"]);?></td>
  </tr>
  <tr class="clear-alert">
    <td>奥沙利铂<?php print drupal_render($form[$key_pre ."_2_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_4"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_5"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_6"]);?></td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>