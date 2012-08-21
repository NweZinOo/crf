<?php

/**
 * Add IE stylesheets
 */
function eldir_kt_preprocess_page(&$vars) {
  // Add IE 7 compatibility stylesheet
  $vars['styles_ie7up'] = base_path() . path_to_theme() . '/ie7up.css';
}

/**
 * Override breadcrumb seperator and allow first term to be special
 */
function eldir_kt_breadcrumb($breadcrumb) {
  if (!empty($breadcrumb)) {
    $themed_crumbs = '<div class="breadcrumb">';
    $num_crumbs = count($breadcrumb);
    $first =    TRUE;
    foreach  ($breadcrumb as $crumb) {
      if ($first) {
        $themed_crumbs .= "<span class='first-crumb'>{$crumb}</span>";
        $first = FALSE;
      } 
      else {
        $themed_crumbs .= " / {$crumb}";
      } 
    }
    $themed_crumbs .= '</div>';
    return $themed_crumbs;
  }
}

/**
 * Override links theming so we can get an extra span for rounded joy
 */
function eldir_kt_links($links, $attributes = array('class' => 'links')) {
  global $language;
  $output = '';

  if (count($links) > 0) {
    $output = '<ul'. drupal_attributes($attributes) .'>';

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      $class = $key;
      // Make some changes to link so that we can use an internal span
      $link['html'] = TRUE;
      $link['title'] = "<span>{$link['title']}</span>";

      // Add first, last and active classes to the list of links to help out themers.
      if ($i == 1) {
        $class .= ' first';
      }
      if ($i == $num_links) {
        $class .= ' last';
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
          && (empty($link['language']) || $link['language']->language == $language->language)) {
        $class .= ' active';
      }
      $output .= '<li'. drupal_attributes(array('class' => $class)) .'>';

      if (isset($link['href'])) {
        // Pass in $link as $options, they share the same keys.
        $output .= l($link['title'], $link['href'], $link);
      }
      else if (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span'. $span_attributes .'>'. $link['title'] .'</span>';
      }

      $i++;
      $output .= "</li>\n";
    }

    $output .= '</ul>';
  }

  return $output;
}

/**
 * Override button theming for more rounded corner fun
 */
function eldir_kt_button($element) {
  // Make sure not to overwrite classes.
  if (isset($element['#attributes']['class'])) {
    $element['#attributes']['class'] = 'form-'. $element['#button_type'] .' '. $element['#attributes']['class'];
  }
  else {
    $element['#attributes']['class'] = 'form-'. $element['#button_type'];
  }

  return '<span class="button-wrapper"><input type="submit" '. (empty($element['#name']) ? '' : 'name="'. $element['#name'] .'" ') .'id="'. $element['#id'] .'" value="'. check_plain($element['#value']) .'" '. drupal_attributes($element['#attributes']) ." /></span>\n";
}

/**
 * Theme a formatted price for display.
 *
 * @ingroup themeable
 */
function eldir_kt_uc_price($value, $context, $options) {
// check if this product kit has cck checkbox 'annual' checked
  if ($context['subject']['node']->field_annual['0']['value'] == 'annual') {

    // add label stating that this is an annual payment
    $options['label'] = TRUE;
    $options['prefixes'] = ''; // clear 'Price:' label
    $options['suffixes'][] = t(' /year');
  }

// Fixup class names.
  if (!is_array($context['class'])) {
    $context['class'] = array();
  }
  foreach ($context['class'] as $key => $class) {
    $context['class'][$key] = 'uc-price-'. $class;
  }
  $context['class'][] = 'uc-price';
  // Class the element.
  $output = '<span class="'. implode(' ', $context['class']) .'">';
  // Prefix(es).
  if ($options['label'] && isset($options['prefixes'])) {
    $output .= '<span class="price-prefixes">'. implode('', $options['prefixes']) .'</span>';
  }
  // Value.
  $output .= $value;
  // Suffix(es).
  if ($options['label'] && isset($options['suffixes'])) {
    $output .= '<span class="price-suffixes">'. implode('', $options['suffixes']) .'</span>';
  }
  $output .= '</span>';

  return $output;
}
