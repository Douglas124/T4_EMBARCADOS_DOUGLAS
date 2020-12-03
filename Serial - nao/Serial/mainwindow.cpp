#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QtDebug>
#include <QTimer>
#include <time.h>

typedef struct{
  char ENDERECO;
  char BMP_PRESSAO;
  char DHT_TEMP;
  char DHT_UMIDADE;
  char GP2D12_DISTANCIA;
  char POSICAO_SERVO;
  char STATUS_CONFIG_HORA;
  char DATA_HORA ;
  char DATA_MINUTO;
  char DATA_SEGUNDO;
  char DATA_DIA;
  char DATA_MES;
  char DATA_ANO;
  char LIGA_RELE_HORA;
  char LIGA_RELE_MIN;
  char LIGA_RELE_SEG;
  char DESLIGA_RELE_HORA;
  char DESLIGA_RELE_MIN;
  char DESLIGA_RELE_SEG;
  char SERVO;
  char LIGA_SERVO_HORA;
  char LIGA_SERVO_MIN;
  char LIGA_SERVO_SEG;
  char DESLIGA_SERVO_HORA;
  char DESLIGA_SERVO_MIN;
  char DESLIGA_SERVO_SEG;
  char fim = '.';
}estrutura_completa;
estrutura_completa DADOS_GERAL_RX, DADOS_GERAL;


struct tm * timeinfo;

QTimer *timer = new QTimer(); //cria novo timer

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
    connect(timer, SIGNAL(timeout()),SLOT(timer_teste()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    serial->setPortName("COM9");
    serial->setBaudRate(9600);
    serial->setDataBits(static_cast<QSerialPort::DataBits>(8));
    serial->setParity(static_cast<QSerialPort::Parity>(0));
    serial->setStopBits(static_cast<QSerialPort::StopBits>(1));
    serial->setFlowControl(static_cast<QSerialPort::FlowControl>(0));
    if (serial->open(QIODevice::ReadWrite))
    {
        qDebug("Porta Aberta");
        ui->label->setText("Status da Porta : ABERTA");
        timer->start(1000);
    }
    else
    {
        qDebug("Não Abriu");
        ui->label->setText("Status da Porta : FECHADA");
    }
}

void MainWindow::timer_teste()
{
    time_t vertempo;
    char buffer[50];
    QString msg;
    time(&vertempo);
    timeinfo = localtime (&vertempo);
    sprintf(buffer,"%02d:%02d:%02d",timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
    qDebug("%s",buffer);
    sprintf(buffer,"%02d/%02d/%04d",timeinfo->tm_mday,timeinfo->tm_mon+1,(timeinfo->tm_year)+1900);
    qDebug("%s",buffer);
}
void MainWindow::readData()
{

    char buffer[50];
    if(serial->bytesAvailable() >= sizeof(DADOS_GERAL)){
       serial->read((char*)&DADOS_GERAL,sizeof(DADOS_GERAL));

       sprintf(buffer,"%d",DADOS_GERAL.DHT_TEMP);
       qDebug("%s",buffer);
       ui->LCD_TEMP->display(DADOS_GERAL.DHT_TEMP);
       ui->LCD_UMI->display(DADOS_GERAL.DHT_UMIDADE);
       ui->LCD_PRESS->display(DADOS_GERAL.BMP_PRESSAO);
       ui->LCD_DISTANCIA->display(DADOS_GERAL.GP2D12_DISTANCIA);
    }


}

void MainWindow::on_pushButton_2_clicked()
{
    char buffer[30];
    buffer[0]='1';
 //   DADOS_GERAL.LIGA_SERVO_HORA = ui->SPIN_HORA_LIGA_M->text();

    if(serial->isOpen())// se porta aberta
    {
        serial->write(buffer,1);
    }
}
