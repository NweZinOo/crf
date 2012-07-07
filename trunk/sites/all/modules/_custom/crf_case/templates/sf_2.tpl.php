<?php
  $key_pre = "e_{$table}";
?>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title"><h2><?php print $table_name?></h2>
    </td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_1_1"]);?></td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>