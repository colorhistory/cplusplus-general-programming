﻿#ifndef MEMORY_HPP
#define MEMORY_HPP

#include "bits/stdc++.h"

namespace GP {

    struct allocator_arg_t {};
    inline constexpr allocator_arg_t allocator_arg = allocator_arg_t();

    template <class T, class Alloc>
    struct uses_allocator;

    template <class Ptr>
    struct pointer_traits {
        typedef Ptr pointer;
        typedef Ptr element_type;
        typedef Ptr difference_type;

        template <class U>
        using rebind = Ptr;

        static pointer pointer_to(Ptr);
    };

    template <class T>
    struct pointer_traits<T*> {
        typedef T* pointer;
        typedef T element_type;
        typedef ptrdiff_t difference_type;

        template <class U>
        using rebind = U*;

        static pointer pointer_to(Ptr) noexcept;  // constexpr in C++20
    };

    template <class T>
    constexpr T* to_address(T* p) noexcept;  // C++20
    template <class Ptr>
    auto to_address(const Ptr& p) noexcept;  // C++20

    template <class Alloc>
    struct allocator_traits {
        typedef Alloc allocator_type;
        typedef typename allocator_type::value_type value_type;

        typedef((Alloc::pointer) | (value_type*)) pointer;
        typedef Alloc::const_pointer | pointer_traits<pointer>::rebind<const value_type> const_pointer;
        typedef Alloc::void_pointer | pointer_traits<pointer>::rebind<void> void_pointer;
        typedef Alloc::const_void_pointer | pointer_traits<pointer>::rebind<const void> const_void_pointer;
        typedef Alloc::difference_type | pointer_traits<pointer>::difference_type difference_type;
        typedef Alloc::size_type | make_unsigned<difference_type>::type size_type;
        typedef Alloc::propagate_on_container_copy_assignment | false_type propagate_on_container_copy_assignment;
        typedef Alloc::propagate_on_container_move_assignment | false_type propagate_on_container_move_assignment;
        typedef Alloc::propagate_on_container_swap | false_type propagate_on_container_swap;
        typedef Alloc::is_always_equal | is_empty is_always_equal;

        template <class T>
        using rebind_alloc = Alloc::rebind<U>::other | Alloc<T, Args...>;
        template <class T>
        using rebind_traits = allocator_traits<rebind_alloc<T>>;

        static pointer allocate(allocator_type& a, size_type n);                           // [[nodiscard]] in C++20
        static pointer allocate(allocator_type& a, size_type n, const_void_pointer hint);  // [[nodiscard]] in C++20

        static void deallocate(allocator_type& a, pointer p, size_type n) noexcept;

        template <class T, class... Args>
        static void construct(allocator_type& a, T* p, Args&&... args);

        template <class T>
        static void destroy(allocator_type& a, T* p);

        static size_type max_size(const allocator_type& a);  // noexcept in C++14

        static allocator_type select_on_container_copy_construction(const allocator_type& a);
    };

    template <>
    class allocator<void> {
      public:
        typedef void* pointer;
        typedef const void* const_pointer;
        typedef void value_type;

        template <class _Up>
        struct rebind {
            typedef allocator<_Up> other;
        };
    };

    template <class T>
    class allocator {
      public:
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef typename add_lvalue_reference<T>::type reference;
        typedef typename add_lvalue_reference<const T>::type const_reference;
        typedef T value_type;

        template <class U>
        struct rebind {
            typedef allocator<U> other;
        };

        constexpr allocator() noexcept;                  // constexpr in C++20
        constexpr allocator(const allocator&) noexcept;  // constexpr in C++20
        template <class U>
        constexpr allocator(const allocator<U>&) noexcept;  // constexpr in C++20
        ~allocator();
        pointer address(reference x) const noexcept;
        const_pointer address(const_reference x) const noexcept;
        pointer allocate(size_type, allocator<void>::const_pointer hint = 0);
        void deallocate(pointer p, size_type n) noexcept;
        size_type max_size() const noexcept;
        template <class U, class... Args>
        void construct(U* p, Args&&... args);
        template <class U>
        void destroy(U* p);
    };

    template <class T, class U>
    bool operator==(const allocator<T>&, const allocator<U>&) noexcept;

    template <class T, class U>
    bool operator!=(const allocator<T>&, const allocator<U>&) noexcept;

