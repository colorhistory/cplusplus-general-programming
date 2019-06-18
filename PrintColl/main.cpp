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

#include "PrintColl.hpp"

int main(int /* argc */, char** /* argv */) {
    std::default_random_engine engine;
    std::uniform_int_distribution<int> random(2, 10);

    std::vector<int> intVec;
    for (int i = 0; i != 100; ++i) {
        intVec.push_back(random(engine));
    }

    GP::printColl(intVec);

    return 0;
}
