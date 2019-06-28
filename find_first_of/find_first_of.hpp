#ifndef FIND_FIRST_OF_HPP
#define FIND_FIRST_OF_HPP

namespace GP {

    ////////////////////////////////////////////////////////////
    /// \brief find_first_of
    /// \param first1
    /// \param last1
    /// \param first2
    /// \param last2
    /// \return
    ///
    template <class ForwardIterator1, class ForwardIterator2>
    constexpr ForwardIterator1 find_first_of(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2) {
        for (; first1 != last1; ++first1) {
            for (ForwardIterator2 j = first2; j != last2; ++j) {
                if (*first1 == *j) {
                    return first1;
                }
            }
        }

        return last1;
    }

}  // namespace GP

#endif  // FIND_FIRST_OF_HPP
