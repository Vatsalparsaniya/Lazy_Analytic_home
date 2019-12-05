const char MAIN_page[] PROGMEM = R"=====(

<!DOCTYPE html>
<html lang="en">
<head>
	<title>LAZY ANALYTIC HOME</title>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
<!--===============================================================================================-->	
	<link rel="stylesheet" type="text/css" href="css/main.css">
<!--===============================================================================================-->
</head>
<style>
	

/*//////////////////////////////////////////////////////////////////
[ FONT ]*/


@font-face {
  font-family: Poppins-Regular;
  src: url('../fonts/poppins/Poppins-Regular.ttf'); 
}

@font-face {
  font-family: Poppins-Bold;
  src: url('../fonts/poppins/Poppins-Bold.ttf'); 
}

/*//////////////////////////////////////////////////////////////////
[ RESTYLE TAG ]*/
* {
	margin: 0px; 
	padding: 0px; 
	box-sizing: border-box;
}

body, html {
	height: 100%;
	font-family: sans-serif;
}

/* ------------------------------------ */
a {
	margin: 0px;
	transition: all 0.4s;
	-webkit-transition: all 0.4s;
  -o-transition: all 0.4s;
  -moz-transition: all 0.4s;
}

a:focus {
	outline: none !important;
}

a:hover {
	text-decoration: none;
}

/* ------------------------------------ */
h1,h2,h3,h4,h5,h6 {margin: 0px;}

p {margin: 0px;}

ul, li {
	margin: 0px;
	list-style-type: none;
}


/* ------------------------------------ */
input {
  display: block;
	outline: none;
	border: none !important;
}

textarea {
  display: block;
  outline: none;
}

textarea:focus, input:focus {
  border-color: transparent !important;
}

/* ------------------------------------ */
button {
	outline: none !important;
	border: none;
	background: transparent;
}

button:hover {
	cursor: pointer;
}

iframe {
	border: none !important;
}


/*//////////////////////////////////////////////////////////////////
[ Table ]*/

.limiter {
  width: 100%;
  margin: 0 auto;
}

.container-table100 {
  width: 100%;
  min-height: 100vh;
  background: #c4d3f6;

  display: -webkit-box;
  display: -webkit-flex;
  display: -moz-box;
  display: -ms-flexbox;
  display: flex;
  align-items: center;
  justify-content: center;
  flex-wrap: wrap;
  padding: 33px 30px;
}

.wrap-table100 {
  width: 960px;
  border-radius: 10px;
  overflow: hidden;
}

.table {
  width: 100%;
  display: table;
  margin: 0;
}

@media screen and (max-width: 768px) {
  .table {
    display: block;
  }
}

.row {
  display: table-row;
  background: #fff;
}

.row.header {
  color: #ffffff;
  background: #6c7ae0;
}

@media screen and (max-width: 768px) {
  .row {
    display: block;
  }

  .row.header {
    padding: 0;
    height: 0px;
  }

  .row.header .cell {
    display: none;
  }

  .row .cell:before {
    font-family: Poppins-Bold;
    font-size: 12px;
    color: #808080;
    line-height: 1.2;
    text-transform: uppercase;
    font-weight: unset !important;

    margin-bottom: 13px;
    content: attr(data-title);
    min-width: 98px;
    display: block;
  }
}

.cell {
  display: table-cell;
}

@media screen and (max-width: 768px) {
  .cell {
    display: block;
  }
}

.row .cell {
  font-family: Poppins-Regular;
  font-size: 15px;
  color: #666666;
  line-height: 1.2;
  font-weight: unset !important;

  padding-top: 20px;
  padding-bottom: 20px;
  border-bottom: 1px solid #f2f2f2;
}

.row.header .cell {
  font-family: Poppins-Regular;
  font-size: 18px;
  color: #fff;
  line-height: 1.2;
  font-weight: unset !important;

  padding-top: 19px;
  padding-bottom: 19px;
}

.row .cell:nth-child(1) {
  width: 360px;
  padding-left: 40px;
}

.row .cell:nth-child(2) {
  width: 160px;
}

.row .cell:nth-child(3) {
  width: 250px;
}

.row .cell:nth-child(4) {
  width: 190px;
}


.table, .row {
  width: 100% !important;
}

.row:hover {
  background-color: #ececff;
  cursor: pointer;
}

