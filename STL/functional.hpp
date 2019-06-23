﻿#ifndef FUNCTIONAL_HPP
#define FUNCTIONAL_HPP

#include "bits/stdc++.h"

namespace GP {

    template <class Arg, class Result>
    struct unary_function {
        typedef Arg argument_type;
        typedef Result result_type;
    };

    template <class Arg1, class Arg2, class Result>
    struct binary_function {
        typedef Arg1 first_argument_type;
        typedef Arg2 second_argument_type;
        typedef Result result_type;
    };

    template <class T, class T2, class R>
    class reference_wrapper : public unary_function<T, R>, public binary_function<T, T2, R> {
      public:
        // types
        typedef T type;
        typedef see below result_type;  // Not always defined

        // construct/copy/destroy
        reference_wrapper(T&) noexcept;
        reference_wrapper(T&&) = delete;  // do not bind to temps
        reference_wrapper(const reference_wrapper<T>& x) noexcept;

        // assignment
        reference_wrapper& operator=(const reference_wrapper<T>& x) noexcept;

        // access
        operator T&() const noexcept;
        T& get() const noexcept;

        // invoke
        template <class... ArgTypes>
        typename std::result_of<T&(ArgTypes&&...)>::type operator()(ArgTypes&&...) const;
    };

    template <class T>
    reference_wrapper<T> ref(T& t) noexcept;
    template <class T>
    void ref(const T&& t) = delete;
    template <class T>
    reference_wrapper<T> ref(reference_wrapper<T> t) noexcept;

    template <class T>
    reference_wrapper<const T> cref(const T& t) noexcept;
    template <class T>
    void cref(const T&& t) = delete;
    template <class T>
    reference_wrapper<const T> cref(reference_wrapper<T> t) noexcept;

    template <class T>
    struct unwrap_reference;  // since C++20
    template <class T>
    struct unwrap_ref_decay : unwrap_reference<decay_t<T>> {};  // since C++20
    template <class T>
    using unwrap_reference_t = typename unwrap_reference<T>::type;  // since C++20
    template <class T>
    using unwrap_ref_decay_t = typename unwrap_ref_decay<T>::type;  // since C++20

    template <class T>  // <class T=void> in C++14
    struct plus : binary_function<T, T, T> {
        T operator()(const T& x, const T& y) const;
    };

    template <class T>  // <class T=void> in C++14
    struct minus : binary_function<T, T, T> {
        T operator()(const T& x, const T& y) const;
    };

    template <class T>  // <class T=void> in C++14
    struct multiplies : binary_function<T, T, T> {
        T operator()(const T& x, const T& y) const;
    };

    template <class T>  // <class T=void> in C++14
    struct divides : binary_function<T, T, T> {
        T operator()(const T& x, const T& y) const;
    };

    template <class T>  // <class T=void> in C++14
    struct modulus : binary_function<T, T, T> {
        T operator()(const T& x, const T& y) const;
    };

    template <class T>  // <class T=void> in C++14
    struct negate : unary_function<T, T> {
        T operator()(const T& x) const;
    };

    template <class T>  // <class T=void> in C++14
    struct equal_to : binary_function<T, T, bool> {
        bool operator()(const T& x, const T& y) const;
    };

    template <class T>  // <class T=void> in C++14
    struct not_equal_to : binary_function<T, T, bool> {
        bool operator()(const T& x, const T& y) const;
    };

    template <class T>  // <class T=void> in C++14
    struct greater : binary_function<T, T, bool> {
        bool operator()(const T& x, const T& y) const;
    };

    template <class T>  // <class T=void> in C++14
    struct less : binary_function<T, T, bool> {
        bool operator()(const T& x, const T& y) const;
    };

    template <class T>  // <class T=void> in C++14
    struct greater_equal : binary_function<T, T, bool> {
        bool operator()(const T& x, const T& y) const;
    };

    template <class T>  // <class T=void> in C++14
    struct less_equal : binary_function<T, T, bool> {
        bool operator()(const T& x, const T& y) const;
    };

    template <class T>  // <class T=void> in C++14
    struct logical_and : binary_function<T, T, bool> {
        bool operator()(const T& x, const T& y) const;
    };

    template <class T>  // <class T=void> in C++14
    struct logical_or : binary_function<T, T, bool> {
        bool operator()(const T& x, const T& y) const;
    };

    template <class T>  // <class T=void> in C++14
    struct logical_not : unary_function<T, bool> {
        bool operator()(const T& x) const;
    };

    template <class T>  // <class T=void> in C++14
    struct bit_and : unary_function<T, bool> {
        bool operator()(const T& x, const T& y) const;
    };

    template <class T>  // <class T=void> in C++14
    struct bit_or : unary_function<T, bool> {
        bool operator()(const T& x, const T& y) const;
    };

    template <class T>  // <class T=void> in C++14
    struct bit_xor : unary_function<T, bool> {
        bool operator()(const T& x, const T& y) const;
    };

    template <class T = void>  // C++14
    struct bit_xor : unary_function<T, bool> {
        bool operator()(const T& x) const;
    };

    template <class Predicate>
    class unary_negate  // deprecated in C++17
        : public unary_function<typename Predicate::argument_type, bool> {
      public:
        explicit unary_negate(const Predicate& pred);
        bool operator()(const typename Predicate::argument_type& x) const;
    };

    template <class Predicate>  // deprecated in C++17
    unary_negate<Predicate> not1(const Predicate& pred);

    template <class Predicate>
    class binary_negate  // deprecated in C++17
        : public binary_function<typename Predicate::first_argument_type, typename Predicate::second_argument_type,
                                 bool> {
      public:
        explicit binary_negate(const Predicate& pred);
        bool operator()(const typename Predicate::first_argument_type& x,
                        const typename Predicate::second_argument_type& y) const;
    };

    template <class Predicate>  // deprecated in C++17
    binary_negate<Predicate> not2(const Predicate& pred);

    template <class F>
    unspecified not_fn(F&& f);  // C++17

    template <class T>
    struct is_bind_expression;
    template <class T>
    struct is_placeholder;

    // See C++14 20.9.9, Function object binders
    template <class T>
    inline constexpr bool is_bind_expression_v = is_bind_expression<T>::value;  // C++17
    template <class T>
    inline constexpr int is_placeholder_v = is_placeholder<T>::value;  // C++17

    template <class Fn, class... BoundArgs>
    unspecified bind(Fn&&, BoundArgs&&...);
    template <class R, class Fn, class... BoundArgs>
    unspecified bind(Fn&&, BoundArgs&&...);

    namespace placeholders {
        // M is the implementation-defined number of placeholders
        extern unspecified _1;
        extern unspecified _2;
        ... extern unspecified _Mp;
    }  // namespace placeholders

    template <class Operation>
    class binder1st  // deprecated in C++11, removed in C++17
        : public unary_function<typename Operation::second_argument_type, typename Operation::result_type> {
      protected:
        Operation op;
        typename Operation::first_argument_type value;

      public:
        binder1st(const Operation& x, const typename Operation::first_argument_type y);
        typename Operation::result_type operator()(typename Operation::second_argument_type& x) const;
        typename Operation::result_type operator()(const typename Operation::second_argument_type& x) const;
    };

    template <class Operation, class T>
    binder1st<Operation> bind1st(const Operation& op, const T& x);  // deprecated in C++11, removed in C++17

    template <class Operation>
    class binder2nd  // deprecated in C++11, removed in C++17
        : public unary_function<typename Operation::first_argument_type, typename Operation::result_type> {
      protected:
        Operation op;
        typename Operation::second_argument_type value;

      public:
        binder2nd(const Operation& x, const typename Operation::second_argument_type y);
        typename Operation::result_type operator()(typename Operation::first_argument_type& x) const;
        typename Operation::result_type operator()(const typename Operation::first_argument_type& x) const;
    };

    template <class Operation, class T>
    binder2nd<Operation> bind2nd(const Operation& op, const T& x);  // deprecated in C++11, removed in C++17

    template <class Arg, class Result>  // deprecated in C++11, removed in C++17
    class pointer_to_unary_function : public unary_function<Arg, Result> {
      public:
        explicit pointer_to_unary_function(Result (*f)(Arg));
        Result operator()(Arg x) const;
    };

    template <class Arg, class Result>
    pointer_to_unary_function<Arg, Result> ptr_fun(Result (*f)(Arg));  // deprecated in C++11, removed in C++17

    template <class Arg1, class Arg2, class Result>  // deprecated in C++11, removed in C++17
    class pointer_to_binary_function : public binary_function<Arg1, Arg2, Result> {
      public:
        explicit pointer_to_binary_function(Result (*f)(Arg1, Arg2));
        Result operator()(Arg1 x, Arg2 y) const;
    };

    template <class Arg1, class Arg2, class Result>
    pointer_to_binary_function<Arg1, Arg2, Result> ptr_fun(Result (*f)(Arg1, Arg2));  // deprecated in C++11, removed in

    template <class S, class T>  // deprecated in C++11, removed in C++17
    class mem_fun_t : public unary_function<T*, S> {
      public:
        explicit mem_fun_t(S (T::*p)());
        S operator()(T* p) const;
    };

    template <class S, class T, class A>
    class mem_fun1_t : public binary_function<T*, A, S>  // deprecated in C++11, removed in C++17
    {
      public:
        explicit mem_fun1_t(S (T::*p)(A));
        S operator()(T* p, A x) const;
    };

    template <class S, class T>
    mem_fun_t<S, T> mem_fun(S (T::*f)());  // deprecated in C++11, removed in
    template <class S, class T, class A>
    mem_fun1_t<S, T, A> mem_fun(S (T::*f)(A));  // deprecated in C++11, removed

    template <class S, class T>
    class mem_fun_ref_t : public unary_function<T, S>  // deprecated in C++11, removed in C++17
    {
      public:
        explicit mem_fun_ref_t(S (T::*p)());
        S operator()(T& p) const;
    };

    template <class S, class T, class A>
    class mem_fun1_ref_t : public binary_function<T, A, S>  // deprecated in C++11, removed in C++17
    {
      public:
        explicit mem_fun1_ref_t(S (T::*p)(A));
        S operator()(T& p, A x) const;
    };

    template <class S, class T>
    mem_fun_ref_t<S, T> mem_fun_ref(S (T::*f)());  // deprecated in C++11, removed
    template <class S, class T, class A>
    mem_fun1_ref_t<S, T, A> mem_fun_ref(S (T::*f)(A));  // deprecated in

    template <class S, class T>
    class const_mem_fun_t : public unary_function<const T*, S>  // deprecated in C++11, removed in C++17
    {
      public:
        explicit const_mem_fun_t(S (T::*p)() const);
        S operator()(const T* p) const;
    };

    template <class S, class T, class A>
    class const_mem_fun1_t : public binary_function<const T*, A, S>  // deprecated in C++11, removed in C++17
    {
      public:
        explicit const_mem_fun1_t(S (T::*p)(A) const);
        S operator()(const T* p, A x) const;
    };

    template <class S, class T>
    const_mem_fun_t<S, T> mem_fun(S (T::*f)() const);  // deprecated in C++11,
    template <class S, class T, class A>
    const_mem_fun1_t<S, T, A> mem_fun(S (T::*f)(A) const);  //

    template <class S, class T>
    class const_mem_fun_ref_t : public unary_function<T, S>  // deprecated in C++11, removed in C++17
    {
      public:
        explicit const_mem_fun_ref_t(S (T::*p)() const);
        S operator()(const T& p) const;
    };

    template <class S, class T, class A>
    class const_mem_fun1_ref_t : public binary_function<T, A, S>  // deprecated in C++11, removed in C++17
    {
      public:
        explicit const_mem_fun1_ref_t(S (T::*p)(A) const);
        S operator()(const T& p, A x) const;
    };

    template <class S, class T>
    const_mem_fun_ref_t<S, T> mem_fun_ref(S (T::*f)() const);  // deprecated in
    template <class S, class T, class A>
    const_mem_fun1_ref_t<S, T, A> mem_fun_ref(S (T::*f)(A) const);  // deprecated in C++11, remo ved in C++17

    template <class R, class T>
    unspecified mem_fn(R T::*);

    class bad_function_call : public exception {};

    template <class>
    class function;  // undefined

