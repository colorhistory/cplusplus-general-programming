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

#include "TemplateTemplateParameters.hpp"

int main(int /* argc */, char** /* argv */) {
    Stack<int> iStack;
    Stack<float> fStack;

    iStack.push(1);
    iStack.push(2);
    std::cout << "iStack.top(): " << iStack.top() << std::endl;

    fStack.push(3.3f);
    std::cout << "fStack.top(): " << fStack.top() << std::endl;

    fStack = iStack;
    fStack.push(4.4f);

    Stack<double, std::vector> vStack;
    vStack.push(5.5);
    vStack.push(6.6);
    std::cout << "vStack.top(): " << vStack.top() << std::endl;

    vStack = fStack;
    std::cout << "vStack: ";
    while (!vStack.empty()) {
        std::cout << vStack.top() << "   ";
        vStack.pop();
    }
    std::cout << std::endl;

    return 0;
}
