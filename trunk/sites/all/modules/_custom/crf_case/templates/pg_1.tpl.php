<?php
  $key_pre = "e_{$table}";
?>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="4"><h2><?php print $table_name?></h2>
    </td>
  </tr>
  <tr>
    <td>检查日期</td>
    <td colspan="3"><?php print drupal_render($form[$key_pre ."_1_1"]);?></td>
  </tr>
  <tr>
    <td>体重</td>
    <td><?php print drupal_render($form[$key_pre ."_2_1"]);?>kg</td>
    <td>ECOG PS评分</td>
    <td><?php print drupal_render($form[$key_pre ."_2_2"]);?>分</td>
  </tr>
  <tr>
    <td>过去3月内体重减轻</td>
    <td><?php print drupal_render($form[$key_pre ."_3_1"]);?>%</td>
    <td>血压</td>
    <td><?php print drupal_render($form[$key_pre ."_3_2"]);?>/<?php print drupal_render($form[$key_pre ."_3_3"]);?>mmHg</td>
  </tr>
  <tr>
    <td>生命体征</td>
    <td colspan="3"><?php print drupal_render($form[$key_pre ."_4_1"]);?>，请说明：<?php print drupal_render($form[$key_pre ."_4_2"]);?></td>
  </tr>
  <tr>
    <td>体格检查</td>
    <td colspan="3"><?php print drupal_render($form[$key_pre ."_5_1"]);?>，请说明：<?php print drupal_render($form[$key_pre ."_5_2"]);?></td>
  </tr>
  <tr>
    <td>食欲</td>
    <td colspan="3"><?php print drupal_render($form[$key_pre ."_6_1"]);?></td>
  </tr>
  <tr>
    <td>神经系统检查</td>
    <td colspan="3"><?php print drupal_render($form[$key_pre ."_7_1"]);?>，请说明：<?php print drupal_render($form[$key_pre ."_7_2"]);?></td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>