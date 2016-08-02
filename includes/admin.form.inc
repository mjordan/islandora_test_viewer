<?php

/**
 * @file
 * Handles the display/submission of the admin settings form for this module.
 */

/**
 * Defines the admin settings form.
 *
 * @param array $form
 *   The Drupal form definition.
 * @param array $form_state
 *   The Drupal form state.
 *
 * @return array
 *   The Drupal form definition.
 */
function islandora_test_viewer_admin(array $form, array &$form_state) {
  $form['islandora_test_viewer_dsid'] = array(
    '#title' => t('Datastream ID'),
    '#type' => 'textfield',
    '#size' => 30,
    '#default_value' => variable_get('islandora_test_viewer_dsid', 'OBJ'),
    '#description' => t('The datastream ID that you are testing.'),
    '#maxlength' => 50,
  );
  $form['islandora_test_viewer_mimetype'] = array(
    '#title' => t('Mime Type'),
    '#type' => 'textfield',
    '#size' => 30,
    '#default_value' => variable_get('islandora_test_viewer_mimetype', ''),
    '#description' => t('Mime Type of OBJ datastream you are testing.'),
    '#maxlength' => 50,
  );
  module_load_include('inc', 'islandora_test_viewer', 'includes/utilities');
  $cmodels = islandora_test_viewer_get_cmodels();
  $form['islandora_test_viewer_cmodel'] = array(
    '#type' => 'select',
    '#title' => t('Content model'),
    '#options' => $cmodels,
    '#default_value' => variable_get('islandora_test_viewer_cmodel', ''),
    '#description' => t('The content model that applies to objects you want to test.'),
  );

  return system_settings_form($form);
}