    template <class R, class... ArgTypes>
    class function<R(ArgTypes...)> : public unary_function<T1, R>  // iff sizeof...(ArgTypes) == 1 and
                                                                   // ArgTypes contains T1
        : public binary_function<T1, T2, R>                        // iff sizeof...(ArgTypes) == 2 and
                                                                   // ArgTypes contains T1 and T2
    {
      public:
        typedef R result_type;

        // construct/copy/destroy:
        function() noexcept;
        function(std::nullptr_t) noexcept;
        function(const function&);
        function(function&&) noexcept;
        template <class F>
        function(F);
        template <Allocator Alloc>
        function(allocator_arg_t, const Alloc&) noexcept;  // removed in C++17
        template <Allocator Alloc>
        function(allocator_arg_t, const Alloc&, std::nullptr_t) noexcept;  // removed in C++17
        template <Allocator Alloc>
        function(allocator_arg_t, const Alloc&, const function&);  // removed in C++17
        template <Allocator Alloc>
        function(allocator_arg_t, const Alloc&, function&&);  // removed in C++17
        template <class F, Allocator Alloc>
        function(allocator_arg_t, const Alloc&, F);  // removed in C++17

        function& operator=(const function&);
        function& operator=(function&&) noexcept;
        function& operator=(std::nullptr_t) noexcept;
        template <class F>
        function& operator=(F&&);
        template <class F>
        function& operator=(reference_wrapper<F>) noexcept;

        ~function();

        // function modifiers:
        void swap(function&) noexcept;
        template <class F, class Alloc>
        void assign(F&&, const Alloc&);  // Removed in C++17

        // function capacity:
        explicit operator bool() const noexcept;

        // function invocation:
        R operator()(ArgTypes...) const;

        // function target access:
        const std::type_info& target_type() const noexcept;
        template <typename T>
        T* target() noexcept;
        template <typename T>
        const T* target() const noexcept;
    };

    // Null pointer comparisons:
    template <class R, class... ArgTypes>
    bool operator==(const function<R(ArgTypes...)>&, std::nullptr_t) noexcept;

    template <class R, class... ArgTypes>
    bool operator==(std::nullptr_t, const function<R(ArgTypes...)>&) noexcept;

    template <class R, class... ArgTypes>
    bool operator!=(const function<R(ArgTypes...)>&, std::nullptr_t) noexcept;

    template <class R, class... ArgTypes>
    bool operator!=(std::nullptr_t, const function<R(ArgTypes...)>&) noexcept;

    // specialized algorithms:
    template <class R, class... ArgTypes>
    void swap(function<R(ArgTypes...)>&, function<R(ArgTypes...)>&) noexcept;

    template <class T>
    struct hash;

    template <>
    struct hash<bool>;
    template <>
    struct hash<char>;
    template <>
    struct hash<signed char>;
    template <>
    struct hash<unsigned char>;
    template <>
    struct hash<char16_t>;
    template <>
    struct hash<char32_t>;
    template <>
    struct hash<wchar_t>;
    template <>
    struct hash<short>;
    template <>
    struct hash<unsigned short>;
    template <>
    struct hash<int>;
    template <>
    struct hash<unsigned int>;
    template <>
    struct hash<long>;
    template <>
    struct hash<long long>;
    template <>
    struct hash<unsigned long>;
    template <>
    struct hash<unsigned long long>;

    template <>
    struct hash<float>;
    template <>
    struct hash<double>;
    template <>
    struct hash<long double>;

    template <class T>
    struct hash<T*>;
    template <>
    struct hash<std::nullptr_t>;  // C++17

    template <class _Tp = void>
    struct plus : binary_function<_Tp, _Tp, _Tp> {
        constexpr _Tp operator()(const _Tp& __x, const _Tp& __y) const {
            return __x + __y;
        }
    };

    template <>
    struct plus<void> {
        template <class _T1, class _T2>
        constexpr auto operator()(_T1&& __t, _T2&& __u) const
            _NOEXCEPT_(noexcept(_VSTD::forward<_T1>(__t) + _VSTD::forward<_T2>(__u)))
                -> decltype(_VSTD::forward<_T1>(__t) + _VSTD::forward<_T2>(__u)) {
            return _VSTD::forward<_T1>(__t) + _VSTD::forward<_T2>(__u);
        }
        typedef void is_transparent;
    };

    template <class _Tp = void>

    struct minus : binary_function<_Tp, _Tp, _Tp> {
        constexpr _Tp operator()(const _Tp& __x, const _Tp& __y) const {
            return __x - __y;
        }
    };

    template <>
    struct minus<void> {
        template <class _T1, class _T2>
        constexpr auto operator()(_T1&& __t, _T2&& __u) const
            _NOEXCEPT_(noexcept(_VSTD::forward<_T1>(__t) - _VSTD::forward<_T2>(__u)))
                -> decltype(_VSTD::forward<_T1>(__t) - _VSTD::forward<_T2>(__u)) {
            return _VSTD::forward<_T1>(__t) - _VSTD::forward<_T2>(__u);
        }
        typedef void is_transparent;
    };

    template <class _Tp = void>

    struct multiplies : binary_function<_Tp, _Tp, _Tp> {
        constexpr _Tp operator()(const _Tp& __x, const _Tp& __y) const {
            return __x * __y;
        }
    };

    template <>
    struct multiplies<void> {
        template <class _T1, class _T2>
        constexpr auto operator()(_T1&& __t, _T2&& __u) const
            _NOEXCEPT_(noexcept(_VSTD::forward<_T1>(__t) * _VSTD::forward<_T2>(__u)))
                -> decltype(_VSTD::forward<_T1>(__t) * _VSTD::forward<_T2>(__u)) {
            return _VSTD::forward<_T1>(__t) * _VSTD::forward<_T2>(__u);
        }
        typedef void is_transparent;
    };

    template <class _Tp = void>
    struct divides : binary_function<_Tp, _Tp, _Tp> {
        constexpr _Tp operator()(const _Tp& __x, const _Tp& __y) const {
            return __x / __y;
        }
    };

    template <>
    struct divides<void> {
        template <class _T1, class _T2>
        constexpr auto operator()(_T1&& __t, _T2&& __u) const
            _NOEXCEPT_(noexcept(_VSTD::forward<_T1>(__t) / _VSTD::forward<_T2>(__u)))
                -> decltype(_VSTD::forward<_T1>(__t) / _VSTD::forward<_T2>(__u)) {
            return _VSTD::forward<_T1>(__t) / _VSTD::forward<_T2>(__u);
        }
        typedef void is_transparent;
    };

    template <class _Tp = void>
    struct modulus : binary_function<_Tp, _Tp, _Tp> {
        constexpr _Tp operator()(const _Tp& __x, const _Tp& __y) const {
            return __x % __y;
        }
    };

    template <>
    struct modulus<void> {
        template <class _T1, class _T2>
        constexpr auto operator()(_T1&& __t, _T2&& __u) const
            _NOEXCEPT_(noexcept(_VSTD::forward<_T1>(__t) % _VSTD::forward<_T2>(__u)))
                -> decltype(_VSTD::forward<_T1>(__t) % _VSTD::forward<_T2>(__u)) {
            return _VSTD::forward<_T1>(__t) % _VSTD::forward<_T2>(__u);
        }
        typedef void is_transparent;
    };

    template <class _Tp = void>
    struct negate : unary_function<_Tp, _Tp> {
        constexpr _Tp operator()(const _Tp& __x) const {
            return -__x;
        }
    };

    template <>
    struct negate<void> {
        template <class _Tp>
        constexpr auto operator()(_Tp&& __x) const _NOEXCEPT_(noexcept(-_VSTD::forward<_Tp>(__x)))
            -> decltype(-_VSTD::forward<_Tp>(__x)) {
            return -_VSTD::forward<_Tp>(__x);
        }
        typedef void is_transparent;
    };

    template <class _Tp = void>
    struct equal_to : binary_function<_Tp, _Tp, bool> {
        constexpr bool operator()(const _Tp& __x, const _Tp& __y) const {
            return __x == __y;
        }
    };

    template <>
    struct equal_to<void> {
        template <class _T1, class _T2>
        constexpr auto operator()(_T1&& __t, _T2&& __u) const
            _NOEXCEPT_(noexcept(_VSTD::forward<_T1>(__t) == _VSTD::forward<_T2>(__u)))
                -> decltype(_VSTD::forward<_T1>(__t) == _VSTD::forward<_T2>(__u)) {
            return _VSTD::forward<_T1>(__t) == _VSTD::forward<_T2>(__u);
        }
        typedef void is_transparent;
    };

    template <class _Tp = void>
    struct not_equal_to : binary_function<_Tp, _Tp, bool> {
        constexpr bool operator()(const _Tp& __x, const _Tp& __y) const {
            return __x != __y;
        }
    };

    template <>
    struct not_equal_to<void> {
        template <class _T1, class _T2>
        constexpr auto operator()(_T1&& __t, _T2&& __u) const
            _NOEXCEPT_(noexcept(_VSTD::forward<_T1>(__t) != _VSTD::forward<_T2>(__u)))
                -> decltype(_VSTD::forward<_T1>(__t) != _VSTD::forward<_T2>(__u)) {
            return _VSTD::forward<_T1>(__t) != _VSTD::forward<_T2>(__u);
        }
        typedef void is_transparent;
    };

    template <class _Tp = void>
    struct greater : binary_function<_Tp, _Tp, bool> {
        constexpr bool operator()(const _Tp& __x, const _Tp& __y) const {
            return __x > __y;
        }
    };

    template <>
    struct greater<void> {
        template <class _T1, class _T2>
        constexpr auto operator()(_T1&& __t, _T2&& __u) const
            _NOEXCEPT_(noexcept(_VSTD::forward<_T1>(__t) > _VSTD::forward<_T2>(__u)))
                -> decltype(_VSTD::forward<_T1>(__t) > _VSTD::forward<_T2>(__u)) {
            return _VSTD::forward<_T1>(__t) > _VSTD::forward<_T2>(__u);
        }
        typedef void is_transparent;
    };

    // less in <__functional_base>

    template <class _Tp = void>
    struct greater_equal : binary_function<_Tp, _Tp, bool> {
        constexpr bool operator()(const _Tp& __x, const _Tp& __y) const {
            return __x >= __y;
        }
    };

