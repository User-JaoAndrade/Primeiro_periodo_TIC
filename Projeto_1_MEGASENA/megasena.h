#ifndef megasena_h
#define megasena_h

//FUNCOES
void qtdApostasManuais(int ApostasManuais[][15], int QM, int QD);
void qtdsurpresinhas (int ApostaSurpesinhas [][15], int QS, int QD);
float ValorDezenas (int QD);
void FunAcertos (int acertos);
float calculopremios (int acertos, int QD);
void sorteio (int ApostasManuais [][15], int ApostaSurpresinhas [] [15], int QT, int QM, int QD, int QS, float TotalApostas);

#endif