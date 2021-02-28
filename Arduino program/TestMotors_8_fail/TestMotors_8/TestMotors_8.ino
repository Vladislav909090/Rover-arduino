 #define Motor1_1 2
 #define Motor1_2 3
 #define Motor2_1 4
 #define Motor2_2 5
 #define Motor3_1 6
 #define Motor3_2 7
 #define Motor4_1 8
 #define Motor4_2 9
 
void setup() {
  for (int i=2; i<=9;i++) {
    pinMode(i, OUTPUT);
  }
    
    digitalWrite (Motor1_1, LOW);
    digitalWrite (Motor1_2, LOW); 
    digitalWrite (Motor2_1, LOW);
    digitalWrite (Motor2_2, LOW); 
    digitalWrite (Motor3_1, LOW);
    digitalWrite (Motor3_2, LOW);
    digitalWrite (Motor4_1, LOW);
    digitalWrite (Motor4_2, LOW);  
}

void Motor1(int napr, float speed) {
  if (napr == 1) {
    digitalWrite (Motor1_1, HIGH);
    digitalWrite (Motor1_2, LOW); 
    delay(100*speed);    
    digitalWrite (Motor1_1, LOW);
    digitalWrite (Motor1_2, LOW); 
    delay(1-100*speed); 
  } else if (napr == -1) {
    digitalWrite (Motor1_1, LOW);
    digitalWrite (Motor1_2, HIGH); 
    delay(100*speed);    
    digitalWrite (Motor1_1, LOW);
    digitalWrite (Motor1_2, LOW); 
    delay(1-100*speed); 
  } else if (napr == 0) {
    digitalWrite (Motor1_1, LOW);
    digitalWrite (Motor1_2, LOW); 
  }
}

void Motor2(int napr, float speed) {
  if (napr == 1) {
    digitalWrite (Motor2_1, HIGH);
    digitalWrite (Motor2_2, LOW); 
    delay(100*speed);    
    digitalWrite (Motor2_1, LOW);
    digitalWrite (Motor2_2, LOW); 
    delay(100-100*speed); 
  } else if (napr == -1) {
    digitalWrite (Motor2_1, LOW);
    digitalWrite (Motor2_2, HIGH); 
    delay(100*speed);    
    digitalWrite (Motor2_1, LOW);
    digitalWrite (Motor2_2, LOW); 
    delay(100-100*speed); 
  } else if (napr == 0) {
    digitalWrite (Motor2_1, LOW);
    digitalWrite (Motor2_2, LOW); 
  }
}

void Motor3(int napr, float speed) {
  if (napr == 1) {
    digitalWrite (Motor3_1, HIGH);
    digitalWrite (Motor3_2, LOW); 
    delay(100*speed);    
    digitalWrite (Motor3_1, LOW);
    digitalWrite (Motor3_2, LOW); 
    delay(100-100*speed); 
  } else if (napr == -1) {
    digitalWrite (Motor3_1, LOW);
    digitalWrite (Motor3_2, HIGH); 
    delay(100*speed);    
    digitalWrite (Motor3_1, LOW);
    digitalWrite (Motor3_2, LOW); 
    delay(100-100*speed); 
  } else if (napr == 0) {
    digitalWrite (Motor3_1, LOW);
    digitalWrite (Motor3_2, LOW); 
  }
}


void Motor4(int napr, float speed) {
  if (napr == 1) {
    digitalWrite (Motor4_1, HIGH);
    digitalWrite (Motor4_2, LOW); 
    delay(100*speed);    
    digitalWrite (Motor4_1, LOW);
    digitalWrite (Motor4_2, LOW); 
    delay(100-100*speed); 
  } else if (napr == -1) {
    digitalWrite (Motor4_1, LOW);
    digitalWrite (Motor4_2, HIGH); 
    delay(100*speed);    
    digitalWrite (Motor4_1, LOW);
    digitalWrite (Motor4_2, LOW); 
    delay(100-100*speed); 
  } else if (napr == 0) {
    digitalWrite (Motor4_1, LOW);
    digitalWrite (Motor4_2, LOW); 
  }
}

void loop() {
   Motor1(1,0.5);
   Motor2(1,0.5);
   Motor3(1,0.5);
   Motor4(1,0.5);
   delay(3000);
   Motor1(0,0.5);
   Motor2(0,0.5);
   Motor3(0,0.5);
   Motor4(0,0.5);
   delay(3000);
   Motor1(-1,0.5);
   Motor2(-1,0.5);
   Motor3(-1,0.5);
   Motor4(-1,0.5);
   delay(3000);
}
