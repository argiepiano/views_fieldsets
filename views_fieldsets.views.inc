<?php

/**
 * Implements hook_views_data().
 */
function views_fieldsets_views_data() {
	$data['views']['fieldset'] = array(
		'title' => t('Fieldset'),
		'help' => t('Adds a fieldset to put fields and other fieldsets in.'),
		'field' => array(
			'handler' => 'views_handler_field_custom',
		),
	);

	return $data;
}
