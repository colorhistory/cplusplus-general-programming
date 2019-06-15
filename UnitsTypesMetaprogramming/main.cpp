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

#include "Ratio.hpp"

int main(int /* argc */, char** /* argv */) {
    int x = 42;
    int y = 77;

    auto a = GP::Duration<int, GP::Ratio<1, 1000>>(x);
    auto b = GP::Duration<int, GP::Ratio<2, 3>>(y);
    auto c = a + b;

    return 0;
}
