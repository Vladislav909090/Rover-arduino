#include "LiquidCrystal.h"

// инициализировать библиотеку, указав ей выводы подключения
LiquidCrystal lcd(8,9,4,5,6,7);

void setup() 
{
  lcd.begin(16,2);

  // установить курсор в начало первой строки LCD дисплея
  lcd.setCursor(0,0);
  // напечатать текст
  lcd.print("DOSAAF");
  // установить курсор в начало следующей строки
  lcd.setCursor(0,1);
  lcd.print("Made by Lozhkin");
}

void loop()
{}
