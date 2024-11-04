<html>
<title>LED Control</title>
<center>
<h1> LED Control </h1>
<a href="?led=on"><button>LED ON</button></a>
<a href="?led=off"><button>LED OFF</button></a>
</center>
</html>
<?php
if(isset($_GET['led'])){
$data = $_GET['led'];
if($data == "on"){
exec('sh on.sh');
}
if($data == "off"){
exec('sh off.sh');
}
}
?>