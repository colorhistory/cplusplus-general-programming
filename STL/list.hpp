#ifndef LIST_HPP
#define LIST_HPP

#include "bits/stdc++.h"

namespace GP {

    template <class T, class Alloc = std::allocator<T>>
    class list {
      public:
        // types:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef std::size_t size_type;
        typedef std::size_t difference_type;
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

        list() noexcept(std::is_nothrow_default_constructible<allocator_type>::value);
        explicit list(const allocator_type& a);
        explicit list(size_type n);
        explicit list(size_type n, const allocator_type& a);  // C++14
        list(size_type n, const value_type& value);
        list(size_type n, const value_type& value, const allocator_type& a);
        template <class Iter>
        list(Iter first, Iter last);
        template <class Iter>
        list(Iter first, Iter last, const allocator_type& a);
        list(const list& x);
        list(const list&, const allocator_type& a);
        list(list&& x) noexcept(std::is_nothrow_move_constructible<allocator_type>::value);
        list(list&&, const allocator_type& a);
        list(std::initializer_list<value_type>);
        list(std::initializer_list<value_type>, const allocator_type& a);

        ~list();

        list& operator=(const list& x);
        list& operator=(list&& x) noexcept(allocator_type::propagate_on_container_move_assignment::value&&
                                               std::is_nothrow_move_assignable<allocator_type>::value);
        list& operator=(std::initializer_list<value_type>);
        template <class Iter>
        void assign(Iter first, Iter last);
        void assign(size_type n, const value_type& t);
        void assign(std::initializer_list<value_type>);

        allocator_type get_allocator() const noexcept;

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

        reference front();
        const_reference front() const;
        reference back();
        const_reference back() const;

        bool empty() const noexcept;
        size_type size() const noexcept;
        size_type max_size() const noexcept;

        template <class... Args>
        reference emplace_front(Args&&... args);  // reference in C++17
        void pop_front();
        template <class... Args>
        reference emplace_back(Args&&... args);  // reference in C++17
        void pop_back();
        void push_front(const value_type& x);
        void push_front(value_type&& x);
        void push_back(const value_type& x);
        void push_back(value_type&& x);
        template <class... Args>
        iterator emplace(const_iterator position, Args&&... args);
        iterator insert(const_iterator position, const value_type& x);
        iterator insert(const_iterator position, value_type&& x);
        iterator insert(const_iterator position, size_type n, const value_type& x);
        template <class Iter>
        iterator insert(const_iterator position, Iter first, Iter last);
        iterator insert(const_iterator position, std::initializer_list<value_type> il);

        iterator erase(const_iterator position);
        iterator erase(const_iterator position, const_iterator last);

        void resize(size_type sz);
        void resize(size_type sz, const value_type& c);

        void swap(list&) noexcept(std::allocator_traits<allocator_type>::is_always_equal::value);  // C++17
        void clear() noexcept;

        void splice(const_iterator position, list& x);
        void splice(const_iterator position, list&& x);
        void splice(const_iterator position, list& x, const_iterator i);
        void splice(const_iterator position, list&& x, const_iterator i);
        void splice(const_iterator position, list& x, const_iterator first, const_iterator last);
        void splice(const_iterator position, list&& x, const_iterator first, const_iterator last);

        void remove(const value_type& value);
        template <class Pred>
        void remove_if(Pred pred);
        void unique();
        template <class BinaryPredicate>
        void unique(BinaryPredicate binary_pred);
        void merge(list& x);
        void merge(list&& x);
        template <class Compare>
        void merge(list& x, Compare comp);
        template <class Compare>
        void merge(list&& x, Compare comp);
        void sort();
        template <class Compare>
        void sort(Compare comp);
        void reverse() noexcept;
    };

    template <class InputIterator,
              class Allocator = std::allocator<typename std::iterator_traits<InputIterator>::value_type>>
    list(InputIterator, InputIterator, Allocator = Allocator())
        ->list<typename std::iterator_traits<InputIterator>::value_type, Allocator>;  // C++17

    template <class T, class Alloc>
    bool operator==(const list<T, Alloc>& x, const list<T, Alloc>& y);
    template <class T, class Alloc>
    bool operator<(const list<T, Alloc>& x, const list<T, Alloc>& y);
    template <class T, class Alloc>
    bool operator!=(const list<T, Alloc>& x, const list<T, Alloc>& y);
    template <class T, class Alloc>
    bool operator>(const list<T, Alloc>& x, const list<T, Alloc>& y);
    template <class T, class Alloc>
    bool operator>=(const list<T, Alloc>& x, const list<T, Alloc>& y);
    template <class T, class Alloc>
    bool operator<=(const list<T, Alloc>& x, const list<T, Alloc>& y);

    template <class T, class Alloc>
    void swap(list<T, Alloc>& x, list<T, Alloc>& y) noexcept(noexcept(x.swap(y)));

    template <class T, class Allocator, class U>
    void erase(list<T, Allocator>& c, const U& value);  // C++20
    template <class T, class Allocator, class Predicate>
    void erase_if(list<T, Allocator>& c, Predicate pred);  // C++20

}  // namespace GP

#endif  // LIST_HPP
