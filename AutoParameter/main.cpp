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

#include "AutoParameter.hpp"

int main(int /* argc */, char** /* argv */) {
    std::default_random_engine engine;
    std::uniform_int_distribution<int> dis(0, 100);

    GP::Stack<int, 10> intStack;
    for (int i = 0; i != 10; ++i) {
        intStack.push(dis(engine));
    }

    for (int i = 0; i != 10; ++i) {
        std::cout << intStack.top() << "   ";
        intStack.pop();
    }

    return 0;
}
