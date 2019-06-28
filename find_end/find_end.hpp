#ifndef FIND_END_HPP
#define FIND_END_HPP

namespace GP {

    ////////////////////////////////////////////////////////////
    /// \brief find_end
    /// \param first1
    /// \param last1
    /// \param first2
    /// \param last2
    /// \return
    ///
    template <class ForwardIterator1, class ForwardIterator2>
    ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2) {
        // last1 is the default answer
        ForwardIterator1 result = last1;
        if (first2 == last2) {
            return result;
        }

        while (true) {
            // scan the source
            while (true) {
                if (first1 == last1) {  // source exhausted return last correct answer
                    return result;
                }
                if (*first1 == first2) {  // find the first letter
                    break;
                }
                ++first1;
            }

            ForwardIterator1 m1 = first1;
            ForwardIterator2 m2 = first2;
            // scan the pattern
            while (true) {
                // pattern exhaused, record answer and search for another one
                ++m2;
                if (m2 == last2) {
                    result = first1;
                    ++first1;
                    break;
                }

                // source exhausted, return last answser
                ++m1;
                if (m1 == last1) {
                    return result;
                }

                // mismatch, restart with a new first1
                if (*m1 != *m2) {
                    ++first1;
                    break;
                }
            }
        }
    }

}  // namespace GP

#endif  // FIND_END_HPP
