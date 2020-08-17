// Open Source
#include <Wire.h> //INCLUSÃO DE BIBLIOTECA
#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

#define pinSensor1 7

void setup () {
  pinMode (pinSensor1, INPUT);
  Serial.begin(9600);
  lcd.begin (16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY
  lcd.setBacklight(HIGH); //LIGA O BACKLIGHT (LUZ DE FUNDO)
}

void loop(){
  lcd.setCursor(0,0); //SETA A POSIÇÃO DO CURSOR
  lcd.print("DETECTANDO LINHA"); //IMPRIME O TEXTO NO DISPLAY LCD
  
  bool estadoSensor1 = digitalRead(pinSensor1);
  if (estadoSensor1) {
    Serial.println("LINHA PRETA");
    lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
    lcd.print("LINHA PRETA      "); //IMPRIME O TEXTO NO DISPLAY LCD
  }
  else {
    Serial.println ("FORA DA LINHA");
    lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
    lcd.print("FORA DA LINHA   "); //IMPRIME O TEXTO NO DISPLAY LCD
  }
  
}
  
