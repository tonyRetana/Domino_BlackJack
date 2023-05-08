using namespace std;

void asignadorFuncion(datosNaipe baraja[]){
    int cont=0;
    for (int i=0 ; i<4;i++){
        for (int j=0; j<13 ; j++){
            if(i==0){
                baraja[cont].figura= "\6"; //se inician 2 ciclos, con el ciclo i determinamos el palo correspondiente a la carta
            }//espadas
            else if (i==1){
                baraja[cont].figura= "\5";
            }//treboles
            else if(i==2){
                baraja[cont].figura= "\3";
            }//corazones
            else if(i==3){
                baraja[cont].figura= "\4";
            }//diamantes

            baraja[cont].valor= j+1; //guardamos el valor que tienen por defecto esas cartas para hacer la suma
            if (j>=10){
                baraja[cont].valor = 10; // en caso de ser j q k entonces valen 10
            }
            else if(j==0){
                baraja[cont].valor = 11; // y por default A vale 11
            }

            baraja[cont].letraNumero = to_string(j+1); //convertimos en string el valor a mostrar al jugador que tiene la carta
            if(j==0){
                baraja[cont].letraNumero = "A"; //y asignamos las A J Q K como casos especiales
            }
            else if(j==10){
                baraja[cont].letraNumero = "J";
            }
            else if (j==11){
                baraja[cont].letraNumero = "Q";
            }
            else if(j==12){
                baraja[cont].letraNumero = "K";
            }
            cont++;
        }
    }
}
//**************************************
void revolver(int vectorDesorden[]){
    int aux=0, aux2=0;
    srand(time(NULL));
    for(int i =0 ; i< 52; i++){
        aux= (0+rand()%52); //generamos un numero aleatorio entre 0 y 51
        aux2 = 0; // inicializamos este aux para comparar las posiciones en while
        while(aux2<i){
            if(aux!=vectorDesorden[aux2]){
                aux2++; //si son completamente diferentes sigue el ciclo de forma nomal aumentando en 1 el aux2
            }
            else{
                aux2=0; // sino, se reinicia el ciclo y se asigna un nuevo numero aleatorio
                aux= (0+rand()%52);
            }
        }
        vectorDesorden[i]=aux;// al final guardamos el aleatorio que no se repitio
    }
}

