#ifndef COMPARE_HPP
#define COMPARE_HPP

#include "bits/stdc++.h"

namespace GP {
    // [cmp.categories], comparison category types
    class weak_equality;
    class strong_equality;
    class partial_ordering;
    class weak_ordering;
    class strong_ordering;

    // named comparison functions
    constexpr bool is_eq(weak_equality cmp) noexcept {
        return cmp == 0;
    }
    constexpr bool is_neq(weak_equality cmp) noexcept {
        return cmp != 0;
    }
    constexpr bool is_lt(partial_ordering cmp) noexcept {
        return cmp < 0;
    }
    constexpr bool is_lteq(partial_ordering cmp) noexcept {
        return cmp <= 0;
    }
    constexpr bool is_gt(partial_ordering cmp) noexcept {
        return cmp > 0;
    }
    constexpr bool is_gteq(partial_ordering cmp) noexcept {
        return cmp >= 0;
    }

    // [cmp.common], common comparison category type
    template <class... Ts>
    struct common_comparison_category {
        using type = see below;
    };
    template <class... Ts>
    using common_comparison_category_t = typename common_comparison_category<Ts...>::type;

    // [cmp.alg], comparison algorithms
    template <class T>
    constexpr strong_ordering strong_order(const T& a, const T& b);
    template <class T>
    constexpr weak_ordering weak_order(const T& a, const T& b);
    template <class T>
    constexpr partial_ordering partial_order(const T& a, const T& b);
    template <class T>
    constexpr strong_equality strong_equal(const T& a, const T& b);
    template <class T>
    constexpr weak_equality weak_equal(const T& a, const T& b);
}  // namespace GP

#endif  // COMPARE_HPP