    template <>
    struct greater_equal<void> {
        template <class _T1, class _T2>
        constexpr auto operator()(_T1&& __t, _T2&& __u) const
            _NOEXCEPT_(noexcept(_VSTD::forward<_T1>(__t) >= _VSTD::forward<_T2>(__u)))
                -> decltype(_VSTD::forward<_T1>(__t) >= _VSTD::forward<_T2>(__u)) {
            return _VSTD::forward<_T1>(__t) >= _VSTD::forward<_T2>(__u);
        }
        typedef void is_transparent;
    };

#if _LIBCPP_STD_VER > 11
    template <class _Tp = void>
#else
    template <class _Tp>
#endif
    struct less_equal : binary_function<_Tp, _Tp, bool> {
        constexpr bool operator()(const _Tp& __x, const _Tp& __y) const {
            return __x <= __y;
        }
    };

#if _LIBCPP_STD_VER > 11
    template <>
    struct less_equal<void> {
        template <class _T1, class _T2>
        constexpr auto operator()(_T1&& __t, _T2&& __u) const
            _NOEXCEPT_(noexcept(_VSTD::forward<_T1>(__t) <= _VSTD::forward<_T2>(__u)))
                -> decltype(_VSTD::forward<_T1>(__t) <= _VSTD::forward<_T2>(__u)) {
            return _VSTD::forward<_T1>(__t) <= _VSTD::forward<_T2>(__u);
        }
        typedef void is_transparent;
    };
#endif

#if _LIBCPP_STD_VER > 11
    template <class _Tp = void>
#else
    template <class _Tp>
#endif
    struct logical_and : binary_function<_Tp, _Tp, bool> {
        constexpr bool operator()(const _Tp& __x, const _Tp& __y) const {
            return __x && __y;
        }
    };

#if _LIBCPP_STD_VER > 11
    template <>
    struct logical_and<void> {
        template <class _T1, class _T2>
        constexpr auto operator()(_T1&& __t, _T2&& __u) const
            _NOEXCEPT_(noexcept(_VSTD::forward<_T1>(__t) && _VSTD::forward<_T2>(__u)))
                -> decltype(_VSTD::forward<_T1>(__t) && _VSTD::forward<_T2>(__u)) {
            return _VSTD::forward<_T1>(__t) && _VSTD::forward<_T2>(__u);
        }
        typedef void is_transparent;
    };
#endif

#if _LIBCPP_STD_VER > 11
    template <class _Tp = void>
#else
    template <class _Tp>
#endif
    struct logical_or : binary_function<_Tp, _Tp, bool> {
        constexpr bool operator()(const _Tp& __x, const _Tp& __y) const {
            return __x || __y;
        }
    };

#if _LIBCPP_STD_VER > 11
    template <>
    struct logical_or<void> {
        template <class _T1, class _T2>
        constexpr auto operator()(_T1&& __t, _T2&& __u) const
            _NOEXCEPT_(noexcept(_VSTD::forward<_T1>(__t) || _VSTD::forward<_T2>(__u)))
                -> decltype(_VSTD::forward<_T1>(__t) || _VSTD::forward<_T2>(__u)) {
            return _VSTD::forward<_T1>(__t) || _VSTD::forward<_T2>(__u);
        }
        typedef void is_transparent;
    };
#endif

#if _LIBCPP_STD_VER > 11
    template <class _Tp = void>
#else
    template <class _Tp>
#endif
    struct logical_not : unary_function<_Tp, bool> {
        constexpr bool operator()(const _Tp& __x) const {
            return !__x;
        }
    };

#if _LIBCPP_STD_VER > 11
    template <>
    struct logical_not<void> {
        template <class _Tp>
        constexpr auto operator()(_Tp&& __x) const _NOEXCEPT_(noexcept(!_VSTD::forward<_Tp>(__x)))
            -> decltype(!_VSTD::forward<_Tp>(__x)) {
            return !_VSTD::forward<_Tp>(__x);
        }
        typedef void is_transparent;
    };
#endif

#if _LIBCPP_STD_VER > 11
    template <class _Tp = void>
#else
    template <class _Tp>
#endif
    struct bit_and : binary_function<_Tp, _Tp, _Tp> {
        constexpr _Tp operator()(const _Tp& __x, const _Tp& __y) const {
            return __x & __y;
        }
    };

#if _LIBCPP_STD_VER > 11
    template <>
    struct bit_and<void> {
        template <class _T1, class _T2>
        constexpr auto operator()(_T1&& __t, _T2&& __u) const
            _NOEXCEPT_(noexcept(_VSTD::forward<_T1>(__t) & _VSTD::forward<_T2>(__u)))
                -> decltype(_VSTD::forward<_T1>(__t) & _VSTD::forward<_T2>(__u)) {
            return _VSTD::forward<_T1>(__t) & _VSTD::forward<_T2>(__u);
        }
        typedef void is_transparent;
    };
#endif

#if _LIBCPP_STD_VER > 11
    template <class _Tp = void>
#else
    template <class _Tp>
#endif
    struct bit_or : binary_function<_Tp, _Tp, _Tp> {
        constexpr _Tp operator()(const _Tp& __x, const _Tp& __y) const {
            return __x | __y;
        }
    };

#if _LIBCPP_STD_VER > 11
    template <>
    struct bit_or<void> {
        template <class _T1, class _T2>
        constexpr auto operator()(_T1&& __t, _T2&& __u) const
            _NOEXCEPT_(noexcept(_VSTD::forward<_T1>(__t) | _VSTD::forward<_T2>(__u)))
                -> decltype(_VSTD::forward<_T1>(__t) | _VSTD::forward<_T2>(__u)) {
            return _VSTD::forward<_T1>(__t) | _VSTD::forward<_T2>(__u);
        }
        typedef void is_transparent;
    };
#endif

#if _LIBCPP_STD_VER > 11
    template <class _Tp = void>
#else
    template <class _Tp>
#endif
    struct bit_xor : binary_function<_Tp, _Tp, _Tp> {
        constexpr _Tp operator()(const _Tp& __x, const _Tp& __y) const {
            return __x ^ __y;
        }
    };

#if _LIBCPP_STD_VER > 11
    template <>
    struct bit_xor<void> {
        template <class _T1, class _T2>
        constexpr auto operator()(_T1&& __t, _T2&& __u) const
            _NOEXCEPT_(noexcept(_VSTD::forward<_T1>(__t) ^ _VSTD::forward<_T2>(__u)))
                -> decltype(_VSTD::forward<_T1>(__t) ^ _VSTD::forward<_T2>(__u)) {
            return _VSTD::forward<_T1>(__t) ^ _VSTD::forward<_T2>(__u);
        }
        typedef void is_transparent;
    };
#endif

#if _LIBCPP_STD_VER > 11
    template <class _Tp = void>
    struct bit_not : unary_function<_Tp, _Tp> {
        constexpr _Tp operator()(const _Tp& __x) const {
            return ~__x;
        }
    };

    template <>
    struct bit_not<void> {
        template <class _Tp>
        constexpr auto operator()(_Tp&& __x) const _NOEXCEPT_(noexcept(~_VSTD::forward<_Tp>(__x)))
            -> decltype(~_VSTD::forward<_Tp>(__x)) {
            return ~_VSTD::forward<_Tp>(__x);
        }
        typedef void is_transparent;
    };
#endif

    template <class _Predicate>
    class _LIBCPP_DEPRECATED_IN_CXX17 unary_negate : public unary_function<typename _Predicate::argument_type, bool> {
        _Predicate __pred_;

      public:
        constexpr explicit unary_negate(const _Predicate& __pred) : __pred_(__pred) {
        }
        constexpr bool operator()(const typename _Predicate::argument_type& __x) const {
            return !__pred_(__x);
        }
    };

    template <class _Predicate>
    _LIBCPP_DEPRECATED_IN_CXX17 inline constexpr unary_negate<_Predicate> not1(const _Predicate& __pred) {
        return unary_negate<_Predicate>(__pred);
    }

    template <class _Predicate>
    class _LIBCPP_DEPRECATED_IN_CXX17 binary_negate
        : public binary_function<typename _Predicate::first_argument_type, typename _Predicate::second_argument_type,
                                 bool> {
        _Predicate __pred_;

      public:
        explicit constexpr binary_negate(const _Predicate& __pred) : __pred_(__pred) {
        }

        constexpr bool operator()(const typename _Predicate::first_argument_type& __x,
                                  const typename _Predicate::second_argument_type& __y) const {
            return !__pred_(__x, __y);
        }
    };

    template <class _Predicate>
    _LIBCPP_DEPRECATED_IN_CXX17 inline constexpr binary_negate<_Predicate> not2(const _Predicate& __pred) {
        return binary_negate<_Predicate>(__pred);
    }

#if _LIBCPP_STD_VER <= 14 || defined(_LIBCPP_ENABLE_CXX17_REMOVED_BINDERS)
    template <class __Operation>
    class _LIBCPP_DEPRECATED_IN_CXX11 binder1st
        : public unary_function<typename __Operation::second_argument_type, typename __Operation::result_type> {
      protected:
        __Operation op;
        typename __Operation::first_argument_type value;

      public:
        binder1st(const __Operation& __x, const typename __Operation::first_argument_type __y) : op(__x), value(__y) {
        }
        typename __Operation::result_type operator()(typename __Operation::second_argument_type& __x) const {
            return op(value, __x);
        }
        typename __Operation::result_type operator()(const typename __Operation::second_argument_type& __x) const {
            return op(value, __x);
        }
    };

    template <class __Operation, class _Tp>
    _LIBCPP_DEPRECATED_IN_CXX11 inline binder1st<__Operation> bind1st(const __Operation& __op, const _Tp& __x) {
        return binder1st<__Operation>(__op, __x);
    }

    template <class __Operation>
    class _LIBCPP_DEPRECATED_IN_CXX11 binder2nd
        : public unary_function<typename __Operation::first_argument_type, typename __Operation::result_type> {
      protected:
        __Operation op;
        typename __Operation::second_argument_type value;

      public:
        binder2nd(const __Operation& __x, const typename __Operation::second_argument_type __y) : op(__x), value(__y) {
        }
        typename __Operation::result_type operator()(typename __Operation::first_argument_type& __x) const {
            return op(__x, value);
        }
        typename __Operation::result_type operator()(const typename __Operation::first_argument_type& __x) const {
            return op(__x, value);
        }
    };

    template <class __Operation, class _Tp>
    _LIBCPP_DEPRECATED_IN_CXX11 inline binder2nd<__Operation> bind2nd(const __Operation& __op, const _Tp& __x) {
        return binder2nd<__Operation>(__op, __x);
    }

    template <class _Arg, class _Result>
    class _LIBCPP_DEPRECATED_IN_CXX11 pointer_to_unary_function : public unary_function<_Arg, _Result> {
        _Result (*__f_)(_Arg);

      public:
        explicit pointer_to_unary_function(_Result (*__f)(_Arg)) : __f_(__f) {
        }
        _Result operator()(_Arg __x) const {
            return __f_(__x);
        }
    };

    template <class _Arg, class _Result>
    _LIBCPP_DEPRECATED_IN_CXX11 inline pointer_to_unary_function<_Arg, _Result> ptr_fun(_Result (*__f)(_Arg)) {
        return pointer_to_unary_function<_Arg, _Result>(__f);
    }

    template <class _Arg1, class _Arg2, class _Result>
    class _LIBCPP_DEPRECATED_IN_CXX11 pointer_to_binary_function : public binary_function<_Arg1, _Arg2, _Result> {
        _Result (*__f_)(_Arg1, _Arg2);

      public:
        explicit pointer_to_binary_function(_Result (*__f)(_Arg1, _Arg2)) : __f_(__f) {
        }
        _Result operator()(_Arg1 __x, _Arg2 __y) const {
            return __f_(__x, __y);
        }
    };

    template <class _Arg1, class _Arg2, class _Result>
    _LIBCPP_DEPRECATED_IN_CXX11 inline pointer_to_binary_function<_Arg1, _Arg2, _Result> ptr_fun(
        _Result (*__f)(_Arg1, _Arg2)) {
        return pointer_to_binary_function<_Arg1, _Arg2, _Result>(__f);
    }

    template <class _Sp, class _Tp>
    class _LIBCPP_DEPRECATED_IN_CXX11 mem_fun_t : public unary_function<_Tp*, _Sp> {
        _Sp (_Tp::*__p_)();

      public:
        explicit mem_fun_t(_Sp (_Tp::*__p)()) : __p_(__p) {
        }
        _Sp operator()(_Tp* __p) const {
            return (__p->*__p_)();
        }
    };

    template <class _Sp, class _Tp, class _Ap>
    class _LIBCPP_DEPRECATED_IN_CXX11 mem_fun1_t : public binary_function<_Tp*, _Ap, _Sp> {
        _Sp (_Tp::*__p_)(_Ap);

      public:
        explicit mem_fun1_t(_Sp (_Tp::*__p)(_Ap)) : __p_(__p) {
        }
        _Sp operator()(_Tp* __p, _Ap __x) const {
            return (__p->*__p_)(__x);
        }
    };

    template <class _Sp, class _Tp>
    _LIBCPP_DEPRECATED_IN_CXX11 inline mem_fun_t<_Sp, _Tp> mem_fun(_Sp (_Tp::*__f)()) {
        return mem_fun_t<_Sp, _Tp>(__f);
    }

    template <class _Sp, class _Tp, class _Ap>
    _LIBCPP_DEPRECATED_IN_CXX11 inline mem_fun1_t<_Sp, _Tp, _Ap> mem_fun(_Sp (_Tp::*__f)(_Ap)) {
        return mem_fun1_t<_Sp, _Tp, _Ap>(__f);
    }

    template <class _Sp, class _Tp>
    class _LIBCPP_DEPRECATED_IN_CXX11 mem_fun_ref_t : public unary_function<_Tp, _Sp> {
        _Sp (_Tp::*__p_)();

      public:
        explicit mem_fun_ref_t(_Sp (_Tp::*__p)()) : __p_(__p) {
        }
        _Sp operator()(_Tp& __p) const {
            return (__p.*__p_)();
        }
    };

    template <class _Sp, class _Tp, class _Ap>
    class _LIBCPP_DEPRECATED_IN_CXX11 mem_fun1_ref_t : public binary_function<_Tp, _Ap, _Sp> {
        _Sp (_Tp::*__p_)(_Ap);

