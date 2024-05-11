#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#include "megasena.h"
#include "megasena.c"

//funcao principal
int main() {
    srand(time(NULL));
    int QD = 0; //Quantidade Dezenas
    int QM = 0; //Quantidade Manuais
    int QT = 0; //QUantidade Teimosinhas
    int VD = 0; //Valor da quantidade de dezenas apostadas
    int QS = 0; //Quantidade de surpresinhas

    printf(">>>>>>>>>> MEGA-SENA <<<<<<<<<<");
    printf("\n\nDezenas: Quantidade de Numeros que ira apostar");
    printf("\nManuais: Numeros que voce ira escolher MANUALMENTE para suas apostas");
    printf("\nSurpresinhas: Numeros gerados ALEATORIAMENTE pelo computador pra voce");
    printf("\nTeimosinhas: Usar as mesmas apostas em concursos diferentes");
    printf("\n\nOBS: Informe pelo menus UM valor para MANUAIS ou UM VALOR para surpresinhas\nCaso nao faca isso, sera enviada uma mensagem de erro");
    printf("\n\nBOA SORTE :D");

    //Quantidade de dezenas
    printf("\n\nDigite quantas dezenas ira apostar (valores possiveis: 6 a 15): "); scanf("%d", &QD);
    
    //Caso o jogador coloque um valor menor que 6 ou maior que 15
    if (QD < 6 || QD > 15) {
        do {
            printf("\n\n!!!NUMERO INVALIDO!!!");
            printf("\nInforme um valor de 6 ate 15: "); scanf("%d", &QD);
        } while (QD < 6 || QD > 15);
    }
    
    //Apostas Manuais
    printf("\n\nDigite quantas apostas manuais ira fazer (valores possiveis: 0 a 3): "); scanf("%d", &QM);
    if (QM > 3) {
        do {
            printf("\n\n!!! NUMERO INVALIDO !!!");
            printf("\nInforme um valor de 0 a 3: "); scanf("%d", &QM);
        } while (QM > 3);
    }
    
    //Colocando Apostas Manuais
    int ApostasManuais[QM][15]; // Máximo de 15 dezenas por aposta manual
    qtdApostasManuais(ApostasManuais, QM, QD);


    //Quantidade de surpresinhas
    printf("\n\nDigite a quantidade de Surpresinhas que deseja apostar (valores possiveis: 0 a 7): "); scanf("%d", &QS);

    //Caso o jogador informe um numero maior que 7
    if (QS > 7) {
        do {
            printf("\n\n!!! NUMERO INVALIDO !!!\n");
            printf("Informe um numero de 1 a 7: "); scanf("%d", &QS);
        } while (QS > 7);
    }

    //gerando surpresinhas
    int ApostaSurpresinhas [QS][15];
    qtdsurpresinhas (ApostaSurpresinhas, QS, QD);
    int auxQS = QS;

    //caso o usuario escolha 0 MANUAIS e 0 SURPRESINHAS
    if (QM == 0 && QS == 0) {
        printf("\n\n>>>>MANUAIS E SURPRESINHAS SEM VALORES<<<<\n");
        printf("Por favor, escolha pelo menos UM valor pra MANUAIS ou UM valor pra SURPRESINHAS\n");
        printf("Deseja reiniciar o jogo?\n\n[1] SIM\n[2] NAO\nR: "); scanf ("%d", &QD);

        if (QD != 1 && QD != 2) {
            do {
                printf("\n\n!!!!RESPOSTA INVALIDA!!!!\n");
                printf("Deseja reiniciar o jogo?\n\n[1] SIM\n[2] NAO\nR: "); scanf ("%d", &QD);
            } while (QD != 1 && QD != 2);
        }

        if (QD == 1) {
            system ("cls");
            main ();
        }
        else if (QD == 2) {
            printf("\n\n>>>>obrigado por jogar<<<<\n\n");
            return 0;
        }
    }

    //Quantidade de Teimosinhas
    printf("\n\nDigite a quantidade de Teimosinhas (valores validos: 1, 2, 4, 8): "); scanf("%d", &QT);

    //caso o jogador coloque teimosinhas como 0
    if (QT == 0) {
        QT = 1;
    }

    //caso o jogador informe um valor de teimosinhas diferente de 1, 2, 4 ou 8
    if (QT > 0) {
        if (QT != 1 && QT != 2 && QT != 4 && QT != 8) {
            do {
                printf("\n\n!!! NUMERO INVALIDO !!!");
                printf("Informe Teimosinhas (1, 2, 4 ou 8): "); scanf("%d", &QT);
            } while (QT != 1 && QT != 2 && QT != 4 && QT != 8);
        }
    }

    //Valor de cada dezena
    VD = ValorDezenas (QD);
    float TotalApostas = QT * (VD * (QM + QS));

    system ("cls");

    //Revisao de Apostas
    printf("REVISE SUAS APOSTAS\n");
    printf("\n%d Dezenas", QD); //6 a 15
    printf("\n%d Manuais", QM); //0 a 3
    printf("\n%d Surpresinhas", QS); //0 a 7
    printf("\n%d Teimosinhas\n", QT);// 0, 1, 2, 4, 8
    printf("\n=======================================================================================");

    //Mostrar as apostas manuais
    if (QM > 0) {
        printf("\n\nApostas Manuais\n\n");
        for (int i = 0; i < QM; i++) {
            printf("Lista %d de Apostas Manuais: ", i + 1);
            for (int j = 0; j < QD; j++) {
                printf("%d ", ApostasManuais[i][j]);
            }
            printf("\n");
        }
    }

    //Mostrar as apostas Surpresinhas
    if (QS > 0) {
        printf("\n=======================================================================================");
        printf("\n\nApostas Surpresinhas\n\n");
        for (int i = 0; i < QS; i++) {
            printf("Lista %d de Surpresinhas: ", i + 1);
            for (int j = 0; j < QD; j++) {
                printf("%d ", ApostaSurpresinhas[i][j]);
            }
            printf("\n");
        }
    }

    printf("\n=======================================================================================");
    printf("\n\n%d Teimosinhas\n\n", QT);
    

    printf("\n=======================================================================================");
    printf("\n\nValor total das apostas: R$%.2f", TotalApostas);

    //Se o usuario deseja continuar
    char opcao[1];
    printf("\n\nDeseja continuar (S/N)? "); scanf("%s", opcao);

    //caso o usuario digite um valor diferente de s ou n
    if (opcao[0] != 's' && opcao[0] != 'S' && opcao[0] != 'n' && opcao[0] != 'N') {
        do {
            printf("\n\n!!!VALOR INVALIDO!!!\nDeseja continuar (S/N)? "); scanf("%s", opcao);
        } while (opcao[0] != 's' && opcao[0] != 'S' && opcao[0] != 'n' && opcao[0] != 'N');
    }
    
    //caso o usuario nao queira continuar
    if (opcao[0] == 'n' || opcao[0] == 'N') {
        printf("\n\n>>>>Obrigado por participar das Loterias Caixa<<<<\n\n");
        return 0;
    }

    //caso o usuario queira continuar
    else if (opcao[0] == 's' || opcao[0] == 'S') {
        sorteio (ApostasManuais, ApostaSurpresinhas, QT, QM, QD, auxQS, TotalApostas);
    }

    //Perguntar se o usuario deseja jogar novamente
    printf("Deseja jogar de novo?\n\n[1] SIM\n[2] NAO\n\nR: "); scanf("%d", &QD);

    if (QD != 1 && QD != 2) {
        do {
            printf("\n\n!!!!RESPOSTA INVALIDA!!!!\n");
            printf("Deseja jogar de novo?\n\n[1] SIM\n[2] NAO\n\nR: "); scanf("%d", &QD);
        } while (QD != 1 && QD != 2);
    }

    if (QD == 1) {
        system ("cls");
        main ();
    } else if (QD == 2){
        printf("\n\n>>>>Obrigado por participar das Loterias Caixa<<<<\n\n");
        return 0;
    }
}