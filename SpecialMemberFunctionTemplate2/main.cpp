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

#include "SpecialMemberFunctionTemplate2.hpp"

int main(int /* argc */, char** /* argv */) {
    std::string s = "sname";
    Person p1(s);
    Person p2("tmp");
    // Person p3(p1);
    Person p4(std::move(p1));

    return 0;
}
