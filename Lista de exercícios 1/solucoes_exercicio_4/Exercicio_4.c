#include <stdio.h>

int main (){

    int n, aux2;
    printf("Informe a quantidade de numeros que deseja informar: "); scanf("%d", &n);

    float vetor[n], aux, mediana;
    
    //Numeros digitados pelo usuario
    for (int i = 0; i < n; i++)
    {
        printf("Numero %d: ", i + 1); scanf("%f", &vetor[i]);
    }

    //Deixando em ordem crescente
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

    //a quantidade de numeros digitados eh par ou impar?
    if (n%2 == 0) //Par
    {
        aux2 = n/2;
        mediana = (vetor[aux2] + vetor[aux2-1]) / 2;
    }

    else //Impar
    {
        aux2 = n/2;
        mediana = vetor[aux2]; 
    }

    printf("A mediana eh %.2f", mediana);
    
    return 0;
}
