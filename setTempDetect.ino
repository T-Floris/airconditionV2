void tempDetect() {

    float c_temp = rTemp();

    if (c_temp == setConfTemp){
      digitalWrite(output25, LOW); //Blue
      digitalWrite(output26, HIGH); //Green
      digitalWrite(output27, LOW); //Red
      Serial.println("test");
    }
    
    //turn temp op (red lamp)
    else if (c_temp < setConfTemp){
      digitalWrite(output25, LOW); //Blue
      digitalWrite(output26, HIGH); //Green
      digitalWrite(output27, HIGH); //Red  
      Serial.println("turn temp op ");  
      
    }
    
    //turn temp dawn (blue lamp)
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
