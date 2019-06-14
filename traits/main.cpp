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

int main(int /* argc */, char** /* argv */) {
    int i = 24;
    std::add_const<int>::type c = i;
    std::add_const_t<int> c14 = i;
    static_assert(std::is_const<decltype(c)>::value, "c should be const");

    std::cout << std::boolalpha;
    std::cout << std::is_same<decltype(c), int const>::value << std::endl;
    std::cout << std::is_same_v<decltype(c), int const> << "\n";

    if (std::is_same<decltype(c), int const>{}) {
        std::cout << "same \n";
    }

    return 0;
}
