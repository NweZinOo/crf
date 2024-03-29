<?php
  $key_pre = "e_{$table}";
?>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="4"><h2><?php print $table_name?></h2>
    </td>
  </tr>
  <tr>
    <td>研究药物</td>
    <td>给药日期</td>
    <td>计划剂量<br/>(mg)</td>
    <td>总给药剂量(mg)</td>
  </tr>
  <tr class="calculate">
    <td>S-1</td>
    <td class="date-select"><?php print drupal_render($form[$key_pre ."_1_1"]);?>至<?php print drupal_render($form[$key_pre ."_1_2"]);?></td>
    <td class="unit"><?php print drupal_render($form[$key_pre ."_1_3"]);?></td>
    <td class="total"><?php print drupal_render($form[$key_pre ."_1_4"]);?></td>
  </tr>
  <tr class="clear-alert">
    <td>奥沙利铂<?php print drupal_render($form[$key_pre ."_2_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_4"]);?></td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>
