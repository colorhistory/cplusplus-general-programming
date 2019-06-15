#ifndef HYBRIDMETAPROGRAMMING_HPP
#define HYBRIDMETAPROGRAMMING_HPP

#include "bits/stdc++.h"

namespace GP {

    template <typename T, std::size_t N>
    auto dotProduct(std::array<T, N> arr1, std::array<T, N> arr2) {
        T result{};
        for (std::size_t k = 0; k != N; ++k) {
            result += arr1[k] * arr2[k];
        }
        return result;
    }

    template <typename T, std::size_t N>
    struct DotProduct {
        static inline T result(T *a, T *b) {
            return *a * *b + DotProduct<T, N - 1>::result(a + 1, b + 1);
        }
    };

    template <typename T>
    struct DotProduct<T, 0> {
        static inline T result(T *, T *) {
            return T{};
        }
    };

    template <typename T, std::size_t N>
    auto dotProduct(std::array<T, N> &arr1, std::array<T, N> &arr2, std::forward_iterator_tag) {
        return DotProduct<T, N>::result(arr1.begin(), arr2.begin());
    }

}  // namespace GP

#endif  // HYBRIDMETAPROGRAMMING_HPP
