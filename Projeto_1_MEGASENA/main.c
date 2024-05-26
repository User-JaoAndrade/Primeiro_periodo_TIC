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
    
    int _quantidadeDezenas = 0; //Quantidade Dezenas
    int _quantidadeApostasManuais = 0; //Quantidade Manuais
    int _quantidadeTeimosinhas = 0; //QUantidade Teimosinhas
    int VALOR_DEZENAS_APOSTADAS = 0; //Valor da quantidade de dezenas apostadas
    int _quantidadeApostasSurpresinhas = 0; //Quantidade de surpresinhas

    printf(">>>>>>>>>> MEGA-SENA <<<<<<<<<<");
    printf("\n\nDezenas: Quantidade de Numeros que ira apostar");
    printf("\nManuais: Numeros que voce ira escolher MANUALMENTE para suas apostas");
    printf("\nSurpresinhas: Numeros gerados ALEATORIAMENTE pelo computador pra voce");
    printf("\nTeimosinhas: Usar as mesmas apostas em concursos diferentes");
    printf("\n\nOBS: Informe pelo menus UM valor para MANUAIS ou UM VALOR para surpresinhas\nCaso nao faca isso, sera enviada uma mensagem de erro");
    printf("\n\nBOA SORTE :D");

    //Quantidade de dezenas
    printf("\n\nDigite quantas dezenas ira apostar (valores possiveis: 6 a 15): "); scanf("%d", &_quantidadeDezenas);
    
    //Caso o jogador coloque um valor menor que 6 ou maior que 15
    if (_quantidadeDezenas < 6 || _quantidadeDezenas > 15) {
        do {
            printf("\n\n!!!NUMERO INVALIDO!!!");
            printf("\nInforme um valor de 6 ate 15: "); scanf("%d", &_quantidadeDezenas);
        } while (_quantidadeDezenas < 6 || _quantidadeDezenas > 15);
    }
    
    //Apostas Manuais
    printf("\n\nDigite quantas apostas manuais ira fazer (valores possiveis: 0 a 3): "); scanf("%d", &_quantidadeApostasManuais);
    if (_quantidadeApostasManuais > 3) {
        do {
            printf("\n\n!!! NUMERO INVALIDO !!!");
            printf("\nInforme um valor de 0 a 3: "); scanf("%d", &_quantidadeApostasManuais);
        } while (_quantidadeApostasManuais > 3);
    }
    
    //Colocando Apostas Manuais
    int ApostasManuais[_quantidadeApostasManuais][15]; // Máximo de 15 dezenas por aposta manual
    qtdApostasManuais(ApostasManuais, _quantidadeApostasManuais, _quantidadeDezenas);


    //Quantidade de surpresinhas
    printf("\n\nDigite a quantidade de Surpresinhas que deseja apostar (valores possiveis: 0 a 7): "); scanf("%d", &_quantidadeApostasSurpresinhas);

    //Caso o jogador informe um numero maior que 7
    if (_quantidadeApostasSurpresinhas > 7) {
        do {
            printf("\n\n!!! NUMERO INVALIDO !!!\n");
            printf("Informe um numero de 1 a 7: "); scanf("%d", &_quantidadeApostasSurpresinhas);
        } while (_quantidadeApostasSurpresinhas > 7);
    }

    //gerando surpresinhas
    int ApostaSurpresinhas [_quantidadeApostasSurpresinhas][15];
    qtdsurpresinhas (ApostaSurpresinhas, _quantidadeApostasSurpresinhas, _quantidadeDezenas);
    int auxQS = _quantidadeApostasSurpresinhas;

    //caso o usuario escolha 0 MANUAIS e 0 SURPRESINHAS
    if (_quantidadeApostasManuais == 0 && _quantidadeApostasSurpresinhas == 0) {
        printf("\n\n>>>>MANUAIS E SURPRESINHAS SEM VALORES<<<<\n");
        printf("Por favor, escolha pelo menos UM valor pra MANUAIS ou UM valor pra SURPRESINHAS\n");
        printf("Deseja reiniciar o jogo?\n\n[1] SIM\n[2] NAO\nR: "); scanf ("%d", &_quantidadeDezenas);

        if (_quantidadeDezenas != 1 && _quantidadeDezenas != 2) {
            do {
                printf("\n\n!!!!RESPOSTA INVALIDA!!!!\n");
                printf("Deseja reiniciar o jogo?\n\n[1] SIM\n[2] NAO\nR: "); scanf ("%d", &_quantidadeDezenas);
            } while (_quantidadeDezenas != 1 && _quantidadeDezenas != 2);
        }

        if (_quantidadeDezenas == 1) {
            system ("cls");
            main ();
        }
        else if (_quantidadeDezenas == 2) {
            printf("\n\n>>>>obrigado por jogar<<<<\n\n");
            return 0;
        }
    }

    //Quantidade de Teimosinhas
    printf("\n\nDigite a quantidade de Teimosinhas (valores validos: 1, 2, 4, 8): "); scanf("%d", &_quantidadeTeimosinhas);

    //caso o jogador coloque teimosinhas como 0
    if (_quantidadeTeimosinhas == 0) {
        _quantidadeTeimosinhas = 1;
    }

    //caso o jogador informe um valor de teimosinhas diferente de 1, 2, 4 ou 8
    if (_quantidadeTeimosinhas > 0) {
        if (_quantidadeTeimosinhas != 1 && _quantidadeTeimosinhas != 2 && _quantidadeTeimosinhas != 4 && _quantidadeTeimosinhas != 8) {
            do {
                printf("\n\n!!! NUMERO INVALIDO !!!");
                printf("Informe Teimosinhas (1, 2, 4 ou 8): "); scanf("%d", &_quantidadeTeimosinhas);
            } while (_quantidadeTeimosinhas != 1 && _quantidadeTeimosinhas != 2 && _quantidadeTeimosinhas != 4 && _quantidadeTeimosinhas != 8);
        }
    }

    //Valor de cada dezena
    VALOR_DEZENAS_APOSTADAS = ValorDezenas (_quantidadeDezenas);
    float TotalApostas = _quantidadeTeimosinhas * (VALOR_DEZENAS_APOSTADAS * (_quantidadeApostasManuais + _quantidadeApostasSurpresinhas));

    system ("cls");

    //Revisao de Apostas
    printf("REVISE SUAS APOSTAS\n");
    printf("\n%d Dezenas", _quantidadeDezenas); //6 a 15
    printf("\n%d Manuais", _quantidadeApostasManuais); //0 a 3
    printf("\n%d Surpresinhas", _quantidadeApostasSurpresinhas); //0 a 7
    printf("\n%d Teimosinhas\n", _quantidadeTeimosinhas);// 0, 1, 2, 4, 8
    printf("\n=======================================================================================");

    //Mostrar as apostas manuais
    if (_quantidadeApostasManuais > 0) {
        printf("\n\nApostas Manuais\n\n");
        for (int i = 0; i < _quantidadeApostasManuais; i++) {
            printf("Lista %d de Apostas Manuais: ", i + 1);
            for (int j = 0; j < _quantidadeDezenas; j++) {
                printf("%d ", ApostasManuais[i][j]);
            }
            printf("\n");
        }
    }

    //Mostrar as apostas Surpresinhas
    if (_quantidadeApostasSurpresinhas > 0) {
        printf("\n=======================================================================================");
        printf("\n\nApostas Surpresinhas\n\n");
        for (int i = 0; i < _quantidadeApostasSurpresinhas; i++) {
            printf("Lista %d de Surpresinhas: ", i + 1);
            for (int j = 0; j < _quantidadeDezenas; j++) {
                printf("%d ", ApostaSurpresinhas[i][j]);
            }
            printf("\n");
        }
    }

    printf("\n=======================================================================================");
    printf("\n\n%d Teimosinhas\n\n", _quantidadeTeimosinhas);
    

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
        sorteio (ApostasManuais, ApostaSurpresinhas, _quantidadeTeimosinhas, _quantidadeApostasManuais, _quantidadeDezenas, auxQS, TotalApostas);
    }

    //Perguntar se o usuario deseja jogar novamente
    printf("Deseja jogar de novo?\n\n[1] SIM\n[2] NAO\n\nR: "); scanf("%d", &_quantidadeDezenas);

    if (_quantidadeDezenas != 1 && _quantidadeDezenas != 2) {
        do {
            printf("\n\n!!!!RESPOSTA INVALIDA!!!!\n");
            printf("Deseja jogar de novo?\n\n[1] SIM\n[2] NAO\n\nR: "); scanf("%d", &_quantidadeDezenas);
        } while (_quantidadeDezenas != 1 && _quantidadeDezenas != 2);
    }

    if (_quantidadeDezenas == 1) {
        system ("cls");
        main ();
    } else if (_quantidadeDezenas == 2){
        printf("\n\n>>>>Obrigado por participar das Loterias Caixa<<<<\n\n");
        return 0;
    }
}