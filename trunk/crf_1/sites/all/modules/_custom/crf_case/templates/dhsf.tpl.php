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
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="4"><h2>一般资料</h2>
    </td>
  </tr>
  <tr>
    <td>患者姓名：<?php print $c_data[1][1]?>
    </td>
    <td>年龄(岁)：<?php print $c_data[1][3]?>
    </td>
    <td>电话：<?php print $c_data[2][2]?>
    </td>
  </tr>
  <tr>
    <td colspan="2">诊断：<?php print drupal_render($form[$key_pre ."_1_1"]);?>
    </td>
    <td>电话随访时间：<?php print drupal_render($form[$key_pre ."_1_2"]);?>
    </td>
  </tr>
</table>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="7"><h2>上次就诊记录</h2>
    </td>
  </tr>
  <tr>
    <td colspan="7">就诊日期:<?php print drupal_render($form[$key_pre ."_2_1"]);?><br/>
      治疗：
      1.输血：<?php print drupal_render($form[$key_pre ."_3_1"]);?>U<br/>
      2.医生处方药物：(列出主要药品即可)<br/>
    </td>
  </tr>
  <tr>
    <td>药物名称
    </td>
    <td colspan="2" width="30%">取药情况
    </td>
    <td colspan="2" width="30%">遵医嘱服药情况
    </td>
    <td colspan="2" width="30%">有无不适，有请详述
    </td>
  </tr>
  
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_4_1"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_4_2"]);?><?php print drupal_render($form[$key_pre ."_4_3"]);?>
    </td>
    <td>原因：<?php print drupal_render($form[$key_pre ."_4_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_4_5"]);?><?php print drupal_render($form[$key_pre ."_4_6"]);?>
    </td>
    <td>原因：<?php print drupal_render($form[$key_pre ."_4_7"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_4_8"]);?><?php print drupal_render($form[$key_pre ."_4_9"]);?>
    </td>
    <td>详述：<?php print drupal_render($form[$key_pre ."_4_10"]);?>
    </td>
  </tr>

  <tr>
    <td><?php print drupal_render($form[$key_pre ."_5_1"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_5_2"]);?><?php print drupal_render($form[$key_pre ."_5_3"]);?>
    </td>
    <td>原因：<?php print drupal_render($form[$key_pre ."_5_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_5_5"]);?><?php print drupal_render($form[$key_pre ."_5_6"]);?>
    </td>
    <td>原因：<?php print drupal_render($form[$key_pre ."_5_7"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_5_8"]);?><?php print drupal_render($form[$key_pre ."_5_9"]);?>
    </td>
    <td>详述：<?php print drupal_render($form[$key_pre ."_5_10"]);?>
    </td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_6_1"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_6_2"]);?><?php print drupal_render($form[$key_pre ."_6_3"]);?>
    </td>
    <td>原因：<?php print drupal_render($form[$key_pre ."_6_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_6_5"]);?><?php print drupal_render($form[$key_pre ."_6_6"]);?>
    </td>
    <td>原因：<?php print drupal_render($form[$key_pre ."_6_7"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_6_8"]);?><?php print drupal_render($form[$key_pre ."_6_9"]);?>
    </td>
    <td>详述：<?php print drupal_render($form[$key_pre ."_6_10"]);?>
    </td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_7_1"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_7_2"]);?><?php print drupal_render($form[$key_pre ."_7_3"]);?>
    </td>
    <td>原因：<?php print drupal_render($form[$key_pre ."_7_4"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_7_5"]);?><?php print drupal_render($form[$key_pre ."_7_6"]);?>
    </td>
    <td>原因：<?php print drupal_render($form[$key_pre ."_7_7"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_7_8"]);?><?php print drupal_render($form[$key_pre ."_7_9"]);?>
    </td>
    <td>详述：<?php print drupal_render($form[$key_pre ."_7_10"]);?>
    </td>
  </tr>
</table>

<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td colspan="3"><h2>近期情况</h2>
    </td>
  </tr>
  <tr>
    <td colspan="3">有无不适症状：<?php print drupal_render($form[$key_pre ."_8_1"]);?>
    </td>
  </tr>
  <tr>
    <td>症状
    </td>
    <td>出现时间
    </td>
    <td>处理和转归
    </td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_9_1"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_9_2"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_9_3"]);?>
    </td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_10_1"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_10_2"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_10_3"]);?>
    </td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_11_1"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_11_2"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_11_3"]);?>
    </td>
  </tr>
</table>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td colspan="3"><h2>下次复诊</h2>
    </td>
  </tr>
  <tr>
    <td>
    
      预计复诊时间：<?php print drupal_render($form[$key_pre ."_12_1"]);?><br/>
      （如果预计复诊时间超过了一个月，需询问推迟复诊的原因）<br/>
      <?php print drupal_render($form[$key_pre ."_13_1"]);?><br/>
      复诊医院：<?php print drupal_render($form[$key_pre ."_14_1"]);?>；<br/>
      是否需要协助预约门诊：<?php print drupal_render($form[$key_pre ."_15_1"]);?> 是：主任名字<?php print drupal_render($form[$key_pre ."_15_2"]);?>，时间<?php print drupal_render($form[$key_pre ."_15_3"]);?><br/>

    </td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>