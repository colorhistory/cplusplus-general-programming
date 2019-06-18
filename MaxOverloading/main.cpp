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

#include "MaxOverloading.hpp"

int main(int /* argc */, char** /* argv */) {
    std::cout << GP::max(7, 42) << std::endl;
    std::cout << GP::max(7.0, 42.0) << std::endl;
    std::cout << GP::max('a', 'b') << std::endl;
    std::cout << GP::max<>(7, 42) << std::endl;
    std::cout << GP::max<double>(7, 42) << std::endl;
    std::cout << GP::max('a', 42.7) << std::endl;

    return 0;
}
