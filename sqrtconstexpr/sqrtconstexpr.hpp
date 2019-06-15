#ifndef SQRTCONSTEXPR_HPP
#define SQRTCONSTEXPR_HPP

namespace GP {

    template <typename T>
    constexpr T sqrt(T x) {
        if (x <= 1) {
            return x;
        }

        T lo = 0;
        T hi = x;
        while (true) {
            auto middle = (lo + hi) / 2;
            auto middleSquare = middle * middle;

            if (lo + 1 >= hi || middleSquare == x) {
                return middle;
            }

            if (middleSquare < x) {
                lo = middle;
            } else {
                hi = middle;
            }
        }
    }

}  // namespace GP

#endif  // SQRTCONSTEXPR_HPP
