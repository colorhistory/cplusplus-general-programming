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

#include "HybridMetaprogramming.hpp"

int main(int /* argc */, char** /* argv */) {
    constexpr int N = 20;
    std::array<int, N> arr1, arr2;

    std::default_random_engine engine(time(nullptr));
    std::uniform_int_distribution<int> intDistribution(0, 100);
    std::uniform_real_distribution<double> doubleDistribution(0.3, 1.5);
    for (std::size_t i = 0; i != arr1.size(); ++i) {
        arr1[i] = intDistribution(engine);
        arr2[i] = doubleDistribution(engine);
    }

    std::cout << GP::dotProduct(arr1, arr2) << std::endl;

    return 0;
}
