#ifndef SQRT_HPP
#define SQRT_HPP

#include "bits/stdc++.h"

namespace GP {

    template <typename T>
    auto sqrt(T val) {
        double epsilon = 1.e-7;
        T low, high, middle;
        if (val > 1) {
            high = val;
            low = T{};
        } else {
            low = val;
            high = 1;
        }

        middle = (low + high) / 2;
        while ((high - low) >= epsilon) {
            if (middle * middle < val) {
                low = middle;
            } else {
                high = middle;
            }
            middle = (low + high) / 2;
        }
        return middle;
    }

}  // namespace GP

#endif  // SQRT_HPP
