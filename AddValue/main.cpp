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

#include "AddValue.hpp"

int main(int /* argc */, char** /* argv */) {
    std::vector<int> intVec;

    std::default_random_engine engine;
    std::uniform_int_distribution<int> distribution(0, 100);

    for (std::vector<int>::size_type i = 0; i != 100; ++i) {
        intVec.push_back(distribution(engine));
    }

    for (auto i : intVec) {
        std::cout << i << "   " << GP::AddValue<5, int>(i) << std::endl;
    }

    return 0;
}
