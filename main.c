#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void primera_letra_nom (char *stringg);

main(){
    char p[30];
    int ch,i=0,f;
    char *array;

    printf("Please, provide input: ");

    while ((ch = getchar()) != '\n') {
        p[i] = (char)ch - 32;
        i++;
    }
    array = (int *)malloc (i*sizeof(int));

    for (f = 0; f <= i; f++){
        array[f] = p[f];
    }
    printf("%s\n",array);
    apepaterno(array);
    free(array);
    exit(EXIT_SUCCESS);
}
void primera_letra_nom (char *stringg){
    char *apellido;
    int j = 0,n = 0,f=0;
    while (n != 1){
        if ((stringg[j] != 'A')||(stringg[j] != 'E')||(stringg[j] != 'I')
        ||(stringg[j] != 'O')||(stringg[j] != 'U')){
            n = 1;
        }
        else{j++;}
    }

    apellido = (int *)malloc (j*sizeof(int));
    for (f = 0; f <= j; f++){
        apellido[f] = stringg[f];
        printf("%c",apellido[f]);
    }
    free(apellido);
}