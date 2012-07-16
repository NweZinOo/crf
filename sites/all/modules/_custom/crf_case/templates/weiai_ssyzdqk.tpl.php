<?php
  $key_pre = "e_{$table}";
?>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="2"><h2><?php print $table_name?></h2></td>
  </tr>
  <tr>
    <td width="30%">首次诊断日期</td>
    <td><?php print drupal_render($form[$key_pre ."_1_1"]);?></td>
  </tr>
  <tr>
    <td>手术日期</td>
    <td><?php print drupal_render($form[$key_pre ."_2_1"]);?></td>
  </tr>
  <tr>
    <td>术后肿瘤分期</td>
    <td>TNM：T<?php print drupal_render($form[$key_pre ."_3_1"]);?> N<?php print drupal_render($form[$key_pre ."_3_2"]);?> M<?php print drupal_render($form[$key_pre ."_3_3"]);?> <br/>
      AJCC：<?php print drupal_render($form[$key_pre ."_3_4"]);?>
    </td>
  </tr>
  <tr>
    <td>肿瘤的组织学分类</td>
    <td><?php print drupal_render($form[$key_pre ."_4_1"]);?>, <?php print drupal_render($form[$key_pre ."_4_2"]);?></td>
  </tr>
  <tr>
    <td>肿瘤原发部位</td>
    <td><?php print drupal_render($form[$key_pre ."_5_1"]);?>, <?php print drupal_render($form[$key_pre ."_5_2"]);?></td>
  </tr>
  <tr>
    <td>淋巴结转移情况</td>
    <td>
    送检淋巴结数量：<?php print drupal_render($form[$key_pre ."_6_1"]);?>个,其中第一站淋巴结<?php print drupal_render($form[$key_pre ."_6_2"]);?>个,第二站<?php print drupal_render($form[$key_pre ."_6_3"]);?>个。<br/>
    阳性淋巴结数量：<?php print drupal_render($form[$key_pre ."_6_4"]);?>个,其中第一站淋巴结<?php print drupal_render($form[$key_pre ."_6_5"]);?>个,第二站<?php print drupal_render($form[$key_pre ."_6_6"]);?>个。
    </td>
  </tr>
  <tr>
    <td>分子生物学检测（肿瘤组织）</td>
    <td>HER2：<br/>
        <div>IHC方法：<?php print drupal_render($form[$key_pre ."_7_1"]);?></div>
        <div>FISH方法：<?php print drupal_render($form[$key_pre ."_7_2"]);?></div>
        VEGF：<br/>
        <div class="f-left">检测方法：</div><?php print drupal_render($form[$key_pre ."_7_3"]);?>
        <div class="clear"></div>
        <div class="f-left">检测结果：</div><?php print drupal_render($form[$key_pre ."_7_4"]);?>
    </td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>