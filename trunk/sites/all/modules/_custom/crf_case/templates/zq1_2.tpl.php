<?php
  $key_pre = "e_{$table}";
?>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="8"><h2><?php print $table_name?></h2> <div>仅记录该周期中针对化疗过程采取的预防措施和针对不良反应采用的所有治疗</div>
    </td>
  </tr>
  <tr>
    <td>药品通用名</td>
    <td>给药日期</td>
    <td>计划剂量<br/>(mg/m2)</td>
    <td>总给药剂量(mg)</td>
    <td>研究药物</td>
    <td>给药日期</td>
    <td>计划剂量<br/>(mg/m2)</td>
    <td>总给药剂量(mg)</td>    
  </tr>
  <tr>
    <td>S-1</td>
    <td><?php print drupal_render($form[$key_pre ."_1_1"]);?>至<?php print drupal_render($form[$key_pre ."_1_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_1_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_1_4"]);?></td>
  </tr>
  <tr>
    <td>奥沙利铂<?php print drupal_render($form[$key_pre ."_2_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_4"]);?></td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>
