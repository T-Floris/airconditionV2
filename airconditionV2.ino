// Load Wi-Fi library
#include <WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <Wire.h>  


WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

// Replace with your network credentials

const char* ssid = "HomeBox_83A0_2.4G";
const char* password = "1c7haa34e";
//const char* ssid = "E308";
//const char* password = "98806829";

char c_buffer[8], f_buffer[8];

// Set web server port number to 80
WiFiServer server(80);

//float setTemp = 21.5;
float setConfTemp = 21.5;
float setSaveTemp = 24.0;

// Variable to store the HTTP request
String header;

bool confActive = false;
bool saveActive = false;

//int[] na;

// Auxiliar variables to store the current output state
String output25State = "off";
String output26State = "off";
String output27State = "off";

// Assign output variables to GPIO pins
const int output25 = 25;
const int output26 = 26;
const int output27 = 27;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

#define DS1621_ADDRESS  0x48

void setup() {
  Serial.begin(115200);

  Wire.begin();           // join i2c bus
  // initialize DS1621 sensor
  Wire.beginTransmission(DS1621_ADDRESS); // connect to DS1621 (send DS1621 address)
  Wire.write(0xAC);                       // send configuration register address (Access Config)
  Wire.write(0);                          // perform continuous conversion
  Wire.beginTransmission(DS1621_ADDRESS); // send repeated start condition
  Wire.write(0xEE);                       // send start temperature conversion command
  Wire.endTransmission();   
  
  // Initialize the output variables as outputs
  pinMode(output25, OUTPUT);
  pinMode(output26, OUTPUT);
  pinMode(output27, OUTPUT);
  // Set outputs to LOW
 digitalWrite(output25, LOW);
  digitalWrite(output26, LOW);
  digitalWrite(output27, LOW);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();


     
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            //////////////////////////set confTemp/////////////////////////////////

            if (header.indexOf("GET /confTemp/up") >= 0) {
              setConfTempUp();
              header = "";
            }
            if (header.indexOf("GET /confTemp/down") >= 0) {
              setConfTempDown();
              header = "";
            }

            /////////////////////////Set saveTemp///////////////////////////////

            /* Set saveTemp  */
            if (header.indexOf("GET /saveTemp/up") >= 0) {
              setSaveTempUp();
              header = "";
            }
            if (header.indexOf("GET /saveTemp/down") >= 0) {
              setSaveTempDown();
              header = "";
            }


            /////////////////////////Activate and deactivate/////////////////////////
            if (header.indexOf("GET /conf/activate") >= 0) {
              confActive = true;
              saveActive = false;  
            }

            if (header.indexOf("GET /conf/deactivate") >= 0) {
              confActive = false;       
              //sparA = false;
            }

            /* define spar temp active and deactive */
            if (header.indexOf("GET /save/activate") >= 0) {
              confActive = false;
              saveActive = true;  
            }

            if (header.indexOf("GET /save/deactivate") >= 0) {
              //confA = false;
              saveActive = false;
       
            }

            /////////////////////////////set mode detect/////////////////////////////
            // comfortable mode
            if(confActive == true && saveActive == false){
              confTempDetect();              
            }
            // save mode
            else if(confActive == false && saveActive == true){
              saveTempDetect();              
            }
            // turn off system
            else{
              turnOff();
            }

            
            

            
            ///////////////////////////WebSide Header////////////////////////////////

            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            
            // CSS to style the on/off buttons 
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".flex-parent { display: flex;}");
            client.println(".flex-child { flex: 1; }");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 10px 30px;");
            client.println("text-decoration: none; font-size: 20px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");

            //////////////////////////Tittel, time and temperatur///////////////////////
            
            // Web Page Heading
            client.println("<body><h1>ESP32 Web Server</h1>");

            // Time and temperatur
            client.print("<h2> KL: " + timeHM() + " Temp: " + GetTemp() + "</h2>");

            //////////////////Show and choice temperatur (comfortable)//////////////////

            // display your comfortable temperature
            client.print("<h2>comfortable temperature</h2>");
            client.print("<h5>" + String(setConfTemp) + " " + (char)176 + "C</h3>");

            // activete and deactivate
            client.print("<div class='parent flex-parent'>");
            client.print("<div class='child flex-child'><p><a href=\"/confTemp/up\"><button class=\"button\">+</button></a></p></div>");
            client.print("<div class='child flex-child'><p><a href=\"/confTemp/down\"><button class=\"button\">-</button></a></p></div>");
            client.print("</div>");
          
          /* set temp comfortable */
          client.println("<p><a href=\"/conf/activate\"><button class=\"button\">activate</button></a></p>");
          client.println("<p><a href=\"/conf/deactivate\"><button class=\"button\">deactivate</button></a></p>");

            //////////////////Show and choice temperatur (saving)/////////////////////

            // display your saving temperature
            client.print("<h2>saving temperature</h2>");
            client.print("<h5>" + String(setSaveTemp) + " " + (char)176 + "C</h3>");

            // activete and deactivate
            client.print("<div class='parent flex-parent'>");
            client.print("<div class='child flex-child'><p><a href=\"/saveTemp/up\"><button class=\"button\">+</button></a></p></div>");
            client.print("<div class='child flex-child'><p><a href=\"/saveTemp/down\"><button class=\"button\">-</button></a></p></div>");
            client.print("</div>");

            // set temp save
            client.println("<p><a href=\"/save/activate\"><button class=\"button\">activate</button></a></p>");
            client.println("<p><a href=\"/save/deactivate\"><button class=\"button\">deactivate</button></a></p>");
            
            
            //////////////////////////End of HTML////////////////////////////////////               
 

            client.println("</body></html>");
            
            client.println();
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
