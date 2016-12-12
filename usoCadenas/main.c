#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Prototipos de las funciones

    // calcular la longitud de la cadena
int longitud(char * cadena );
    // comprar cadenas
bool iguales(char * , char * );
    //mostrar minimo alfabeto de la cadena
void alfabeto(char* cadena );
    //concatena las cadenas
char *concatenar(char *cadena1 , char* cadena2);
    //potenciar e imprimir las cadenas
char *potencia(char *cadena , int n);

int main(){
    //variables de cadenas dinamicas

    char *a = (char*) malloc(50);
    char *b = (char*) malloc(50);
    char *c = (char*) malloc(250);
    char *p = (char*) malloc(250);
    int sizeA, sizeB, n, total;


    printf("Ingresa cadena a: \n");
    gets(a);
    printf("Ingresa cadena b: \n");
    gets(b);
    printf("potencia: ");
    scanf("%i", &n);

    printf("\n------------------------------------");
    printf("\n\tAlfabeto de la cadena A: ");
    alfabeto(a);

    sizeA = longitud(a);
    printf("\tLongitud de la cadena A: %i", sizeA);

    printf("\n\n");

    printf("\tAlfabeto de la cadena B: ");
    alfabeto(b);
    sizeB = longitud(b);

    printf("\tLongitud de la cadena B: %i\n", sizeB);
    printf("\n");
    if(iguales(a,b)){
        printf("\n\t Las cadenas A y B son iguales\n");
    }
    else {
        printf("\n\tLas cadenas A y B no son iguales\n");
    }
    printf("\n");

    printf("\tConcatenacion de A y B: ");
    total = sizeA+sizeB;
    c = concatenar(a,b);
    printf("%s", c);
    printf("\n\tLongitud de la concatenacion es: %i", total);

    printf("\n\n");

    printf("\tConcatenacion de B y A: ");
    c = concatenar(b,a);
    printf("%s",c);
    printf("\n\tLongitud de la concatenacion es: %i", total);

    printf("\n");

    printf("\n\tLa potencia %i de la cadena A: ",n);
    p=potencia(a,n);
    printf("%s", p);

    printf("\n\tLa potencia %i de la cadena B: ",n);
    p=potencia(b,n);
    printf("%s", p);
    printf("\n\n------------------------------------\n");

    //libero memoria
    free(a);
    free(b);
    return 0;
}

int longitud(char* cadena){
    int tamano=0;
    while(cadena[tamano] != '\0'){
        tamano ++;
    }
    return tamano;
}

bool iguales(char* a, char* b){

    int i = 0;
    //llamo tamano
    int limiteA = longitud(a),limiteB = longitud(b);

    if(limiteA == limiteB){
        while(i <= limiteA){
            if(a[i] != b[i]){
                return false;
            } else if(limiteA == i){
                return true;
            }
            i++;
        }
    }
    return false;
}

void alfabeto(char* cadena ){
    int i,j;
    int rep=0;
    int limite = longitud(cadena);
    char* copia = (char*) malloc(50);
    char temp;
    //copeado de cadena
    for(i=0;i<limite;i++){
        copia[i]=cadena[i];
    }
    //ordenado alfabetico de copia.
    for (i=0; i<limite-1; i++){
        for(j=i+1; j<limite; j++){
           if(copia[i]> copia[j]){
             temp=copia[i];
             copia[i]=copia[j];
             copia[j]=temp;
           }
        }
    }
    //elimino repetidos
    j=limite;
    while(j != 0){
        for(i=0;i<limite;i++){
            if(copia[j] == (copia[i])){
                rep++;
            }
            if(rep > 1){
                copia[j] = '\0';
            }
        }
        j--;
        rep=0;
    }
    //imprimo contenido de arreglo
   printf("[");
   for(i=0;i<limite;i++){
    if(*copia != '\0'){
        printf("%c,", *copia);
    }
    copia++;
   }
   //printf("%c",copia[limite]);
   printf("]");
   printf("\n");
    //libero memoria de cadenas dinamicas
    free(copia);
}

char *concatenar(char *cadena1 , char *cadena2 ){
    int limA = longitud(&*cadena1);
    int limB = longitud(&*cadena2);
    int limTotal= limA+limB;

    //char *nueva[limTotal];
    char *nueva =malloc((limTotal +1)* sizeof(char *));
    int i = 0;
    char *aux,*aux2;
    for(aux=cadena1; *aux != '\0'; aux++){
       nueva[i] = *aux;
       nueva[i+1] = '\0';
       i++;
    }

    for(aux2=cadena2; *aux2 != '\0'; aux2++){
        nueva[i] = *aux2;
        nueva[i+1] = '\0';
        i++;
    }

    return nueva;
}

char *potencia(char *cadena, int n){
    int limite = longitud(&*cadena);
    int i, j=0;
    char *aux;
    char *nueva =malloc((limite*n +1)* sizeof(char *));

    if(n == 0){
            nueva ="";
    }else{
        for(i = 0;i < n; i++){
            for(aux=cadena; *aux != '\0'; aux++){
            nueva[j] = *aux;
            nueva[j+1] = '\0';
            j++;
            }
        }
    }
    return nueva;
}
