// Copyright 2023 Mokrousov Artem

#include <gtest/gtest.h>

#include "./mokrousov_a_crs_mult_matrix_seq.h"

TEST(OMP, Test_OMP_CRSmult_10x10) {
    Matrix A(std::vector<int>{85, 97, 81, 86, 86, 90, 91, 93, 84, 89, 86,
                              93, 98, 90, 94, 81, 88, 86, 96, 87, 85, 99},
             std::vector<int>{7, 7, 8, 9, 1, 5, 1, 4, 4, 6, 8,
                              2, 7, 2, 6, 2, 8, 2, 7, 4, 5, 5},
             std::vector<int>{0, 1, 1, 2, 2, 2, 4, 6, 8, 9, 11, 22});
    Matrix B(std::vector<int>{81, 97, 94, 94, 88, 88, 81},
             std::vector<int>{1, 1, 6, 8, 9, 2, 4},
             std::vector<int>{0, 1, 1, 1, 2, 3, 3, 4, 5, 5, 7});
    Matrix awaitRes(std::vector<int>{7480, 8536, 7568, 6966, 8742, 7896, 8366,
                                     8178, 8836, 17072},
                    std::vector<int>{9, 9, 2, 4, 6, 6, 8, 6, 8, 9},
                    std::vector<int>{0, 1, 1, 2, 2, 2, 4, 4, 5, 6, 7, 10});

    auto res = seq_crs_mult(A, B);
    EXPECT_TRUE(res == awaitRes);
}

