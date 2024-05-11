#include <stdio.h>

int quadrado (int quad); //calcular quadrado

int main () {
    int n, quad; 

    do {
        printf("Informe um numero (0 caso deseje encerrar o programa): "); scanf("%d", &n);

        //Encerrar o programa
        if (n == 0) { printf("\nPrograma Encerrado!\n"); return 0; }

        quad = (n * (n + 1) * (2 * n + 1) / 6);

        printf("\n%d x %d tem %d quadrados\n", n, n, quad);
        printf("\nAperte '0' para encerrar o programa e qualquer outro valor para continuar: "); scanf ("%d", &n);
        system ("cls");

    } while (n != 0);

    printf("programa encerrado");

    return 0;
}
