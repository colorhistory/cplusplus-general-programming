﻿#ifndef ATOMIC_HPP
#define ATOMIC_HPP

#include "bits/stdc++.h"

namespace GP {

#define __cpp_lib_atomic_is_always_lock_free  // as specified by SG10
    typedef enum memory_order {
        memory_order_relaxed,
        memory_order_consume,  // load-consume
        memory_order_acquire,  // load-acquire
        memory_order_release,  // store-release
        memory_order_acq_rel,  // store-release load-acquire
        memory_order_seq_cst   // store-release load-acquire
    } memory_order;

    template <class T>
    T kill_dependency(T y) noexcept;

    // lock-free property
#define ATOMIC_BOOL_LOCK_FREE unspecified
#define ATOMIC_CHAR_LOCK_FREE unspecified
#define ATOMIC_CHAR16_T_LOCK_FREE unspecified
#define ATOMIC_CHAR32_T_LOCK_FREE unspecified
#define ATOMIC_WCHAR_T_LOCK_FREE unspecified
#define ATOMIC_SHORT_LOCK_FREE unspecified
#define ATOMIC_INT_LOCK_FREE unspecified
#define ATOMIC_LONG_LOCK_FREE unspecified
#define ATOMIC_LLONG_LOCK_FREE unspecified
#define ATOMIC_POINTER_LOCK_FREE unspecified

    // flag type and operations

    typedef struct atomic_flag {
        bool test_and_set(memory_order m = memory_order_seq_cst) volatile noexcept;
        bool test_and_set(memory_order m = memory_order_seq_cst) noexcept;
        void clear(memory_order m = memory_order_seq_cst) volatile noexcept;
        void clear(memory_order m = memory_order_seq_cst) noexcept;
        atomic_flag() noexcept = default;
        atomic_flag(const atomic_flag&) = delete;
        atomic_flag& operator=(const atomic_flag&) = delete;
        atomic_flag& operator=(const atomic_flag&) volatile = delete;
    } atomic_flag;

    bool atomic_flag_test_and_set(volatile atomic_flag* obj) noexcept;

    bool atomic_flag_test_and_set(atomic_flag* obj) noexcept;

    bool atomic_flag_test_and_set_explicit(volatile atomic_flag* obj, memory_order m) noexcept;

    bool atomic_flag_test_and_set_explicit(atomic_flag* obj, memory_order m) noexcept;

    void atomic_flag_clear(volatile atomic_flag* obj) noexcept;

    void atomic_flag_clear(atomic_flag* obj) noexcept;

    void atomic_flag_clear_explicit(volatile atomic_flag* obj, memory_order m) noexcept;

    void atomic_flag_clear_explicit(atomic_flag* obj, memory_order m) noexcept;

#define ATOMIC_FLAG_INIT see below
#define ATOMIC_VAR_INIT(value) see below

    template <class T>
    struct atomic {
        static constexpr bool is_always_lock_free;
        bool is_lock_free() const volatile noexcept;
        bool is_lock_free() const noexcept;
        void store(T desr, memory_order m = memory_order_seq_cst) volatile noexcept;
        void store(T desr, memory_order m = memory_order_seq_cst) noexcept;
        T load(memory_order m = memory_order_seq_cst) const volatile noexcept;
        T load(memory_order m = memory_order_seq_cst) const noexcept;
        operator T() const volatile noexcept;
        operator T() const noexcept;
        T exchange(T desr, memory_order m = memory_order_seq_cst) volatile noexcept;
        T exchange(T desr, memory_order m = memory_order_seq_cst) noexcept;
        bool compare_exchange_weak(T& expc, T desr, memory_order s, memory_order f) volatile noexcept;
        bool compare_exchange_weak(T& expc, T desr, memory_order s, memory_order f) noexcept;
        bool compare_exchange_strong(T& expc, T desr, memory_order s, memory_order f) volatile noexcept;
        bool compare_exchange_strong(T& expc, T desr, memory_order s, memory_order f) noexcept;
        bool compare_exchange_weak(T& expc, T desr, memory_order m = memory_order_seq_cst) volatile noexcept;
        bool compare_exchange_weak(T& expc, T desr, memory_order m = memory_order_seq_cst) noexcept;
        bool compare_exchange_strong(T& expc, T desr, memory_order m = memory_order_seq_cst) volatile noexcept;
        bool compare_exchange_strong(T& expc, T desr, memory_order m = memory_order_seq_cst) noexcept;

