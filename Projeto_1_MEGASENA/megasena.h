#ifndef megasena_h
#define megasena_h

//FUNCOES
void qtdApostasManuais(int ApostasManuais[][15], int _quantidadeApostasManuais, int _quantidadeDezenas);
void qtdsurpresinhas (int ApostaSurpesinhas [][15], int _quantidadeApostasSurpresinhas, int _quantidadeDezenas);
float ValorDezenas (int _quantidadeDezenas);
void FunAcertos (int acertos);
float calculopremios (int acertos, int _quantidadeDezenas);
void sorteio (int ApostasManuais [][15], int ApostaSurpresinhas [] [15], int _quantidadeTeimosinhas, int _quantidadeApostasManuais, int _quantidadeDezenas, int _quantidadeApostasSurpresinhas, float TotalApostas);

#endif