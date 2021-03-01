//пин tx -->rx3
//пин rx -->tx3
//схема нумеровки моторов      FD
//                            6||1
//                            5||2
//                            4||3

 int parspeedperiod=50;
 int speeed = 0;
 
 #define Motor1_1 2 //FR EN
 #define Motor1_2 43 //FR
 #define Motor2_1 3 //CR EN
 #define Motor2_2 45 //CR
 #define Motor3_1 4 //BR EN
 #define Motor3_2 47 //BR
 #define Motor4_1 5 //BL EN
 #define Motor4_2 49 //BL
 #define Motor5_1 6 //CL EN
 #define Motor5_2 51 //CL
 #define Motor6_1 7 //FL EN
 #define Motor6_2 53 //FL

void setup()  {
  Serial.begin(230400); 
  Serial3.begin(230400);
  
  for (int i=42; i<=53;i++) {
    pinMode(i, OUTPUT);
    digitalWrite (i, LOW);
  }
  for (int i=2; i<=7;i++) {
    analogWrite (i, 0);
  }
}

void movewh(char orientation, int speeed) { //функция с параметрами куда ехать и с какой скоростью (от 0 до 100)
  if (orientation == 'F') { //вперед
    analogWrite(Motor1_1, speeed);
    digitalWrite (Motor1_2, HIGH); 
    analogWrite(Motor2_1, speeed);
    digitalWrite (Motor2_2, HIGH); 
    analogWrite(Motor3_1, speeed);
    digitalWrite (Motor3_2, HIGH); 
    analogWrite(Motor4_1, speeed);
    digitalWrite (Motor4_2, HIGH); 
    analogWrite(Motor5_1, speeed);
    digitalWrite (Motor5_2, HIGH);
    analogWrite(Motor6_1, speeed);
    digitalWrite (Motor6_2, HIGH);
     
  } else if (orientation == 'B') { //назад
    analogWrite(Motor1_1, speeed);
    digitalWrite (Motor1_2, LOW);  
    analogWrite(Motor2_1, speeed);
    digitalWrite (Motor2_2, LOW); 
    analogWrite(Motor3_1, speeed);
    digitalWrite (Motor3_2, LOW); 
    analogWrite(Motor4_1, speeed);
    digitalWrite (Motor4_2, LOW);
    analogWrite(Motor5_1, speeed);
    digitalWrite (Motor5_2, LOW); 
    analogWrite(Motor6_1, speeed);
    digitalWrite (Motor6_2, LOW);  
          
  } else if (orientation == 'R') {  //вправо
    analogWrite(Motor1_1, speeed);
    digitalWrite (Motor1_2, LOW); 
    analogWrite(Motor2_1, speeed);
    digitalWrite (Motor2_2, LOW); 
    analogWrite(Motor3_1, speeed);
    digitalWrite (Motor3_2, LOW); 
    analogWrite(Motor4_1, speeed);
    digitalWrite (Motor4_2, HIGH); 
    analogWrite(Motor5_1, speeed);
    digitalWrite (Motor5_2, HIGH);
    analogWrite(Motor6_1, speeed);
    digitalWrite (Motor6_2, HIGH); 
  
  } else if (orientation == 'L') {  //влево
    analogWrite(Motor1_1, speeed);
    digitalWrite (Motor1_2, HIGH);  
    analogWrite(Motor2_1, speeed);
    digitalWrite (Motor2_2, HIGH); 
    analogWrite(Motor3_1, speeed);
    digitalWrite (Motor3_2, HIGH); 
    analogWrite(Motor4_1, speeed);
    digitalWrite (Motor4_2, LOW);
    analogWrite(Motor5_1, speeed);
    digitalWrite (Motor5_2, LOW); 
    analogWrite(Motor6_1, speeed);
    digitalWrite (Motor6_2, LOW);  
   
  } else if (orientation == 'I') { //вперед налево
    analogWrite(Motor1_1, speeed);
    digitalWrite (Motor1_2, HIGH); 
    analogWrite(Motor2_1, speeed);
    digitalWrite (Motor2_2, HIGH); 
    analogWrite(Motor3_1, speeed);
    digitalWrite (Motor3_2, HIGH); 
    analogWrite(Motor4_1, 0);
    analogWrite(Motor5_1, speeed);
    digitalWrite (Motor5_2, HIGH);
    analogWrite(Motor6_1, speeed);
    digitalWrite (Motor6_2, HIGH); 
    
  } else if (orientation == 'Y') { //вперед направо
    analogWrite(Motor1_1, speeed);
    digitalWrite (Motor1_2, HIGH); 
    analogWrite(Motor2_1, speeed);
    digitalWrite (Motor2_2, HIGH); 
    analogWrite(Motor3_1, 0); 
    analogWrite(Motor4_1, speeed);
    digitalWrite (Motor4_2, HIGH); 
    analogWrite(Motor5_1, speeed);
    digitalWrite (Motor5_2, HIGH);
    analogWrite(Motor6_1, speeed);
    digitalWrite (Motor6_2, HIGH);  
   
  } else if (orientation == 'T') { //назад налево
    analogWrite(Motor1_1, speeed);
    digitalWrite (Motor1_2, LOW);  
    analogWrite(Motor2_1, speeed);
    digitalWrite (Motor2_2, LOW); 
    analogWrite(Motor3_1, speeed);
    digitalWrite (Motor3_2, LOW); 
    analogWrite(Motor4_1, speeed);
    digitalWrite (Motor4_2, LOW);
    analogWrite(Motor5_1, speeed);
    digitalWrite (Motor5_2, LOW); 
    analogWrite(Motor6_1, 0);
   
  } else if (orientation == 'N') { //назад направо
    analogWrite(Motor1_1, 0); 
    analogWrite(Motor2_1, speeed);
    digitalWrite (Motor2_2, LOW); 
    analogWrite(Motor3_1, speeed);
    digitalWrite (Motor3_2, LOW); 
    analogWrite(Motor4_1, speeed);
    digitalWrite (Motor4_2, LOW);
    analogWrite(Motor5_1, speeed);
    digitalWrite (Motor5_2, LOW); 
    analogWrite(Motor6_1, speeed);
    digitalWrite (Motor6_2, LOW); 
    
  } if (orientation == 'S'){
    analogWrite(Motor1_1, 0);
    analogWrite(Motor2_1, 0);
    analogWrite(Motor3_1, 0);
    analogWrite(Motor4_1, 0);
    analogWrite(Motor5_1, 0);
    analogWrite(Motor6_1, 0);
  }
}

