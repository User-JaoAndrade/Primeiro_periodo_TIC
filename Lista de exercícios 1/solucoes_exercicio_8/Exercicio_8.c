#include <stdio.h>
#include <string.h>
#define TAM 100

int main () {
    char str1 [TAM], str1copy[TAM]; //palavra digitada pelo usuario e copia dessa palavra pra inverter
    int tamanho, count = 0, i; //tamanho: tamanho da palavra digitada, count: contador pra ver se as letras sao iguais

    printf("Escreva uma palavra: "); gets (str1);
    tamanho = strlen (str1);
    
    //inverter as palavras que o usuario digitar
    for (i = 0; i < tamanho; i++) {
        str1copy [i] = str1[tamanho - 1];
        tamanho--;
    }
    str1copy[i] = '\0';

    //comparar se invertidas sao as mesmas palavras
    for (i = 0; i < tamanho; i++) {
        if (str1[i] == str1copy[i]) {
            count++;
        }
    }

    if (tamanho == count) {
        printf("'%s' eh palindromo", str1);
    } else {
        printf("'%s' nao eh palindromo", str1);
    }
    return 0;
}