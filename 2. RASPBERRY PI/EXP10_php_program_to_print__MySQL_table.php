<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Table: dhtdata</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: center;
            min-height: 100vh;
            margin: 0;
            background-color: #f4f4f4;
        }
        .container {
            text-align: center;
            padding: 20px;
            border: 2px solid #333;
            border-radius: 8px;
            background-color: #fff;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            width: 90%;
            max-width: 1200px;
        }
        h1 {
            font-size: 2em;
            margin-bottom: 10px;
        }
        h2 {
            font-size: 1.2em;
            margin: 5px 0;
            color: #555;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 20px;
        }
        th, td {
            padding: 10px;
            text-align: center;
            border: 1px solid #ccc;
        }
        th {
            background-color: #0073b1;
            color: #fff;
        }
        tr:nth-child(even) {
            background-color: #f9f9f9;
        }
        tr:hover {
            background-color: #f1f1f1;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Naganandana - 2021A7PS0215U</h1>
        <h2>MySQL Database: iotdata</h2>
        <h2>MySQL Table: dhtdata</h2>
        <table>
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
    </div>
</body>
</html>