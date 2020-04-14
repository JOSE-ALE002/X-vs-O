#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

void llenar(char [3][3]);
void mostrar(char [3][3]);
void insertar(char [3][3]);
void rival(char [3][3]);
bool ganador(char [3][3]);
bool perdedor(char [3][3]);
bool endGame (char [3][3]);
int disponible(char [3][3]);

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
}

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

    if(ganador(array) && disponible(array)>=1 ){
        rival(array);
    }
    
}

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

