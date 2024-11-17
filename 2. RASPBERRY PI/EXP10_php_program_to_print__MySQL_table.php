<!DOCTYPE html>
<html>
<head>
<meta http-equiv="refresh" content="5">
<title>Table: dhtdata</title>
</head>
<body>
<center>
<h1>Naganandana - 2021A7PS0215U</h1>
<h2>MySQL Database: iotdata</h2>
<h2>MySQL Table: dhtdata</h2>
<table border="1" width="100%" cellspacing="0">
<tr>
<th>ID</th>
<th>Date</th>
<th>Time</th>
<th>Humidity</th>
<th>Temperature</th>
</tr>
<?php

error_reporting(E_ALL); // done to check errors or warnings
ini_set('display_errors', 1); 

$host = "localhost";
$user = "iot_user";
$pass = "iot@1122";
$db = "iotdata"; // replace this with your database name from phpMyAdmin
$con = mysqli_connect($host,$user,$pass,$db);
$sql = "select * from dhtdata order by id desc"; // replace dhtdata with your table name 
$result = mysqli_query($con,$sql);
while($row = mysqli_fetch_array($result)){
 echo "<tr>";
 echo "<td>".$row['id']."</td>";
 echo "<td>".$row['date']."</td>";
 echo "<td>".$row['time']."</td>";
 echo "<td>".$row['humidity']."</td>";
 echo "<td>".$row['temperature']."</td>";
 echo "</tr>";
}
?>
</table>
</center>
</body>
</html>