#ifndef COUNT_IF_HPP
#define COUNT_IF_HPP

#include "bits/stdc++.h"

namespace GP {

    ////////////////////////////////////////////////////////////
    /// \brief count_if
    /// \param first
    /// \param last
    /// \param pred
    /// \return
    ///
    template <class InputIterator, class Predicate>
    constexpr typename std::iterator_traits<InputIterator>::difference_type count_if(InputIterator first, InputIterator last, Predicate pred) {
        typename std::iterator_traits<InputIterator>::difference_type result{0};

        for (; first != last; ++first) {
            if (pred(*first)) {
                ++result;
            }
        }

        return result;
    }

}  // namespace GP

#endif  // COUNT_IF_HPP
