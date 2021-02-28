
#define pinX    A2  // ось X джойстика
#define pinY    A1  // ось Y джойстика
#define swPin    2  // кнопка джойстика

void setup() {
  Serial.begin(230400);
  
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  pinMode(swPin, INPUT);
  digitalWrite(swPin, HIGH);
}
 
void loop() {
  boolean ledState = digitalRead(swPin);   
  int X = analogRead(pinX);              
  int Y = analogRead(pinY);             
  
  if ((X>500) && (Y<490)) {
         Serial.println("X");
  } else if ((Y>500) && (X>500)) {
         Serial.println("P");
  } else if ((X<490) && (Y>500)) {
         Serial.println("V");
  } else if ((Y<490) && (X<490)) {
         Serial.println("B");
  } else if ((490<=X<=500) && (Y<490)) {
         Serial.println("N");
  } else if ((Y>500) && (490<=X<=500)){
         Serial.println("M");
  } else if ((490<=Y<=500) && (X>500)) {
         Serial.println("Z"); 
  } else if ((X<490) && (490<=Y<=500)){
         Serial.println("L");
  } else if (!ledState) { 
         Serial.println("W");
  } else if ((490<=Y<=500)&&(490<=X<=500)) {
         Serial.println("0");
  }
}
