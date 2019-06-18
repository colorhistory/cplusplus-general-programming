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

#include "DefaultClassTemplateArguments.hpp"

int main(int /* argc */, char** /* argv */) {
    GP::Stack<int> intStack;
    intStack.push(7);
    std::cout << intStack.top() << '\n';
    intStack.pop();

    GP::Stack<std::string, std::deque<std::string>> strStack;
    strStack.push(std::string{"xiaohai"});
    std::cout << strStack.top() << '\n';
    strStack.pop();

    return 0;
}
