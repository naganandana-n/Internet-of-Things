<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="refresh" content="10"> <!-- Auto-refresh every 5 seconds -->
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
        .controls {
            margin: 20px 0;
        }
        .controls input[type="text"] {
            padding: 10px;
            font-size: 1em;
            border: 1px solid #ccc;
            border-radius: 5px;
            width: 200px;
        }
        .controls button {
            padding: 10px 20px;
            margin-left: 10px;
            font-size: 1em;
            font-weight: bold;
            color: #fff;
            background-color: #0073b1;
            border: none;
            border-radius: 5px;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s;
        }
        .controls button:hover {
            background-color: #005f8c;
            transform: scale(1.05);
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

        <!-- Date Controls -->
        <div class="controls">
            <label for="date">Enter Date (DD-MM-YYYY):</label>
            <input type="text" id="date" name="date" placeholder="DD-MM-YYYY">
            <button onclick="filterData()">Filter Data</button>
            <button onclick="clearDate()">Clear Date</button>
        </div>

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
            $con = mysqli_connect($host, $user, $pass, $db);

            // Check if a date filter is applied
            $dateFilter = isset($_GET['date']) ? $_GET['date'] : null;

            if ($dateFilter) {
                // Query to fetch data for the selected date
                $sql = "SELECT * FROM dhtdata WHERE date = '$dateFilter' ORDER BY id DESC";
            } else {
                // Default query to fetch all data
                $sql = "SELECT * FROM dhtdata ORDER BY id DESC";
            }

            $result = mysqli_query($con, $sql);
            while ($row = mysqli_fetch_array($result)) {
                echo "<tr>";
                echo "<td>" . $row['id'] . "</td>";
                echo "<td>" . $row['date'] . "</td>";
                echo "<td>" . $row['time'] . "</td>";
                echo "<td>" . $row['humidity'] . "</td>";
                echo "<td>" . $row['temperature'] . "</td>";
                echo "</tr>";
            }
            ?>
        </table>
    </div>

    <script>
        function filterData() {
            const dateInput = document.getElementById('date').value;
            if (dateInput) {
                window.location.href = `?date=${dateInput}`;
            } else {
                alert('Please enter a date in DD-MM-YYYY format.');
            }
        }

        function clearDate() {
            window.location.href = window.location.pathname; // Reload the page without query parameters
        }
    </script>
</body>
</html>