    template <class OutputIterator, class T>
    class raw_storage_iterator : public iterator<output_iterator_tag,
                                                 T,                      // purposefully not C++03
                                                 ptrdiff_t,              // purposefully not C++03
                                                 T*,                     // purposefully not C++03
                                                 raw_storage_iterator&>  // purposefully not C++03
    {
      public:
        explicit raw_storage_iterator(OutputIterator x);
        raw_storage_iterator& operator*();
        raw_storage_iterator& operator=(const T& element);
        raw_storage_iterator& operator++();
        raw_storage_iterator operator++(int);
    };

    template <class T>
    pair<T*, ptrdiff_t> get_temporary_buffer(ptrdiff_t n) noexcept;
    template <class T>
    void return_temporary_buffer(T* p) noexcept;

    template <class T>
    T* addressof(T& r) noexcept;
    template <class T>
    T* addressof(const T&& r) noexcept = delete;

    template <class InputIterator, class ForwardIterator>
    ForwardIterator uninitialized_copy(InputIterator first, InputIterator last, ForwardIterator result);

    template <class InputIterator, class Size, class ForwardIterator>
    ForwardIterator uninitialized_copy_n(InputIterator first, Size n, ForwardIterator result);

    template <class ForwardIterator, class T>
    void uninitialized_fill(ForwardIterator first, ForwardIterator last, const T& x);

    template <class ForwardIterator, class Size, class T>
    ForwardIterator uninitialized_fill_n(ForwardIterator first, Size n, const T& x);

    template <class T>
    void destroy_at(T* location);

    template <class ForwardIterator>
    void destroy(ForwardIterator first, ForwardIterator last);

    template <class ForwardIterator, class Size>
    ForwardIterator destroy_n(ForwardIterator first, Size n);

    template <class InputIterator, class ForwardIterator>
    ForwardIterator uninitialized_move(InputIterator first, InputIterator last, ForwardIterator result);

    template <class InputIterator, class Size, class ForwardIterator>
    pair<InputIterator, ForwardIterator> uninitialized_move_n(InputIterator first, Size n, ForwardIterator result);

    template <class ForwardIterator>
    void uninitialized_value_construct(ForwardIterator first, ForwardIterator last);

    template <class ForwardIterator, class Size>
    ForwardIterator uninitialized_value_construct_n(ForwardIterator first, Size n);

    template <class ForwardIterator>
    void uninitialized_default_construct(ForwardIterator first, ForwardIterator last);

    template <class ForwardIterator, class Size>
    ForwardIterator uninitialized_default_construct_n(ForwardIterator first, Size n);

    template <class Y>
    struct auto_ptr_ref {};  // deprecated in C++11, removed in C++17

    template <class X>
    class auto_ptr  // deprecated in C++11, removed in C++17
    {
      public:
        typedef X element_type;

        explicit auto_ptr(X* p = 0) throw();
        auto_ptr(auto_ptr&) throw();
        template <class Y>
        auto_ptr(auto_ptr<Y>&) throw();
        auto_ptr& operator=(auto_ptr&) throw();
        template <class Y>
        auto_ptr& operator=(auto_ptr<Y>&) throw();
        auto_ptr& operator=(auto_ptr_ref<X> r) throw();
        ~auto_ptr() throw();

        typename add_lvalue_reference<X>::type operator*() const throw();
        X* operator->() const throw();
        X* get() const throw();
        X* release() throw();
        void reset(X* p = 0) throw();

        auto_ptr(auto_ptr_ref<X>) throw();
        template <class Y>
        operator auto_ptr_ref<Y>() throw();
        template <class Y>
        operator auto_ptr<Y>() throw();
    };

    template <class T>
    struct default_delete {
        constexpr default_delete() noexcept = default;
        template <class U>
        default_delete(const default_delete<U>&) noexcept;

        void operator()(T*) const noexcept;
    };

    template <class T>
    struct default_delete<T[]> {
        constexpr default_delete() noexcept = default;
        void operator()(T*) const noexcept;
        template <class U>
        void operator()(U*) const = delete;
    };

    template <class T, class D = default_delete<T>>
    class unique_ptr {
      public:
        typedef see below pointer;
        typedef T element_type;
        typedef D deleter_type;

