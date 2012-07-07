<?php
  $key_pre = "e_{$table}";
?>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="4"><h2><?php print $table_name?></h2> <div><?php print drupal_render($form[$key_pre ."_1_1"]);?></div>
    </td>
  </tr>
  <tr>
    <td>检查日期</td>
    <td><?php print drupal_render($form[$key_pre ."_2_1"]);?></td>
  </tr>
  <tr>
    <td>检查结果</td>
    <td><?php print drupal_render($form[$key_pre ."_3_1"]);?>，请说明<?php print drupal_render($form[$key_pre ."_3_2"]);?></td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>