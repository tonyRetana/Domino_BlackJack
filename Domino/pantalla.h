using namespace std;

void menu(){
    cout << "******************************" << endl;
    cout << "**** BIENVENIDO AL DOMINO ****" << endl;
    cout << "******************************" << endl;
    cout << "\n\n\n";

    cout << "REGLAS:\n";
    cout << "1. A cada jugador se le dan 7 fichas\n";
    cout << "2. Empieza el jugador con la ficha [6|6]\n";
    cout << "3. El ganador es el que se quede sin fichas\n";
    cout << "4. En caso de que no se pueda poner mas fichas, gana el que tenga la suma menor en las fichas\n\n\n";

    cout << "SUERTE A LOS JUGADORES\n";
    cout << endl;
    cout << "Toque ENTER para comenzar\n";//le ensennamos al usuario el menu, esperamos un enter y borramos la pantalla
    cin.get();
    system("cls");
}

void juego(estructuraDomino jugador1[],estructuraDomino jugador2[], estructuraDomino jugador3[], estructuraDomino jugador4[],vector<int> tablero,vector<int> tablero2){
    int ficha=0,tamanno=0, pases=0, aux1=0,aux2=0,aux3=0,aux4=0;
    int suma1=0,suma2=0,suma3=0,suma4=0;
    int blanco1=0, blanco2=0, blanco3=0, blanco4=0;
//iniciamos las variables necesarias
    cout << "Las fichas del jugador 1 son: ";
    for (int i=0; i<7;i++){
        if((jugador1[i].num1 < 7)){
            cout << "["<< jugador1[i].num1 << "|" << jugador1[i].num2<<"] ";//dibujamos las fichas del profesor
        }
        if((jugador1[i].num1==6) & (jugador1[i].num2 == 6)){
            tablero.insert(tablero.begin(),jugador1[i].num1);
            tablero2.insert(tablero2.begin(),jugador1[i].num2);
            jugador1[i].num1=7;//si tiene la ficha 6 6 entonces se pone en tablero y se sustituye las fichas con un 7
            jugador1[i].num2=7;
            ficha =1;
        }
    }

    cout << "\nLas fichas del jugador 2 son: ";
    for (int i=0; i<7;i++){
        if(jugador2[i].num1<7){
            cout << "["<< jugador2[i].num1 << "|" << jugador2[i].num2<<"] ";
        }
        if((jugador2[i].num1==6) & (jugador2[i].num2 == 6)){
            tablero.insert(tablero.begin(),jugador2[i].num1);
            tablero2.insert(tablero2.begin(),jugador2[i].num2);
            jugador2[i].num1=7;
            jugador2[i].num2=7;
            ficha =2;
        }
    }

    cout << "\nLas fichas del jugador 3 son: ";
    for (int i=0; i<7;i++){
        if(jugador3[i].num1<7){
            cout << "["<< jugador3[i].num1 << "|" << jugador3[i].num2<<"] ";
        }
        if((jugador3[i].num1==6) & (jugador3[i].num2 == 6)){
            tablero.insert(tablero.begin(),jugador3[i].num1);
            tablero2.insert(tablero2.begin(),jugador3[i].num2);
            jugador3[i].num1=7;
            jugador3[i].num2=7;
            ficha =3;
        }
    }

    cout << "\nLas fichas del jugador 4 son: ";
    for (int i=0; i<7;i++){
        if(jugador4[i].num1<7){
            cout << "["<< jugador4[i].num1 << "|" << jugador4[i].num2<<"] ";
        }
        if((jugador4[i].num1==6) & (jugador4[i].num2 == 6)){
            tablero.insert(tablero.begin(),jugador4[i].num1);
            tablero2.insert(tablero2.begin(),jugador4[i].num2);
            jugador4[i].num1=7;
            jugador4[i].num2=7;
            ficha =3;//esto se usa para el segun
        }
    }
    cout << endl;

    cout << "En el tablero estan las siguientes fichas: ";
    tamanno=tablero.size();
    for(int i =0; i < tamanno; i++){
        cout << "[" << tablero[i] << "|" << tablero2[i] << "] ";//mostramos las fichas del tablero
    }
    cout << endl;

    do{
        aux1=0;
        aux2=0;
        aux3=0;
        aux4=0;
        blanco1=0;
        blanco2=0;
        blanco3=0;
        blanco4=0;
        pases=0;//antes de empezar el segun iniciamos todo en 0
        switch(ficha){//segun la ficha se hace el segun
        case 1:
            tamanno=tablero.size(); //encontramos el tamanno del vector tablero
            for(int i=0; i<7; i++){
                if(tablero[0]==jugador1[i].num1){ //revisamos las fichas del tablero con el del jugador para sustituirlas
                    tablero.insert(tablero.begin(),jugador1[i].num2);
                    tablero2.insert(tablero2.begin(),jugador1[i].num1);
                    jugador1[i].num1=7;
                    jugador1[i].num2=7;
                    aux1=1;
                    break;//se detiene el ciclo
                }
                else if(tablero[0]==jugador1[i].num2){
                    tablero.insert(tablero.begin(),jugador1[i].num1);
                    tablero2.insert(tablero2.begin(),jugador1[i].num2);
                    jugador1[i].num1=7;
                    jugador1[i].num2=7;
                    aux1=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador1[i].num2){
                    tablero.insert(tablero.end(),jugador1[i].num2);
                    tablero2.insert(tablero2.end(),jugador1[i].num1);
                    jugador1[i].num1=7;
                    jugador1[i].num2=7;
                    aux1=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador1[i].num1){
                    tablero.insert(tablero.end(),jugador1[i].num1);
                    tablero2.insert(tablero2.end(),jugador1[i].num2);
                    jugador1[i].num1=7;
                    jugador1[i].num2=7;
                    aux1=1;
                    break;
                }//se revisan las otras 3 posibilidades para insertar fichas al inicio o al final, para asi cambiar la pocision  de la ficha de ser necesario
            }
            cout << "Jugador 1: ";
            for(int i=0; i<7; i++){
                if((jugador1[i].num1 < 7)& (jugador1[i].num2 < 7)){
                    cout << "[" << jugador1[i].num1 << "|" << jugador1[i].num2 << "] ";
                }
            }//se muestran nuevamente las fichas del jugador y el tablero
            cout << endl;
            cout << "Tablero: ";
            tamanno=tablero.size();
            for(int i =0; i < tamanno; i++){
                cout << "[" << tablero[i] << "|" << tablero2[i] << "] ";
            }
            cout << endl;
            if(aux1==0){
                pases++;//si el jugador se queda sin jugadas se hace 1 pase de turno
                cout << "El jugador 1 se quedo sin fichas\n";
            }
            cout << "Presione ENTER para el siguiente turno\n";
            cin.get();//se le indica usuario que pase de turno
            //*********************************************************
            //se utiliza la misma logica para el resto de turno
            tamanno=tablero.size();
            for(int i=0; i<7; i++){
                if(tablero[0]==jugador2[i].num1){
                    tablero.insert(tablero.begin(),jugador2[i].num2);
                    tablero2.insert(tablero2.begin(),jugador2[i].num1);
                    jugador2[i].num1=7;
                    jugador2[i].num2=7;
                    aux2=1;
                    break;
                }
                else if(tablero[0]==jugador2[i].num2){
                    tablero.insert(tablero.begin(),jugador2[i].num1);
                    tablero2.insert(tablero2.begin(),jugador2[i].num2);
                    jugador2[i].num1=7;
                    jugador2[i].num2=7;
                    aux2=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador2[i].num2){
                    tablero.insert(tablero.end(),jugador2[i].num2);
                    tablero2.insert(tablero2.end(),jugador2[i].num1);
                    jugador2[i].num1=7;
                    jugador2[i].num2=7;
                    aux2=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador2[i].num1){
                    tablero.insert(tablero.end(),jugador2[i].num1);
                    tablero2.insert(tablero2.end(),jugador2[i].num2);
                    jugador2[i].num1=7;
                    jugador2[i].num2=7;
                    aux2=1;
                    break;
                }
            }
            cout << "Jugador 2: ";
            for(int i=0; i<7; i++){
                if((jugador2[i].num1 < 7)& (jugador2[i].num2 < 7)){
                    cout << "[" << jugador2[i].num1 << "|" << jugador2[i].num2 << "] ";
                }
            }
            cout << endl;
            tamanno=tablero.size();
            for(int i =0; i < tamanno; i++){
                cout << "[" << tablero[i] << "|" << tablero2[i] << "] ";
            }
            cout << endl;
            if(aux2==0){
                pases++;
                cout << "El jugador 2 se quedo sin fichas\n";
            }
            cout << "Presione ENTER para el siguiente turno\n";
            cin.get();
            //**************************************************
            tamanno=tablero.size();
            for(int i=0; i<7; i++){
                if(tablero[0]==jugador3[i].num1){
                    tablero.insert(tablero.begin(),jugador3[i].num2);
                    tablero2.insert(tablero2.begin(),jugador3[i].num1);
                    jugador3[i].num1=7;
                    jugador3[i].num2=7;
                    aux3=1;
                    break;
                }
                else if(tablero[0]==jugador3[i].num2){
                    tablero.insert(tablero.begin(),jugador3[i].num1);
                    tablero2.insert(tablero2.begin(),jugador3[i].num2);
                    jugador3[i].num1=7;
                    jugador3[i].num2=7;
                    aux3=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador3[i].num2){
                    tablero.insert(tablero.end(),jugador3[i].num2);
                    tablero2.insert(tablero2.end(),jugador3[i].num1);
                    jugador3[i].num1=7;
                    jugador3[i].num2=7;
                    aux3=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador3[i].num1){
                    tablero.insert(tablero.end(),jugador3[i].num1);
                    tablero2.insert(tablero2.end(),jugador3[i].num2);
                    jugador3[i].num1=7;
                    jugador3[i].num2=7;
                    aux3=1;
                    break;
                }
            }
            cout << "Jugador 3: ";
            for(int i=0; i<7; i++){
                if((jugador3[i].num1 < 7)& (jugador3[i].num2 < 7)){
                    cout << "[" << jugador3[i].num1 << "|" << jugador3[i].num2 << "] ";
                }
            }
            cout << endl;
            tamanno=tablero.size();
            for(int i =0; i < tamanno; i++){
                cout << "[" << tablero[i] << "|" << tablero2[i] << "] ";
            }
            cout << endl;
            if(aux3==0){
                pases++;
                cout << "El jugador 3 se quedo sin fichas\n";
            }
            cout << "Presione ENTER para el siguiente turno\n";
            cin.get();
            //********************************************
            tamanno=tablero.size();
            for(int i=0; i<7; i++){
                if(tablero[0]==jugador4[i].num1){
                    tablero.insert(tablero.begin(),jugador4[i].num2);
                    tablero2.insert(tablero2.begin(),jugador4[i].num1);
                    jugador4[i].num1=7;
                    jugador4[i].num2=7;
                    aux4=1;
                    break;
                }
                else if(tablero[0]==jugador4[i].num2){
                    tablero.insert(tablero.begin(),jugador4[i].num1);
                    tablero2.insert(tablero2.begin(),jugador4[i].num2);
                    jugador4[i].num1=7;
                    jugador4[i].num2=7;
                    aux4=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador4[i].num2){
                    tablero.insert(tablero.end(),jugador4[i].num2);
                    tablero2.insert(tablero2.end(),jugador4[i].num1);
                    jugador4[i].num1=7;
                    jugador4[i].num2=7;
                    aux4=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador4[i].num1){
                    tablero.insert(tablero.end(),jugador4[i].num1);
                    tablero2.insert(tablero2.end(),jugador4[i].num2);
                    jugador4[i].num1=7;
                    jugador4[i].num2=7;
                    aux4=1;
                    break;
                }
            }
            cout << "Jugador 4: ";
            for(int i=0; i<7; i++){
                if((jugador4[i].num1 < 7)& (jugador4[i].num2 < 7)){
                    cout << "[" << jugador4[i].num1 << "|" << jugador4[i].num2 << "] ";
                }
            }
            cout << endl;
            tamanno=tablero.size();
            for(int i =0; i < tamanno; i++){
                cout << "[" << tablero[i] << "|" << tablero2[i] << "] ";
            }
            cout << endl;
            if(aux4==0){
                pases++;
                cout << "El jugador 4 se quedo sin fichas\n";
            }
            cout << "Presione ENTER para el siguiente turno\n";
            cin.get();
            break;
        case 2:
            tamanno=tablero.size();
            for(int i=0; i<7; i++){
                if(tablero[0]==jugador2[i].num1){
                    tablero.insert(tablero.begin(),jugador2[i].num2);
                    tablero2.insert(tablero2.begin(),jugador2[i].num1);
                    jugador2[i].num1=7;
                    jugador2[i].num2=7;
                    aux2=1;
                    break;
                }
                else if(tablero[0]==jugador2[i].num2){
                    tablero.insert(tablero.begin(),jugador2[i].num1);
                    tablero2.insert(tablero2.begin(),jugador2[i].num2);
                    jugador2[i].num1=7;
                    jugador2[i].num2=7;
                    aux2=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador2[i].num2){
                    tablero.insert(tablero.end(),jugador2[i].num2);
                    tablero2.insert(tablero2.end(),jugador2[i].num1);
                    jugador2[i].num1=7;
                    jugador2[i].num2=7;
                    aux2=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador2[i].num1){
                    tablero.insert(tablero.end(),jugador2[i].num1);
                    tablero2.insert(tablero2.end(),jugador2[i].num2);
                    jugador2[i].num1=7;
                    jugador2[i].num2=7;
                    aux2=1;
                    break;
                }
            }
            cout << "Jugador 2: ";
            for(int i=0; i<7; i++){
                if((jugador2[i].num1 < 7)& (jugador2[i].num2 < 7)){
                    cout << "[" << jugador2[i].num1 << "|" << jugador2[i].num2 << "] ";
                }
            }
            cout << endl;
            tamanno=tablero.size();
            for(int i =0; i < tamanno; i++){
                cout << "[" << tablero[i] << "|" << tablero2[i] << "] ";
            }
            cout << endl;
            if(aux2==0){
                pases++;
                cout << "El jugador 2 se quedo sin fichas\n";
            }
            cout << "Presione ENTER para el siguiente turno\n";
            cin.get();
            //**************************************************
            tamanno=tablero.size();
            for(int i=0; i<7; i++){
                if(tablero[0]==jugador3[i].num1){
                    tablero.insert(tablero.begin(),jugador3[i].num2);
                    tablero2.insert(tablero2.begin(),jugador3[i].num1);
                    jugador3[i].num1=7;
                    jugador3[i].num2=7;
                    aux3=1;
                    break;
                }
                else if(tablero[0]==jugador3[i].num2){
                    tablero.insert(tablero.begin(),jugador3[i].num1);
                    tablero2.insert(tablero2.begin(),jugador3[i].num2);
                    jugador3[i].num1=7;
                    jugador3[i].num2=7;
                    aux3=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador3[i].num2){
                    tablero.insert(tablero.end(),jugador3[i].num2);
                    tablero2.insert(tablero2.end(),jugador3[i].num1);
                    jugador3[i].num1=7;
                    jugador3[i].num2=7;
                    aux3=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador3[i].num1){
                    tablero.insert(tablero.end(),jugador3[i].num1);
                    tablero2.insert(tablero2.end(),jugador3[i].num2);
                    jugador3[i].num1=7;
                    jugador3[i].num2=7;
                    aux3=1;
                    break;
                }
            }
            cout << "Jugador 3: ";
            for(int i=0; i<7; i++){
                if((jugador3[i].num1 < 7)& (jugador3[i].num2 < 7)){
                    cout << "[" << jugador3[i].num1 << "|" << jugador3[i].num2 << "] ";
                }
            }
            cout << endl;
            tamanno=tablero.size();
            for(int i =0; i < tamanno; i++){
                cout << "[" << tablero[i] << "|" << tablero2[i] << "] ";
            }
            cout << endl;
            if(aux3==0){
                pases++;
                cout << "El jugador 3 se quedo sin fichas\n";
            }
            cout << "Presione ENTER para el siguiente turno\n";
            cin.get();
            //********************************************
            tamanno=tablero.size();
            for(int i=0; i<7; i++){
                if(tablero[0]==jugador4[i].num1){
                    tablero.insert(tablero.begin(),jugador4[i].num2);
                    tablero2.insert(tablero2.begin(),jugador4[i].num1);
                    jugador4[i].num1=7;
                    jugador4[i].num2=7;
                    aux4=1;
                    break;
                }
                else if(tablero[0]==jugador4[i].num2){
                    tablero.insert(tablero.begin(),jugador4[i].num1);
                    tablero2.insert(tablero2.begin(),jugador4[i].num2);
                    jugador4[i].num1=7;
                    jugador4[i].num2=7;
                    aux4=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador4[i].num2){
                    tablero.insert(tablero.end(),jugador4[i].num2);
                    tablero2.insert(tablero2.end(),jugador4[i].num1);
                    jugador4[i].num1=7;
                    jugador4[i].num2=7;
                    aux4=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador4[i].num1){
                    tablero.insert(tablero.end(),jugador4[i].num1);
                    tablero2.insert(tablero2.end(),jugador4[i].num2);
                    jugador4[i].num1=7;
                    jugador4[i].num2=7;
                    aux4=1;
                    break;
                }
            }
            cout << "Jugador 4: ";
            for(int i=0; i<7; i++){
                if((jugador4[i].num1 < 7)& (jugador4[i].num2 < 7)){
                    cout << "[" << jugador4[i].num1 << "|" << jugador4[i].num2 << "] ";
                }
            }
            cout << endl;
            tamanno=tablero.size();
            for(int i =0; i < tamanno; i++){
                cout << "[" << tablero[i] << "|" << tablero2[i] << "] ";
            }
            cout << endl;
            if(aux4==0){
                pases++;
                cout << "El jugador 4 se quedo sin fichas\n";
            }
            cout << "Presione ENTER para el siguiente turno\n";
            cin.get();
            //**************************************************************
            tamanno=tablero.size();
            for(int i=0; i<7; i++){
                if(tablero[0]==jugador1[i].num1){
                    tablero.insert(tablero.begin(),jugador1[i].num2);
                    tablero2.insert(tablero2.begin(),jugador1[i].num1);
                    jugador1[i].num1=7;
                    jugador1[i].num2=7;
                    aux1=1;
                    break;
                }
                else if(tablero[0]==jugador1[i].num2){
                    tablero.insert(tablero.begin(),jugador1[i].num1);
                    tablero2.insert(tablero2.begin(),jugador1[i].num2);
                    jugador1[i].num1=7;
                    jugador1[i].num2=7;
                    aux1=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador1[i].num2){
                    tablero.insert(tablero.end(),jugador1[i].num2);
                    tablero2.insert(tablero2.end(),jugador1[i].num1);
                    jugador1[i].num1=7;
                    jugador1[i].num2=7;
                    aux1=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador1[i].num1){
                    tablero.insert(tablero.end(),jugador1[i].num1);
                    tablero2.insert(tablero2.end(),jugador1[i].num2);
                    jugador1[i].num1=7;
                    jugador1[i].num2=7;
                    aux1=1;
                    break;
                }
            }
            cout << "Jugador 1: ";
            for(int i=0; i<7; i++){
                if((jugador1[i].num1 < 7)& (jugador1[i].num2 < 7)){
                    cout << "[" << jugador1[i].num1 << "|" << jugador1[i].num2 << "] ";
                }
            }
            cout << endl;
            tamanno=tablero.size();
            for(int i =0; i < tamanno; i++){
                cout << "[" << tablero[i] << "|" << tablero2[i] << "] ";
            }
            cout << endl;
            if(aux1==0){
                pases++;
                cout << "El jugador 1 se quedo sin fichas\n";
            }
            cout << "Presione ENTER para el siguiente turno\n";
            cin.get();
            //*********************************************************
            break;
        case 3:
            tamanno=tablero.size();
            for(int i=0; i<7; i++){
                if(tablero[0]==jugador3[i].num1){
                    tablero.insert(tablero.begin(),jugador3[i].num2);
                    tablero2.insert(tablero2.begin(),jugador3[i].num1);
                    jugador3[i].num1=7;
                    jugador3[i].num2=7;
                    aux3=1;
                    break;
                }
                else if(tablero[0]==jugador3[i].num2){
                    tablero.insert(tablero.begin(),jugador3[i].num1);
                    tablero2.insert(tablero2.begin(),jugador3[i].num2);
                    jugador3[i].num1=7;
                    jugador3[i].num2=7;
                    aux3=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador3[i].num2){
                    tablero.insert(tablero.end(),jugador3[i].num2);
                    tablero2.insert(tablero2.end(),jugador3[i].num1);
                    jugador3[i].num1=7;
                    jugador3[i].num2=7;
                    aux3=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador3[i].num1){
                    tablero.insert(tablero.end(),jugador3[i].num1);
                    tablero2.insert(tablero2.end(),jugador3[i].num2);
                    jugador3[i].num1=7;
                    jugador3[i].num2=7;
                    aux3=1;
                    break;
                }
            }
            cout << "Jugador 3: ";
            for(int i=0; i<7; i++){
                if((jugador3[i].num1 < 7)& (jugador3[i].num2 < 7)){
                    cout << "[" << jugador3[i].num1 << "|" << jugador3[i].num2 << "] ";
                }
            }
            cout << endl;
            tamanno=tablero.size();
            for(int i =0; i < tamanno; i++){
                cout << "[" << tablero[i] << "|" << tablero2[i] << "] ";
            }
            cout << endl;
            if(aux3==0){
                pases++;
                cout << "El jugador 3 se quedo sin fichas\n";
            }
            cout << "Presione ENTER para el siguiente turno\n";
            cin.get();
            //********************************************
            tamanno=tablero.size();
            for(int i=0; i<7; i++){
                if(tablero[0]==jugador4[i].num1){
                    tablero.insert(tablero.begin(),jugador4[i].num2);
                    tablero2.insert(tablero2.begin(),jugador4[i].num1);
                    jugador4[i].num1=7;
                    jugador4[i].num2=7;
                    aux4=1;
                    break;
                }
                else if(tablero[0]==jugador4[i].num2){
                    tablero.insert(tablero.begin(),jugador4[i].num1);
                    tablero2.insert(tablero2.begin(),jugador4[i].num2);
                    jugador4[i].num1=7;
                    jugador4[i].num2=7;
                    aux4=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador4[i].num2){
                    tablero.insert(tablero.end(),jugador4[i].num2);
                    tablero2.insert(tablero2.end(),jugador4[i].num1);
                    jugador4[i].num1=7;
                    jugador4[i].num2=7;
                    aux4=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador4[i].num1){
                    tablero.insert(tablero.end(),jugador4[i].num1);
                    tablero2.insert(tablero2.end(),jugador4[i].num2);
                    jugador4[i].num1=7;
                    jugador4[i].num2=7;
                    aux4=1;
                    break;
                }
            }
            cout << "Jugador 4: ";
            for(int i=0; i<7; i++){
                if((jugador4[i].num1 < 7)& (jugador4[i].num2 < 7)){
                    cout << "[" << jugador4[i].num1 << "|" << jugador4[i].num2 << "] ";
                }
            }
            cout << endl;
            tamanno=tablero.size();
            for(int i =0; i < tamanno; i++){
                cout << "[" << tablero[i] << "|" << tablero2[i] << "] ";
            }
            cout << endl;
            if(aux4==0){
                pases++;
                cout << "El jugador 4 se quedo sin fichas\n";
            }
            cout << "Presione ENTER para el siguiente turno\n";
            cin.get();
            //**************************************************************
            tamanno=tablero.size();
            for(int i=0; i<7; i++){
                if(tablero[0]==jugador1[i].num1){
                    tablero.insert(tablero.begin(),jugador1[i].num2);
                    tablero2.insert(tablero2.begin(),jugador1[i].num1);
                    jugador1[i].num1=7;
                    jugador1[i].num2=7;
                    aux1=1;
                    break;
                }
                else if(tablero[0]==jugador1[i].num2){
                    tablero.insert(tablero.begin(),jugador1[i].num1);
                    tablero2.insert(tablero2.begin(),jugador1[i].num2);
                    jugador1[i].num1=7;
                    jugador1[i].num2=7;
                    aux1=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador1[i].num2){
                    tablero.insert(tablero.end(),jugador1[i].num2);
                    tablero2.insert(tablero2.end(),jugador1[i].num1);
                    jugador1[i].num1=7;
                    jugador1[i].num2=7;
                    aux1=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador1[i].num1){
                    tablero.insert(tablero.end(),jugador1[i].num1);
                    tablero2.insert(tablero2.end(),jugador1[i].num2);
                    jugador1[i].num1=7;
                    jugador1[i].num2=7;
                    aux1=1;
                    break;
                }
            }
            cout << "Jugador 1: ";
            for(int i=0; i<7; i++){
                if((jugador1[i].num1 < 7)& (jugador1[i].num2 < 7)){
                    cout << "[" << jugador1[i].num1 << "|" << jugador1[i].num2 << "] ";
                }
            }
            cout << endl;
            tamanno=tablero.size();
            for(int i =0; i < tamanno; i++){
                cout << "[" << tablero[i] << "|" << tablero2[i] << "] ";
            }
            cout << endl;
            if(aux1==0){
                pases++;
                cout << "El jugador 1 se quedo sin fichas\n";
            }
            cout << "Presione ENTER para el siguiente turno\n";
            cin.get();
            //*********************************************************
            tamanno=tablero.size();
            for(int i=0; i<7; i++){
                if(tablero[0]==jugador2[i].num1){
                    tablero.insert(tablero.begin(),jugador2[i].num2);
                    tablero2.insert(tablero2.begin(),jugador2[i].num1);
                    jugador2[i].num1=7;
                    jugador2[i].num2=7;
                    aux2=1;
                    break;
                }
                else if(tablero[0]==jugador2[i].num2){
                    tablero.insert(tablero.begin(),jugador2[i].num1);
                    tablero2.insert(tablero2.begin(),jugador2[i].num2);
                    jugador2[i].num1=7;
                    jugador2[i].num2=7;
                    aux2=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador2[i].num2){
                    tablero.insert(tablero.end(),jugador2[i].num2);
                    tablero2.insert(tablero2.end(),jugador2[i].num1);
                    jugador2[i].num1=7;
                    jugador2[i].num2=7;
                    aux2=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador2[i].num1){
                    tablero.insert(tablero.end(),jugador2[i].num1);
                    tablero2.insert(tablero2.end(),jugador2[i].num2);
                    jugador2[i].num1=7;
                    jugador2[i].num2=7;
                    aux2=1;
                    break;
                }
            }
            cout << "Jugador 2: ";
            for(int i=0; i<7; i++){
                if((jugador2[i].num1 < 7)& (jugador2[i].num2 < 7)){
                    cout << "[" << jugador2[i].num1 << "|" << jugador2[i].num2 << "] ";
                }
            }
            cout << endl;
            tamanno=tablero.size();
            for(int i =0; i < tamanno; i++){
                cout << "[" << tablero[i] << "|" << tablero2[i] << "] ";
            }
            cout << endl;
            if(aux2==0){
                pases++;
                cout << "El jugador 2 se quedo sin fichas\n";
            }
            cout << "Presione ENTER para el siguiente turno\n";
            cin.get();
            //**************************************************
        case 4:
            tamanno=tablero.size();
            for(int i=0; i<7; i++){
                if(tablero[0]==jugador4[i].num1){
                    tablero.insert(tablero.begin(),jugador4[i].num2);
                    tablero2.insert(tablero2.begin(),jugador4[i].num1);
                    jugador4[i].num1=7;
                    jugador4[i].num2=7;
                    aux4=1;
                    break;
                }
                else if(tablero[0]==jugador4[i].num2){
                    tablero.insert(tablero.begin(),jugador4[i].num1);
                    tablero2.insert(tablero2.begin(),jugador4[i].num2);
                    jugador4[i].num1=7;
                    jugador4[i].num2=7;
                    aux4=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador4[i].num2){
                    tablero.insert(tablero.end(),jugador4[i].num2);
                    tablero2.insert(tablero2.end(),jugador4[i].num1);
                    jugador4[i].num1=7;
                    jugador4[i].num2=7;
                    aux4=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador4[i].num1){
                    tablero.insert(tablero.end(),jugador4[i].num1);
                    tablero2.insert(tablero2.end(),jugador4[i].num2);
                    jugador4[i].num1=7;
                    jugador4[i].num2=7;
                    aux4=1;
                    break;
                }
            }
            cout << "Jugador 4: ";
            for(int i=0; i<7; i++){
                if((jugador4[i].num1 < 7)& (jugador4[i].num2 < 7)){
                    cout << "[" << jugador4[i].num1 << "|" << jugador4[i].num2 << "] ";
                }
            }
            cout << endl;
            tamanno=tablero.size();
            for(int i =0; i < tamanno; i++){
                cout << "[" << tablero[i] << "|" << tablero2[i] << "] ";
            }
            cout << endl;
            if(aux4==0){
                pases++;
                cout << "El jugador 4 se quedo sin fichas\n";
            }
            cout << "Presione ENTER para el siguiente turno\n";
            cin.get();
            //**************************************************************
            tamanno=tablero.size();
            for(int i=0; i<7; i++){
                if(tablero[0]==jugador1[i].num1){
                    tablero.insert(tablero.begin(),jugador1[i].num2);
                    tablero2.insert(tablero2.begin(),jugador1[i].num1);
                    jugador1[i].num1=7;
                    jugador1[i].num2=7;
                    aux1=1;
                    break;
                }
                else if(tablero[0]==jugador1[i].num2){
                    tablero.insert(tablero.begin(),jugador1[i].num1);
                    tablero2.insert(tablero2.begin(),jugador1[i].num2);
                    jugador1[i].num1=7;
                    jugador1[i].num2=7;
                    aux1=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador1[i].num2){
                    tablero.insert(tablero.end(),jugador1[i].num2);
                    tablero2.insert(tablero2.end(),jugador1[i].num1);
                    jugador1[i].num1=7;
                    jugador1[i].num2=7;
                    aux1=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador1[i].num1){
                    tablero.insert(tablero.end(),jugador1[i].num1);
                    tablero2.insert(tablero2.end(),jugador1[i].num2);
                    jugador1[i].num1=7;
                    jugador1[i].num2=7;
                    aux1=1;
                    break;
                }
            }
            cout << "Jugador 1: ";
            for(int i=0; i<7; i++){
                if((jugador1[i].num1 < 7)& (jugador1[i].num2 < 7)){
                    cout << "[" << jugador1[i].num1 << "|" << jugador1[i].num2 << "] ";
                }
            }
            cout << endl;
            tamanno=tablero.size();
            for(int i =0; i < tamanno; i++){
                cout << "[" << tablero[i] << "|" << tablero2[i] << "] ";
            }
            cout << endl;
            if(aux1==0){
                pases++;
                cout << "El jugador 1 se quedo sin fichas\n";
            }
            cout << "Presione ENTER para el siguiente turno\n";
            cin.get();
            //*********************************************************
            tamanno=tablero.size();
            for(int i=0; i<7; i++){
                if(tablero[0]==jugador2[i].num1){
                    tablero.insert(tablero.begin(),jugador2[i].num2);
                    tablero2.insert(tablero2.begin(),jugador2[i].num1);
                    jugador2[i].num1=7;
                    jugador2[i].num2=7;
                    aux2=1;
                    break;
                }
                else if(tablero[0]==jugador2[i].num2){
                    tablero.insert(tablero.begin(),jugador2[i].num1);
                    tablero2.insert(tablero2.begin(),jugador2[i].num2);
                    jugador2[i].num1=7;
                    jugador2[i].num2=7;
                    aux2=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador2[i].num2){
                    tablero.insert(tablero.end(),jugador2[i].num2);
                    tablero2.insert(tablero2.end(),jugador2[i].num1);
                    jugador2[i].num1=7;
                    jugador2[i].num2=7;
                    aux2=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador2[i].num1){
                    tablero.insert(tablero.end(),jugador2[i].num1);
                    tablero2.insert(tablero2.end(),jugador2[i].num2);
                    jugador2[i].num1=7;
                    jugador2[i].num2=7;
                    aux2=1;
                    break;
                }
            }
            cout << "Jugador 2: ";
            for(int i=0; i<7; i++){
                if((jugador2[i].num1 < 7)& (jugador2[i].num2 < 7)){
                    cout << "[" << jugador2[i].num1 << "|" << jugador2[i].num2 << "] ";
                }
            }
            cout << endl;
            tamanno=tablero.size();
            for(int i =0; i < tamanno; i++){
                cout << "[" << tablero[i] << "|" << tablero2[i] << "] ";
            }
            cout << endl;
            if(aux2==0){
                pases++;
                cout << "El jugador 2 se quedo sin fichas\n";
            }
            cout << "Presione ENTER para el siguiente turno\n";
            cin.get();
            //**************************************************
            tamanno=tablero.size();
            for(int i=0; i<7; i++){
                if(tablero[0]==jugador3[i].num1){
                    tablero.insert(tablero.begin(),jugador3[i].num2);
                    tablero2.insert(tablero2.begin(),jugador3[i].num1);
                    jugador3[i].num1=7;
                    jugador3[i].num2=7;
                    aux3=1;
                    break;
                }
                else if(tablero[0]==jugador3[i].num2){
                    tablero.insert(tablero.begin(),jugador3[i].num1);
                    tablero2.insert(tablero2.begin(),jugador3[i].num2);
                    jugador3[i].num1=7;
                    jugador3[i].num2=7;
                    aux3=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador3[i].num2){
                    tablero.insert(tablero.end(),jugador3[i].num2);
                    tablero2.insert(tablero2.end(),jugador3[i].num1);
                    jugador3[i].num1=7;
                    jugador3[i].num2=7;
                    aux3=1;
                    break;
                }
                else if(tablero2[tamanno-1]==jugador3[i].num1){
                    tablero.insert(tablero.end(),jugador3[i].num1);
                    tablero2.insert(tablero2.end(),jugador3[i].num2);
                    jugador3[i].num1=7;
                    jugador3[i].num2=7;
                    aux3=1;
                    break;
                }
            }
            cout << "Jugador 3: ";
            for(int i=0; i<7; i++){
                if((jugador3[i].num1 < 7)& (jugador3[i].num2 < 7)){
                    cout << "[" << jugador3[i].num1 << "|" << jugador3[i].num2 << "] ";
                }
            }
            cout << endl;
            tamanno=tablero.size();
            for(int i =0; i < tamanno; i++){
                cout << "[" << tablero[i] << "|" << tablero2[i] << "] ";
            }
            cout << endl;
            if(aux3==0){
                pases++;
                cout << "El jugador 3 se quedo sin fichas\n";
            }
            cout << "Presione ENTER para el siguiente turno\n";
            cin.get();
            break;
        }
        for(int i=0; i<7; i++){
            if((jugador1[i].num1==7)&(jugador1[i].num2==7)){
                blanco1+=1;//si el jugador tiene 1 ficha en 7 (en blanco) se suma 1
            }
            if((jugador2[i].num1==7)&(jugador2[i].num2==7)){
                blanco2+=1;
            }
            if((jugador3[i].num1==7)&(jugador3[i].num2==7)){
                blanco3+=1;
            }
            if((jugador4[i].num1==7)&(jugador4[i].num2==7)){
                blanco4+=1;
            }
        }
        if(blanco1>6){
            pases=4;
        }
        else if(blanco2>6){
            pases=4;
        }
        else if(blanco3>6){
            pases=4;
        }
        else if(blanco4>6){
            pases=4;
        }
    }while(pases<4);
    for(int i=0; i<7; i++){
        if((jugador1[i].num1<7)&(jugador1[i].num2<7)){
            suma1+=jugador1[i].num1 + jugador1[i].num2;
        }// se muestra las sumatorias de las fichas
        if((jugador2[i].num1<7)&(jugador2[i].num2<7)){
            suma2+=jugador2[i].num1 + jugador2[i].num2;
        }
        if((jugador3[i].num1<7)&(jugador3[i].num2<7)){
            suma3+=jugador3[i].num1 + jugador3[i].num2;
        }
        if((jugador4[i].num1<7)&(jugador4[i].num2<7)){
            suma4+= jugador4[i].num1 + jugador4[i].num2;
        }
    }
    if((suma1<=suma2)&(suma1<=suma3)&(suma1<=suma4)){
        cout << "El ganador del juego es el jugador 1\n";
    }// el que tenga la sumatoria menor gana
    else if((suma2<=suma1)&(suma2<=suma3)&(suma2<=suma4)){
        cout << "El ganador del juego es el jugador 2\n";
    }
    else if((suma3<=suma1)&(suma3<=suma2)&(suma3<=suma4)){
        cout << "El ganador del juego es el jugador 3\n";
    }
    else if((suma4<=suma1)&(suma4<=suma2)&(suma4<=suma3)){
        cout << "El ganador del juego es el jugador 4\n";
    }
}

