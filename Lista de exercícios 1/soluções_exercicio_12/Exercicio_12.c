#include <stdio.h>

int main () {

    int pessoas, saltos, vivo, casos;

    printf("Informe a quantidade de casos: "); scanf("%d", &casos);
    printf("\n");

    for (int i = 1; i <= casos; i++) {
        printf("Caso %d\n", i);
        printf("Informe a quantidade de pessoas: "); scanf("%d", &pessoas);
        printf("Informe o numero de saltos: "); scanf("%d", &saltos);

        for (int j = 1; j <= pessoas; j++) {
            vivo = (vivo + saltos) % j;
        }
        printf("\nA pessoa numero %d eh a sobrevivente\n\n", vivo + 1);
    }

    return 0;
}
    