      public:
        explicit mem_fun1_ref_t(_Sp (_Tp::*__p)(_Ap)) : __p_(__p) {
        }
        _Sp operator()(_Tp& __p, _Ap __x) const {
            return (__p.*__p_)(__x);
        }
    };

    template <class _Sp, class _Tp>
    _LIBCPP_DEPRECATED_IN_CXX11 inline mem_fun_ref_t<_Sp, _Tp> mem_fun_ref(_Sp (_Tp::*__f)()) {
        return mem_fun_ref_t<_Sp, _Tp>(__f);
    }

    template <class _Sp, class _Tp, class _Ap>
    _LIBCPP_DEPRECATED_IN_CXX11 inline mem_fun1_ref_t<_Sp, _Tp, _Ap> mem_fun_ref(_Sp (_Tp::*__f)(_Ap)) {
        return mem_fun1_ref_t<_Sp, _Tp, _Ap>(__f);
    }

    template <class _Sp, class _Tp>
    class _LIBCPP_DEPRECATED_IN_CXX11 const_mem_fun_t : public unary_function<const _Tp*, _Sp> {
        _Sp (_Tp::*__p_)() const;

      public:
        explicit const_mem_fun_t(_Sp (_Tp::*__p)() const) : __p_(__p) {
        }
        _Sp operator()(const _Tp* __p) const {
            return (__p->*__p_)();
        }
    };

    template <class _Sp, class _Tp, class _Ap>
    class _LIBCPP_DEPRECATED_IN_CXX11 const_mem_fun1_t : public binary_function<const _Tp*, _Ap, _Sp> {
        _Sp (_Tp::*__p_)(_Ap) const;

      public:
        explicit const_mem_fun1_t(_Sp (_Tp::*__p)(_Ap) const) : __p_(__p) {
        }
        _Sp operator()(const _Tp* __p, _Ap __x) const {
            return (__p->*__p_)(__x);
        }
    };

    template <class _Sp, class _Tp>
    _LIBCPP_DEPRECATED_IN_CXX11 inline const_mem_fun_t<_Sp, _Tp> mem_fun(_Sp (_Tp::*__f)() const) {
        return const_mem_fun_t<_Sp, _Tp>(__f);
    }

    template <class _Sp, class _Tp, class _Ap>
    _LIBCPP_DEPRECATED_IN_CXX11 inline const_mem_fun1_t<_Sp, _Tp, _Ap> mem_fun(_Sp (_Tp::*__f)(_Ap) const) {
        return const_mem_fun1_t<_Sp, _Tp, _Ap>(__f);
    }

    template <class _Sp, class _Tp>
    class _LIBCPP_DEPRECATED_IN_CXX11 const_mem_fun_ref_t : public unary_function<_Tp, _Sp> {
        _Sp (_Tp::*__p_)() const;

      public:
        explicit const_mem_fun_ref_t(_Sp (_Tp::*__p)() const) : __p_(__p) {
        }
        _Sp operator()(const _Tp& __p) const {
            return (__p.*__p_)();
        }
    };

    template <class _Sp, class _Tp, class _Ap>
    class _LIBCPP_DEPRECATED_IN_CXX11 const_mem_fun1_ref_t : public binary_function<_Tp, _Ap, _Sp> {
        _Sp (_Tp::*__p_)(_Ap) const;

      public:
        explicit const_mem_fun1_ref_t(_Sp (_Tp::*__p)(_Ap) const) : __p_(__p) {
        }
        _Sp operator()(const _Tp& __p, _Ap __x) const {
            return (__p.*__p_)(__x);
        }
    };

    template <class _Sp, class _Tp>
    _LIBCPP_DEPRECATED_IN_CXX11 inline const_mem_fun_ref_t<_Sp, _Tp> mem_fun_ref(_Sp (_Tp::*__f)() const) {
        return const_mem_fun_ref_t<_Sp, _Tp>(__f);
    }

    template <class _Sp, class _Tp, class _Ap>
    _LIBCPP_DEPRECATED_IN_CXX11 inline const_mem_fun1_ref_t<_Sp, _Tp, _Ap> mem_fun_ref(_Sp (_Tp::*__f)(_Ap) const) {
        return const_mem_fun1_ref_t<_Sp, _Tp, _Ap>(__f);
    }
#endif

    ////////////////////////////////////////////////////////////////////////////////
    //                                MEMFUN
    //==============================================================================

    template <class _Tp>
    class __mem_fn : public __weak_result_type<_Tp> {
      public:
        // types
        typedef _Tp type;

      private:
        type __f_;

      public:
        __mem_fn(type __f) _NOEXCEPT : __f_(__f) {
        }

#ifndef _LIBCPP_CXX03_LANG
        // invoke
        template <class... _ArgTypes>
        typename __invoke_return<type, _ArgTypes...>::type operator()(_ArgTypes&&... __args) const {
            return __invoke(__f_, _VSTD::forward<_ArgTypes>(__args)...);
        }
#else

        template <class _A0>
        typename __invoke_return0<type, _A0>::type operator()(_A0& __a0) const {
            return __invoke(__f_, __a0);
        }

        template <class _A0>
        typename __invoke_return0<type, _A0 const>::type operator()(_A0 const& __a0) const {
            return __invoke(__f_, __a0);
        }

        template <class _A0, class _A1>
        typename __invoke_return1<type, _A0, _A1>::type operator()(_A0& __a0, _A1& __a1) const {
            return __invoke(__f_, __a0, __a1);
        }

        template <class _A0, class _A1>
        typename __invoke_return1<type, _A0 const, _A1>::type operator()(_A0 const& __a0, _A1& __a1) const {
            return __invoke(__f_, __a0, __a1);
        }

        template <class _A0, class _A1>
        typename __invoke_return1<type, _A0, _A1 const>::type operator()(_A0& __a0, _A1 const& __a1) const {
            return __invoke(__f_, __a0, __a1);
        }

        template <class _A0, class _A1>
        typename __invoke_return1<type, _A0 const, _A1 const>::type operator()(_A0 const& __a0, _A1 const& __a1) const {
            return __invoke(__f_, __a0, __a1);
        }

        template <class _A0, class _A1, class _A2>
        typename __invoke_return2<type, _A0, _A1, _A2>::type operator()(_A0& __a0, _A1& __a1, _A2& __a2) const {
            return __invoke(__f_, __a0, __a1, __a2);
        }

        template <class _A0, class _A1, class _A2>
        typename __invoke_return2<type, _A0 const, _A1, _A2>::type operator()(_A0 const& __a0, _A1& __a1,
                                                                              _A2& __a2) const {
            return __invoke(__f_, __a0, __a1, __a2);
        }

        template <class _A0, class _A1, class _A2>
        typename __invoke_return2<type, _A0, _A1 const, _A2>::type operator()(_A0& __a0, _A1 const& __a1,
                                                                              _A2& __a2) const {
            return __invoke(__f_, __a0, __a1, __a2);
        }

        template <class _A0, class _A1, class _A2>
        typename __invoke_return2<type, _A0, _A1, _A2 const>::type operator()(_A0& __a0, _A1& __a1,
                                                                              _A2 const& __a2) const {
            return __invoke(__f_, __a0, __a1, __a2);
        }

        template <class _A0, class _A1, class _A2>
        typename __invoke_return2<type, _A0 const, _A1 const, _A2>::type operator()(_A0 const& __a0, _A1 const& __a1,
                                                                                    _A2& __a2) const {
            return __invoke(__f_, __a0, __a1, __a2);
        }

        template <class _A0, class _A1, class _A2>
        typename __invoke_return2<type, _A0 const, _A1, _A2 const>::type operator()(_A0 const& __a0, _A1& __a1,
                                                                                    _A2 const& __a2) const {
            return __invoke(__f_, __a0, __a1, __a2);
        }

        template <class _A0, class _A1, class _A2>
        typename __invoke_return2<type, _A0, _A1 const, _A2 const>::type operator()(_A0& __a0, _A1 const& __a1,
                                                                                    _A2 const& __a2) const {
            return __invoke(__f_, __a0, __a1, __a2);
        }

        template <class _A0, class _A1, class _A2>
        typename __invoke_return2<type, _A0 const, _A1 const, _A2 const>::type operator()(_A0 const& __a0,
                                                                                          _A1 const& __a1,
                                                                                          _A2 const& __a2) const {
            return __invoke(__f_, __a0, __a1, __a2);
        }
#endif
    };

    template <class _Rp, class _Tp>
    inline __mem_fn<_Rp _Tp::*> mem_fn(_Rp _Tp::*__pm) _NOEXCEPT {
        return __mem_fn<_Rp _Tp::*>(__pm);
    }

    ////////////////////////////////////////////////////////////////////////////////
    //                                FUNCTION
    //==============================================================================

    // bad_function_call

    class _LIBCPP_EXCEPTION_ABI bad_function_call : public exception {
#ifdef _LIBCPP_ABI_BAD_FUNCTION_CALL_KEY_FUNCTION
      public:
        virtual ~bad_function_call() _NOEXCEPT;

        virtual const char* what() const _NOEXCEPT;
#endif
    };

    _LIBCPP_NORETURN inline void __throw_bad_function_call() {
#ifndef _LIBCPP_NO_EXCEPTIONS
        throw bad_function_call();
#else
        _VSTD::abort();
#endif
    }

    template <class _Fp>
    class function;  // undefined

    namespace __function {

        template <class _Rp>
        struct __maybe_derive_from_unary_function {};

        template <class _Rp, class _A1>
        struct __maybe_derive_from_unary_function<_Rp(_A1)> : public unary_function<_A1, _Rp> {};

        template <class _Rp>
        struct __maybe_derive_from_binary_function {};

        template <class _Rp, class _A1, class _A2>
        struct __maybe_derive_from_binary_function<_Rp(_A1, _A2)> : public binary_function<_A1, _A2, _Rp> {};

        template <class _Fp>
        bool __not_null(_Fp const&) {
            return true;
        }

        template <class _Fp>
        bool __not_null(_Fp* __ptr) {
            return __ptr;
        }

        template <class _Ret, class _Class>
        bool __not_null(_Ret _Class::*__ptr) {
            return __ptr;
        }

        template <class _Fp>
        bool __not_null(function<_Fp> const& __f) {
            return !!__f;
        }

    }  // namespace __function

#ifndef _LIBCPP_CXX03_LANG

    namespace __function {

        // __alloc_func holds a functor and an allocator.

        template <class _Fp, class _Ap, class _FB>
        class __alloc_func;

        template <class _Fp, class _Ap, class _Rp, class... _ArgTypes>
        class __alloc_func<_Fp, _Ap, _Rp(_ArgTypes...)> {
            __compressed_pair<_Fp, _Ap> __f_;

          public:
            typedef _Fp _Target;
            typedef _Ap _Alloc;

            const _Target& __target() const {
                return __f_.first();
            }

            const _Alloc& __allocator() const {
                return __f_.second();
            }

            explicit __alloc_func(_Target&& __f)
                : __f_(piecewise_construct, _VSTD::forward_as_tuple(_VSTD::move(__f)), _VSTD::forward_as_tuple()) {
            }

            explicit __alloc_func(const _Target& __f, const _Alloc& __a)
                : __f_(piecewise_construct, _VSTD::forward_as_tuple(__f), _VSTD::forward_as_tuple(__a)) {
            }

            explicit __alloc_func(const _Target& __f, _Alloc&& __a)
                : __f_(piecewise_construct, _VSTD::forward_as_tuple(__f), _VSTD::forward_as_tuple(_VSTD::move(__a))) {
            }

            explicit __alloc_func(_Target&& __f, _Alloc&& __a)
                : __f_(piecewise_construct, _VSTD::forward_as_tuple(_VSTD::move(__f)),
                       _VSTD::forward_as_tuple(_VSTD::move(__a))) {
            }

            _Rp operator()(_ArgTypes&&... __arg) {
                typedef __invoke_void_return_wrapper<_Rp> _Invoker;
                return _Invoker::__call(__f_.first(), _VSTD::forward<_ArgTypes>(__arg)...);
            }

            __alloc_func* __clone() const {
                typedef allocator_traits<_Alloc> __alloc_traits;
                typedef typename __rebind_alloc_helper<__alloc_traits, __alloc_func>::type _AA;
                _AA __a(__f_.second());
                typedef __allocator_destructor<_AA> _Dp;
                unique_ptr<__alloc_func, _Dp> __hold(__a.allocate(1), _Dp(__a, 1));
                ::new ((void*)__hold.get()) __alloc_func(__f_.first(), _Alloc(__a));
                return __hold.release();
            }

