#include "megasena.h"

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>


//APOSTAS MANUAIS
void qtdApostasManuais(int ApostasManuais[][15], int QM, int QD) {

    for (int i = 0; i < QM; i++) {
        printf("\n\n___APOSTAS MANUAIS %d___\n\n", i + 1);

        for (int j = 0; j < QD; j++) {
            printf("Aposta Manual %d: ", j + 1); scanf("%d", &ApostasManuais[i][j]);

            //Caso informe um numero menor que 1 ou maior que 60
            if (ApostasManuais[i][j] < 1 || ApostasManuais[i][j] > 60) {
                do {
                    printf("\n\n!!! NUMERO INVALIDO !!!");
                    printf("\nInforme um numero de 1 a 60: "); scanf("%d", &ApostasManuais [i][j]);
                } while (ApostasManuais[i][j] < 1 || ApostasManuais[i][j] > 60);
            }

            //Caso o numero ja tenha sido utilizado
            for (int k = 0; k < j; k++) {
                if (ApostasManuais[i][k] == ApostasManuais[i][j]) {
                    do {
                        printf("\n\n!!! ERRO !!!");
                        printf("\nNumero ja utilizado, informe outro numero de 1 a 60: "); scanf("%d", &ApostasManuais[i][j]);
                    } while (ApostasManuais[i][k] == ApostasManuais[i][j]);
                } 
            }
        }
    }
}



//Surpresinhas
void qtdsurpresinhas (int ApostaSurpresinhas [][15], int QS, int QD) {
    for (int i = 0; i < QS; i++) {
        for (int j = 0; j < QD; j++) {
            ApostaSurpresinhas [i][j]= rand() % 60 + 1;

            //Caso o computador gere um numero repetido
            for (int k = 0; k < j; k++) {
                if (ApostaSurpresinhas [i][k] == ApostaSurpresinhas [i][j]) {
                    do {
                        ApostaSurpresinhas [i][j] = rand() % 60 + 1;
                    } while (ApostaSurpresinhas [i][k] == ApostaSurpresinhas [i][j]);
                }
            }
        }
    }
}



//Valor das dezenas
float ValorDezenas (int QD) {
    switch (QD) {
        case 6: 
            return 5;
            break;
        case 7:
            return 35;
            break;
        case 8:
            return 140;
            break;
        case 9:
            return 420;
            break;
        case 10:
            return 1.050;
            break;
        case 11:
            return 2.310;
            break;
        case 12:
            return 4.620;
            break;
        case 13:
            return 8.580;
            break;
        case 14:
            return 15.015;
            break;
        case 15:
            return 25.025;
            break;
        default: 
            break;
    }
}




//Acertos 
void FunAcertos (int acertos) {
    switch (acertos) {
        case 4:
            printf("\nQUADRA!");
            break;
        case 5: 
            printf("\nQUINA!");
            break;
        case 6: 
            printf("\n SENA!");
            break;
    }
}



//Calcular valor dos premios finais
float calculopremios (int acertos, int QD) {
    int premio [10][6] = {
        {1, 0, 0, 1, 0, 1},        // 6 dezenas
        {1, 6, 0, 2, 5, 3},        // 7 dezenas
        {1, 12, 15, 3, 15, 6},     // 8 dezenas
        {1, 18, 45, 4, 30, 10},    // 9 dezenas
        {1, 24, 90, 5, 50, 25},    // 10 dezenas
        {1, 30, 150, 6, 75, 21},   // 11 dezenas
        {1,36, 225, 7, 105, 28},   // 12 dezenas
        {1, 42, 315, 8, 140, 36},  // 13 dezenas
        {1, 48, 420, 9, 180, 45},  // 14 dezenas
        {1, 54, 540, 10, 225, 55}, // 15 dezenas
    };

    float sena = 118265926.76, quina = 32797.02, quadra = 834.93;

    float premio_total = 0.0;
    if (acertos == 6) {
        premio_total = sena * premio[QD - 6][0];
    } else if (acertos == 5) {
        premio_total = quina * premio[QD - 6][1];
    } else if (acertos == 4) {
        premio_total = quadra * premio[QD - 6][2];
    }

    return premio_total;
}



