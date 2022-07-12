#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

void primera_letra_nom (char *nombre);              // prototopo de fuciones
const char* todo_mayusculas (char *nombre,int j);
void apellido_paterno (char *nombre,int j);
void apellido_materno (char *nombre,int j);
void ano_nacimineto (int);
void dia_nacimineto (int);
int verificar_dia (int,int,int);
int verificar_mes (int mes);

// inicio del main
main(){
    char p[30];
    int fecha;
    int ch,i=0,f,dia,anio,mes,diaa;
    char *nobre_completo;

    printf("Ingrese su nombre: ");

    while ((ch = getchar()) != '\n') {
        p[i] = (char)ch;
        i++;
    }
    nobre_completo = (int *)malloc (i*sizeof(int));
    for (f = 0; f <= i; f++){
        nobre_completo[f] = p[f];
    }
    printf("Ingrese su fecha de nacimiento 12 05 1983: ");
    scanf("%d %d %d",&dia,&mes,&anio);
    
    mes = verificar_mes(mes);
    dia = verificar_dia (dia,mes,anio);
    printf("%s  \n",todo_mayusculas(nobre_completo,i));
    apellido_paterno(nobre_completo,i);
    apellido_materno(nobre_completo,i);
    primera_letra_nom(nobre_completo);
    ano_nacimineto (anio);
    dia_nacimineto (mes);
    free(nobre_completo);
    exit(EXIT_SUCCESS);
}

// finaliza el main y comienzan las funciones

const char* todo_mayusculas (char *nombre,int j){
    int i;
    for (i = 0; i <= j; i++){
        if((nombre[i]>=95)&&(nombre[i]<=122)){
            nombre[i] -= 32;
        }
    }
    return nombre;
}

void primera_letra_nom (char *nombre){
    char *apellido;
    int j = 0,n = 0,f=0;
    while (n != 1){
        if ((nombre[j] != 'A')||(nombre[j] != 'E')||(nombre[j] != 'I')
        ||(nombre[j] != 'O')||(nombre[j] != 'U')){
            n = 1;
        }
        else{j++;}
    }
    apellido = (int *)malloc(j*sizeof(int));
    for (f = 0; f <= j; f++){
        apellido[f] = nombre[f];
        printf("%c",apellido[f]);
    }
    free(apellido);
}

void apellido_paterno (char *nombre,int j){
    int i=0,n=0,espblanco=0;

    for (i = 0; i <= j; i++){
        if(nombre[i]== ' '){
            n++;
        }
    }
    i = 0;
    while (n == 2){
        if(nombre[i]== ' '){
            printf("%c%c",nombre[i+1],nombre[i+2]);
            break;
        }
        i++;
    }
    i = 0;
    while ( n == 3){
        if(nombre[i]== ' '){
            espblanco++;
        }
        if (espblanco == 2){
            printf("%c%c",nombre[i+1],nombre[i+2]);
            break;
        }
        i++;
    }
    
}

void apellido_materno (char *nombre,int j){
    int i=0,n=0,h=0;
    while (i != j){
        if (nombre[i] == ' '){
            n++;
            h = i;
        }
        i++;
    }
    printf("%c",nombre[h+1]);
}

void ano_nacimineto (int anio){
    int ano=0;
    ano = anio / 10;
    printf("%d",ano%10);
    printf("%d",anio%10);
}

void dia_nacimineto (int dia){
    if(dia<=9)
        printf("0%d",dia);
    else
        printf("%d",dia);

}

int verificar_dia (int diaa,int mes,int anio){
    int dia,mess;
    bool x = true;
    dia = diaa;
while(x){
    if(mes == 2){
        if(anio%4 != 0 && anio%100 == 0 && anio%400 == 0)
            mess = 29;
        else
            mess = 28;
    }
    if(mes == 1||mes == 3||mes == 5||mes == 7|| mes ==8|| mes ==10||mes ==12)
        mess = 31;
    if(mes == 4||mes ==6||mes == 9||mes == 11)
        mess = 30;
    if (dia <= mess && dia >= 1)
        x = false;
    else{
        printf("el dia que introdujiste es incorrecto: \n");
        printf("intrduce dia: ");
        scanf("%d",&dia);
    }
}
return dia;
}

int verificar_mes (int mes){
    bool x = true;
    while (x){
        if(mes <= 12 && mes >= 1)
        x = true;
        else{
            printf("el mes es incorrecto\n");
            printf("introdusca el mes: ");
            scanf("%d",&mes);
            return mes;
        }
    return mes;
    }
}