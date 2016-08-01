<?php

/**
 * @file
 * Any hooks/functions used by this module's themes.
 */

/**
 * Implements hook_preprocess_theme().
 */
function islandora_test_viewer_preprocess_islandora_test_viewer(array &$variables) {
  if (isset($variables['islandora_object'])) {
    $islandora_object = $variables['islandora_object'];
    $variables['islandora_content'] = '<div>Islandora Test Viewer says the title from Dublin Core is: ' .
      $islandora_object->label . '</div>';
  }
}
