//
// Created by Katya on 01.12.2020.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using testing::Eq;

class CommandTest: public testing::Test {};
class MemoryTest: public testing::Test {};
class TimeTests: public testing::Test {};

TEST_F(CommandTest, steps) {
    ASSERT_EQ(6, 6);
}

