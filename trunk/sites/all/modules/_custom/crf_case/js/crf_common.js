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
  });
});
