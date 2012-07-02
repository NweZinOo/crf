<?php
  $key_pre = "e_{$table}";
?>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="5"><h2><?php print $table_name?></h2> <div><?php print drupal_render($form[$key_pre ."_1_1"]);?></div> <br/>
      如果本周期检测了肿瘤标记物，请填写P46《标记物检测汇总表》
    </td>
  </tr>
  <tr>
    <td><b>参数</b></td>
    <td><b>数值</b></td>
    <td><b>单位</b></td>
    <td><b>是否有<br/>临床意义？</b></td>
    <td><b>取样日期<br/>（年/月/日）</b></td>
  </tr>
  <tr>
    <td>中性粒细胞计数</td>
    <td><?php print drupal_render($form[$key_pre ."_2_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_4"]);?></td>
  </tr>
  <tr>
    <td>血小板计数</td>
    <td><?php print drupal_render($form[$key_pre ."_3_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_3_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_3_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_3_4"]);?></td>
  </tr>
  <tr>
    <td>血肌酐清除率</td>
    <td><?php print drupal_render($form[$key_pre ."_4_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_4_2"]);?><?php print drupal_render($form[$key_pre ."_4_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_4_4"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_4_5"]);?></td>
  </tr>
  <tr>
    <td>其它，<?php print drupal_render($form[$key_pre ."_5_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_5_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_5_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_5_4"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_5_5"]);?></td>
  </tr>
  <tr>
    <td>其它，<?php print drupal_render($form[$key_pre ."_6_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_6_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_6_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_6_4"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_6_5"]);?></td>
  </tr>
  <tr>
    <td>其它，<?php print drupal_render($form[$key_pre ."_7_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_7_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_7_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_7_4"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_7_5"]);?></td>
  </tr>
  <tr>
    <td colspan="5" align="center"><b><i>如有临床意义,请完成上一页的不良事件表</i></b></td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>