
(function($) {

	Drupal.behaviors.viewsFieldsets = {
		attach: function(context, settings) {

			$context = $(context);

			console.log('views_fieldsets context', $context[0]);
			context != document && console.log("========\n========\n" + $context.html() + "\n========\n========");

		} // attach()
	}; // behaviors.viewsFieldsets

})(jQuery);
