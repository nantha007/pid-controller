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
#pragma once
#include <iostream>
#include "../include/add.h"
/**
 * @brief Class to compute velocty using PID controller
 * @param k_p   Proportional gain
 * @param k_i   Integral gain
 * @param k_d   Derivative gain
 * @param dt    time step
 * @param integral integral term is the one that takes
 *                 care of accumulated error
 * @param prevError this term is to keep a tab of the
 *                  previous error so as to calculate the
 *                  gradient of error
 *
 * @return none
 */
class pidController : public addition {
 private:
  float k_p;
  float k_i;
  float k_d;
 public:
  addition & add;
  pidController(addition &);
  double dt;
  double integral;
  double prevError;
  double computeVelocity(double&, double&);
};


