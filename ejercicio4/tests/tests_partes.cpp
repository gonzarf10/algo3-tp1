//
// Created by gonza on 7/9/2023.
//
#include "gtest-1.8.1/gtest.h"
#include "../choripanes.h"

using namespace std;

/*
 * PARTES DE {1, 5, 15, 20}
 * {
            {},
            {1},
            {5},
            {15},
            {20},
            {1, 5},
            {1, 15},
            {1, 20},
            {5, 15},
            {5, 20},
            {15, 20},
            {1, 5, 15},
            {1, 5, 20},
            {1, 15, 20},
            {5, 15, 20},
            {1, 5, 15, 20}
    }
 * */

TEST(tests_partes, conjuntoDePartesN) {
    vector<int> conjunto = {1, 2};
    int k = 2;
    vector<vector<int>> res = conjuntoDePartesN(conjunto, k);

    vector<vector<int>> resExpected = {
            {1, 2}
    };

    ASSERT_EQ(res, resExpected);
}

TEST(tests_partes, conjuntoDePartes1) {
    vector<int> conjunto = {1, 2};
    int k = 1;
    vector<vector<int>> res = conjuntoDePartesN(conjunto, k);

    vector<vector<int>> resExpected = {
            {1},
            {2},
    };

    ASSERT_EQ(res, resExpected);
}

TEST(tests_partes, conjuntoDePartes2) {
    vector<int> conjunto = {1, 5, 15, 20};
    int k = 2;
    vector<vector<int>> res = conjuntoDePartesN(conjunto, k);

    vector<vector<int>> resExpected = {
            {1,  5},
            {1,  15},
            {5,  15},
            {1,  20},
            {5,  20},
            {15, 20},
    };

    ASSERT_EQ(res, resExpected);
}

TEST(tests_partes, conjuntoDePartes3) {
    vector<int> conjunto = {1, 5, 15, 20};
    int k = 3;
    vector<vector<int>> res = conjuntoDePartesN(conjunto, k);

    vector<vector<int>> resExpected = {
            {1, 5,  15},
            {1, 5,  20},
            {1, 15, 20},
            {5, 15, 20},
    };

    ASSERT_EQ(res, resExpected);
}

TEST(tests_partes, conjuntoDePartes4) {
    vector<int> conjunto = {1, 5, 15, 20};
    int k = 4;
    vector<vector<int>> res = conjuntoDePartesN(conjunto, k);

    vector<vector<int>> resExpected = {
            {1, 5, 15, 20}
    };

    ASSERT_EQ(res, resExpected);
}

TEST(tests_partes, conjuntoDePartes5) {
    vector<int> conjunto = {1, 5, 15, 20, 26, 27, 28, 29, 30, 31, 32, 33};
    int k = 2;
    vector<vector<int>> res = conjuntoDePartesN(conjunto, k);

    vector<vector<int>> resExpected = {
            {1, 5, 15, 20}
    };

    ASSERT_EQ(res, resExpected);
}
