// Bibliotecas
#include <Servo.h>

// Variaveis biblioteca do servo
Servo base;
Servo ombro;
Servo cotovelo;
Servo rotacao;
Servo pulso;
void _Servos(char servo, int posicao);
void _OmbroCotovelo(int posicao_ombro, int posicao_cotovelo);
void _CotoveloPulso(int posicao_cotovelo, int posicao_pulso);
void _BaseRotacao(int posicao_base, int posicao_rotacao);
void _OmbroCotoveloPulso(int posicao_ombro, int posicao_cotovelo, int posicao_pulso);
void _posicaoInicial();

// Variaveis
const int pinBase = 4;
const int pinOmbro = 5;
const int pinCotovelo = 6;
const int pinRotacao = 7;
const int pinPulso = 8;
const int pinGarraA = 9;
const int pinGarraF = 10;
const int luz = 11;

void setup() {
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
  _Servos('G', 1);

  delay(1000);
}

void loop() {
  /*
  _OmbroCotovelo(40, 40);
  delay(500);
  _OmbroCotovelo(170, 30);
  delay(500);
  _OmbroCotoveloPulso(40, 40, 40);
  delay(500);
  _OmbroCotoveloPulso(170, 30, 93);
  delay(500);
  _Servos('O', 100);
  delay(500);
  _CotoveloPulso(100, 40);
  delay(500);
  _CotoveloPulso(30, 93);
  delay(500);
  _Servos('O', 170);
  delay(500);
  _BaseRotacao(180, 180);
  delay(500);
  _BaseRotacao(0, 0);
  delay(500);
*/
  /*
  digitalWrite(luz, HIGH);
  delay(1000);
  digitalWrite(luz, LOW);

  // Etapa 01 - Pega frasco
  _Servos('B', 150);
  _Servos('G', 0);
  _Servos('O', 40);
  _Servos('C', 50);
  _Servos('P', 60);
  _Servos('G', 1);

  // Etapa 02 - Vira o frasco no pote
  _Servos('O', 100);
  _Servos('C', 30);
  _Servos('P', 90);
  _Servos('B', 100);
  _Servos('R', 150);
  delay(2000);

  // Etapa 03 - poem o frasco de volta o lugar
  _Servos('R', 5);
  _Servos('B', 150);
  _Servos('P', 60);
  _Servos('O', 40);
  _Servos('C', 50);
  delay(500);
  _Servos('G', 0);

  // Etapa 04 - Recolhe o braço para a posição inical
  _Servos('C', 30);
  _Servos('O', 170);
  _Servos('P', 93);
  _Servos('G', 1);

  // Etapa 05 - pega objeto
  _Servos('B', 10);
  _Servos('G', 0);
  _Servos('R', 100);
  _Servos('C', 0);
  delay(500);
  _Servos('O', 110);
  delay(500);
  _Servos('G', 1);

  // Etapa 06 - Recolhe um pouco o braço
  _Servos('O', 150);  // Traz o ombro para traz
  _Servos('R', 5);
  _Servos('P', 20);  // Levanta o pulso
  delay(500);

  // Etapa 07 - Posiciona o braço em baixo
  _Servos('C', 50);   // Desce o cotovelo
  _Servos('O', 90);   // Leva o ombro para frente
  _Servos('P', 0);    // Levanta o pulso totalmente
  _Servos('C', 120);  // Desce o cotovelo
  delay(500);

  // Etapa 08 - Leva o braço ate o proximo local
  _Servos('B', 50);
  _Servos('P', 25);  // desce o pulso um pouco
  _Servos('C', 90);  // levanta o cotovelo
  delay(500);

  // Etapa 09 - solta o objeto
  _Servos('G', 0);  // Abre a garra
  delay(500);
  _Servos('C', 130);
  _Servos('P', 0);
  _Servos('G', 1);  // Fecha a garra

  // Etapa 10 - sai do local
  _Servos('B', 90);
  _Servos('C', 50);
  _Servos('O', 150);
  _Servos('P', 70);
*/



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