        atomic() noexcept = default;
        constexpr atomic(T desr) noexcept;
        atomic(const atomic&) = delete;
        atomic& operator=(const atomic&) = delete;
        atomic& operator=(const atomic&) volatile = delete;
        T operator=(T) volatile noexcept;
        T operator=(T) noexcept;
    };

    template <>
    struct atomic<integral> {
        static constexpr bool is_always_lock_free;
        bool is_lock_free() const volatile noexcept;
        bool is_lock_free() const noexcept;
        void store(integral desr, memory_order m = memory_order_seq_cst) volatile noexcept;
        void store(integral desr, memory_order m = memory_order_seq_cst) noexcept;
        integral load(memory_order m = memory_order_seq_cst) const volatile noexcept;
        integral load(memory_order m = memory_order_seq_cst) const noexcept;
        operator integral() const volatile noexcept;
        operator integral() const noexcept;
        integral exchange(integral desr, memory_order m = memory_order_seq_cst) volatile noexcept;
        integral exchange(integral desr, memory_order m = memory_order_seq_cst) noexcept;
        bool compare_exchange_weak(integral& expc, integral desr, memory_order s, memory_order f) volatile noexcept;
        bool compare_exchange_weak(integral& expc, integral desr, memory_order s, memory_order f) noexcept;
        bool compare_exchange_strong(integral& expc, integral desr, memory_order s, memory_order f) volatile noexcept;
        bool compare_exchange_strong(integral& expc, integral desr, memory_order s, memory_order f) noexcept;
        bool compare_exchange_weak(integral& expc, integral desr,
                                   memory_order m = memory_order_seq_cst) volatile noexcept;
        bool compare_exchange_weak(integral& expc, integral desr, memory_order m = memory_order_seq_cst) noexcept;
        bool compare_exchange_strong(integral& expc, integral desr,
                                     memory_order m = memory_order_seq_cst) volatile noexcept;
        bool compare_exchange_strong(integral& expc, integral desr, memory_order m = memory_order_seq_cst) noexcept;

        integral fetch_add(integral op, memory_order m = memory_order_seq_cst) volatile noexcept;
        integral fetch_add(integral op, memory_order m = memory_order_seq_cst) noexcept;
        integral fetch_sub(integral op, memory_order m = memory_order_seq_cst) volatile noexcept;
        integral fetch_sub(integral op, memory_order m = memory_order_seq_cst) noexcept;
        integral fetch_and(integral op, memory_order m = memory_order_seq_cst) volatile noexcept;
        integral fetch_and(integral op, memory_order m = memory_order_seq_cst) noexcept;
        integral fetch_or(integral op, memory_order m = memory_order_seq_cst) volatile noexcept;
        integral fetch_or(integral op, memory_order m = memory_order_seq_cst) noexcept;
        integral fetch_xor(integral op, memory_order m = memory_order_seq_cst) volatile noexcept;
        integral fetch_xor(integral op, memory_order m = memory_order_seq_cst) noexcept;

        atomic() noexcept = default;
        constexpr atomic(integral desr) noexcept;
        atomic(const atomic&) = delete;
        atomic& operator=(const atomic&) = delete;
        atomic& operator=(const atomic&) volatile = delete;
        integral operator=(integral desr) volatile noexcept;
        integral operator=(integral desr) noexcept;

        integral operator++(int) volatile noexcept;
        integral operator++(int) noexcept;
        integral operator--(int) volatile noexcept;
        integral operator--(int) noexcept;
        integral operator++() volatile noexcept;
        integral operator++() noexcept;
        integral operator--() volatile noexcept;
        integral operator--() noexcept;
        integral operator+=(integral op) volatile noexcept;
        integral operator+=(integral op) noexcept;
        integral operator-=(integral op) volatile noexcept;
        integral operator-=(integral op) noexcept;
        integral operator&=(integral op) volatile noexcept;
        integral operator&=(integral op) noexcept;
        integral operator|=(integral op) volatile noexcept;
        integral operator|=(integral op) noexcept;
        integral operator^=(integral op) volatile noexcept;
        integral operator^=(integral op) noexcept;
    };

