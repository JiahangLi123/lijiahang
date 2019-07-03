#include "Arduino.h"
#include "Morse.h"

Morse::Morse(int pin)//���취 
{
	pinMode(pin,OUTPUT);//����Ϊ��� 
	_pin=pin;//��pin����_pin 
}

void Morse::dot()
{
	digitalWrite(_pin,HIGH);
	delay(250);
	digitalWrite(_pin,LOW);
	delay(250);
}

void Morse::dash()
{
	digitalWrite(_pin,HIGH);
	delay(1000);
	digitalWrite(_pin,LOW);
	delay(250);
}
void Morse::c_space()//�ַ���� 
{
	digitalWrite(_pin,LOW);
	delay(250*3);
}
void Morse::w_space()//���ʼ�� 
{
	digitalWrite(_pin,LOW);
	delay(250*7);
}
