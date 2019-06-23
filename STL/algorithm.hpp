#include "bits/stdc++.h"

namespace GP {

    template <class InputIterator, class Predicate>
    constexpr bool all_of(InputIterator first, InputIterator last, Predicate pred);

    template <class InputIterator, class Predicate>
    constexpr bool any_of(InputIterator first, InputIterator last, Predicate pred);

    template <class InputIterator, class Predicate>
    constexpr bool none_of(InputIterator first, InputIterator last, Predicate pred);

    template <class InputIterator, class Function>
    constexpr Function for_each(InputIterator first, InputIterator last, Function f);

    template <class InputIterator, class Size, class Function>
    constexpr InputIterator for_each_n(InputIterator first, Size n, Function f);

    template <class InputIterator, class T>
    constexpr InputIterator find(InputIterator first, InputIterator last, const T& value);

    template <class InputIterator, class Predicate>
    constexpr InputIterator find_if(InputIterator first, InputIterator last, Predicate pred);

    template <class InputIterator, class Predicate>
    InputIterator find_if_not(InputIterator first, InputIterator last, Predicate pred);

    template <class ForwardIterator1, class ForwardIterator2>
    ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2,
                              ForwardIterator2 last2);

    template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
    ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2,
                              ForwardIterator2 last2, BinaryPredicate pred);

    template <class ForwardIterator1, class ForwardIterator2>
    constexpr ForwardIterator1 find_first_of(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2,
                                             ForwardIterator2 last2);

    template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
    constexpr ForwardIterator1 find_first_of(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2,
                                             ForwardIterator2 last2, BinaryPredicate pred);

    template <class ForwardIterator>
    constexpr ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last);

    template <class ForwardIterator, class BinaryPredicate>
    constexpr ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last, BinaryPredicate pred);

    template <class InputIterator, class T>
    constexpr typename std::iterator_traits<InputIterator>::difference_type count(InputIterator first,
                                                                                  InputIterator last, const T& value);

    template <class InputIterator, class Predicate>
    constexpr typename std::iterator_traits<InputIterator>::difference_type count_if(InputIterator first,
                                                                                     InputIterator last,
                                                                                     Predicate pred);

    template <class InputIterator1, class InputIterator2>
    constexpr std::pair<InputIterator1, InputIterator2> mismatch(InputIterator1 first1, InputIterator1 last1,
                                                                 InputIterator2 first2);

    template <class InputIterator1, class InputIterator2>
    constexpr std::pair<InputIterator1, InputIterator2> mismatch(InputIterator1 first1, InputIterator1 last1,
                                                                 InputIterator2 first2, InputIterator2 last2);

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    constexpr std::pair<InputIterator1, InputIterator2> mismatch(InputIterator1 first1, InputIterator1 last1,
                                                                 InputIterator2 first2, BinaryPredicate pred);

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    constexpr std::pair<InputIterator1, InputIterator2> mismatch(InputIterator1 first1, InputIterator1 last1,
                                                                 InputIterator2 first2, InputIterator2 last2,
                                                                 BinaryPredicate pred);

    template <class InputIterator1, class InputIterator2>
    constexpr bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2);

    template <class InputIterator1, class InputIterator2>
    constexpr bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2);

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    constexpr bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred);

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    constexpr bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2,
                         BinaryPredicate pred);

    template <class ForwardIterator1, class ForwardIterator2>
    constexpr bool is_permutation(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2);

    template <class ForwardIterator1, class ForwardIterator2>
    constexpr bool is_permutation(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2,
                                  ForwardIterator2 last2);

    template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
    constexpr bool is_permutation(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2,
                                  BinaryPredicate pred);

    template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
    constexpr bool is_permutation(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2,
                                  ForwardIterator2 last2, BinaryPredicate pred);

    template <class ForwardIterator1, class ForwardIterator2>
    constexpr ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2,
                                      ForwardIterator2 last2);

    template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
    constexpr ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2,
                                      ForwardIterator2 last2, BinaryPredicate pred);

    template <class ForwardIterator, class Size, class T>
    constexpr ForwardIterator search_n(ForwardIterator first, ForwardIterator last, Size count, const T& value);

    template <class ForwardIterator, class Size, class T, class BinaryPredicate>
    constexpr ForwardIterator search_n(ForwardIterator first, ForwardIterator last, Size count, const T& value,
                                       BinaryPredicate pred);

    template <class InputIterator, class OutputIterator>
    OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result);

    template <class InputIterator, class OutputIterator, class Predicate>
    OutputIterator copy_if(InputIterator first, InputIterator last, OutputIterator result, Predicate pred);

    template <class InputIterator, class Size, class OutputIterator>
    OutputIterator copy_n(InputIterator first, Size n, OutputIterator result);

    template <class BidirectionalIterator1, class BidirectionalIterator2>
    BidirectionalIterator2 copy_backward(BidirectionalIterator1 first, BidirectionalIterator1 last,
                                         BidirectionalIterator2 result);

    template <class ForwardIterator1, class ForwardIterator2>
    ForwardIterator2 swap_ranges(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2);

    template <class ForwardIterator1, class ForwardIterator2>
    void iter_swap(ForwardIterator1 a, ForwardIterator2 b);

    template <class InputIterator, class OutputIterator, class UnaryOperation>
    constexpr OutputIterator transform(InputIterator first, InputIterator last, OutputIterator result,
                                       UnaryOperation op);

    template <class InputIterator1, class InputIterator2, class OutputIterator, class BinaryOperation>
    constexpr OutputIterator transform(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
                                       OutputIterator result, BinaryOperation binary_op);

    template <class ForwardIterator, class T>
    constexpr void replace(ForwardIterator first, ForwardIterator last, const T& old_value, const T& new_value);

    template <class ForwardIterator, class Predicate, class T>
    constexpr void replace_if(ForwardIterator first, ForwardIterator last, Predicate pred, const T& new_value);

    template <class InputIterator, class OutputIterator, class T>
    constexpr OutputIterator replace_copy(InputIterator first, InputIterator last, OutputIterator result,
                                          const T& old_value, const T& new_value);

    template <class InputIterator, class OutputIterator, class Predicate, class T>
    constexpr OutputIterator replace_copy_if(InputIterator first, InputIterator last, OutputIterator result,
                                             Predicate pred, const T& new_value);

    template <class ForwardIterator, class T>
    constexpr void fill(ForwardIterator first, ForwardIterator last, const T& value);

    template <class OutputIterator, class Size, class T>
    constexpr OutputIterator fill_n(OutputIterator first, Size n, const T& value);

    template <class ForwardIterator, class Generator>
    constexpr void generate(ForwardIterator first, ForwardIterator last, Generator gen);

    template <class OutputIterator, class Size, class Generator>
    constexpr OutputIterator generate_n(OutputIterator first, Size n, Generator gen);

    template <class ForwardIterator, class T>
    constexpr ForwardIterator remove(ForwardIterator first, ForwardIterator last, const T& value);

    template <class ForwardIterator, class Predicate>
    constexpr ForwardIterator remove_if(ForwardIterator first, ForwardIterator last, Predicate pred);

    template <class InputIterator, class OutputIterator, class T>
    constexpr OutputIterator remove_copy(InputIterator first, InputIterator last, OutputIterator result,
                                         const T& value);

    template <class InputIterator, class OutputIterator, class Predicate>
    constexpr OutputIterator remove_copy_if(InputIterator first, InputIterator last, OutputIterator result,
                                            Predicate pred);

    template <class ForwardIterator>
    ForwardIterator unique(ForwardIterator first, ForwardIterator last);

    template <class ForwardIterator, class BinaryPredicate>
    ForwardIterator unique(ForwardIterator first, ForwardIterator last, BinaryPredicate pred);

    template <class InputIterator, class OutputIterator>
    OutputIterator unique_copy(InputIterator first, InputIterator last, OutputIterator result);

    template <class InputIterator, class OutputIterator, class BinaryPredicate>
    OutputIterator unique_copy(InputIterator first, InputIterator last, OutputIterator result, BinaryPredicate pred);

    template <class BidirectionalIterator>
    void reverse(BidirectionalIterator first, BidirectionalIterator last);

    template <class BidirectionalIterator, class OutputIterator>
    constexpr OutputIterator reverse_copy(BidirectionalIterator first, BidirectionalIterator last,
                                          OutputIterator result);

    template <class ForwardIterator>
    ForwardIterator rotate(ForwardIterator first, ForwardIterator middle, ForwardIterator last);

    template <class ForwardIterator, class OutputIterator>
    OutputIterator rotate_copy(ForwardIterator first, ForwardIterator middle, ForwardIterator last,
                               OutputIterator result);

    template <class RandomAccessIterator>
    void random_shuffle(RandomAccessIterator first,
                        RandomAccessIterator last);  // deprecated in C++14, removed in C++17

    template <class RandomAccessIterator, class RandomNumberGenerator>
    void random_shuffle(RandomAccessIterator first, RandomAccessIterator last,
                        RandomNumberGenerator& rand);  // deprecated in C++14, removed in C++17

    template <class PopulationIterator, class SampleIterator, class Distance, class UniformRandomBitGenerator>
    SampleIterator sample(PopulationIterator first, PopulationIterator last, SampleIterator out, Distance n,
                          UniformRandomBitGenerator&& g);

    template <class RandomAccessIterator, class UniformRandomNumberGenerator>
    void shuffle(RandomAccessIterator first, RandomAccessIterator last, UniformRandomNumberGenerator&& g);

    template <class InputIterator, class Predicate>
    constexpr bool is_partitioned(InputIterator first, InputIterator last, Predicate pred);

    template <class ForwardIterator, class Predicate>
    ForwardIterator partition(ForwardIterator first, ForwardIterator last, Predicate pred);

    template <class InputIterator, class OutputIterator1, class OutputIterator2, class Predicate>
    constexpr std::pair<OutputIterator1, OutputIterator2> partition_copy(InputIterator first, InputIterator last,
                                                                         OutputIterator1 out_true,
                                                                         OutputIterator2 out_false, Predicate pred);

    template <class ForwardIterator, class Predicate>
    ForwardIterator stable_partition(ForwardIterator first, ForwardIterator last, Predicate pred);

    template <class ForwardIterator, class Predicate>
    constexpr ForwardIterator partition_point(ForwardIterator first, ForwardIterator last, Predicate pred);

    template <class ForwardIterator>
    constexpr bool is_sorted(ForwardIterator first, ForwardIterator last);

    template <class ForwardIterator, class Compare>
    bool is_sorted(ForwardIterator first, ForwardIterator last, Compare comp);

    template <class ForwardIterator>
    constexpr ForwardIterator is_sorted_until(ForwardIterator first, ForwardIterator last);

    template <class ForwardIterator, class Compare>
    constexpr ForwardIterator is_sorted_until(ForwardIterator first, ForwardIterator last, Compare comp);

    template <class RandomAccessIterator>
    void sort(RandomAccessIterator first, RandomAccessIterator last);

    template <class RandomAccessIterator, class Compare>
    void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);

    template <class RandomAccessIterator>
    void stable_sort(RandomAccessIterator first, RandomAccessIterator last);

    template <class RandomAccessIterator, class Compare>
    void stable_sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);

    template <class RandomAccessIterator>
    void partial_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last);

    template <class RandomAccessIterator, class Compare>
    void partial_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last, Compare comp);

    template <class InputIterator, class RandomAccessIterator>
    RandomAccessIterator partial_sort_copy(InputIterator first, InputIterator last, RandomAccessIterator result_first,
                                           RandomAccessIterator result_last);

    template <class InputIterator, class RandomAccessIterator, class Compare>
    RandomAccessIterator partial_sort_copy(InputIterator first, InputIterator last, RandomAccessIterator result_first,
                                           RandomAccessIterator result_last, Compare comp);

    template <class RandomAccessIterator>
    void nth_element(RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last);

    template <class RandomAccessIterator, class Compare>
    void nth_element(RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last, Compare comp);

    template <class ForwardIterator, class T>
    constexpr ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, const T& value);

    template <class ForwardIterator, class T, class Compare>
    constexpr ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, const T& value, Compare comp);

    template <class ForwardIterator, class T>
    constexpr ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last, const T& value);

    template <class ForwardIterator, class T, class Compare>
    constexpr ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last, const T& value, Compare comp);

    template <class ForwardIterator, class T>
    constexpr std::pair<ForwardIterator, ForwardIterator> equal_range(ForwardIterator first, ForwardIterator last,
                                                                      const T& value);

    template <class ForwardIterator, class T, class Compare>
    constexpr std::pair<ForwardIterator, ForwardIterator> equal_range(ForwardIterator first, ForwardIterator last,
                                                                      const T& value, Compare comp);

    template <class ForwardIterator, class T>
    constexpr bool binary_search(ForwardIterator first, ForwardIterator last, const T& value);

    template <class ForwardIterator, class T, class Compare>
    constexpr bool binary_search(ForwardIterator first, ForwardIterator last, const T& value, Compare comp);

    template <class InputIterator1, class InputIterator2, class OutputIterator>
    OutputIterator merge(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2,
                         OutputIterator result);

    template <class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
    OutputIterator merge(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2,
                         OutputIterator result, Compare comp);

    template <class BidirectionalIterator>
    void inplace_merge(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last);

    template <class BidirectionalIterator, class Compare>
    void inplace_merge(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last,
                       Compare comp);

    template <class InputIterator1, class InputIterator2>
    constexpr bool includes(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2);

    template <class InputIterator1, class InputIterator2, class Compare>
    constexpr bool includes(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2,
                            Compare comp);

    template <class InputIterator1, class InputIterator2, class OutputIterator>
    OutputIterator set_union(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2,
                             OutputIterator result);

    template <class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
    OutputIterator set_union(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2,
                             OutputIterator result, Compare comp);

    template <class InputIterator1, class InputIterator2, class OutputIterator>
    constexpr OutputIterator set_intersection(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
                                              InputIterator2 last2, OutputIterator result);

    template <class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
    constexpr OutputIterator set_intersection(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
                                              InputIterator2 last2, OutputIterator result, Compare comp);

    template <class InputIterator1, class InputIterator2, class OutputIterator>
    OutputIterator set_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
                                  InputIterator2 last2, OutputIterator result);

    template <class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
    OutputIterator set_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
                                  InputIterator2 last2, OutputIterator result, Compare comp);

    template <class InputIterator1, class InputIterator2, class OutputIterator>
    OutputIterator set_symmetric_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
                                            InputIterator2 last2, OutputIterator result);

    template <class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
    OutputIterator set_symmetric_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
                                            InputIterator2 last2, OutputIterator result, Compare comp);

    template <class RandomAccessIterator>
    void push_heap(RandomAccessIterator first, RandomAccessIterator last);

    template <class RandomAccessIterator, class Compare>
    void push_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp);

    template <class RandomAccessIterator>
    void pop_heap(RandomAccessIterator first, RandomAccessIterator last);

    template <class RandomAccessIterator, class Compare>
    void pop_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp);

    template <class RandomAccessIterator>
    void make_heap(RandomAccessIterator first, RandomAccessIterator last);

    template <class RandomAccessIterator, class Compare>
    void make_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp);

    template <class RandomAccessIterator>
    void sort_heap(RandomAccessIterator first, RandomAccessIterator last);

    template <class RandomAccessIterator, class Compare>
    void sort_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp);

    template <class RandomAccessIterator>
    constexpr bool is_heap(RandomAccessIterator first, RandomAccessIterator last);

    template <class RandomAccessIterator, class Compare>
    constexpr bool is_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp);

    template <class RandomAccessIterator>
    constexpr RandomAccessIterator is_heap_until(RandomAccessIterator first, RandomAccessIterator last);

    template <class RandomAccessIterator, class Compare>
    constexpr RandomAccessIterator is_heap_until(RandomAccessIterator first, RandomAccessIterator last, Compare comp);

    template <class ForwardIterator>
    ForwardIterator min_element(ForwardIterator first, ForwardIterator last);  // constexpr in C++14

    template <class ForwardIterator, class Compare>
    ForwardIterator min_element(ForwardIterator first, ForwardIterator last, Compare comp);  // constexpr in C++14

    template <class T>
    const T& min(const T& a, const T& b);  // constexpr in C++14

    template <class T, class Compare>
    const T& min(const T& a, const T& b, Compare comp);  // constexpr in C++14

    template <class T>
    T min(std::initializer_list<T> t);  // constexpr in C++14

    template <class T, class Compare>
    T min(std::initializer_list<T> t, Compare comp);  // constexpr in C++14

    template <class T>
    constexpr const T& clamp(const T& v, const T& lo, const T& hi);

    template <class T, class Compare>
    constexpr const T& clamp(const T& v, const T& lo, const T& hi, Compare comp);

    template <class ForwardIterator>
    ForwardIterator max_element(ForwardIterator first, ForwardIterator last);  // constexpr in C++14

    template <class ForwardIterator, class Compare>
    ForwardIterator max_element(ForwardIterator first, ForwardIterator last, Compare comp);  // constexpr in C++14

    template <class T>
    const T& max(const T& a, const T& b);  // constexpr in C++14

    template <class T, class Compare>
    const T& max(const T& a, const T& b, Compare comp);  // constexpr in C++14

    template <class T>
    T max(std::initializer_list<T> t);  // constexpr in C++14

    template <class T, class Compare>
    T max(std::initializer_list<T> t, Compare comp);  // constexpr in C++14

    template <class ForwardIterator>
    std::pair<ForwardIterator, ForwardIterator> minmax_element(ForwardIterator first,
                                                               ForwardIterator last);  // constexpr in C++14

    template <class ForwardIterator, class Compare>
    std::pair<ForwardIterator, ForwardIterator> minmax_element(ForwardIterator first, ForwardIterator last,
                                                               Compare comp);  // constexpr in C++14

    template <class T>
    std::pair<const T&, const T&> minmax(const T& a, const T& b);  // constexpr in C++14

    template <class T, class Compare>
    std::pair<const T&, const T&> minmax(const T& a, const T& b, Compare comp);  // constexpr in C++14

    template <class T>
    std::pair<T, T> minmax(std::initializer_list<T> t);  // constexpr in C++14

    template <class T, class Compare>
    std::pair<T, T> minmax(std::initializer_list<T> t, Compare comp);  // constexpr in C++14

    template <class InputIterator1, class InputIterator2>
    constexpr bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
                                           InputIterator2 last2);

    template <class InputIterator1, class InputIterator2, class Compare>
    constexpr bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
                                           InputIterator2 last2, Compare comp);

    template <class BidirectionalIterator>
    bool next_permutation(BidirectionalIterator first, BidirectionalIterator last);

    template <class BidirectionalIterator, class Compare>
    bool next_permutation(BidirectionalIterator first, BidirectionalIterator last, Compare comp);

    template <class BidirectionalIterator>
    bool prev_permutation(BidirectionalIterator first, BidirectionalIterator last);

    template <class BidirectionalIterator, class Compare>
    bool prev_permutation(BidirectionalIterator first, BidirectionalIterator last, Compare comp);

}  // namespace GP
