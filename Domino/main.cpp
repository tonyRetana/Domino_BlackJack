#include <iostream>
#include <vector>
#include <cctype>
#include "estructura.h"
#include "domino.h"
#include "pantalla.h"
using namespace std;

int main()
{
    estructuraDomino dominoVector[28] = {};
    int vectorDesordenado[28]={};
    char respuesta;
    vector<int> tablero ={};
    vector<int> tablero2 = {};
    estructuraDomino jugador1[7] = {};
    estructuraDomino jugador2[7] = {};
    estructuraDomino jugador3[7] = {};
    estructuraDomino jugador4[7] = {};
    //definimos las variables y las matrices y le mostramos el menu al usuario
    menu();

    do{
        system("cls");//borramos la pantalla
        revolver(vectorDesordenado); //revolvemos un vector y generamos las fichas
        generarDomino(dominoVector);
        llenarJugadores(jugador1,jugador2,jugador3,jugador4,dominoVector,vectorDesordenado); //le asignamos a cada vector de jugador una parte del domino
        juego(jugador1,jugador2,jugador3,jugador4,tablero,tablero2);//empezamos el juego
        cout << "Quiere darle otra ronda?(S/n)\n";//se le pregunta al usuario si quiere volver a jugar para empezar de nuevo el ciclo
        cin >> respuesta;
    }while(toupper(respuesta)=='S');
    return 0;
}
