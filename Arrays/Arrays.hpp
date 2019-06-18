#ifndef ARRAYS_HPP
#define ARRAYS_HPP

#include "bits/stdc++.h"

namespace GP {

    template <typename T>
    struct Arrays;

    template <typename T, std::size_t SZ>
    struct Arrays<T[SZ]> {
        static void print() {
            std::cout << "print() for T[" << SZ << "]\n";
        }
    };

    template <typename T, std::size_t SZ>
    struct Arrays<T (&)[SZ]> {
        static void print() {
            std::cout << "print() for T(&)[" << SZ << "]\n";
        }
    };

    template <typename T>
    struct Arrays<T[]> {
        static void print() {
            std::cout << "print() for T[]\n";
        }
    };

    template <typename T>
    struct Arrays<T (&)[]> {
        static void print() {
            std::cout << "print() for T(&)[]\n";
        }
    };

    template <typename T>
    struct Arrays<T*> {
        static void print() {
            std::cout << "print() for T* \n";
        }
    };

}  // namespace GP

#endif  // ARRAYS_HPP
