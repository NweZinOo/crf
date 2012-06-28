<?php
  $key_pre = "e_{$table}";
?>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="3"><h2><?php print $table_name?></h2><?php print drupal_render($form[$key_pre ."_1_1"]);?><br/>
    (除研究的疾病外，患者目前或12个月内是否患有任何有临床意义或接受治疗的疾病)
    </td>
  </tr>
  <tr>
    <td width="30%">医学事件/疾病</td>
    <td>入组时仍存在<?php print drupal_render($form[$key_pre ."_1_1"]);?></td>
    <td>诊断日期<?php print drupal_render($form[$key_pre ."_1_1"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_2_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_3"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_3_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_3_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_3_3"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_4_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_4_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_4_3"]);?></td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>