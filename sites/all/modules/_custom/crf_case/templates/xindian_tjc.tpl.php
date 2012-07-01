<?php
  $key_pre = "e_{$table}";
?>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title"><h2><?php print $table_name?></h2><div> 在首次给药前14天内进行</div>
    </td>
  </tr>
  <tr>
    <td>检查日期<?php print drupal_render($form[$key_pre ."_1_1"]);?></td>
  </tr>
  <tr>
    <td><div class="inline-block"><?php print drupal_render($form[$key_pre ."_2_1"]);?><div class="i-block">,请说明<?php print drupal_render($form[$key_pre ."_2_2"]);?></div></div></td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>