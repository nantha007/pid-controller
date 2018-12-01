/**
 * MIT License
 * Copyright (c) 2018 Nantha Kumar Sunder
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
/** @file main.cpp
 * @brief To utilize a PID controller for given
 *        initial velocity and desired velocity
 *
 * An object of pidController class is created
 * The program runs until the desired velocity
 * is achieved.
 */

#include <iostream>
#include "../include/pid.h"
#include "../include/add.h"

/**
 * @brief Asks user for initial and desired velocity
 *        and calls the compute velocity function of
 *        the object of PID controller class.
 * @param none
 * @return none
 */

int main() {
  double vI, vF;
  double count = 0;
  // Threshold for the
  double threshold = 0.01;
  // Asking the user to enter initial velocity and final velocity
  std::cout << "Please enter the initial velocity" << std::endl;
  std::cin >> vI;
  std::cout << "Please enter the final velocity" << std::endl;
  std::cin >> vF;
  addition addAgent;
  pidController controller(addAgent);
  // Loop is for computing velocity
  while (true) {
    // Calling the computeVelocity function
    vI = controller.computeVelocity(vI, vF);
    std::cout << "Current Velocity  : " << vI << "\t" << "Desired Velocity  : "
              << vF << std::endl;
    // Checking whether the current velocity has reached
    // +/- 0.01 of the desired velocity
    if ((vI >= vF - threshold) && (vI <= vF + threshold))
      count += 1;
    else
      count = 0;
    // If the velocity is within the threshold of the
    // desired velocity of 100 consecutive time
    // it will break
    if ((count == 100) && ((vI >= vF - threshold) && (vI <= vF + threshold)))
      break;
  }
  std::cout << "Reach Final Velocity." << std::endl;
  return 0;
}

