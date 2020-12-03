

//------------------------------------------------------------------------------------- INCLUDES


//------------------------------------------------------------------------------------- DEFINES






//------------------------------------------------------------------------------------- INICIALIZAÇÃO DAS BIBLIOTECAS



//------------------------------------------------------------------------------------- VAR GLOBAIS


typedef struct{
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

char dadoRx1, dadoRx2;


//------------------------------------------------------------------------------------- FUNÇÕES 




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
    dadoRx1 = Serial.read();
    if (dadoRx1 == 'A'){
    Serial1.write(dadoRx1);
    dadoRx1 = 0;
    }
    else if (dadoRx1 == 'B'){
    Serial1.write(dadoRx1);
    dadoRx1 = 0;
    }
    else if (dadoRx1 == 'C'){
    Serial1.write(dadoRx1);
    dadoRx1 = 0;
    }
    else if (dadoRx1 == 'D'){
    Serial1.write(dadoRx1);
    dadoRx1 = 0;
    }
    else if (dadoRx1 == 'E'){
    Serial2.write(dadoRx1);
    dadoRx1 = 0;
    }
    else if (dadoRx1 == 'F'){
    Serial2.write(dadoRx1);
    dadoRx1 = 0;
    }
  }

  if (Serial1.available()){   
    dadoRx2 = Serial1.read();
    Serial.write(dadoRx2);
    dadoRx2 = 0;
  }
  

}
