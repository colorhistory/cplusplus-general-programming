#ifndef ALL_OF_HPP
#define ALL_OF_HPP

namespace GP {

    ////////////////////////////////////////////////////////////
    /// \brief all_of
    /// \param first
    /// \param last
    /// \param pred
    /// \return
    ///
    template <class InputIterator, class Predicate>
    constexpr bool all_of(InputIterator first, InputIterator last, Predicate pred) {
        for (; first != last; ++first) {
            if (!pred(*first)) {
                return false;
            }
        }
        return true;
    }

}  // namespace GP

#endif  // ALL_OF_HPP
