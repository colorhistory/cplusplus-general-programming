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

#include "Specialization.hpp"

int main(int /* argc */, char** /* argv */) {
    GP::Stack<int> intStack;
    GP::Stack<std::string> strStack;

    intStack.push(7);
    std::cout << intStack.top() << std::endl;

    strStack.push("hello");
    std::cout << strStack.top() << std::endl;
    strStack.pop();

    return 0;
}
