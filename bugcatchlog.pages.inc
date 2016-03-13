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
  $wd_severity_levels = watchdog_severity_levels();
  // Format levels labels
  $severity_levels = array();
  foreach ($wd_severity_levels as $level => $label) {
    $severity_levels[$level] = "[{$level}] " . drupal_ucfirst($label);
  }
  $level = bugcatchlog_config('max_severity');
  $form['bugcatchlog_max_severity'] = array(
    '#title' => t('Severity level'),
    '#description' => t('Maximum severity level to report. All logs with this severity or lower will be reported'),
    '#type' => 'radios',
    '#options' => $severity_levels,
    '#default_value' => $level,
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
