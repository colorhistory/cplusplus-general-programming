#ifndef ADJACENT_FIND_WITH_PRED_HPP
#define ADJACENT_FIND_WITH_PRED_HPP

namespace GP {

    ////////////////////////////////////////////////////////////
    /// \brief adjacent_find
    /// \param first
    /// \param last
    /// \param pred
    /// \return
    ///
    template <class ForwardIterator, class BinaryPredicate>
    constexpr ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last, BinaryPredicate pred) {
        if (first != last) {
            ForwardIterator i = first;
            while (++i != last) {
                if (pred(*first, *i)) {
                    return first;
                }
                first = i;
            }
        }

        return last;
    }

}  // namespace GP

#endif  // ADJACENT_FIND_WITH_PRED_HPP
