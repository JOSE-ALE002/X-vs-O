#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;


int main(){
    char matriz[3][3];
    char casilla;
    llenar(matriz);

    do{
        do{
            mostrar(matriz);
            cin>>casilla;
        }while( casilla <  '1' ||  casilla > '9');
        modificar(matriz, casilla);

        if(disponible(matriz) != 0){
            cout<<"Disponibles antes:"<<disponible(matriz)<<endl;
            rival(matriz);
            cout<<"Disponibles despues:"<<disponible(matriz)<<endl;
        }else if(disponible(matriz) == 0 && ganador(matriz)){
            cout<<"Empate";
        }
        
    }while(endGame(matriz) && ganador(matriz));

    // mostrar(matriz);
    
    return 0;
}

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

void mostrar(char array[3][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<"\t"<<array[i][j]<<"\t||";
        }       

        cout<<"\n==================================================\n";
    }

    cout<<"Ingrese numero a jugar: ";
}

void modificar(char array[3][3], char num){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(array[i][j] == num){
                array[i][j] = 'X';
            }
        }      
    }
}

bool endGame (char arr[3][3]){
    bool resp = false;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(arr[i][j] != 'X' || arr[i][j] != 'O'){
                resp = true;
                break;
            }

            if(resp == true){
                break;
            }
        }     
    }

    return resp;
}

bool ganador(char arr[3][3]){
    bool ganar = true;
    if((arr[0][0] == 'X' && arr[0][1] == 'X' && arr[0][2] == 'X')){
        ganar = false;
        mostrar(arr);
        cout<<"Ganaste"<<endl;
    }else if((arr[0][0] == 'O' && arr[0][1] == 'O' && arr[0][2] == 'O')){
        ganar = false;
        mostrar(arr);
        cout<<"Has Perdido"<<endl;
    }


    if((arr[1][0] == 'X' && arr[1][1] == 'X' && arr[1][2] == 'X')){
        ganar = false;
        mostrar(arr);
        cout<<"Ganaste"<<endl;
    }else if((arr[1][0] == 'O' && arr[1][1] == 'O' && arr[1][2] == 'O')){
        ganar = false;
        mostrar(arr);
        cout<<"Has Perdido"<<endl;
    }


    if((arr[2][0] == 'X' && arr[2][1] == 'X' && arr[2][2] == 'X')){
        ganar = false;
        mostrar(arr);
        cout<<"Ganaste"<<endl;
    }else if((arr[2][0] == 'O' && arr[2][1] == 'O' && arr[2][2] == 'O')){
        ganar = false;
        mostrar(arr);
        cout<<"Has Perdido"<<endl;
    }


    if((arr[0][0] == 'X' && arr[1][0] == 'X' && arr[2][0] == 'X')){
        ganar = false;
        mostrar(arr);
        cout<<"Ganaste"<<endl;
    }else if((arr[0][0] == 'O' && arr[1][0] == 'O' && arr[2][0] == 'O')){
        ganar = false;
        mostrar(arr);
        cout<<"Has Perdido"<<endl;
    }


    if((arr[0][1] == 'X' && arr[1][1] == 'X' && arr[2][1] == 'X')){
        ganar = false;
        mostrar(arr);
        cout<<"Ganaste"<<endl;
    }else if((arr[0][1] == 'O' && arr[1][1] == 'O' && arr[2][1] == 'O')){
        ganar = false;
        mostrar(arr);
        cout<<"Has Perdido"<<endl;
    }


    if((arr[0][2] == 'X' && arr[1][2] == 'X' && arr[2][2] == 'X')){
        ganar = false;
        mostrar(arr);
        cout<<"Ganaste"<<endl;
    }else if((arr[0][2] == 'O' && arr[1][2] == 'O' && arr[2][2] == 'O')){
        ganar = false;
        mostrar(arr);
        cout<<"Has Perdido"<<endl;
    }

    if((arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X')){
        ganar = false;
        mostrar(arr);
        cout<<"Ganaste"<<endl;
    }else if((arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O')){
        ganar = false;
        mostrar(arr);
        cout<<"Has Perdido"<<endl;
    }

    
    if((arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X')){
        ganar = false;
        mostrar(arr);
        cout<<"Ganaste"<<endl;
    }else if((arr[0][1] == 'O' && arr[1][1] == 'O' && arr[2][1] == 'O')){
        ganar = false;
        mostrar(arr);
        cout<<"Has Perdido"<<endl;
    }

    if((arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X')){
        ganar = false;
        mostrar(arr);
        cout<<"Ganaste"<<endl;
    }else if((arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O')){
        ganar = false;
        mostrar(arr);
        cout<<"Has Perdido"<<endl;
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

void rival(char arr[3][3]){
    char *disponibles = new char[disponible(arr)];
    int index = 0;

    cout<<"Disponibles en funcion: "<<disponible(arr)<<endl;
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
    cout<<"La posicion elegida O es: "<<disponibles[num]<<endl;
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

