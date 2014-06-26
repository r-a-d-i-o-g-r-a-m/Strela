// Подключим библиотеку для работы с I2C-расширителем портов
#include <Wire.h>
// Подключим библиотеку Strela
#include <Strela.h>

void setup() {
  motorConnection(1, 0);// Я неправильно прикрутил один мотор
  //поэтому, чтобы их не перекручивать
  //можно воспользоваться этой функцией.
  //Направление вращения мотора 1 будет изменено.
}

void loop() {

  //Моторы управляются функцией drive(int m1, int m2). 
  //m1 (m2) - это скорость вращения мотора 1 (2). 
  //Скорость регулируется в пределах от -255 до 255
  //Если это число положительное - мотор будет вращаться вперёд, 
  //если отрицательное - назад.
  
  //Фаза 1
  uDigitalWrite(L1, HIGH);   // Зажгли светодиод 1

  drive(127, 127);   //Средний ход вперёд
  delay(2000);       // в течении 2 секунд.

  //Фаза 2
  uDigitalWrite(L2, HIGH);   // Зажгли светодиод 2

  drive(127, 0);     //Поворот на право
  delay(1000);        // в течении 1 секунды

  //Фаза 3
  uDigitalWrite(L3, HIGH);   // Зажгли светодиод 3

  drive(-255, -255); //Полный назад
  delay(1000);        // в течении 1 секунды

  //Фаза 4
  uDigitalWrite(L4, HIGH);   // Зажгли светодиод 4

  for (int i = 0; i <= 255; ++i)
  {
    drive(i, -i);    //Разворот на месте с ускорением
    delay(1);
  }

  //Фаза 5

  drive(0, 0);       //Стоп

  for (int i = L1; i <= L4; i++)
  {
    uDigitalWrite(i, LOW); // Гасим все светодиоды
  }

  // Всё, приехали
  while (true)
    ;

}