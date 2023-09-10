//
// Created by gonza on 1/9/2023.
//

#ifndef TP1_CHORIPANES_H
#define TP1_CHORIPANES_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <limits>

using namespace std;

using ubicacion = int;
using ubicaciones = vector<int>;
struct choripanesRes {
    int coste;
    ubicaciones proveedurias;
};
using memo = vector<vector<vector<choripanesRes>>>;


vector<vector<int>> conjuntoDePartes(int i, vector<int> n, int k);

vector<vector<int>> conjuntoDePartesNUtil(vector<int> n, int k, int i);

vector<vector<int>> conjuntoDePartesN(vector<int> n, int k);

int coste(ubicaciones &puestos, ubicaciones &proveedurias);

ubicacion proveeduriaMasCercana(ubicacion puesto, ubicaciones proveedurias);

choripanesRes choripanes(ubicaciones puestos, int cantProveedurias);

choripanesRes choripanesV2(ubicaciones &puestos, int k, int begin, int end);

choripanesRes choripanesV3(ubicaciones &puestos, int k, int begin, int end, memo &memory);

choripanesRes choripanesDP(ubicaciones puestos, int cantProveedurias);

#endif //TP1_CHORIPANES_H
