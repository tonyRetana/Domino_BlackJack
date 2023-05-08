//Anthony Jesus Retana Contreras || creado el 29/11/2022 || ultima modificacion 9/12/2022
//Juego de BlackJack
#include <iostream>
#include <cstdlib>
#include <array>
#include <cctype>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "estructura.h"
#include "menus.h"
#include "cartas.h"

using namespace std;
int main()
{
    datosNaipe cartas[52] = {};
    int desorden[52] ={};
    string nombres [4];
    char respuesta;


    mensajeBienvenida(); //le damos la bienvenida al a los jugadores
    do{
        system("cls"); // borramos pantalla para seguidamente enviar el vector nombre para que lo ingrese el usuario
        pedirNombres(nombres);
        asignadorFuncion(cartas); //creamos los valores y palos de la carta, para ello enviamos el vector de cartas y el num que es el valor de A
        revolver(desorden); //enviamos el vector desorden para crear numeros aleatorios entre 0 y 51 que no se repitan
        juego(nombres,desorden,cartas); //empieza el juego con el vector cartas, desorden y nombres
        cout << "Quiere volver a jugar(S/N)" << endl;
        cin >> respuesta; // luego del juego se le consulta al jugador si quiere volver a jugar
    }while(toupper(respuesta)=='S');//mientras la respuesta sea S se empezara un nuevo turno

    return 0;
}
