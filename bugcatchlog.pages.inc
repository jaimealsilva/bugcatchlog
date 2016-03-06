<?php

/**
 * BugCatchLog module configuration form.
 */
function bugcatchlog_config_form($form, &$form_state) {
  $url = bugcatchlog_config('service_url');
  $site_link = l('BugCatch', 'http://bugcatches.com');
  $form['bugcatchlog_service_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Service URL'),
    '#description' => t('BugCatch service URL, go to !site_link for more information.', array(
      '!site_link' => $site_link,
    )),
    '#default_value' => $url,
    '#required' => TRUE,
  );
  $key = bugcatchlog_config('service_key');
  $form['bugcatchlog_service_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Service key'),
    '#description' => t('BugCatch service key, go to !site_link for more information.', array(
      '!site_link' => $site_link,
    )),
    '#default_value' => $key,
    '#required' => TRUE,
  );
  return system_settings_form($form);
}

/**
 * BugCatchLog configuration form validation.
 */
function bugcatchlog_config_form_validate($form, &$form_state) {
  $url = $form_state['values']['bugcatchlog_service_url'];
  if (!valid_url($url, TRUE)) {
    form_error($form['bugcatchlog_service_url'], t('Invalid URL'));
  }
  // TODO: Check WS answers to a test request
}
