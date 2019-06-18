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

#include "Message.hpp"

int main(int /* argc */, char** /* argv */) {
    GP::Message<42> msg1;
    msg1.print();

    static const char s[] = "xiaohai";
    GP::Message<s> msg2;
    msg2.print();

    return 0;
}
