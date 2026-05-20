#include <gtest/gtest.h>
#include "suma.h"

TEST(SumaTest, Positivos) {
    EXPECT_EQ(suma(2, 3), 5);
}

TEST(SumaTest, ConCero) {
    EXPECT_EQ(suma(7, 0), 7);
}

TEST(SumaTest, Negativos) {
    EXPECT_EQ(suma(-2, -3), -5);
}