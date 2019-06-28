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

#include "all_of.hpp"

bool greaterFive(int number);

int main(int /* argc */, char** /* argv */) {
    static std::default_random_engine engige(std::time(0));
    static std::uniform_int_distribution<int> dis(6, 100);

    std::vector<int> intVec;
    for (int i = 0; i != 100; ++i) {
        intVec.push_back(dis(engige));
    }

    std::cout << std::boolalpha << GP::all_of(intVec.begin(), intVec.end(), greaterFive) << std::endl;

    return 0;
}

bool greaterFive(int number) {
    return number > 5 ? true : false;
}
