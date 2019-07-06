#<div align="center"> 国际双创实践周——开源硬件实战学习总结报告 
>姓名：李嘉航
>学号：17019110023
>日期：2019/7/2-2019/7/5
## 一、国际双创实践周参与情况
### 7月2日
课堂：
1.介绍了创客
2.介绍了Arduino
3.介绍了Processing、Frizting、GitHub

作业：
1.创建GitHub账号
2.安装Arduino、fritzing、processing
3.安装VMware

### 7月3日
课堂：
1.讲解了串口的相关知识
2.讲解了arduino的代码知识和类库编写
3.讲解了莫尔斯代码的知识，并加以应用

作业：
实现arduino代码编写用morse代码来表示26个小写英文字母
```arduino
#include <Morse.h>
#define SIZE 26
//定义摩尔斯电码表
String MORSE[SIZE] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",  //A to I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",//J to R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."        //S to Z 
};
Morse morse(13);

void setup() {
  Serial.begin(9600);//设置通信波特率

}

void loop() {
  String str = "";    //储存串口读到的字符串
  String output = "";  //转义后字符串
  int i, t , temp = 0;
  int n = 0;  //对传入字符个数计数
  while (Serial.available() > 0) {
    temp = 1;  //判断是否有数据传入
    str += char(Serial.read());  //将传入的数据储存在字符串中
    delay(1000);  //延迟保证传入正常
    n++;
  }

  if (temp) {
    //查询Morse电码表并进行转换
    for (i = 0; i < n; i++)
    {

        //判断是否为小写字母，如果是则转义
        if (str[i] >= 97 && str[i] <= 122)
        {
          output += String(MORSE[int(str[i] - 97)]);
        }
        else output += String(MORSE[int(str[i] - 65)]);

      
    }
    Serial.print(output);  //串口传入
  }
    for(int j=0;j<output.length()-1;j++)
    {
        if(output[j]==46)
        {
         morse.dot();
       }
        if(output[j]==45)
        {
         morse.dash();
       }
    }
    delay(3000);
  
}
```

### 7月4日 认识tinkercad及操作
课堂：
1.讲解了用在线网站tinkercad来模拟组装arduino电路和编写运行arduino代码
2.介绍了电机的使用，PWM技术

作业：
1.实现在小车上添加转向灯的功能
2.在数码管上显示数字1-9
```arduino
void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}
int income=0;
void loop()
{
	if(Serial.available()>0)
    {
    	income=Serial.read();
      	switch(income)
        {
        	case 'f':
          		forward();
          		break;
          	case 'b':
          		backward();
          		break;
          	case 'l':
          		left();
          		break;
          	case 'r':
          		right();
          		break;
          	case 's':
          		stop();
          		break;
          	default:
          		break;
        }
    }
}

void forward()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
}

void backward()
{
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
}

void left()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(13,LOW);
  
  
}

void right()
{
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(4,LOW);
  digitalWrite(13,HIGH);
}

void stop()
{
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
}
```
```arduino
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  
  int income;
  if(Serial.available()>0)
  {      
    income=Serial.read()-'0';

    if((income&1)==1)
       digitalWrite(2, HIGH);
       
    if((income>>1&1)==1)
       digitalWrite(3, HIGH);
      
    if((income>>2&1)==1)
       digitalWrite(4, HIGH);
      
    if((income>>3&1)==1)
       digitalWrite(5, HIGH);
      
    
       digitalWrite(6,HIGH);
       delay(1000);
  }

}
```
### 7月5日 总结
课堂：
1.介绍使用了markdown
2.在tinkercad上实现莫尔斯代码功能
3.现场答疑

