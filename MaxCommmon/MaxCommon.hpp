#ifndef MAXCOMMON_HPP
#define MAXCOMMON_HPP

#include "bits/stdc++.h"

namespace GP {

    template <typename T1, typename T2>
    typename std::common_type<T1, T2>::type max(T1 a, T2 b) {
        return b < a ? a : b;
    }

}  // namespace GP

#endif  // MAXCOMMON_HPP
