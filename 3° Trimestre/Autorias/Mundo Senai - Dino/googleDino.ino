#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int score = 0;
int hiscore = 0;
int speeds = 400;
boolean butt;
int but = 2;
int buttt = 0;
int cact = 15;
int gameover = 0;
int valdino;
int valcac;
int buzzer = 3;

byte dino[8] = {
  0b01110,
  0b01011,
  0b01111,
  0b00110,
  0b10111,
  0b11110,
  0b01010,
  0b01000
};
byte dino2[8] = {
  0b01110,
  0b01011,
  0b01111,
  0b00110,
  0b10111,
  0b11110,
  0b01010,
  0b00010
};
byte vazio[8] = {
  0000000,
  0000000,
  0000000,
  0000000,
  0000000,
  0000000,
  0000000,
  0000000
};

byte cacti[8] = {
  0b00100,
  0b00101,
  0b10101,
  0b10101,
  0b10111,
  0b11100,
  0b00100,
  0b00000
};

byte block[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  Serial.begin(9600);
  lcd.createChar(0, dino);
  lcd.createChar(1, cacti);
  lcd.createChar(2, block);
  lcd.createChar(3, vazio);
  lcd.createChar(4, dino2);
  pinMode(but, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //vars de config iniciais
  butt = digitalRead(but);
  lcd.setBacklight(HIGH);

  //se o gameover ocorrer
  if (gameover == 0) {
    lcd.clear();
    tone(buzzer, 250);
    delay(200);
    tone(buzzer, 150);
    delay(200);
    noTone(buzzer);
    if (score > hiscore) {
      hiscore = score;
    }
    while (butt == LOW) {
      butt = digitalRead(but);
      lcd.setCursor(0, 0);
      lcd.print("gameover");
      lcd.setCursor(9, 0);
      lcd.print("HI:" );
      lcd.setCursor(12, 0);
      lcd.print(hiscore);
      lcd.setCursor(3, 1);
      lcd.print("PLAY AGAIN");
      lcd.setCursor(2, 1);
      lcd.print(">");
      delay(200);
      lcd.setCursor(2, 1);
      lcd.write(byte(3));
      butt = digitalRead(but);
      delay(200);
      butt = digitalRead(but);
      delay(200);
    }
    //restart
    if (butt == HIGH) {
      gameover = 1;
    }
  }
  //var pro cac andar e se o gameover for falso
  if (gameover == 1) {
    lcd.clear();
    speeds = 400;
    score = 0;
    while (cact >= 0 && gameover == 1) {
      if (valcac == 1 && valdino == 1) {
        gameover = 0;
      }
      lcd.setCursor(1, 1);//só pra arrumar bugzin de árvore travada
      lcd.write(byte(3));

      butt = digitalRead(but);
      lcd.setCursor(9, 0);
      lcd.print("sc:");
      lcd.setCursor(12, 0);
      lcd.print(score);
      score = score + 10; //aumenta score

      if (speeds > 50) {//aumenta a speed
        speeds = speeds - 5;
      }

      lcd.setCursor(cact, 1);
      lcd.write(byte(1));
      lcd.write(byte(3));
      cact--;
      lcd.setCursor(0, 0);//anim dino2
      lcd.write(byte(3));
      lcd.setCursor(0, 1);
      lcd.write(byte(4));
      delay(speeds / 2);
      valcac = 0;
      if (cact == 0) {
        valcac = 1;
        lcd.setCursor(0, 1);
        lcd.write(byte(3));
        cact = 15;
      }
      if (butt == HIGH && buttt == 1) {
        tone(buzzer, 550);
        buttt = 0;
        valdino = 0;
        lcd.setCursor(0, 1);
        lcd.write(byte(3));
        lcd.setCursor(0, 0);
        lcd.write(byte(0));
        delay(200);
        noTone(buzzer);
      } else {
        buttt = 1;
        valdino = 1;
        lcd.setCursor(0, 0);
        lcd.write(byte(3));
        lcd.setCursor(0, 1);
        lcd.write(byte(0));//anim dino1
        delay(speeds / 2);
      }
    }//cac
  }//gameover
}//void