作业：
1.交流总结4天来的收获和感受，上交一篇总结
2.课后一个额外的联系，可与课堂上的作业二选一
```arduino
#include "Arduino.h"
#define SIZE 26
//定义摩尔斯电码表
String MORSE[SIZE] = 
{
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",  //A to I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",//J to R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."        //S to Z 
};

void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600);//设置通信波特率

}

void loop() {
  String str = "";    //储存串口读到的字符串
  String output = "";  //转义后字符串
  int i, t , temp = 0;
  int n = 0;  //对传入字符个数计数
  while (Serial.available() > 0) {
    temp = 1;  //判断是否有数据传入
    str += char(Serial.read());  //将传入的数据储存在字符串中
    delay(1000);  //延迟保证传入正常
    n++;
  }

  if (temp) {
    //查询Morse电码表并进行转换
    for (i = 0; i < n; i++)
    {

        //判断是否为小写字母，如果是则转义
        if (str[i] >= 97 && str[i] <= 122)
        {
          output += String(MORSE[int(str[i] - 97)]);
        }
        else output += String(MORSE[int(str[i] - 65)]);

      
    }
    Serial.print(output);  //串口传入
  }
    for(int j=0;j<output.length()-1;j++)
    {
        if(output[j]==46)
        {
         digitalWrite(13, HIGH);
      delay(250);
     digitalWrite(13, LOW);
      delay(250);
       }
        if(output[j]==45)
        {
         digitalWrite(13, HIGH);
      delay(1000);
     digitalWrite(13, LOW);
      delay(250);
       }
    }
    delay(3000);
  
}
```
## 二、国际双创实践周主要收获
1.了解了开源的相关知识和思想:开源全称为开放源代码，就是要用户利用源代码在其基础上修改和学习的。接纳、包容和发展，求同存异，互利共赢，才是开源的本质。所以老师在课上课下更多地是鼓励我们多讨论，多思考，互相补充，共同进步，可以说，开源是一群人思想的碰撞摩擦。通过这次双创周的学习，我不仅收获了知识，而且收获了友谊。
2.学会了使用arduino编程，它是基于C和C++地编程语言。Arduino能通过各种各样的传感器来感知环境，通过控制灯光、马达和其他的装置来反馈、影响环境。板子上的微控制器可以通过Arduino的编程语言来编写程序，编译成二进制文件，烧录进微控制器。对Arduino的编程是通过 Arduino编程语言 (基于 Wiring)和Arduino开发环境(基于 Processing)来实现的。基于Arduino的项目，可以只包含Arduino，也可以包含Arduino和其他一些在PC上运行的软件，他们之间进行通信 (比如 Flash, Processing, MaxMSP)来实现。
3.接触到GitHub平台上其他的编程爱好者和开发者，向他们学习交流。

## 三、意见与建议
### 意见：
1.此次双创实践周选课期间出现了一些问题，首先是校园选课系统问题：学校的服务器在选课开始的9点钟后几乎面临崩溃，无法登录服务器，切换VPN也不行，同样的之前选择选修课时也遇到了相同的问题。
2.在登陆上去后，由于开设的课程的名额不足，导致部分学生无法参与到正常的选课之中，选不上课，强迫选了某一门课，选到的课所需的要求与自己的年级和专业不符。虽后续持续开设了新的选修课来弥补这一部分无课选择的学生，但仍然有小部分同学没选到课。
3.选修课由于课时较短，所学习到的也只是皮毛或者大概，这点有利有弊吧。利就是可以大体地让同学了解这门课程的内容和大致方向、未来前景；但弊端就是对于此门课感兴趣的同学只能自学，效率和深度和有专业老师教的情况比可能低一些。
### 建议：
1.针对这一点希望学校可以重视对于校园服务器和系统的优化和完善，提高处理能力，避免因同时登陆人数过多而产生的卡住、停顿等问题。
2.提前算清学生人数以及开设课程提供的名额数，以及对不同年级不同专业的同学设置好课程权限，防止与学生地年级专业冲突。
3.假如学校要在后续继续开展国际双创周的话，可以把上一次已经有的课做进一步的深入，开展高级班等方式。