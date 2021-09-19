void saveTempDetect() {

    
    float c_temp = rTemp();

    /*  
     *   if the rum temperatur is the satme as the set temperatur
     *  the green led will light up
     */
    if (c_temp == setSaveTemp){
      digitalWrite(output25, LOW); //Blue
      digitalWrite(output26, HIGH); //Green
      digitalWrite(output27, LOW); //Red
      Serial.println("same temperatur");
    }

    /*  
     *   if the rum temperatur is lower then the set temperatur
     *  the green and the red led will light up
     *  and the temperatur will rise
     */
    else if (c_temp < setSaveTemp){
      digitalWrite(output25, LOW); //Blue
      digitalWrite(output26, HIGH); //Green
      digitalWrite(output27, HIGH); //Red  
      Serial.println("turn temperatur op");  
      
    }
    
    /*  
     *   if the rum temperatur is lower then the set temperatur
     *  the green and the blue led will light up
     *  and the temperatur will fall
     */
    else if (c_temp > setSaveTemp){
      digitalWrite(output25, HIGH); //Blue
      digitalWrite(output26, HIGH); //Green
      digitalWrite(output27, LOW); //Red   
      Serial.println("turn temperatur down"); 
    }


    
    /*
     * ERROR  
     */
    else{
      digitalWrite(output25, HIGH); //Blue
      digitalWrite(output26, HIGH); //Green
      digitalWrite(output27, HIGH); //Red
    }
}
