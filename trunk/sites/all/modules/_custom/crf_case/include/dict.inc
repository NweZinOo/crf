<?php

function crf_case_dict() {
//  print dirname(__FILE__);
  
  include_once dirname(__FILE__) . '/crf_dict_source.php';
  include_once dirname(__FILE__) . '/class/PHPExcel.php';
  include_once dirname(__FILE__) . '/class/phpExcel/Writer/Excel2007.php';
  include_once dirname(__FILE__) . '/class/phpExcel/IOFactory.php';
  
  $objExcel = new PHPExcel();  
  
  $i=0;  
  //表头  
  $k1 = "代码";  
  $k2 = "名称";  
  $k3 = "变量类型";  
  $k4 = "连续型取值说明";  
  $k5 = "分类型取值说明";  
  $k6 = "文本型取值说明";  

  $objExcel->getActiveSheet()->setCellValue('a1', "$k1");  
  $objExcel->getActiveSheet()->setCellValue('b1', "$k2");  
  $objExcel->getActiveSheet()->setCellValue('c1', "$k3");  
  $objExcel->getActiveSheet()->setCellValue('d1', "$k4");  
  $objExcel->getActiveSheet()->setCellValue('e1', "$k5"); 
  $objExcel->getActiveSheet()->setCellValue('f1', "$k6"); 
  
  foreach($data_basic as $k => $v) {  
      $u1 = $i + 2;  
      $code = $v[0];
      $name = "基本资料:" . $v[1];
      $type = $v[2];
      if ($type == 0) {
        $desc_0 = $v[3];
        unset($desc_1);
        unset($desc_2);
      }
      if ($type == 1) {
        $desc_1 = $v[3];
        unset($desc_0);
        unset($desc_2);
      }
      if ($type == 2) {
        $desc_2 = $v[3];
        unset($desc_0);
        unset($desc_1);
      }

      $objExcel->getActiveSheet()->setCellValue('a'.$u1, $code);  
      $objExcel->getActiveSheet()->setCellValue('b'.$u1, $name);  
      $objExcel->getActiveSheet()->setCellValue('c'.$u1, $types[$type]);  
      $objExcel->getActiveSheet()->setCellValue('d'.$u1, $desc_0);  
      $objExcel->getActiveSheet()->setCellValue('e'.$u1, $desc_1);  
      $objExcel->getActiveSheet()->setCellValue('f'.$u1, $desc_2);  
      $i++;  
  }  
  
  foreach($data_crf as $table_k => $table_v) {  
    foreach($table_v as $line_k => $line_v) {
//      print_r($table_v);
      if ($line_k != "#name") {
        foreach($line_v as $element_k => $element_v) {
          if ($element_k != "#name") {
            $u1 = $i + 2;  
            $code = "e_" . $table_k . "_" . $line_k ."_". $element_k;
            $name = $table_v["#name"] . $line_v["#name"] . $element_v[0];
            $type = $element_v[1];
            if ($type == 0) {
              $desc_0 = $element_v[2];
              unset($desc_1);
              unset($desc_2);
            }
            if ($type == 1) {
              $desc_1 = $element_v[2];
              unset($desc_0);
              unset($desc_2);
            }
            if ($type == 2) {
              $desc_2 = $element_v[2];
              unset($desc_0);
              unset($desc_1);
            }      
            $objExcel->getActiveSheet()->setCellValue('a'.$u1, $code);  
            $objExcel->getActiveSheet()->setCellValue('b'.$u1, $name);  
            $objExcel->getActiveSheet()->setCellValue('c'.$u1, $types[$type]);  
            $objExcel->getActiveSheet()->setCellValue('d'.$u1, $desc_0);  
            $objExcel->getActiveSheet()->setCellValue('e'.$u1, $desc_1);  
            $objExcel->getActiveSheet()->setCellValue('f'.$u1, $desc_2);  
            $i++;  
          }
        }
      }
    }
  }
// 高置列的宽度  
$objExcel->getActiveSheet()->getColumnDimension('A')->setWidth(27);  
$objExcel->getActiveSheet()->getColumnDimension('B')->setWidth(97);  
$objExcel->getActiveSheet()->getColumnDimension('C')->setWidth(16);  
$objExcel->getActiveSheet()->getColumnDimension('D')->setWidth(17);  
$objExcel->getActiveSheet()->getColumnDimension('E')->setWidth(55);  
$objExcel->getActiveSheet()->getColumnDimension('F')->setWidth(155);  
  
$objExcel->getActiveSheet()->getHeaderFooter()->setOddHeader('&L&BPersonal cash register&RPrinted on &D');  
$objExcel->getActiveSheet()->getHeaderFooter()->setOddFooter('&L&B' . $objExcel->getProperties()->getTitle() . '&RPage &P of &N');  
  
// 设置页方向和规模  
$objExcel->getActiveSheet()->getPageSetup()->setOrientation(PHPExcel_Worksheet_PageSetup::ORIENTATION_PORTRAIT);  
$objExcel->getActiveSheet()->getPageSetup()->setPaperSize(PHPExcel_Worksheet_PageSetup::PAPERSIZE_A4);  
$objExcel->setActiveSheetIndex(0);  
$timestamp = time();  
$ex = "2007";
if($ex == '2007') { //导出excel2007文档  
    header('Content-Type: application/vnd.openxmlformats-officedocument.spreadsheetml.sheet');  
    header('Content-Disposition: attachment;filename="links_out'.$timestamp.'.xlsx"');  
    header('Cache-Control: max-age=0');  
    $objWriter = PHPExcel_IOFactory::createWriter($objExcel, 'Excel2007');  
    $objWriter->save('php://output');  
    exit;  
} else {  //导出excel2003文档  
    header('Content-Type: application/vnd.ms-excel');  
    header('Content-Disposition: attachment;filename="links_out'.$timestamp.'.xls"');  
    header('Cache-Control: max-age=0');  
    $objWriter = PHPExcel_IOFactory::createWriter($objExcel, 'Excel5');  
    $objWriter->save('php://output');  
    exit;  
}  
 
}