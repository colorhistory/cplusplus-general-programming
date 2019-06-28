#ifndef COUNT_HPP
#define COUNT_HPP

#include "bits/stdc++.h"

namespace GP {

    ////////////////////////////////////////////////////////////
    /// \brief count
    /// \param first
    /// \param last
    /// \param value
    /// \return
    ///
    template <class InputIterator, class T>
    constexpr typename std::iterator_traits<InputIterator>::difference_type count(InputIterator first, InputIterator last, const T& value) {
        typename std::iterator_traits<InputIterator>::difference_type result{0};
        for (; first != last; ++first) {
            if (*first == value) {
                ++result;
            }
        }

        return result;
    }

}  // namespace GP

#endif  // COUNT_HPP
