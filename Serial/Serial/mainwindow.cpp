#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QtDebug>
#include <QTimer>
#include <time.h>

struct tm * timeinfo;

QTimer *timer = new QTimer(); //cria novo timer

typedef struct{
  char nome[20];
  char cargo[20];
  char matricula[10];
  char hora_entrada[12];
  char data_entrada[12];
  char hora_saida[12];
  char data_saida[12];
  char aux_cadastro; // N = Nao cadastrado, E = Escrever cadastro, L = Ler cadastro, C = Clear estrutura, A = acesso
  char aux_acesso;   // I = entra, O = saida
  char fim = '.';
}estrutura;

estrutura usuario,usuarioRX;
static int estado_codigo=0;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
    connect(timer, SIGNAL(timeout()),SLOT(timer_teste()));

    ui->FOTO->setVisible(false);

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BOTAO_CONN_clicked()
{
    serial->setPortName("COM7");
    serial->setBaudRate(9600);
    serial->setDataBits(static_cast<QSerialPort::DataBits>(8));
    serial->setParity(static_cast<QSerialPort::Parity>(0));
    serial->setStopBits(static_cast<QSerialPort::StopBits>(1));
    serial->setFlowControl(static_cast<QSerialPort::FlowControl>(0));
    if (serial->open(QIODevice::ReadWrite))
    {
        qDebug("Porta Aberta");
        ui->label_STSPORTA->setText("Status da Porta : ABERTA");
        timer->start(1000);
    }
    else
    {
        qDebug("Não Abriu");
        ui->label_STSPORTA->setText("Status da Porta : FECHADA");
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
    // qDebug("%s",buffer);
    sprintf(buffer,"%02d/%02d/%04d",timeinfo->tm_mday,timeinfo->tm_mon+1,(timeinfo->tm_year)+1900);
    // qDebug("%s",buffer);
}
void MainWindow::readData()
{
    char buffer[30];
    QString msg,msg2;
    msg.clear();
    msg2.clear();
    if(serial->bytesAvailable() >= sizeof(estrutura)){
       serial->read((char*)&usuarioRX,sizeof(estrutura));
       if (usuarioRX.aux_cadastro == 'N'){
           QMessageBox messageBox(QMessageBox::Question,
           tr("Não há usuario cadastrado."),
           tr("Deseja cadastrar?"),
           QMessageBox::Yes | QMessageBox::No,
           NULL);
           messageBox.setButtonText(QMessageBox::Yes, tr("Sim!"));
           messageBox.setButtonText(QMessageBox::No, tr("Não!"));
           if (messageBox.exec() == QMessageBox::Yes) {
               ui->LE_NOME->setReadOnly(false);
               ui->LE_CARGO->setReadOnly(false);
               ui->LE_MATRICULA->setReadOnly(false);
               ui->LE_NOME->clear();
               ui->LE_CARGO->clear();
               ui->LE_MATRICULA->clear();
               ui->LE_ENTRADA->clear();
               ui->LE_SAIDA->clear();
            }

           qDebug("sem usuario");
           ui->LE_NOME->clear();
           ui->LE_CARGO->clear();
           ui->LE_MATRICULA->clear();
           ui->LE_ENTRADA->clear();
           ui->LE_SAIDA->clear();
       }
        else {
            ui->LE_NOME->clear();
            ui->LE_CARGO->clear();
            ui->LE_MATRICULA->clear();
            ui->LE_ENTRADA->clear();
            ui->LE_SAIDA->clear();

            strcpy(usuario.nome,usuarioRX.nome);
            strcpy(usuario.matricula,usuarioRX.matricula);
            strcpy(usuario.cargo,usuarioRX.cargo);
            strcpy(usuario.hora_entrada,usuarioRX.hora_entrada);
            strcpy(usuario.hora_saida,usuarioRX.hora_saida);
            strcpy(usuario.data_entrada,usuarioRX.data_entrada);
            strcpy(usuario.data_saida,usuarioRX.data_saida);

            ui->LE_NOME->setText(usuario.nome);
            ui->LE_MATRICULA->setText(usuario.matricula);
            ui->LE_CARGO->setText(usuario.cargo);

            msg.append(usuario.hora_entrada);
            msg.append(" - ");
            msg.append(usuario.data_entrada);
            ui->LE_ENTRADA->setText(msg);

            msg2.append(usuario.hora_saida);
            msg2.append(" - ");
            msg2.append(usuario.data_saida);
            ui->LE_SAIDA->setText(msg2);

            ui->FOTO->setVisible(true);
            estado_codigo = 1;
            ui->BOTAO_ENVIA->setText("Entrar/Sair");

         }
    serial->flush();
    }
}

void MainWindow::on_BOTAO_ENVIA_clicked()
{
    char buffer[30];
    QString nome, cargo, matricula, entrada, saida,msg,msg2;
    msg.clear();
    msg2.clear();
    // buffer[0]='1';
   // sprintf(buffer,"%02d:%02d:%02d\r",timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
    if (estado_codigo == 0){
    nome = ui->LE_NOME->text();
    cargo = ui->LE_CARGO->text();
    matricula =ui->LE_MATRICULA->text();
    entrada = ui->LE_ENTRADA->text();
    saida = ui->LE_SAIDA->text();

    strcpy(usuario.nome,nome.toLatin1());
    usuario.nome[nome.size()+1] = '\0';
    strcpy(usuario.cargo, cargo.toLatin1());
    usuario.cargo[cargo.size()+1] = '\0';
    strcpy(usuario.matricula, matricula.toLatin1());
    usuario.matricula[matricula.size()+1] = '\0';
    usuario.aux_cadastro = 'E';
    qDebug("Escrevendo");
    if(serial->isOpen())// se porta aberta
    {
        serial->write((char*)&usuario,sizeof(usuario));
    }

    ui->LE_NOME->setReadOnly(true);
    ui->LE_CARGO->setReadOnly(true);
    ui->LE_MATRICULA->setReadOnly(true);
    estado_codigo = 1;
    ui->BOTAO_ENVIA->setText("Entrar/Sair");

    }
    else if (estado_codigo == 1){
        QMessageBox messageBox(QMessageBox::Question,
        tr("Entrada/Saida"),
        tr("Deseja entrar ou sair?"),
        QMessageBox::Yes | QMessageBox::No,
        NULL);
        messageBox.setButtonText(QMessageBox::Yes, tr("Entrar"));
        messageBox.setButtonText(QMessageBox::No, tr("Sair"));
        if (messageBox.exec() == QMessageBox::Yes) {
           sprintf(usuario.hora_entrada,"%02d:%02d:%02d\r",timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
           sprintf(usuario.data_entrada,"%02d/%02d/%04d",timeinfo->tm_mday,timeinfo->tm_mon+1,(timeinfo->tm_year)+1900);
           msg.append(usuario.hora_entrada);
           msg.append(" - ");
           msg.append(usuario.data_entrada);
           ui->LE_ENTRADA->setText(msg);

           msg2.append(usuario.hora_saida);
           msg2.append(" - ");
           msg2.append(usuario.data_saida);
           ui->LE_SAIDA->setText(msg2);
           usuario.aux_cadastro = 'A';
           usuario.aux_acesso = 'I';
           if(serial->isOpen())// se porta aberta
           {
               serial->write((char*)&usuario,sizeof(usuario));
           }

        }
        else{
            sprintf(usuario.hora_saida,"%02d:%02d:%02d\r",timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
            sprintf(usuario.data_saida,"%02d/%02d/%04d",timeinfo->tm_mday,timeinfo->tm_mon+1,(timeinfo->tm_year)+1900);
            msg.append(usuario.hora_entrada);
            msg.append(" - ");
            msg.append(usuario.data_entrada);
            ui->LE_ENTRADA->setText(msg);

            msg2.append(usuario.hora_saida);
            msg2.append(" - ");
            msg2.append(usuario.data_saida);
            ui->LE_SAIDA->setText(msg2);
            usuario.aux_cadastro = 'A';
            usuario.aux_acesso = 'O';
            if(serial->isOpen())// se porta aberta
            {
                serial->write((char*)&usuario,sizeof(usuario));
            }
        }
    }

}


void MainWindow::on_BOTAO_LERDADOS_clicked()
{
    char buffer[30];
    usuario.aux_cadastro = 'L';
    if(serial->isOpen())// se porta aberta
    {
        serial->write((char*)&usuario,sizeof(usuario));
    }

}

void MainWindow::on_BOTAO_APAGA_clicked()
{
    usuario.aux_cadastro = 'C';
    if(serial->isOpen())// se porta aberta
    {
        serial->write((char*)&usuario,sizeof(usuario));
    }
    ui->LE_NOME->clear();
    ui->LE_CARGO->clear();
    ui->LE_MATRICULA->clear();
    ui->LE_ENTRADA->clear();
    ui->LE_SAIDA->clear();
    ui->LE_NOME->setReadOnly(false);
    ui->LE_CARGO->setReadOnly(false);
    ui->LE_MATRICULA->setReadOnly(false);
    ui->FOTO->setVisible(false);
    ui->BOTAO_LERDADOS->setText("Carregar");
    estado_codigo = 0;
    ui->BOTAO_ENVIA->setText("Cadastrar");
}

void MainWindow::on_BOTAO_LIMPA_clicked()
{
    static int aux = 0;
    QString msg,msg2;
    msg.clear();
    msg2.clear();
    if (aux == 0){
    ui->BOTAO_LIMPA->setText("Mostrar dados");
    ui->LE_NOME->clear();
    ui->LE_CARGO->clear();
    ui->LE_MATRICULA->clear();
    ui->LE_ENTRADA->clear();
    ui->LE_SAIDA->clear();
    ui->FOTO->setVisible(false);
    aux = 1;
    }
    else if (aux == 1){
        if (usuario.aux_cadastro == 'C'){
            ui->BOTAO_LIMPA->setText("Mostrar dados");
            ui->LE_NOME->clear();
            ui->LE_CARGO->clear();
            ui->LE_MATRICULA->clear();
            ui->LE_ENTRADA->clear();
            ui->LE_SAIDA->clear();
            ui->FOTO->setVisible(false);
            aux = 0;
        }
        else {
        ui->LE_NOME->setText(usuario.nome);
        ui->LE_MATRICULA->setText(usuario.matricula);
        ui->LE_CARGO->setText(usuario.cargo);

        msg.append(usuario.hora_entrada);
        msg.append(" - ");
        msg.append(usuario.data_entrada);
        ui->LE_ENTRADA->setText(msg);

        msg2.append(usuario.hora_saida);
        msg2.append(" - ");
        msg2.append(usuario.data_saida);
        ui->FOTO->setVisible(true);
        ui->LE_SAIDA->setText(msg2);
        ui->BOTAO_LIMPA->setText("Limpa Tela");
        aux = 0;
        }
    }
}
