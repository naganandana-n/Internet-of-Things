<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>LED Control</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: center;
            height: 100vh;
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
        }
        h1 {
            font-size: 2em;
            margin-bottom: 20px;
        }
        .buttons {
            display: flex;
            justify-content: center;
            gap: 20px;
        }
        .buttons a {
            text-decoration: none;
            padding: 10px 30px;
            border-radius: 5px;
            color: #fff;
            font-weight: bold;
            font-size: 1.2em;
            transition: background-color 0.3s, transform 0.2s;
        }
        .buttons a.on {
            background-color: #4caf50; /* Green for ON */
        }
        .buttons a.off {
            background-color: #f44336; /* Red for OFF */
        }
        .buttons a:hover {
            transform: scale(1.05);
            opacity: 0.9;
        }
        .message {
            margin-top: 20px;
            font-size: 1.2em;
            color: #333;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>AWS server controlled LED</h1>
        <p>Click a button to turn the LED ON or OFF and store the action in the database.</p>
        <div class="buttons">
            <a href="?status=on" class="on">ON</a>
            <a href="?status=off" class="off">OFF</a>
        </div>
        
        <?php
        if (isset($_GET['status'])) {
            // Set timezone
            date_default_timezone_set("Asia/Dubai");
            
            // Database credentials
            $host = "localhost";
            $user = "iot_user";
            $pass = "iot@1122";
            $db = "myled";

            // Create connection
            $con = mysqli_connect($host, $user, $pass, $db);

            // Check connection
            if (!$con) {
                die("<p class='message' style='color: red;'>Database connection failed: " . mysqli_connect_error() . "</p>");
            }

            // Get the current date, time, and status
            $date = date("d-m-Y");
            $time = date("H:i:s");
            $status = $_GET['status'];

            // Insert into database
            $sql = "INSERT INTO led1 (date, time, status) VALUES ('$date', '$time', '$status')";
            
            if (mysqli_query($con, $sql)) {
                echo "<p class='message'>LED status '$status' recorded successfully at $time on $date.</p>";
            } else {
                echo "<p class='message' style='color: red;'>Error: " . mysqli_error($con) . "</p>";
            }

            // Close connection
            mysqli_close($con);
        }
        ?>
    </div>
</body>
</html>