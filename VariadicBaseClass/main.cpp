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

#include "VariadicBaseClass.hpp"

int main(int /* argc */, char** /* argv */) {
    using CustomerOP = GP::Overloader<GP::CustomerHash, GP::CustomerEq>;

    std::unordered_set<GP::Customer, GP::CustomerHash, GP::CustomerEq> coll1;

    return 0;
}
