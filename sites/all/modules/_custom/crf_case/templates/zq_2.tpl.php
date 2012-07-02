<?php
  $key_pre = "e_{$table}";
?>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="2"><h2><?php print $table_name?></h2> <div><?php print drupal_render($form[$key_pre ."_1_1"]);?></div>
    </td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_2_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_2"]);?><br/>主要原因是<?php print drupal_render($form[$key_pre ."_2_3"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_3_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_3_2"]);?><br/>主要原因是<?php print drupal_render($form[$key_pre ."_3_3"]);?></td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>