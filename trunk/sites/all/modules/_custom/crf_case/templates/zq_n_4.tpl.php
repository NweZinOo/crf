<?php
  $key_pre = "e_{$table}";
?>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="8"><h2><?php print $table_name?></h2> <div><?php print drupal_render($form[$key_pre ."_1_1"]);?></div>
      <br/><div>仅记录第<?php print $no_1;?>周期中针对化疗过程采取的预防措施和针对不良反应采用的所有治疗</div>
    </td>
  </tr>
  <tr>
    <td>药品通用名</td>
    <td>用法</td>
    <td>给药途径</td>
    <td>治疗类别<br/>针对化疗预防<br/>/针对不良反应</td>
    <td>适应症</td>
    <td>开始日期</td>
    <td>结束日期</td>
    <td>继续</td>    
  </tr>
  <?php
  for($i=2;$i<=11;$i++) {
    print "<tr>";
      print "<td>". drupal_render($form[$key_pre ."_{$i}_1"]) ."</td>";
      print "<td>". drupal_render($form[$key_pre ."_{$i}_2"]) ."</td>";
      print "<td>". drupal_render($form[$key_pre ."_{$i}_3"]) ."</td>";
      print "<td>". drupal_render($form[$key_pre ."_{$i}_4"]) ."</td>";
      print "<td>". drupal_render($form[$key_pre ."_{$i}_5"]) ."</td>";
      print "<td>". drupal_render($form[$key_pre ."_{$i}_6"]) ."</td>";
      print "<td>". drupal_render($form[$key_pre ."_{$i}_7"]) ."</td>";
      print "<td>". drupal_render($form[$key_pre ."_{$i}_8"]) ."</td>";
    print "</tr>";
  }
  ?>
</table>
<table>
<tr><td>
<?php
if(arg(1) == 'zq8_4' || arg(1) == 'zq12_4' || arg(1) == 'zq16_4') {
?>
<u><i>请进行疗效与安全性评估，并完成《临床评估》表。</i></u>
<?php
}
?>
</td></tr>
</table>
<?php
  print drupal_render($form);
?>