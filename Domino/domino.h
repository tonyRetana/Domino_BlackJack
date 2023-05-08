#include <time.h>
#include <stdlib.h>
using namespace std;
void generarDomino(estructuraDomino listaDomino[]){
    int aux = 0;

    for (int i=0 ; i <= 6 ; i++){
        for (int j=0; j<=i ; j++){
            listaDomino[aux].num1= i;
            listaDomino[aux].num2= j;
            listaDomino[aux].suma=i+j;
            //le asignamos un numero a cada ficha
            aux++;
        }
    }
}

void revolver(int vectorDesordenado[]){
    int aux=0, aux2=0;
    srand(time(NULL));
    //generamos una semilla aleatoria
    for(int i=0; i<28;i++){
        aux = rand()%28; //en el auxiliar le asignamos un numero aleatorio
        aux2=0;
        while(aux2<i){
            if(aux!=vectorDesordenado[aux2]){
                aux2++;//si aux es diferente al vector aumentamos en 1 la posicion del vector
            }
            else{
                aux2=0;//sino se reinicia la posicion y se genera un nuevo numero aleatorio
                aux=rand()%28;
            }
        }
        vectorDesordenado[i]=aux;//le asignamos al vector el numero aleatorio
    }
}

void llenarJugadores(estructuraDomino jugador1[], estructuraDomino jugador2[], estructuraDomino jugador3[], estructuraDomino jugador4[], estructuraDomino listaDomino[], int desorden[]){
    int aux=0;
    for(int i=0; i<7 ; i++){//le asignamos a cada jugador una ficha del vector
        jugador1[i].num1= listaDomino[desorden[i]].num1;
        jugador1[i].num2= listaDomino[desorden[i]].num2;
        jugador1[i].suma= listaDomino[desorden[i]].suma;
    }
    for(int i=7; i<14;i++){
        jugador2[aux].num1= listaDomino[desorden[i]].num1;
        jugador2[aux].num2= listaDomino[desorden[i]].num2;
        jugador2[aux].suma= listaDomino[desorden[i]].suma;
        aux++;
    }
    aux=0;
    for(int i=14; i<21 ; i++){
        jugador3[aux].num1= listaDomino[desorden[i]].num1;
        jugador3[aux].num2= listaDomino[desorden[i]].num2;
        jugador3[aux].suma= listaDomino[desorden[i]].suma;
        aux++;
    }
    aux=0;
    for(int i=21; i<28; i++){
        jugador4[aux].num1= listaDomino[desorden[i]].num1;
        jugador4[aux].num2= listaDomino[desorden[i]].num2;
        jugador4[aux].suma= listaDomino[desorden[i]].suma;
        aux++;
    }
}
