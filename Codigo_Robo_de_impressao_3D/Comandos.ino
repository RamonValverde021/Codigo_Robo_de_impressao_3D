// Função que envia as coordenadas para acionar os motores
void _Comandos() {
  char articulacao;
  int posicao;
  const int velocidade = 50;

  // Ao chamar a função, é preciso passar os endereços das variáveis onde deseja armazenar os resultados, isso é feito usando o operador '&' antes das variáveis.
  _entradaDados(&articulacao, &posicao);

  if (posicao != -1) {
    if (articulacao == 'B') {
      if (posicaoAtual != posicao) {
        _DisplaySerial(articulacao, posicao);
        _Servos('B', posicao, 15);
      }
      posicaoAtual = posicao;
    } else if (articulacao == 'O') {
      if (posicaoAtual != posicao) {
        _DisplaySerial(articulacao, posicao);
        _Servos('O', posicao, 15);
      }
      posicaoAtual = posicao;
    } else if (articulacao == 'C') {
      if (posicaoAtual != posicao) {
        _DisplaySerial(articulacao, posicao);
        _Servos('C', posicao, 15);
      }
      posicaoAtual = posicao;
    } else if (articulacao == 'P') {
      if (posicaoAtual != posicao) {
        _DisplaySerial(articulacao, posicao);
        _Servos('P', posicao, 15);
      }
      posicaoAtual = posicao;
    } else if (articulacao == 'R') {
      if (posicaoAtual != posicao) {
        _DisplaySerial(articulacao, posicao);
        _Servos('R', posicao, 15);
      }
      posicaoAtual = posicao;
    } else if (articulacao == 'G') {
      if (posicaoAtual != posicao) {
        _DisplaySerial(articulacao, posicao);
        _Servos('G', posicao, 0);
      }
      posicaoAtual = posicao;
    } else if (articulacao == 'Z') {
      _DisplaySerial(articulacao, 0);
      _posicaoInicial();
    }
  }
  _entradaDados('x', -1);
}