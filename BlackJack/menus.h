using namespace std;
void mensajeBienvenida(){
    system("cls");
    cout << "\n\n";
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl;
    cout << "*-Bienvenido al juego de black jack-*" << endl;
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl;
    cout << "\n\n";
    cout << "Reglas del juego:" << endl;//se le muestra al usuario el mensaje de bienvenida y las reglas de juego
    cout << "1. Se le van a dar 7 cartas a cada jugador\n";
    cout << "2. El jugador que haga una sumatoria de 21 gana automaticamente\n";
    cout << "3. Las cartas J,Q,K valen 10 y la A puede valer 1 o 11 segun sea el caso(11 por defecto)\n";
    cout << "4. La unica forma de que 2 ganen al mismo tiempo es que hayan varios jugadores con 21\n";
    cout << "5. Si ningun jugador llega a 21 es que solo 1 tenga la sumatoria mas alta, sino se muestra el empate\n\n\n";
    cout << "Presione ENTER para empezar\n";
    cin.get();
    system("cls");
    //se espera un enter y borra la pantalla
}
//*-*-*-*-*-*-*-*-*-*-*-*
void pedirNombres(string nombres[]){
    for (int i =0 ; i< 4 ; i++){
        cout << "Ingrese el nombre del jugador " << i+1 << ":\n";
        cin >> nombres[i]; //se guardan los nombres del jugador
    }
    cout << "Presione ENTER para continuar\n";
    cin.get();
    system("cls");
}
//**-*-*-*-*-*-*-*-*-*
void juego(string nombres[],int vectorDesorden[],datosNaipe baraja[]){
    int puntos1=0,puntos2=0,puntos3=0,puntos4=0,salto=8, cont1=0, cont2 =19,cont3=30,cont4=41;//
    char respuesta;
    cont1=8;
    cont2=19;

    cout << nombres[0] << ": \n";//escribimos en un mismo reglon el nombre del jugador y las 2 cartas iniciales de cada jugador
    cout << baraja[vectorDesorden[0]].letraNumero << baraja[vectorDesorden[0]].figura << " | ";//cada carta se compone de
    cout << baraja[vectorDesorden[1]].letraNumero << baraja[vectorDesorden[1]].figura << " \n";// la letra-numero y su palo
    puntos1 = baraja[vectorDesorden[0]].valor + baraja[vectorDesorden[1]].valor;//dibujando la carta con el valor aleatorio del vector desoden en su posicion correspondiente
    if((puntos1>21)&(baraja[vectorDesorden[0]].letraNumero=="A") || (baraja[vectorDesorden[1]].letraNumero=="A")){
        puntos1-=10;//si se detecta un numero mayor a 21 y hay un A en la mano del jugador se vuelve 1 ese A
        cout << "Se detecto una sumatoria mayor a 21 y la carta A, por ende ahora ese A vale 1 ahora\n";
    }
    do{ //para saber los puntos sumamos el resultado de la vector baraja que almacena los valores
        cout << nombres[0] << " quiere otra carta?(S/N)\n" ;
        cin>> respuesta;//despues de mostrarle las cartas a los jugadores se le pregunta si quiere otra carta
        if (toupper(respuesta)=='S'){
            cout << baraja[vectorDesorden[cont1]].letraNumero << baraja[vectorDesorden[cont1]].figura << " \n";
            puntos1+=baraja[vectorDesorden[cont1]].valor;//en caso de que lo quiera solo agregamos 1 carta mas en la posicion cont1
            if((puntos1>21)&(baraja[vectorDesorden[cont1]].letraNumero=="A")){
                puntos1-=10;
                cout << "Se detecto una sumatoria mayor a 21 y la carta A, por ende ahora ese A vale 1 ahora\n";
            }
            cont1++;
        }
        else{
            salto++;//sino agregamos 1 al salto
        }
        if(puntos1>21){
            respuesta='n';
            cout << nombres[0] << " Perdiste\n";
            salto++;//si el jugador hace mas de 21 en su sumatoria se le dice que perdio y se hace un +1 a salto y se le pone a
            puntos1=0;                                                                  //puntos1 el valor de 0
        }
    }while(toupper(respuesta)=='S');
    //la misma logica anterior se aplica al resto de jugadores, cambiando unicamente la posicion de los vectores
    cout << nombres[1] << ": ";
    cout << baraja[vectorDesorden[2]].letraNumero << baraja[vectorDesorden[2]].figura << " | ";
    cout << baraja[vectorDesorden[3]].letraNumero << baraja[vectorDesorden[3]].figura << " \n";
    puntos2 = baraja[vectorDesorden[2]].valor + baraja[vectorDesorden[3]].valor;
    if((puntos2>21)&(baraja[vectorDesorden[2]].letraNumero=="A") || (baraja[vectorDesorden[3]].letraNumero=="A")){
        puntos2-=10;//si se detecta un numero mayor a 21 y hay un A en la mano del jugador se vuelve 1 ese A
        cout << "Se detecto una sumatoria mayor a 21 y la carta A, por ende ahora ese A vale 1 ahora\n";
    }
    do{
        cout << nombres[1] << " quiere otra carta?(S/N)\n" ;
        cin>> respuesta;
        if (toupper(respuesta)=='S'){
            cout << baraja[vectorDesorden[cont2]].letraNumero << baraja[vectorDesorden[cont2]].figura << " \n";
            puntos2+=baraja[vectorDesorden[cont2]].valor;
            if((puntos2>21)&(baraja[vectorDesorden[cont2]].letraNumero=="A")){
                puntos2-=10;
                cout << "Se detecto una sumatoria mayor a 21 y la carta A, por ende ahora ese A vale 1 ahora\n";
            }
            cont2++;
        }
        else{
            salto++;
        }

        if(puntos2>21){
            respuesta='n';
            cout << nombres[1] << " Perdiste\n";
            salto++;
            puntos2=0;
        }
    }while(toupper(respuesta)=='S');

    cout << nombres[2] << ": ";
    cout << baraja[vectorDesorden[4]].letraNumero << baraja[vectorDesorden[4]].figura << " | ";
    cout << baraja[vectorDesorden[5]].letraNumero << baraja[vectorDesorden[5]].figura << " \n";
    puntos3 = baraja[vectorDesorden[4]].valor + baraja[vectorDesorden[5]].valor;
    if((puntos3>21)&(baraja[vectorDesorden[4]].letraNumero=="A") || (baraja[vectorDesorden[5]].letraNumero=="A")){
        puntos3-=10;//si se detecta un numero mayor a 21 y hay un A en la mano del jugador se vuelve 1 ese A
        cout << "Se detecto una sumatoria mayor a 21 y la carta A, por ende ahora ese A vale 1 ahora\n";
    }
    do{
        cout << nombres[2] << " quiere otra carta?(S/N)\n" ;
        cin>> respuesta;
        if (toupper(respuesta)=='S'){
            cout << baraja[vectorDesorden[cont3]].letraNumero << baraja[vectorDesorden[cont3]].figura << " \n";
            puntos3+=baraja[vectorDesorden[cont3]].valor;
            if((puntos3>21)&(baraja[vectorDesorden[cont3]].letraNumero=="A")){
                puntos3-=10;
                cout << "Se detecto una sumatoria mayor a 21 y la carta A, por ende ahora ese A vale 1 ahora\n";
            }
            cont3++;
        }
        else{
            salto++;
        }

        if(puntos3>21){
            respuesta='n';
            cout << nombres[2] << " Perdiste\n";
            salto++;
            puntos3=0;
        }
    }while(toupper(respuesta)=='S');

    cout << nombres[3] << ": ";
    cout << baraja[vectorDesorden[6]].letraNumero << baraja[vectorDesorden[6]].figura << " | ";
    cout << baraja[vectorDesorden[7]].letraNumero << baraja[vectorDesorden[7]].figura << " \n";
    puntos4 = baraja[vectorDesorden[6]].valor + baraja[vectorDesorden[7]].valor;
    if((puntos4>21)&(baraja[vectorDesorden[6]].letraNumero=="A") || (baraja[vectorDesorden[7]].letraNumero=="A")){
        puntos4-=10;//si se detecta un numero mayor a 21 y hay un A en la mano del jugador se vuelve 1 ese A
        cout << "Se detecto una sumatoria mayor a 21 y la carta A, por ende ahora ese A vale 1 ahora\n";
    }
    do{
        cout << nombres[3] << " quiere otra carta?\n" ;
        cin>> respuesta;
        if (toupper(respuesta)=='S'){
            cout << baraja[vectorDesorden[cont4]].letraNumero << baraja[vectorDesorden[cont4]].figura << " \n";
            puntos4+=baraja[vectorDesorden[cont4]].valor;
            if((puntos4>21)&(baraja[vectorDesorden[cont4]].letraNumero=="A")){
                puntos4-=10;
                cout << "Se detecto una sumatoria mayor a 21 y la carta A, por ende ahora ese A vale 1 ahora\n";
            }
            cont4++;
        }
        else{
            salto++;
        }
        if(puntos4>21){
            respuesta='n';
            cout << nombres[3] << " Perdiste\n";
            salto++;
            puntos4=0;
        }
    }while(toupper(respuesta)=='S');
    //si uno o mas jugadores hace 21 se muestra que ganaron
    if(puntos1==21){
        cout << "Gano " << nombres[0] << endl;
    }
    if(puntos2==21){
        cout << "Gano " << nombres[1] << endl;
    }
    if(puntos3 ==21){
        cout << "Gano " << nombres[2] << endl;
    }
    if(puntos4==21){
        cout << "Gano " << nombres[3] << endl;
    }
    //sino se revisa al unico jugador con la sumatoria mayor
    if((puntos1 <21) & (puntos1>puntos2) & (puntos1>puntos3) & (puntos1>puntos4)){
        cout << "Gano " << nombres[0] << endl;
    }
    else if((puntos2<21) & (puntos2>puntos1)& (puntos2>puntos3) & (puntos2>puntos4)){
        cout << "Gano " << nombres[1] << endl;
    }
    else if ((puntos3<21) & (puntos3>puntos1) & (puntos3>puntos2) & (puntos3>puntos4)){
        cout << "GANO " << nombres[2] << endl;
    }
    else if((puntos4<21) & (puntos4>puntos1) & (puntos4>puntos2) & (puntos4>puntos3)){
        cout << "GANO " << nombres[2] << endl;
    }
    else{//si hay mas de 1 con la sumatoria se muestra el empate
        cout << "Al parecer ningun jugador hizo un 21 y hay 2 jugadores con la misma suma, se decreta empate\n";
    }
    cout << "/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*" << endl;
    cout << "Para este turno se usaron " << salto << " cartas"<< endl;
    cout << "*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/" << endl; //se le dice a los jugadores cuantas cartas se usaron
}
