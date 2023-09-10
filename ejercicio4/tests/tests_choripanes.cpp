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

TEST(tests_choripanes, choripanes3) {
    ubicaciones puestos = {4, 5, 6, 7};
    int cantProveedurias = 4;
    choripanesRes res = choripanes(puestos, cantProveedurias);
    ubicaciones proveeduriasExpected = {4, 5, 6, 7};


    ASSERT_EQ(res.coste, 0);
    ASSERT_EQ(res.proveedurias, proveeduriasExpected);

}

TEST(tests_choripanes, choripanes4) {
    ubicaciones puestos = {4, 5, 6, 7};
    int cantProveedurias = 3;
    choripanesRes res = choripanes(puestos, cantProveedurias);
    ubicaciones proveeduriasExpected = {4, 5, 6};


    ASSERT_EQ(res.coste, 1);
    ASSERT_EQ(res.proveedurias, proveeduriasExpected);

}

TEST(tests_choripanes, choripanes5) {
    ubicaciones puestos;
    puestos = {1, 5, 15, 20};
    int k = 1;
    choripanesRes expected = {.coste = 29, .proveedurias = {5}};

    choripanesRes res = choripanesV2(puestos, k, 0, puestos.size() - 1);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);

}

TEST(tests_choripanes, choripanes6) {
    ubicaciones puestos;
    puestos = {1, 5, 15};
    int k = 1;
    choripanesRes expected = {.coste = 14, .proveedurias = {5}};

    choripanesRes res = choripanesV2(puestos, k, 0, puestos.size() - 1);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);

}

TEST(tests_choripanes, choripanes8) {
    ubicaciones puestos;
    puestos = {1, 5, 15, 20};
    int k = 1;
    choripanesRes expected = {.coste = 0, .proveedurias = {}};

    choripanesRes res = choripanesV2(puestos, k, puestos.size(), puestos.size() - 1);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);

}

/*TEST(tests_choripanes, choripanes7) {
    ubicaciones puestos;
    puestos = {1, 5, 15, 20};
    int k = 2;
    choripanesRes expected = {.coste = 9, .proveedurias = {1, 15}};

    choripanesRes res = choripanesV2(puestos, k, 0, puestos.size() - 1);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);

}*/