//Comparar numeros sorteados com valores do usuario
void sorteio (int ApostasManuais [][15], int ApostaSurpresinhas [] [15], int QT, int QM, int QD, int QS, float TotalApostas) {
    int teimosinhas = 1, acertos, num = 1, sorteadas [6]; float premio = 0.0, premiototal = 0.0, total = 0.0;
    system ("cls");

    printf("VOCE ESCOLHEU\n");
    printf("\n%d Dezenas", QD); //6 a 15
    printf("\n%d Manuais", QM); //0 a 3
    printf("\n%d Surpresinhas", QS); //0 a 7
    printf("\n%d Teimosinhas\n", QT);// 0, 1, 2, 4, 8
    printf("\n=======================================================================================");
    printf("\n\nVAMOS PRO SORTEIO");
    sleep (1);

    while (teimosinhas <= QT) {
        printf("\n\n===============================================================");
        printf("\n\n>>>> Concurso 000%d <<<<\n\n", teimosinhas);
        printf("Numeros Sorteados => ");
        num = 0;
        premiototal = 0.0;
        
        //Gerando sorteio
        for (int i = 0; i < 6; i++) {
            sorteadas [i] = rand() % 60 + 1;
            //Pra nao gerar numeros repetidos
            for (int j = 0; j < i; j++) {
                if (sorteadas [j] == sorteadas [i]) {
                    sorteadas [i] = rand() % 60 + 1;
                }
            }
            sleep (1);
            printf("%d ", sorteadas [i]);
        }
        printf("\n");
        printf("\n\n>>>COMPARANDO SUAS APOSTAS<<<\n");
        sleep (1);
        
         //Comparando Manuais
        for (int i = 0; i < QM; i++) {
            acertos = 0;

            for (int j = 0; j < QD; j++) {
                for (int k = 0; k < 6; k++) {
                    if (sorteadas [k] == ApostasManuais [i][j]){
                        acertos++;
                    }
                }
            }
            num++;
            printf("\n\nAposta %d (MANUAIS): ", num);
            usleep (500000);
            printf("%d/6", acertos);
            if (acertos == 4 || acertos == 5 || acertos == 6) {
                FunAcertos (acertos);
                premio = calculopremios (acertos, QD);
                premiototal = premiototal + premio;
            }
        }

        //Comparando Surpresinhas
        for (int i = 0; i < QS; i++) {
            acertos = 0;

            for (int j = 0; j < QD; j++) {
                for (int k = 0; k < 6; k++) {
                    if (sorteadas [k] == ApostaSurpresinhas [i][j]){
                        acertos++;
                    }
                }
            }
            num++;
            printf("\n\nAposta %d (SURPRESINHAS): ", num);
            usleep (500000);
            printf("%d/6", acertos);
            if (acertos == 4 || acertos == 5 || acertos == 6) {
                FunAcertos (acertos);
                premio = calculopremios (acertos, QD);
                premiototal = premiototal + premio;
            }
        }

        printf("\n\n\n$$$$$$ | Voce recebeu um valor de R$%.2f no concurso 000%d | $$$$$$\n\n\n", premiototal, teimosinhas);
        printf("\n===============================================================");

        total = premiototal + total;
        teimosinhas++;
    }

    printf("\n\nTOTAL DAS APOSTAS: R$%.2f", TotalApostas);
    printf("\nTotal dos Premios: R$%.2f", total);
    total = total - TotalApostas;
    printf("\n\n________________________________________________________________________________");
    printf("\n\n$$$ >>> O valor total ganho em TODOS os concursos foi de R$%.2f <<< $$$\n\n", total);
    printf("________________________________________________________________________________\n\n");
    

    printf("\n\nObrigado por participar das Loterias Caixa! ;) \n\n");
}