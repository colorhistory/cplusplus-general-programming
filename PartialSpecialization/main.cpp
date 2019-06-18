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

#include "PartialSpecialization.hpp"

int main(int /* argc */, char** /* argv */) {
    GP::Stack<int*> intStackPtr;

    int val = 12;
    int* ptr = &val;
    intStackPtr.push(ptr);
    std::cout << intStackPtr.top() << std::endl;

    return 0;
}
