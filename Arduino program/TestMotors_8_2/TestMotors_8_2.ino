 #define Motor1_1 2 //FR
 #define Motor1_2 3 //FR
 #define Motor2_1 4 //FL
 #define Motor2_2 5 //FL
 #define Motor3_1 6 //BR
 #define Motor3_2 7 //BR
 #define Motor4_1 8 //BL
 #define Motor4_2 9 //BL
 
void setup() {
  for (int i=2; i<=9;i++) {
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
    delay(speed);     
  } else if (orientation == 'R') {  //вправо
    digitalWrite (Motor1_1, LOW);
    digitalWrite (Motor1_2, HIGH); 
    digitalWrite (Motor2_1, HIGH);
    digitalWrite (Motor2_2, LOW); 
    digitalWrite (Motor3_1, LOW);
    digitalWrite (Motor3_2, HIGH); 
    digitalWrite (Motor4_1, HIGH);
    digitalWrite (Motor4_2, LOW); 
    delay(speed);    
  } else if (orientation == 'L') {  //влево
    digitalWrite (Motor1_1, HIGH);
    digitalWrite (Motor1_2, LOW);
    digitalWrite (Motor2_1, LOW);
    digitalWrite (Motor2_2, HIGH); 
    digitalWrite (Motor3_1, HIGH);
    digitalWrite (Motor3_2, LOW); 
    digitalWrite (Motor4_1, LOW);
    digitalWrite (Motor4_2, HIGH);  
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
    delay(speed);     
  } else if (orientation == 'T') { //назад налево
    digitalWrite (Motor1_1, LOW);
    digitalWrite (Motor1_2, HIGH);
    digitalWrite (Motor2_1, LOW);
    digitalWrite (Motor2_2, LOW); 
    digitalWrite (Motor3_1, LOW);
    digitalWrite (Motor3_2, HIGH); 
    digitalWrite (Motor4_1, LOW);
    digitalWrite (Motor4_2, HIGH);  
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
    delay(speed);     
  } 
    digitalWrite (Motor1_1, LOW);
    digitalWrite (Motor1_2, LOW);
    digitalWrite (Motor2_1, LOW);
    digitalWrite (Motor2_2, LOW); 
    digitalWrite (Motor3_1, LOW);
    digitalWrite (Motor3_2, LOW); 
    digitalWrite (Motor4_1, LOW);
    digitalWrite (Motor4_2, LOW);  
    delay(100-speed); 
}

void loop() {
   movewh('L',100);
}
