<?php
  $key_pre = "e_{$table}";
?>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="4"><h2><?php print $table_name?></h2>
    </td>
  </tr>
  <tr>
    <td>研究药物</td>
    <td>给药日期</td>
    <td>计划剂量<br/>(mg)</td>
    <td>总给药剂量(mg)</td>
  </tr>
  <tr class="calculate">
    <td>S-1</td>
    <td class="date-select"><?php print drupal_render($form[$key_pre ."_1_1"]);?>至<?php print drupal_render($form[$key_pre ."_1_2"]);?></td>
    <td class="unit"><?php print drupal_render($form[$key_pre ."_1_3"]);?></td>
    <td class="total"><?php print drupal_render($form[$key_pre ."_1_4"]);?></td>
  </tr>
  <tr class="clear-alert">
    <td>奥沙利铂<?php print drupal_render($form[$key_pre ."_2_1"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_3"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_4"]);?></td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>

<script type="text/javascript">
 var cal = function(){
   var date1 = $('.date-select input:text').eq(0).val();
   var date2 = $('.date-select input:text').eq(1).val();
   
   var days  = get_days(date1, date2);
   
   if (isNaN(days)) {
     //alert('日期不对，请检查！')
   }
   if (days < 0) {
     alert('结束日期不能早于起始日期');
     return;
   }
   else {
     var unit = 0
     $('.calculate input:checkbox').each(function(){
       if ($(this).is(':checked')) {
         var u = parseInt($(this).parent().text());//.val();
         if (!isNaN(u)) {
           unit += u; 
         }
       }
     });
     $('.total input:text').val(unit * 14 * 2);s
   }
 }
 
 /*
 $('.date-select input').eq(1).blur(function(){
   var date1 = $('.date-select input:text').eq(0).val();
   var date2 = $('.date-select input:text').eq(1).val();
   
   var days  = get_days(date1, date2);
   
   if (days < 0) {
     alert('结束日期不能早于起始日期');
     return;
   }
 });
 */
 $('.calculate input:checkbox').click(cal);
 $('.total input').focus(cal);
</script>
