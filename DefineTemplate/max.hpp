#ifndef MAX_HPP
#define MAX_HPP

namespace GP {

    /*!
     * \brief max
     * \param a
     * \param b
     * \return
     */
    template <typename T>
    T max(T a, T b) {
        return b < a ? a : b;
    }

}  // namespace GP

#endif  // MAX_HPP
