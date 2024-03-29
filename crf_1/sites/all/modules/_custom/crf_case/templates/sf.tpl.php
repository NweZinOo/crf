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
    <td rowspan="2"><div align="center"><?php print $table_name; ?></div></td>
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
<table>
  <tr>
    <td>随访日期: <?php print drupal_render($form[$key_pre ."_1_1"]);?></td>
  </tr>  
</table>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="4"><h2>祛铁治疗记录</h2>
    </td>
  </tr>
  <tr>
    <td colspan="4">药物名称:<?php print drupal_render($form[$key_pre ."_2_1"]);?>
    </td>
  </tr>
  <tr>
    <td width="25%"></td>
    <td width="25%">第一个月</td>
    <td width="25%">第二个月</td>
    <td width="25%">第三个月</td>
  </tr>
  <tr>
    <td>剂量（mg/kg/d）</td>
    <td><?php print drupal_render($form[$key_pre ."_3_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_3_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_3_3"]);?></td>
  </tr>
  <tr>
    <td>治疗时间</td>
    <td><?php print drupal_render($form[$key_pre ."_4_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_4_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_4_3"]);?></td>
  </tr>
</table>

<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="4"><h2>辅助检查</h2> （与筛选/基线时间间隔<=2周者可不用填写）
    </td>
  </tr>
  <tr>
    <td colspan="4"><h2>1)  血铁五项</h2> （填写自上次访视以来的检查结果）
    </td>
  </tr>
  <tr>
    <td width="25%">取样日期</td>
    <td width="25%"><?php print drupal_render($form[$key_pre ."_5_1"]);?></td>
    <td width="25%"><?php print drupal_render($form[$key_pre ."_5_2"]);?></td>
    <td width="25%"><?php print drupal_render($form[$key_pre ."_5_3"]);?></td>
  </tr>
  <tr>
    <td>血清铁蛋白(SF)</td>
    <td><?php print drupal_render($form[$key_pre ."_6_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_6_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_6_3"]);?></td>
  </tr>
  <tr>
    <td colspan="4"><h2>2)  血常规</h2>  取样日期：<?php print drupal_render($form[$key_pre ."_7_1"]);?><br/>
     Hb：<?php print drupal_render($form[$key_pre ."_8_1"]);?>g/L；WBC：<?php print drupal_render($form[$key_pre ."_8_2"]);?>×10<sup>9</sup>/L；ANC：<?php print drupal_render($form[$key_pre ."_8_3"]);?>×10<sup>9</sup>/L；<br/>
     PLT：<?php print drupal_render($form[$key_pre ."_8_4"]);?>×10<sup>9</sup>/L；
     其他：<?php print drupal_render($form[$key_pre ."_9_1"]);?>
    </td>
  </tr>
  <tr>
    <td colspan="4"><h2>3)  血生化</h2> 取样日期：<?php print drupal_render($form[$key_pre ."_10_1"]);?><br/>
     谷草转氨酶(SGOT)：<?php print drupal_render($form[$key_pre ."_11_1"]);?>；谷丙转氨酶(SGPT)：<?php print drupal_render($form[$key_pre ."_11_2"]);?>
     空腹血糖(FBS)：<?php print drupal_render($form[$key_pre ."_12_1"]);?>
    </td>
  </tr>
</table>

<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="3"><h2>原发病治疗情况</h2> （选填项目）
    </td>
  </tr>
  <tr>
    <td width="25%">药物</td>
    <td width="25%">剂量</td>
    <td width="50%">用药时间</td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_13_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_13_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_13_3"]);?>到<?php print drupal_render($form[$key_pre ."_13_4"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_14_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_14_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_14_3"]);?>到<?php print drupal_render($form[$key_pre ."_14_4"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_15_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_15_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_15_3"]);?>到<?php print drupal_render($form[$key_pre ."_15_4"]);?></td>
  </tr>
  <tr>
    <td><?php print drupal_render($form[$key_pre ."_16_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_16_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_16_3"]);?>到<?php print drupal_render($form[$key_pre ."_16_4"]);?></td>
  </tr>
</table>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title"><h2>原发病相关检查</h2> （选填项目）
    </td>
  </tr>
  <tr>
    <td><b>骨髓检查：</b>检查日期:<?php print drupal_render($form[$key_pre ."_17_1"]);?>
    </td>
  </tr>
  <tr>
    <td>结果:<?php print drupal_render($form[$key_pre ."_18_1"]);?>
    </td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>
<script type="text/javascript">
//  
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
//  
</script>