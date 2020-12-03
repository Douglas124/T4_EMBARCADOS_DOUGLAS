

//------------------------------------------------------------------------------------- INCLUDES
#include <LiquidCrystal.h>
#include <Servo.h>
#include <Wire.h>
#include <DS1307.h>


//------------------------------------------------------------------------------------- DEFINES

#define SERVO_PIN 9
#define RELE_PIN 7




//------------------------------------------------------------------------------------- INICIALIZAÇÃO DAS BIBLIOTECAS
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


//------------------------------------------------------------------------------------- VAR GLOBAIS
// these constants won't change.  But you can change the size of
// your LCD using them:
const int numRows = 4;
const int numCols = 20;
static int estado_codigo=0, angulo, aux_hora=0, RL_STATUS=0;
Servo meuservo;
DS1307 clock;//define a object of DS1307 class

typedef struct{
  char ENDERECO;
  char STATUS_CONFIG_HORA;
  char DATA_HORA = 0;
  char DATA_MINUTO = 0;
  char DATA_SEGUNDO = 0;
  char DATA_DIA = 0;
  char DATA_MES =0 ;
  char DATA_ANO = 0;
  char LIGA_RELE_HORA = 0;
  char LIGA_RELE_MIN = 0;
  char LIGA_RELE_SEG = 0;
  char DESLIGA_RELE_HORA = 0;
  char DESLIGA_RELE_MIN = 0;
  char DESLIGA_RELE_SEG = 0;
  char SERVO;
  char LIGA_SERVO_HORA = 0;
  char LIGA_SERVO_MIN = 0;
  char LIGA_SERVO_SEG = 0;
  char DESLIGA_SERVO_HORA = 0;
  char DESLIGA_SERVO_MIN = 0;
  char DESLIGA_SERVO_SEG = 0;
  char fim = '.';
}estrutura;
estrutura DADOS_UNO2RX, DADOS_UNO2;
int escreve_pos_servo=0;
char dadoRx;


//------------------------------------------------------------------------------------- FUNÇÕES 


//--------------------------------------------------- ESCREVE A HORA NA SERIAL
void printTime(){
  if (aux_hora == 0){
  lcd.setCursor(2,0); 
  lcd.print("Configure a Hora!");

  }
  else {
  clock.getTime();
  lcd.setCursor(1,0); 
  lcd.print(clock.hour, DEC);
  lcd.print(":");
  lcd.print(clock.minute, DEC);
  lcd.print(":");
  lcd.print(clock.second, DEC);

  
  lcd.setCursor(10,0); 
  lcd.print(clock.month, DEC);
  lcd.print("/");
  lcd.print(clock.dayOfMonth, DEC);
  lcd.print("/");
  lcd.print(clock.year, DEC);

  delay(50);

  }

}

//--------------------------------------------------- ESCREVE LCD
void ESCREVE_LCD(){
 char buffer[30];

 lcd.setCursor(0,1); 
 sprintf(buffer,"M:%.2d:%.2d:%.2d",DADOS_UNO2.LIGA_SERVO_HORA,DADOS_UNO2.LIGA_SERVO_MIN,DADOS_UNO2.LIGA_SERVO_SEG);
 lcd.print(buffer);
 lcd.setCursor(11,1); 
 sprintf(buffer,"%.02d:%.2d:%.2d",DADOS_UNO2.DESLIGA_SERVO_HORA,DADOS_UNO2.DESLIGA_SERVO_MIN,DADOS_UNO2.DESLIGA_SERVO_SEG);
 lcd.print(buffer);
 
 lcd.setCursor(0,2); 
 sprintf(buffer,"R:%.2d:%.2d:%.2d",(int)DADOS_UNO2.LIGA_RELE_HORA,(int)DADOS_UNO2.LIGA_RELE_MIN,(int)DADOS_UNO2.LIGA_RELE_SEG);
 lcd.print(buffer);
 lcd.setCursor(11,2); 
 sprintf(buffer,"%.2d:%.2d:%.2d",DADOS_UNO2.DESLIGA_RELE_HORA,DADOS_UNO2.DESLIGA_RELE_MIN,DADOS_UNO2.DESLIGA_RELE_SEG);
 lcd.print(buffer);

 lcd.setCursor(0,3); 
 sprintf(buffer,"Motor:%.2d",DADOS_UNO2.SERVO);
 lcd.print(buffer);


 lcd.setCursor(13,3); 
 if (RL_STATUS == 1)  sprintf(buffer,"RELE:O");
 else if (RL_STATUS == 2)  sprintf(buffer,"RELE:C");
 lcd.print(buffer);


}


