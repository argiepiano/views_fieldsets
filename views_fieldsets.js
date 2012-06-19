
(function($) {

	Drupal.behaviors.viewsFieldsets = {
		attach: function(context, settings) {

			console.log('behaviors:viewsFieldsets:attach context', $(context)[0]);

		} // attach()
	}; // behaviors.viewsFieldsets

})(jQuery);
