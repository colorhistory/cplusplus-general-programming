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

class X {
    // ...
};

void g(X &) {
    std::cout << "g() for variables" << std::endl;
}

void g(const X &) {
    std::cout << "g() for constant" << std::endl;
}

void g(X &&) {
    std::cout << "g() for movable object" << std::endl;
}

template <typename T>
void f(T &&val) {
    g(std::forward<T>(val));
}

int main(int /* argc */, char ** /* argv */) {
    X v;
    const X c;

    f(v);             // f(X &) => calls g(X &)
    f(c);             // f(const X &) => g(const X &)
    f(X());           // f(X &&) => g(X &&)
    f(std::move(v));  // f(X &&) => g(X &&)

    return 0;
}
