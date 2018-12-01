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
/** @file pid.cpp
 * @brief To create a PID controller for given
 *        initial velocity and desired velocity
 *
 * An object of pidController class is created
 * and we can initialize the control parameters.
 * The program runs until the desired velocity
 * is achieved.
 */
#include <iostream>
#include "../include/pid.h"

/**
 * @brief Constructor is used to set the gains for
 *        the system
 *
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
pidController::pidController(addition & _add_)
    : add(_add_) {
  // set values of the gains
  k_p = 0.4;
  k_i = 0.1;
  k_d = 0.05;
  // set dt to small value, EXCEPT zero
  // for example dt = 0.4
  dt = 0.4;

  // integral and prevError can be initialized
  // to zero
  integral = 0;
  prevError = 0;
}
/**
 * @brief function to compute the velocity given
 *        the knowledge of gains and provided with
 *        the initial velocity and desired velocity
 *
 * @param vI  initial velocity
 * @param vF  final/desired velocity
 * @return computed velocity
 */
double pidController::computeVelocity(double& vI, double& vF) {
  // Setting error and dervative to zero
  double error = 0, derivative = 0;
  double differenceError = 0;
  // creating Addition object
  // addition addAgent;
  // Calculation of the error
  error = vF - vI;
  // Calculation of the integral error
  differenceError = error * dt;
  std::cout << "differenceError is calculated" << std::endl;
  integral = add.computeAddition(integral, differenceError);
  // Calculation of the derivative error
  derivative = (error - prevError) / dt;
  prevError = error;
  // Returning the Velocity
  return vI + k_p * error + k_i * integral + k_d * derivative;
}

