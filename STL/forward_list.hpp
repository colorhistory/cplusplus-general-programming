#ifndef FORWARD_LIST_HPP
#define FORWARD_LIST_HPP

#include "bits/stdc++.h"

namespace GP {

    template <class T, class Allocator = std::allocator<T>>
    class forward_list {
      public:
        typedef T value_type;
        typedef Allocator allocator_type;

        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef typename std::allocator_traits<allocator_type>::pointer pointer;
        typedef typename std::allocator_traits<allocator_type>::const_pointer const_pointer;
        typedef typename std::allocator_traits<allocator_type>::size_type size_type;
        typedef typename std::allocator_traits<allocator_type>::difference_type difference_type;

        typedef T* iterator;
        typedef const T* const_iterator;

        forward_list() noexcept(std::is_nothrow_default_constructible<allocator_type>::value);
        explicit forward_list(const allocator_type& a);
        explicit forward_list(size_type n);
        explicit forward_list(size_type n, const allocator_type& a);  // C++14
        forward_list(size_type n, const value_type& v);
        forward_list(size_type n, const value_type& v, const allocator_type& a);
        template <class InputIterator>
        forward_list(InputIterator first, InputIterator last);
        template <class InputIterator>
        forward_list(InputIterator first, InputIterator last, const allocator_type& a);
        forward_list(const forward_list& x);
        forward_list(const forward_list& x, const allocator_type& a);
        forward_list(forward_list&& x) noexcept(std::is_nothrow_move_constructible<allocator_type>::value);
        forward_list(forward_list&& x, const allocator_type& a);
        forward_list(std::initializer_list<value_type> il);
        forward_list(std::initializer_list<value_type> il, const allocator_type& a);

        ~forward_list();

        forward_list& operator=(const forward_list& x);
        forward_list& operator=(forward_list&& x) noexcept(
            allocator_type::propagate_on_container_move_assignment::value&&
                std::is_nothrow_move_assignable<allocator_type>::value);
        forward_list& operator=(std::initializer_list<value_type> il);

        template <class InputIterator>
        void assign(InputIterator first, InputIterator last);
        void assign(size_type n, const value_type& v);
        void assign(std::initializer_list<value_type> il);

        allocator_type get_allocator() const noexcept;

        iterator begin() noexcept;
        const_iterator begin() const noexcept;
        iterator end() noexcept;
        const_iterator end() const noexcept;

        const_iterator cbegin() const noexcept;
        const_iterator cend() const noexcept;

        iterator before_begin() noexcept;
        const_iterator before_begin() const noexcept;
        const_iterator cbefore_begin() const noexcept;

        bool empty() const noexcept;
        size_type max_size() const noexcept;

        reference front();
        const_reference front() const;

        template <class... Args>
        reference emplace_front(Args&&... args);  // reference in C++17
        void push_front(const value_type& v);
        void push_front(value_type&& v);

        void pop_front();

        template <class... Args>
        iterator emplace_after(const_iterator p, Args&&... args);
        iterator insert_after(const_iterator p, const value_type& v);
        iterator insert_after(const_iterator p, value_type&& v);
        iterator insert_after(const_iterator p, size_type n, const value_type& v);
        template <class InputIterator>
        iterator insert_after(const_iterator p, InputIterator first, InputIterator last);
        iterator insert_after(const_iterator p, std::initializer_list<value_type> il);

        iterator erase_after(const_iterator p);
        iterator erase_after(const_iterator first, const_iterator last);

        void swap(forward_list& x) noexcept(std::allocator_traits<allocator_type>::is_always_equal::value);  // C++17

        void resize(size_type n);
        void resize(size_type n, const value_type& v);
        void clear() noexcept;

        void splice_after(const_iterator p, forward_list& x);
        void splice_after(const_iterator p, forward_list&& x);
        void splice_after(const_iterator p, forward_list& x, const_iterator i);
        void splice_after(const_iterator p, forward_list&& x, const_iterator i);
        void splice_after(const_iterator p, forward_list& x, const_iterator first, const_iterator last);
        void splice_after(const_iterator p, forward_list&& x, const_iterator first, const_iterator last);
        void remove(const value_type& v);
        template <class Predicate>
        void remove_if(Predicate pred);
        void unique();
        template <class BinaryPredicate>
        void unique(BinaryPredicate binary_pred);
        void merge(forward_list& x);
        void merge(forward_list&& x);
        template <class Compare>
        void merge(forward_list& x, Compare comp);
        template <class Compare>
        void merge(forward_list&& x, Compare comp);
        void sort();
        template <class Compare>
        void sort(Compare comp);
        void reverse() noexcept;
    };

    template <class InputIterator,
              class Allocator = std::allocator<typename std::iterator_traits<InputIterator>::value_type>>
    forward_list(InputIterator, InputIterator, Allocator = Allocator())
        ->forward_list<typename std::iterator_traits<InputIterator>::value_type, Allocator>;  // C++17

    template <class T, class Allocator>
    bool operator==(const forward_list<T, Allocator>& x, const forward_list<T, Allocator>& y);

    template <class T, class Allocator>
    bool operator<(const forward_list<T, Allocator>& x, const forward_list<T, Allocator>& y);

    template <class T, class Allocator>
    bool operator!=(const forward_list<T, Allocator>& x, const forward_list<T, Allocator>& y);

    template <class T, class Allocator>
    bool operator>(const forward_list<T, Allocator>& x, const forward_list<T, Allocator>& y);

    template <class T, class Allocator>
    bool operator>=(const forward_list<T, Allocator>& x, const forward_list<T, Allocator>& y);

    template <class T, class Allocator>
    bool operator<=(const forward_list<T, Allocator>& x, const forward_list<T, Allocator>& y);

    template <class T, class Allocator>
    void swap(forward_list<T, Allocator>& x, forward_list<T, Allocator>& y) noexcept(noexcept(x.swap(y)));

    template <class T, class Allocator, class U>
    void erase(forward_list<T, Allocator>& c, const U& value);  // C++20
    template <class T, class Allocator, class Predicate>
    void erase_if(forward_list<T, Allocator>& c, Predicate pred);  // C++20

}  // namespace GP

#endif  // FORWARD_LIST_HPP
