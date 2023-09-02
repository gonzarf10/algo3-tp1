#include "gtest-1.8.1/gtest.h"
#include "../tablero.h"

using namespace std;

TEST(tests_tuki, 1) {
    tablero t = {
            {"I", "L", "L", "+", "L"},
            {"L", "L", "L", "I", "L"},
    };

    senderoRes res = sendero(t);
    ASSERT_TRUE(res.existeCamino);
    ASSERT_EQ(res.max, 7);
    ASSERT_EQ(res.min, 7);
}

TEST(tests_tuki, 2) {
    tablero t = {
            {"I", "L", "L", "L", "L"},
            {"L", "L", "L", "L", "L"},
    };

    senderoRes res = sendero(t);
    ASSERT_TRUE(res.existeCamino);
    ASSERT_EQ(res.max, 9);
    ASSERT_EQ(res.min, 7);
}

TEST(tests_tuki, 3) {
    tablero t = {
            {"I", "L", "I"},
            {"#", "I", "L"},
            {"+", "L", "+"},
    };

    senderoRes res = sendero(t);
    ASSERT_TRUE(res.existeCamino);
    ASSERT_EQ(res.max, 4);
    ASSERT_EQ(res.min, 4);
}

TEST(tests_tuki, 4) {
    tablero t = {
            {"+", "#"},
            {"#", "l"}
    };

    senderoRes res = sendero(t);
    ASSERT_FALSE(res.existeCamino);
    ASSERT_EQ(res.max, 0);
    ASSERT_EQ(res.min, 0);
}

TEST(tests_tuki, 5) {
    tablero t = {
            {"L", "I", "+", "L"},
            {"+", "+", "I", "L"},
            {"I", "#", "+", "#"},
            {"L", "I", "+", "+"},
    };

    senderoRes res = sendero(t);
    ASSERT_TRUE(res.existeCamino);
    ASSERT_EQ(res.max, 12);
    ASSERT_EQ(res.min, 6);
}

TEST(tests_tuki, 6) {
    tablero t = {
            {"+", "I", "+", "L"},
            {"+", "+", "I", "L"},
            {"I", "#", "+", "#"},
            {"L", "I", "+", "+"},
    };

    senderoRes res = sendero(t);
    ASSERT_TRUE(res.existeCamino);
    ASSERT_EQ(res.max, 12);
    ASSERT_EQ(res.min, 6);
}

TEST(tests_tuki, 7) {
    tablero t = {
            {"+", "I", "+", "L"},
            {"+", "+", "I", "L"},
            {"I", "#", "+", "#"},
            {"L", "I", "+", "#"},
    };

    senderoRes res = sendero(t);
    ASSERT_FALSE(res.existeCamino);
    ASSERT_EQ(res.max, 0);
    ASSERT_EQ(res.min, 0);
}

TEST(tests_tuki, 8) {
    tablero t = {
            {"+", "I", "I", "I", "#"},
            {"L", "L", "I", "I", "I"},
            {"I", "L", "L", "I", "I"},
            {"L", "I", "L", "L", "I"},
            {"L", "I", "+", "L", "+"},
    };

    senderoRes res = sendero(t);
    ASSERT_TRUE(res.existeCamino);
    ASSERT_EQ(res.max, 8);
    ASSERT_EQ(res.min, 8);
}

TEST(tests_tuki, 9) {
    tablero t = {
            {"+", "I", "L", "L", "#"},
            {"L", "L", "I", "I", "I"},
            {"I", "L", "L", "L", "L"},
            {"L", "I", "L", "L", "I"},
            {"L", "I", "+", "L", "+"},
    };

    senderoRes res = sendero(t);
    ASSERT_TRUE(res.existeCamino);
    ASSERT_EQ(res.max, 12);
    ASSERT_EQ(res.min, 8);
}

TEST(tests_tuki, 10) {
    tablero t = {
            {"+", "+", "+", "+", "+"},
            {"+", "+", "+", "+", "+"},
            {"+", "+", "+", "+", "+"},
            {"+", "+", "+", "+", "+"},
            {"+", "+", "+", "+", "+"},
    };

    senderoRes res = sendero(t);
    ASSERT_TRUE(res.existeCamino);
    ASSERT_EQ(res.max, 24);
    ASSERT_EQ(res.min, 8);
}

TEST(tests_tuki, 11) {
    tablero t = {
            {"+", "L", "L", "L", "L", "L"},
            {"+", "L", "+", "L", "I", "L"},
            {"I", "L", "I", "L", "I", "L"},
            {"I", "I", "I", "L", "I", "I"},
            {"I", "I", "I", "L", "I", "+"},
            {"L", "I", "+", "+", "+", "+"},
    };

    senderoRes res = sendero(t);
    ASSERT_TRUE(res.existeCamino);
    ASSERT_EQ(res.max, 14);
    ASSERT_EQ(res.min, 10);
}

TEST(tests_tuki, 12) {
    tablero t = {
            {"+", "L", "L", "L", "L", "L"},
            {"+", "L", "+", "L", "I", "L"},
            {"I", "L", "I", "L", "I", "L"},
            {"I", "I", "I", "L", "I", "I"},
            {"I", "I", "I", "L", "I", "+"},
            {"L", "I", "+", "+", "L", "+"},
    };

    senderoRes res = sendero(t);
    ASSERT_TRUE(res.existeCamino);
    ASSERT_EQ(res.max, 14);
    ASSERT_EQ(res.min, 10);
}

TEST(tests_tuki, finalBloqueado) {
    tablero t = {
            {"+", "+"},
            {"+", "#"}
    };

    senderoRes res = sendero(t);
    ASSERT_FALSE(res.existeCamino);
    ASSERT_EQ(res.max, 0);
    ASSERT_EQ(res.min, 0);
}

TEST(tests_tuki, inicioBloqueado) {
    tablero t = {
            {"#", "+"},
            {"+", "+"}
    };

    senderoRes res = sendero(t);
    ASSERT_FALSE(res.existeCamino);
    ASSERT_EQ(res.max, 0);
    ASSERT_EQ(res.min, 0);
}