//
// Created by gonza on 10/9/2023.
//

#include "gtest-1.8.1/gtest.h"
#include "../choripanes.h"

using namespace std;

TEST(tests_choripanesv3, _R42) {
    ubicaciones puestos;
    puestos = {1, 5, 15, 20};
    int k = 2;
    choripanesRes expected = {.coste = 9, .proveedurias = {1, 15}};

    choripanesRes res = choripanesDP(puestos, k);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);
}

// puestos2 = { 4, 5, 6, 7 }
TEST(tests_choripanesv3, puestos_2_R43) {
    ubicaciones puestos2 = {4, 5, 6, 7};
    int k = 3;
    choripanesRes expected = {.coste = 1, .proveedurias = {4, 5, 6}};

    choripanesRes res = choripanesDP(puestos2, k);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);
}

TEST(tests_choripanesv3, test1) {
    ubicaciones puestos2 = {4, 5, 6, 7, 8};
    int k = 3;
    choripanesRes expected = {.coste = 2, .proveedurias = {4, 5, 7}};

    choripanesRes res = choripanesDP(puestos2, k);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);
}

TEST(tests_choripanesv3, R63) {
    ubicaciones puestos2 = {4, 5, 6, 7, 8, 9};
    int k = 3;
    choripanesRes expected = {.coste = 3, .proveedurias = {4, 5, 8}};

    choripanesRes res = choripanesDP(puestos2, k);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);
}

TEST(tests_choripanesv3, R62) {
    ubicaciones puestos2 = {4, 5, 6, 7, 8, 9};
    int k = 2;
    choripanesRes expected = {.coste = 4, .proveedurias = { 5, 8}};

    choripanesRes res = choripanesDP(puestos2, k);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);
}

TEST(tests_choripanesv3, R52) {
    ubicaciones puestos2 = {4, 5, 6, 7, 8};
    int k = 2;
    choripanesRes expected = {.coste = 3, .proveedurias = { 4, 7}};

    choripanesRes res = choripanesDP(puestos2, k);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);
}

TEST(tests_choripanesv3, R42) {
    ubicaciones puestos2 = {4, 5, 6, 7};
    int k = 2;
    choripanesRes expected = {.coste = 2, .proveedurias = { 4, 6}};

    choripanesRes res = choripanesDP(puestos2, k);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);
}

TEST(tests_choripanesv3, test13) {
    ubicaciones puestos2 = {4, 5, 6, 7};
    int k = 3;
    choripanesRes expected = {.coste = 1, .proveedurias = { 4, 5, 6}};

    choripanesRes res = choripanesDP(puestos2, k);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);
}

TEST(tests_choripanesv3, test14) {
    ubicaciones puestos2 = {4, 5, 6, 7, 8};
    int k = 3;
    choripanesRes expected = {.coste = 2, .proveedurias = { 4, 5, 7}};

    choripanesRes res = choripanesDP(puestos2, k);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);
}

TEST(tests_choripanesv3, test2) {
    ubicaciones puestos2 = {4, 5, 6, 7, 8, 9, 10, 11};
    int k = 3;
    choripanesRes expected = {.coste = 5, .proveedurias = {4, 7, 10}};

    choripanesRes res = choripanesDP(puestos2, k);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);
}

TEST(tests_choripanesv3, test3) {
    ubicaciones puestos2 = {4, 5, 6, 7, 8, 9, 10, 11};
    int k = 2;
    choripanesRes expected = {.coste = 8, .proveedurias = {5, 9}};

    choripanesRes res = choripanesDP(puestos2, k);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);
}

TEST(tests_choripanesv3, test4) {
    ubicaciones puestos2 = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int k = 2;
    choripanesRes expected = {.coste = 15, .proveedurias = {6, 11}};

    choripanesRes res = choripanesDP(puestos2, k);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);
}

TEST(tests_choripanesv3, test5) {
    ubicaciones puestos2 = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int k = 5;
    choripanesRes expected = {.coste = 6, .proveedurias = {4, 5, 7, 10, 13}};

    choripanesRes res = choripanesDP(puestos2, k);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);
}

TEST(tests_choripanesv3, hard) {
    // 5 segundos
    //ubicaciones puestos = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
    //                      26, 27, 28, 29, 30};
    ubicaciones puestos = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
                           26, 28, 29, 30};
    int k = 7;
    choripanesRes expected = {.coste = 30, .proveedurias = {2, 5, 9, 14, 19, 24, 29}};

    choripanesRes res = choripanesDP(puestos, k);

    ASSERT_EQ(res.coste, expected.coste);
    ASSERT_EQ(res.proveedurias, expected.proveedurias);
}