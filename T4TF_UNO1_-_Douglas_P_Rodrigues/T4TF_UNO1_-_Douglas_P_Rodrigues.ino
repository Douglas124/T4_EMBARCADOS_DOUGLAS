

//------------------------------------------------------------------------------------- INCLUDES
#include <LiquidCrystal.h>
#include <Servo.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085.h>

//------------------------------------------------------------------------------------- DEFINES
#define DHTTYPE DHT11   // DHT 11
#define DHTPIN 7     
#define GP2D12_PIN A1
#define SERVO_PIN 9




//------------------------------------------------------------------------------------- INICIALIZAÇÃO DAS BIBLIOTECAS
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP085 BMP180;


//------------------------------------------------------------------------------------- VAR GLOBAIS
// these constants won't change.  But you can change the size of
// your LCD using them:
const int numRows = 2;
const int numCols = 16;
static int estado_codigo=0, angulo;
Servo meuservo;

typedef struct{
  char ENDERECO = '0';
  char BMP_PRESSAO = '5';
  char DHT_TEMP = '5';
  char DHT_UMIDADE = '5';
  char GP2D12_DISTANCIA = '5';
  char POSICAO_SERVO = '5';
  char fim = '.';
}estrutura;
estrutura DADOS_UNO1;
int escreve_pos_servo=0;
char dadoRx;


//------------------------------------------------------------------------------------- FUNÇÕES 
//--------------------------------------------------- INICIA BMP180
void BMP_INIT(void){
  if (!BMP180.begin()) {
  while (1) {}
  }
}

//--------------------------------------------------- LEITURA BMP180
void LEITURA_BMP(void){
  DADOS_UNO1.BMP_PRESSAO = (int)(BMP180.readPressure()/1000);
}


//--------------------------------------------------- LEITURA DHT11
void LEITURA_DHT11(void){
  DADOS_UNO1.DHT_TEMP = (int)(dht.readTemperature());
  DADOS_UNO1.DHT_UMIDADE = (int)(dht.readHumidity());
  delay(250);
}

//--------------------------------------------------- LEITURA DISTANCIA
void LEITURA_GP2D12(void){
  int leit_aux;
  char inteiro=0, resto=0, valor=0;

  leit_aux = analogRead(GP2D12_PIN);
  valor = (6787.0 /((float)leit_aux - 3.0)) - 4.0;

  inteiro = valor/10;
  resto = valor%10;

  DADOS_UNO1.GP2D12_DISTANCIA = (int)(inteiro*10+resto);
  
  
}


//--------------------------------------------------- ESCREVE MOTOR
void ESCREVE_MOTOR(void){
  meuservo.write(DADOS_UNO1.POSICAO_SERVO);
  delay(15);                                                      // waits for the servo to get there
}

//--------------------------------------------------- ESCREVE LCD
void ESCREVE_LCD(){
 char buffer[30];

 lcd.setCursor(0,0); 
 sprintf(buffer,"%.2doC",DADOS_UNO1.DHT_TEMP);
 lcd.print(buffer);

 lcd.setCursor(6,0); 
 sprintf(buffer,"%.2d%%",DADOS_UNO1.DHT_UMIDADE);
 lcd.print(buffer);
 
 lcd.setCursor(12,0); 
 sprintf(buffer,"%.2dm",DADOS_UNO1.GP2D12_DISTANCIA);
 lcd.print(buffer);
 
 lcd.setCursor(0,1); 
 sprintf(buffer,"P:%.4d",DADOS_UNO1.BMP_PRESSAO);
 lcd.print(buffer);

 lcd.setCursor(10,1); 
 sprintf(buffer,"S:%.2d",DADOS_UNO1.POSICAO_SERVO);
 lcd.print(buffer);

}




//------------------------------------------------------------------------------------- SETUP
void setup() {
  // initialize digital pin LED_BUILTIN as an output.  
  dht.begin();
  BMP_INIT();
  meuservo.attach(SERVO_PIN);
  lcd.begin(numCols, numRows);
  Serial.begin(9600);
  
  
}





//------------------------------------------------------------------------------------- WHILE1
void loop() {
  LEITURA_BMP();
  LEITURA_DHT11();
  LEITURA_GP2D12();
  ESCREVE_LCD();

  if (Serial.available()){
      Serial.readBytesUntil('.',(char*)&DADOS_UNO1, sizeof(DADOS_UNO1));
      if (DADOS_UNO1.ENDERECO == '1'){
        ESCREVE_MOTOR();      
      }
       
    }

    Serial.write((char*)&DADOS_UNO1, sizeof(DADOS_UNO1)); 
    delay(500);
}
