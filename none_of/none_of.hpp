#ifndef NONE_OF_HPP
#define NONE_OF_HPP

namespace GP {

    ////////////////////////////////////////////////////////////
    /// \brief none_of
    /// \param first
    /// \param last
    /// \param pred
    /// \return
    ///
    template <class InputIterator, class Predicate>
    constexpr bool none_of(InputIterator first, InputIterator last, Predicate pred) {
        for (; first != last; ++first) {
            if (pred(*first)) {
                return false;
            }
        }
        return true;
    }

}  // namespace GP

#endif  // NONE_OF_HPP