    template <class T>
    struct atomic<T*> {
        static constexpr bool is_always_lock_free;
        bool is_lock_free() const volatile noexcept;
        bool is_lock_free() const noexcept;
        void store(T* desr, memory_order m = memory_order_seq_cst) volatile noexcept;
        void store(T* desr, memory_order m = memory_order_seq_cst) noexcept;
        T* load(memory_order m = memory_order_seq_cst) const volatile noexcept;
        T* load(memory_order m = memory_order_seq_cst) const noexcept;
        operator T*() const volatile noexcept;
        operator T*() const noexcept;
        T* exchange(T* desr, memory_order m = memory_order_seq_cst) volatile noexcept;
        T* exchange(T* desr, memory_order m = memory_order_seq_cst) noexcept;
        bool compare_exchange_weak(T*& expc, T* desr, memory_order s, memory_order f) volatile noexcept;
        bool compare_exchange_weak(T*& expc, T* desr, memory_order s, memory_order f) noexcept;
        bool compare_exchange_strong(T*& expc, T* desr, memory_order s, memory_order f) volatile noexcept;
        bool compare_exchange_strong(T*& expc, T* desr, memory_order s, memory_order f) noexcept;
        bool compare_exchange_weak(T*& expc, T* desr, memory_order m = memory_order_seq_cst) volatile noexcept;
        bool compare_exchange_weak(T*& expc, T* desr, memory_order m = memory_order_seq_cst) noexcept;
        bool compare_exchange_strong(T*& expc, T* desr, memory_order m = memory_order_seq_cst) volatile noexcept;
        bool compare_exchange_strong(T*& expc, T* desr, memory_order m = memory_order_seq_cst) noexcept;
        T* fetch_add(ptrdiff_t op, memory_order m = memory_order_seq_cst) volatile noexcept;
        T* fetch_add(ptrdiff_t op, memory_order m = memory_order_seq_cst) noexcept;
        T* fetch_sub(ptrdiff_t op, memory_order m = memory_order_seq_cst) volatile noexcept;
        T* fetch_sub(ptrdiff_t op, memory_order m = memory_order_seq_cst) noexcept;

        atomic() noexcept = default;
        constexpr atomic(T* desr) noexcept;
        atomic(const atomic&) = delete;
        atomic& operator=(const atomic&) = delete;
        atomic& operator=(const atomic&) volatile = delete;

        T* operator=(T*) volatile noexcept;
        T* operator=(T*) noexcept;
        T* operator++(int) volatile noexcept;
        T* operator++(int) noexcept;
        T* operator--(int) volatile noexcept;
        T* operator--(int) noexcept;
        T* operator++() volatile noexcept;
        T* operator++() noexcept;
        T* operator--() volatile noexcept;
        T* operator--() noexcept;
        T* operator+=(ptrdiff_t op) volatile noexcept;
        T* operator+=(ptrdiff_t op) noexcept;
        T* operator-=(ptrdiff_t op) volatile noexcept;
        T* operator-=(ptrdiff_t op) noexcept;
    };

    template <class T>
    bool atomic_is_lock_free(const volatile atomic<T>* obj) noexcept;

    template <class T>
    bool atomic_is_lock_free(const atomic<T>* obj) noexcept;

    template <class T>
    void atomic_init(volatile atomic<T>* obj, T desr) noexcept;

    template <class T>
    void atomic_init(atomic<T>* obj, T desr) noexcept;

    template <class T>
    void atomic_store(volatile atomic<T>* obj, T desr) noexcept;

    template <class T>
    void atomic_store(atomic<T>* obj, T desr) noexcept;

    template <class T>
    void atomic_store_explicit(volatile atomic<T>* obj, T desr, memory_order m) noexcept;

    template <class T>
    void atomic_store_explicit(atomic<T>* obj, T desr, memory_order m) noexcept;

    template <class T>
    T atomic_load(const volatile atomic<T>* obj) noexcept;

    template <class T>
    T atomic_load(const atomic<T>* obj) noexcept;

    template <class T>
    T atomic_load_explicit(const volatile atomic<T>* obj, memory_order m) noexcept;

    template <class T>
    T atomic_load_explicit(const atomic<T>* obj, memory_order m) noexcept;

