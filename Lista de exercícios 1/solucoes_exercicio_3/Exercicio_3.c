#include <stdio.h>

int main () 
{
    int n; //Quantidade de valores no vetor

    printf("Informe a quantidade de numeros que deseja digitar: "); scanf("%d", &n);

    int vetor[n], aux;

    //Escrever os números
    for (int i = 0; i < n; i++)
    {
        printf("Numero %d: ", i + 1); scanf("%d", &vetor[i]);
    }

    //Colocar os números em ordem crescente
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (vetor[i] > vetor[j])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

    //Mostrar todos os números digitados no array
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", vetor[i]);
    }

    return 0;
}