@media (max-width: 768px) {
  .row {
    border-bottom: 1px solid #f2f2f2;
    padding-bottom: 18px;
    padding-top: 30px;
    padding-right: 15px;
    margin: 0;
  }
  
  .row .cell {
    border: none;
    padding-left: 30px;
    padding-top: 16px;
    padding-bottom: 16px;
  }
  .row .cell:nth-child(1) {
    padding-left: 30px;
  }
  
  .row .cell {
    font-family: Poppins-Regular;
    font-size: 18px;
    color: #555555;
    line-height: 1.2;
    font-weight: unset !important;
  }

  .table, .row, .cell {
    width: 100% !important;
  }
}
</style>
<body>
	
	<div class="limiter">
		<div class="container-table100">
			<div class="wrap-table100">
					<div class="table">

						<div class="row header">
							<div class="cell">
								Name
							</div>
							<div class="cell">
								Data
							</div>
							<div class="cell">
								Unit
							</div>
						</div>

						<div class="row">
							<div class="cell" data-title="Full Name">
								Analog Value - Gas Sensor
							</div>
							<div class="cell" data-title="Data">
							<span id="Analogvalue">0</span>
							</div>
							<div class="cell" data-title="Unit">
								-
							</div>
						</div>

						<div class="row">
							<div class="cell" data-title="Full Name">
								O/P Voltage of Gas Sensor
							</div>
							<div class="cell" data-title="Data">
							<span id="Volt">0</span>
							</div>
							<div class="cell" data-title="Unit">
								V
							</div>
							
						</div>

						<div class="row">
							<div class="cell" data-title="Full Name">
								Ro-resistor value
							</div>
							<div class="cell" data-title="Data">
							<span id="Ro-resistor">0</span></h1>
							</div>
							<div class="cell" data-title="Unit">
								Ohm
							</div>
							
						</div>

						<div class="row">
							<div class="cell" data-title="Full Name">
								H2 - Gas
							</div>
							<div class="cell" data-title="Data">
							<span id="H2-Gas">0</span>
							</div>
							<div class="cell" data-title="Unit">
								PPM
							</div>
							
						</div>

						<div class="row">
							<div class="cell" data-title="Full Name">
								LPG 
							</div>
							<div class="cell" data-title="Data">
							<span id="LPG">0</span>
							</div>
							<div class="cell" data-title="Unit">
								PPM
							</div>
							
						</div>

						<div class="row">
							<div class="cell" data-title="Full Name">
								CO - Gas
							</div>
							<div class="cell" data-title="Data">
							<span id="CO-GAS">0</span>
							</div>
							<div class="cell" data-title="Unit">
								PPM
							</div>
							
						</div>

						<div class="row">
							<div class="cell" data-title="Full Name">
								Alcohol
							</div>
							<div class="cell" data-title="Data">
							<span id="ALCOHOL">0</span>
							</div>
							<div class="cell" data-title="Unit">
								PPM
							</div>
							
						</div>

						<div class="row">
							<div class="cell" data-title="Full Name">
								Propane
							</div>
							<div class="cell" data-title="Data">
							<span id="Propane">0</span>
							</div>
							<div class="cell" data-title="Unit">
								PPM
							</div>
							
						</div>
						<div class="row">
							<div class="cell" data-title="Full Name">
								Humidity
							</div>
							<div class="cell" data-title="Data">
							<span id="Humidity">0</span>
							</div>
							<div class="cell" data-title="Unit">
								%
							</div>
							
						</div>
						<div class="row">
							<div class="cell" data-title="Full Name">
								Temperature in Celcius
							</div>
							<div class="cell" data-title="Data">
							<span id="Temperatureinc">0</span>
							</div>
							<div class="cell" data-title="Unit">
								°C
							</div>
							
						</div>
						<div class="row">
							<div class="cell" data-title="Full Name">
								Temperature in Farenheit
							</div>
							<div class="cell" data-title="Data">
							<span id="Temperatureinf">0</span>
							</div>
							<div class="cell" data-title="Unit">
								°F
							</div>
							
						</div>
						<div class="row">
							<div class="cell" data-title="Full Name">
								Heat Index in Celcius
							</div>
							<div class="cell" data-title="Data">
							<span id="HeatIndexinc">0</span>
							</div>
							<div class="cell" data-title="Unit">
								°C
							</div>
							
						</div>
						<div class="row">
							<div class="cell" data-title="Full Name">
								Heat Index in Farenheit
							</div>
							<div class="cell" data-title="Data">
							<span id="HeatIndexinf">0</span>
							</div>
							<div class="cell" data-title="Unit">
								°F
							</div>
							
						</div>

					</div>
			</div>
		</div>
	</div>
<script>
   
setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getData();
}, 1000); //2000mSeconds update rate

function getData() {

  var data = new XMLHttpRequest();
  data.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
	var str = this.responseText;
      	var arrr = str.split(",")
      	document.getElementById("Analogvalue").innerHTML =arrr[0];
	document.getElementById("Volt").innerHTML =arrr[1];
	document.getElementById("Ro-resistor").innerHTML =arrr[2];
	document.getElementById("H2-Gas").innerHTML =arrr[3];
	document.getElementById("LPG").innerHTML =arrr[4];
	document.getElementById("CO-GAS").innerHTML =arrr[5];
	document.getElementById("ALCOHOL").innerHTML =arrr[6];
	document.getElementById("Propane").innerHTML =arrr[7];
	document.getElementById("Humidity").innerHTML =arrr[8];
	document.getElementById("Temperatureinc").innerHTML =arrr[9];
	document.getElementById("Temperatureinf").innerHTML =arrr[10];
	document.getElementById("HeatIndexinc").innerHTML =arrr[11];
	document.getElementById("HeatIndexinf").innerHTML =arrr[12];
    }
  };
  data.open("GET", "readData", true);
  data.send();
}
</script>
</body>
</html>


)=====";
