// Exibe na Serial oque está sendo executado no decorrer do codigo
void _DisplaySerial(char index, int coordenada) {
  switch (index) {
    case '0':
      Serial.println("\nFUNCAO: ENTRADA DE DADOS");
      break;

    case '1':
      Serial.println("\nAUTOMACAO 01: MINHA ROTINA");
      break;

    case '2':
      Serial.println("\nAUTOMACAO 02: PEGAR OVO");
      break;

    case '3':
      Serial.println("\nAUTOMACAO 03: PEGAR NA ESTEIRA");
      break;

    case 'I':
      Serial.println("\n\n     INICIANDO ROBO     ");
      Serial.println("      ARM MARK VI      ");
      delay(1000);  // 5000
      break;

    case 'B':
      Serial.print("\nBASE: ");
      Serial.println(coordenada);
      break;

    case 'O':
      Serial.print("\nOMBRO: ");
      Serial.println(coordenada);
      break;

    case 'C':
      Serial.print("\nCOTOVELO: ");
      Serial.println(coordenada);
      break;

    case 'P':
      Serial.print("\nPULSO: ");
      Serial.println(coordenada);
      break;

    case 'R':
      Serial.print("\nROTACAO: ");
      Serial.println(coordenada);
      break;

    case 'G':
      Serial.print("\nGARRA: ");
      Serial.println(coordenada);
      break;

    case 'Z':
      Serial.print("\nPOSICAO INICIAL");
      break;

    default:
      break;
  }
}

// Exibe na Serial constantemente a posição dos servos motores
void _Status() {
  Serial.println("Status Motores:");

  Serial.print("Base: ");
  Serial.println(base.read());

  Serial.print("Omrbo: ");
  Serial.println(ombro.read());

  Serial.print("Cotovelo: ");
  Serial.println(cotovelo.read());

  Serial.print("Pulso: ");
  Serial.println(pulso.read());

  Serial.print("Garra: ");
  Serial.println(status_garra);

  Serial.println('\n');
}