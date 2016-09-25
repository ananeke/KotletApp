#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void sprawdz(int* cenapomodulo){

    if (*cenapomodulo <= 5)
        *cenapomodulo = 5;
    else
        *cenapomodulo = 9;
};




int main()
{
    int cena, cenapl,i;
    float mnoznik[4] = {0.85,0.75,0.65,0.5};
    int temp,temp2;
    char wybor;
    do{

        printf("\nPodaj cene w EURO znaleziona na zagranicznych stronach: ");
        scanf("%d", &cena);
        cenapl = cena*4;
        printf("Cena sugerowana to %d PLN \n\n", cenapl);
        printf("\tNormalne \t\t Dodatkowo obnizone\n");

        for(i=0; i<4; i++)
        {
            temp = cenapl*mnoznik[i];
            temp2 = cenapl*mnoznik[i];
            //printf("\n\ncena po obnizce %d\n\n", temp);
            temp = temp%10;
            temp2 -= temp;
            sprawdz(&temp);
            temp2 += temp;


            if(i==0)
                printf("\tKlasa 1 to %d PLN ", temp2);
            else if(i==1)
                printf("\t\t Klasa 1 to %d PLN \n", temp2);
            else if(i==2)
                printf("\tKlasa 2 to %d PLN ", temp2);
            else
                printf("\t\t Klasa 2 to %d PLN \n\n", temp2);
        }


        printf("Czy chcesz pracowac dalej? Wpisz t lub n: ");
        scanf(" %c", &wybor);


  } while (wybor !='n');
  printf("\t\tDziekuje za skorzystanie z programu\n\t\tCopyright by Dorota Przyjemska.");
  Sleep(2000);

    return 0;
}