void loop() { 
  if (Serial3.available()) {  
    char c = Serial3.read();

  switch (c){
      case '9':speeed=255;Serial.println("255");
        break;
      case '8':speeed=230;Serial.println("220");
        break;
      case '7':speeed=205;Serial.println("190");
        break;
      case '6':speeed=180;Serial.println("160");
        break;
      case '5':speeed=155;Serial.println("120");
        break;
      case '4':speeed=130;Serial.println("90");
        break;
      case '3':speeed=105;Serial.println("70");
        break;
      case '2':speeed=80;Serial.println("50");
        break;
      case '1':speeed=55;Serial.println("30");
        break;
      case '0':speeed=30;Serial.println("10");
        break;
      case 'X':movewh('Y',speeed);Serial.println("Y");//вперед направо
        break;
      case 'P':movewh('N',speeed);Serial.println("N");//назад направо
        break;
      case 'V':movewh('T',speeed);Serial.println("T");//назад налево
        break;
      case 'B':movewh('I',speeed);Serial.println("I");//вперед налево
        break;
      case 'N':movewh('F',speeed);Serial.println("F");//вперед
        break;
      case 'M':movewh('B',speeed);Serial.println("B");//назад
        break;
      case 'Z':movewh('R',speeed);Serial.println("R");//вправо
        break;
      case 'L':movewh('L',speeed);Serial.println("L");//влево
        break;
      case 'W':movewh('F',100);Serial.println("F");//вперед
        break;
      case 'Q':movewh('S', 0);Serial.println("Q");//стоп
    } 
  }
}
