#include <Morse.h>
Morse morse(13);
 
void setup()
{
  Serial.begin(9600);   //波特率
}

void loop()
{
  char str[] = "";
  while(Serial.available()>0)  //判断串口是否有数据读入
  {
    strcpy(str,(Serial.read()));
  }
  if(strlen(str)!=0)
  {
    for(int i = 0;i<strlen(str);i++)
    {
      if(str[i]==" ")
        continue;
      switch(str[i]-96)
      {
        case 1:Serial.println(".-  \n");
        morse.dot();
        morse.dash();
        morse.c_space();
        break;
        case 2:Serial.println("-...\n");
        morse.dash();
        morse.dot();
        morse.dot();
        morse.dot();
        morse.c_space();
        break;
        case 3:Serial.println("-.-.\n");
        morse.dash();
        morse.dot();
        morse.dash();
        morse.dot();
        morse.c_space();
        break;
        case 4:Serial.println("-.. \n");
        morse.dash();
        morse.dot();
        morse.dot();
        morse.c_space();
        break;
        case 5:Serial.println(".   \n");
        morse.dot();
        morse.c_space();
        break;
        case 6:Serial.println("..-.\n");
        morse.dot();
        morse.dot();
        morse.dash();
        morse.dot();
        morse.c_space();
        break;
        case 7:Serial.println("--. \n");
        morse.dash();
        morse.dash();
        morse.dot();
        morse.c_space();
        break;
        case 8:Serial.println("....\n");
        morse.dot();
        morse.dot();
        morse.dot();
        morse.dot();
        morse.c_space();
        break;
        case 9:Serial.println("..  \n");
        morse.dot();
        morse.dot();
        morse.c_space();
        break;
        case 10:Serial.println(".---\n");
        morse.dot();
        morse.dash();
        morse.dash();
        morse.dash();
        morse.c_space();
        break;
        
        case 11:Serial.println("-.- \n");
        morse.dash();
        morse.dot();
        morse.dash();
        morse.c_space();
        break;
        case 12:Serial.println(".-..\n");
        morse.dot();
        morse.dash();
        morse.dot();
        morse.dot();
        morse.c_space();
        break;
        case 13:Serial.println("--  \n");
        morse.dash();
        morse.dash();
        morse.c_space();
        break;
        case 14:Serial.println("-.  \n");
        morse.dash();
        morse.dot();
        morse.c_space();
        break;
        case 15:Serial.println("--- \n");
        morse.dash();
        morse.dash();
        morse.dash();
        morse.c_space();
        break;
        case 16:Serial.println(".--.\n");
        morse.dot();
        morse.dash();
        morse.dash();
        morse.dot();
        morse.c_space();
        break;
        case 17:Serial.println("--.-\n");
        morse.dash();
        morse.dash();
        morse.dot();
        morse.dash();
        morse.c_space();
        break;
        case 18:Serial.println(".-. \n");
        morse.dot();
        morse.dash();
        morse.dot();
        morse.c_space();
        break;
        case 19:Serial.println("... \n");
        morse.dot();
        morse.dot();
        morse.dot();
        morse.c_space();
        break;
        case 20:Serial.println("-   \n");
        morse.dash();
        morse.c_space();
        break;
        case 21:Serial.println("..- \n");
        morse.dot();
        morse.dot();
        morse.dash();
        morse.c_space();
        break;
        case 22:Serial.println("...-\n");
        morse.dot();
        morse.dot();
        morse.dot();
        morse.dash();
        morse.c_space();
        break;
        case 23:Serial.println(".-- \n");
        morse.dot();
        morse.dash();
        morse.dash();
        morse.c_space();
        break;
        case 24:Serial.println("-..-\n");
        morse.dash();
        morse.dot();
        morse.dot();
        morse.dash();
        morse.c_space();
        break;
        case 25:Serial.println("-.--\n");
        morse.dash();
        morse.dot();
        morse.dash();
        morse.dash();
        morse.c_space();
        break;
        case 26:Serial.println("--..\n");
        morse.dash();
        morse.dash();
        morse.dot();
        morse.dot();
        morse.c_space();
        break;
      }
    }
  }
}