    template <class T>
    T atomic_exchange(volatile atomic<T>* obj, T desr) noexcept;

    template <class T>
    T atomic_exchange(atomic<T>* obj, T desr) noexcept;

    template <class T>
    T atomic_exchange_explicit(volatile atomic<T>* obj, T desr, memory_order m) noexcept;

    template <class T>
    T atomic_exchange_explicit(atomic<T>* obj, T desr, memory_order m) noexcept;

    template <class T>
    bool atomic_compare_exchange_weak(volatile atomic<T>* obj, T* expc, T desr) noexcept;

    template <class T>
    bool atomic_compare_exchange_weak(atomic<T>* obj, T* expc, T desr) noexcept;

    template <class T>
    bool atomic_compare_exchange_strong(volatile atomic<T>* obj, T* expc, T desr) noexcept;

    template <class T>
    bool atomic_compare_exchange_strong(atomic<T>* obj, T* expc, T desr) noexcept;

    template <class T>
    bool atomic_compare_exchange_weak_explicit(volatile atomic<T>* obj, T* expc, T desr, memory_order s,
                                               memory_order f) noexcept;

    template <class T>
    bool atomic_compare_exchange_weak_explicit(atomic<T>* obj, T* expc, T desr, memory_order s,
                                               memory_order f) noexcept;

    template <class T>
    bool atomic_compare_exchange_strong_explicit(volatile atomic<T>* obj, T* expc, T desr, memory_order s,
                                                 memory_order f) noexcept;

    template <class T>
    bool atomic_compare_exchange_strong_explicit(atomic<T>* obj, T* expc, T desr, memory_order s,
                                                 memory_order f) noexcept;

    template <class Integral>
    Integral atomic_fetch_add(volatile atomic<Integral>* obj, Integral op) noexcept;

    template <class Integral>
    Integral atomic_fetch_add(atomic<Integral>* obj, Integral op) noexcept;

    template <class Integral>
    Integral atomic_fetch_add_explicit(volatile atomic<Integral>* obj, Integral op, memory_order m) noexcept;
    template <class Integral>
    Integral atomic_fetch_add_explicit(atomic<Integral>* obj, Integral op, memory_order m) noexcept;
    template <class Integral>
    Integral atomic_fetch_sub(volatile atomic<Integral>* obj, Integral op) noexcept;

    template <class Integral>
    Integral atomic_fetch_sub(atomic<Integral>* obj, Integral op) noexcept;

    template <class Integral>
    Integral atomic_fetch_sub_explicit(volatile atomic<Integral>* obj, Integral op, memory_order m) noexcept;
    template <class Integral>
    Integral atomic_fetch_sub_explicit(atomic<Integral>* obj, Integral op, memory_order m) noexcept;
    template <class Integral>
    Integral atomic_fetch_and(volatile atomic<Integral>* obj, Integral op) noexcept;

    template <class Integral>
    Integral atomic_fetch_and(atomic<Integral>* obj, Integral op) noexcept;

    template <class Integral>
    Integral atomic_fetch_and_explicit(volatile atomic<Integral>* obj, Integral op, memory_order m) noexcept;
    template <class Integral>
    Integral atomic_fetch_and_explicit(atomic<Integral>* obj, Integral op, memory_order m) noexcept;
    template <class Integral>
    Integral atomic_fetch_or(volatile atomic<Integral>* obj, Integral op) noexcept;

    template <class Integral>
    Integral atomic_fetch_or(atomic<Integral>* obj, Integral op) noexcept;

    template <class Integral>
    Integral atomic_fetch_or_explicit(volatile atomic<Integral>* obj, Integral op, memory_order m) noexcept;
    template <class Integral>
    Integral atomic_fetch_or_explicit(atomic<Integral>* obj, Integral op, memory_order m) noexcept;
    template <class Integral>
    Integral atomic_fetch_xor(volatile atomic<Integral>* obj, Integral op) noexcept;

    template <class Integral>
    Integral atomic_fetch_xor(atomic<Integral>* obj, Integral op) noexcept;

    template <class Integral>
    Integral atomic_fetch_xor_explicit(volatile atomic<Integral>* obj, Integral op, memory_order m) noexcept;
    template <class Integral>
    Integral atomic_fetch_xor_explicit(atomic<Integral>* obj, Integral op, memory_order m) noexcept;

