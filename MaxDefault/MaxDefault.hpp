#ifndef MAXDEFAULT_HPP
#define MAXDEFAULT_HPP

namespace GP {

    template <typename T1, typename T2>
    auto max(T1 a, T2 b) {
        return b < a ? a : b;
    }

    template <typename RT, typename T1, typename T2>
    RT max(T1 a, T2 b) {
        return b < a ? a : b;
    }

}  // namespace GP
#endif  // MAXDEFAULT_HPP
