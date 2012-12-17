<?php
  $key_pre = "e_{$table}";
  $genders[0] = "男";
  $genders[1] = "女";
//  print_r($_SESSION);
?>
<?php //print_r($hospital_name_arr);?>
<?php //print_r($user);?>
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
    <td><b>患者姓名</b>：<?php print drupal_render($form[$key_pre ."_1_1"]);?>
    </td>
    <td><b>年龄(岁)</b>：<?php print drupal_render($form[$key_pre ."_1_2"]);?>
    </td>
    <td><b>生日</b>：<?php print drupal_render($form[$key_pre ."_1_3"]);?>
    </td>
    <td><b>性别</b>：<?php print drupal_render($form[$key_pre ."_1_4"]);?>
    </td>
  </tr>
  <tr>
    <td colspan="2"><b>家庭住址</b>：<?php print drupal_render($form[$key_pre ."_2_1"]);?>
    </td>
    <td colspan="2"><b>联系电话</b>：<?php print drupal_render($form[$key_pre ."_2_2"]);?>
    </td>
  </tr>
  <tr>
    <td colspan="2"><b>身份证号码</b>：<?php print drupal_render($form[$key_pre ."_3_1"]);?>
    </td>
    <td colspan="2"><b>体重(kg)</b>：<?php print drupal_render($form[$key_pre ."_3_2"]);?>
    </td>
  </tr>
  <tr>
    <td>就诊医院：<?php print drupal_render($form[$key_pre ."_37_1"]);?>
    </td>
    <td>就诊医生：<?php print drupal_render($form[$key_pre ."_37_2"]);?>
    </td>
    <td>就诊日期：<?php print drupal_render($form[$key_pre ."_37_3"]);?>
    </td>
    <td>IPSS积分：<?php print drupal_render($form[$key_pre ."_37_4"]);?>
    </td>
  </tr>
</table>
<table>
  <tr>
    <td>
      <b>是否接受统一随访</b>: <?php print drupal_render($form[$key_pre ."_35_1"]);?>
    </td>
  </tr>
</table>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="2"><h2>基础疾病诊断信息</h2>(可多选)
    </td>
  </tr>
  <tr>
    <td colspan="2">诊断日期：<?php print drupal_render($form[$key_pre ."_4_1"]);?>
    </td>
  </tr>
  <tr>
    <td colspan="2">诊断为：<br/>
      <?php print drupal_render($form[$key_pre ."_5_1"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_6_1"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_6_2"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_6_3"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_6_4"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_6_5"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_6_6"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_6_7"]);?><br/>
      <?php print drupal_render($form[$key_pre ."_7_1"]);?><br/>
      <?php print drupal_render($form[$key_pre ."_7_2"]);?><br/>
      <?php print drupal_render($form[$key_pre ."_8_1"]);?><br/>
      <?php print drupal_render($form[$key_pre ."_8_2"]);?> 请详述<?php print drupal_render($form[$key_pre ."_8_3"]);?>
    </td>
  </tr>
  <tr>
    <td colspan="2">WPSS 评分：<?php print drupal_render($form[$key_pre ."_9_1"]);?><?php print drupal_render($form[$key_pre ."_9_2"]);?>
    </td>
  </tr>
  <tr>
    <td colspan="2">骨髓涂片（增生度/粒红比，原始细胞百分比（红系>50%请去红计算），病态造血累计几系，主要形态特征:<br/>
      <?php print drupal_render($form[$key_pre ."_39_1"]);?>
    </td>
  </tr>
  <tr>
    <td colspan="2">骨髓穿刺结果（铁染色+活检）<br/>
      日期：<?php print drupal_render($form[$key_pre ."_10_1"]);?>(选填项)<br/>
      结果：<?php print drupal_render($form[$key_pre ."_11_1"]);?>
    </td>
  </tr>
  <tr>
    <td colspan="2">染色体检查结果<br/>
      日期：<?php print drupal_render($form[$key_pre ."_12_1"]);?>(选填项)<br/>
      结果:<?php print drupal_render($form[$key_pre ."_13_1"]);?>
    </td>
  </tr>
  <tr>
    <td colspan="2">基因检测结果<br/>
      日期：<?php print drupal_render($form[$key_pre ."_14_1"]);?>(选填项)<br/>
      结果：<?php print drupal_render($form[$key_pre ."_15_1"]);?>
    </td>
  </tr>
  <tr>
    <td colspan="2">染色体G带:<?php print drupal_render($form[$key_pre ."_42_1"]);?>
    </td>
  </tr>
  <tr>
    <td>FISH结果:<?php print drupal_render($form[$key_pre ."_42_2"]);?>
    </td>
    <td>EPO（稀释定量）：<?php print drupal_render($form[$key_pre ."_42_5"]);?>
    </td>
  </tr>
    <tr>
    <td colspan="2">既往去铁史:<?php print drupal_render($form[$key_pre ."_42_13"]);?>，&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_42_15"]);?><?php print drupal_render($form[$key_pre ."_42_16"]);?>&nbsp;&nbsp;时间<?php print drupal_render($form[$key_pre ."_42_17"]);?><?php print drupal_render($form[$key_pre ."_42_18"]);?>
    </td>
  </tr>
    </tr>
    <tr>
    <td colspan="2">其他肿瘤史:<?php print drupal_render($form[$key_pre ."_42_14"]);?>，&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_42_19"]);?>&nbsp;&nbsp;请详述<?php print drupal_render($form[$key_pre ."_42_20"]);?>&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_42_21"]);?>
    </td>
  </tr>
