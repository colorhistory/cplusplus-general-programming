#ifndef RATIO_HPP
#define RATIO_HPP

namespace GP {

    /*!
     * \brief The Ratio struct
     */
    template <unsigned int N, unsigned int D = 1>
    struct Ratio {
        static constexpr unsigned int num = N;
        static constexpr unsigned int den = D;
        using type = Ratio<num, den>;
    };

    template <typename R1, typename R2>
    struct RatioAddImpl {
      public:
        typedef Ratio<num, den> type;

      private:
        static constexpr unsigned int den = R1::den * R2::den;
        static constexpr unsigned int num = R1::num * R2::den + R2::num * R1::den;
    };

    template <typename R1, typename R2>
    using RatioAdd = typename RatioAddImpl<R1, R2>::type;

    template <typename T, typename U = Ratio<1>>
    class Duration {
      public:
        using ValueType = T;
        using UnitType = typename U::type;

        constexpr Duration(ValueType v = 0) : val(v) {
        }

        constexpr ValueType value() const {
            return val;
        }

      private:
        ValueType val;
    };

    template <typename T1, typename U1, typename T2, typename U2>
    auto constexpr operator+(const Duration<T1, U1> &lhs, const Duration<T2, U2> &rhs) {
        using VT = Ratio<1, RatioAdd<U1, U2>::den>;

        auto val = lhs.value() * VT::den / U1::den * U1::num + rhs.value() * VT::den / U2::den * U2::num;

        return Duration<decltype(val), VT>(val);
    }

}  // namespace GP
#endif  // RATIO_HPP
