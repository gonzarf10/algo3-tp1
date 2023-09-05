#include "gtest-1.8.1/gtest.h"
#include "../choripanes.h"

using namespace std;

TEST(tests_choripanes, proveeduriaMasCercana) {
    ubicacion res = proveeduriaMasCercana(3, {1, 2, 3});

    ASSERT_EQ(res, 3);
}

TEST(tests_choripanes, proveeduriaMasCercana2) {
    ubicacion res = proveeduriaMasCercana(2, {1, 2, 3});

    ASSERT_EQ(res, 2);
}

TEST(tests_choripanes, proveeduriaMasCercana3) {
    ubicacion res = proveeduriaMasCercana(4, {1, 2, 3, 5});

    ASSERT_EQ(res, 3);
}

TEST(tests_choripanes, proveeduriaMasCercana4) {
    ubicacion res = proveeduriaMasCercana(25, {1, 49});

    ASSERT_EQ(res, 1);
}

TEST(tests_choripanes, proveeduriaMasCercana5) {
    ubicacion res = proveeduriaMasCercana(26, {1, 49});

    ASSERT_EQ(res, 49);
}

TEST(tests_choripanes, coste) {
    ubicaciones proveedurias = {1, 15};
    ubicaciones puestos = {1, 5, 15, 20};
    int res = coste(puestos, proveedurias);

    ASSERT_EQ(res, 9);
}

TEST(tests_choripanes, coste1) {
    ubicaciones proveedurias = {6};
    ubicaciones puestos = {4, 5, 6, 7, 8};
    int res = coste(puestos, proveedurias);

    ASSERT_EQ(res, 6);
}

TEST(tests_choripanes, coste2) {
    ubicaciones proveedurias = {5};
    ubicaciones puestos = {4, 5, 6, 7};
    int res = coste(puestos, proveedurias);

    ASSERT_EQ(res, 4);
}

TEST(tests_choripanes, conjuntoDePartesN) {
    vector<int> conjunto = {1, 2};
    int k = 2;
    vector<vector<int>> res = conjuntoDePartesN(conjunto, k);

    vector<vector<int>> resExpected = {
            {1, 2}
    };

    ASSERT_EQ(res, resExpected);
}

TEST(tests_choripanes, conjuntoDePartes1) {
    vector<int> conjunto = {1, 2};
    int k = 1;
    vector<vector<int>> res = conjuntoDePartesN(conjunto, k);

    vector<vector<int>> resExpected = {
            {2},
            {1},
    };

    ASSERT_EQ(res, resExpected);
}

TEST(tests_choripanes, conjuntoDePartes2) {
    vector<int> conjunto = {1, 5, 15, 20};
    int k = 2;
    vector<vector<int>> res = conjuntoDePartesN(conjunto, k);

    vector<vector<int>> resExpected = {
            {15, 20},
            {5,  20},
            {5,  15},
            {1,  20},
            {1,  15},
            {1,  5},
    };

    ASSERT_EQ(res, resExpected);
}

TEST(tests_choripanes, choripanes) {
    ubicaciones puestos = {1, 5, 15, 20};
    int cantProveedurias = 2;
    choripanesRes res = choripanes(puestos, cantProveedurias);
    ubicaciones proveeduriasExpected = {1, 15};


    ASSERT_EQ(res.coste, 9);
    ASSERT_EQ(res.proveedurias, proveeduriasExpected);

}

TEST(tests_choripanes, choripanes1) {
    ubicaciones puestos = {4, 5, 6, 7, 8};
    int cantProveedurias = 1;
    choripanesRes res = choripanes(puestos, cantProveedurias);
    ubicaciones proveeduriasExpected = {6};


    ASSERT_EQ(res.coste, 6);
    ASSERT_EQ(res.proveedurias, proveeduriasExpected);

}

TEST(tests_choripanes, choripanes2) {
    ubicaciones puestos = {4, 5, 6, 7};
    int cantProveedurias = 1;
    choripanesRes res = choripanes(puestos, cantProveedurias);
    ubicaciones proveeduriasExpected = {5};


    ASSERT_EQ(res.coste, 4);
    ASSERT_EQ(res.proveedurias, proveeduriasExpected);

}