</table>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="3"><h2>输血治疗史</h2><?php print drupal_render($form[$key_pre ."_16_1"]);?>, 有则需填写以下内容：
    </td>
  </tr>
  <tr>
    <td>输血治疗的开始日期：<?php print drupal_render($form[$key_pre ."_17_1"]);?><br/>
      既往RBC输注总量为：<?php print drupal_render($form[$key_pre ."_18_1"]);?>U(1U=200ml)
    </td>
  </tr>
</table>

<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="3"><h2>铁过载主要实验室检查结果</h2>
    </td>
  </tr>
  <tr>
    <td colspan="3"><b>血铁五项</b>（推荐连续测两次）
    </td>
  </tr>
  <tr>
    <td>取样日期
    </td>
    <td><?php print drupal_render($form[$key_pre ."_19_1"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_19_2"]);?>
    </td>
  </tr>
  <tr>
    <td>血清铁蛋白(SF)
    </td>
    <td><?php print drupal_render($form[$key_pre ."_20_1"]);?>ug/L
    </td>
    <td><?php print drupal_render($form[$key_pre ."_20_2"]);?>ug/L
    </td>
  </tr>
  <tr>
    <td>转铁蛋白饱和度(%)
    </td>
    <td><?php print drupal_render($form[$key_pre ."_21_1"]);?>
    </td>
    <td><?php print drupal_render($form[$key_pre ."_21_2"]);?>
    </td>
  </tr>
  <tr>
    <td>总铁结合力
    </td>
    <td><?php print drupal_render($form[$key_pre ."_22_1"]);?>umol/L
    </td>
    <td><?php print drupal_render($form[$key_pre ."_22_2"]);?>umol/L
    </td>
  </tr>
  <tr>
    <td colspan="3">血清叶酸B12:<?php print drupal_render($form[$key_pre ."_22_3"]);?>
    </td>
  </tr>
  <tr>
    <td colspan="3">LPI:<?php print drupal_render($form[$key_pre ."_22_4"]);?>
    </td>
  </tr>
  <tr>
    <td colspan="3">Hepcidine:<?php print drupal_render($form[$key_pre ."_22_5"]);?>
    </td>
  </tr>
  <tr>
    <td colspan="3"><b>血常规</b>   取样日期:<?php print drupal_render($form[$key_pre ."_23_1"]);?>&nbsp;&nbsp;有无异常细胞<?php print drupal_render($form[$key_pre ."_23_2"]);?>
    </td>
  </tr>
  <tr>
    <td colspan="3">Hb：<?php print drupal_render($form[$key_pre ."_24_1"]);?>g/L； WBC：<?php print drupal_render($form[$key_pre ."_24_2"]);?>×10<sup>9</sup>/L； ANC：<?php print drupal_render($form[$key_pre ."_24_3"]);?>×10<sup>9</sup>/L；<br/>PLT：<?php print drupal_render($form[$key_pre ."_24_4"]);?>×10<sup>9</sup>/L；Ret%<?php print drupal_render($form[$key_pre ."_24_5"]);?>  
    </td>
  </tr>
  
  <tr>
    <td colspan="3"><b>血生化</b> 请填写有临床意义的异常结果 	取样日期：<?php print drupal_render($form[$key_pre ."_25_1"]);?>
    </td>
  </tr>
  <tr>
    <td>肝功能：<?php print drupal_render($form[$key_pre ."_26_1"]);?></td><td colspan="2">如有异常请填写：<br/>谷草转氨酶(SGOT)：<?php print drupal_render($form[$key_pre ."_26_2"]);?>U/L；谷丙转氨酶(SGPT)：<?php print drupal_render($form[$key_pre ."_26_3"]);?>U/L
    </td>
  </tr>
  <tr>
    <td>乙肝两对半：<?php print drupal_render($form[$key_pre ."_43_1"]);?></td><td colspan="2">如有异常请详述：<?php print drupal_render($form[$key_pre ."_43_2"]);?>
    </td>
  </tr>
  <tr>
    <td>肾功能：<?php print drupal_render($form[$key_pre ."_44_1"]);?></td><td colspan="2">如有异常请详述：<?php print drupal_render($form[$key_pre ."_44_2"]);?>
    </td>
  </tr>
  <tr>
    <td>肌酐：<?php print drupal_render($form[$key_pre ."_45_1"]);?></td><td colspan="2">如有异常请详述：<?php print drupal_render($form[$key_pre ."_45_2"]);?>umol/L
    </td>
  </tr>
  <tr>
    <td>尿素氮：<?php print drupal_render($form[$key_pre ."_46_1"]);?></td><td colspan="2">如有异常请详述：<?php print drupal_render($form[$key_pre ."_46_2"]);?>mmol/L
    </td>
  </tr>
  <tr>
    <td><b>血糖</b>：<?php print drupal_render($form[$key_pre ."_27_1"]);?></td><td colspan="2">如有异常请填写：<br/>空腹血糖(FBS)：<?php print drupal_render($form[$key_pre ."_27_2"]);?>mmol/L；餐后两小时血糖：<?php print drupal_render($form[$key_pre ."_27_3"]);?>mmol/L
    </td>
  </tr>
  <tr>
    <td colspan="3"><b>MRI检查：</b> <br/>
      <?php print drupal_render($form[$key_pre ."_28_1"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;检测日期：<?php print drupal_render($form[$key_pre ."_28_2"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;检测结果：<br/>
      &nbsp;&nbsp;&nbsp;&nbsp;1.T2*<?php print drupal_render($form[$key_pre ."_29_1"]);?>MS；LIC：<?php print drupal_render($form[$key_pre ."_29_2"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;2.其它请详述：<?php print drupal_render($form[$key_pre ."_29_3"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;3.是否判定为铁过载？<br/>
      &nbsp;&nbsp;&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_30_1"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_30_2"]);?>，程度为<?php print drupal_render($form[$key_pre ."_30_3"]);?><?php print drupal_render($form[$key_pre ."_30_4"]);?><?php print drupal_render($form[$key_pre ."_30_5"]);?><br/>
      <?php print drupal_render($form[$key_pre ."_31_1"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;检测日期：<?php print drupal_render($form[$key_pre ."_31_2"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;检测结果：<br/>
      &nbsp;&nbsp;&nbsp;&nbsp;1.T2*<?php print drupal_render($form[$key_pre ."_32_1"]);?>MS；其它请详述：<?php print drupal_render($form[$key_pre ."_32_2"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;2.其它请详述：<?php print drupal_render($form[$key_pre ."_32_3"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;3.是否判定为铁过载？<br/>
      &nbsp;&nbsp;&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_33_1"]);?><br/>
      &nbsp;&nbsp;&nbsp;&nbsp;<?php print drupal_render($form[$key_pre ."_33_2"]);?>，程度为<?php print drupal_render($form[$key_pre ."_33_3"]);?><?php print drupal_render($form[$key_pre ."_33_4"]);?><?php print drupal_render($form[$key_pre ."_33_5"]);?><br/>
      
      胸部X线：<?php print drupal_render($form[$key_pre ."_47_1"]);?><?php print drupal_render($form[$key_pre ."_47_2"]);?><br/>
      心电图：<?php print drupal_render($form[$key_pre ."_48_1"]);?><?php print drupal_render($form[$key_pre ."_48_2"]);?><br/>
      腹部B超：<br/>
      &nbsp;&nbsp;肝脏大小：<?php print drupal_render($form[$key_pre ."_49_1"]);?><?php print drupal_render($form[$key_pre ."_49_2"]);?><br/>
      &nbsp;&nbsp;脾：<?php print drupal_render($form[$key_pre ."_50_1"]);?><?php print drupal_render($form[$key_pre ."_50_2"]);?><br/>
      &nbsp;&nbsp;门静脉宽度：<?php print drupal_render($form[$key_pre ."_51_1"]);?><?php print drupal_render($form[$key_pre ."_51_2"]);?><br/>
    </td>
  </tr>
</table>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title"><h2>治疗决定</h2>
    </td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_34_1"]);?><br/><?php print drupal_render($form[$key_pre ."_34_2"]);?>
    </td>
  </tr>
</table>
<table>
  <tr>
    <td>
      <b>填表医生签名</b>：<?php print drupal_render($form[$key_pre ."_36_1"]);?>       <b>填表日期</b>：<?php print drupal_render($form[$key_pre ."_36_2"]);?>
    </td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>
<script type="text/javascript">
  
//  function tbmj() {
//    var sg = parseInt($('.v_sg input').val());
//    var tz = parseInt($('.v_tz input').val());
//    
//    if (isNaN(tz)) {
//      alert('体重请填写数字！');
//      return false;
//    }
//    
//    if (isNaN(sg)) {
//      alert('身高请填写数字！');
//      return false;
//    }
//    
//    tbmj = 0.0061 * sg + 0.0128 * tz - 0.1529;
//    $('#tbmj input').val(tbmj.toFixed(4));
//    return true;
//  }
//  
//  $('.v_tz input').blur(
//     function(){
//       var a = parseInt($(this).val());
//       if (isNaN(a)) {
//         alert('体重请填写数字！');
//       }
//       if (a>150) {
//         alert('体重应该不能超过150KG');
//       }
//       
//     }
//  );
//    
//  $('.v_sg input').blur(
//     function(){
//       var a = parseInt($(this).val());
//       if (isNaN(a)) {
//         alert('身高请填写数字！');
//       }
//       
//       if (a>220) {
//         alert('身高应该不能超过220CM');
//       } else {
//         
//         tbmj();
//       }
//       
//     }
//  );
//  $('form').submit(tbmj);
  
</script>