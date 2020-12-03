

//------------------------------------------------------------------------------------- INCLUDES


//------------------------------------------------------------------------------------- DEFINES






//------------------------------------------------------------------------------------- INICIALIZAÇÃO DAS BIBLIOTECAS



//------------------------------------------------------------------------------------- VAR GLOBAIS


typedef struct{
  char ENDERECO;
  char BMP_PRESSAO;
  char DHT_TEMP;
  char DHT_UMIDADE;
  char GP2D12_DISTANCIA;
  char POSICAO_SERVO;
  char fim = '.';
}estrutura;
estrutura DADOS_UNO1;

typedef struct{
  char ENDERECO;
  char STATUS_CONFIG_HORA;
  char DATA_HORA = 10;
  char DATA_MINUTO = 10;
  char DATA_SEGUNDO = 10;
  char DATA_DIA = 10;
  char DATA_MES =10 ;
  char DATA_ANO = 10;
  char LIGA_RELE_HORA = 10;
  char LIGA_RELE_MIN = 10;
  char LIGA_RELE_SEG = 12;
  char DESLIGA_RELE_HORA = 10;
  char DESLIGA_RELE_MIN = 10;
  char DESLIGA_RELE_SEG = 15;
  char SERVO;
  char LIGA_SERVO_HORA = 10;
  char LIGA_SERVO_MIN = 10;
  char LIGA_SERVO_SEG = 12;
  char DESLIGA_SERVO_HORA = 10;
  char DESLIGA_SERVO_MIN = 10;
  char DESLIGA_SERVO_SEG = 15;
  char fim = '.';
}estrutura2;
estrutura2 DADOS_UNO2RX, DADOS_UNO2;

typedef struct{
  char ENDERECO = '0';
  char BMP_PRESSAO = '5';
  char DHT_TEMP = '1';
  char DHT_UMIDADE = '2';
  char GP2D12_DISTANCIA = '3';
  char POSICAO_SERVO = '0';
  char STATUS_CONFIG_HORA = '0';
  char DATA_HORA = '5' ;
  char DATA_MINUTO = '5';
  char DATA_SEGUNDO = '5';
  char DATA_DIA = '5';
  char DATA_MES = '5';
  char DATA_ANO = '5';
  char LIGA_RELE_HORA = '5';
  char LIGA_RELE_MIN = '5';
  char LIGA_RELE_SEG = '5';
  char DESLIGA_RELE_HORA = '5';
  char DESLIGA_RELE_MIN = '5';
  char DESLIGA_RELE_SEG = '5';
  char SERVO = '0';
  char LIGA_SERVO_HORA = '5';
  char LIGA_SERVO_MIN = '5';
  char LIGA_SERVO_SEG = '5';
  char DESLIGA_SERVO_HORA = '5';
  char DESLIGA_SERVO_MIN = '5';
  char DESLIGA_SERVO_SEG = '5';
  char fim = '.';
}estrutura_completa;
estrutura_completa DADOS_GERAL_RX, DADOS_GERAL;

char dadoRx1, dadoRx2;


//------------------------------------------------------------------------------------- FUNÇÕES 
//--------------------------------------------------- SET DADOS DO UNO1 NA STRUCT GERAL
void DADOS_UNO1_TO_GERAL(void){
  DADOS_GERAL_RX.BMP_PRESSAO = DADOS_UNO1.BMP_PRESSAO;
  DADOS_GERAL_RX.DHT_TEMP = DADOS_UNO1.DHT_TEMP;
  DADOS_GERAL_RX.DHT_UMIDADE = DADOS_UNO1.DHT_UMIDADE;
  DADOS_GERAL_RX.GP2D12_DISTANCIA = DADOS_UNO1.GP2D12_DISTANCIA;
  DADOS_GERAL_RX.ENDERECO = '0';
  
}

//--------------------------------------------------- SET UNO1
void SET_UNO1(void){
  DADOS_UNO1.ENDERECO = '1';
  DADOS_UNO1.POSICAO_SERVO = DADOS_GERAL_RX.POSICAO_SERVO;
}

