//
// Created by gonza on 1/9/2023.
//
#include "choripanes.h"


ubicacion proveeduriaMasCercana(ubicacion puesto, ubicaciones proveedurias) {
    pair<int, int> res = make_pair(proveedurias[0], abs(proveedurias[0] - puesto));

    for (const ubicacion prov: proveedurias) {
        int diferencia = abs(puesto - prov);

        int minimo = min(diferencia, res.second);
        if (minimo == diferencia && res.second != minimo) {
            res = make_pair(prov, diferencia);
        }
    }

    return res.first;
};

int coste(ubicaciones &puestos, ubicaciones &proveedurias) {
    int res = 0;
    for (ubicacion &puesto: puestos) {

        res += abs(proveeduriaMasCercana(puesto, proveedurias) - puesto);
    }

    return res;
};

vector<vector<int>> conjuntoDePartes(int i, vector<int> n, int k) {
    if (k == 0 or i == n.size()) {
        return {{}};
    }
    vector<vector<int>> res, res1;
    res = conjuntoDePartes(i + 1, n, k - 1);
    res1 = res;

    for (auto conj: res) {
        conj.insert(conj.begin(), n[i]);
        res1.push_back(conj);
    }

    return res1;
};

vector<vector<int>> conjuntoDePartesN(vector<int> n, int k) {
    vector<vector<int>> cp = conjuntoDePartes(0, n, n.size());

    vector<vector<int>> res = {};
    for (auto conj: cp) {
        if (conj.size() == k) {
            res.push_back(conj);
        }
    }

    return res;
}

choripanesRes choripanes(ubicaciones puestos, int cantProveedurias) {
    vector<vector<int>> proveedurias = conjuntoDePartesN(puestos, cantProveedurias);
    ubicaciones resProveedurias = proveedurias[0];
    int resCoste = coste(puestos, proveedurias[0]);

    for (int i = proveedurias.size() - 1; i < proveedurias.size(); i--) {
        vector<int> distProveeduria = proveedurias[i];

        int costePuesto = coste(puestos, distProveeduria);
        if (costePuesto < resCoste) {
            resCoste = costePuesto;
            resProveedurias = distProveeduria;
        }
    }

    return {
            .coste = resCoste,
            .proveedurias = resProveedurias
    };
};

