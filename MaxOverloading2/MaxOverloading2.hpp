#ifndef MAXOVERLOADING2_HPP
#define MAXOVERLOADING2_HPP

#include "bits/stdc++.h"

namespace GP {

    /*!
     * \brief maximum of two values of any type.
     * \param a
     * \param b
     * \return
     */
    template <typename T>
    T max(T a, T b) {
        return b < a ? a : b;
    }

    /*!
     * \brief maximum of two pointers
     * \param a
     * \param b
     * \return
     */
    template <typename T>
    T *max(T *a, T *b) {
        return *b < *a ? a : b;
    }

    /*!
     * \brief maximum of two cstrings
     * \param a
     * \param b
     * \return
     */
    const char *max(const char *a, const char *b) {
        return std::strcmp(b, a) < 0 ? a : b;
    }

}  // namespace GP

#endif  // MAXOVERLOADING2_HPP
