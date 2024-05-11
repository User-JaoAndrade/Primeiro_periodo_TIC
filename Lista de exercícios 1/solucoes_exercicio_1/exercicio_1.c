#include<stdio.h>

int main()
{
    float _kelvin, _celsius, _fahrenheit; 
    
    printf ("Informe o valor de celsius: ");
    scanf ("%f", &_celsius);
    
   _kelvin = _celsius + 273.15; //Conversão para Kelvin*/
   _fahrenheit = (_celsius * 1.8) + 32; //Conversao para Fahrenheit*/
    
    printf ("\n%.2f graus Celsius eh igual a:\n%.2f graus Fahrenheit;\n%.2f Kelvin\n", _celsius, _fahrenheit, _kelvin);

    return 0;
}