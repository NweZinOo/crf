<?php
  $key_pre = "e_{$table}";
?>
<div align="center"><h2><b>死亡记录</b></h2></div>
<div><b>死亡日期:</b><?php print drupal_render($form[$key_pre ."_1_1"]);?></div>
<div><b>死亡原因:</b></div>
<table class="<?php print $class?>" border="1">
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_2_1"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_3_1"]);?><?php print drupal_render($form[$key_pre ."_3_2"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_4_1"]);?><?php print drupal_render($form[$key_pre ."_4_2"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_5_1"]);?><?php print drupal_render($form[$key_pre ."_5_2"]);?></td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>