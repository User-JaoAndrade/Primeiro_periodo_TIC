#include <stdio.h>

int main () {
    int num, binario [32];

    printf("Exemplo\n\n");
    printf("Decimal (base 10): 20");
    printf("\nBinario (base 2): 10100\n\n");

    do {
        int i = 0;
        printf("informe um numero decimal (0 para encerrar o programa): "); scanf("%d", &num);

        //Caso o usuario queira encerrar o programa
        if (num == 0) {
            printf("\nPrograma Encerrado\n");
            return 0;
        }

        printf("\nDecimal (base 10): %d\n", num);

        //Convertendo para binario
        while (num > 0) {
            binario[i] = num % 2;
            num = num / 2;
            i++;
        }

        printf("Binario (base 2): ");

        for (int j = i - 1; j >= 0; j--) {
            printf("%d", binario [j]);
        }
        printf("\n\n");

        num = 1;

    } while (num != 0);
}