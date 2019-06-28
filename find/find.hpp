#ifndef FIND_HPP
#define FIND_HPP

namespace GP {

    ////////////////////////////////////////////////////////////
    /// \brief find
    /// \param first
    /// \param last
    /// \param value
    /// \return
    ///
    template <class InputIterator, class T>
    constexpr InputIterator find(InputIterator first, InputIterator last, const T& value) {
        for (; first != last; ++first) {
            if (*first == value) {
                break;
            }
        }
        return first;
    }

}  // namespace GP

#endif  // FIND_HPP