        // constructors
        constexpr unique_ptr() noexcept;
        explicit unique_ptr(pointer p) noexcept;
        unique_ptr(pointer p, see below d1) noexcept;
        unique_ptr(pointer p, see below d2) noexcept;
        unique_ptr(unique_ptr&& u) noexcept;
        unique_ptr(nullptr_t) noexcept : unique_ptr() {
        }
        template <class U, class E>
        unique_ptr(unique_ptr<U, E>&& u) noexcept;
        template <class U>
        unique_ptr(auto_ptr<U>&& u) noexcept;  // removed in C++17

        // destructor
        ~unique_ptr();

        // assignment
        unique_ptr& operator=(unique_ptr&& u) noexcept;
        template <class U, class E>
        unique_ptr& operator=(unique_ptr<U, E>&& u) noexcept;
        unique_ptr& operator=(nullptr_t) noexcept;

        // observers
        typename add_lvalue_reference<T>::type operator*() const;
        pointer operator->() const noexcept;
        pointer get() const noexcept;
        deleter_type& get_deleter() noexcept;
        const deleter_type& get_deleter() const noexcept;
        explicit operator bool() const noexcept;

        // modifiers
        pointer release() noexcept;
        void reset(pointer p = pointer()) noexcept;
        void swap(unique_ptr& u) noexcept;
    };

    template <class T, class D>
    class unique_ptr<T[], D> {
      public:
        typedef implementation - defined pointer;
        typedef T element_type;
        typedef D deleter_type;

        // constructors
        constexpr unique_ptr() noexcept;
        explicit unique_ptr(pointer p) noexcept;
        unique_ptr(pointer p, see below d) noexcept;
        unique_ptr(pointer p, see below d) noexcept;
        unique_ptr(unique_ptr&& u) noexcept;
        unique_ptr(nullptr_t) noexcept : unique_ptr() {
        }

        // destructor
        ~unique_ptr();

        // assignment
        unique_ptr& operator=(unique_ptr&& u) noexcept;
        unique_ptr& operator=(nullptr_t) noexcept;

        // observers
        T& operator[](size_t i) const;
        pointer get() const noexcept;
        deleter_type& get_deleter() noexcept;
        const deleter_type& get_deleter() const noexcept;
        explicit operator bool() const noexcept;

        // modifiers
        pointer release() noexcept;
        void reset(pointer p = pointer()) noexcept;
        void reset(nullptr_t) noexcept;
        template <class U>
        void reset(U) = delete;
        void swap(unique_ptr& u) noexcept;
    };

    template <class T, class D>
    void swap(unique_ptr<T, D>& x, unique_ptr<T, D>& y) noexcept;

    template <class T1, class D1, class T2, class D2>
    bool operator==(const unique_ptr<T1, D1>& x, const unique_ptr<T2, D2>& y);
    template <class T1, class D1, class T2, class D2>
    bool operator!=(const unique_ptr<T1, D1>& x, const unique_ptr<T2, D2>& y);
    template <class T1, class D1, class T2, class D2>
    bool operator<(const unique_ptr<T1, D1>& x, const unique_ptr<T2, D2>& y);
    template <class T1, class D1, class T2, class D2>
    bool operator<=(const unique_ptr<T1, D1>& x, const unique_ptr<T2, D2>& y);
    template <class T1, class D1, class T2, class D2>
    bool operator>(const unique_ptr<T1, D1>& x, const unique_ptr<T2, D2>& y);
    template <class T1, class D1, class T2, class D2>
    bool operator>=(const unique_ptr<T1, D1>& x, const unique_ptr<T2, D2>& y);

    template <class T, class D>
    bool operator==(const unique_ptr<T, D>& x, nullptr_t) noexcept;
    template <class T, class D>
    bool operator==(nullptr_t, const unique_ptr<T, D>& y) noexcept;
    template <class T, class D>
    bool operator!=(const unique_ptr<T, D>& x, nullptr_t) noexcept;
    template <class T, class D>
    bool operator!=(nullptr_t, const unique_ptr<T, D>& y) noexcept;

