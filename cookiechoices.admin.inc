<?php
/**
 * @file
 * Implements the configuration of the Cookies Directive pop-up dialog.
 * @todo add settings for
 * visibility (timeout, country restriction), exclude path
 *
 */

/**
 * Implements admin settings form.
 */
function cookiechoices_admin_settings() {
  $form = array();
  $path = drupal_get_path('module', 'cookiechoices');

  $form['interface'] = array(
    '#type' => 'fieldset',
    '#title' => t('User Interface'),
    '#description' => t('Strings are translated. Please add translations in the <a href="@link">Translate interface</a>.<br>Leave the fields blank then save to reset them to default', array('@link' => '/admin/config/regional/translate/translate')),
  );
  $form['interface']['cookiechoices_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Introduction Text'),
    '#default_value' => variable_get('cookiechoices_text', COOKIECHOICES_TEXT),
    '#description' => t('A short message requesting consent to use cookies on this site. HTML markup is allowed for adding links and paragraphs.'),
  );
  $form['interface']['cookiechoices_more_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Learn more link text'),
    '#default_value' => variable_get('cookiechoices_more_text', COOKIECHOICES_MORE_TEXT),
    '#description' => t('The label used for "read more about cookies" link'),
  );
  $form['interface']['cookiechoices_more_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Learn more link URL'),
    '#default_value' => variable_get('cookiechoices_more_url', COOKIECHOICES_MORE_URL),
    '#description' => t('An external url used for the "read more about cookies" link. Use that synthax: http://url.com.'),
  );
  $form['interface']['cookiechoices_close_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Close button text'),
    '#default_value' => variable_get('cookiechoices_close_text', COOKIECHOICES_CLOSE_TEXT),
    '#description' => t('Close link label'),
  );
  $form['interface']['cookiechoices_theme'] = array(
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

/**
 * Admin settings validate.
 *
 * @param mixed $form
 * @param mixed &$form_state
 */
function cookiechoices_admin_settings_validate($form, &$form_state) {
  // Revert blank fields to default
  if ($form_state['values']['cookiechoices_text'] == '') {
    form_set_value($form['interface']['cookiechoices_text'], COOKIECHOICES_TEXT, $form_state);
  }
  if ($form_state['values']['cookiechoices_more_text'] == '') {
    form_set_value($form['interface']['cookiechoices_more_text'], COOKIECHOICES_MORE_TEXT, $form_state);
  }
  if ($form_state['values']['cookiechoices_more_url'] == '') {
    form_set_value($form['interface']['cookiechoices_more_url'], COOKIECHOICES_MORE_URL, $form_state);
  }
  if ($form_state['values']['cookiechoices_close_text'] == '') {
    form_set_value($form['interface']['cookiechoices_close_text'], COOKIECHOICES_CLOSE_TEXT, $form_state);
  }
  
  // Remove any newlines to avoid breaking JavaScript
  form_set_value($form['interface']['cookiechoices_text'], str_replace(array("\r\n", "\n", "\r"), '', $form_state['values']['cookiechoices_text']), $form_state);
}