<?php
  $key_pre = "e_{$table}";
?>
<table class="<?php print $class?>" border="1">
  <tr class="title">
    <td class="title" colspan="3"><h2><?php print $table_name?></h2> <div> 在首次给药前14天内进行</div>
    </td>
  </tr>
  <tr>
    <td colspan="3">取样日期:<?php print drupal_render($form[$key_pre ."_1_1"]);?></td>
  </tr>
  <tr>
    <td>参数</td>
    <td>数值</td>
    <td>单位</td>
  </tr>
  <tr>
    <td>CEA</td>
    <td><?php print drupal_render($form[$key_pre ."_2_1"]);?><?php print drupal_render($form[$key_pre ."_2_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_2_3"]);?><?php print drupal_render($form[$key_pre ."_2_4"]);?><?php print drupal_render($form[$key_pre ."_2_5"]);?></td>
  </tr>
  <tr>
    <td>CA19-9</td>
    <td><?php print drupal_render($form[$key_pre ."_3_1"]);?><?php print drupal_render($form[$key_pre ."_3_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_3_3"]);?><?php print drupal_render($form[$key_pre ."_3_4"]);?><?php print drupal_render($form[$key_pre ."_3_5"]);?></td>
  </tr>
  <tr>
    <td>CA724</td>
    <td><?php print drupal_render($form[$key_pre ."_4_1"]);?><?php print drupal_render($form[$key_pre ."_4_2"]);?></td>
    <td><?php print drupal_render($form[$key_pre ."_4_3"]);?><?php print drupal_render($form[$key_pre ."_4_4"]);?><?php print drupal_render($form[$key_pre ."_4_5"]);?></td>
  </tr>
</table>
<?php
  print drupal_render($form);
?>
<script type="text/javascript">
  $('.xueqing-zlbzwjc input:checkbox').click(
    function() {
      if ($(this).is(':checked')) {
        if(confirm('如果选择【未做】，其他项将被清空，是否继续？')) {
          $(this).parents('tr').find('input:not(checkbox)').each( function(){
             if ($(this).attr('type') == 'radio') {
               $(this).attr('checked', false);
             }
             else if ($(this).attr('type') == 'text') {
               $(this).val('');
             }
           }
          );
        }
        else {
          $(this).attr('checked', false);
        }
      }
    }
  );
</script>