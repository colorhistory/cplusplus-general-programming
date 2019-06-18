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

#include "Arrays.hpp"

using namespace GP;

template <typename T1, typename T2, typename T3>
void foo(int a1[7], int a2[], int (&a3)[42], int (&x0)[], T1 x1, T2& x2, T3&& x3) {
    Arrays<decltype(a1)>::print();
    Arrays<decltype(a2)>::print();
    Arrays<decltype(a3)>::print();
    Arrays<decltype(x0)>::print();
    Arrays<decltype(x1)>::print();
    Arrays<decltype(x2)>::print();
    Arrays<decltype(x3)>::print();
}

int main(int /* argc */, char** /* argv */) {
    int a[42];
    Arrays<decltype(a)>::print();

    extern int x[];
    Arrays<decltype(x)>::print();
    foo(a, a, a, x, x, x, x);

    return 0;
}

int x[] = {0, 1, 2, 3};
