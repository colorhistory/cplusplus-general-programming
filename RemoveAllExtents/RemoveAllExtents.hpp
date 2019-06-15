#ifndef REMOVEALLEXTENTS_HPP
#define REMOVEALLEXTENTS_HPP

#include "bits/stdc++.h"

namespace GP {

    template <typename T>
    struct RemoveAllExtents {
        using type = T;
    };

    template <typename T, std::size_t SZ>
    struct RevoveAllExtents<T[SZ]> {
        using type = typename RemoveAllExtents<T>::type;
    };

    template <typename T>
    struct RemoveAllExtents<T[]> {
        using type = typename RevoveAllExtents<T>::type;
    };

    template <typename T>
    using RevoveAllExtents = typename RevoveAllExtents<T>::type;

}  // namespace GP
#endif  // REMOVEALLEXTENTS_HPP
