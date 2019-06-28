#ifndef MISMATCH_HPP
#define MISMATCH_HPP

#include "bits/stdc++.h"

namespace GP {

    ////////////////////////////////////////////////////////////
    /// \brief mismatch
    /// \param first1
    /// \param last1
    /// \param first2
    /// \return
    ///
    template <class InputIterator1, class InputIterator2>
    constexpr std::pair<InputIterator1, InputIterator2> mismatch(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
        for (; first1 != last1; ++first1, ++first2) {
            if (*first1 != *first2) {
                break;
            }
        }

        return std::pair<InputIterator1, InputIterator2>(first1, first2);
    }

}  // namespace GP

#endif  // MISMATCH_HPP
