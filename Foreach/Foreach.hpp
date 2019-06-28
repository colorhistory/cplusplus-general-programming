#ifndef FOREACH_HPP
#define FOREACH_HPP

namespace GP {

    template <typename ForwardIterator, typename Callable>
    void foreach (ForwardIterator current, ForwardIterator end, Callable op) {
        while (current != end) {
            op(*current);
            ++current;
        }
    }

}  // namespace GP

#endif  // FOREACH_HPP
