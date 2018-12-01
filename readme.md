# C++ Boilerplate

[![Build Status](https://travis-ci.com/smahajan07/pid-controller.svg?branch=master)](https://travis-ci.com/smahajan07/pid-controller)
[![Coverage Status](https://coveralls.io/repos/github/smahajan07/pid-controller/badge.svg?branch=master)](https://coveralls.io/github/smahajan07/pid-controller?branch=master)
---

## Standard install via command-line
To run the code, it has to be cloned first. To clone it, enter the following command

```
git clone --recursive https://github.com/nantha007/pid-controller
cd pid-controller/
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## GMock 

This code is written to utilize Google mock frame work. To use google mock frame work on a class, the class has to be fully consumed by an another class. In this code, Class addition is completely consumed by the class pidController. The class mockAdd mocked the class addition. So, that it can be tested with google mock test framework.

## Disclaimer
This code is licensed under MIT license.

```
 Copyright (c) 2018 Nantha Kumar Sunder

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
```
