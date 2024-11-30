// Função para apontar os servos
void _Servos(char servo, int posicao, int atraso) {
  if (servo == 'B') {
    int base_atual = base.read();
    if (posicao > base_atual) {
      for (int c = base_atual; c < posicao; c++) {
        base.write(c);
        delay(atraso);
      }
    } else {
      for (int c = base_atual; c > posicao; c--) {
        base.write(c);
        delay(atraso);
      }
    }
  }

  if (servo == 'O') {
    int ombro_atual = ombro.read();
    if (posicao > ombro_atual) {
      for (int c = ombro_atual; c < posicao; c++) {
        ombro.write(c);
        delay(atraso);
      }
    } else {
      for (int c = ombro_atual; c > posicao; c--) {
        ombro.write(c);
        delay(atraso);
      }
    }
  }

  if (servo == 'C') {
    int cotovelo_atual = cotovelo.read();
    if (posicao > cotovelo_atual) {
      for (int c = cotovelo_atual; c < posicao; c++) {
        cotovelo.write(c);
        delay(atraso);
      }
    } else {
      for (int c = cotovelo_atual; c > posicao; c--) {
        cotovelo.write(c);
        delay(atraso);
      }
    }
  }

  if (servo == 'P') {
    int pulso_atual = pulso.read();
    if (posicao > pulso_atual) {
      for (int c = pulso_atual; c < posicao; c++) {
        pulso.write(c);
        delay(atraso);
      }
    } else {
      for (int c = pulso_atual; c > posicao; c--) {
        pulso.write(c);
        delay(atraso);
      }
    }
  }

  if (servo == 'R') {
    int rotacao_atual = rotacao.read();
    if (posicao > rotacao_atual) {
      for (int c = rotacao_atual; c < posicao; c++) {
        rotacao.write(c);
        delay(atraso);
      }
    } else {
      for (int c = rotacao_atual; c > posicao; c--) {
        rotacao.write(c);
        delay(atraso);
      }
    }
  }

  if (servo == 'G') {
    // 1 garra aberta   0 garra fechada
    int potencia = 255;
    int espera = atraso;  // 150
    if (posicao == 1) {
      // Abre a Garra
      digitalWrite(pinGarraA, LOW);
      analogWrite(pinGarraF, potencia);
      delay(espera);
      status_garra = "ABERTA";
    } else {
      // Fecha a Garra
      analogWrite(pinGarraA, potencia);
      digitalWrite(pinGarraF, LOW);
      delay(espera);
      status_garra = "FECHADA";
    }
    // Para o motor
    digitalWrite(pinGarraA, HIGH);
    digitalWrite(pinGarraF, HIGH);
    delay(500);
    digitalWrite(pinGarraA, LOW);
    digitalWrite(pinGarraF, LOW);
  }
}

// Sequencia de movimentos para posicionar o motor inicialmente
void _posicaoInicial() {
  _Servos('B', 90, 10);
  _Servos('C', 30, 10);
  _Servos('O', 170, 10);
  _Servos('R', 5, 0);
  _Servos('P', 93, 10);
  _Servos('G', 1, 150);
  digitalWrite(luz, HIGH);
  delay(2000);
  digitalWrite(luz, LOW);
}