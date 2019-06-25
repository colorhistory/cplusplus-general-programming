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

int main(int /* argc */, char** /* argv */) {
    auto l = [](auto x, auto y) { return x < y; };

    static std::default_random_engine engine(std::time(0));
    static std::uniform_int_distribution<int> dis(0, 100);

    std::vector<int> intVec1, intVec2;

    for (int i = 0; i != 10; ++i) {
        intVec1.push_back(dis(engine));
        intVec2.push_back(dis(engine));
    }

    for (int i = 0; i != 10; ++i) {
        std::cout << std::boolalpha << l(intVec1[i], intVec2[i]) << std::endl;
    }

    return 0;
}
