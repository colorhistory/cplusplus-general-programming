#ifndef FOR_EACH_N_HPP
#define FOR_EACH_N_HPP

#include "bits/stdc++.h"

namespace GP {

    ////////////////////////////////////////////////////////////
    /// \brief for_each_n
    /// \param first
    /// \param n
    /// \param f
    /// \return
    ///
    template <class InputIterator, class Size, class Function>
    constexpr InputIterator for_each_n(InputIterator first, Size n, Function f) {
        while (n > 0) {
            f(*first);
            ++first;
            --n;
        }
        return first;
    }

}  // namespace GP

#endif  // FOR_EACH_N_HPP
