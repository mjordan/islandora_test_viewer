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
    // Get object label from dc:title.
    $dom = new DOMDocument();
    $dom->loadXML($islandora_object['OBJ']->content);
    $xpath = new DOMXPath($dom);
    $xpath->registerNamespace('dc', 'http://purl.org/dc/elements/1.1/');
    $titles = $xpath->query("//dc:title");
    if ($titles->length > 0) {
      $title = $titles->item(0)->nodeValue;
    }
    else {
      $title = '[No object label available]';
    }

    $variables['islandora_content'] = '<div>Islandora Test Viewer says the title from Dublin Core is: ' . $title . '</div>';
  }
}
