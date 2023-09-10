//
// Created by gonza on 9/9/2023.
//
#include "gtest-1.8.1/gtest.h"
#include "../choripanes.h"

using namespace std;

TEST(tests_choripanesv2, R41) {
    ubicaciones puestos;
    puestos = {1, 5, 15, 20};
    int k = 1;
    choripanesRes expected = {.coste = 29, .proveedurias = {5}};

    choripanesRes res = choripanesV2(puestos, k, 0, puestos.size() - 1);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);

}

TEST(tests_choripanesv2, R_01) {
    ubicaciones puestos;
    puestos = {1, 5, 15, 20};
    int k = 1;
    choripanesRes expected = {.coste = 0, .proveedurias = {}};

    choripanesRes res = choripanesV2(puestos, k, 0, -1);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);

}

TEST(tests_choripanesv2, R31) {
    ubicaciones puestos;
    puestos = {1, 5, 15, 20};
    int k = 1;
    choripanesRes expected = {.coste = 14, .proveedurias = {5}};

    choripanesRes res = choripanesV2(puestos, k, 0, 2);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);

}

TEST(tests_choripanesv2, R_11) {
    ubicaciones puestos;
    puestos = {1, 5, 15, 20};
    int k = 1;
    choripanesRes expected = {.coste = 0, .proveedurias = {20}};

    choripanesRes res = choripanesV2(puestos, k, 3, 3);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);

}

TEST(tests_choripanesv2, R21) {
    ubicaciones puestos;
    puestos = {1, 5, 15, 20};
    int k = 1;
    choripanesRes expected = {.coste = 4, .proveedurias = {1}};

    choripanesRes res = choripanesV2(puestos, k, 0, 1);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);

}

TEST(tests_choripanesv2, R_21) {
    ubicaciones puestos;
    puestos = {1, 5, 15, 20};
    int k = 1;
    choripanesRes expected = {.coste = 5, .proveedurias = {15}};

    choripanesRes res = choripanesV2(puestos, k, 2, 3);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);

}

TEST(tests_choripanesv2, R11) {
    ubicaciones puestos;
    puestos = {1, 5, 15, 20};
    int k = 1;
    choripanesRes expected = {.coste = 0, .proveedurias = {1}};

    choripanesRes res = choripanesV2(puestos, k, 0, 0);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);

}

TEST(tests_choripanesv2, R_31) {
    ubicaciones puestos;
    puestos = {1, 5, 15, 20};
    int k = 1;
    choripanesRes expected = {.coste = 15, .proveedurias = {15}};

    choripanesRes res = choripanesV2(puestos, k, 1, 3);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);

}

TEST(tests_choripanesv2, R01) {
    ubicaciones puestos;
    puestos = {1, 5, 15, 20};
    int k = 1;
    choripanesRes expected = {.coste = 0, .proveedurias = {}};

    choripanesRes res = choripanesV2(puestos, k, 0, -1);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);
}

TEST(tests_choripanesv2, R_41) {
    ubicaciones puestos;
    puestos = {1, 5, 15, 20};
    int k = 1;
    choripanesRes expected = {.coste = 29, .proveedurias = {5}};

    choripanesRes res = choripanesV2(puestos, k, 0, 3);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);
}

TEST(tests_choripanesv2, R42) {
    ubicaciones puestos;
    puestos = {1, 5, 15, 20};
    int k = 2;
    choripanesRes expected = {.coste = 9, .proveedurias = {1, 15}};

    choripanesRes res = choripanesV2(puestos, k, 0, puestos.size() - 1);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);
}

// puestos2 = { 4, 5, 6, 7 }
ubicaciones puestos2 = {4, 5, 6, 7};

TEST(tests_choripanesv2, puestos_2_R42) {
    int k = 2;
    choripanesRes expected = {.coste = 2, .proveedurias = {4, 6}};

    choripanesRes res = choripanesV2(puestos2, k, 0, puestos2.size() - 1);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);
}

TEST(tests_choripanesv2, puestos_2_R32) {
    int k = 2;
    choripanesRes expected = {.coste = 1, .proveedurias = {4, 5}};

    choripanesRes res = choripanesV2(puestos2, k, 0, puestos2.size() - 2);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);
}

TEST(tests_choripanesv2, puestos_2_R43) {
    int k = 3;
    choripanesRes expected = {.coste = 1, .proveedurias = {4, 5, 6}};

    choripanesRes res = choripanesV2(puestos2, k, 0, puestos2.size() - 1);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);
}

TEST(tests_choripanesv2, hard) {
    // 5 segundos
    //ubicaciones puestos = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
    //                      26, 27, 28, 29, 30};
    ubicaciones puestos = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
                           26, 28, 29, 30};
    int k = 7;
    choripanesRes expected = {.coste = 1, .proveedurias = {4, 5, 6}};

    choripanesRes res = choripanesV2(puestos, k, 0, puestos.size() - 1);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);
}

TEST(tests_choripanesv2, R63) {
    ubicaciones puestos2 = {4, 5, 6, 7, 8, 9};
    int k = 3;
    choripanesRes expected = {.coste = 3, .proveedurias = {4, 5, 8}};

    choripanesRes res = choripanesV2(puestos2, k, 0, puestos2.size() - 1);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);
}
