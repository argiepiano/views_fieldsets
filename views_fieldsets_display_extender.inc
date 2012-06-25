<?php

class views_fieldsets_display_extender extends views_plugin_display_extender {

	function option_definition(&$options) {
		parent::option_definition($options);
		$options['fieldsets'] = array('default' => array());
	}

}
