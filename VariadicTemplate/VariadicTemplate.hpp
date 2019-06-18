#ifndef VARIADICTEMPLATE_HPP
#define VARIADICTEMPLATE_HPP

#include "bits/stdc++.h"

namespace GP {

    /*!
     * \brief print
     */
    void print() {
    }

    template <typename T, typename... Types>
    void print(T firstArg, Types... args) {
        std::cout << firstArg << std::endl;
        print(args...);
    }
}  // namespace GP
#endif  // VARIADICTEMPLATE_HPP
