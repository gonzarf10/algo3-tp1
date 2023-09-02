//
// Created by gonza on 1/9/2023.
//
#include "tablero.h"

bool estoyEnSalida(posicion actual, tablero t) {
    return (actual.first + 1 == t[0].size() and actual.second + 1 == t.size());
}

bool estoyFueraDeTablero(posicion actual, tablero t) {
    return (t.empty()) or (t[0].empty()) or actual.first < 0 or actual.first >= t[0].size() or actual.second < 0 or
           actual.second >= t.size();
}

int obtenerDireccionDeLaQueVengo(posicion anterior, posicion actual) {
    int xOffset = actual.first - anterior.first;
    int yOffset = actual.second - anterior.second;

    if (yOffset == 0 and xOffset == 1) {
        // Fui sentido derecho, entonces vengo de la izquierda
        return IZQUIERDA;
    } else if (yOffset == 1 and xOffset == 0) {
        // Fui sentido arriba, entonces vengo de abajo
        return ABAJO;
    } else if (yOffset == 0 and xOffset == -1) {
        // Fui sentido izquierda, entonces vengo de derecha
        return DERECHA;
    } else
        // Fui sentido abajo, entonces vengo de arriba
        return ARRIBA;
}

senderoRes senderoBT(posicion anterior, posicion actual, tablero t, vector<posicion> posicionesRecorridas) {
    if (posicionesRecorridas.size() == 20) {
        //cout << "debug" << endl;
    }

    if (find(posicionesRecorridas.begin(), posicionesRecorridas.end(), actual) != posicionesRecorridas.end()) {
        return {.min =  0, .max =  0, .existeCamino =  false};

    } else if (estoyFueraDeTablero(actual, t)) {
        return {.min= 0, .max= 0, .existeCamino= false};
    }

    string simbolo = t[actual.second][actual.first];

    if (estoyEnSalida(actual, t) and simbolo != "#") {
        return {.min= 0, .max= 0, .existeCamino= true, .caminoRecorrido= posicionesRecorridas};
    }

    posicionesRecorridas.push_back(actual);

    int direccionDeLaQueVengo = obtenerDireccionDeLaQueVengo(anterior, actual);
    vector<senderoRes> caminos;
    vector<posicion> posicionesARecorrer = {};

    if (simbolo == "L") {
        if (direccionDeLaQueVengo == DERECHA or direccionDeLaQueVengo == IZQUIERDA) {
            posicionesARecorrer.emplace_back(actual.first, actual.second - 1);
            posicionesARecorrer.emplace_back(actual.first, actual.second + 1);

        } else {
            posicionesARecorrer.emplace_back(actual.first - 1, actual.second);
            posicionesARecorrer.emplace_back(actual.first + 1, actual.second);
        }

    } else if (simbolo == "I") {
        if (direccionDeLaQueVengo == DERECHA) {
            posicionesARecorrer.emplace_back(actual.first - 1, actual.second);
        } else if (direccionDeLaQueVengo == IZQUIERDA) {
            posicionesARecorrer.emplace_back(actual.first + 1, actual.second);

        } else if (direccionDeLaQueVengo == ARRIBA) {
            posicionesARecorrer.emplace_back(actual.first, actual.second - 1);
        } else {
            posicionesARecorrer.emplace_back(actual.first, actual.second + 1);
        }

    } else if (simbolo == "#") {
        return {.min =  0, .max =  0, .existeCamino =  false};


    } else {
        if (direccionDeLaQueVengo == DERECHA or direccionDeLaQueVengo == IZQUIERDA) {
            posicionesARecorrer.emplace_back(actual.first, actual.second + 1);
            posicionesARecorrer.emplace_back(actual.first, actual.second - 1);

            if (direccionDeLaQueVengo == DERECHA) {
                posicionesARecorrer.emplace_back(actual.first - 1, actual.second);
            } else {
                posicionesARecorrer.emplace_back(actual.first + 1, actual.second);
            }

        } else {
            posicionesARecorrer.emplace_back(actual.first + 1, actual.second);
            posicionesARecorrer.emplace_back(actual.first - 1, actual.second);

            if (direccionDeLaQueVengo == ARRIBA) {
                posicionesARecorrer.emplace_back(actual.first, actual.second - 1);
            } else {
                posicionesARecorrer.emplace_back(actual.first, actual.second + 1);
            }
        }
    }

    for (posicion posicionARecorrer: posicionesARecorrer) {
        senderoRes camino = senderoBT(actual, posicionARecorrer, t, posicionesRecorridas);

        if (camino.existeCamino) {
            caminos.push_back(camino);
        }
    }

    int minimo = -1;
    int maximo = -1;

    if (posicionesRecorridas[0].first == 0 and posicionesRecorridas[0].second == 0 and simbolo == "+" and
        anterior.first == -1 and anterior.second == 0 and actual.first == 0 and actual.second == 0
            ) {
        //cout << "debug" << endl;
    }

    bool existeCamino = !caminos.empty();

    for (auto camino: caminos) {
        if (minimo == -1) {
            minimo = camino.min;
        } else {
            minimo = min(minimo, camino.min);
        }

        if (maximo == -1) {
            maximo = camino.max;
        } else {
            maximo = max(maximo, camino.max);
        };
    }

   /* if (existeCamino) {
        //cout << "debug" << endl;
        cout << "[";
        for (auto pos:posicionesRecorridas) {
            cout << "("<<pos.first<<","<<pos.second<<") ";
        }
        cout << "]"<<endl;
    }*/

    if (maximo == 23) {
        //cout << "debug 23" << endl;
    }

    return {.min =  minimo + 1, .max =  maximo + 1, .existeCamino =  existeCamino, .caminoRecorrido = posicionesRecorridas};
}

