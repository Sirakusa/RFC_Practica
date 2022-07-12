#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void primera_letra_nom (char *stringg);

const char* todo_mayusculas (char *stringg,int j);

void apellido_paterno (char *stringg,int j);

void apellido_materno (char *stringg,int j);

main(){
    char p[30];
    int ch,i=0,f;
    char *array;

    printf("Please, provide input: ");

    while ((ch = getchar()) != '\n') {
        p[i] = (char)ch;
        i++;
    }
    array = (int *)malloc (i*sizeof(int));
    for (f = 0; f <= i; f++){
        array[f] = p[f];
    }
    
    printf("%s  \n",array);
    printf("%s  \n",todo_mayusculas(array,i));
    apellido_paterno(array,i);
    apellido_materno(array,i);
    primera_letra_nom(array);
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
    apellido = (int *)malloc(j*sizeof(int));
    for (f = 0; f <= j; f++){
        apellido[f] = stringg[f];
        printf("%c",apellido[f]);
    }
    free(apellido);
}

const char* todo_mayusculas (char *stringg,int j){
    int i;
    for (i = 0; i <= j; i++){
        if((stringg[i]>=95)&&(stringg[i]<=122)){
            stringg[i] -= 32;
        }
    }
    return stringg;
}

void apellido_paterno (char *stringg,int j){
    int i=0,n=0,h=0;

    for (i = 0; i <= j; i++){
        if(stringg[i]== ' '){
            n++;
        }
    }
    i = 0;
    while (n == 2){
        if(stringg[i]== ' '){
            printf("%c%c",stringg[i+1],stringg[i+2]);
            break;
        }
        i++;
    }
    i = 0;
    while ( n == 3){
        if(stringg[i]== ' '){
            h++;
        }
        if (h == 2){
            printf("%c%c",stringg[i+1],stringg[i+2]);
            break;
        }
        i++;
    }
    
}

void apellido_materno (char *stringg,int j){
    int i=0,n=0,h=0;
    while (i != j){
        if (stringg[i] == ' '){
            n++;
            h = i;
        }
        i++;
    }
    printf("%c",stringg[h+1]);
}