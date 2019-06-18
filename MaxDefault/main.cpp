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

#include "MaxDefault.hpp"

int main(int /* argc */, char** /* argv */) {
    std::cout << GP::max(4, 7.2) << std::endl;
    std::cout << GP::max<long double>(7.2, 4) << std::endl;

    // std::cout << GP::max<int>(4, 7.2) << std::endl;

    return 0;
}