            void destroy() _NOEXCEPT {
                __f_.~__compressed_pair<_Target, _Alloc>();
            }
        };

        // __base provides an abstract interface for copyable functors.

        template <class _Fp>
        class __base;

        template <class _Rp, class... _ArgTypes>
        class __base<_Rp(_ArgTypes...)> {
            __base(const __base&);
            __base& operator=(const __base&);

          public:
            __base() {
            }
            virtual ~__base() {
            }
            virtual __base* __clone() const = 0;
            virtual void __clone(__base*) const = 0;
            virtual void destroy() _NOEXCEPT = 0;
            virtual void destroy_deallocate() _NOEXCEPT = 0;
            virtual _Rp operator()(_ArgTypes&&...) = 0;
#    ifndef _LIBCPP_NO_RTTI
            virtual const void* target(const type_info&) const _NOEXCEPT = 0;
            virtual const std::type_info& target_type() const _NOEXCEPT = 0;
#    endif  // _LIBCPP_NO_RTTI
        };

        // __func implements __base for a given functor type.

        template <class _FD, class _Alloc, class _FB>
        class __func;

        template <class _Fp, class _Alloc, class _Rp, class... _ArgTypes>
        class __func<_Fp, _Alloc, _Rp(_ArgTypes...)> : public __base<_Rp(_ArgTypes...)> {
            __alloc_func<_Fp, _Alloc, _Rp(_ArgTypes...)> __f_;

          public:
            explicit __func(_Fp&& __f) : __f_(_VSTD::move(__f)) {
            }

            explicit __func(const _Fp& __f, const _Alloc& __a) : __f_(__f, __a) {
            }

            explicit __func(const _Fp& __f, _Alloc&& __a) : __f_(__f, _VSTD::move(__a)) {
            }

            explicit __func(_Fp&& __f, _Alloc&& __a) : __f_(_VSTD::move(__f), _VSTD::move(__a)) {
            }

            virtual __base<_Rp(_ArgTypes...)>* __clone() const;
            virtual void __clone(__base<_Rp(_ArgTypes...)>*) const;
            virtual void destroy() _NOEXCEPT;
            virtual void destroy_deallocate() _NOEXCEPT;
            virtual _Rp operator()(_ArgTypes&&... __arg);
#    ifndef _LIBCPP_NO_RTTI
            virtual const void* target(const type_info&) const _NOEXCEPT;
            virtual const std::type_info& target_type() const _NOEXCEPT;
#    endif  // _LIBCPP_NO_RTTI
        };

        template <class _Fp, class _Alloc, class _Rp, class... _ArgTypes>
        __base<_Rp(_ArgTypes...)>* __func<_Fp, _Alloc, _Rp(_ArgTypes...)>::__clone() const {
            typedef allocator_traits<_Alloc> __alloc_traits;
            typedef typename __rebind_alloc_helper<__alloc_traits, __func>::type _Ap;
            _Ap __a(__f_.__allocator());
            typedef __allocator_destructor<_Ap> _Dp;
            unique_ptr<__func, _Dp> __hold(__a.allocate(1), _Dp(__a, 1));
            ::new ((void*)__hold.get()) __func(__f_.__target(), _Alloc(__a));
            return __hold.release();
        }

        template <class _Fp, class _Alloc, class _Rp, class... _ArgTypes>
        void __func<_Fp, _Alloc, _Rp(_ArgTypes...)>::__clone(__base<_Rp(_ArgTypes...)>* __p) const {
            ::new (__p) __func(__f_.__target(), __f_.__allocator());
        }

        template <class _Fp, class _Alloc, class _Rp, class... _ArgTypes>
        void __func<_Fp, _Alloc, _Rp(_ArgTypes...)>::destroy() _NOEXCEPT {
            __f_.destroy();
        }

        template <class _Fp, class _Alloc, class _Rp, class... _ArgTypes>
        void __func<_Fp, _Alloc, _Rp(_ArgTypes...)>::destroy_deallocate() _NOEXCEPT {
            typedef allocator_traits<_Alloc> __alloc_traits;
            typedef typename __rebind_alloc_helper<__alloc_traits, __func>::type _Ap;
            _Ap __a(__f_.__allocator());
            __f_.destroy();
            __a.deallocate(this, 1);
        }

        template <class _Fp, class _Alloc, class _Rp, class... _ArgTypes>
        _Rp __func<_Fp, _Alloc, _Rp(_ArgTypes...)>::operator()(_ArgTypes&&... __arg) {
            return __f_(_VSTD::forward<_ArgTypes>(__arg)...);
        }

#    ifndef _LIBCPP_NO_RTTI

        template <class _Fp, class _Alloc, class _Rp, class... _ArgTypes>
        const void* __func<_Fp, _Alloc, _Rp(_ArgTypes...)>::target(const type_info& __ti) const _NOEXCEPT {
            if (__ti == typeid(_Fp))
                return &__f_.__target();
            return (const void*)0;
        }

        template <class _Fp, class _Alloc, class _Rp, class... _ArgTypes>
        const std::type_info& __func<_Fp, _Alloc, _Rp(_ArgTypes...)>::target_type() const _NOEXCEPT {
            return typeid(_Fp);
        }

#    endif  // _LIBCPP_NO_RTTI

        // __value_func creates a value-type from a __func.

        template <class _Fp>
        class __value_func;

        template <class _Rp, class... _ArgTypes>
        class __value_func<_Rp(_ArgTypes...)> {
            typename aligned_storage<3 * sizeof(void*)>::type __buf_;

            typedef __base<_Rp(_ArgTypes...)> __func;
            __func* __f_;

            _LIBCPP_NO_CFI static __func* __as_base(void* p) {
                return reinterpret_cast<__func*>(p);
            }

          public:
            __value_func() _NOEXCEPT : __f_(0) {
            }

            template <class _Fp, class _Alloc>
            __value_func(_Fp&& __f, const _Alloc __a) : __f_(0) {
                typedef allocator_traits<_Alloc> __alloc_traits;
                typedef __function::__func<_Fp, _Alloc, _Rp(_ArgTypes...)> _Fun;
                typedef typename __rebind_alloc_helper<__alloc_traits, _Fun>::type _FunAlloc;

                if (__function::__not_null(__f)) {
                    _FunAlloc __af(__a);
                    if (sizeof(_Fun) <= sizeof(__buf_) && is_nothrow_copy_constructible<_Fp>::value &&
                        is_nothrow_copy_constructible<_FunAlloc>::value) {
                        __f_ = ::new ((void*)&__buf_) _Fun(_VSTD::move(__f), _Alloc(__af));
                    } else {
                        typedef __allocator_destructor<_FunAlloc> _Dp;
                        unique_ptr<__func, _Dp> __hold(__af.allocate(1), _Dp(__af, 1));
                        ::new ((void*)__hold.get()) _Fun(_VSTD::move(__f), _Alloc(__a));
                        __f_ = __hold.release();
                    }
                }
            }

            __value_func(const __value_func& __f) {
                if (__f.__f_ == 0)
                    __f_ = 0;
                else if ((void*)__f.__f_ == &__f.__buf_) {
                    __f_ = __as_base(&__buf_);
                    __f.__f_->__clone(__f_);
                } else
                    __f_ = __f.__f_->__clone();
            }

            __value_func(__value_func&& __f) _NOEXCEPT {
                if (__f.__f_ == 0)
                    __f_ = 0;
                else if ((void*)__f.__f_ == &__f.__buf_) {
                    __f_ = __as_base(&__buf_);
                    __f.__f_->__clone(__f_);
                } else {
                    __f_ = __f.__f_;
                    __f.__f_ = 0;
                }
            }

            ~__value_func() {
                if ((void*)__f_ == &__buf_)
                    __f_->destroy();
                else if (__f_)
                    __f_->destroy_deallocate();
            }

            __value_func& operator=(__value_func&& __f) {
                *this = nullptr;
                if (__f.__f_ == 0)
                    __f_ = 0;
                else if ((void*)__f.__f_ == &__f.__buf_) {
                    __f_ = __as_base(&__buf_);
                    __f.__f_->__clone(__f_);
                } else {
                    __f_ = __f.__f_;
                    __f.__f_ = 0;
                }
                return *this;
            }

            __value_func& operator=(std::nullptr_t) {
                __func* __f = __f_;
                __f_ = 0;
                if ((void*)__f == &__buf_)
                    __f->destroy();
                else if (__f)
                    __f->destroy_deallocate();
                return *this;
            }

            _Rp operator()(_ArgTypes&&... __args) const {
                if (__f_ == 0)
                    __throw_bad_function_call();
                return (*__f_)(_VSTD::forward<_ArgTypes>(__args)...);
            }

            void swap(__value_func& __f) _NOEXCEPT {
                if (&__f == this)
                    return;
                if ((void*)__f_ == &__buf_ && (void*)__f.__f_ == &__f.__buf_) {
                    typename aligned_storage<sizeof(__buf_)>::type __tempbuf;
                    __func* __t = __as_base(&__tempbuf);
                    __f_->__clone(__t);
                    __f_->destroy();
                    __f_ = 0;
                    __f.__f_->__clone(__as_base(&__buf_));
                    __f.__f_->destroy();
                    __f.__f_ = 0;
                    __f_ = __as_base(&__buf_);
                    __t->__clone(__as_base(&__f.__buf_));
                    __t->destroy();
                    __f.__f_ = __as_base(&__f.__buf_);
                } else if ((void*)__f_ == &__buf_) {
                    __f_->__clone(__as_base(&__f.__buf_));
                    __f_->destroy();
                    __f_ = __f.__f_;
                    __f.__f_ = __as_base(&__f.__buf_);
                } else if ((void*)__f.__f_ == &__f.__buf_) {
                    __f.__f_->__clone(__as_base(&__buf_));
                    __f.__f_->destroy();
                    __f.__f_ = __f_;
                    __f_ = __as_base(&__buf_);
                } else
                    _VSTD::swap(__f_, __f.__f_);
            }

            _LIBCPP_EXPLICIT operator bool() const _NOEXCEPT {
                return __f_ != 0;
            }

#    ifndef _LIBCPP_NO_RTTI

            const std::type_info& target_type() const _NOEXCEPT {
                if (__f_ == 0)
                    return typeid(void);
                return __f_->target_type();
            }

            template <typename _Tp>
            const _Tp* target() const _NOEXCEPT {
                if (__f_ == 0)
                    return 0;
                return (const _Tp*)__f_->target(typeid(_Tp));
            }
#    endif  // _LIBCPP_NO_RTTI
        };

        // Storage for a functor object, to be used with __policy to manage copy and
        // destruction.
        union __policy_storage {
            mutable char __small[sizeof(void*) * 2];
            void* __large;
        };

        // True if _Fun can safely be held in __policy_storage.__small.
        template <typename _Fun>
        struct __use_small_storage
            : public _VSTD::integral_constant<bool, sizeof(_Fun) <= sizeof(__policy_storage) &&
                                                        _LIBCPP_ALIGNOF(_Fun) <= _LIBCPP_ALIGNOF(__policy_storage) &&
                                                        _VSTD::is_trivially_copy_constructible<_Fun>::value &&
                                                        _VSTD::is_trivially_destructible<_Fun>::value> {};

        // Policy contains information about how to copy, destroy, and move the
        // underlying functor. You can think of it as a vtable of sorts.
        struct __policy {
            // Used to copy or destroy __large values. null for trivial objects.
            void* (*const __clone)(const void*);
            void (*const __destroy)(void*);

            // True if this is the null policy (no value).
            const bool __is_null;

            // The target type. May be null if RTTI is disabled.
            const std::type_info* const __type_info;

            // Returns a pointer to a static policy object suitable for the functor
            // type.
            template <typename _Fun>
            static const __policy* __create() {
                return __choose_policy<_Fun>(__use_small_storage<_Fun>());
            }

            static const __policy* __create_empty() {
                static const _LIBCPP_CONSTEXPR __policy __policy_ = {nullptr, nullptr, true,
#    ifndef _LIBCPP_NO_RTTI
                                                                     &typeid(void)
#    else
                                                                     nullptr
#    endif
                };
                return &__policy_;
            }

