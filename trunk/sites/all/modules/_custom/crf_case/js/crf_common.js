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


  $('#sidebar-left .block-nice_menus li a').each(function(){
    var href = $(this).attr('href');
    var key  = href.split('/').pop();
   
    if($(this).hasClass('active')){ //current
      $(this).append("<span class='big-active'></span>")
      $(this).parent().parent().siblings("a").append("<span class='big-active'></span>");
    }
    else if (p.indexOf(key) != -1) {
//      $(this).addClass('done').css('background', 'yellow');
      $(this).addClass('done');
    }
    else {
      $(this).addClass('inactived');
      $(this).attr('href', 'javascript:void(0)');
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
                

      if ($(this).is(':checked')) {
        if (confirm('选中此项，下面所有内容都不能保存，是否确定？')) {
        }
        else {
          $(this).attr('checked', false);
        }
      }
    });
  }
});

/**
 * el 要点击的按钮
 * msg 要提示的信息
 */
function clear_alert(el, msg) {
  
  
  if ($(el).is(':checked')) {
    var text = $(el).parent().text();
    
    if (!msg) {
      msg = '由于您选择了【 ' + text + ' 】，因此其他内容将不被保存，是否确定？';
    }
  
    if(confirm(msg)) {
      reset_form();
      $(el).attr('checked', true).attr('disabled', false);
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
  var date1   = new Date(dd1[0], dd1[1], dd1[2]);
  var date2   = new Date(dd2[0], dd2[1], dd2[2]);
  var one_day = 1000*60*60*24;
  var offset  = (date2.getTime() - date1.getTime()) / one_day;
  return offset;
}
