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
      
    }
    else if (p.indexOf(key) != -1) {
      $(this).addClass('done').css('background', 'yellow');
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
    els.click(function(){
      clear_alert(this)
    });
  }
});

/**
 * el 要点击的按钮
 * msg 要提示的信息
 */
function clear_alert(el, msg) {
  if (!msg) {
    msg = '选中将清空下面所有内容，是否确定？';
  }
  
  if ($(el).is(':checked')) {
    if(confirm(msg)) {
      reset_form();
      $(el).attr('checked', true).attr('disabled', false);
    }
  }
  else {
    $("form input").attr('disabled', false);
  }
}

function reset_form() {
  $("form input:radio").attr("checked", false);//.attr('disabled', true);;
  $("form input:checkbox").attr("checked", false);//.attr('disabled', true);;
  $("form input:text").val('');//.attr('disabled', true);;
}
