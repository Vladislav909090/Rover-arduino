
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
  int spX = abs(512-X)/512;
  int spY = abs(512-Y)/512; 
  int spD = abs(724-abs(sqrt(X*X+Y*Y)))/724;
  int erproc = round (0.5*1023/100);  //погрешность измерения в проценте - 0.5% = 5 ед.   

  if (!ledState) { 
         Serial.println("W");
  } else if ((Y>-2*X)&&(Y<-0.5*X)) {
         Serial.println("P");//назад направо 
         Serial.println(spD);
  } else if ((Y>2*X)&&(Y<0.5*X)) {
         Serial.println("V");//назад налево
         Serial.println(spD);
  } else if ((Y>-0.5*X)&&(Y<-2*X)) {
         Serial.println("B");//вперед налево 
         Serial.println(spD);
  } else if ((Y>0.5*X)&&(Y<2*X)) {
         Serial.println("X");//вперед направо
         Serial.println(spD);
  } else if (Y>2*abs(X)) {
         Serial.println("N"); //вперед
         Serial.println(spY);
  } else if (Y<=-2*abs(X)){
         Serial.println("M");//назад
         Serial.println(spY);
  } else if ((Y>=-0.5*X)&&(Y<=0.5*X)) {
         Serial.println("Z"); //вправо
         Serial.println(spX);
  } else if ((Y<=-0.5*X)&&(Y>=0.5*X)){
         Serial.println("L");//влево
         Serial.println(spX);
  } else if ((496-erproc<=Y<=496+erproc)&&(496-erproc<=X<=496+erproc)) {
         Serial.println("0");
  }
  delay(1000);
}
