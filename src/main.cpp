#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Saidas digitais

#define LED_1 19
#define LED_2 18
#define LED_3 5
#define LED_4 4
#define LED_5 2

// Entradas digitais

#define BT_1 35
#define BT_2 32
#define BT_3 27
#define BT_4 25
#define BT_5 26

// Entradas analógicas

#define LDR 34

bool BT_1_ST = false;
bool BT_2_ST = false;

int LUMINOSIDADE = 0;
const int PWM_LED = 0;
int intensidade_led = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);


  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);

  pinMode(BT_1, INPUT);
  pinMode(BT_2, INPUT);
  pinMode(BT_3, INPUT);
  pinMode(BT_4, INPUT);
  pinMode(BT_5, INPUT);

  ledcSetup(PWM_LED, 500, 12);
  ledcAttachPin(LED_1, 0);
}   
  

void loop() {
  LUMINOSIDADE = analogRead(LDR);
  ledcWrite(PWM_LED, LUMINOSIDADE);

  if (LUMINOSIDADE > 3000)
  {
    lcd.setCursor(0, 0);
    lcd.print("ESCURO!         ");
    lcd.setCursor(0, 1);
    lcd.print("ANOITECEU!      ");
  }

  if (LUMINOSIDADE > 1500 && LUMINOSIDADE <= 3000)
  {
    lcd.setCursor(0, 0);
    lcd.print("ESCURECENDO     ");
    lcd.setCursor(0, 1);
    lcd.print("NUBLADO         ");
  }

  if (LUMINOSIDADE > 0 && LUMINOSIDADE <= 1500)
  {
    lcd.setCursor(0, 0);
    lcd.print("MUITO CLARO     ");
    lcd.setCursor(0, 1);
    lcd.print("ENSOLARADO      ");;
  }

 

 
}