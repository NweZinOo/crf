<?php

define('SCRIPT_ROOT',  dirname(__FILE__).'/SMS_Client/');

require_once SCRIPT_ROOT . '/include/Client.php';

define('SMS_SESSION', '100043');
define('SMS_PASS', '237728');
//define('SMS_PASS', 575842);
define('SMS_NO', '3SDK-EMY-0130-NGVNO');
define('SMS_URL', 'http://sdkhttp.eucp.b2m.cn/sdk/SDKService?wsdl');


function crf_common_drush_command() {
  $items = array();
  $items['crf_sms'] = array(
    'callback' => 'crf_sms',
    'options' => array('mode' => dt('[test|formal] mode to send tester number'), 'test' => dt('test sms')),
    'description' => 'Sent SMS to users.',
    'aliases' => array('cms'),
    'examples' => array(
      'drush cms --mode=test|formal --test=1' => 'Send test SMS to number, please set mode=formal when you are running this script.',
    ),
  );
  return $items;
}

function crf_sms() {
  $test  = drush_get_option('test', FALSE);
  $mode  = drush_get_option('mode', 'test');
  $reg   = drush_get_option('reg', 0);
  
  if ($reg) {
    crf_sms_reg();
  }
  else {
    if ($test) {
      if (is_numeric($test) && $test > 1) {
        $row = db_fetch_array(db_query('SELECT * FROM apply WHERE p_uid = %d', $test));
        crf_scan_user_stage($row, '18610256090');
      }
      else {
        crf_sendSMS('18610256090');
      }
    }
    else {
      $sql = 'SELECT * FROM apply';
      $res = db_query($sql);
      
      while ($row = db_fetch_array($res)) {
        $to_phone = $mode == 'formal' ? $row['phone'] : 0;
        crf_scan_user_stage($row, $to_phone);
      }
    }
  }
}

function crf_scan_user_stage($data, $phone) {
  $stages = array(
    'zq1','zq2','zq3','zq4','zq5','zq6','zq7','zq8','zq9', 'zq10', 'zq11', 'zq12', 'zq13', 'zq14', 'zq15', 'zq16',
    'zhiliao_js',
    'sf1', 'sf2', 'sf3', 'sf4', 
  );
  foreach ($stages as $stage ) {
    crf_send_next_sms($data['p_uid'], $stage, $phone, $data['p_name'], $data['case_history_no']);
  }
}

function crf_send_next_sms($p_uid, $stage, $phone = 0, $p_name = NULL, $case_no = NULL) {
  
  $db_exists = db_result(db_query('SELECT count(1) FROM apply_sms WHERE puid = %d AND sms_stage = "%s"', $p_uid, $stage));
  //drush_log($db_exists, 'ok');
  drush_log($p_uid . ' --stage: ' . $stage . ' --sent: ' . $db_exists, 'warning');

  if ($db_exists == 1) {
    //drush_log('User ' . $p_uid . ' at stage ' . $stage . ' has been sent sms to admin', 'warning');
    return false;
  }
  
  list($name, $key_1st, $key_2nd) = crf_geiyao_key($stage);
  drush_print($name . '--' . $stage . " ==>[$name, $key_1st, $key_2nd]");
  
  $object = crf_ds_load($name, $p_uid);
  $array  = json_to_array($object);
  
  if (isset($array[$key_1st]) && $date = $array[$key_1st][$key_2nd]) {
    
    $is_zq = preg_match('{^zq}i', $stage);
    list($new_stage, $time_span, $content) = _next_sms_meta($stage);

    $done_date = strtotime($date);
    $send_date = $done_date + $time_span;
    
    if (time() > $send_date) {

      $next_op_date = date('Y年m月d日', $done_date +  21 * 24 * 3600);
      if ($is_zq && time() > $done_date +  21 * 24 * 3600) {
        drush_log($p_uid . ' --expired, ' . $next_op_date, 'warning');
        //时间已过
        return FALSE;
      }
      
      $content = str_replace(array('{name}', '{patient_no}', '{date}'), array($p_name, $case_no, $next_op_date), $content);
      crf_sendSMS($phone, $content);
      
      drush_log("Sent SMS to $phone at user: $p_uid, stage: $stage", 'ok');
      if ($phone) {
        $sql = "INSERT INTO apply_sms (puid, sms_stage, updated, phone, content) VALUES (%d, '%s', %d, '%s', '%s')";
        db_query($sql, $p_uid, $stage, time(), $phone, $content);
        
        /*
        if ($db_exists) {
          $sql = "UPDATE apply_sms SET sms_stage = '%s', updated = %d WHERE puid = %d";
          db_query($sql, $new_stage, time(), $p_uid);
        }
        else {
        }
        */
      }
    }
  }
}

