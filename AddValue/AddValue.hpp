#ifndef ADDVALUE_HPP
#define ADDVALUE_HPP

namespace GP {

    template <int Val, typename T>
    auto AddValue(T x) {
        return x + Val;
    }

}  // namespace GP

#endif  // ADDVALUE_HPP
