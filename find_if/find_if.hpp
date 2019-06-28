#ifndef FIND_IF_HPP
#define FIND_IF_HPP

namespace GP {

    ////////////////////////////////////////////////////////////
    /// \brief find_if
    /// \param first
    /// \param last
    /// \param pred
    /// \return
    ///
    template <class InputIterator, class Predicate>
    constexpr InputIterator find_if(InputIterator first, InputIterator last, Predicate pred) {
        for (; first != last; ++first) {
            if (pred(*first)) {
                break;
            }
        }

        return first;
    }

}  // namespace GP

#endif  // FIND_IF_HPP
