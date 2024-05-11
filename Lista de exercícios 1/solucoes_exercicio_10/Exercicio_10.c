#include <stdio.h>
#include <string.h>
#define TAM 1000

int main () {
    char string [TAM], direcao; //direcao = Esquerda ou direita
    int pulo, tamanhoP, i; //pulo = numero de saltos, tamanhoP = tamanho da string

    printf("Digite a mensagem a ser criptografada: "); fgets(string, TAM, stdin);
    printf("Digite o valor do pulo: "); scanf("%d", &pulo);
    printf("Digite a direcao da codificacao (e/E || d/D): "); scanf(" %c", &direcao);

    //Verificar os espacos da frase
    for (i = 0; i < (tamanhoP = strlen(string)); i++) {
        if (string[i] == ' ') {
            continue;
        }

         //numero de pulos pra direita
        if (direcao == 'D' || direcao == 'd') {
            string[i] = string[i] + pulo;

            //Verificando de passou o limife superior da tabela ASCII
            if (string[i] > 126) {
                string[i] = string[i] - 126 + 33 - 1;
            }
        }

        //numero de pulos pra esquerda
        else if (direcao == 'E' || direcao == 'e') {
            string[i] = string [i] - pulo;

            //Verificando se passou o limite inferior da tabela ASCII
            if (string[i] < 33) {
            string [i] = string [i] + 126 - 33 + 1;
            }
        }
    }

    printf("Mensagem criptografada: %s\n", string);

    return 0;
}