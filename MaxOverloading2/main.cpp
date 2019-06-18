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

#include "MaxOverloading2.hpp"

int main(int /* argc */, char ** /* argv */) {
    int a = 7;
    int b = 42;
    auto m1 = GP::max(a, b);
    std::cout << m1 << std::endl;

    std::string s1 = "hey";
    std::string s2 = "you";
    std::cout << GP::max(s1, s2) << std::endl;

    int *p1 = &b;
    int *p2 = &a;
    std::cout << GP::max(p1, p2) << std::endl;

    const char *x = "hello";
    const char *y = "world";
    std::cout << GP::max(x, y) << std::endl;

    return 0;
}
