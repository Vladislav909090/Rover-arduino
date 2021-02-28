//пин tx -->rx3
//пин rx -->tx3
//схема нумеровки моторов      FD
//                            6||1
//                            5||2
//                            4||3

 int parspeedperiod=50;
 
 #define Motor1_1 42 //FR
 #define Motor1_2 43 //FR
 #define Motor2_1 44 //CR
 #define Motor2_2 45 //CR
 #define Motor3_1 46 //BR
 #define Motor3_2 47 //BR
 #define Motor4_1 48 //BL
 #define Motor4_2 49 //BL
 #define Motor5_1 50 //CL
 #define Motor5_2 51 //CL
 #define Motor6_1 52 //FL
 #define Motor6_2 53 //FL

void setup()  {
  Serial.begin(230400); 
  Serial3.begin(230400);
  
  for (int i=42; i<=53;i++) {
    pinMode(i, OUTPUT);
    digitalWrite (i, LOW);
  }
}

void movewh(char orientation, int speed) { //функция с параметрами куда ехать и с какой скоростью (от 0 до 100)
  if (orientation == 'F') { //вперед
    digitalWrite (Motor1_1, HIGH);
    digitalWrite (Motor1_2, LOW); 
    digitalWrite (Motor2_1, HIGH);
    digitalWrite (Motor2_2, LOW); 
    digitalWrite (Motor3_1, HIGH);
    digitalWrite (Motor3_2, LOW); 
    digitalWrite (Motor4_1, HIGH);
    digitalWrite (Motor4_2, LOW); 
    digitalWrite (Motor5_1, HIGH);
    digitalWrite (Motor5_2, LOW);
    digitalWrite (Motor6_1, HIGH);
    digitalWrite (Motor6_2, LOW);
    delay(speed);    
  } else if (orientation == 'B') { //назад
    digitalWrite (Motor1_1, LOW);
    digitalWrite (Motor1_2, HIGH);  
    digitalWrite (Motor2_1, LOW);
    digitalWrite (Motor2_2, HIGH); 
    digitalWrite (Motor3_1, LOW);
    digitalWrite (Motor3_2, HIGH); 
    digitalWrite (Motor4_1, LOW);
    digitalWrite (Motor4_2, HIGH);
    digitalWrite (Motor5_1, LOW);
    digitalWrite (Motor5_2, HIGH); 
    digitalWrite (Motor6_1, LOW);
    digitalWrite (Motor6_2, HIGH);    
    delay(speed);     
  } else if (orientation == 'R') {  //вправо
    digitalWrite (Motor1_1, LOW);
    digitalWrite (Motor1_2, HIGH); 
    digitalWrite (Motor2_1, LOW);
    digitalWrite (Motor2_2, HIGH); 
    digitalWrite (Motor3_1, LOW);
    digitalWrite (Motor3_2, HIGH); 
    digitalWrite (Motor4_1, HIGH);
    digitalWrite (Motor4_2, LOW); 
    digitalWrite (Motor5_1, HIGH);
    digitalWrite (Motor5_2, LOW); 
    digitalWrite (Motor6_1, HIGH);
    digitalWrite (Motor6_2, LOW); 
    delay(speed);    
  } else if (orientation == 'L') {  //влево
    digitalWrite (Motor1_1, HIGH);
    digitalWrite (Motor1_2, LOW);
    digitalWrite (Motor2_1, HIGH);
    digitalWrite (Motor2_2, LOW); 
    digitalWrite (Motor3_1, HIGH);
    digitalWrite (Motor3_2, LOW); 
    digitalWrite (Motor4_1, LOW);
    digitalWrite (Motor4_2, HIGH);  
    digitalWrite (Motor5_1, LOW);
    digitalWrite (Motor5_2, HIGH); 
    digitalWrite (Motor6_1, LOW);
    digitalWrite (Motor6_2, HIGH);  
    delay(speed);     
  } else if (orientation == 'I') { //вперед налево
    digitalWrite (Motor1_1, HIGH);
    digitalWrite (Motor1_2, LOW);
    digitalWrite (Motor2_1, HIGH);
    digitalWrite (Motor2_2, LOW); 
    digitalWrite (Motor3_1, HIGH);
    digitalWrite (Motor3_2, LOW); 
    digitalWrite (Motor4_1, LOW);
    digitalWrite (Motor4_2, LOW);  
    digitalWrite (Motor5_1, HIGH);
    digitalWrite (Motor5_2, LOW); 
    digitalWrite (Motor6_1, HIGH);
    digitalWrite (Motor6_2, LOW);
    delay(speed);     
  } else if (orientation == 'Y') { //вперед направо
    digitalWrite (Motor1_1, HIGH);
    digitalWrite (Motor1_2, LOW);
    digitalWrite (Motor2_1, HIGH);
    digitalWrite (Motor2_2, LOW); 
    digitalWrite (Motor3_1, LOW);
    digitalWrite (Motor3_2, LOW); 
    digitalWrite (Motor4_1, HIGH);
    digitalWrite (Motor4_2, LOW);
    digitalWrite (Motor5_1, HIGH);
    digitalWrite (Motor5_2, LOW); 
    digitalWrite (Motor6_1, HIGH);
    digitalWrite (Motor6_2, LOW);   
    delay(speed);     
  } else if (orientation == 'T') { //назад налево
    digitalWrite (Motor1_1, LOW);
    digitalWrite (Motor1_2, HIGH);
    digitalWrite (Motor2_1, LOW);
    digitalWrite (Motor2_2, HIGH); 
    digitalWrite (Motor3_1, LOW);
    digitalWrite (Motor3_2, HIGH); 
    digitalWrite (Motor4_1, LOW);
    digitalWrite (Motor4_2, HIGH);  
    digitalWrite (Motor5_1, LOW);
    digitalWrite (Motor5_2, HIGH); 
    digitalWrite (Motor6_1, LOW);
    digitalWrite (Motor6_2, LOW); 
    delay(speed);     
  } else if (orientation == 'N') { //назад направо
    digitalWrite (Motor1_1, LOW);
    digitalWrite (Motor1_2, LOW);
    digitalWrite (Motor2_1, LOW);
    digitalWrite (Motor2_2, HIGH); 
    digitalWrite (Motor3_1, LOW);
    digitalWrite (Motor3_2, HIGH); 
    digitalWrite (Motor4_1, LOW);
    digitalWrite (Motor4_2, HIGH);  
    digitalWrite (Motor5_1, LOW);
    digitalWrite (Motor5_2, HIGH); 
    digitalWrite (Motor6_1, LOW);
    digitalWrite (Motor6_2, HIGH);
    delay(speed);     
  } 
    if (speed!=parspeedperiod){
      digitalWrite (Motor1_1, LOW);
      digitalWrite (Motor1_2, LOW);
      digitalWrite (Motor2_1, LOW);
      digitalWrite (Motor2_2, LOW); 
      digitalWrite (Motor3_1, LOW);
      digitalWrite (Motor3_2, LOW); 
      digitalWrite (Motor4_1, LOW);
      digitalWrite (Motor4_2, LOW);
      digitalWrite (Motor5_1, LOW);
      digitalWrite (Motor5_2, LOW); 
      digitalWrite (Motor6_1, LOW);
      digitalWrite (Motor6_2, LOW);
      delay(parspeedperiod-speed); 
    }
}

void loop() { 
  if (Serial3.available()) {  
    char c = Serial3.read();
    
  switch (c){
      case 'X':movewh('Y',50);//вперед направо
        break;
      case 'P':movewh('N',50);//назад направо
        break;
      case 'V':movewh('T',50);//назад налево
        break;
      case 'B':movewh('I',50);//вперед налево
        break;
      case 'N':movewh('F',50);//вперед
        break;
      case 'M':movewh('B',50);//назад
        break;
      case 'Z':movewh('R',50);//вправо
        break;
      case 'L':movewh('L',50);//влево
        break;
      case 'W':movewh('F',10);//вперед
        break;
      case '0':movewh('F', 0);//стоп
    }
  }
}
