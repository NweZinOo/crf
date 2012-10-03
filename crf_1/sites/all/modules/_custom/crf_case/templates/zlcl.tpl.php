<?php
  $key_pre = "e_{$table}";
  $genders[0] = "男";
  $genders[1] = "女";
//  print_r($_SESSION);
?>
<?php //print_r($hospital_name_arr);?>
<table border="3">
  <tr>
    <td>&quot;中国慢性输血患者铁过载现状调研&quot;数据收集表</td>
    <td rowspan="2"><div align="center">筛选</div></td>
  </tr>
  <tr>
    <td>医院名称: 
      <?php 
        global $user;
        print($hospital_name_arr[$user->profile_hospital_no]);
      ?>
    </td>
  </tr>
</table>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="4"><h2>整体治疗策略（可多选）</h2>
    </td>
  </tr>
  <tr>
    <td>MDS：<br/>
      <?php print drupal_render($form[$key_pre ."_1_1"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_2_1"]);?>
      <?php print drupal_render($form[$key_pre ."_2_2"]);?>
      <?php print drupal_render($form[$key_pre ."_2_3"]);?>
      <?php print drupal_render($form[$key_pre ."_2_4"]);?>
      <?php print drupal_render($form[$key_pre ."_2_5"]);?><br/>
      <?php print drupal_render($form[$key_pre ."_3_1"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_4_1"]);?>
      <?php print drupal_render($form[$key_pre ."_4_2"]);?>
      <?php print drupal_render($form[$key_pre ."_4_3"]);?>
      <?php print drupal_render($form[$key_pre ."_4_4"]);?>,<?php print drupal_render($form[$key_pre ."_4_5"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_5_1"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_6_1"]);?>
      <?php print drupal_render($form[$key_pre ."_6_2"]);?>
      <?php print drupal_render($form[$key_pre ."_6_3"]);?>
      <?php print drupal_render($form[$key_pre ."_6_4"]);?>,<?php print drupal_render($form[$key_pre ."_6_5"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_7_1"]);?>
      <?php print drupal_render($form[$key_pre ."_7_2"]);?>
      <?php print drupal_render($form[$key_pre ."_7_3"]);?>,<?php print drupal_render($form[$key_pre ."_7_4"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_8_1"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_9_1"]);?>,<?php print drupal_render($form[$key_pre ."_9_2"]);?><br/>
    </td>
  </tr>
  <tr>
    <td>AA：<br/>
      <?php print drupal_render($form[$key_pre ."_10_1"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_11_1"]);?>
      <?php print drupal_render($form[$key_pre ."_11_2"]);?>
      <?php print drupal_render($form[$key_pre ."_11_3"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_12_1"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_13_1"]);?><?php print drupal_render($form[$key_pre ."_13_2"]);?>
    </td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>