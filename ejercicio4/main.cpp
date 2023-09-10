#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

using ubicacion = int;
using ubicaciones = vector<int>;
struct choripanesRes {
    int coste;
    ubicaciones proveedurias;
};
using memo = vector<vector<vector<choripanesRes>>>;

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

void init() {
    int tests;
    cin >> tests;

    for (int i = 0; i < tests; ++i) {
        int n, k;

        cin >> n >> k;
        ubicaciones p = {};

        while (p.size() < n) {
            int temp;
            cin >> temp;
            p.push_back(temp);
        };

        choripanesRes res = choripanesDP(p, k);
        cout << res.coste << endl;
        for (int i = 0; i < res.proveedurias.size(); i++) {
            int proveduria = res.proveedurias[i];
            cout << proveduria;
            if (i != res.proveedurias.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    init();
    return 0;
}

