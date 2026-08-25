#include "MatrixMini.h"

float mode;
float powerleft;
float basic;
float grayleft;
float grayright;
float kp;
float keep;
float kd;
float powerright;
float chose = 1;
float save;
float voice;
float lowlight = 920;//black
float highlight_r = 40;//whiteright
float highlight_l = 40;//whiteleft

void X() {
  Mini.PS2.polling();
  if(Mini.PS2.CROSS)
  {
    mode = 1;
  }
  if((-100) > powerleft)
  {
    powerleft = -100;
  }
  else
  {
    if((-100) > powerleft)
    {
      powerleft = -100;
    }
    else
    {
      if(powerleft > 100)
      {
        powerleft = 100;
      }
      else
      {
        if(powerleft > 100)
        {
          powerleft = 100;
        }
      }
    }
  }
}

void touch_n_n(float M1, float M2) {
  basic = 400;
  grayleft = Mini.A1.getANG();
  grayright = Mini.A2.getANG();
  while(!(((grayright < basic) && (grayleft < basic))||(mode == 1)))
  {
    X();
    Serial.println(Mini.A2.getANG());
    grayleft = Mini.A1.getANG();
    grayright = Mini.A2.getANG();
    Mini.M1.set(M1);
    Mini.M2.set(M2);
    if(grayright < basic)
    {
      Mini.M2.set(0);
    }
    else
    {
      if(grayleft < basic)
      {
        Mini.M1.set(0);
      }
    }
  }
  Mini.M1.set(0);
  Mini.M2.set(0);
}

void choice() {
  if(!(mode == 1))
  {
    while(!(Mini.PS2.TRIANGLE||(mode == 1)))
    {
      Mini.PS2.polling();
      X();
      if(Mini.PS2.LEFT){
        chose = 1;
        light();
      }
      if(Mini.PS2.RIGHT){
        chose = 3;
        light();
      }
      if(Mini.PS2.UP){
        chose = 5;
        light();
      }
      if(Mini.PS2.CIRCLE){
        chose = chose + 1;
        delay(500);
        Serial.println(mode);
        light();
      }
      Serial.println(chose);
    }
  }
}
unsigned long timer_1 = 0;
void deside() {
  if(!(mode == 1))
  {
    if(chose == 1){
      light();
      if(!(1 == mode))
      {
        Mini.RC3.set(120);
        delay(1000);
      }

      
      find_n(0);//找方塊
      if(!(1 == mode))
      {
        Mini.RC3.set(0);
        move_n_M1_n_M2_n_time(80, 80, 400);
        delay(200);
      }
      move_n_M1_n_M2_n_time(-60, -60, 300);
      move_n_M1_n_M2_n_time(60, -60, 700);
      move_n_M1_n_M2_n_time(-100, -50, 1000);
      move_n_M1_n_M2_n_time(100, 100, 1000);
      if(!(1 == mode)){
        Mini.RC4.set(180);
      }
      
      if(!(1 == mode)){
        delay(500);
        Mini.RC3.set(120);
      }
      touch_n_n(-60, -60);
      move_n_M1_n_M2_n_time(20, 20, 200);
      move_n_M1_n_M2_n_time(60, -65, 250);
      find_n(0.01);//找方塊
      if(!(mode==1)){
        Mini.RC3.set(0);
        delay(500);
      }
      move_n_M1_n_M2_n_time(60, 60, 200);
      move_n_M1_n_M2_n_time(-60, 65, 250);
      move_n_M1_n_M2_n_time(100, 98, 600);
    
      if(!(1 == mode))
      {
        delay(300);
        Mini.RC4.set(180);
        move_n_M1_n_M2_n_time(100, 100, 300);
        delay(300);
      }
      
      move_n_M1_n_M2_n_time(-100, -65, 2600);
      if(!(1 == mode))
      {
        Mini.RC3.set(120);
      }
      touch_n_n(-60,-60);
      move_n_M1_n_M2_n_time(20, 20, 200);
      move_n_M1_n_M2_n_time(60, -60, 350);
      find_n(0.1);//找方塊
      move_n_M1_n_M2_n_time(95, 100, 1300);
      move_n_M1_n_M2_n_time(-60, 65, 250);
      move_n_M1_n_M2_n_time(-100, -100, 1000);
      if(!(1 == mode))
      {
        Mini.RC3.set(60);
        Mini.RC4.set(180);
      }
      move_n_M1_n_M2_n_time(100, 100, 500);
      


    }
    else{
      if(chose == 2){
        light();
        
      }
      else{
        if(chose == 3){
          light();
        }
        else {
          if(chose == 4){
           light();
          }
          else{
            light();
          }
        }
      }
    }
  }
}

void con() {
  Mini.PS2.polling();
  powerleft = map(Mini.PS2.LY, 0, 255, 100, (-100));
  powerright = map(Mini.PS2.RY, 0, 255, 100, (-100));
  Mini.M1.set(powerleft);
  Mini.M2.set(powerright);
  if(Mini.PS2.R2)
  {
    Mini.RC1.set(40);
    Mini.RC2.set(140);
  }
  else
  {
    if(Mini.PS2.L1)
    {
      Mini.RC1.set(180);
      Mini.RC2.set(0);
    }else{
      Mini.RC1.set(172);
      Mini.RC2.set(8);
    }
    
  }
  if(Mini.PS2.L2)
  {
    Mini.RC4.set(45);
  }
  else
  {
    Mini.RC4.set(180);
  }
  if(Mini.PS2.UP)
  {
    basic = basic + -1;
  }
  else
  {
    if(Mini.PS2.DOWN)
    {
      basic = basic + 1;
    }
  }
  if(basic > 175)
  {
    basic = 175;
  }
  else
  {
    if(basic < 0)
    {
      basic = 0;
    }
  }
  if(Mini.PS2.CROSS)
  {
    basic = 175;
  }
  if(Mini.PS2.SQUARE)
  {
    basic = 155;
  }
  if(Mini.PS2.R1)
  {
    basic = 120;
  }
  Mini.RC3.set(basic);
}


void find_n(float number) {
  if  ( ! ( mode == 1 )){
    Mini.RC3.set(120);
    delay(200);
    int received_byte = -1;
      while (Serial.available() > 0) {
      Serial.read();
    }
    delay(500);
    
    while(!((123 == received_byte)||(mode == 1)))
    {
      X();
      if (Serial.available() > 0) {
      received_byte = Serial.read();
      X();
      }

      PD_followline_n_n_n(-20, number, 0);
    }
    if(!(mode==1)){
      move_n_M1_n_M2_n_time(0,0,0);
      Mini.RC3.set(155);
      delay(200);
      Mini.RC4.set(45);
      delay(500);
      received_byte = -1;
    }
  }
}

void test() {
  int received_byte;
  Serial.print("leftgray:");
  Serial.println(Mini.A1.getANG());
  delay(200);
  Serial.print("rightgray:");
  Serial.println(Mini.A2.getANG());
  Mini.RC3.set(120);
  if (Serial.available() > 0) {
    received_byte = Serial.read();
    X();
    Serial.println(received_byte);
    }

  
}



void setup()
{
  Mini.begin(LI_2, 0, 9600);
  Serial.begin(9600);
  Mini.PS2.begin();
  mode = 0;
  Mini.RC3.set(60);
  Mini.RC4.set(180);
  Mini.RC1.set(40);
  Mini.RC2.set(140);
  //choice();
  //deside();
}

void loop()
{
  con();
  //test();
}





