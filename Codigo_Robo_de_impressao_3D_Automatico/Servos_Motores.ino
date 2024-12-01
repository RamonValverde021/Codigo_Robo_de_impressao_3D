int delay_Base = 10;
int delay_Ombro = 4;
int delay_Cotovelo = 4;
int delay_Pulso = 4;
int delay_Rotacao = 10;
int delay_Garra = 150;

// Função para apontar os servos
void _Servos(char servo, int posicao) {
  if (servo == 'B') {
    int base_atual = base.read();
    if (posicao > base_atual) {
      for (int c = base_atual; c < posicao; c++) {
        base.write(c);
        delay(delay_Base);
      }
    } else {
      for (int c = base_atual; c > posicao; c--) {
        base.write(c);
        delay(delay_Base);
      }
    }
  }

  if (servo == 'O') {
    int ombro_atual = ombro.read();
    if (posicao > ombro_atual) {
      for (int c = ombro_atual; c < posicao; c++) {
        ombro.write(c);
        delay(delay_Ombro);
      }
    } else {
      for (int c = ombro_atual; c > posicao; c--) {
        ombro.write(c);
        delay(delay_Ombro);
      }
    }
  }

  if (servo == 'C') {
    int cotovelo_atual = cotovelo.read();
    if (posicao > cotovelo_atual) {
      for (int c = cotovelo_atual; c < posicao; c++) {
        cotovelo.write(c);
        delay(delay_Cotovelo);
      }
    } else {
      for (int c = cotovelo_atual; c > posicao; c--) {
        cotovelo.write(c);
        delay(delay_Cotovelo);
      }
    }
  }

  if (servo == 'P') {
    int pulso_atual = pulso.read();
    if (posicao > pulso_atual) {
      for (int c = pulso_atual; c < posicao; c++) {
        pulso.write(c);
        delay(delay_Pulso);
      }
    } else {
      for (int c = pulso_atual; c > posicao; c--) {
        pulso.write(c);
        delay(delay_Pulso);
      }
    }
  }

  if (servo == 'R') {
    int rotacao_atual = rotacao.read();
    if (posicao > rotacao_atual) {
      for (int c = rotacao_atual; c < posicao; c++) {
        rotacao.write(c);
        delay(delay_Rotacao);
      }
    } else {
      for (int c = rotacao_atual; c > posicao; c--) {
        rotacao.write(c);
        delay(delay_Rotacao);
      }
    }
  }

  if (servo == 'G') {
    // 1 garra aberta   0 garra fechada
    int potencia = 255;
    if (posicao == 1) {
      // Abre a Garra
      digitalWrite(pinGarraA, LOW);
      analogWrite(pinGarraF, potencia);
      delay(delay_Garra);
    } else {
      // Fecha a Garra
      analogWrite(pinGarraA, potencia);
      digitalWrite(pinGarraF, LOW);
      delay(delay_Garra);
    }
    // Para o motor
    digitalWrite(pinGarraA, HIGH);
    digitalWrite(pinGarraF, HIGH);
    delay(500);
    digitalWrite(pinGarraA, LOW);
    digitalWrite(pinGarraF, LOW);
  }
}


//////////////////////// SERVOS SIMULTANEOS ////////////////////////

void _OmbroCotovelo(int posicao_ombro, int posicao_cotovelo) {
  int ombro_atual, cotovelo_atual, o, c = 0;
  while ((posicao_ombro != ombro_atual) || (posicao_cotovelo != cotovelo_atual)) {
    // OMBRO
    ombro_atual = ombro.read();
    o = ombro_atual;
    if (posicao_ombro > ombro_atual) {
      o++;
      ombro.write(o);
    } else if (posicao_ombro < ombro_atual) {
      o--;
      ombro.write(o);
    }
    // COTOVELO
    cotovelo_atual = cotovelo.read();
    c = cotovelo_atual;
    if (posicao_cotovelo > cotovelo_atual) {
      c++;
      cotovelo.write(c);
    } else if (posicao_cotovelo < cotovelo_atual) {
      c--;
      cotovelo.write(c);
    }
    delay(4);
  }
}

void _CotoveloPulso(int posicao_cotovelo, int posicao_pulso) {
  int cotovelo_atual, pulso_atual, c, p = 0;
  while ((posicao_cotovelo != cotovelo_atual) || (posicao_pulso != pulso_atual)) {
    // COTOVELO
    cotovelo_atual = cotovelo.read();
    c = cotovelo_atual;
    if (posicao_cotovelo > cotovelo_atual) {
      c++;
      cotovelo.write(c);
    } else if (posicao_cotovelo < cotovelo_atual) {
      c--;
      cotovelo.write(c);
    }
    // PULSO
    pulso_atual = pulso.read();
    p = pulso_atual;
    if (posicao_pulso > pulso_atual) {
      p++;
      pulso.write(p);
    } else if (posicao_pulso < pulso_atual) {
      p--;
      pulso.write(p);
    }
    delay(4);
  }
}

void _BaseRotacao(int posicao_base, int posicao_rotacao) {
  int base_atual, rotacao_atual, b, r = 0;
  while ((posicao_base != base_atual) || (posicao_rotacao != rotacao_atual)) {
    // BASE
    base_atual = base.read();
    b = base_atual;
    if (posicao_base > base_atual) {
      b++;
      base.write(b);
    } else if (posicao_base < base_atual) {
      b--;
      base.write(b);
    }
    // ROTACAO
    rotacao_atual = rotacao.read();
    r = rotacao_atual;
    if (posicao_rotacao > rotacao_atual) {
      r++;
      rotacao.write(r);
    } else if (posicao_rotacao < rotacao_atual) {
      r--;
      rotacao.write(r);
    }
    delay(5);
  }
}

void _OmbroCotoveloPulso(int posicao_ombro, int posicao_cotovelo, int posicao_pulso) {
  int ombro_atual, cotovelo_atual, pulso_atual, o, c, p = 0;
  while ((posicao_ombro != ombro_atual) || (posicao_cotovelo != cotovelo_atual) || (posicao_pulso != pulso_atual)) {
    // OMBRO
    ombro_atual = ombro.read();
    o = ombro_atual;
    if (posicao_ombro > ombro_atual) {
      o++;
      ombro.write(o);
    } else if (posicao_ombro < ombro_atual) {
      o--;
      ombro.write(o);
    }
    // COTOVELO
    cotovelo_atual = cotovelo.read();
    c = cotovelo_atual;
    if (posicao_cotovelo > cotovelo_atual) {
      c++;
      cotovelo.write(c);
    } else if (posicao_cotovelo < cotovelo_atual) {
      c--;
      cotovelo.write(c);
    }
    // PULSO
    pulso_atual = pulso.read();
    p = pulso_atual;
    if (posicao_pulso > pulso_atual) {
      p++;
      pulso.write(p);
    } else if (posicao_pulso < pulso_atual) {
      p--;
      pulso.write(p);
    }
    delay(3);
  }
}

// Sequencia de movimentos para posicionar o motor inicialmente
void _posicaoInicial() {
  _Servos('B', 90);
  _Servos('C', 30);
  _Servos('O', 170);
  _Servos('R', 5);
  _Servos('P', 93);
  _Servos('G', 1);
  digitalWrite(luz, HIGH);
  delay(2000);
  digitalWrite(luz, LOW);
}