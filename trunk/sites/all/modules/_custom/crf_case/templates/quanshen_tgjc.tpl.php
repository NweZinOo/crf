<?php
  $key_pre = "e_{$table}";
?>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="4"><h2><?php print $table_name?></h2> <div> 在首次给药前8天内进行</div>
    </td>
  </tr>
  <tr>
    <td>检查日期</td>
    <td colspan="3"><?php print drupal_render($form[$key_pre ."_1_1"]);?></td>
  </tr>
  <tr>
    <td>体重</td>
    <td class="v_tz"><?php print drupal_render($form[$key_pre ."_2_1"]);?>kg</td>
    <td>身高</td>
    <td class="v_sg"><?php print drupal_render($form[$key_pre ."_2_2"]);?>cm</td>
  </tr>
  <tr>
    <td>过去3月内体重减轻</td>
    <td><?php print drupal_render($form[$key_pre ."_3_1"]);?>%</td>
    <td>体表面积</td>
    <td id="tbmj"><?php print drupal_render($form[$key_pre ."_3_2"]);?>m2<br/>(无需填写，系统会自动算出。)</td>
  </tr>
  <tr>
    <td>血压</td>
    <td><?php print drupal_render($form[$key_pre ."_4_1"]);?>/<?php print drupal_render($form[$key_pre ."_4_2"]);?>mmHg</td>
    <td>ECOG PS评分</td>
    <td><?php print drupal_render($form[$key_pre ."_4_3"]);?>分</td>
  </tr>
  <tr>
    <td>检查项目</td>
    <td>正常/异常</td>
    <td colspan="2">如体检有异常，请说明</td>
  </tr>
  <tr>
    <td>一般状况</td>
    <td><?php print drupal_render($form[$key_pre ."_5_1"]);?></td>
    <td colspan="2"><?php print drupal_render($form[$key_pre ."_5_2"]);?></td>
  </tr>
  <tr>
    <td>头（面）部</td>
    <td><?php print drupal_render($form[$key_pre ."_6_1"]);?></td>
    <td colspan="2"><?php print drupal_render($form[$key_pre ."_6_2"]);?></td>
  </tr>
  <tr>
    <td>皮肤</td>
    <td><?php print drupal_render($form[$key_pre ."_7_1"]);?></td>
    <td colspan="2"><?php print drupal_render($form[$key_pre ."_7_2"]);?></td>
  </tr>
  <tr>
    <td>淋巴结</td>
    <td><?php print drupal_render($form[$key_pre ."_8_1"]);?></td>
    <td colspan="2"><?php print drupal_render($form[$key_pre ."_8_2"]);?></td>
  </tr>
  <tr>
    <td>口腔</td>
    <td><?php print drupal_render($form[$key_pre ."_9_1"]);?></td>
    <td colspan="2"><?php print drupal_render($form[$key_pre ."_9_2"]);?></td>
  </tr>
  <tr>
    <td>呼吸系统</td>
    <td><?php print drupal_render($form[$key_pre ."_10_1"]);?></td>
    <td colspan="2"><?php print drupal_render($form[$key_pre ."_10_2"]);?></td>
  </tr>
  <tr>
    <td>心血管系统</td>
    <td><?php print drupal_render($form[$key_pre ."_11_1"]);?></td>
    <td colspan="2"><?php print drupal_render($form[$key_pre ."_11_2"]);?></td>
  </tr>
  <tr>
    <td>腹部（包括肝脾）</td>
    <td><?php print drupal_render($form[$key_pre ."_12_1"]);?></td>
    <td colspan="2"><?php print drupal_render($form[$key_pre ."_12_2"]);?></td>
  </tr>
  <tr>
    <td>生殖-泌尿系统</td>
    <td><?php print drupal_render($form[$key_pre ."_13_1"]);?></td>
    <td colspan="2"><?php print drupal_render($form[$key_pre ."_13_2"]);?></td>
  </tr>
  <tr>
    <td>肌肉骨骼</td>
    <td><?php print drupal_render($form[$key_pre ."_14_1"]);?></td>
    <td colspan="2"><?php print drupal_render($form[$key_pre ."_14_2"]);?></td>
  </tr>
  <tr>
    <td>神经系统</td>
    <td><?php print drupal_render($form[$key_pre ."_15_1"]);?></td>
    <td colspan="2"><?php print drupal_render($form[$key_pre ."_15_2"]);?></td>
  </tr>
  <tr>
    <td>精神状况</td>
    <td><?php print drupal_render($form[$key_pre ."_16_1"]);?></td>
    <td colspan="2"><?php print drupal_render($form[$key_pre ."_16_2"]);?></td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>
<script type="text/javascript">
  
  function tbmj() {
    var sg = parseInt($('.v_sg input').val());
    var tz = parseInt($('.v_tz input').val());
    
    if (isNaN(tz)) {
      alert('体重请填写数字！');
      return false;
    }
    
    if (isNaN(sg)) {
      alert('身高请填写数字！');
      return false;
    }
    
    tbmj = 0.0061 * sg + 0.0128 * tz - 0.1529;
    $('#tbmj input').val(tbmj.toFixed(4));
    return true;
  }
  
  $('.v_tz input').blur(
     function(){
       var a = parseInt($(this).val());
       if (isNaN(a)) {
         alert('体重请填写数字！');
       }
       if (a>150) {
         alert('体重应该不能超过150KG');
       }
       
     }
  );
    
  $('.v_sg input').blur(
     function(){
       var a = parseInt($(this).val());
       if (isNaN(a)) {
         alert('身高请填写数字！');
       }
       
       if (a>220) {
         alert('身高应该不能超过220CM');
       } else {
         
         tbmj();
       }
       
     }
  );
  $('form').submit(tbmj);
  
</script>