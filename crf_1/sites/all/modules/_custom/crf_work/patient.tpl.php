<?php
//  print_r($team_arr);
//  print_r($row);
  $genders[0] = '男';
  $genders[1] = '女';
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
    <label>受试者姓名：</label> <span><?php echo $row['u_name'] ?></span>
  </div>
  <div>
    <label>受试者姓名缩写：</label> <span><?php echo $row['p_name'] ?></span>
  </div>
  <div>
    <label>受试者出生日期：</label> <span><?php echo $row['p_birthday'] ?></span>
  </div>
  <div>
    <label>受试者年龄：</label> <span><?php echo $row['u_age'] ?></span>
  </div>
  <div>
    <label>受试者体重：</label> <span><?php echo $row['u_weight'] ?>kg</span>
  </div>
  <div>
    <label>受试者性别：</label> <span><?php echo $genders[$row['u_gender']] ?></span>
  </div>
  <div>
    <label>受试者身份证号：</label> <span><?php echo $row['u_card_id'] ?></span>
  </div>
  <div>
    <label>受试者地址：</label> <span><?php echo $row['u_address'] ?></span>
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
  <?php    
    }
  ?>
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