#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "bits/stdc++.h"

namespace GP {
    template <class T, size_t N>
    struct array {
        // types:
        typedef T& reference;
        typedef const T& const_reference;
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

        // No explicit construct/copy/destroy for aggregate type
        void fill(const T& u);
        void swap(array& a) noexcept(std::is_nothrow_swappable_v<T>);

        // iterators:
        iterator begin() noexcept;
        const_iterator begin() const noexcept;
        iterator end() noexcept;
        const_iterator end() const noexcept;

        reverse_iterator rbegin() noexcept;
        const_reverse_iterator rbegin() const noexcept;
        reverse_iterator rend() noexcept;
        const_reverse_iterator rend() const noexcept;

        const_iterator cbegin() const noexcept;
        const_iterator cend() const noexcept;
        const_reverse_iterator crbegin() const noexcept;
        const_reverse_iterator crend() const noexcept;

        // capacity:
        constexpr size_type size() const noexcept;
        constexpr size_type max_size() const noexcept;
        constexpr bool empty() const noexcept;

        // element access:
        reference operator[](size_type n);
        const_reference operator[](size_type n) const;  // constexpr in C++14
        const_reference at(size_type n) const;          // constexpr in C++14
        reference at(size_type n);

        reference front();
        const_reference front() const;  // constexpr in C++14
        reference back();
        const_reference back() const;  // constexpr in C++14

        T* data() noexcept;
        const T* data() const noexcept;
    };

    template <class T, class... U>
    array(T, U...)->array<T, 1 + sizeof...(U)>;

    template <class T, size_t N>
    bool operator==(const array<T, N>& x, const array<T, N>& y);
    template <class T, size_t N>
    bool operator!=(const array<T, N>& x, const array<T, N>& y);
    template <class T, size_t N>
    bool operator<(const array<T, N>& x, const array<T, N>& y);
    template <class T, size_t N>
    bool operator>(const array<T, N>& x, const array<T, N>& y);
    template <class T, size_t N>
    bool operator<=(const array<T, N>& x, const array<T, N>& y);
    template <class T, size_t N>
    bool operator>=(const array<T, N>& x, const array<T, N>& y);

    template <class T, size_t N>
    void swap(array<T, N>& x, array<T, N>& y) noexcept(noexcept(x.swap(y)));  // C++17

    template <class T>
    struct tuple_size;
    template <size_t I, class T>
    class tuple_element;
    template <class T, size_t N>
    struct tuple_size<array<T, N>>;
    template <size_t I, class T, size_t N>
    struct tuple_element<I, array<T, N>>;
    template <size_t I, class T, size_t N>
    T& get(array<T, N>&) noexcept;  // constexpr in C++14
    template <size_t I, class T, size_t N>
    const T& get(const array<T, N>&) noexcept;  // constexpr in C++14
    template <size_t I, class T, size_t N>
    T&& get(array<T, N>&&) noexcept;  // constexpr in C++14
    template <size_t I, class T, size_t N>
    const T&& get(const array<T, N>&&) noexcept;  // constexpr in C++14

}  // namespace GP

#endif  // ARRAY_HPP
