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
  $('#sidebar-left #block-nice_menus-1 li a').each(function(){
    var href = $(this).attr('href');
    var key  = href.split('/').pop();
    if (p.indexOf(key) != -1) {
      $(this).addClass('done').css('background', 'yellow');
    }
  });
});
