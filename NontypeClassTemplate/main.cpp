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

#include "NontypeClassTemplate.hpp"

int main(int /* argc */, char** /* argv */) {
    GP::Stack<int, 20> int20Stack;
    GP::Stack<int, 40> int40Stack;
    GP::Stack<std::string, 40> stringStack;

    int20Stack.push(7);
    std::cout << int20Stack.top() << std::endl;
    int20Stack.pop();

    stringStack.push("xiaohai");
    std::cout << stringStack.top() << std::endl;
    stringStack.pop();

    return 0;
}
