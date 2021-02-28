//пин tx -->rx3
//пин rx -->tx3

void setup()  {
  Serial.begin(230400); 
  Serial3.begin(230400);
}

void loop() { 
  if (Serial3.available()) {  
    char c = Serial3.read();
    
    switch (c){
      case 'X':Serial.println("🡽");; 
        break;
      case 'P':Serial.println("🡾");
        break;
      case 'V':Serial.println("🡿"); 
        break;
      case 'B':Serial.println("🡼");;
        break;
      case 'N':Serial.println("🡹");
        break;
      case 'M':Serial.println("🡻");
        break;
      case 'Z':Serial.println("🡺"); ;
        break;
      case 'L':Serial.println("🡸");;
        break;
      case 'W':Serial.println("W");
        break;
      case '0':Serial.println("0");
    }
  }
}
