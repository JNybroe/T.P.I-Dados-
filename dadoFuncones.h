#ifndef DADOFUNCONES_H_INCLUDED
#define DADOFUNCONES_H_INCLUDED
#include <time.h>
#include <iostream>
#include <windows.h>
#include "rlutil.h"
using namespace std;

/// void nombreJugador(string nombre)
void acomodarNombreJugador(string &nombre){
    for(int i=0;i<nombre.length();i++){
        nombre[i]=towupper(nombre[i]);
    }
}

/// void calcularSexto(int dado[],int caraDado
bool verificarSexto(int dado[],int caraDado){
    bool haySexto=false;///Expresion booleana
    int iguales=0,contador=0;
    while(contador<=6){
        for(int i=0; i<=5;i++){
            if(contador==dado[i]){
                iguales++;
            }
        }
        if(iguales==6){
            haySexto=true;
            break;
        }else{
            iguales=0;
            contador++;
            haySexto=false;
        }
    }
    return haySexto;
}

/// void calcularNumRepetido(int dado[], int caraDado)
int calcularNumRepetido(int dado[],int caraDado){
    int numRepetido=0,anteriorRepetido=0;///Cual es el numero repetido
    int contador=0, iguales;
    while(contador<6){
        iguales=0;
        for(int i=0; i<=5;i++){
            if(dado[i]==dado[contador]){
                iguales++;
            }
        }
        if((iguales>=3)&&(iguales<=5)){
            numRepetido=dado[contador];
            if(numRepetido==0||numRepetido>anteriorRepetido){
                anteriorRepetido=numRepetido;
            }
        }else{
            if(iguales==6){
                numRepetido=dado[contador];
            }
        }
    contador++;
    }
return anteriorRepetido;
}

/// void calcularTriple(int dado[], int caraDado)
bool verificarTriple(int dado[],int caraDado){
    bool hayTriple;///Expresion booleana
    int contador=1, iguales;
    while(contador<=6){
        iguales=0;
        for(int i=0; i<=5;i++){
            if(contador==dado[i]){
                iguales++;
            }
        }
        if(iguales>=3&&iguales<=5){
            hayTriple=true;
            break;
        }else{
            iguales=0;
            contador++;
            hayTriple=false;
        }
    }
    return hayTriple;
}

///void verificarEscalera(int dado[], int caraDado)
bool verificarEscalera(int dado[], int caraDado){
    bool hayEscalera=false;/// Expresion booleana
    int contador=1,escalera=0;
    while(contador<=6){
        for(int i=0;i<=5;i++){ //0,1,2,3,4,5
            if(dado[i]==contador){
                escalera++;
            }
            contador++;
        }
    }
    if(escalera==6){
        hayEscalera=true;///Hay escalera
    }
    return hayEscalera;
}

///void lanzarDados(int dado[], int caraDado)
void lanzarDados(int dado[], int caraDado){
    for(int i=0;i<=5;i++){
        dado[i]=1+rand()%6;
    }
}

#endif // DADOFUNCONES_H_INCLUDED
