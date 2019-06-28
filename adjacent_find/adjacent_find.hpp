#ifndef ADJACENT_FIND_HPP
#define ADJACENT_FIND_HPP

namespace GP {

    ////////////////////////////////////////////////////////////
    /// \brief adjacent_find
    /// \param first
    /// \param last
    /// \return
    ///
    template <class ForwardIterator>
    constexpr ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last) {
        if (first != last) {
            ForwardIterator i = first;
            while (++i != last) {
                if (*first == i) {
                    return first;
                }
                first = i;
            }
        }

        return last;
    }

}  // namespace GP

#endif  // ADJACENT_FIND_HPP
