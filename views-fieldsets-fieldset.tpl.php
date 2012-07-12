
<<?php print $tag; ?> class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php if ('fieldset' == $tag): ?>
    <legend><span class="fieldset-legend"><?php print $legend; ?></span></legend>
    <div class="fieldset-wrapper">
  <?php endif; ?>

  <?php print $content; ?>

  <?php if ('fieldset' == $tag): ?>
    </div>
  <?php endif; ?>

</<?php print $tag; ?>>
