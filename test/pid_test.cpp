/**
 * MIT License
 * Copyright (c) 2018 Nantha Kumar Sunder, Sarthak Mahajan, Chein Te Lee
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
/** @file pid_test.cpp
 * @brief To test a PID controller
 *
 */
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "include/mockAdd.h"
#include "../include/add.h"
#include "../include/pid.h"

/**
 * @brief Unit test to check time interval dt
 *
 * test to ensure that the value of dt is not zero
 * to avoid division-by-zero error
 */

TEST(timeInterval, timeIntervalNotZero) {
  addition addobj;
  pidController obj1(addobj);
  EXPECT_NE(0, obj1.dt);
}

/**
 * @brief Unit test for compute method
 *
 * Test to check if compute function returns the
 * same velocity as desired velocity if their is
 * no error
 */

TEST(computeTest, noError) {
  addition addObj;
  pidController obj2(addObj);
  double vI = 10, vF = 10;
  EXPECT_EQ(vF, obj2.computeVelocity(vI, vF));
}
/**
 * @brief Unit test for computeAddition
 *
 * Test to check if compute function returns the
 * value correctly
 */

TEST(mockAdd, AdditionCheck) {
  mockAdd addAgent;
  pidController obj(addAgent);
  double vI = 10, vF = 10, Result;
  EXPECT_CALL(addAgent, computeAddition(::testing::_, ::testing::_)).Times(1);
  Result = obj.computeVelocity(vI, vF);
  EXPECT_EQ(vF, Result);
}

