#include <Arduino.h>

double data1 = 10, data2 = 3; 
#=======================================
void setup()
{
  Serial.begin(115200);
  while (!Serial)
    ;
}
#=======================================
void loop()
{
  #______________________________________
  #Printing on the Serial port every 10ms 
  if (micros() - Serial_time >= 10000)
  {
    Serial_time = micros();
    Serial.print(Serial_time / 10000);
    Serial.print(",");
    Serial.print(data1);
    Serial.println();
  }
  #______________________________________
  #Keyboard input in the serial monitor to change the value of data1
  #Entering q12 change data1 to 12. Entering w34 change data2 to 34
    static String received_chars;
  while (Serial.available())
  {
    char inChar = (char)Serial.read();
    received_chars += inChar;
    if (inChar == '\n')
    {
      switch (received_chars[0])
      {
      case 'q':
        received_chars.remove(0, 1);
        data1 = received_chars.toFloat();
        break;
      case 'w':
        received_chars.remove(0, 1);
        data2 = received_chars.toFloat();
        break;
      default:
        break;
      }
      received_chars = "";
    }
  }
}
