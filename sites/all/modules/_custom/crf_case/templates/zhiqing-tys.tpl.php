<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="2"><h2>知情同意书</h2></td>
  </tr>
  <tr>
    <td><h4>获得日期</h4></td>
    <td><?php print drupal_render($form['e_zhiqing_tys_1_1']);?></td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>