    template <class T, class D>
    bool operator<(const unique_ptr<T, D>& x, nullptr_t);
    template <class T, class D>
    bool operator<(nullptr_t, const unique_ptr<T, D>& y);
    template <class T, class D>
    bool operator<=(const unique_ptr<T, D>& x, nullptr_t);
    template <class T, class D>
    bool operator<=(nullptr_t, const unique_ptr<T, D>& y);
    template <class T, class D>
    bool operator>(const unique_ptr<T, D>& x, nullptr_t);
    template <class T, class D>
    bool operator>(nullptr_t, const unique_ptr<T, D>& y);
    template <class T, class D>
    bool operator>=(const unique_ptr<T, D>& x, nullptr_t);
    template <class T, class D>
    bool operator>=(nullptr_t, const unique_ptr<T, D>& y);

    class bad_weak_ptr : public std::exception {
        bad_weak_ptr() noexcept;
    };

    template <class T, class... Args>
    unique_ptr<T> make_unique(Args&&... args);  // C++14
    template <class T>
    unique_ptr<T> make_unique(size_t n);  // C++14
    template <class T, class... Args>
    unspecified make_unique(Args&&...) = delete;  // C++14, T == U[N]

    template <class E, class T, class Y, class D>
    basic_ostream<E, T>& operator<<(basic_ostream<E, T>& os, unique_ptr<Y, D> const& p);

    template <class T>
    class shared_ptr {
      public:
        typedef T element_type;
        typedef weak_ptr<T> weak_type;  // C++17

        // constructors:
        constexpr shared_ptr() noexcept;
        template <class Y>
        explicit shared_ptr(Y* p);
        template <class Y, class D>
        shared_ptr(Y* p, D d);
        template <class Y, class D, class A>
        shared_ptr(Y* p, D d, A a);
        template <class D>
        shared_ptr(nullptr_t p, D d);
        template <class D, class A>
        shared_ptr(nullptr_t p, D d, A a);
        template <class Y>
        shared_ptr(const shared_ptr<Y>& r, T* p) noexcept;
        shared_ptr(const shared_ptr& r) noexcept;
        template <class Y>
        shared_ptr(const shared_ptr<Y>& r) noexcept;
        shared_ptr(shared_ptr&& r) noexcept;
        template <class Y>
        shared_ptr(shared_ptr<Y>&& r) noexcept;
        template <class Y>
        explicit shared_ptr(const weak_ptr<Y>& r);
        template <class Y>
        shared_ptr(auto_ptr<Y>&& r);  // removed in C++17
        template <class Y, class D>
        shared_ptr(unique_ptr<Y, D>&& r);
        shared_ptr(nullptr_t) : shared_ptr() {
        }

        // destructor:
        ~shared_ptr();

        // assignment:
        shared_ptr& operator=(const shared_ptr& r) noexcept;
        template <class Y>
        shared_ptr& operator=(const shared_ptr<Y>& r) noexcept;
        shared_ptr& operator=(shared_ptr&& r) noexcept;
        template <class Y>
        shared_ptr& operator=(shared_ptr<Y>&& r);
        template <class Y>
        shared_ptr& operator=(auto_ptr<Y>&& r);  // removed in C++17
        template <class Y, class D>
        shared_ptr& operator=(unique_ptr<Y, D>&& r);

        // modifiers:
        void swap(shared_ptr& r) noexcept;
        void reset() noexcept;
        template <class Y>
        void reset(Y* p);
        template <class Y, class D>
        void reset(Y* p, D d);
        template <class Y, class D, class A>
        void reset(Y* p, D d, A a);

        // observers:
        T* get() const noexcept;
        T& operator*() const noexcept;
        T* operator->() const noexcept;
        long use_count() const noexcept;
        bool unique() const noexcept;
        explicit operator bool() const noexcept;
        template <class U>
        bool owner_before(shared_ptr<U> const& b) const noexcept;
        template <class U>
        bool owner_before(weak_ptr<U> const& b) const noexcept;
    };

    // shared_ptr comparisons:
    template <class T, class U>
    bool operator==(shared_ptr<T> const& a, shared_ptr<U> const& b) noexcept;
    template <class T, class U>
    bool operator!=(shared_ptr<T> const& a, shared_ptr<U> const& b) noexcept;
    template <class T, class U>
    bool operator<(shared_ptr<T> const& a, shared_ptr<U> const& b) noexcept;
    template <class T, class U>
    bool operator>(shared_ptr<T> const& a, shared_ptr<U> const& b) noexcept;
    template <class T, class U>
    bool operator<=(shared_ptr<T> const& a, shared_ptr<U> const& b) noexcept;
    template <class T, class U>
    bool operator>=(shared_ptr<T> const& a, shared_ptr<U> const& b) noexcept;

