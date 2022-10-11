#include <LiquidCrystal_I2C.h>

#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int cambien_vao = 5; //Chân cảm biến vào nối chân số 5 Arduino
int cambien_ra = 2; //chân cảm biến ra nối chân số 2
int giatri_vao;
int cambien1 = 6;
int cambien2 = 7;
int cambien3 = 8;
int cambien4 = 9;
int giatri_ra;
int gtmacdinh1 = 1;
int gtmacdinh2 = 1;
int giatri1;
int giatri2;
int giatri3;
int giatri4;
int dem;

void setup() 
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Full Slots :");
  lcd.setCursor(0,1);
  lcd.print("Empty slots:");
  Serial.begin(9600);

  pinMode(cambien_vao, INPUT);
  pinMode(cambien_ra, INPUT);
  pinMode(cambien1, INPUT);
  pinMode(cambien2, INPUT);
  pinMode(cambien3, INPUT);
  pinMode(cambien4, INPUT);

}

void loop() 
{
  giatri_vao = digitalRead(cambien_vao);
  giatri_ra = digitalRead(cambien_ra);
  giatri1 = digitalRead(cambien1);
  giatri2 = digitalRead(cambien2);
  giatri3 = digitalRead(cambien3);
  giatri4 = digitalRead(cambien4);
  if (giatri_vao != gtmacdinh1)
  {
    if (giatri_vao == 0)
      {
        dem++;
      }
    gtmacdinh1 = giatri_vao;
  }
   if (giatri_ra != gtmacdinh2)
  {
    if (giatri_ra == 0)
      {
        dem--;
      }
    gtmacdinh2 = giatri_ra;
  }
  if (dem <= 0)
  {dem = 0;
  }
  if (giatri1!=0)
  { giatri1=1;}
  lcd.setCursor(12,1);
  lcd.print(giatri1);
  if (giatri2!=0)
  { giatri2=2;}
  lcd.setCursor(13,1);
  lcd.print(giatri2);
  if (giatri3!=0)
  { giatri3=3;}
  lcd.setCursor(14,1);
  lcd.print(giatri3);
  if (giatri4!=0)
  { giatri4=4;}
  lcd.setCursor(15,1);
  lcd.print(giatri4);
  lcd.setCursor(13,0);
  lcd.print(dem);
  delay(200);

}
