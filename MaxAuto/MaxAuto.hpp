#ifndef MAXAUTO_HPP
#define MAXAUTO_HPP

namespace GP {

    template <typename T1, typename T2>
    auto max(T1 a, T2 b) {
        return b < a ? a : b;
    }

}  // namespace GP

#endif  // MAXAUTO_HPP
