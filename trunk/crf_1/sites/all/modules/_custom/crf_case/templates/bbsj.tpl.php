<?php
  $key_pre = "e_{$table}";
  $genders[0] = "男";
  $genders[1] = "女";
  $c_data = crf_ds_load('dyxx', $_SESSION['crf']['p_uid']);
  $c_data = json_to_array($c_data);
//  print_r($c_data);
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
送样单位样本号（<?php print drupal_render($form[$key_pre ."_1_1"]);?>）
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="6"><h2>一般资料</h2>
    </td>
  </tr>
  <tr>
    <td width="20%">姓名：
    </td>
    <td><?php print drupal_render($form[$key_pre ."_1_2"]);?>
    </td>
    <td>出生年月：
    </td>
    <td><?php print drupal_render($form[$key_pre ."_1_3"]);?>
    </td>
    <td>联系电话：
    </td>
    <td><?php print drupal_render($form[$key_pre ."_1_4"]);?>
    </td>
  </tr>
  <tr>
    <td>性别：
    </td>
    <td><?php print drupal_render($form[$key_pre ."_1_5"]);?>
    </td>
    <td>家庭住址：
    </td>
    <td><?php print drupal_render($form[$key_pre ."_1_6"]);?>
    </td>
    <td>身份证号码：
    </td>
    <td><?php print drupal_render($form[$key_pre ."_1_7"]);?>
    </td>
  </tr>
  <tr>
    <td>就诊医院：
    </td>
    <td><?php print drupal_render($form[$key_pre ."_1_8"]);?>
    </td>
    <td>就诊医生：
    </td>
    <td><?php print drupal_render($form[$key_pre ."_1_10"]);?>
    </td>
    <td>就诊日期：
    </td>
    <td><?php print substr($c_data[37][3], 0, 10)?>
    </td>
  </tr>
  <tr>
    <td>病人诊断：
    </td>
    <td><?php print drupal_render($form[$key_pre ."_2_1"]);?>
    </td>
    <td>WHO分型：
    </td>
    <td><?php print drupal_render($form[$key_pre ."_2_2"]);?>
    </td>
    <td>IPSS积分：
    </td>
    <td><?php print drupal_render($form[$key_pre ."_2_3"]);?>
    </td>
  </tr>
  <tr>
    <td>血常规（有无异常细胞）
    </td>
    <td colspan="5"><?php print drupal_render($form[$key_pre ."_3_1"]);?>
    </td>
  </tr>
  <tr>
    <td>骨髓涂片（增生度/粒红比，原始细胞百分比（红系>50%请去红计算），病态造血累计几系，主要形态特征
    </td>
    <td colspan="5"><?php print drupal_render($form[$key_pre ."_4_1"]);?>
    </td>
  </tr>
  <tr>
    <td>染色体G带
    </td>
    <td colspan="5"><?php print drupal_render($form[$key_pre ."_5_1"]);?>
    </td>
  </tr>
  <tr>
    <td>FISH结果
    </td>
    <td colspan="5"><?php print drupal_render($form[$key_pre ."_6_1"]);?>
    </td>
  </tr>
  <tr>
    <td>送检外周血（ml数/抗凝剂）
    </td>
    <td colspan="5"><?php print drupal_render($form[$key_pre ."_7_1"]);?>
    </td>
  </tr>
  <tr>
    <td>送检骨髓液（ml数/抗凝剂）
    </td>
    <td colspan="5"><?php print drupal_render($form[$key_pre ."_8_1"]);?>
    </td>
  </tr>
  <tr>
    <td>备注
    </td>
    <td colspan="5"><?php print drupal_render($form[$key_pre ."_9_1"]);?>
    </td>
  </tr>
</table>

<?php
  print drupal_render($form);
?>