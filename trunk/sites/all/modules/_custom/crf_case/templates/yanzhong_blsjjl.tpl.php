<?php
  $key_pre = "e_{$table}";
?>
<div class="big-title"><?php print $table_name?></div>
<div><b>报告日期：</b><?php print drupal_render($form[$key_pre ."_1_1"]);?></div>
<div><b>报告来源：</b><?php print drupal_render($form[$key_pre ."_2_1"]);?><?php print drupal_render($form[$key_pre ."_2_2"]);?></div>
<div><b>单位名称：</b><?php print drupal_render($form[$key_pre ."_3_1"]);?><b>联系电话：</b><?php print drupal_render($form[$key_pre ."_3_2"]);?></div>
<div><b>联系地址：</b><?php print drupal_render($form[$key_pre ."_4_1"]);?><b>邮编：</b><?php print drupal_render($form[$key_pre ."_4_2"]);?></div>
<div><b>严重不良事件记录</b></div>
<table class="<?php print $class?>" border="1">
  <tr class='title'>
    <td class='title'><b>A．患者资料</b></td>
  </tr>
  <tr>
    <td><b>患者姓名：</b><?php print drupal_render($form[$key_pre ."_5_1"]);?><b>年龄</b>：<?php print drupal_render($form[$key_pre ."_5_2"]);?>岁  <b>性别</b>：<?php print drupal_render($form[$key_pre ."_5_3"]);?></td>
  </tr>
  <tr class='title'>
    <td><b>B．不良事件情况</b></td>
  </tr>
  <tr>
    <td><b>事件主要表现：<?php print drupal_render($form[$key_pre ."_6_1"]);?></b></td>
  </tr>
  <tr>
    <td><b>事件发生日期</b>：<?php print drupal_render($form[$key_pre ."_7_1"]);?></td>
  </tr>
  <tr>
    <td><b>事件发生场所：</b><br/><?php print drupal_render($form[$key_pre ."_8_1"]);?><?php print drupal_render($form[$key_pre ."_8_2"]);?></td>
  </tr>
  <tr>
    <td><b>事件后果</b></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_9_1"]);?><br/>死亡时间:<?php print drupal_render($form[$key_pre ."_9_2"]);?></td>
  </tr>
  <tr>
    <td><b>事件陈述：</b>(至少包括药物使用情况、出现的不良事件情况、对受害者影响、采取的治疗措施等情况)</td>
  </tr>
  <tr>
    <td><b>报告人：</b><?php print drupal_render($form[$key_pre ."_10_1"]);?><?php print drupal_render($form[$key_pre ."_10_2"]);?></td>
  </tr>
  <tr>
    <td><b>药物具体名称：</b><?php print drupal_render($form[$key_pre ."_11_1"]);?></td>
  </tr>
  <tr>
    <td><b>生产企业名称：</b><?php print drupal_render($form[$key_pre ."_12_1"]);?><b>型号规格：</b><?php print drupal_render($form[$key_pre ."_12_2"]);?><b>生产企业地址：</b><?php print drupal_render($form[$key_pre ."_12_3"]);?><br/>
      <b>产品编号：</b><?php print drupal_render($form[$key_pre ."_12_4"]);?><b>企业联系电话：</b><?php print drupal_render($form[$key_pre ."_12_5"]);?><b>产品批号：</b><?php print drupal_render($form[$key_pre ."_12_6"]);?></td>
  </tr>
  <tr>
    <td><b>有效期至：</b><?php print drupal_render($form[$key_pre ."_13_1"]);?><b>停用日期：</b><?php print drupal_render($form[$key_pre ."_13_2"]);?></td>
  </tr>
  <tr>
    <td><b>事件发生原因分析</b>：<?php print drupal_render($form[$key_pre ."_14_1"]);?></td>
  </tr>
  <tr>
    <td><b>事件处理情况：</b><?php print drupal_render($form[$key_pre ."_15_1"]);?></td>
  </tr>
  <tr>
    <td><b>事件报告状态：</b><br/><?php print drupal_render($form[$key_pre ."_16_1"]);?></td>
  </tr>
  <tr>
    <td><b>严重不良事件评价及与治疗药物关系</b><br/>
      <?php print drupal_render($form[$key_pre ."_17_1"]);?>
    </td>
  </tr>
</table>
<div>报告人签名：<?php print drupal_render($form[$key_pre ."_18_1"]);?>   日期：<?php print drupal_render($form[$key_pre ."_18_2"]);?></div>
<?php
  print drupal_render($form);
?>