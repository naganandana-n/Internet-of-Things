<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="refresh" content="10"> <!-- Auto-refresh every 10 seconds -->
    <title>Graph: DHT Sensor Data</title>
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
        canvas {
            margin-top: 20px;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Naganandana - 2021A7PS0215U</h1>
        <h2>Graphical Representation of DHT Sensor Data</h2>

        <!-- Date Controls -->
        <div class="controls">
            <label for="date">Enter Date (DD-MM-YYYY):</label>
            <input type="text" id="date" name="date" placeholder="DD-MM-YYYY">
            <button onclick="filterData()">Filter Data</button>
            <button onclick="clearDate()">Clear Date</button>
        </div>

        <!-- Graphs -->
        <canvas id="tempChart" width="800" height="400"></canvas>
        <canvas id="humidityChart" width="800" height="400"></canvas>
    </div>

    <?php
    error_reporting(E_ALL);
    ini_set('display_errors', 1);

    $host = "localhost";
    $user = "iot_user";
    $pass = "iot@1122";
    $db = "iotdata";
    $con = mysqli_connect($host, $user, $pass, $db);

    // Check if a date filter is applied
    $dateFilter = isset($_GET['date']) ? $_GET['date'] : null;

    if ($dateFilter) {
        $sql = "SELECT * FROM dhtdata WHERE date = '$dateFilter' ORDER BY id DESC";
    } else {
        $sql = "SELECT * FROM dhtdata ORDER BY id DESC LIMIT 100"; // Default: Fetch last 100 entries
    }

    $result = mysqli_query($con, $sql);
    $data = [];
    while ($row = mysqli_fetch_assoc($result)) {
        $data[] = $row;
    }
    ?>

    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <script>
        const data = <?php echo json_encode($data); ?>;

        // Extract time, temperature, and humidity data
        const timeLabels = data.map(entry => entry.time);
        const temperatureData = data.map(entry => parseFloat(entry.temperature));
        const humidityData = data.map(entry => parseFloat(entry.humidity));

        // Graph 1: Temperature vs Time
        const tempCtx = document.getElementById('tempChart').getContext('2d');
        new Chart(tempCtx, {
            type: 'line',
            data: {
                labels: timeLabels,
                datasets: [{
                    label: 'Temperature (°C)',
                    data: temperatureData,
                    borderColor: 'rgba(255, 99, 132, 1)',
                    backgroundColor: 'rgba(255, 99, 132, 0.2)',
                    borderWidth: 2,
                    tension: 0.3,
                    fill: true,
                }]
            },
            options: {
                responsive: true,
                plugins: {
                    legend: {
                        position: 'top',
                    },
                },
                scales: {
                    x: {
                        title: {
                            display: true,
                            text: 'Time',
                        }
                    },
                    y: {
                        title: {
                            display: true,
                            text: 'Temperature (°C)',
                        }
                    }
                }
            }
        });

        // Graph 2: Humidity vs Time
        const humidityCtx = document.getElementById('humidityChart').getContext('2d');
        new Chart(humidityCtx, {
            type: 'line',
            data: {
                labels: timeLabels,
                datasets: [{
                    label: 'Humidity (%)',
                    data: humidityData,
                    borderColor: 'rgba(54, 162, 235, 1)',
                    backgroundColor: 'rgba(54, 162, 235, 0.2)',
                    borderWidth: 2,
                    tension: 0.3,
                    fill: true,
                }]
            },
            options: {
                responsive: true,
                plugins: {
                    legend: {
                        position: 'top',
                    },
                },
                scales: {
                    x: {
                        title: {
                            display: true,
                            text: 'Time',
                        }
                    },
                    y: {
                        title: {
                            display: true,
                            text: 'Humidity (%)',
                        }
                    }
                }
            }
        });

        function filterData() {
            const dateInput = document.getElementById('date').value;
            if (dateInput) {
                window.location.href = `?date=${dateInput}`;
            } else {
                alert('Please enter a date in DD-MM-YYYY format.');
            }
        }

        function clearDate() {
            window.location.href = window.location.pathname;
        }
    </script>
</body>
</html>