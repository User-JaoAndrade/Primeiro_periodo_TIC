#include <stdio.h>
#define TAM 1000

int main() {
    char string[TAM];
    int palavras = 0, naPalavra = 0;
    
    printf("Digite uma frase: ");
    fgets(string, TAM, stdin);

    for (int i = 0; string[i] != '\0'; i++) {
    
        if (string[i] != ' ') {
            if (!naPalavra) {
                palavras++;
                naPalavra = 1;
            }
        } else {
            naPalavra = 0;
        }
    }

    // Exibe o número de palavras encontradas
    printf("Foram encontradas %d palavras.\n", palavras);

    return 0;
}