// Bibliotecas
#include <Servo.h>
#include <SoftwareSerial.h>

// Variaveis biblioteca do servo
Servo base;
Servo ombro;
Servo cotovelo;
Servo rotacao;
Servo pulso;
void _Servos(char servo, int posicao, int atraso);

// Variaveis
bool bluetooth = false;
bool serial = false;
int posicaoAtual = -1;

const int pinBase = 4;
const int pinOmbro = 5;
const int pinCotovelo = 6;
const int pinRotacao = 7;
const int pinPulso = 8;
const int pinGarraA = 9;
const int pinGarraF = 10;
const int luz = 11;
String status_garra = "FECHADA";

// Entradas e Saidas Bluetooth
const int RxD = 3, TxD = 2;
SoftwareSerial Bluetooth(RxD, TxD);  //RX pino 3, TX pino 2

// Outras Funções
void _DisplaySerial(char index, int coordenada);
void _entradaDados(char *articulacao, int *posicao);
void _posicaoInicial();
void _Status();

void setup() {
  // Inicializa as Seriais
  Serial.begin(38400);
  Bluetooth.begin(38400);

  // Define os pinos de entrada
  pinMode(pinGarraA, OUTPUT);
  pinMode(pinGarraF, OUTPUT);
  pinMode(luz, OUTPUT);
  digitalWrite(pinGarraA, LOW);
  digitalWrite(pinGarraF, LOW);
  digitalWrite(luz, LOW);

  // Inicializar os servos motores
  pinMode(pinBase, INPUT);
  pinMode(pinOmbro, INPUT);
  pinMode(pinCotovelo, INPUT);
  pinMode(pinRotacao, INPUT);
  pinMode(pinPulso, INPUT);
  base.attach(pinBase);
  ombro.attach(pinOmbro);
  cotovelo.attach(pinCotovelo);
  rotacao.attach(pinRotacao);
  pulso.attach(pinPulso);
  base.write(90);
  cotovelo.write(30);
  ombro.write(170);
  rotacao.write(5);
  pulso.write(93);
  _Servos('G', 1, 150);

  // Inicializa o display serial
  _DisplaySerial('I', 0);
  _Status();
  // Primeiros comandos
  _entradaDados('x', -1);  // Chamada de função para bloquear a ultima instrução enviada

  _Status();
  delay(200);
}

void loop() {
  //delay(2000);
  //_Status();
  //_Comandos();


  
  // Etapa 01 - Pega frasco
  _Servos('B', 150, 15);
  _Servos('G', 0, 150);
  _Servos('O', 40, 6);
  _Servos('C', 50, 6);
  _Servos('P', 60, 15);
  _Servos('G', 1, 50);

  // Etapa 02 - Vira o frasco no pote
  _Servos('O', 100, 5);
  _Servos('C', 30, 5);
  _Servos('P', 90, 15);
  _Servos('B', 100, 15);
  _Servos('R', 150, 5);
  delay(2000);

  // Etapa 03 - poem o frasco de volta o lugar
  _Servos('R', 5, 5);
  _Servos('B', 150, 15);
  _Servos('P', 60, 15);
  _Servos('O', 40, 6);
  _Servos('C', 50, 6);
  delay(500);
  _Servos('G', 0, 150);

  // Etapa 04 - Recolhe o braço para a posição inical
  _Servos('C', 30, 5);
  _Servos('O', 170, 5);
  _Servos('P', 93, 15);
  _Servos('G', 1, 150);

  // Etapa 05 - pega objeto
  _Servos('B', 10, 15);
  _Servos('G', 0, 150);
  _Servos('R', 100, 5);
  _Servos('C', 0, 15);
  delay(500);
  _Servos('O', 110, 15);
  delay(500);
  _Servos('G', 1, 100);

  // Etapa 06 - Recolhe um pouco o braço
  _Servos('O', 150, 10);  // Traz o ombro para traz
  _Servos('R', 5, 5);
  _Servos('P', 20, 10);  // Levanta o pulso
  delay(500);

  // Etapa 07 - Posiciona o braço em baixo
  _Servos('C', 50, 10);   // Desce o cotovelo
  _Servos('O', 90, 10);   // Leva o ombro para frente
  _Servos('P', 0, 10);    // Levanta o pulso totalmente
  _Servos('C', 120, 10);  // Desce o cotovelo
  delay(500);

  // Etapa 08 - Leva o braço ate o proximo local
  _Servos('B', 50, 15);
  _Servos('P', 25, 10);  // desce o pulso um pouco
  _Servos('C', 90, 10);  // levanta o cotovelo
  delay(500);

  // Etapa 09 - solta o objeto
  _Servos('G', 0, 150);  // Abre a garra
  delay(500);
  _Servos('C', 130, 10);
  _Servos('P', 0, 10);
  _Servos('G', 1, 150);  // Fecha a garra

  // Etapa 10 - sai do local
  _Servos('B', 90, 15);
  _Servos('C', 50, 10);
  _Servos('O', 150, 10);
  _Servos('P', 70, 10);



  delay(3000);
  // POSIÇÃO INICIAL
  _posicaoInicial();

  //Descansa os servos
  base.detach();
  ombro.detach();
  cotovelo.detach();
  rotacao.detach();
  pulso.detach();
  delay(600000);  // Espera 10 minutos

  //Reativa os servos
  base.attach(pinBase);
  ombro.attach(pinOmbro);
  cotovelo.attach(pinCotovelo);
  rotacao.attach(pinRotacao);
  pulso.attach(pinPulso);
}