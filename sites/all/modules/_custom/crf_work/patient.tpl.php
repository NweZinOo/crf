<?php
//  print_r($team_arr);
//  print_r($row);
?>
<div id="patient">
  <div>
    <label>实验中心编号：</label> <span><?php echo $row['hospital_no'] ?></span>
  </div>
  <div>
    <label>实验中心名称：</label> <span><?php global $hospital_name_arr; echo $hospital_name_arr[$row['hospital_no']] ?></span>
  </div>
<!--  <div>
    <label>筛选号：</label> <span><?php echo $row['sift'] ?></span>
  </div>-->
  <div>
    <label>受试者姓名缩写：</label> <span><?php echo $row['p_name'] ?></span>
  </div>
  <div>
    <label>受试者出生日期：</label> <span><?php echo $row['p_birthday'] ?></span>
  </div>
  <div>
    <label>受试者身份证号：</label> <span><?php echo $row['p_id_card'] ?></span>
  </div>
  <div>
    <label>受试者是否获得知情同意书：</label> <span><?php echo $approved_arr[$row['approved']] ?></span>
  </div>

  <?php 
    if ($row['approved'] == 0) {
  ?>
  <div>
    <label>知情同意日期：</label> <span><?php echo $row['approved_time'] ?></span>
  </div>
  <div>
    <label>研究医生：</label> <span><?php echo $row['editor'] ?></span>
  </div>
  <div>
    <label>手机号：</label> <span><?php echo $row['phone'] ?></span>
  </div>
  <div>
    <label>备用手机号：</label> <span><?php echo $row['phone_1'] ?></span>
  </div>
  <?php    
    }
  ?>

  <div style="clear: both;">--------------------------<span style="color: red; font-size: 1.2em;">随机结果</span> -------------------------- </div>

  <div>
    <label>受试者分组：</label> <span><?php echo $team_arr[$row['team']] ?></span>
  </div>
  <div>
    <label>随机号：</label> <span><?php echo _add_rand($row['p_uid']) ?></span>
  </div>
  <div>
    <label>随机时间：</label> <span><?php echo $row['apply_time'] ?></span>
  </div>
</div>

<div style="margin-left: 20px;">
  <input type="submit" value="进入列表" onclick="location.href = '<?php echo url("crf_list");?>'"/>  <input type="submit" value="打印" onclick="window.print();"/>
</div>
<style type="text/css">
  #patient div {
    margin: 10px;
  }
  #patient {
    margin: 20px;
    border-bottom: 1px solid #ddd;
    border-top: 1px solid #ddd;
    width: 500px;
  }
  #patient label {
    font-weight: bold;
    width: 185px;
    display: block;
    float: left;
  }
</style>