function _next_sms_meta($stage) {
  
  preg_match('{([a-z]+)(\d+)}', $stage, $matches);
  
  if ($matches[1] == 'zq' && $matches[2] == '16') {
    $new_stage = 'zhiliao_js';
  }
  else if($stage == 'zhiliao_js') {
    $new_stage = 'sf1';
  }
  else {
    $new_stage = $matches[1] . $matches[2] + 1;
  }
  
  if ($matches[1] == 'zq') {
    $time_span   = 17 * 24 * 60 * 60;
    $content = "医生您好！您负责的SOX对比S-1辅助化疗III期临床，{name} 患者病历号为 {patient_no} 将于{date}开始下一周期的治疗。";
  }
  else if ($matches[1] == 'sf') {
    $content = "医生您好！您负责的SOX对比S-1辅助化疗III期临床，{name} 患者病历号为 {patient_no} 将于下周进行下一次访视，需按方案对疾病情况进行评估。";
    
    if ($matches[2] < 5) {
      $time_span   = 86 * 24 * 60 * 60;
    }
    else {
      $time_span   = 176 * 24 * 60 * 60;
    }
  }
  else if ($stage == 'zhiliao_js') {
    $content = "医生您好！您负责的SOX对比S-1辅助化疗III期临床，{name} 患者病历号为 {patient_no} 将于下周进行下一次访视，需按方案对疾病情况进行评估。";
    $time_span = 86 * 24 * 60 * 60;
  }
  
  return array($new_stage, $time_span, $content);
}

/**
 *
 * @param type $stage such as zq1 zq2
 * @return type 
 */
function crf_geiyao_key($stage) {
  
  global $crf_el;
  static $stages;
  
  if ($stage == 'zhiliao_js') {
    return array('zhiliao_js', 1, 1);
  }
  else if (preg_match('{^sf(\d+)}i', $stage, $matches) ) {
    return array("{$stage}_1", 1, 1);
  }
  
  if (isset($stages[$stage])) {
    return $stages[$stage];
  }
  
  for ($i = 1; $i < 5; $i++) {     
    $key = "{$stage}_{$i}";
    if (isset($crf_el[$key])) {
      if (in_array($crf_el[$key]['#name'], array('研究给药'))) {
        $stages[$stage][] = $key;
        
        for ($n = 1; $n < 5; $n++) {
          $array = $crf_el[$key][$n];

          foreach ($array as $k => $v) {
            if ($v['#type'] == 'date_popup') {
              $stages[$stage][] = $n;
              $stages[$stage][] = $k;
              break 3;
            }
          }
        }
      }
    }
  }
  
  return $stages[$stage];
}

function crf_sms_reg() {
  set_time_limit(0);
	header("Content-Type: text/html; charset=$encode");
  
  $client = new Client(SMS_URL, SMS_NO, SMS_PASS, SMS_SESSION);
  $client->setOutgoingEncoding("$encode");
  
  $regStatus = $client->registDetailInfo('中国抗癌协会', '肖德楠', '13811980205', '13811980205', 'xiaodenan@gmail.com', '13811980205', 'Beijing', '100085');
  drush_print_r($regStatus);
}

function crf_sendSMS($phone = 0, $msg = NULL) {
  $encode = 'UTF-8';
  
  set_time_limit(0);
	//header("Content-Type: text/html; charset=$encode");
  
  $client = new Client(SMS_URL, SMS_NO, SMS_PASS, SMS_SESSION);
  $client->setOutgoingEncoding("$encode");
  
  //$loginStatus = $client->login(SMS_SESSION);
  //drush_print('Login status: ' . $loginStatus);
  /*
  if ($loginStatus == 0) {
  	//登录成功，并且做保存 $sessionKey 的操作，用于以后相关操作的使用
    $SMS_text = 'TEST21111';
    $statusCode = $client->sendSMS(array($phone), $SMS_text . ' [中国抗癌协会]');
    drush_print('Sent status: ' . $statusCode);
  }else{
  	 //登录失败处理
  }*/
  if (empty ($msg)) {
    $msg = 'Test Message';
  }
  
  $phones = array('18610256090', /*'13811980205'*/);
  if ($phone) {
    $phones[] = $phone;
  }
  
  $statusCode = $client->sendSMS($phones, $msg . ' [中国抗癌协会]');
  

  //
  //drush_log('Sent status code : ' .$statusCode, 'notice');
  
   
  //$statusCode = $client->login();
  //drush_print('Login status: ' . $statusCode);
  
  //$SMS_text = 'TEST21111';
  //$statusCode = $client->sendSMS(array($phone), $SMS_text . ' [中国抗癌协会]');
  //var_dump($statusCode);
  
  //$balance = $client->getBalance();
  //drush_print($balance);
	//drush_print("StatusCode: " . $statusCode);
  
  //$err = $client->getError();
  
  watchdog('sms', "Sent SMS to $phone");
  drush_log("Sent SMS to $phone", 'ok');
}