//--------------------------------------------------- SET UNO2
void SET_UNO2(void){
  DADOS_UNO2.DATA_HORA = DADOS_GERAL_RX.DATA_HORA;
  DADOS_UNO2.DATA_MINUTO = DADOS_GERAL_RX.DATA_MINUTO;
  DADOS_UNO2.DATA_SEGUNDO = DADOS_GERAL_RX.DATA_SEGUNDO;
  DADOS_UNO2.DATA_DIA = DADOS_GERAL_RX.DATA_DIA;
  DADOS_UNO2.DATA_MES = DADOS_GERAL_RX.DATA_MES;
  DADOS_UNO2.DATA_ANO = DADOS_GERAL_RX.DATA_ANO;
  DADOS_UNO2.LIGA_RELE_HORA = DADOS_GERAL_RX.LIGA_RELE_HORA;
  DADOS_UNO2.LIGA_RELE_MIN = DADOS_GERAL_RX.LIGA_RELE_MIN;
  DADOS_UNO2.LIGA_RELE_SEG = DADOS_GERAL_RX.LIGA_RELE_SEG;
  DADOS_UNO2.DESLIGA_RELE_HORA = DADOS_GERAL_RX.DESLIGA_RELE_HORA;
  DADOS_UNO2.DESLIGA_RELE_MIN = DADOS_GERAL_RX.DESLIGA_RELE_MIN;
  DADOS_UNO2.DESLIGA_RELE_SEG = DADOS_GERAL_RX.DESLIGA_RELE_SEG;
  DADOS_UNO2.SERVO = DADOS_GERAL_RX.SERVO;
  DADOS_UNO2.LIGA_SERVO_HORA = DADOS_GERAL_RX.LIGA_SERVO_HORA;
  DADOS_UNO2.LIGA_SERVO_MIN = DADOS_GERAL_RX.LIGA_SERVO_MIN;
  DADOS_UNO2.LIGA_SERVO_SEG = DADOS_GERAL_RX.LIGA_SERVO_SEG;
  DADOS_UNO2.DESLIGA_SERVO_HORA = DADOS_GERAL_RX.LIGA_SERVO_HORA;
  DADOS_UNO2.DESLIGA_SERVO_MIN = DADOS_GERAL_RX.DESLIGA_SERVO_MIN;
  DADOS_UNO2.DESLIGA_SERVO_SEG = DADOS_GERAL_RX.DESLIGA_SERVO_SEG;
  DADOS_UNO2.STATUS_CONFIG_HORA = '1';
  DADOS_UNO2.ENDERECO = '2';
}


//------------------------------------------------------------------------------------- SETUP
void setup() {
  Serial.begin(9600);    // serial QT
  Serial1.begin(9600);   // serial uno1
  Serial2.begin(9600);   // seruial uno2
  
  
}





//------------------------------------------------------------------------------------- WHILE1
void loop() {
//------------------------------- recebe msg QT
  if (Serial.available()){
    Serial.readBytesUntil('.',(char*)&DADOS_GERAL_RX, sizeof(DADOS_GERAL_RX));
    if (DADOS_GERAL_RX.ENDERECO == '1'){
     SET_UNO1();
     Serial1.write((char*)&DADOS_UNO1, sizeof(DADOS_UNO1)); 
    }
    else if (DADOS_GERAL_RX.ENDERECO == '2'){
     SET_UNO2();
     Serial2.write((char*)&DADOS_UNO2, sizeof(DADOS_UNO2));
    }
  }

  if (Serial1.available()){
   Serial1.readBytesUntil('.',(char*)&DADOS_UNO1, sizeof(DADOS_UNO1));
   DADOS_UNO1_TO_GERAL();
//   Serial.print(DADOS_GERAL_RX.BMP_PRESSAO, DEC);
//   Serial.print(DADOS_GERAL_RX.DHT_TEMP, DEC);
//   Serial.print(DADOS_GERAL_RX.DHT_UMIDADE, DEC);
//   Serial.println(DADOS_GERAL_RX.GP2D12_DISTANCIA, DEC);
  }

  
   Serial.write((char*)&DADOS_GERAL_RX, sizeof(DADOS_GERAL_RX));

}
