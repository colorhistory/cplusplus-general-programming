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

template <int N>
std::array<int, N> arr{};

template <auto N>
constexpr decltype(N) dval = N;

int main(int /* argc */, char** /* argv */) {
    std::cout << dval<'c'> << std::endl;
    arr<10>[0] = 42;

    for (std::size_t i = 0; i < arr<10>.size(); ++i) {
        std::cout << arr<10>[i] << std::endl;
    }

    return 0;
}
