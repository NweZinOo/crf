<?php
//  print_r($form);
?>
<table border="1" class="<?php print $class?>">
  <tr class="title">
    <td colspan='4'><h2><?php print $table_name?></h2></td>
  </tr>
  <tr>
    <td width="20%" class='center'>出生日期</td>
    <td width="30%"><?php print drupal_render($form['e_renkou_tjx_1_1']);?></td>
    <td width="20%" class='center'>性别</td>
    <td width="30%"><?php print drupal_render($form['e_renkou_tjx_1_2']);?></td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>