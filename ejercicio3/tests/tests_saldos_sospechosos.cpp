//
// Created by gonza on 11/9/2023.
//

#include "gtest-1.8.1/gtest.h"
#include "../saldos_sospechosos.h"

TEST(tests_saldos_sospechosos, 0) {
    std::string res = saldos_sospechosos(1, 500, {500});
    std::string resExpected = "+";

    ASSERT_EQ(res, resExpected);
}

TEST(tests_saldos_sospechosos, 1) {
    std::string res = saldos_sospechosos(2, -200, {500, 700});
    std::string resExpected = "+-";

    ASSERT_EQ(res, resExpected);
}

TEST(tests_saldos_sospechosos, 2) {
    std::string res = saldos_sospechosos(4, 400, {500, 700, 700, 100});
    std::string resExpected = "+??-";

    ASSERT_EQ(res, resExpected);
}

TEST(tests_saldos_sospechosos, 3) {
    std::vector<int> book = {500, 700, 700, 100, 100};
    std::string res = saldos_sospechosos(book.size(), 500, book);
    std::string resExpected = "+????";

    ASSERT_EQ(res, resExpected);
}

TEST(tests_saldos_sospechosos, 4) {
    std::vector<int> book = {500, 700, 700, 100, 100};
    std::string res = saldos_sospechosos(book.size(), 300, book);
    std::string resExpected = "+??--";

    ASSERT_EQ(res, resExpected);
}

TEST(tests_saldos_sospechosos, 5) {
    std::vector<int> book = {500, 700, 200};
    std::string res = saldos_sospechosos(book.size(), 1000, book);
    std::string resExpected = "++-";

    ASSERT_EQ(res, resExpected);
}

TEST(tests_saldos_sospechosos, 6) {
    std::vector<int> book = {500, 800, 200};
    std::string res = saldos_sospechosos(book.size(), -100, book);
    std::string resExpected = "+-+";

    ASSERT_EQ(res, resExpected);
}

TEST(tests_saldos_sospechosos, 7) {
    std::vector<int> book = {500, 800, 200};
    std::string res = saldos_sospechosos(book.size(), 100, book);
    std::string resExpected = "-+-";

    ASSERT_EQ(res, resExpected);
}

TEST(tests_saldos_sospechosos, maxValores1) {
    std::vector<int> book = {50000, 50000};
    std::string res = saldos_sospechosos(book.size(), 100000, book);
    std::string resExpected = "++";

    ASSERT_EQ(res, resExpected);
}

TEST(tests_saldos_sospechosos, maxValores2) {
    std::vector<int> book = {50000, 50000};
    std::string res = saldos_sospechosos(book.size(), 0, book);
    std::string resExpected = "??";

    ASSERT_EQ(res, resExpected);
}

TEST(tests_saldos_sospechosos, maxValores3) {
    std::vector<int> book = {50000, 50000};
    std::string res = saldos_sospechosos(book.size(), -1000000, book);
    std::string resExpected = "--";

    ASSERT_EQ(res, resExpected);
}

TEST(tests_saldos_sospechosos, 8) {
    std::vector<int> book = {9400, 9300};
    std::string res = saldos_sospechosos(book.size(), 100, book);
    std::string resExpected = "+-";

    ASSERT_EQ(res, resExpected);
}

TEST(tests_saldos_sospechosos, 9) {
    std::vector<int> book = {9900, 9300};
    std::string res = saldos_sospechosos(book.size(), 600, book);
    std::string resExpected = "+-";

    ASSERT_EQ(res, resExpected);
}

TEST(tests_saldos_sospechosos, 10) {
    std::vector<int> book = {9900, 9300};
    std::string res = saldos_sospechosos(book.size(), -600, book);
    std::string resExpected = "-+";

    ASSERT_EQ(res, resExpected);
}

TEST(tests_saldos_sospechosos, 11) {
    std::vector<int> book = {93500, 93200};
    std::string res = saldos_sospechosos(book.size(), 300, book);
    std::string resExpected = "+-";

    ASSERT_EQ(res, resExpected);
}