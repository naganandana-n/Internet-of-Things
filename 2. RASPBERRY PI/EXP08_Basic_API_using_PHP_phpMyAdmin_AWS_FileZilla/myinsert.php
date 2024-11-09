<?php // marks the beginning of a php program

// Load the configuration file
include 'config.php'; // Load confidential details

// THIS IS A BASIC API PROGRAM

// PART 1 - printing connect message
// Send this file via FileZilla to the AWS instance
// put this file [myinsert.php] in the /var/www/html folder
// go to ipaddress/myinsert.php to see result:
// Hi Naga. You are connected to the AWS database!

// PART 2 - using API call to put humidity and temperature into database
// http://ipaddress/myinsert.php?h=10&t=20
// ? onwards are the variables being sent using GET method

// PART 3 - putting the data into the database (phpMyAdmin - free tool to handle mysql over the web)
// if you put empty data ie, ipaddress/myinsert.php -> will push null data to the database
// How do we prevent that -> isset() [IMP!!]

// [NOTE] GET vs POST method:
// GET: sends the value, but shows it also (on the link)
// POST: send the value, but DOESN'T SHOW! (eg: for passwords - dont wanna show!)
// see midsem answer key for more differences

date_default_timezone_set("Asia/Dubai"); // sets timezone to Dubai timezone

// every php variable starts with a dollar ($) sign

// THESE WILL BE TAKEN FROM config.php 
// $host = "";
// $user = "";
// $pass = "";
// $db = ""; // database name [NOT TABLE NAME!!] -> a database can have many tables

$con = mysqli_connect($host, $user, $pass, $db); // function to connect to the database

// check if connected or not:
if ($con){

    if (isset($_GET['h']) && isset($_GET['t'])){ // PART 3
    // PART 1
    echo "Hi Naga. You are connected to the AWS database!"; // print command in php
    echo "<br>"; // linebreak - nextline
    echo "<br>"; // using 2 in a row - prints empty line

    // PART 2
    $hum = $_GET['h']; // 'h' is the variable being used in the API call
    $temp = $_GET['t'];
    $date = date("d-m-Y"); // checking online for the different formats (date/month/year)
    $time = date("H:i:s"); // check online for different formats

    echo "Humidity: "; echo $hum; // prints -> Humidity: 10
    echo "<br>";
    echo "Temperature: " . $temp; // easier way of printing
    echo "<br>";
    echo "Date: " . $date;
    echo "<br>";
    echo "Time: " . $time;
    echo "<br>";
    echo "<br>"; // printing empty line (OCD)

    // PART 3
    // this inserts data into the database on phpMyAdmin
    $sql = "insert into dhtdata(date, time, humidity, temperature) values ('$date', '$time', '$hum', '$temp')";
    
    // check if data was inserted:
    if (mysqli_query($con, $sql)){ // [IMP!!] mysqli_query -> sends the query, and returns true / false [IMP!!]
        echo "Congratulations! Data entered into database.";
    }
    else{
        echo "Sorry! Data is not inserted.";
    }
}
else{
    echo "No data available!"; // checking with isset() to see if data was sent -> to prevent null entries to database
}
}
else{
    echo "Not connected to the AWS database!";
}

// marks the end of a php program
?> 