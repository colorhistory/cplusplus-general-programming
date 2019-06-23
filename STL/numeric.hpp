#ifndef NUMERIC_HPP
#define NUMERIC_HPP

#include "bits/stdc++.h"

namespace GP {

    template <class InputIterator, class T>
    T accumulate(InputIterator first, InputIterator last, T init);

    template <class InputIterator, class T, class BinaryOperation>
    T accumulate(InputIterator first, InputIterator last, T init, BinaryOperation binary_op);

    template <class InputIterator>
    typename std::iterator_traits<InputIterator>::value_type reduce(InputIterator first, InputIterator last);  // C++17

    template <class InputIterator, class T>
    T reduce(InputIterator first, InputIterator last, T init);  // C++17

    template <class InputIterator, class T, class BinaryOperation>
    T reduce(InputIterator first, InputIterator last, T init, BinaryOperation binary_op);  // C++17

    template <class InputIterator1, class InputIterator2, class T>
    T inner_product(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init);

    template <class InputIterator1, class InputIterator2, class T, class BinaryOperation1, class BinaryOperation2>
    T inner_product(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init,
                    BinaryOperation1 binary_op1, BinaryOperation2 binary_op2);

    template <class InputIterator1, class InputIterator2, class T>
    T transform_reduce(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init);  // C++17

    template <class InputIterator1, class InputIterator2, class T, class BinaryOperation1, class BinaryOperation2>
    T transform_reduce(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init,
                       BinaryOperation1 binary_op1, BinaryOperation2 binary_op2);  // C++17

    template <class InputIterator, class T, class BinaryOperation, class UnaryOperation>
    T transform_reduce(InputIterator first, InputIterator last, T init, BinaryOperation binary_op,
                       UnaryOperation unary_op);  // C++17

    template <class InputIterator, class OutputIterator>
    OutputIterator partial_sum(InputIterator first, InputIterator last, OutputIterator result);

    template <class InputIterator, class OutputIterator, class BinaryOperation>
    OutputIterator partial_sum(InputIterator first, InputIterator last, OutputIterator result,
                               BinaryOperation binary_op);

    template <class InputIterator, class OutputIterator, class T>
    OutputIterator exclusive_scan(InputIterator first, InputIterator last, OutputIterator result, T init);  // C++17

    template <class InputIterator, class OutputIterator, class T, class BinaryOperation>
    OutputIterator exclusive_scan(InputIterator first, InputIterator last, OutputIterator result, T init,
                                  BinaryOperation binary_op);  // C++17

    template <class InputIterator, class OutputIterator>
    OutputIterator inclusive_scan(InputIterator first, InputIterator last, OutputIterator result);  // C++17

    template <class InputIterator, class OutputIterator, class BinaryOperation>
    OutputIterator inclusive_scan(InputIterator first, InputIterator last, OutputIterator result,
                                  BinaryOperation binary_op);  // C++17

    template <class InputIterator, class OutputIterator, class BinaryOperation, class T>
    OutputIterator inclusive_scan(InputIterator first, InputIterator last, OutputIterator result,
                                  BinaryOperation binary_op, T init);  // C++17

    template <class InputIterator, class OutputIterator, class T, class BinaryOperation, class UnaryOperation>
    OutputIterator transform_exclusive_scan(InputIterator first, InputIterator last, OutputIterator result, T init,
                                            BinaryOperation binary_op, UnaryOperation unary_op);  // C++17

    template <class InputIterator, class OutputIterator, class BinaryOperation, class UnaryOperation>
    OutputIterator transform_inclusive_scan(InputIterator first, InputIterator last, OutputIterator result,
                                            BinaryOperation binary_op, UnaryOperation unary_op);  // C++17

    template <class InputIterator, class OutputIterator, class BinaryOperation, class UnaryOperation, class T>
    OutputIterator transform_inclusive_scan(InputIterator first, InputIterator last, OutputIterator result,
                                            BinaryOperation binary_op, UnaryOperation unary_op,
                                            T init);  // C++17

    template <class InputIterator, class OutputIterator>
    OutputIterator adjacent_difference(InputIterator first, InputIterator last, OutputIterator result);

    template <class InputIterator, class OutputIterator, class BinaryOperation>
    OutputIterator adjacent_difference(InputIterator first, InputIterator last, OutputIterator result,
                                       BinaryOperation binary_op);

    template <class ForwardIterator, class T>
    void iota(ForwardIterator first, ForwardIterator last, T value);

    template <class M, class N>
    constexpr std::common_type_t<M, N> gcd(M m, N n);  // C++17

    template <class M, class N>
    constexpr std::common_type_t<M, N> lcm(M m, N n);  // C++17

}  // namespace GP

#endif  // NUMERIC_HPP
