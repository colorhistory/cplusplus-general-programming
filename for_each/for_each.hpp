#ifndef FOR_EACH_HPP
#define FOR_EACH_HPP

namespace GP {

    ////////////////////////////////////////////////////////////
    /// \brief for_each
    /// \param first
    /// \param last
    /// \param f
    /// \return
    ///
    template <class InputIterator, class Function>
    constexpr Function for_each(InputIterator first, InputIterator last, Function f) {
        for (; first != last; ++first) {
            f(*first);
        }
        return f;
    }

}  // namespace GP

#endif  // FOR_EACH_HPP
