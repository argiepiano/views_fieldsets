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

    $options['children'] = array('default' => array());

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
    $element['#description'] = t('The back-end admin label and front-end fieldset title.');

    // @todo Add css_class etc here.
//dpm($form);
  }

  function render($values) {
    if (isset($this->options['children'])) {
      return 'I SHOULD CONTAIN: ' . implode(', ', $this->options['children']);
    }
  }

}
