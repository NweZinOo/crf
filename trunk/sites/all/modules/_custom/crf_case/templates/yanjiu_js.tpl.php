<?php
  $key_pre = "e_{$table}";
?>
<div align="center"><h2><b>研究结束</b></h2></div>
<div><b>研究结束日期:</b><?php print drupal_render($form[$key_pre ."_1_1"]);?></div>
<div><b>研究结束原因:</b></div>
<table class="<?php print $class?>" border="1">
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_2_1"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_3_1"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_4_1"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_5_1"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_6_1"]);?><?php print drupal_render($form[$key_pre ."_6_2"]);?></td>
  </tr>
</table>
<div><b>我证实：</b></div>
<div>由我签名的这份患者病例报告表的各项内容已由我检查，并确认所有的信息是真实、准确的，符合研究方案的要求。</div>
<div align="right">研究者签名：<?php print drupal_render($form[$key_pre ."_7_1"]);?></div>
<div align="right">签名日期：<?php print drupal_render($form[$key_pre ."_8_1"]);?></div>
<?php
  print drupal_render($form);
?>