#include <stdio.h>
#include <stdlib.h>

enum { SIZE = 30 };

int main(void)
{
    char buf[SIZE];
    char *p;
    int ch,i,tamano;
    p = buf;

    printf("Please, provide input: ");

    while ((ch = getchar()) != '\n') {
        *p++ = (char)ch;
    }
    *p++ = 0;
    printf("%s\n", buf);

    for (i = 0; i <= 30; i++){
        printf("[%d.%d]  ",i,buf[i]);
    }

    for (i = 0; i <= 30; i++){
        if(buf[i] == 0){
            tamano = i;
            break;
        }
    }
    
    printf("\npppppppppppppppppppppp");   
        printf("%d",tamano);
    exit(EXIT_SUCCESS);
}