          private:
            template <typename _Fun>
            static void* __large_clone(const void* __s) {
                const _Fun* __f = static_cast<const _Fun*>(__s);
                return __f->__clone();
            }

            template <typename _Fun>
            static void __large_destroy(void* __s) {
                typedef allocator_traits<typename _Fun::_Alloc> __alloc_traits;
                typedef typename __rebind_alloc_helper<__alloc_traits, _Fun>::type _FunAlloc;
                _Fun* __f = static_cast<_Fun*>(__s);
                _FunAlloc __a(__f->__allocator());
                __f->destroy();
                __a.deallocate(__f, 1);
            }

            template <typename _Fun>
            static const __policy* __choose_policy(/* is_small = */ false_type) {
                static const _LIBCPP_CONSTEXPR __policy __policy_ = {&__large_clone<_Fun>, &__large_destroy<_Fun>,
                                                                     false,
#    ifndef _LIBCPP_NO_RTTI
                                                                     &typeid(typename _Fun::_Target)
#    else
                                                                     nullptr
#    endif
                };
                return &__policy_;
            }

            template <typename _Fun>
            static const __policy* __choose_policy(/* is_small = */ true_type) {
                static const _LIBCPP_CONSTEXPR __policy __policy_ = {nullptr, nullptr, false,
#    ifndef _LIBCPP_NO_RTTI
                                                                     &typeid(typename _Fun::_Target)
#    else
                                                                     nullptr
#    endif
                };
                return &__policy_;
            }
        };

        // Used to choose between perfect forwarding or pass-by-value. Pass-by-value is
        // faster for types that can be passed in registers.
        template <typename _Tp>
        using __fast_forward = typename _VSTD::conditional<_VSTD::is_scalar<_Tp>::value, _Tp, _Tp&&>::type;

        // __policy_invoker calls an instance of __alloc_func held in __policy_storage.

        template <class _Fp>
        struct __policy_invoker;

        template <class _Rp, class... _ArgTypes>
        struct __policy_invoker<_Rp(_ArgTypes...)> {
            typedef _Rp (*__Call)(const __policy_storage*, __fast_forward<_ArgTypes>...);

            __Call __call_;

            // Creates an invoker that throws bad_function_call.

            __policy_invoker() : __call_(&__call_empty) {
            }

            // Creates an invoker that calls the given instance of __func.
            template <typename _Fun>
            static __policy_invoker __create() {
                return __policy_invoker(&__call_impl<_Fun>);
            }

          private:
            explicit __policy_invoker(__Call __c) : __call_(__c) {
            }

            static _Rp __call_empty(const __policy_storage*, __fast_forward<_ArgTypes>...) {
                __throw_bad_function_call();
            }

            template <typename _Fun>
            static _Rp __call_impl(const __policy_storage* __buf, __fast_forward<_ArgTypes>... __args) {
                _Fun* __f =
                    reinterpret_cast<_Fun*>(__use_small_storage<_Fun>::value ? &__buf->__small : __buf->__large);
                return (*__f)(_VSTD::forward<_ArgTypes>(__args)...);
            }
        };

        // __policy_func uses a __policy and __policy_invoker to create a type-erased,
        // copyable functor.

        template <class _Fp>
        class __policy_func;

        template <class _Rp, class... _ArgTypes>
        class __policy_func<_Rp(_ArgTypes...)> {
            // Inline storage for small objects.
            __policy_storage __buf_;

            // Calls the value stored in __buf_. This could technically be part of
            // policy, but storing it here eliminates a level of indirection inside
            // operator().
            typedef __function::__policy_invoker<_Rp(_ArgTypes...)> __invoker;
            __invoker __invoker_;

            // The policy that describes how to move / copy / destroy __buf_. Never
            // null, even if the function is empty.
            const __policy* __policy_;

          public:
            __policy_func() : __policy_(__policy::__create_empty()) {
            }

            template <class _Fp, class _Alloc>
            __policy_func(_Fp&& __f, const _Alloc& __a) : __policy_(__policy::__create_empty()) {
                typedef __alloc_func<_Fp, _Alloc, _Rp(_ArgTypes...)> _Fun;
                typedef allocator_traits<_Alloc> __alloc_traits;
                typedef typename __rebind_alloc_helper<__alloc_traits, _Fun>::type _FunAlloc;

                if (__function::__not_null(__f)) {
                    __invoker_ = __invoker::template __create<_Fun>();
                    __policy_ = __policy::__create<_Fun>();

                    _FunAlloc __af(__a);
                    if (__use_small_storage<_Fun>()) {
                        ::new ((void*)&__buf_.__small) _Fun(_VSTD::move(__f), _Alloc(__af));
                    } else {
                        typedef __allocator_destructor<_FunAlloc> _Dp;
                        unique_ptr<_Fun, _Dp> __hold(__af.allocate(1), _Dp(__af, 1));
                        ::new ((void*)__hold.get()) _Fun(_VSTD::move(__f), _Alloc(__af));
                        __buf_.__large = __hold.release();
                    }
                }
            }

            __policy_func(const __policy_func& __f)
                : __buf_(__f.__buf_), __invoker_(__f.__invoker_), __policy_(__f.__policy_) {
                if (__policy_->__clone)
                    __buf_.__large = __policy_->__clone(__f.__buf_.__large);
            }

            __policy_func(__policy_func&& __f)
                : __buf_(__f.__buf_), __invoker_(__f.__invoker_), __policy_(__f.__policy_) {
                if (__policy_->__destroy) {
                    __f.__policy_ = __policy::__create_empty();
                    __f.__invoker_ = __invoker();
                }
            }

            ~__policy_func() {
                if (__policy_->__destroy)
                    __policy_->__destroy(__buf_.__large);
            }

            __policy_func& operator=(__policy_func&& __f) {
                *this = nullptr;
                __buf_ = __f.__buf_;
                __invoker_ = __f.__invoker_;
                __policy_ = __f.__policy_;
                __f.__policy_ = __policy::__create_empty();
                __f.__invoker_ = __invoker();
                return *this;
            }

            __policy_func& operator=(std::nullptr_t) {
                const __policy* __p = __policy_;
                __policy_ = __policy::__create_empty();
                __invoker_ = __invoker();
                if (__p->__destroy)
                    __p->__destroy(__buf_.__large);
                return *this;
            }

            _Rp operator()(_ArgTypes&&... __args) const {
                return __invoker_.__call_(_VSTD::addressof(__buf_), _VSTD::forward<_ArgTypes>(__args)...);
            }

            void swap(__policy_func& __f) {
                _VSTD::swap(__invoker_, __f.__invoker_);
                _VSTD::swap(__policy_, __f.__policy_);
                _VSTD::swap(__buf_, __f.__buf_);
            }

            explicit operator bool() const _NOEXCEPT {
                return !__policy_->__is_null;
            }

#    ifndef _LIBCPP_NO_RTTI

            const std::type_info& target_type() const _NOEXCEPT {
                return *__policy_->__type_info;
            }

            template <typename _Tp>
            const _Tp* target() const _NOEXCEPT {
                if (__policy_->__is_null || typeid(_Tp) != *__policy_->__type_info)
                    return nullptr;
                if (__policy_->__clone)  // Out of line storage.
                    return reinterpret_cast<const _Tp*>(__buf_.__large);
                else
                    return reinterpret_cast<const _Tp*>(&__buf_.__small);
            }
#    endif  // _LIBCPP_NO_RTTI
        };

    }  // namespace __function

    template <class _Rp, class... _ArgTypes>
    class function<_Rp(_ArgTypes...)> : public __function::__maybe_derive_from_unary_function<_Rp(_ArgTypes...)>,
                                        public __function::__maybe_derive_from_binary_function<_Rp(_ArgTypes...)> {
#    ifndef _LIBCPP_ABI_OPTIMIZED_FUNCTION
        typedef __function::__value_func<_Rp(_ArgTypes...)> __func;
#    else
        typedef __function::__policy_func<_Rp(_ArgTypes...)> __func;
#    endif

        __func __f_;

        template <class _Fp, bool = __lazy_and<integral_constant<bool, !is_same<__uncvref_t<_Fp>, function>::value>,
                                               __invokable<_Fp&, _ArgTypes...>>::value>
        struct __callable;
        template <class _Fp>
        struct __callable<_Fp, true> {
            static const bool value =
                is_same<void, _Rp>::value || is_convertible<typename __invoke_of<_Fp&, _ArgTypes...>::type, _Rp>::value;
        };
        template <class _Fp>
        struct __callable<_Fp, false> {
            static const bool value = false;
        };

        template <class _Fp>
        using _EnableIfCallable = typename enable_if<__callable<_Fp>::value>::type;

      public:
        typedef _Rp result_type;

        // construct/copy/destroy:

        function() _NOEXCEPT {
        }

        function(std::nullptr_t) _NOEXCEPT {
        }
        function(const function&);
        function(function&&) _NOEXCEPT;
        template <class _Fp, class = _EnableIfCallable<_Fp>>
        function(_Fp);

#    if _LIBCPP_STD_VER <= 14
        template <class _Alloc>
        function(allocator_arg_t, const _Alloc&) _NOEXCEPT {
        }
        template <class _Alloc>
        function(allocator_arg_t, const _Alloc&, std::nullptr_t) _NOEXCEPT {
        }
        template <class _Alloc>
        function(allocator_arg_t, const _Alloc&, const function&);
        template <class _Alloc>
        function(allocator_arg_t, const _Alloc&, function&&);
        template <class _Fp, class _Alloc, class = _EnableIfCallable<_Fp>>
        function(allocator_arg_t, const _Alloc& __a, _Fp __f);
#    endif

        function& operator=(const function&);
        function& operator=(function&&) _NOEXCEPT;
        function& operator=(std::nullptr_t) _NOEXCEPT;
        template <class _Fp, class = _EnableIfCallable<_Fp>>
        function& operator=(_Fp&&);

        ~function();

        // function modifiers:
        void swap(function&) _NOEXCEPT;

#    if _LIBCPP_STD_VER <= 14
        template <class _Fp, class _Alloc>
        void assign(_Fp&& __f, const _Alloc& __a) {
            function(allocator_arg, __a, _VSTD::forward<_Fp>(__f)).swap(*this);
        }
#    endif

        // function capacity:

        _LIBCPP_EXPLICIT operator bool() const _NOEXCEPT {
            return static_cast<bool>(__f_);
        }

        // deleted overloads close possible hole in the type system
        template <class _R2, class... _ArgTypes2>
        bool operator==(const function<_R2(_ArgTypes2...)>&) const = delete;
        template <class _R2, class... _ArgTypes2>
        bool operator!=(const function<_R2(_ArgTypes2...)>&) const = delete;

      public:
        // function invocation:
        _Rp operator()(_ArgTypes...) const;

#    ifndef _LIBCPP_NO_RTTI
        // function target access:
        const std::type_info& target_type() const _NOEXCEPT;
        template <typename _Tp>
        _Tp* target() _NOEXCEPT;
        template <typename _Tp>
        const _Tp* target() const _NOEXCEPT;
#    endif  // _LIBCPP_NO_RTTI
    };

    template <class _Rp, class... _ArgTypes>
    function<_Rp(_ArgTypes...)>::function(const function& __f) : __f_(__f.__f_) {
    }

#    if _LIBCPP_STD_VER <= 14
    template <class _Rp, class... _ArgTypes>
    template <class _Alloc>
    function<_Rp(_ArgTypes...)>::function(allocator_arg_t, const _Alloc&, const function& __f) : __f_(__f.__f_) {
    }
#    endif

    template <class _Rp, class... _ArgTypes>
    function<_Rp(_ArgTypes...)>::function(function&& __f) _NOEXCEPT : __f_(_VSTD::move(__f.__f_)) {
    }

#    if _LIBCPP_STD_VER <= 14
    template <class _Rp, class... _ArgTypes>
    template <class _Alloc>
    function<_Rp(_ArgTypes...)>::function(allocator_arg_t, const _Alloc&, function&& __f)
        : __f_(_VSTD::move(__f.__f_)) {
    }
#    endif

    template <class _Rp, class... _ArgTypes>
    template <class _Fp, class>
    function<_Rp(_ArgTypes...)>::function(_Fp __f) : __f_(_VSTD::move(__f), allocator<_Fp>()) {
    }

#    if _LIBCPP_STD_VER <= 14
    template <class _Rp, class... _ArgTypes>
    template <class _Fp, class _Alloc, class>
    function<_Rp(_ArgTypes...)>::function(allocator_arg_t, const _Alloc& __a, _Fp __f) : __f_(_VSTD::move(__f), __a) {
    }
#    endif

