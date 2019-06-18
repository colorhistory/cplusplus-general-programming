#ifndef DEFAULTTEMPLATEARGUMENTS2_HPP
#define DEFAULTTEMPLATEARGUMENTS2_HPP

#include "bits/stdc++.h"

namespace GP {

    template <typename T1, typename T2, typename RT = std::common_type_t<T1, T2>>
    RT max(T1 a, T2 b) {
        return b < a ? a : b;
    }

}  // namespace GP

#endif  // DEFAULTTEMPLATEARGUMENTS2_HPP
