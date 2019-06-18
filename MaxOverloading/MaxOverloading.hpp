#ifndef MAXOVERLOADING_HPP
#define MAXOVERLOADING_HPP

namespace GP {

    int max(int a, int b) {
        return b < a ? a : b;
    }

    template <typename T>
    T max(T a, T b) {
        return b < a ? a : b;
    }

}  // namespace GP

#endif  // MAXOVERLOADING_HPP