    template <class _Rp, class... _ArgTypes>
    function<_Rp(_ArgTypes...)>& function<_Rp(_ArgTypes...)>::operator=(const function& __f) {
        function(__f).swap(*this);
        return *this;
    }

    template <class _Rp, class... _ArgTypes>
    function<_Rp(_ArgTypes...)>& function<_Rp(_ArgTypes...)>::operator=(function&& __f) _NOEXCEPT {
        __f_ = std::move(__f.__f_);
        return *this;
    }

    template <class _Rp, class... _ArgTypes>
    function<_Rp(_ArgTypes...)>& function<_Rp(_ArgTypes...)>::operator=(std::nullptr_t) _NOEXCEPT {
        __f_ = nullptr;
        return *this;
    }

    template <class _Rp, class... _ArgTypes>
    template <class _Fp, class>
    function<_Rp(_ArgTypes...)>& function<_Rp(_ArgTypes...)>::operator=(_Fp&& __f) {
        function(_VSTD::forward<_Fp>(__f)).swap(*this);
        return *this;
    }

    template <class _Rp, class... _ArgTypes>
    function<_Rp(_ArgTypes...)>::~function() {
    }

    template <class _Rp, class... _ArgTypes>
    void function<_Rp(_ArgTypes...)>::swap(function& __f) _NOEXCEPT {
        __f_.swap(__f.__f_);
    }

    template <class _Rp, class... _ArgTypes>
    _Rp function<_Rp(_ArgTypes...)>::operator()(_ArgTypes... __arg) const {
        return __f_(_VSTD::forward<_ArgTypes>(__arg)...);
    }

#    ifndef _LIBCPP_NO_RTTI

    template <class _Rp, class... _ArgTypes>
    const std::type_info& function<_Rp(_ArgTypes...)>::target_type() const _NOEXCEPT {
        return __f_.target_type();
    }

    template <class _Rp, class... _ArgTypes>
    template <typename _Tp>
    _Tp* function<_Rp(_ArgTypes...)>::target() _NOEXCEPT {
        return (_Tp*)(__f_.template target<_Tp>());
    }

    template <class _Rp, class... _ArgTypes>
    template <typename _Tp>
    const _Tp* function<_Rp(_ArgTypes...)>::target() const _NOEXCEPT {
        return __f_.template target<_Tp>();
    }

#    endif  // _LIBCPP_NO_RTTI

    template <class _Rp, class... _ArgTypes>
    inline bool operator==(const function<_Rp(_ArgTypes...)>& __f, std::nullptr_t) _NOEXCEPT {
        return !__f;
    }

    template <class _Rp, class... _ArgTypes>
    inline bool operator==(std::nullptr_t, const function<_Rp(_ArgTypes...)>& __f) _NOEXCEPT {
        return !__f;
    }

    template <class _Rp, class... _ArgTypes>
    inline bool operator!=(const function<_Rp(_ArgTypes...)>& __f, std::nullptr_t) _NOEXCEPT {
        return (bool)__f;
    }

    template <class _Rp, class... _ArgTypes>
    inline bool operator!=(std::nullptr_t, const function<_Rp(_ArgTypes...)>& __f) _NOEXCEPT {
        return (bool)__f;
    }

    template <class _Rp, class... _ArgTypes>
    inline void swap(function<_Rp(_ArgTypes...)>& __x, function<_Rp(_ArgTypes...)>& __y) _NOEXCEPT {
        return __x.swap(__y);
    }

#else  // _LIBCPP_CXX03_LANG

#    include <__functional_03>

#endif

    ////////////////////////////////////////////////////////////////////////////////
    //                                  BIND
    //==============================================================================

    template <class _Tp>
    struct __is_bind_expression : public false_type {};
    template <class _Tp>
    struct is_bind_expression : public __is_bind_expression<typename remove_cv<_Tp>::type> {};

#if _LIBCPP_STD_VER > 14
    template <class _Tp>
    _LIBCPP_INLINE_VAR constexpr size_t is_bind_expression_v = is_bind_expression<_Tp>::value;
#endif

    template <class _Tp>
    struct __is_placeholder : public integral_constant<int, 0> {};
    template <class _Tp>
    struct is_placeholder : public __is_placeholder<typename remove_cv<_Tp>::type> {};

#if _LIBCPP_STD_VER > 14
    template <class _Tp>
    _LIBCPP_INLINE_VAR constexpr size_t is_placeholder_v = is_placeholder<_Tp>::value;
#endif

    namespace placeholders {

        template <int _Np>
        struct __ph {};

#if defined(_LIBCPP_CXX03_LANG) || defined(_LIBCPP_BUILDING_LIBRARY)
        _LIBCPP_FUNC_VIS extern const __ph<1> _1;
        _LIBCPP_FUNC_VIS extern const __ph<2> _2;
        _LIBCPP_FUNC_VIS extern const __ph<3> _3;
        _LIBCPP_FUNC_VIS extern const __ph<4> _4;
        _LIBCPP_FUNC_VIS extern const __ph<5> _5;
        _LIBCPP_FUNC_VIS extern const __ph<6> _6;
        _LIBCPP_FUNC_VIS extern const __ph<7> _7;
        _LIBCPP_FUNC_VIS extern const __ph<8> _8;
        _LIBCPP_FUNC_VIS extern const __ph<9> _9;
        _LIBCPP_FUNC_VIS extern const __ph<10> _10;
#else
        /* _LIBCPP_INLINE_VAR */ constexpr __ph<1> _1{};
        /* _LIBCPP_INLINE_VAR */ constexpr __ph<2> _2{};
        /* _LIBCPP_INLINE_VAR */ constexpr __ph<3> _3{};
        /* _LIBCPP_INLINE_VAR */ constexpr __ph<4> _4{};
        /* _LIBCPP_INLINE_VAR */ constexpr __ph<5> _5{};
        /* _LIBCPP_INLINE_VAR */ constexpr __ph<6> _6{};
        /* _LIBCPP_INLINE_VAR */ constexpr __ph<7> _7{};
        /* _LIBCPP_INLINE_VAR */ constexpr __ph<8> _8{};
        /* _LIBCPP_INLINE_VAR */ constexpr __ph<9> _9{};
        /* _LIBCPP_INLINE_VAR */ constexpr __ph<10> _10{};
#endif  // defined(_LIBCPP_CXX03_LANG) || defined(_LIBCPP_BUILDING_LIBRARY)

    }  // namespace placeholders

    template <int _Np>
    struct __is_placeholder<placeholders::__ph<_Np>> : public integral_constant<int, _Np> {};

#ifndef _LIBCPP_CXX03_LANG

    template <class _Tp, class _Uj>
    inline _Tp& __mu(reference_wrapper<_Tp> __t, _Uj&) {
        return __t.get();
    }

    template <class _Ti, class... _Uj, size_t... _Indx>
    inline typename __invoke_of<_Ti&, _Uj...>::type __mu_expand(_Ti& __ti, tuple<_Uj...>& __uj,
                                                                __tuple_indices<_Indx...>) {
        return __ti(_VSTD::forward<_Uj>(_VSTD::get<_Indx>(__uj))...);
    }

    template <class _Ti, class... _Uj>
    inline typename __lazy_enable_if<is_bind_expression<_Ti>::value, __invoke_of<_Ti&, _Uj...>>::type __mu(
        _Ti& __ti, tuple<_Uj...>& __uj) {
        typedef typename __make_tuple_indices<sizeof...(_Uj)>::type __indices;
        return __mu_expand(__ti, __uj, __indices());
    }

    template <bool IsPh, class _Ti, class _Uj>
    struct __mu_return2 {};

    template <class _Ti, class _Uj>
    struct __mu_return2<true, _Ti, _Uj> {
        typedef typename tuple_element<is_placeholder<_Ti>::value - 1, _Uj>::type type;
    };

    template <class _Ti, class _Uj>
    inline typename enable_if<0 < is_placeholder<_Ti>::value,
                              typename __mu_return2<0 < is_placeholder<_Ti>::value, _Ti, _Uj>::type>::type
    __mu(_Ti&, _Uj& __uj) {
        const size_t _Indx = is_placeholder<_Ti>::value - 1;
        return _VSTD::forward<typename tuple_element<_Indx, _Uj>::type>(_VSTD::get<_Indx>(__uj));
    }

    template <class _Ti, class _Uj>
    inline typename enable_if<!is_bind_expression<_Ti>::value && is_placeholder<_Ti>::value == 0 &&
                                  !__is_reference_wrapper<_Ti>::value,
                              _Ti&>::type
    __mu(_Ti& __ti, _Uj&) {
        return __ti;
    }

    template <class _Ti, bool IsReferenceWrapper, bool IsBindEx, bool IsPh, class _TupleUj>
    struct __mu_return_impl;

    template <bool _Invokable, class _Ti, class... _Uj>
    struct __mu_return_invokable  // false
    {
        typedef __nat type;
    };

    template <class _Ti, class... _Uj>
    struct __mu_return_invokable<true, _Ti, _Uj...> {
        typedef typename __invoke_of<_Ti&, _Uj...>::type type;
    };

    template <class _Ti, class... _Uj>
    struct __mu_return_impl<_Ti, false, true, false, tuple<_Uj...>>
        : public __mu_return_invokable<__invokable<_Ti&, _Uj...>::value, _Ti, _Uj...> {};

    template <class _Ti, class _TupleUj>
    struct __mu_return_impl<_Ti, false, false, true, _TupleUj> {
        typedef typename tuple_element<is_placeholder<_Ti>::value - 1, _TupleUj>::type&& type;
    };

    template <class _Ti, class _TupleUj>
    struct __mu_return_impl<_Ti, true, false, false, _TupleUj> {
        typedef typename _Ti::type& type;
    };

    template <class _Ti, class _TupleUj>
    struct __mu_return_impl<_Ti, false, false, false, _TupleUj> {
        typedef _Ti& type;
    };

    template <class _Ti, class _TupleUj>
    struct __mu_return
        : public __mu_return_impl<
              _Ti, __is_reference_wrapper<_Ti>::value, is_bind_expression<_Ti>::value,
              0 < is_placeholder<_Ti>::value && is_placeholder<_Ti>::value <= tuple_size<_TupleUj>::value, _TupleUj> {};

    template <class _Fp, class _BoundArgs, class _TupleUj>
    struct __is_valid_bind_return {
        static const bool value = false;
    };

    template <class _Fp, class... _BoundArgs, class _TupleUj>
    struct __is_valid_bind_return<_Fp, tuple<_BoundArgs...>, _TupleUj> {
        static const bool value = __invokable<_Fp, typename __mu_return<_BoundArgs, _TupleUj>::type...>::value;
    };

    template <class _Fp, class... _BoundArgs, class _TupleUj>
    struct __is_valid_bind_return<_Fp, const tuple<_BoundArgs...>, _TupleUj> {
        static const bool value = __invokable<_Fp, typename __mu_return<const _BoundArgs, _TupleUj>::type...>::value;
    };

    template <class _Fp, class _BoundArgs, class _TupleUj,
              bool = __is_valid_bind_return<_Fp, _BoundArgs, _TupleUj>::value>
    struct __bind_return;

    template <class _Fp, class... _BoundArgs, class _TupleUj>
    struct __bind_return<_Fp, tuple<_BoundArgs...>, _TupleUj, true> {
        typedef typename __invoke_of<_Fp&, typename __mu_return<_BoundArgs, _TupleUj>::type...>::type type;
    };

    template <class _Fp, class... _BoundArgs, class _TupleUj>
    struct __bind_return<_Fp, const tuple<_BoundArgs...>, _TupleUj, true> {
        typedef typename __invoke_of<_Fp&, typename __mu_return<const _BoundArgs, _TupleUj>::type...>::type type;
    };

    template <class _Fp, class _BoundArgs, size_t... _Indx, class _Args>
    inline typename __bind_return<_Fp, _BoundArgs, _Args>::type __apply_functor(_Fp& __f, _BoundArgs& __bound_args,
                                                                                __tuple_indices<_Indx...>,
                                                                                _Args&& __args) {
        return _VSTD::__invoke(__f, _VSTD::__mu(_VSTD::get<_Indx>(__bound_args), __args)...);
    }

