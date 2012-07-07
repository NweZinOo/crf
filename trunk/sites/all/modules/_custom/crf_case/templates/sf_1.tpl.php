<?php
  $key_pre = "e_{$table}";
?>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="2"><h2><?php print $table_name?></h2>
    </td>
  </tr>
  <tr>
    <td>随访日期</td>
    <td><?php print drupal_render($form[$key_pre ."_1_1"]);?></td>
  </tr>
  <tr>
    <td>随访方法</td>
    <td><?php print drupal_render($form[$key_pre ."_2_1"]);?></td>
  </tr>
  <tr>
    <td>患者状态<br/>（仅在一项上打×）</td>
    <td><?php print drupal_render($form[$key_pre ."_3_1"]);?></td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>