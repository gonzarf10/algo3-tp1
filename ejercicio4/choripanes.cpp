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
        //conj.insert(conj.begin(), n[i]);
        conj.push_back(n[n.size() - i - 1]);
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

choripanesRes choripanesV2(ubicaciones &puestos, int k, int begin, int end) {
    if (end < begin) {
        return {.coste = 0, .proveedurias = {}};
    } else if (k >= end - begin + 1) {
        ubicaciones proveedurias;
        for (int i = begin; i <= end; ++i) {
            proveedurias.push_back(puestos[i]);
        }

        return {.coste = 0, .proveedurias = proveedurias};
    } else if (k == 1) {
        int mid = ((end - begin + 1) / 2) - ((end - begin + 1) % 2 == 0 ? 1 : 0);
        ubicaciones nuevosPuestos = {};
        ubicaciones proveedurias = {puestos[begin + mid]};

        for (int i = begin; i <= end; ++i) {
            nuevosPuestos.push_back(puestos[i]);
        }

        return {.coste = coste(nuevosPuestos, proveedurias), .proveedurias = proveedurias};
    }

    int min = numeric_limits<int>::max();
    ubicaciones minUbi;

    for (int m = 0; m <= end - begin; ++m) {
        choripanesRes r1, r2;
        r1 = choripanesV2(puestos, k - 1, begin, end - m);
        r2 = choripanesV2(puestos, 1, end - m + 1, end);

        int posibleMinCoste = r1.coste + r2.coste;
        bool esMenorLexicograficamente = false;

        if (posibleMinCoste == min) {
            esMenorLexicograficamente = true;
            for (int i = 0; i < minUbi.size(); ++i) {
                if (i == minUbi.size() - 1) {
                    esMenorLexicograficamente = esMenorLexicograficamente && r2.proveedurias[0] <= minUbi[i];
                } else {
                    esMenorLexicograficamente = esMenorLexicograficamente && r1.proveedurias[i] <= minUbi[i];
                }
            }

        } else if (posibleMinCoste < min) {
            esMenorLexicograficamente = true;
        }

        if (esMenorLexicograficamente) {
            minUbi.clear();
            min = r1.coste + r2.coste;
            minUbi.reserve(r1.proveedurias.size() + r2.proveedurias.size());
            minUbi.insert(minUbi.end(), r1.proveedurias.begin(), r1.proveedurias.end());
            minUbi.insert(minUbi.end(), r2.proveedurias.begin(), r2.proveedurias.end());
        }
    }

    return {.coste = min, .proveedurias = minUbi};
}

choripanesRes choripanesV3(ubicaciones &puestos, int k, int begin, int end, memo &memory) {

    if (memory[begin][end][k].coste != -1) {
        //cout << "HIT --> R(" << end - begin + 1 << ", " << k << ")" << endl;

        return memory[begin][end][k];
    } else {
        //cout << "MISS --> R(" << end - begin + 1 << ", " << k << ")" << endl;
    }


    if (end < begin) {
        choripanesRes res = {.coste = 0, .proveedurias = {}};
        memory[begin][end][k] = res;

        return res;
    } else if (k >= end - begin + 1) {
        ubicaciones proveedurias;
        for (int i = begin; i <= end; ++i) {
            proveedurias.push_back(puestos[i]);
        }

        choripanesRes res = {.coste = 0, .proveedurias = proveedurias};
        memory[begin][end][k] = res;

        return res;
    } else if (k == 1) {
        int mid = ((end - begin + 1) / 2) - ((end - begin + 1) % 2 == 0 ? 1 : 0);
        ubicaciones nuevosPuestos = {};
        ubicaciones proveedurias = {puestos[begin + mid]};

        for (int i = begin; i <= end; ++i) {
            nuevosPuestos.push_back(puestos[i]);
        }
        choripanesRes res = {.coste = coste(nuevosPuestos, proveedurias), .proveedurias = proveedurias};

        memory[begin][end][k] = res;

        return res;
    }

    int min = numeric_limits<int>::max();
    ubicaciones minUbi;

    for (int m = 0; m <= end - begin; ++m) {
        choripanesRes r1, r2;
        r1 = choripanesV3(puestos, k - 1, begin, end - m, memory);
        r2 = choripanesV3(puestos, 1, end - m + 1, end, memory);

        int posibleMinCoste = r1.coste + r2.coste;
        bool esMenorLexicograficamente = false;

        if (posibleMinCoste == min) {
            esMenorLexicograficamente = true;
            for (int i = 0; i < minUbi.size(); ++i) {
                if (i == minUbi.size() - 1) {
                    esMenorLexicograficamente = esMenorLexicograficamente && r2.proveedurias[0] <= minUbi[i];
                } else {
                    esMenorLexicograficamente = esMenorLexicograficamente && r1.proveedurias[i] <= minUbi[i];
                }
            }

        } else if (posibleMinCoste < min) {
            esMenorLexicograficamente = true;
        }

        if (esMenorLexicograficamente) {
            minUbi.clear();
            min = r1.coste + r2.coste;
            minUbi.reserve(r1.proveedurias.size() + r2.proveedurias.size());
            minUbi.insert(minUbi.end(), r1.proveedurias.begin(), r1.proveedurias.end());
            minUbi.insert(minUbi.end(), r2.proveedurias.begin(), r2.proveedurias.end());
        }
    }

    choripanesRes res = {.coste = min, .proveedurias = minUbi};
    memory[begin][end][k] = res;

    return res;
}

choripanesRes choripanes(ubicaciones puestos, int cantProveedurias) {
    choripanesRes res = choripanesV2(puestos, cantProveedurias, 0, puestos.size() - 1);

    return res;
};

choripanesRes choripanesDP(ubicaciones puestos, int cantProveedurias) {
    memo memory(puestos.size() + 1);
    choripanesRes def = {.coste = -1, .proveedurias = {}};
    vector<choripanesRes> defFila(cantProveedurias + 1, def);
    vector<vector<choripanesRes>> defC(puestos.size() + 1, defFila);

    for (int i = 0; i <= puestos.size(); ++i) {
        memory[i] = defC;
    }

    choripanesRes res = choripanesV3(puestos, cantProveedurias, 0, puestos.size() - 1, memory);

    return res;
}