senderoRes sendero(const tablero &t) {
    senderoRes sen1 = senderoBT(make_pair(-1, 0), make_pair(0, 0), t, {});
    senderoRes sen2 = senderoBT(make_pair(0, -1), make_pair(0, 0), t, {});

    if (!sen1.existeCamino && sen2.existeCamino) {
        return sen2;
    } else if (sen1.existeCamino && !sen2.existeCamino) {
        return sen1;
    } else if (sen1.existeCamino && sen2.existeCamino) {
        int minimo = min(sen1.min, min(sen2.min, min(sen1.max, sen2.max)));
        int maximo = max(sen1.min, max(sen2.min, max(sen1.max, sen2.max)));

        return {.min =  minimo, .max =  maximo, .existeCamino =  true};
    }

    return sen1;
}

void mostrarTablero(tablero t) {
    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < t[0].size(); ++j) {
            cout << t[i][j];
        }

        cout << endl;
    }
}

tablero pedirTablero() {
    posicion dimension;

    cin >> dimension.first >> dimension.second;

    tablero t = {};
    for (int j = 0; j < dimension.second; ++j) {
        vector<string> fila = {};
        string simbolo;
        if (dimension.first > 0) {
            cin >> simbolo;
        }

        for (int k = 0; k < dimension.first; ++k) {
            string sim(1, simbolo[k]);
            fila.push_back(sim);
        }

        t.push_back(fila);
    }

    return t;
}

vector<tablero> pedirTableros() {
    int cantidadTableros;
    cin >> cantidadTableros;

    vector<tablero> tableros = {};
    tableros.reserve(cantidadTableros);

    for (int i = 0; i < cantidadTableros; ++i) {
        tableros.push_back(pedirTablero());
    }

    return tableros;
}

void analizarTablero(const tablero &t) {
    senderoRes solucion = sendero(t);

    if (solucion.existeCamino) {
        cout << "POSIBLE " << solucion.min << " " << solucion.max << endl;
    } else {
        cout << "IMPOSIBLE" << endl;
    }
}


void pedirTablerosYAnalizar() {
    vector<tablero> tableros = pedirTableros();


    for (const tablero &t: tableros) {
        analizarTablero(t);
    }
}

void ejemploEnunciado() {
    vector<tablero> tableros = {
            {
                    {"I", "L", "I"},
                    {"#", "I", "L"},
                    {"+", "L", "+"}
            },
            {
                    {"+", "#"},
                    {"#", "L"}
            },
            {
                    {"L", "I", "+", "L"},
                    {"+", "+", "I", "L"},
                    {"I", "#", "+", "#"},
                    {"L", "I", "+", "+"}
            }
    };
    int cantidadTableros = tableros.size();


    for (int i = 0; i < cantidadTableros; ++i) {
        senderoRes solucion = sendero(tableros[i]);

        if (solucion.existeCamino) {
            cout << "POSIBLE " << solucion.min << " " << solucion.max << endl;
        } else {
            cout << "IMPOSIBLE" << endl;
        }

    }

}

void pedirInfinitosTableros() {
    while (true) {
        tablero t = pedirTablero();

        senderoRes solucion = sendero(t);

        if (solucion.existeCamino) {
            cout << "POSIBLE " << solucion.min << " " << solucion.max << endl;
        } else {
            cout << "IMPOSIBLE" << endl;
        }
    }
}