    template <class T>
    bool operator==(const shared_ptr<T>& x, nullptr_t) noexcept;
    template <class T>
    bool operator==(nullptr_t, const shared_ptr<T>& y) noexcept;
    template <class T>
    bool operator!=(const shared_ptr<T>& x, nullptr_t) noexcept;
    template <class T>
    bool operator!=(nullptr_t, const shared_ptr<T>& y) noexcept;
    template <class T>
    bool operator<(const shared_ptr<T>& x, nullptr_t) noexcept;
    template <class T>
    bool operator<(nullptr_t, const shared_ptr<T>& y) noexcept;
    template <class T>
    bool operator<=(const shared_ptr<T>& x, nullptr_t) noexcept;
    template <class T>
    bool operator<=(nullptr_t, const shared_ptr<T>& y) noexcept;
    template <class T>
    bool operator>(const shared_ptr<T>& x, nullptr_t) noexcept;
    template <class T>
    bool operator>(nullptr_t, const shared_ptr<T>& y) noexcept;
    template <class T>
    bool operator>=(const shared_ptr<T>& x, nullptr_t) noexcept;
    template <class T>
    bool operator>=(nullptr_t, const shared_ptr<T>& y) noexcept;

    // shared_ptr specialized algorithms:
    template <class T>
    void swap(shared_ptr<T>& a, shared_ptr<T>& b) noexcept;

    // shared_ptr casts:
    template <class T, class U>
    shared_ptr<T> static_pointer_cast(shared_ptr<U> const& r) noexcept;
    template <class T, class U>
    shared_ptr<T> dynamic_pointer_cast(shared_ptr<U> const& r) noexcept;
    template <class T, class U>
    shared_ptr<T> const_pointer_cast(shared_ptr<U> const& r) noexcept;

    // shared_ptr I/O:
    template <class E, class T, class Y>
    basic_ostream<E, T>& operator<<(basic_ostream<E, T>& os, shared_ptr<Y> const& p);

    // shared_ptr get_deleter:
    template <class D, class T>
    D* get_deleter(shared_ptr<T> const& p) noexcept;

    template <class T, class... Args>
    shared_ptr<T> make_shared(Args&&... args);
    template <class T, class A, class... Args>
    shared_ptr<T> allocate_shared(const A& a, Args&&... args);

    template <class T>
    class weak_ptr {
      public:
        typedef T element_type;

        // constructors
        constexpr weak_ptr() noexcept;
        template <class Y>
        weak_ptr(shared_ptr<Y> const& r) noexcept;
        weak_ptr(weak_ptr const& r) noexcept;
        template <class Y>
        weak_ptr(weak_ptr<Y> const& r) noexcept;
        weak_ptr(weak_ptr&& r) noexcept;  // C++14
        template <class Y>
        weak_ptr(weak_ptr<Y>&& r) noexcept;  // C++14

        // destructor
        ~weak_ptr();

        // assignment
        weak_ptr& operator=(weak_ptr const& r) noexcept;
        template <class Y>
        weak_ptr& operator=(weak_ptr<Y> const& r) noexcept;
        template <class Y>
        weak_ptr& operator=(shared_ptr<Y> const& r) noexcept;
        weak_ptr& operator=(weak_ptr&& r) noexcept;  // C++14
        template <class Y>
        weak_ptr& operator=(weak_ptr<Y>&& r) noexcept;  // C++14

        // modifiers
        void swap(weak_ptr& r) noexcept;
        void reset() noexcept;

        // observers
        long use_count() const noexcept;
        bool expired() const noexcept;
        shared_ptr<T> lock() const noexcept;
        template <class U>
        bool owner_before(shared_ptr<U> const& b) const noexcept;
        template <class U>
        bool owner_before(weak_ptr<U> const& b) const noexcept;
    };

    // weak_ptr specialized algorithms:
    template <class T>
    void swap(weak_ptr<T>& a, weak_ptr<T>& b) noexcept;

    // class owner_less:
    template <class T>
    struct owner_less;

