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
