<?php

/**
 * @file
 * Implements the configuration of the Cookies Directive pop-up dialog.
 * @todo add settings for
 * visibility (timeout, country restriction), exclude path
 *
 */

/**
 * Defines admin settings form.
 */
function cookiechoices_settings_form($form, &$form_state) {
  $form = array();

  $form['ui'] = array(
    '#type' => 'fieldset',
    '#title' => t('User interface'),
  );
  $form['ui']['cookiechoices_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Introduction Text'),
    '#default_value' => variable_get('cookiechoices_text', COOKIECHOICES_TEXT),
    '#description' => t('A short message requesting consent to use cookies on this site. HTML markup is allowed for adding links and paragraphs.'),
  );
  $form['ui']['cookiechoices_more_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Learn more link text'),
    '#default_value' => variable_get('cookiechoices_more_text', COOKIECHOICES_MORE_TEXT),
    '#description' => t('The label used for "read more about cookies" link'),
  );
  $form['ui']['cookiechoices_more_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Learn more link URL'),
    '#default_value' => variable_get('cookiechoices_more_url', COOKIECHOICES_MORE_URL),
    '#description' => t('An external url used for the "read more about cookies" link. Use that synthax: http://url.com.'),
  );
  $form['ui']['cookiechoices_close_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Close button text'),
    '#default_value' => variable_get('cookiechoices_close_text', COOKIECHOICES_CLOSE_TEXT),
    '#description' => t('Close link label'),
  );
  $form['ui']['cookiechoices_theme'] = array(
    '#type' => 'radios',
    '#title' => t('Colour theme'),
    '#description' => t("Choose the colour set used on the widget. Selecting a contrast to your theme will help visitors see the pop-up. Fancy people, choose “none” to style the message yourself."),
    '#default_value' => variable_get('cookiechoices_theme', 'dark'),
    '#options' => array(
      'dark' => t('Dark'),
      'light' => t('Light'),
      'none' => t('None'),
    )
  );

  $form['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced'),
    '#collapsed' => FALSE,
    '#collapsible' => FALSE
  );

  $form['advanced']['cookiechoices_exclude_paths'] = array(
    '#type' => 'textarea',
    '#title' => t('Exclude Paths'),
    '#default_value' => variable_get('cookiechoices_exclude_paths', ''),
    '#description' => t('Specify pages, on which to not display the cookie control, by using their paths. Enter one path per line. The \'*\' character is a wildcard. Example paths are blog for the blog page and blog/* for every personal blog. %front is the front page.', array('%front' => '<front>')),
  );

  return system_settings_form($form);
}
