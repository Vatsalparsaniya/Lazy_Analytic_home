#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <MQUnifiedsensor.h>  //Include the library
#include "DHT.h"
#include "index.h";


#define DHTTYPE DHT11  // DHT 11
#define DHTPIN 14
#define pin A0  //Analog input 0 of your arduino for MQ-2
#define type 2  // MQ-2

ESP8266WebServer server(80);

//Enter your SSID and PASSWORD
const char *ssid = "vatsal__1";  //a Lannister always surfs the net
const char *password = "qwertyuiop";

void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}

float Ro, H2, LPG, CO, Alcohol, Propane, Benzene, h, t, f, hif ,hic , analogreadvalue, voltvalue;   //Variables

void handleData() {
 String str_arr = String(analogreadvalue);
 str_arr += "," + String(voltvalue);
 str_arr += "," + String(Ro);
 str_arr += "," + String(H2);
 str_arr += "," + String(LPG);
 str_arr += "," + String(CO);
 str_arr += "," + String(Alcohol);
 str_arr += "," + String(Propane);
 str_arr += "," + String(h);
 str_arr += "," + String(t);
 str_arr += "," + String(f);
 str_arr += "," + String(hic);
 str_arr += "," + String(hif);
 server.send(200, "text/plane", str_arr);//Send ADC value only to client ajax request
}

MQUnifiedsensor MQ2(pin, type);
DHT dht(DHTPIN, DHTTYPE);



void setup(){
    Serial.begin(9600);
    MQ2.inicializar();
    dht.begin();

    Serial.println();
    Serial.println("Booting Sketch...");
    
    WiFi.mode(WIFI_STA); //Connectto your wifi
    WiFi.begin(ssid, password);

    Serial.println("Connecting to ");
    Serial.print(ssid);

    //Wait for WiFi to connect
    while(WiFi.waitForConnectResult() != WL_CONNECTED){      
        Serial.print(".");
    }
    
    //If connection successful show IP address in serial monitor
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());  //IP address assigned to your ESP
//----------------------------------------------------------------
 
  server.on("/", handleRoot);      //This is display page
  server.on("/readData", handleData);//To get update of ADC Value only
  server.begin();                  //Start server
  Serial.println("HTTP server started");

}


int flag = 1 ;


void loop(){
     server.handleClient();
     delay(2000); // wait few seconds
     h = dht.readHumidity();
     t = dht.readTemperature();
     f = dht.readTemperature(true);

     // Check if any reads failed and exit early (to try again).
     if (isnan(h) || isnan(t) || isnan(f)) {
         Serial.println(F("Failed to read from DHT sensor!"));
         return;
     }
     
     // Compute heat index in Fahrenheit (the default)
     hif = dht.computeHeatIndex(f, h);
     // Compute heat index in Celsius (isFahreheit = false)
     hic = dht.computeHeatIndex(t, h, false);
     
     if(flag){
            delay(5000);
            Serial.print(",Analog Value,");
            Serial.print("Volt(V),");
            Serial.print("R0(Ohm),");
            Serial.print("H2(ppm),");
            Serial.print("LPG(ppm),");
            Serial.print("CO(ppm),");
            Serial.print("Alcohol(ppm),");
            Serial.print("Propane(ppm),");
            Serial.print("Humidity(%),");
            Serial.print("Temperature(°C),");
            Serial.print("Temperature(°F),");
            Serial.print("Heat index in(°C),");
            Serial.println("Heat index in(°F),");
            flag = 0;
      }
      
      MQ2.update(); // Update data, the arduino will be read the voltaje in the analog pin

      Ro = MQ2.getR0();
      H2 =  MQ2.readSensor("H2");                               // Return H2 concentration in PPM
      LPG =  MQ2.readSensor("LPG");                             // Return LPG concentration in PPM
      CO =  MQ2.readSensor("CO");                               // Return CO concentration in PPM
      Alcohol =  MQ2.readSensor("Alcohol");                     // Return Alcohol concentration in PPM
      Propane =  MQ2.readSensor("Propane");                     // Return Propane concentration in PPM
      analogreadvalue = analogRead(A0);
      voltvalue = MQ2.getVoltage(false);
      Serial.print(",");
      Serial.print(analogreadvalue);Serial.print(",");
      Serial.print(voltvalue);Serial.print(","); 
      Serial.print(Ro);Serial.print(","); 
      Serial.print(H2,2);Serial.print(",");
      Serial.print(LPG,2);Serial.print(",");
      Serial.print(CO,2);Serial.print(",");
      Serial.print(Alcohol,2);Serial.print(",");
      Serial.print(Propane,2);Serial.print(",");
      Serial.print(h);Serial.print(",");
      Serial.print(t);Serial.print(",");
      Serial.print(f);Serial.print(",");
      Serial.print(hic);Serial.print(",");
      Serial.println(hif);
      
}