//--------------------------------------------------- ESCREVE MOTOR
void ESCREVE_MOTOR(int posicao_servo){
  escreve_pos_servo = map(posicao_servo , 0, 180, 0, 255);      // scale it to use it with the servo (value between 0 and 180)
  meuservo.write(posicao_servo);                             // sets the servo position according to the scaled value
  DADOS_UNO2.SERVO = posicao_servo;   
  delay(15);                                                      // waits for the servo to get there
}


//--------------------------------------------------- CONFIGURA HORA
void CONFIG_HORA (void){
  clock.fillByYMD(DADOS_UNO2.DATA_ANO,DADOS_UNO2.DATA_MES,DADOS_UNO2.DATA_DIA);//Jan 19,2013
  clock.fillByHMS(DADOS_UNO2.DATA_HORA,DADOS_UNO2.DATA_MINUTO,DADOS_UNO2.DATA_SEGUNDO);//15:28 30"
  clock.setTime();//write time to the RTC chip
  DADOS_UNO2.STATUS_CONFIG_HORA = '0';
  aux_hora = 1;
  lcd.clear();
  delay(50);
}


//--------------------------------------------------- ACIONA RELE
void ACIONA_RELE(void){
  clock.getTime();
  lcd.setCursor(8,1); 
  
  if ((clock.hour >= (int)DADOS_UNO2.LIGA_RELE_HORA)){
    if ((clock.minute >= (int)DADOS_UNO2.LIGA_RELE_MIN)){
      if((clock.second >= (int)DADOS_UNO2.LIGA_RELE_SEG) && (clock.second <= (int)DADOS_UNO2.LIGA_RELE_SEG+3)){
      digitalWrite(RELE_PIN, HIGH);
      RL_STATUS=1;
      }
    }
  }

  if ((clock.hour >= (int)DADOS_UNO2.DESLIGA_RELE_HORA)){
    if ((clock.minute >= (int)DADOS_UNO2.DESLIGA_RELE_MIN)){
      if((clock.second >=(int)DADOS_UNO2.DESLIGA_RELE_SEG) && (clock.second <= (int)DADOS_UNO2.DESLIGA_RELE_SEG+3)){
      digitalWrite(RELE_PIN, LOW);
      RL_STATUS=2;
      }
    }
  }
  
}

//--------------------------------------------------- ACIONA SERVO
void ACIONA_SERVO(void){
  clock.getTime();
  
  if ((clock.hour >= (int)DADOS_UNO2.LIGA_SERVO_HORA)){
    if ((clock.minute >= (int)DADOS_UNO2.LIGA_SERVO_MIN)){
      if((clock.second >= (int)DADOS_UNO2.LIGA_SERVO_SEG) && (clock.second <= (int)DADOS_UNO2.LIGA_SERVO_SEG+3)){
      ESCREVE_MOTOR(0);
      }
    }
  }

  if ((clock.hour >= (int)DADOS_UNO2.DESLIGA_SERVO_HORA)){
    if ((clock.minute >= (int)DADOS_UNO2.DESLIGA_SERVO_MIN)){
      if((clock.second >=(int)DADOS_UNO2.DESLIGA_SERVO_SEG) && (clock.second <= (int)DADOS_UNO2.DESLIGA_SERVO_SEG+3)){
      ESCREVE_MOTOR(90);
      }
    }
  }
  
}




//------------------------------------------------------------------------------------- SETUP
void setup() {
  meuservo.attach(SERVO_PIN);
  lcd.begin(numCols, numRows);
  Serial.begin(9600);
  clock.begin();
  pinMode(RELE_PIN, OUTPUT);

  
}





//------------------------------------------------------------------------------------- WHILE1
void loop() {
    printTime();
    ACIONA_RELE();
    ACIONA_SERVO();
    ESCREVE_LCD();
   if (Serial.available()){
      Serial.readBytesUntil('.',(char*)&DADOS_UNO2, sizeof(DADOS_UNO2));
      if (DADOS_UNO2.ENDERECO == '2'){
          if (DADOS_UNO2.STATUS_CONFIG_HORA == '1'){
          CONFIG_HORA();
        }
      }
    }
}
