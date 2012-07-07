<?php
  $key_pre = "e_{$table}";
?>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="4"><h2><?php print $table_name?></h2> <div><?php print drupal_render($form[$key_pre ."_1_1"]);?></div>
    </td>
  </tr>
  <tr>
    <td width="25%"><b>项目</b></td>
    <td width="20%"><b>结果</b></td>
    <td width="30%"><b>单位</b></td>
    <td width="25%"><b>取样日期</b></td>
  </tr>
  <tr>
    <td>血清CEA<br/><?php print drupal_render($form[$key_pre ."_2_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_3"]);?>，<?php print drupal_render($form[$key_pre ."_2_4"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_5"]);?></td>    
  </tr>
  <tr>
    <td>血清CA19-9<br/><?php print drupal_render($form[$key_pre ."_3_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_3_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_3_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_3_4"]);?></td>    
  </tr>
  <tr>
    <td>血清CA724<br/><?php print drupal_render($form[$key_pre ."_4_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_4_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_4_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_4_4"]);?></td>    
  </tr>
</table>
<?php
  print drupal_render($form);
?>