TEST(OMP, Test_OMP_CRSmult_15x15) {
    Matrix A(
        std::vector<int>{
            89, 97, 86, 91, 86, 83, 93, 87, 97, 89, 90, 99, 96, 90,
            98, 92, 98, 97, 91, 89, 92, 85, 91, 94, 87, 82, 99, 81,
            93, 87, 98, 94, 91, 97, 90, 89, 96, 82, 94, 88,
        },
        std::vector<int>{
            4,  6, 0,  1,  0, 10, 11, 12, 5, 12, 13, 7,  7, 13,
            8,  3, 9,  10, 1, 5,  8,  14, 7, 9,  1,  5,  6, 12,
            11, 7, 10, 2,  8, 12, 7,  2,  0, 1,  12, 13,
        },
        std::vector<int>{
            0,
            2,
            4,
            5,
            8,
            11,
            12,
            14,
            15,
            16,
            18,
            19,
            22,
            24,
            24,
            25,
            40,
        });
    Matrix B(
        std::vector<int>{
            92,
            90,
            98,
            93,
            89,
            96,
            93,
            97,
            90,
            84,
            92,
            86,
            99,
            88,
            95,
            98,
        },
        std::vector<int>{
            3,
            3,
            6,
            8,
            9,
            0,
            4,
            5,
            9,
            0,
            11,
            3,
            3,
            5,
            9,
            13,
        },
        std::vector<int>{
            0,
            1,
            2,
            3,
            3,
            3,
            3,
            5,
            9,
            9,
            10,
            10,
            11,
            12,
            14,
            16,
        });
    Matrix awaitRes(
        std::vector<int>{
            9021,  8633,  16102, 7912,  7482, 8556,  16564, 7920, 9504,
            9207,  9603,  8910,  9216,  8910, 8928,  17232, 8640, 8232,
            8190,  8075,  8330,  16632, 8463, 8827,  8190,  7830, 16992,
            48316, 16461, 24913, 17934, 9207, 24741, 8556,
        },
        std::vector<int>{
            8, 9, 3, 3,  3, 11, 3, 5, 0, 4, 5, 9, 0, 3, 4, 5, 9,
            0, 3, 9, 13, 0, 4,  5, 9, 3, 0, 3, 4, 5, 6, 8, 9, 11,
        },
        std::vector<int>{
            0,
            2,
            3,
            4,
            6,
            8,
            12,
            17,
            17,
            17,
            18,
            19,
            21,
            25,
            25,
            26,
            34,
        });

    auto res = seq_crs_mult(A, B);
    EXPECT_TRUE(res == awaitRes);
}
TEST(OMP, Test_OMP_CRSmult_20x20) {
    Matrix A(
        std::vector<int>{
            97, 88, 82, 94, 97, 81, 95, 99, 84, 94, 97, 94, 82, 88, 90, 95,
            84, 98, 87, 82, 97, 83, 82, 82, 92, 82, 81, 97, 84, 89, 82, 91,
            92, 89, 90, 94, 89, 91, 82, 84, 82, 99, 91, 81, 89, 97, 90, 81,
            82, 92, 81, 99, 90, 86, 87, 84, 90, 90, 82, 94, 87, 92,
        },
        std::vector<int>{
            1, 19, 10, 1,  8,  7,  15, 17, 15, 10, 11, 4, 8,  12, 13, 17,
            8, 14, 8,  8,  9,  16, 17, 17, 0,  8,  12, 8, 14, 1,  12, 5,
            7, 12, 14, 19, 9,  12, 12, 19, 1,  16, 12, 0, 10, 3,  14, 0,
            6, 11, 8,  1,  19, 18, 2,  5,  7,  3,  13, 2, 1,  17,
        },
        std::vector<int>{
            0,  2,  3,  5,  8,  9,  11, 16, 18, 19, 22,
            23, 24, 24, 27, 29, 30, 31, 32, 36, 38, 62,
        });
    Matrix B(
        std::vector<int>{
            86, 86, 95, 84, 85, 97, 90, 94, 87, 82, 86, 99, 91,
            82, 94, 92, 85, 92, 82, 97, 83, 93, 92, 88, 87, 95,
            99, 95, 89, 81, 90, 93, 97, 81, 83, 98, 86, 96,
        },
        std::vector<int>{
            7,  2, 13, 18, 4,  14, 17, 10, 13, 18, 3,  2,  17,
            12, 1, 11, 14, 15, 8,  14, 16, 2,  3,  11, 9,  10,
            2,  8, 1,  8,  19, 6,  7,  9,  17, 19, 8,  17,
        },
        std::vector<int>{
            0,  1,  4,  5,  7,  10, 11, 13, 13, 14, 18,
            20, 21, 24, 26, 28, 31, 31, 36, 37, 38,
        });
    Matrix awaitRes(
        std::vector<int>{
            8342,  9215,  8448, 8148,  6724,  7954,  8084,  7954,  8930,
            7896,  8455,  9207, 9603,  7695,  8019,  8217,  18252, 7476,
            6804,  7560,  7708, 9118,  8051,  8184,  8096,  8835,  9215,
            15525, 17386, 7744, 6724,  8178,  7885,  7708,  9310,  9702,
            9310,  6888,  7134, 9118,  8924,  6724,  8245,  8924,  7626,
            7954,  6642,  6806, 8036,  7626,  7954,  6642,  6806,  8036,
            7533,  7452,  7912, 7128,  6724,  8316,  7980,  7954,  7654,
            8455,  7476,  7626, 7544,  7216,  7826,  17187, 8188,  8550,
            7832,  9024,  8366, 8463,  8372,  16196, 7565,  8188,  56165,
            23140, 15385, 8556, 22856, 23244, 14586, 7790,  15224, 6642,
            25460, 26772, 7636, 48632, 22512, 9016,
        },
        std::vector<int>{
            2,  13, 17, 18, 8,  14, 2,  12, 13, 18, 1,  6,  7,  8,  9,  17,
            19, 1,  8,  19, 8,  14, 16, 2,  3,  6,  7,  9,  10, 11, 12, 13,
            17, 18, 19, 2,  8,  12, 12, 1,  11, 12, 14, 15, 6,  7,  9,  17,
            19, 6,  7,  9,  17, 19, 2,  3,  7,  11, 12, 2,  8,  12, 2,  13,
            18, 2,  3,  11, 3,  2,  3,  8,  11, 17, 1,  2,  3,  11, 14, 15,
            2,  3,  4,  6,  7,  8,  9,  10, 11, 12, 13, 14, 16, 17, 18, 19,
        },
        std::vector<int>{
            0,  4,  6,  10, 17, 20, 23, 35, 38, 39, 44,
            49, 54, 54, 59, 62, 65, 68, 69, 74, 80, 96,
        });

    auto res = seq_crs_mult(A, B);
    EXPECT_TRUE(res == awaitRes);
}
TEST(OMP, Test_OMP_CRSmult_25x25) {
    Matrix A(
        std::vector<int>{
            88, 84, 97, 83, 91, 97, 90, 83, 91, 91, 97, 89, 94, 86, 98, 98,
            96, 84, 86, 98, 89, 94, 83, 99, 86, 83, 88, 90, 81, 81, 96, 89,
            82, 95, 86, 91, 82, 89, 95, 86, 89, 85, 94, 85, 98, 89, 93, 99,
            99, 89, 99, 87, 91, 83, 96, 86, 88, 88, 89, 85, 87, 90, 83, 91,
            90, 98, 87, 86, 83, 98, 92, 88, 97, 84, 97, 97, 83, 84, 84, 90,
            94, 93, 99, 87, 82, 95, 96, 94, 89, 89, 84, 92, 98, 83, 98, 85,
            99, 89, 97, 93, 92, 88, 82, 82, 95, 84, 95, 87, 96, 86, 83, 83,
            83, 86, 86, 83, 84, 91, 95, 97, 98, 81,
        },
        std::vector<int>{
            7,  8,  13, 5,  9,  16, 24, 8,  20, 17, 3,  5,  6,  9,  15, 3,
            20, 2,  9,  23, 3,  12, 18, 3,  11, 21, 1,  6,  9,  11, 14, 12,
            14, 15, 18, 5,  6,  7,  2,  16, 20, 4,  6,  13, 17, 18, 2,  9,
            23, 0,  3,  3,  11, 19, 23, 8,  19, 24, 5,  12, 6,  24, 10, 5,
            13, 5,  7,  15, 0,  1,  5,  6,  9,  12, 0,  7,  13, 18, 2,  24,
            14, 10, 13, 14, 21, 23, 3,  20, 2,  3,  5,  14, 16, 8,  14, 15,
            7,  4,  7,  14, 14, 17, 18, 22, 18, 2,  11, 12, 20, 6,  17, 18,
            5,  8,  19, 3,  10, 18, 21, 1,  3,  5,
        },
        std::vector<int>{
            0,  3,  7,  7,  9,  10, 15, 17, 20, 23, 24, 26, 26,  27,
            31, 35, 38, 41, 46, 46, 49, 51, 55, 58, 60, 62, 122,
        });
    Matrix B(
        std::vector<int>{
            87, 94, 96, 88, 94, 93, 83, 85, 93, 99, 85, 94, 91, 96, 85,
            84, 93, 88, 96, 83, 97, 96, 93, 88, 83, 98, 99, 91, 95, 95,
            91, 82, 93, 88, 86, 81, 92, 99, 91, 94, 90, 94, 89, 90, 87,
            99, 95, 93, 99, 97, 97, 89, 85, 93, 94, 86, 91, 84, 90, 84,
        },
        std::vector<int>{
            2,  4,  24, 5,  9,  23, 20, 2,  9,  13, 17, 23, 7,  17, 14,
            23, 8,  8,  17, 10, 23, 11, 5,  18, 20, 0,  12, 14, 20, 3,
            4,  7,  8,  11, 17, 21, 22, 1,  7,  8,  15, 18, 16, 20, 0,
            1,  10, 13, 16, 10, 23, 15, 11, 21, 0,  13, 14, 3,  21, 24,
        },
        std::vector<int>{
            0,  3,  6,  7,  12, 14, 16, 17, 19, 21, 22, 25, 29,
            33, 37, 42, 44, 49, 49, 51, 52, 54, 55, 57, 59, 60,
        });
    Matrix awaitRes(
        std::vector<int>{
            7744,  6972,  8536,   16790, 7857,  8924,  8148,  8439,   9603,
            9215,  8736,  9021,   7055,  9603,  6972,  7560,  6889,   7735,
            8463,  8051,  8245,   8742,  9021,  8256,  9603,  7565,   8722,
            8245,  8820,  16594,  8330,  9114,  8160,  9702,  8330,   8928,
            9212,  8232,  8256,   6972,  8820,  7565,  8930,  8554,   7708,
            8742,  8277,  8051,   8811,  7565,  16417, 8415,  9207,   9801,
            8415,  9306,  16230,  8514,  7826,  8170,  7744,  8272,   8184,
            7938,  9504,  8736,   17394, 7776,  8019,  7371,  8640,   9024,
            7695,  8118,  8455,   8099,  14760, 15985, 8342,  7380,   8455,
            7708,  8550,  8342,   15458, 7735,  8544,  7644,  7482,   8514,
            8170,  7565,  7998,   8514,  7885,  8277,  7735,  8742,   8633,
            7480,  15470, 6885,   7820,  8633,  8316,  9504,  7719,   8910,
            16158, 8366,  9207,   9801,  8415,  9306,  8544,  8918,   7395,
            8064,  8091,  9009,   8613,  8281,  7387,  7395,  8645,   8640,
            8178,  7138,  7832,   8342,  7392,  8075,  7735,  6970,   7905,
            7565,  7476,  8091,   7560,  34474, 64746, 46770, 24225,  32481,
            41340, 72717, 117789, 52368, 65532, 49398, 9405,  52400,  61072,
            57694, 24921, 99526,  75144, 67326, 48252, 25024, 155563, 24840,
        },
        std::vector<int>{
            8,  10, 11, 17, 21, 22, 23, 0,  1,  10, 11, 13, 14, 16, 23, 24, 10,
            11, 21, 23, 2,  8,  9,  11, 13, 14, 16, 17, 20, 23, 2,  9,  11, 13,
            17, 21, 23, 3,  11, 20, 21, 2,  3,  4,  7,  8,  9,  10, 13, 17, 23,
            2,  9,  13, 17, 23, 0,  12, 14, 20, 5,  9,  23, 0,  1,  7,  8,  11,
            12, 14, 15, 18, 20, 1,  3,  4,  7,  8,  10, 15, 16, 18, 20, 23, 8,
            14, 17, 23, 0,  1,  10, 11, 13, 16, 20, 21, 7,  8,  10, 11, 17, 21,
            22, 23, 3,  11, 20, 21, 2,  4,  9,  13, 17, 23, 24, 0,  2,  3,  9,
            12, 13, 14, 15, 17, 20, 21, 23, 10, 15, 23, 24, 3,  4,  7,  8,  14,
            23, 8,  24, 0,  1,  2,  3,  4,  5,  7,  8,  9,  10, 11, 12, 13, 14,
            15, 16, 17, 18, 20, 21, 22, 23, 24,
        },
        std::vector<int>{
            0,  7,  16, 16, 20,  20,  30,  37,  41,  51,  56,  60,  60,  63,
            73, 84, 88, 96, 104, 104, 108, 115, 127, 131, 137, 139, 162,
        });

    auto res = seq_crs_mult(A, B);
    EXPECT_TRUE(res == awaitRes);
}
TEST(OMP, Test_OMP_CRSmult_30x30) {
    Matrix A(
        std::vector<int>{
            84, 82, 84, 83, 92, 94, 85, 83, 83, 82, 87, 84, 98, 86, 95, 81,
            91, 91, 89, 99, 86, 85, 92, 99, 88, 86, 86, 97, 92, 84, 98, 87,
            81, 85, 82, 88, 92, 81, 82, 94, 88, 90, 97, 93, 92, 97, 95, 82,
            94, 96, 96, 94, 97, 81, 81, 92, 94, 93, 87, 84, 93, 85, 87, 90,
            83, 95, 96, 98, 88, 91, 98, 96, 99, 87, 93, 85, 92, 91, 90, 85,
            93, 81, 95, 89, 88, 90, 88, 96, 97, 96, 91, 98, 87, 87, 89, 94,
            96, 91, 90, 94, 93, 93, 82, 99, 96, 93, 81, 86, 99, 85, 87, 96,
            96, 84, 88, 97, 86, 99, 97, 94, 84, 96, 83, 82, 99, 88, 91, 99,
            97, 96, 88, 82, 89, 82, 93, 93, 88, 85, 82, 87, 81, 96, 85, 87,
            81, 99, 87, 92, 99, 86, 90, 84, 93, 84, 94, 89, 84, 89, 84, 88,
        },
        std::vector<int>{
            7,  20, 23, 0,  5,  19, 20, 29, 3,  10, 21, 23, 28, 9,  16, 22,
            3,  14, 20, 4,  9,  18, 23, 27, 18, 9,  5,  26, 8,  24, 2,  15,
            23, 27, 8,  14, 18, 20, 4,  6,  8,  10, 17, 28, 29, 26, 1,  6,
            20, 2,  4,  24, 1,  2,  3,  17, 21, 4,  5,  18, 11, 22, 27, 24,
            27, 3,  22, 28, 17, 19, 1,  5,  10, 12, 10, 23, 4,  12, 17, 18,
            23, 17, 21, 10, 15, 19, 24, 25, 0,  20, 25, 27, 3,  4,  9,  20,
            27, 14, 20, 25, 26, 3,  7,  1,  19, 20, 28, 14, 16, 22, 24, 0,
            11, 17, 11, 8,  13, 6,  8,  17, 24, 17, 19, 26, 2,  16, 28, 18,
            1,  4,  20, 5,  8,  11, 26, 28, 6,  11, 26, 9,  3,  24, 28, 5,
            11, 0,  4,  27, 10, 20, 29, 6,  23, 29, 11, 12, 26, 6,  19, 23,
        },
        std::vector<int>{
            0,  3,  4,  8,  13, 16, 19, 24, 24, 25, 26, 28, 30, 33, 34, 38,
            45, 46, 49, 52, 57, 60, 63, 65, 68, 70, 74, 76, 81, 81, 83, 160,
        });
    Matrix B(
        std::vector<int>{
            90, 91, 93, 88, 90, 96, 88, 81, 98, 99, 98, 90, 96, 85, 88,
            98, 99, 94, 87, 86, 91, 98, 90, 93, 90, 93, 97, 91, 93, 92,
            81, 90, 89, 99, 86, 94, 95, 90, 88, 90, 83, 83, 82, 97, 87,
            94, 95, 90, 82, 90, 82, 91, 82, 94, 99, 99, 89, 85, 89, 95,
            89, 82, 98, 92, 91, 81, 97, 95, 92, 88, 88, 90, 89, 87, 88,
            83, 98, 92, 86, 94, 90, 93, 97, 93, 99, 91, 82, 99, 82, 93,
        },
        std::vector<int>{
            27, 6,  8,  13, 20, 24, 25, 7,  13, 28, 29, 3,  1,  2,  12,
            17, 18, 21, 16, 22, 0,  3,  5,  7,  11, 14, 3,  7,  1,  4,
            12, 21, 25, 9,  11, 14, 12, 19, 23, 3,  11, 13, 4,  10, 14,
            16, 18, 20, 11, 14, 17, 1,  6,  17, 5,  10, 15, 16, 26, 8,
            10, 4,  8,  19, 0,  6,  16, 24, 5,  18, 20, 22, 23, 29, 6,
            7,  11, 14, 21, 23, 7,  9,  10, 20, 6,  14, 3,  7,  9,  28,
        },
        std::vector<int>{
            0,  1,  3,  7,  11, 12, 18, 20, 26, 28, 31, 33, 36, 39, 42, 47,
            48, 51, 54, 54, 59, 61, 61, 64, 68, 74, 80, 84, 86, 90, 90,
        });
    Matrix awaitRes(
        std::vector<int>{
            15288,  8232,   7560,   6804,  7812,   7790,   7298,   7560,  7812,
            8148,   7980,   7470,   8832,  7820,   9306,   8075,   16871, 8096,
            8366,   7990,   9016,   9108,  8648,   8366,   7644,   8036,  6804,
            16425,  8036,   8134,   8148,  7380,   7980,   7298,   17331, 8134,
            7998,   14554,  7938,   7790,  6966,   8550,   7790,   7452,  7462,
            7371,   8455,   16748,  8918,  7917,   8554,   8645,   9009,  8918,
            8372,   7998,   8910,   7912,  17253,  6966,   9009,   8924,  8740,
            7998,   7912,   6966,   8256,  7310,   8730,   9021,   9409,  7568,
            8428,   8514,   9021,   8084,  8924,   7728,   8372,   7392,  7392,
            7560,   7476,   7308,   7371,  6561,   8624,   7857,   16650, 17103,
            8624,   8415,   7735,   7954,  7216,   7462,   7695,   15745, 7656,
            8272,   8360,   8827,   23542, 7954,   17215,  7626,   8178,  9118,
            8100,   8084,   8010,   8649,  8730,   9021,   9409,   9021,  8645,
            17765,  8366,   7134,   7052,  8640,   8648,   8448,   8272,  16912,
            8460,   8366,   9216,   8448,  8178,   8372,   16371,  6561,  9021,
            15066,  8648,   7290,   7776,  7128,   8019,   7938,   8352,  7395,
            8370,   7656,   8526,   8613,  8178,   6970,   8613,   8330,  9207,
            7998,   16659,  7820,   8280,  8217,   7553,   7920,   7920,  8100,
            8010,   7830,   8036,   7872,  17397,  9408,   8036,   9310,  8832,
            18519,  9310,   8008,   9009,  7216,   9009,   8099,   7735,  8272,
            8099,   9216,   8160,   8918,  9114,   16713,  9408,   9504,  7830,
            17934,  7656,   8811,   7735,  6885,   8245,   8370,   8075,  8277,
            8463,   8190,   8280,   14913, 8645,   9021,   8460,   8190,  8008,
            8835,   7371,   6642,   7614,  23933,  57526,  14365,  96227, 37676,
            74987,  108007, 151553, 78523, 121136, 142897, 102626, 37583, 41428,
            141177, 31417,  95520,  57652, 64786,  15830,  88432,  56972, 62910,
            65841,  26699,  25444,  31417, 26280,  58389,  56463,
        },
        std::vector<int>{
            0,  3,  5,  6,  7,  8,  10, 11, 14, 16, 24, 27, 1,  2,  5,  8,  10,
            12, 15, 16, 17, 18, 21, 26, 0,  3,  6,  7,  9,  13, 16, 21, 24, 25,
            28, 29, 1,  4,  8,  11, 12, 14, 17, 19, 4,  7,  8,  10, 13, 14, 16,
            18, 28, 29, 0,  1,  3,  4,  6,  12, 14, 16, 24, 1,  4,  12, 1,  2,
            7,  9,  10, 12, 17, 18, 20, 21, 3,  5,  7,  18, 20, 22, 23, 29, 0,
            6,  13, 16, 20, 24, 25, 6,  14, 3,  4,  7,  8,  10, 14, 16, 18, 1,
            3,  6,  7,  9,  16, 17, 21, 22, 25, 28, 7,  9,  10, 20, 6,  8,  10,
            16, 22, 3,  5,  13, 18, 20, 22, 23, 24, 25, 29, 1,  6,  7,  8,  13,
            17, 20, 24, 25, 28, 29, 1,  2,  3,  12, 17, 18, 21, 4,  6,  8,  9,
            11, 14, 19, 5,  6,  14, 18, 20, 22, 23, 29, 3,  4,  7,  8,  9,  13,
            19, 28, 29, 1,  5,  6,  10, 15, 16, 17, 26, 1,  2,  6,  8,  12, 17,
            18, 19, 21, 23, 25, 0,  6,  16, 21, 24, 25, 0,  1,  3,  6,  12, 16,
            17, 19, 23, 24, 1,  6,  17, 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
            10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
            27, 28, 29,
        },
        std::vector<int>{
            0,   11,  12,  24,  36,  44,  54,  63,  63,  63,  66,
            76,  84,  91,  93,  101, 112, 116, 121, 131, 142, 149,
            156, 164, 173, 181, 192, 198, 208, 208, 211, 241,
        });

    auto res = seq_crs_mult(A, B);
    EXPECT_TRUE(res == awaitRes);
}
