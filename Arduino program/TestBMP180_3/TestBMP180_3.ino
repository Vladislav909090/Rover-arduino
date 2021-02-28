#include <SFE_BMP180.h>
#include <Wire.h>

// создаем экземпляр класса SFE_BMP180 и называем его «pressure»:
SFE_BMP180 pressure;

// это высота над уровнем моря в штаб-квартире SparkFun, в Боулдере;
// указана в метрах:
#define ALTITUDE 1655.0 

void setup()
{
  Serial.begin(9600);
  Serial.println("REBOOT");  //  "ПЕРЕЗАГРУЗКА"

  // инициализируем датчик (важно извлечь калибровочные данные,
  // хранящиеся в устройстве):
  if (pressure.begin())
    Serial.println("BMP180 init success");
    // "Инициализация BMP180 прошла успешно"
  else
  {
    // упс, что-то пошло не так! 
    // как правило, так происходит из-за проблем с подключением
    // (о том, как подключить датчик правильно, читайте выше):
    Serial.println("BMP180 init fail\n\n");
    // "Инициализация BMP180 не удалась"
    while(1); // вечная пауза
  }
}

void loop()
{
  char status;
  double T,P,p0,a;
  Serial.println();
  Serial.print("provided altitude: ");
  Serial.print(ALTITUDE,0);
  Serial.print(" meters, ");  //  " метров, "
  Serial.print(ALTITUDE*3.28084,0);
  Serial.println(" feet");   //  " футов, "
  
  status = pressure.startTemperature();
  if (status != 0)
  {
    delay(status);

    status = pressure.getTemperature(T);
    if (status != 0)
    {
      // печатаем измеренную температуру:
      Serial.print("temperature: ");  //  "температура: "
      Serial.print(T,2);
      Serial.print(" deg C, ");  //  " градусов Цельсия, "
      Serial.print((9.0/5.0)*T+32.0,2);
      Serial.println(" deg F");  //  " градусов Фаренгейта"

      status = pressure.startPressure(3);
      if (status != 0)
      {
        // ждем завершения измерения:
        delay(status);

        status = pressure.getPressure(P,T);
        if (status != 0)
        {
          // печатаем результат:
          Serial.print("absolute pressure: ");
          // "абсолютное давление: "
          Serial.print(P,2);
          Serial.print(" mb, ");  // " мбар, "
          Serial.print(P*0.0295333727,2);
          Serial.println(" inHg");  // " дюймов рт. ст."

          p0 = pressure.sealevel(P,ALTITUDE);
          // здесь, в Боулдере, 1655 метров над уровнем моря
          Serial.print("relative (sea-level) pressure: ");
          // относительное давление (приведенное к уровню моря)
          Serial.print(p0,2);
          Serial.print(" mb, ");  // " мбар, "
          Serial.print(p0*0.0295333727,2);
          Serial.println(" inHg");  // " дюймов рт. ст."

          a = pressure.altitude(P,p0);
          Serial.print("computed altitude: ");
          // "расчитанная высота над уровнем моря: "
          Serial.print(a,0);
          Serial.print(" meters, "); // " метров, "
          Serial.print(a*3.28084,0);
          Serial.println(" feet"); // " футов"
        }
        else Serial.println("error retrieving pressure measurement\n");
        // "ошибка при извлечении данных о давлении"
      }
      else Serial.println("error starting pressure measurement\n");
      // "ошибка при запуске измерения давления"
    }
    else Serial.println("error retrieving temperature measurement\n");
    // "ошибка при извлечении данных о температуре"
  }
  else Serial.println("error starting temperature measurement\n");
  // "ошибка при запуске измерения температуры"
  delay(5000);  // 5-секундная пауза
}
