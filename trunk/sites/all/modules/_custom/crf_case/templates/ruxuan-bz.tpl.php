<?php
//  print_r($form);
?>
<table border="1" class="<?php print $class?>">
  <tr class="title">
    <td><h2>入选标准</h2></td>
	<td>是/否</td>
  </tr>
  <tr>
    <td width="80%">1.患者本人签署知情同意书</td><td><?php print drupal_render($form['e_ruxuan_bz_1_1']);?></td>
  </tr>
  <tr>
    <td>2.组织学证实的II期、Ⅲ期进展期胃癌患者</td><td><?php print drupal_render($form['e_ruxuan_bz_2_1']);?></td>
  </tr>
  <tr>
    <td>3.已接受D2淋巴结清除的R0切除术（无残余肿瘤）</td><td><?php print drupal_render($form['e_ruxuan_bz_3_1']);?></td>
  </tr>
  <tr>
    <td>4.无肝脏、腹膜或远处转移</td><td><?php print drupal_render($form['e_ruxuan_bz_4_1']);?></td>
  </tr>
    <td>5.细胞学检查在腹水中未发现肿瘤细胞</td><td><?php print drupal_render($form['e_ruxuan_bz_5_1']);?></td>
  </tr>
  <tr>
    <td>6.ECOG评分0-2分</td><td><?php print drupal_render($form['e_ruxuan_bz_6_1']);?></td>
  </tr>
  <tr>
    <td>7.年龄18-70岁</td><td><?php print drupal_render($form['e_ruxuan_bz_7_1']);?></td>
  </tr>
  <tr>
    <td>8.除原发性胃癌初治时的胃切除外，既往无癌症治疗</td><td><?php print drupal_render($form['e_ruxuan_bz_8_1']);?></td>
  </tr>
  <tr>
    <td>9.入组前血流动力学指标（包括血细胞计数、肝肾功能）正常。如WBC&gt;4.0×109/L，血小板&gt;100×109/L，胆红素&lt;1.5倍正常参考值上限，谷草转氨酶和谷丙转氨酶肌酐&lt;2.5倍正常参考值上限</td><td><?php print drupal_render($form['e_ruxuan_bz_9_1']);?></td>
  </tr>
  <tr>
    <td>10.入组前心脏功能良好，半年内无心脑血管意外发作，高血压、冠心病等目前在可控制范围内</td><td><?php print drupal_render($form['e_ruxuan_bz_10_1']);?></td>
  </tr>
  <tr>
    <td>11.入组前不伴有其他不可控制的良性疾病如肺部、肾脏、肝脏疾病及感染等</td><td><?php print drupal_render($form['e_ruxuan_bz_11_1']);?></td>
  </tr>
  <tr>
    <td>12.治疗前及治疗过程中未参加其他研究项目</td><td><?php print drupal_render($form['e_ruxuan_bz_12_1']);?></td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>