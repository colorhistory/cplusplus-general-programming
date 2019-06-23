#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "bits/stdc++.h"

namespace GP {

    template <class T, class Allocator = std::allocator<T>>
    class deque {
      public:
        // types:
        typedef T value_type;
        typedef Allocator allocator_type;

        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef typename allocator_type::size_type size_type;
        typedef typename allocator_type::difference_type difference_type;

        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

        // construct/copy/destroy:
        deque() noexcept(std::is_nothrow_default_constructible<allocator_type>::value);
        explicit deque(const allocator_type& a);
        explicit deque(size_type n);
        explicit deque(size_type n, const allocator_type& a);  // C++14
        deque(size_type n, const value_type& v);
        deque(size_type n, const value_type& v, const allocator_type& a);
        template <class InputIterator>
        deque(InputIterator f, InputIterator l);
        template <class InputIterator>
        deque(InputIterator f, InputIterator l, const allocator_type& a);
        deque(const deque& c);
        deque(deque&& c) noexcept(std::is_nothrow_move_constructible<allocator_type>::value);
        deque(std::initializer_list<value_type> il, const Allocator& a = allocator_type());
        deque(const deque& c, const allocator_type& a);
        deque(deque&& c, const allocator_type& a);
        ~deque();

        deque& operator=(const deque& c);
        deque& operator=(deque&& c) noexcept(allocator_type::propagate_on_container_move_assignment::value&&
                                                 std::is_nothrow_move_assignable<allocator_type>::value);
        deque& operator=(std::initializer_list<value_type> il);

        template <class InputIterator>
        void assign(InputIterator f, InputIterator l);
        void assign(size_type n, const value_type& v);
        void assign(std::initializer_list<value_type> il);

        allocator_type get_allocator() const noexcept;

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
        size_type size() const noexcept;
        size_type max_size() const noexcept;
        void resize(size_type n);
        void resize(size_type n, const value_type& v);
        void shrink_to_fit();
        bool empty() const noexcept;

        // element access:
        reference operator[](size_type i);
        const_reference operator[](size_type i) const;
        reference at(size_type i);
        const_reference at(size_type i) const;
        reference front();
        const_reference front() const;
        reference back();
        const_reference back() const;

        // modifiers:
        void push_front(const value_type& v);
        void push_front(value_type&& v);
        void push_back(const value_type& v);
        void push_back(value_type&& v);
        template <class... Args>
        reference emplace_front(Args&&... args);  // reference in C++17
        template <class... Args>
        reference emplace_back(Args&&... args);  // reference in C++17
        template <class... Args>
        iterator emplace(const_iterator p, Args&&... args);
        iterator insert(const_iterator p, const value_type& v);
        iterator insert(const_iterator p, value_type&& v);
        iterator insert(const_iterator p, size_type n, const value_type& v);
        template <class InputIterator>
        iterator insert(const_iterator p, InputIterator f, InputIterator l);
        iterator insert(const_iterator p, std::initializer_list<value_type> il);
        void pop_front();
        void pop_back();
        iterator erase(const_iterator p);
        iterator erase(const_iterator f, const_iterator l);
        void swap(deque& c) noexcept(std::allocator_traits<allocator_type>::is_always_equal::value);  // C++17
        void clear() noexcept;
    };

    template <class InputIterator,
              class Allocator = std::allocator<typename std::iterator_traits<InputIterator>::value_type>>
    deque(InputIterator, InputIterator, Allocator = Allocator())
        ->deque<typename std::iterator_traits<InputIterator>::value_type, Allocator>;

    template <class T, class Allocator>
    bool operator==(const deque<T, Allocator>& x, const deque<T, Allocator>& y);
    template <class T, class Allocator>
    bool operator<(const deque<T, Allocator>& x, const deque<T, Allocator>& y);
    template <class T, class Allocator>
    bool operator!=(const deque<T, Allocator>& x, const deque<T, Allocator>& y);
    template <class T, class Allocator>
    bool operator>(const deque<T, Allocator>& x, const deque<T, Allocator>& y);
    template <class T, class Allocator>
    bool operator>=(const deque<T, Allocator>& x, const deque<T, Allocator>& y);
    template <class T, class Allocator>
    bool operator<=(const deque<T, Allocator>& x, const deque<T, Allocator>& y);

    // specialized algorithms:
    template <class T, class Allocator>
    void swap(deque<T, Allocator>& x, deque<T, Allocator>& y) noexcept(noexcept(x.swap(y)));

    template <class T, class Allocator, class U>
    void erase(deque<T, Allocator>& c, const U& value);  // C++20
    template <class T, class Allocator, class Predicate>
    void erase_if(deque<T, Allocator>& c, Predicate pred);  // C++20

}  // namespace GP

#endif  // DEQUE_HPP
