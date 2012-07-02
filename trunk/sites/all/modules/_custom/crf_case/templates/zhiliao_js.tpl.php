<?php
  $key_pre = "e_{$table}";
?>
<div>请于研究治疗结束时填写</div>
<div class="big-title"><?php print $table_name?></div>

<table class="<?php print $class?>" border="1">
  <tr>
    <td>总结日期：<?php print drupal_render($form[$key_pre ."_1_1"]);?></td>
  </tr>  
  <tr>
    <td>是否完成治疗计划？<?php print drupal_render($form[$key_pre ."_2_1"]);?>,共完成<?php print drupal_render($form[$key_pre ."_2_2"]);?>个给药周期<br/>
        中止日期：<?php print drupal_render($form[$key_pre ."_3_1"]);?><br/>
        中止治疗的原因：<div class='l-block'><?php print drupal_render($form[$key_pre ."_4_1"]);?></div>
    </td>
  </tr>    
</table>
<?php
  print drupal_render($form);
?>