<?php
//  print_r($form);
?>
<table border="1" class="<?php print $class?>">
  <tr class="title">
    <td><h2><?php print $table_name?></h2></td>
	<td>是/否</td>
  </tr>
  <tr>
    <td width="80%">1.不符合上述入选标准</td><td><?php print drupal_render($form['e_paichu_bz_1_1']);?></td>
  </tr>
  <tr>
    <td>2.入组前已经进行了其他药物治疗（包含中药）或入组后无法保证按照研究要求进行者</td><td><?php print drupal_render($form['e_paichu_bz_2_1']);?></td>
  </tr>
  <tr>
    <td>3.对本方案药物过敏</td><td><?php print drupal_render($form['e_paichu_bz_3_1']);?></td>
  </tr>
  <tr>
    <td>4.妊娠或哺乳期妇女</td><td><?php print drupal_render($form['e_paichu_bz_4_1']);?></td>
  </tr>
    <td>5.女性育龄患者，研究期间有生育要求者</td><td><?php print drupal_render($form['e_paichu_bz_5_1']);?></td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>