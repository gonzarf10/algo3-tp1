//
// Created by gonza on 1/9/2023.
//

#ifndef TP1_TABLERO_H
#define TP1_TABLERO_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using x = int;
using y = int;
using posicion = pair<x, y>;
using tablero = vector<vector<string>>;
const int DERECHA = 1;
const int ARRIBA = 2;
const int IZQUIERDA = 3;
const int ABAJO = 4;

struct senderoRes {
    int min;
    int max;
    bool existeCamino;
    vector<posicion> caminoRecorrido;
};


bool estoyEnSalida(posicion actual, tablero t);
bool estoyFueraDeTablero(posicion actual, tablero t);
int obtenerDireccionDeLaQueVengo(posicion anterior, posicion actual);
senderoRes senderoBT(posicion anterior, posicion actual, tablero t, vector<posicion> posicionesRecorridas);
senderoRes sendero(const tablero& t);
void mostrarTablero(tablero t);
tablero pedirTablero();
vector<tablero> pedirTableros();
void analizarTablero(const tablero& t);
void pedirTablerosYAnalizar();
void ejemploEnunciado();
void pedirInfinitosTableros();

#endif //TP1_TABLERO_H
