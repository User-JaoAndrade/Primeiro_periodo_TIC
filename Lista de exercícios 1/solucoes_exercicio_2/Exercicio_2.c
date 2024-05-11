#include <stdio.h>

int main()
{
    int _opcao; float _distancia;

    printf("Digite uma das opcoes abaixo\n\n1- Transformar KPH para MPH\n2- Transformar MPH para KPH\n\nDigite o numero correspodente a opcao: ");
    scanf("%d", &_opcao); 
    
    switch (_opcao) 
    {
        case 1: 
          printf ("\n\nInforme os quilometros: "); scanf ("%f", &_distancia);
          _distancia = _distancia / 1.609344;
          printf("\n%.2f milhas por hora", _distancia);
          break;
          
        case 2:
          printf ("\n\nInforme as milhas: "); scanf ("%f", &_distancia);
          _distancia = _distancia * 1.609344;
          printf("\n%.2f quilometros por hora", _distancia);
          break;

        default:
          printf("Opcao invalida");
          
          break;
    }
    return 0;
}