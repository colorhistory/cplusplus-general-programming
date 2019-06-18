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

#include "LessArray.hpp"

int main(int /* argc */, char** /* argv */) {
    int a[] = {1, 2, 3, 5};
    int b[] = {1, 2, 3, 4, 5};

    std::cout << GP::less(a, b) << std::endl;

    return 0;
}
