#ifndef MAXDECLTYPE_HPP
#define MAXDECLTYPE_HPP

namespace GP {

    /*!
     * \brief max
     * \param a
     * \param b
     */
    template <typename T1, typename T2>
    auto max(T1 a, T2 b) -> decltype(b < a ? a : b) {
        return b < a ? a : b;
    }

}  // namespace GP

#endif  // MAXDECLTYPE_HPP
