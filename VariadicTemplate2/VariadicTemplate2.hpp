#ifndef VARIADICTEMPLATE2_HPP
#define VARIADICTEMPLATE2_HPP

#include "bits/stdc++.h"

namespace GP {

    template <typename T>
    void print(T arg) {
        std::cout << arg << std::endl;
    }

    template <typename T, typename... Types>
    void print(T firstArg, Types... args) {
        print(firstArg);
        std::cout << sizeof...(Types) << std::endl;
        std::cout << sizeof...(args) << std::endl;
        print(args...);
    }

}  // namespace GP

#endif  // VARIADICTEMPLATE2_HPP
