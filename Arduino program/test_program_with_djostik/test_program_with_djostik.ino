
#define pinX    A2  // ось X джойстика
#define pinY    A1  // ось Y джойстика
#define swPin    2  // кнопка джойстика

int generalsp;
int dgeneralsp = 1000;//беру случайное число

  
void setup() {
  Serial.begin(230400);
  
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  pinMode(swPin, INPUT);
  digitalWrite(swPin, HIGH);
}
 
void loop() {
  boolean ledState = digitalRead(swPin);   
  int X = analogRead(pinY);//меняю координаты для того, чтобы оси XY на джостике располпгплись по-другому (вверх джостика в противоположной стороне от проводов)            
  int Y = analogRead(pinX); 
  float spX = ((512-(float)X)/512)*100;
  spX = abs(spX);
  float spY = ((512-(float)Y)/512)*100;
  spY = abs(spY);
  float spDR = floor(((724-sqrt((float)X*(float)X+(float)Y*(float)Y))/724)*100);
  spDR = abs(spDR);
  float spDL = floor(((724-sqrt((float)(1023-X)*(float)(1023-X)+(float)Y*(float)Y))/724)*100);
  spDL = abs(spDL);
  int erproc = floor (0.005*1023);  //погрешность измерения в проценте - 0.5% = 5 ед.   
  //Serial.print("X:");Serial.println(X);
  //Serial.print("Y:");Serial.println(Y);
  int dX = map(X, 0, 1024, -512, 512);
  int dY = map(Y, 0, 1024, -512, 512);
  int dspX = map((int)spX, 0, 98, 0, 9);
  int dspY = map((int)spY, 0, 98, 0, 9);
  int dspDR = map((int)spDR, 0, 98, 0, 9);
  int dspDL = map((int)spDL, 0, 98, 0, 9);
  
  if (!ledState) { 
         Serial.println("W");//нажатие кнопки
  } else if (((-15-erproc)<=dY)&&(dY<=(-15+erproc)) && ((-15-erproc)<=dX)&&(dX<=(-15+erproc))) {
         Serial.println("Q");//стсутствие действий
  } else if ((dY>-2*dX)&&(dY<-0.5*dX)) {
         generalsp = dspDL;
         Serial.println("P");//назад направо 
  } else if ((dY>2*dX)&&(dY<0.5*dX)) {
         generalsp = dspDR;
         Serial.println("V");//назад налево
  } else if ((dY>-0.5*dX)&&(dY<-2*dX)) {
         generalsp = dspDL;
         Serial.println("B");//вперед налево 
  } else if ((dY>0.5*dX)&&(dY<2*dX)) {
         generalsp = dspDR;
         Serial.println("X");//вперед направо
  } else if ((dY>=-2*dX)&&(dY>=2*dX)) {
         generalsp = dspY;
         Serial.println("N"); //вперед
  } else if ((dY<=-2*dX)&&(dY<=2*dX)){
         generalsp = dspY;
         Serial.println("M");//назад
  } else if ((dY>=-0.5*dX)&&(dY<=0.5*dX)) {
         generalsp = dspX;
         Serial.println("Z"); //вправо
  } else if ((dY<=-0.5*dX)&&(dY>=0.5*dX)){
         generalsp = dspX;
         Serial.println("L");//влево
  }

   if (generalsp != dgeneralsp) {
    Serial.println(generalsp);
    dgeneralsp = generalsp;
   }
}