    template <class T>
    T* atomic_fetch_add(volatile atomic<T*>* obj, ptrdiff_t op) noexcept;

    template <class T>
    T* atomic_fetch_add(atomic<T*>* obj, ptrdiff_t op) noexcept;

    template <class T>
    T* atomic_fetch_add_explicit(volatile atomic<T*>* obj, ptrdiff_t op, memory_order m) noexcept;
    template <class T>
    T* atomic_fetch_add_explicit(atomic<T*>* obj, ptrdiff_t op, memory_order m) noexcept;

    template <class T>
    T* atomic_fetch_sub(volatile atomic<T*>* obj, ptrdiff_t op) noexcept;

    template <class T>
    T* atomic_fetch_sub(atomic<T*>* obj, ptrdiff_t op) noexcept;

    template <class T>
    T* atomic_fetch_sub_explicit(volatile atomic<T*>* obj, ptrdiff_t op, memory_order m) noexcept;
    template <class T>
    T* atomic_fetch_sub_explicit(atomic<T*>* obj, ptrdiff_t op, memory_order m) noexcept;

    // Atomics for standard typedef types

    typedef atomic<bool> atomic_bool;
    typedef atomic<char> atomic_char;
    typedef atomic<signed char> atomic_schar;
    typedef atomic<unsigned char> atomic_uchar;
    typedef atomic<short> atomic_short;
    typedef atomic<unsigned short> atomic_ushort;
    typedef atomic<int> atomic_int;
    typedef atomic<unsigned int> atomic_uint;
    typedef atomic<long> atomic_long;
    typedef atomic<unsigned long> atomic_ulong;
    typedef atomic<long long> atomic_llong;
    typedef atomic<unsigned long long> atomic_ullong;
    typedef atomic<char16_t> atomic_char16_t;
    typedef atomic<char32_t> atomic_char32_t;
    typedef atomic<wchar_t> atomic_wchar_t;

    typedef atomic<int_least8_t> atomic_int_least8_t;
    typedef atomic<uint_least8_t> atomic_uint_least8_t;
    typedef atomic<int_least16_t> atomic_int_least16_t;
    typedef atomic<uint_least16_t> atomic_uint_least16_t;
    typedef atomic<int_least32_t> atomic_int_least32_t;
    typedef atomic<uint_least32_t> atomic_uint_least32_t;
    typedef atomic<int_least64_t> atomic_int_least64_t;
    typedef atomic<uint_least64_t> atomic_uint_least64_t;

    typedef atomic<int_fast8_t> atomic_int_fast8_t;
    typedef atomic<uint_fast8_t> atomic_uint_fast8_t;
    typedef atomic<int_fast16_t> atomic_int_fast16_t;
    typedef atomic<uint_fast16_t> atomic_uint_fast16_t;
    typedef atomic<int_fast32_t> atomic_int_fast32_t;
    typedef atomic<uint_fast32_t> atomic_uint_fast32_t;
    typedef atomic<int_fast64_t> atomic_int_fast64_t;
    typedef atomic<uint_fast64_t> atomic_uint_fast64_t;

    typedef atomic<int8_t> atomic_int8_t;
    typedef atomic<uint8_t> atomic_uint8_t;
    typedef atomic<int16_t> atomic_int16_t;
    typedef atomic<uint16_t> atomic_uint16_t;
    typedef atomic<int32_t> atomic_int32_t;
    typedef atomic<uint32_t> atomic_uint32_t;
    typedef atomic<int64_t> atomic_int64_t;
    typedef atomic<uint64_t> atomic_uint64_t;

    typedef atomic<intptr_t> atomic_intptr_t;
    typedef atomic<uintptr_t> atomic_uintptr_t;
    typedef atomic<size_t> atomic_size_t;
    typedef atomic<ptrdiff_t> atomic_ptrdiff_t;
    typedef atomic<intmax_t> atomic_intmax_t;
    typedef atomic<uintmax_t> atomic_uintmax_t;

    // fences

    void atomic_thread_fence(memory_order m) noexcept;
    void atomic_signal_fence(memory_order m) noexcept;

}  // namespace GP

#endif  // ATOMIC_HPP
