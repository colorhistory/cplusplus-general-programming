#ifndef FIND_END_HPP
#define FIND_END_HPP

namespace GP {

    ////////////////////////////////////////////////////////////
    /// \brief find_end
    /// \param first1
    /// \param last1
    /// \param first2
    /// \param last2
    /// \param pred
    /// \return
    ///
    template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
    ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate pred) {
        ForwardIterator1 result = last1;

        if (first2 == last2) {
            return result;
        }

        while (true) {
            // scan source
            while (true) {
                if (first1 == last1) {
                    return result;
                }

                if (pred(*first1, *first2)) {
                    break;
                }

                ++first1;
            }

            ForwardIterator1 m1 = first1;
            ForwardIterator2 m2 = first2;
            while (true) {
                ++m2;
                if (m2 == last2) {
                    result = first1;
                    ++first1;
                    break;
                }

                ++m1;
                if (m1 == last1) {
                    return result;
                }

                if (!pred(*m1, *m2)) {
                    ++first1;
                    break;
                }
            }
        }
    }

}  // namespace GP

#endif  // FIND_END_HPP
