#include <stdio.h>

int main () 
{
    int n;
    printf("Informe a quantidade de numeros que deseja digitar: "); scanf("%d", &n);
    int vetor [n];

    //Escrever os números
    for (int i = 0; i < n; i++)
    {
        printf("Numero %d: ", i + 1); scanf("%d", &vetor[i]);
    }
    
    
    //numero de ocorrencias

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (vetor[i] == vetor [j])
            {
                count++;
            }
        }

        int num_atual = 0;
        for (int k = 0; k < i; k++)
        {
            if(vetor[i] == vetor[k])
            {
                num_atual = 1;
                break;
            }
        }

        if (!num_atual)
        {
            printf("%d: %d ocorrencias\n", vetor[i], count);
        }
    }
    
    return 0;
}