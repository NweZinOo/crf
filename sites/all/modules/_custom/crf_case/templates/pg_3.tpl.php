<?php
  $key_pre = "e_{$table}";
?>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="4"><h2><?php print $table_name?></h2> <div><?php print drupal_render($form[$key_pre ."_1_1"]);?></div>
    </td>
  </tr>
  <tr>
    <td width="25%"><b>方法</b><br/>(请选择：1＝CT；2＝MRI；3＝PET-CT；4＝X-Ray；5＝B超；6＝内镜；7＝组织学和/或细胞学检查。)</td>
    <td width="25%"><b>部位</b></td>
    <td width="25%"><b>结果描述/说明</b></td>
    <td width="25%"><b>日期</b></td>
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
</table>
<?php
  print drupal_render($form);
?>