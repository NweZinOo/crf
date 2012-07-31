if (!Array.indexOf) {
  Array.prototype.indexOf = function(obj) {
    for (var i=0; i<this.length; i++) {
      if (this[i]==obj) {
        return i;
      }
    }
    return -1;
  }
}

$(document).ready(function() {
  var p = Drupal.settings.progress;
  
  var d = Drupal.settings.disabled;
  
  var can = [];
  
  if (Drupal.settings.all_doable == 1) {
    //nothing
  }
  else if (false) {
    can = [/*'zhiliao_js', 'xueye_zlbjwjcjghzb', 'yanzhong_blsjjl', */'siwang_jl', 'yanjiu_js'];

    for(var i=1; i<=5; i++) {
      can.push('pg' + i.toString() + '_1');
      can.push('pg' + i.toString() + '_2');
      can.push('pg' + i.toString() + '_3');
      can.push('pg' + i.toString() + '_4');
      can.push('pg' + i.toString() + '_5');
      can.push('pg' + i.toString() + '_6');
    }
  }
  
  $('#sidebar-left .block-nice_menus li a').each(function(){
    var href = $(this).attr('href');
    var key  = href.split('/').pop();
   
    if($(this).hasClass('active')){ //current
      $(this).append("<span class='big-active'></span>")
      $(this).parent().parent().siblings("a").append("<span class='big-active'></span>");
    }
    else if (p.indexOf(key) != -1) {
//    $(this).addClass('done').css('background', 'yellow');
      $(this).addClass('done');
    }
    else if (Drupal.settings.all_doable == 1 || can.indexOf(key) != -1) {
      $(this).addClass('doable');
    }
    else {
      $(this).addClass('inactived');
      $(this).attr('href', 'javascript:alert("目前不能编辑该项，请按顺序完成！")');
    }
    
    if (d && d.join) {
      if (d.indexOf(key) != -1) {
        $(this).parent().hide();
      }
    }
  });
  
  
});


$(document).ready(function(){
  var els = $('tr.title').find('input:checkbox');
  if (els && els.size() == 1) {
    $('form#crf-case-form').submit(function(){
      clear_alert(els);
    });
    
    els.click(function(){
     clear_alert(els);
    });
  }
  
  var tt = setTimeout(function() {
    $('form#user-login-form').attr("autocomplete", "off").find('#edit-name, #edit-pass').val('').attr("autocomplete", "off");
    clearTimeout(tt);
  }, 500);
});

/**
 * el 要点击的按钮
 * msg 要提示的信息
 */
function clear_alert(el, msg, callback) {
  
  
  if ($(el).is(':checked')) {
    var text = $(el).parent().text();
    
    if (!msg) {
      msg = '由于您选择了【 ' + text + ' 】，因此其他内容将不被保存，是否确定？';
    }
  
    if(confirm(msg)) {
      if (!callback) {
        reset_form();
      }
      else {
        callback.apply();
      }
      
      $(el).attr('checked', true).attr('disabled', false);
    }
    else {
      $(el).attr('checked', false);
    }
  }
}

function reset_form() {
  $("form input:radio").attr("checked", false);//.attr('disabled', true);;
  $("form input:checkbox").attr("checked", false);//.attr('disabled', true);;
  $("form input:text").val('');//.attr('disabled', true);;
}


function get_days(d1, d2) {
  var dd1 = d1.split('-');
  var dd2 = d2.split('-');
  var date1   = new Date(dd1[0], dd1[1] - 1, dd1[2]);
  var date2   = new Date(dd2[0], dd2[1] - 1, dd2[2]);
  var one_day = 1000*60*60*24;
  var offset  = (date2.getTime() - date1.getTime()) / one_day;
  return offset;
}



$(document).ready(function(){
 var tr = $('tr.clear-alert');
 var el = tr.find('td:nth-child(1)').find('input[type=checkbox]');
 
 if (el.size()) {
   el.click(
     function () {
       clear_alert(el, null, function(){ tr.find('input[type=text]').val('')}) 
     }
   );
 }
});

$(document).ready(function(){
  var cal = function(){
   var date1 = $('.date-select input:text').eq(0).val();
   var date2 = $('.date-select input:text').eq(1).val();
   
   var days  = get_days(date1, date2) + 1;
   
   if (isNaN(days)) {
     alert('日期不对，请检查！');
     return false;
   }
   if (days < 0) {
     alert('结束日期不能早于起始日期');
     return false;
   }
   else if(days != 14) {
     alert('您选择的时间间隔为' + days + '，给药持续时间间隔必须为14天，请检查！');
     return false;
   }
   else {
     var unit = 0
     $('.calculate input:radio').each(function(){
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
 if ($('.calculate input[type=radio]').size()) {
   $('.calculate input[type=radio]').click(cal);
   $('.total input[type=text]').focus(cal);
   $('form').submit(cal);
  }
});//给药日期计算总量