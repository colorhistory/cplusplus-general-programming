/****************************************************************************
**
** Copyright (C) 2019 Xiaohai <xiaohaidotpro@outlook.com>.
** Contact: http://xiaohai.pro
**
** This file is part of cplusplus-general-programming
**
**
****************************************************************************/

#include "bits/stdc++.h"

#include "Foreach.hpp"

void func(int i) {
    std::cout << "func() called for: " << i << std::endl;
}

class FuncObj {
  public:
    void operator()(int i) const {
        std::cout << "FuncObj::op() called for: " << i << std::endl;
    }
};

int main(int /* argc */, char** /* argv */) {
    std::vector<int> primes{1, 2, 4, 9, 3, 5, 8, 7};

    GP::foreach (primes.begin(), primes.end(), func);
    GP::foreach (primes.begin(), primes.end(), &func);
    GP::foreach (primes.begin(), primes.end(), FuncObj());
    GP::foreach (primes.begin(), primes.end(), [](int i) { std::cout << "lambda Called for: " << i << std::endl; });

    return 0;
}
