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

#include "MaxAuto.hpp"

int main(int /* argc */, char** /* argv */) {
    int i = 42;
    std::cout << "max(7, i) " << GP::max(7, i) << '\n';

    double f1 = 3.4;
    double f2 = -6.7;
    std::cout << "max(f1, f2): " << GP::max(f1, f2) << '\n';

    std::string s1 = "xiaohai";
    std::string s2 = "xiaohaijin";
    std::cout << "max(s1, s2): " << GP::max(s1, s2) << '\n';

    return 0;
}
