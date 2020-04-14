#include <iostream>
#include <ctime> //FUNCION PARA GENERAR UN NUMERO RANDOM
#include <stdlib.h>//
using namespace std;

void llenar(char [3][3]); //PERMITE LLENAR LA MATRIZ CON LAS POSICIONES DEL 1-9
void mostrar(char [3][3]);//MUESTRA LA MATRIZ 
void insertar(char [3][3]);// INSERTA EL CARACTER 'X' - 'O', MODIFICANDO LA MATRIZ
void rival(char [3][3]);// PERMITE REALIZAR EL JUEGO DEL RIVAL
bool ganador(char [3][3]);//PERMITE SABER SI GANO LA 'X'
bool perdedor(char [3][3]);//PERMITE SABER SI GANO LA 'O'
bool endGame (char [3][3]);//VERIFICA SI TODAS LAS CASILLAS ESTAN LLENAS Y SI HAY UN GANADOR
int disponible(char [3][3]); // VERIFICA LA CANTIDAD DE CASILLAS VACIAS

int main(){
    char matriz[3][3];
    llenar(matriz);
    mostrar(matriz);

    do{
        insertar(matriz);
        cout<<"\n\n";
    }while(endGame(matriz));
    
    
    return 0;
}

//LLENAMOS EL ARREGLO CON LAS POSICIONES DEL 1-9
void llenar(char array[3][3]){
    char num = '1';

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            array[i][j] = num;
            num++;

        }      
    }
}

//MOSTRAMOS EL ARREGLO Y LAS MODIFICACIONES
void mostrar(char array[3][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<"\t"<<array[i][j]<<"\t||";
        }       

        cout<<"\n==================================================\n";
    }
}


//INSERTAMOS LOS MOVIMIENTOS DEL JUGADOR PRINCIPAL Y DE EL RIVAL
void insertar(char array[3][3]){
    char casilla;

    do{
        cout<<"Ingrese numero a jugar: ";
        cin>>casilla;
    }while(casilla <  '1' ||  casilla > '9');

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(array[i][j] == casilla){
                array[i][j] = 'X';
            }
        }      
    }

/*VERIFICAMOS SI HAN GANADO LAS 'X', y SI LAS CASILLAS DISPONIBLES SON MAYORES QUE 1, YA QUE CUANDO QUEDA 
LA ULTIMA CASILLAS ESTE LE PERTENECE A LAS 'X', MIENTRAS ESTO SE CUMPLA EL RIVAL PODRA DAR SU MOVIMIENTO*/
    if(ganador(array) && disponible(array)>=1 ){
        rival(array);
    }
    
}

/*VERIFICAMOS SI TODAS LAS CASILLAS ESTEN LLENAS Y SI HAY UN GANADOR, MIENTRAS NO OCURRA UNA DE ESTAS 
CONDICIONES EL JUEGO CONTINUARA*/
bool endGame (char arr[3][3]){
    bool resp = true;
    mostrar(arr);

    if(disponible(arr) != 0){
        if(!ganador(arr)){
            resp = false;
            cout<<"Has Ganado :D"<<endl;
        }
        
        if(!perdedor(arr)){
            resp = false;
            cout<<"Has Perdido :("<<endl;
        }
    }else{
        if(perdedor(arr) && ganador(arr)){
            resp = false;
            cout<<"Empate :/"<<endl;
        }

        if(!ganador(arr)){
            resp = false;
            cout<<"Has Ganado :D"<<endl;
        }
        
        if(!perdedor(arr)){
            resp = false;
            cout<<"Has Perdido :("<<endl;
        }
    }

    return resp;
}

//VERIFICAMOS SI LAS 'X' GANAN CON LAS POSIBLES COMBINACIONES GANADORORAS
bool ganador(char arr[3][3]){
    bool ganar = true;

    if((arr[0][0] == 'X' && arr[0][1] == 'X' && arr[0][2] == 'X')){
        ganar = false;
    }


    if((arr[1][0] == 'X' && arr[1][1] == 'X' && arr[1][2] == 'X')){
        ganar = false;
    }


    if((arr[2][0] == 'X' && arr[2][1] == 'X' && arr[2][2] == 'X')){
        ganar = false;
    }


    if((arr[0][0] == 'X' && arr[1][0] == 'X' && arr[2][0] == 'X')){
        ganar = false;
    }


    if((arr[0][1] == 'X' && arr[1][1] == 'X' && arr[2][1] == 'X')){
        ganar = false;
    }


    if((arr[0][2] == 'X' && arr[1][2] == 'X' && arr[2][2] == 'X')){
        ganar = false;
    }


    if((arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X')){
        ganar = false;
    }

    if((arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X')){
        ganar = false;
    }

    return ganar;
}

void mostrarGanador(char array[3][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<"\t"<<array[i][j]<<"\t||";
        }       

        cout<<"\n==================================================\n";
    }
}

//INSERTA MOVIMIENTO DEL RIVAL
void rival(char arr[3][3]){
    char *disponibles = new char[disponible(arr)];
    int index = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(arr[i][j] != 'X' && arr[i][j] != 'O'){
                disponibles[index] = arr[i][j];
                index++;
            }
        }
    }

    srand(time(NULL));
    int num = 0 + rand()% (disponible(arr));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(arr[i][j] == disponibles[num]){
                arr[i][j] = 'O';
            }
        }
    }

    delete []disponibles;
}

//VERIFICA LAS CASILLAS QUE ESTAN VACIAS
int disponible(char arr[3][3]){
    int acum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(arr[i][j] != 'X' && arr[i][j] != 'O'){
                acum++;
            }
        }
    }

    return acum;
}


//VERIFICAMOS SI LAS 'O' GANAN CON LAS POSIBLES COMBINACIONES GANADORORAS
bool perdedor(char arr[3][3]){
    bool perder = true;

    if((arr[0][0] == 'O' && arr[0][1] == 'O' && arr[0][2] == 'O')){
        perder = false;
    }


    if((arr[1][0] == 'O' && arr[1][1] == 'O' && arr[1][2] == 'O')){
        perder = false;
    }


    if((arr[2][0] == 'O' && arr[2][1] == 'O' && arr[2][2] == 'O')){
        perder = false;
    }


    if((arr[0][0] == 'O' && arr[1][0] == 'O' && arr[2][0] == 'O')){
        perder = false;
    }


    if((arr[0][1] == 'O' && arr[1][1] == 'O' && arr[2][1] == 'O')){
        perder = false;
    }


    if((arr[0][2] == 'O' && arr[1][2] == 'O' && arr[2][2] == 'O')){
        perder = false;
    }


    if((arr[0][0] == '0' && arr[1][1] == '0' && arr[2][2] == '0')){
        perder = false;
    }

    if((arr[0][2] == '0' && arr[1][1] == '0' && arr[2][0] == '0')){
        perder = false;
    }

    return perder;
}

