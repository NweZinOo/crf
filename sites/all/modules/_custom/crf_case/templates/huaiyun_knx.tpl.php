<?php
  $key_pre = "e_{$table}";
?>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title"><h2><?php print $table_name?></h2><div>（仅适用于女性，首次给药前进行）</div>
    </td>
  </tr>
  <tr>
    <td>受试者是否进行尿妊娠试验？<?php print drupal_render($form[$key_pre ."_1_1"]);?><div class="i-block">，请说明：<?php print drupal_render($form[$key_pre ."_1_2"]);?></div></td>
  </tr>
  <tr>
    <td><b><i>育龄期妇女</i></b>，请在试验前48小时内完成尿妊娠试验检查，并且试验期间受试者必须采取充分的避孕措施。尿妊娠试验结果：<?php print drupal_render($form[$key_pre ."_2_1"]);?></td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>