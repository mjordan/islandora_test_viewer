<?php

/**
 * @file
 * Utilities.
 */

/**
 * Populates a list of cmodels for use in the admin setting form.
 *
 * @return array
 *   A list of supported content models that are currently installed.
 */
function islandora_test_viewer_get_cmodels() {
  module_load_include('inc', 'islandora', 'includes/utilities');
  $cmodels = islandora_get_content_models();
  $options = array();
  foreach ($cmodels as $cmodel) {
    $pid = $cmodel['pid'];
    $options[$pid] = $cmodel['label'];
  }
  return $options;
}
