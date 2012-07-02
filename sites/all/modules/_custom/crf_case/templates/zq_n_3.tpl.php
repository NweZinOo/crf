<?php
  $key_pre = "e_{$table}";
?>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title"><h2><?php print $table_name?></h2>
    </td>
  </tr>
  <tr>
    <td><b>第<?php print $no_1?>周期S-1给药记录：</b></td>
  </tr>
  <tr>
    <td>实际给药总量为：<?php print drupal_render($form[$key_pre ."_1_1"]);?>mg;   剂量强度为：<?php print drupal_render($form[$key_pre ."_1_2"]);?></td>
  </tr>
  <tr>
    <td>是否发生减量/或延迟给药？<?php print drupal_render($form[$key_pre ."_2_1"]);?>，原因为：<?php print drupal_render($form[$key_pre ."_2_2"]);?></td>
  </tr>  
  <tr>
    <td><b>第<?php print $no_2?>周期S-1给药计划：</b></td>
  </tr>
  <tr>
    <td>给药日期：<?php print drupal_render($form[$key_pre ."_3_1"]);?>至<?php print drupal_render($form[$key_pre ."_3_2"]);?></td>
  </tr>
  <tr>
    <td>计划剂量：<?php print drupal_render($form[$key_pre ."_4_1"]);?>mg/m2；计划总量：<?php print drupal_render($form[$key_pre ."_4_2"]);?>mg</td>
  </tr>  
</table>
<?php
  print drupal_render($form);
?>