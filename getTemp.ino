// gets the temperature to display on the webside
String GetTemp(){
  // get temperature in tenths °C
  int16_t c_temp = get_temperature();
  


  // place a "-" in front of the char "c_buffer"
  if(c_temp < 0) {   // if temperature < 0 °C
    c_temp = abs(c_temp);  // absolute value
    sprintf(c_buffer, "-%02u.%1u%cC ", c_temp / 10, c_temp % 10, 176);
  }
  else {
    if (c_temp >= 1000)    // if temperature >= 100.0 °C
      sprintf(c_buffer, "%03u.%1u%cC", c_temp / 10, c_temp % 10, 176);
    else
      sprintf(c_buffer, " %02u.%1u%cC", c_temp / 10, c_temp % 10, 176);
  }

  return String( c_buffer );
}

// make you able to calculate if with the temperature
float rTemp(){

  float floatTempC = GetTemp().toFloat(); // convert the string to a flot
  Serial.println(floatTempC);
  return floatTempC;
  
}

// gets the raw °C temperature from the DS1621
int16_t get_temperature() {
  
  Wire.beginTransmission(DS1621_ADDRESS); // connect to DS1621 (send DS1621 address)
  Wire.write(0xAA);                       // read temperature command
  Wire.endTransmission(false);            // send repeated start condition
  Wire.requestFrom(DS1621_ADDRESS, 2);    // request 2 bytes from DS1621 and release I2C bus at end of reading
  
  uint8_t t_msb = Wire.read();            // read temperature MSB register
  uint8_t t_lsb = Wire.read();            // read temperature LSB register
 
  // calculate full temperature (raw value)
  int16_t raw_t = (int8_t)t_msb << 1 | t_lsb >> 7;
  // convert raw temperature value to tenths °C
  raw_t = raw_t * 10/2;
  //Serial.println(raw_t / 10 + "." + raw_t % 10);
  return raw_t;

}
