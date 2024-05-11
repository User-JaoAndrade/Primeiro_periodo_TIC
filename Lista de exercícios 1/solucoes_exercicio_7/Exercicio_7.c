#include <stdio.h> 
#include <string.h>
#define TAM 100

//funcao principal
int main () {
    //variaveis
    char str1[TAM], str2[TAM]; //Palavras que o usuario vai digitar
    int letras1, letras2; //numero de letras nas palavras
    int countstr1, countstr2; //guardar se possui letras iguais
    
    //texto de auxilio para usuario
    printf("Informe a primeira palavra: "); gets (str1);
    fflush(stdin);
    printf("Informe a segunda palavra: "); gets (str2);
    system ("cls");

    //Contando quantas letras tem em str1 e str2
    letras1 = strlen (str1);
    letras2 = strlen (str2);

    if((letras1 != letras2) || (strcmp(str1, str2) == 0)) {
        printf("'%s' e '%s' nao sao anagramas", str1, str2);
        return 0;
    }

    //Comparando as letras
    for (int i = 0; i < letras1; i++) {

        countstr1 = 0;
        countstr2 = 0;
        
        //comparando se str1 tem as mesmas coisas que str2
        for (int j = 0; j < letras1; j++) {
            if (str1 [i] == str1[j]) {
                countstr1++;
            }
        }

        for (int k = 0; k < letras2; k++) {
            if (str1[i] == str2[k]) {
                countstr2++;
            }
        }
        
        //se tiver alguma letra diferente eles nao sao anagramas
        if(countstr1 != countstr2) {
            printf("'%s' e '%s' nao sao anagramas", str1, str2);
            return 0;
        }
    }

    printf("'%s' e '%s' sao anagramas", str1, str2);
    return 0;
}