    template <class T>
    struct owner_less<shared_ptr<T>> : binary_function<shared_ptr<T>, shared_ptr<T>, bool> {
        typedef bool result_type;
        bool operator()(shared_ptr<T> const&, shared_ptr<T> const&) const noexcept;
        bool operator()(shared_ptr<T> const&, weak_ptr<T> const&) const noexcept;
        bool operator()(weak_ptr<T> const&, shared_ptr<T> const&) const noexcept;
    };

    template <class T>
    struct owner_less<weak_ptr<T>> : binary_function<weak_ptr<T>, weak_ptr<T>, bool> {
        typedef bool result_type;
        bool operator()(weak_ptr<T> const&, weak_ptr<T> const&) const noexcept;
        bool operator()(shared_ptr<T> const&, weak_ptr<T> const&) const noexcept;
        bool operator()(weak_ptr<T> const&, shared_ptr<T> const&) const noexcept;
    };

    template <>  // Added in C++14
    struct owner_less<void> {
        template <class _Tp, class _Up>
        bool operator()(shared_ptr<_Tp> const& __x, shared_ptr<_Up> const& __y) const noexcept;
        template <class _Tp, class _Up>
        bool operator()(shared_ptr<_Tp> const& __x, weak_ptr<_Up> const& __y) const noexcept;
        template <class _Tp, class _Up>
        bool operator()(weak_ptr<_Tp> const& __x, shared_ptr<_Up> const& __y) const noexcept;
        template <class _Tp, class _Up>
        bool operator()(weak_ptr<_Tp> const& __x, weak_ptr<_Up> const& __y) const noexcept;

        typedef void is_transparent;
    };

    template <class T>
    class enable_shared_from_this {
      protected:
        constexpr enable_shared_from_this() noexcept;
        enable_shared_from_this(enable_shared_from_this const&) noexcept;
        enable_shared_from_this& operator=(enable_shared_from_this const&) noexcept;
        ~enable_shared_from_this();

      public:
        shared_ptr<T> shared_from_this();
        shared_ptr<T const> shared_from_this() const;
    };

    template <class T>
    bool atomic_is_lock_free(const shared_ptr<T>* p);
    template <class T>
    shared_ptr<T> atomic_load(const shared_ptr<T>* p);
    template <class T>
    shared_ptr<T> atomic_load_explicit(const shared_ptr<T>* p, memory_order mo);
    template <class T>
    void atomic_store(shared_ptr<T>* p, shared_ptr<T> r);
    template <class T>
    void atomic_store_explicit(shared_ptr<T>* p, shared_ptr<T> r, memory_order mo);
    template <class T>
    shared_ptr<T> atomic_exchange(shared_ptr<T>* p, shared_ptr<T> r);
    template <class T>
    shared_ptr<T> atomic_exchange_explicit(shared_ptr<T>* p, shared_ptr<T> r, memory_order mo);
    template <class T>
    bool atomic_compare_exchange_weak(shared_ptr<T>* p, shared_ptr<T>* v, shared_ptr<T> w);
    template <class T>
    bool atomic_compare_exchange_strong(shared_ptr<T>* p, shared_ptr<T>* v, shared_ptr<T> w);
    template <class T>
    bool atomic_compare_exchange_weak_explicit(shared_ptr<T>* p, shared_ptr<T>* v, shared_ptr<T> w,
                                               memory_order success, memory_order failure);
    template <class T>
    bool atomic_compare_exchange_strong_explicit(shared_ptr<T>* p, shared_ptr<T>* v, shared_ptr<T> w,
                                                 memory_order success, memory_order failure);
    // Hash support
    template <class T>
    struct hash;
    template <class T, class D>
    struct hash<unique_ptr<T, D>>;
    template <class T>
    struct hash<shared_ptr<T>>;

    template <class T, class Alloc>
    inline constexpr bool uses_allocator_v = uses_allocator<T, Alloc>::value;

    // Pointer safety
    enum class pointer_safety { relaxed, preferred, strict };
    void declare_reachable(void* p);
    template <class T>
    T* undeclare_reachable(T* p);
    void declare_no_pointers(char* p, size_t n);
    void undeclare_no_pointers(char* p, size_t n);
    pointer_safety get_pointer_safety() noexcept;

    void* align(size_t alignment, size_t size, void*& ptr, size_t& space);

}  // namespace GP

#endif  // MEMORY_HPP
