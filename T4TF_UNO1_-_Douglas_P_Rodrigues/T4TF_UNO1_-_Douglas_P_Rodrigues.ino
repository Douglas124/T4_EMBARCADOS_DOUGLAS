

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
  char BMP_PRESSAO;
  char DHT_TEMP;
  char DHT_UMIDADE;
  char GP2D12_DISTANCIA;
  char POSICAO_SERVO;
  char fim = '.';
}estrutura;
estrutura DADOS_UNO1;
int escreve_pos_servo=0;


//------------------------------------------------------------------------------------- FUNÇÕES 
//--------------------------------------------------- INICIA BMP180
void BMP_INIT(void){
  if (!BMP180.begin()) {
  Serial.println("algo de errado nao está certo.");
  while (1) {}
  }
}

//--------------------------------------------------- LEITURA BMP180
void LEITURA_BMP(void){
  DADOS_UNO1.BMP_PRESSAO = BMP180.readPressure()/1000;
}


//--------------------------------------------------- LEITURA DHT11
void LEITURA_DHT11(void){
  DADOS_UNO1.DHT_TEMP = dht.readTemperature();
  DADOS_UNO1.DHT_UMIDADE = dht.readHumidity();
  delay(250);
}

//--------------------------------------------------- LEITURA DISTANCIA
void LEITURA_GP2D12(void){
  int leit_aux = 0;
  char inteiro=0, resto=0, valor=0;

  leit_aux = analogRead(GP2D12_PIN);
  valor = (6787.0 /((float)leit_aux - 3.0)) - 4.0;

  inteiro = valor/10;
  resto = valor%10;

  DADOS_UNO1.GP2D12_DISTANCIA = inteiro*10+resto;
  
  
}


//--------------------------------------------------- ESCREVE MOTOR
void ESCREVE_MOTOR(int posicao_servo){
  escreve_pos_servo = map(posicao_servo , 0, 1023, 0, 180);      // scale it to use it with the servo (value between 0 and 180)
  meuservo.write(escreve_pos_servo );                             // sets the servo position according to the scaled value
  delay(15);                                                      // waits for the servo to get there
}

//--------------------------------------------------- ESCREVE LCD
void ESCREVE_LCD(){
 char buffer[30];

 lcd.setCursor(0,1); 
 sprintf(buffer,"T:%.2doC",DADOS_UNO1.DHT_TEMP);
 lcd.print(buffer);

 lcd.setCursor(8,1); 
 sprintf(buffer,"U:%.2d%%",DADOS_UNO1.DHT_UMIDADE);
 lcd.print(buffer);
 
 lcd.setCursor(0,2); 
 sprintf(buffer,"P:%.3d",DADOS_UNO1.BMP_PRESSAO);
 lcd.print(buffer);

 lcd.setCursor(8,2); 
 sprintf(buffer,"D:%.2dm",DADOS_UNO1.GP2D12_DISTANCIA);
 lcd.print(buffer);

 lcd.setCursor(10,2); 
 sprintf(buffer,"S:%.2d",DADOS_UNO1.POSICAO_SERVO);
 lcd.print(buffer);

}




//------------------------------------------------------------------------------------- SETUP
void setup() {
  // initialize digital pin LED_BUILTIN as an output.  
  dht.begin();
  BMP_INIT();
  meuservo.attach(SERVO_PIN);
  Serial.begin(9600);
 lcd.setCursor(0,0); 
  lcd.print("teste");
  
  
}





//------------------------------------------------------------------------------------- WHILE1
void loop() {
  LEITURA_BMP();
  LEITURA_DHT11();
  LEITURA_GP2D12();
  ESCREVE_LCD();

}