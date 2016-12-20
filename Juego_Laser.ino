#include <LiquidCrystal_I2C.h>
#include <Wire.h>

int NLEDS = 4;
byte cero = B00000000;
int puntos = 0;

void calSensor(int cal[5]);
void infoSensor(int pin);

void setup()
{
DDRD = B00011111;
Serial.begin(9600);


}
void loop()
{
  delay(500);
  int cal[5]= {0,0,analogRead(A0),analogRead(A1),analogRead(A2)};
  calSensor(cal);

  for(int led=2;led<5;led++)
    {
      PORTD = cero;
      do{
          digitalWrite(led,HIGH);
          infoSensor(led);

      }while(analogRead(led-2)>cal[led]-100);
    }

}


void calSensor(int cal[5])
{
Serial.print("Calibrado ronda -->     ");
Serial.print(cal[2]);
Serial.print(" ");
Serial.print(cal[3]);
Serial.print(" ");
Serial.println(cal[4]);
}
void infoSensor(int led){
  
Serial.print("Sensor actual  ");
Serial.print(led-1);
Serial.print("-->  ");
Serial.println(analogRead(led-2));
delay(100);
}
