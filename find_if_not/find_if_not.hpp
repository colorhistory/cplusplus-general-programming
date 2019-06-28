#ifndef FIND_IF_NOT_HPP
#define FIND_IF_NOT_HPP

namespace GP {

    ////////////////////////////////////////////////////////////
    /// \brief find_if_not
    /// \param first
    /// \param last
    /// \param pred
    /// \return
    ///
    template <class InputIterator, class Predicate>
    InputIterator find_if_not(InputIterator first, InputIterator last, Predicate pred) {
        for (; first != last; ++first) {
            if (!pred(*first)) {
                break;
            }
        }

        return first;
    }

}  // namespace GP

#endif  // FIND_IF_NOT_HPP