    template <class _Fp, class... _BoundArgs>
    class __bind : public __weak_result_type<typename decay<_Fp>::type> {
      protected:
        typedef typename decay<_Fp>::type _Fd;
        typedef tuple<typename decay<_BoundArgs>::type...> _Td;

      private:
        _Fd __f_;
        _Td __bound_args_;

        typedef typename __make_tuple_indices<sizeof...(_BoundArgs)>::type __indices;

      public:
        template <class _Gp, class... _BA,
                  class = typename enable_if<is_constructible<_Fd, _Gp>::value &&
                                             !is_same<typename remove_reference<_Gp>::type, __bind>::value>::type>
        explicit __bind(_Gp&& __f, _BA&&... __bound_args)
            : __f_(_VSTD::forward<_Gp>(__f)), __bound_args_(_VSTD::forward<_BA>(__bound_args)...) {
        }

        template <class... _Args>
        typename __bind_return<_Fd, _Td, tuple<_Args&&...>>::type operator()(_Args&&... __args) {
            return _VSTD::__apply_functor(__f_, __bound_args_, __indices(),
                                          tuple<_Args&&...>(_VSTD::forward<_Args>(__args)...));
        }

        template <class... _Args>
        typename __bind_return<const _Fd, const _Td, tuple<_Args&&...>>::type operator()(_Args&&... __args) const {
            return _VSTD::__apply_functor(__f_, __bound_args_, __indices(),
                                          tuple<_Args&&...>(_VSTD::forward<_Args>(__args)...));
        }
    };

    template <class _Fp, class... _BoundArgs>
    struct __is_bind_expression<__bind<_Fp, _BoundArgs...>> : public true_type {};

    template <class _Rp, class _Fp, class... _BoundArgs>
    class __bind_r : public __bind<_Fp, _BoundArgs...> {
        typedef __bind<_Fp, _BoundArgs...> base;
        typedef typename base::_Fd _Fd;
        typedef typename base::_Td _Td;

      public:
        typedef _Rp result_type;

        template <class _Gp, class... _BA,
                  class = typename enable_if<is_constructible<_Fd, _Gp>::value &&
                                             !is_same<typename remove_reference<_Gp>::type, __bind_r>::value>::type>
        explicit __bind_r(_Gp&& __f, _BA&&... __bound_args)
            : base(_VSTD::forward<_Gp>(__f), _VSTD::forward<_BA>(__bound_args)...) {
        }

        template <class... _Args>
        typename enable_if<
            is_convertible<typename __bind_return<_Fd, _Td, tuple<_Args&&...>>::type, result_type>::value ||
                is_void<_Rp>::value,
            result_type>::type
        operator()(_Args&&... __args) {
            typedef __invoke_void_return_wrapper<_Rp> _Invoker;
            return _Invoker::__call(static_cast<base&>(*this), _VSTD::forward<_Args>(__args)...);
        }

        template <class... _Args>
        typename enable_if<
            is_convertible<typename __bind_return<const _Fd, const _Td, tuple<_Args&&...>>::type, result_type>::value ||
                is_void<_Rp>::value,
            result_type>::type
        operator()(_Args&&... __args) const {
            typedef __invoke_void_return_wrapper<_Rp> _Invoker;
            return _Invoker::__call(static_cast<base const&>(*this), _VSTD::forward<_Args>(__args)...);
        }
    };

    template <class _Rp, class _Fp, class... _BoundArgs>
    struct __is_bind_expression<__bind_r<_Rp, _Fp, _BoundArgs...>> : public true_type {};

    template <class _Fp, class... _BoundArgs>
    inline __bind<_Fp, _BoundArgs...> bind(_Fp&& __f, _BoundArgs&&... __bound_args) {
        typedef __bind<_Fp, _BoundArgs...> type;
        return type(_VSTD::forward<_Fp>(__f), _VSTD::forward<_BoundArgs>(__bound_args)...);
    }

    template <class _Rp, class _Fp, class... _BoundArgs>
    inline __bind_r<_Rp, _Fp, _BoundArgs...> bind(_Fp&& __f, _BoundArgs&&... __bound_args) {
        typedef __bind_r<_Rp, _Fp, _BoundArgs...> type;
        return type(_VSTD::forward<_Fp>(__f), _VSTD::forward<_BoundArgs>(__bound_args)...);
    }

#endif  // _LIBCPP_CXX03_LANG

#if _LIBCPP_STD_VER > 14

    template <class _Fn, class... _Args>
    result_of_t<_Fn && (_Args && ...)> invoke(_Fn&& __f, _Args&&... __args) noexcept(
        noexcept(_VSTD::__invoke(_VSTD::forward<_Fn>(__f), _VSTD::forward<_Args>(__args)...))) {
        return _VSTD::__invoke(_VSTD::forward<_Fn>(__f), _VSTD::forward<_Args>(__args)...);
    }

    template <class _DecayFunc>
    class __not_fn_imp {
        _DecayFunc __fd;

      public:
        __not_fn_imp() = delete;

        template <class... _Args>
            auto operator()(_Args&&... __args) &
            noexcept(noexcept(!_VSTD::invoke(__fd, _VSTD::forward<_Args>(__args)...)))
                -> decltype(!_VSTD::invoke(__fd, _VSTD::forward<_Args>(__args)...)) {
            return !_VSTD::invoke(__fd, _VSTD::forward<_Args>(__args)...);
        }

        template <class... _Args>
            auto operator()(_Args&&... __args) &&
            noexcept(noexcept(!_VSTD::invoke(_VSTD::move(__fd), _VSTD::forward<_Args>(__args)...)))
                -> decltype(!_VSTD::invoke(_VSTD::move(__fd), _VSTD::forward<_Args>(__args)...)) {
            return !_VSTD::invoke(_VSTD::move(__fd), _VSTD::forward<_Args>(__args)...);
        }

        template <class... _Args>
        auto operator()(_Args&&... __args) const& noexcept(noexcept(!_VSTD::invoke(__fd,
                                                                                   _VSTD::forward<_Args>(__args)...)))
            -> decltype(!_VSTD::invoke(__fd, _VSTD::forward<_Args>(__args)...)) {
            return !_VSTD::invoke(__fd, _VSTD::forward<_Args>(__args)...);
        }

        template <class... _Args>
        auto operator()(_Args&&... __args) const&& noexcept(noexcept(!_VSTD::invoke(_VSTD::move(__fd),
                                                                                    _VSTD::forward<_Args>(__args)...)))
            -> decltype(!_VSTD::invoke(_VSTD::move(__fd), _VSTD::forward<_Args>(__args)...)) {
            return !_VSTD::invoke(_VSTD::move(__fd), _VSTD::forward<_Args>(__args)...);
        }

      private:
        template <class _RawFunc, class = enable_if_t<!is_same<decay_t<_RawFunc>, __not_fn_imp>::value>>
        explicit __not_fn_imp(_RawFunc&& __rf) : __fd(_VSTD::forward<_RawFunc>(__rf)) {
        }

        template <class _RawFunc>
        friend inline __not_fn_imp<decay_t<_RawFunc>> not_fn(_RawFunc&&);
    };

    template <class _RawFunc>
    inline __not_fn_imp<decay_t<_RawFunc>> not_fn(_RawFunc&& __fn) {
        return __not_fn_imp<decay_t<_RawFunc>>(_VSTD::forward<_RawFunc>(__fn));
    }

#endif

    // struct hash<T*> in <memory>

    template <class _BinaryPredicate, class _ForwardIterator1, class _ForwardIterator2>
    pair<_ForwardIterator1, _ForwardIterator1> constexpr __search(_ForwardIterator1 __first1, _ForwardIterator1 __last1,
                                                                  _ForwardIterator2 __first2, _ForwardIterator2 __last2,
                                                                  _BinaryPredicate __pred, forward_iterator_tag,
                                                                  forward_iterator_tag) {
        if (__first2 == __last2)
            return make_pair(__first1, __first1);  // Everything matches an empty sequence
        while (true) {
            // Find first element in sequence 1 that matchs *__first2, with a mininum of loop checks
            while (true) {
                if (__first1 == __last1)  // return __last1 if no element matches *__first2
                    return make_pair(__last1, __last1);
                if (__pred(*__first1, *__first2))
                    break;
                ++__first1;
            }
            // *__first1 matches *__first2, now match elements after here
            _ForwardIterator1 __m1 = __first1;
            _ForwardIterator2 __m2 = __first2;
            while (true) {
                if (++__m2 == __last2)  // If pattern exhausted, __first1 is the answer (works for 1 element pattern)
                    return make_pair(__first1, __m1);
                if (++__m1 == __last1)  // Otherwise if source exhaused, pattern not found
                    return make_pair(__last1, __last1);
                if (!__pred(*__m1, *__m2))  // if there is a mismatch, restart with a new __first1
                {
                    ++__first1;
                    break;
                }  // else there is a match, check next elements
            }
        }
    }

    template <class _BinaryPredicate, class _RandomAccessIterator1, class _RandomAccessIterator2>
    constexpr pair<_RandomAccessIterator1, _RandomAccessIterator1> __search(
        _RandomAccessIterator1 __first1, _RandomAccessIterator1 __last1, _RandomAccessIterator2 __first2,
        _RandomAccessIterator2 __last2, _BinaryPredicate __pred, random_access_iterator_tag,
        random_access_iterator_tag) {
        typedef typename iterator_traits<_RandomAccessIterator1>::difference_type _D1;
        typedef typename iterator_traits<_RandomAccessIterator2>::difference_type _D2;
        // Take advantage of knowing source and pattern lengths.  Stop short when source is smaller than pattern
        const _D2 __len2 = __last2 - __first2;
        if (__len2 == 0)
            return make_pair(__first1, __first1);
        const _D1 __len1 = __last1 - __first1;
        if (__len1 < __len2)
            return make_pair(__last1, __last1);
        const _RandomAccessIterator1 __s = __last1 - (__len2 - 1);  // Start of pattern match can't go beyond here

        while (true) {
            while (true) {
                if (__first1 == __s)
                    return make_pair(__last1, __last1);
                if (__pred(*__first1, *__first2))
                    break;
                ++__first1;
            }

            _RandomAccessIterator1 __m1 = __first1;
            _RandomAccessIterator2 __m2 = __first2;
            while (true) {
                if (++__m2 == __last2)
                    return make_pair(__first1, __first1 + __len2);
                ++__m1;  // no need to check range on __m1 because __s guarantees we have enough source
                if (!__pred(*__m1, *__m2)) {
                    ++__first1;
                    break;
                }
            }
        }
    }

#if _LIBCPP_STD_VER > 14

    // default searcher
    template <class _ForwardIterator, class _BinaryPredicate = equal_to<>>
    class _LIBCPP_TYPE_VIS default_searcher {
      public:
        default_searcher(_ForwardIterator __f, _ForwardIterator __l, _BinaryPredicate __p = _BinaryPredicate())
            : __first_(__f), __last_(__l), __pred_(__p) {
        }

        template <typename _ForwardIterator2>
        pair<_ForwardIterator2, _ForwardIterator2> operator()(_ForwardIterator2 __f, _ForwardIterator2 __l) const {
            return _VSTD::__search(__f, __l, __first_, __last_, __pred_,
                                   typename _VSTD::iterator_traits<_ForwardIterator>::iterator_category(),
                                   typename _VSTD::iterator_traits<_ForwardIterator2>::iterator_category());
        }

      private:
        _ForwardIterator __first_;
        _ForwardIterator __last_;
        _BinaryPredicate __pred_;
    };

#endif  // _LIBCPP_STD_VER > 14

#if _LIBCPP_STD_VER > 17
    template <class _Tp>
    using unwrap_reference_t = typename unwrap_reference<_Tp>::type;

    template <class _Tp>
    using unwrap_ref_decay_t = typename unwrap_ref_decay<_Tp>::type;
#endif  // > C++17

    template <class _Container, class _Predicate>
    inline void __libcpp_erase_if_container(_Container& __c, _Predicate __pred) {
        for (typename _Container::iterator __iter = __c.begin(), __last = __c.end(); __iter != __last;) {
            if (__pred(*__iter))
                __iter = __c.erase(__iter);
            else
                ++__iter;
        }
    }

    _LIBCPP_END_NAMESPACE_STD

}  // namespace GP
#endif  // FUNCTIONAL_HPP
