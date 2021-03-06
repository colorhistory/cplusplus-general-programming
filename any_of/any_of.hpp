﻿#ifndef ANY_OF_HPP
#define ANY_OF_HPP

namespace GP {

    ////////////////////////////////////////////////////////////
    /// \brief any_of
    /// \param first
    /// \param last
    /// \param pred
    /// \return
    ///
    template <class InputIterator, class Predicate>
    constexpr bool any_of(InputIterator first, InputIterator last, Predicate pred) {
        for (; first != last; ++first) {
            if (pred(*first)) {
                return true;
            }
        }
        return false;
    }

}  // namespace GP

#endif  // ANY_OF_HPP
