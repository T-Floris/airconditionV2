void confTempDetect() {

    // this is used to not waste resources
    float c_temp = rTemp();

    /*  if the rum temperatur is the satme as the set temperatur
     *  the green led will light up
     */
    if (c_temp == setConfTemp){
      digitalWrite(output25, LOW); //Blue
      digitalWrite(output26, HIGH); //Green
      digitalWrite(output27, LOW); //Red
      Serial.println("test");
    }

    /*  if the rum temperatur is lower then the set temperatur
     *  the green and the red led will light up
     *  and the temperatur will rise
     */
    else if (c_temp < setConfTemp){
      digitalWrite(output25, LOW); //Blue
      digitalWrite(output26, HIGH); //Green
      digitalWrite(output27, HIGH); //Red  
      Serial.println("turn temp op ");  
      
    }
    
    /*  if the rum temperatur is lower then the set temperatur
     *  the green and the blue led will light up
     *  and the temperatur will fall
     */
    else if (c_temp > setConfTemp){
      digitalWrite(output25, HIGH); //Blue
      digitalWrite(output26, HIGH); //Green
      digitalWrite(output27, LOW); //Red   
      Serial.println("turn temp down "); 
    }


    
    //ERROR  
    else{
      digitalWrite(output25, HIGH); //Blue
      digitalWrite(output26, HIGH); //Green
      digitalWrite(output27, HIGH); //Red
    }
}
