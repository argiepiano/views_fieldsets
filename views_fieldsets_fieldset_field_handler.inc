<?php

/**
 * @file
 * A handler to provide a Views Fieldsets field.
 */

class views_fieldsets_fieldset_field_handler extends views_handler_field {
  function query() {
    // do nothing -- to override the parent query.
  }

  function option_definition() {
    $options = parent::option_definition();

    // Remove all but three.
//    $options = array_intersect_key($options, array_flip(array('table', 'id', 'field')));
//    unset($options['alter']);

    // Add the hierarchical fieldset structure storage.
    $options['children'] = array('default' => array());

    // Add (cosmetic) user options.
    $options['fieldset']['contains'] = array();
    $options['fieldset']['contains']['type'] = array('default' => 'fieldset');
    $options['fieldset']['contains']['classes'] = array('default' => '');
    $options['fieldset']['contains']['collapsible'] = array('default' => 0);
    $options['fieldset']['contains']['collapsed'] = array('default' => 0);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    $keep_form_elements = element_children($form);
    $keep_form_elements[] = 'custom_label';
    $keep_form_elements[] = 'label';

    // Get the usual suspects.
    parent::options_form($form, $form_state);

    // Remove all of them, except `label`.
    foreach (element_children($form) as $name) {
      if (!in_array($name, $keep_form_elements)) {
        unset($form[$name]);
      }
    }

    // Alter custom_label (always ON).
    $element = &$form['custom_label'];
    $element['#default_value'] = $element['#value'] = TRUE;
    $element['#type'] = 'hidden';

    // Alter label to make it fit our needs.
    $element = &$form['label'];
    unset($element['#dependency']);
    $element['#title'] = t('Fieldset title');
    $element['#required'] = TRUE;
    $element['#description'] = t('The back-end admin label and front-end fieldset legend.');

    // Add 'fieldset' tree.
    $form['fieldset'] = array(
      '#tree' => TRUE,
    );

    $fieldset_types = array(
      'fieldset' => '<fieldset>',
      'div' => '<div>',
    );
    $form['fieldset']['type'] = array(
      '#type' => 'select',
      '#title' => t('Display type'),
      '#options' => $fieldset_types,
      '#default_value' => $this->options['fieldset']['type'],
      '#description' => t('A <code>&lt;fieldset&gt;</code> will always show its title as <code>&lt;legend&gt;</code>. A <code>&lt;div&gt;</code> will never show the title.'),
    );

    $form['fieldset']['classes'] = array(
      '#type' => 'textfield',
      '#title' => t('CSS classes'),
      '#default_value' => $this->options['fieldset']['classes'],
    );

    $form['fieldset']['collapsible'] = array(
      '#type' => 'checkbox',
      '#title' => t('Collapsible'),
      '#default_value' => $this->options['fieldset']['collapsible'],
    );

    $form['fieldset']['collapsed'] = array(
      '#type' => 'checkbox',
      '#title' => t('Collapsed'),
      '#default_value' => $this->options['fieldset']['collapsed'],
    );
  }

  function render($values) {
    if (isset($this->options['children'])) {
      return 'I SHOULD CONTAIN: ' . implode(', ', $this->options['children']);
    }
  }

}
