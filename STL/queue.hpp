#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "bits/stdc++.h"

namespace GP {

    template <class T, class Container = deque<T>>
    class queue {
      public:
        typedef Container container_type;
        typedef typename container_type::value_type value_type;
        typedef typename container_type::reference reference;
        typedef typename container_type::const_reference const_reference;
        typedef typename container_type::size_type size_type;

      protected:
        container_type c;

      public:
        queue() = default;
        ~queue() = default;

        queue(const queue& q) = default;
        queue(queue&& q) = default;

        queue& operator=(const queue& q) = default;
        queue& operator=(queue&& q) = default;

        explicit queue(const container_type& c);
        explicit queue(container_type&& c) template <class Alloc>
        explicit queue(const Alloc& a);
        template <class Alloc>
        queue(const container_type& c, const Alloc& a);
        template <class Alloc>
        queue(container_type&& c, const Alloc& a);
        template <class Alloc>
        queue(const queue& q, const Alloc& a);
        template <class Alloc>
        queue(queue&& q, const Alloc& a);

        bool empty() const;
        size_type size() const;

        reference front();
        const_reference front() const;
        reference back();
        const_reference back() const;

        void push(const value_type& v);
        void push(value_type&& v);
        template <class... Args>
        reference emplace(Args&&... args);  // reference in C++17
        void pop();

        void swap(queue& q) noexcept(is_nothrow_swappable_v<Container>)
    };

    template <class Container>
    queue(Container)->queue<typename Container::value_type, Container>;  // C++17

    template <class Container, class Allocator>
    queue(Container, Allocator)->queue<typename Container::value_type, Container>;  // C++17

    template <class T, class Container>
    bool operator==(const queue<T, Container>& x, const queue<T, Container>& y);

    template <class T, class Container>
    bool operator<(const queue<T, Container>& x, const queue<T, Container>& y);

    template <class T, class Container>
    bool operator!=(const queue<T, Container>& x, const queue<T, Container>& y);

    template <class T, class Container>
    bool operator>(const queue<T, Container>& x, const queue<T, Container>& y);

    template <class T, class Container>
    bool operator>=(const queue<T, Container>& x, const queue<T, Container>& y);

    template <class T, class Container>
    bool operator<=(const queue<T, Container>& x, const queue<T, Container>& y);

    template <class T, class Container>
    void swap(queue<T, Container>& x, queue<T, Container>& y) noexcept(noexcept(x.swap(y)));

    template <class T, class Container = vector<T>, class Compare = less<typename Container::value_type>>
    class priority_queue {
      public:
        typedef Container container_type;
        typedef typename container_type::value_type value_type;
        typedef typename container_type::reference reference;
        typedef typename container_type::const_reference const_reference;
        typedef typename container_type::size_type size_type;

      protected:
        container_type c;
        Compare comp;

      public:
        priority_queue() = default;
        ~priority_queue() = default;

        priority_queue(const priority_queue& q) = default;
        priority_queue(priority_queue&& q) = default;

        priority_queue& operator=(const priority_queue& q) = default;
        priority_queue& operator=(priority_queue&& q) = default;

        explicit priority_queue(const Compare& comp);
        priority_queue(const Compare& comp, const container_type& c);
        explicit priority_queue(const Compare& comp, container_type&& c);
        template <class InputIterator>
        priority_queue(InputIterator first, InputIterator last, const Compare& comp = Compare());
        template <class InputIterator>
        priority_queue(InputIterator first, InputIterator last, const Compare& comp, const container_type& c);
        template <class InputIterator>
        priority_queue(InputIterator first, InputIterator last, const Compare& comp, container_type&& c);
        template <class Alloc>
        explicit priority_queue(const Alloc& a);
        template <class Alloc>
        priority_queue(const Compare& comp, const Alloc& a);
        template <class Alloc>
        priority_queue(const Compare& comp, const container_type& c, const Alloc& a);
        template <class Alloc>
        priority_queue(const Compare& comp, container_type&& c, const Alloc& a);
        template <class Alloc>
        priority_queue(const priority_queue& q, const Alloc& a);
        template <class Alloc>
        priority_queue(priority_queue&& q, const Alloc& a);

        bool empty() const;
        size_type size() const;
        const_reference top() const;

        void push(const value_type& v);
        void push(value_type&& v);
        template <class... Args>
        void emplace(Args&&... args);
        void pop();

        void swap(priority_queue& q) noexcept(is_nothrow_swappable_v<Container>&& is_nothrow_swappable_v<Comp>)
    };

    template <class Compare, class Container>
    priority_queue(Compare, Container)->priority_queue<typename Container::value_type, Container, Compare>;  // C++17

    template <class InputIterator, class Compare = less<typename iterator_traits<InputIterator>::value_type>,
              class Container = vector<typename iterator_traits<InputIterator>::value_type>>
    priority_queue(InputIterator, InputIterator, Compare = Compare(), Container = Container())
        ->priority_queue<typename iterator_traits<InputIterator>::value_type, Container, Compare>;  // C++17

    template <class Compare, class Container, class Allocator>
    priority_queue(Compare, Container, Allocator)
        ->priority_queue<typename Container::value_type, Container, Compare>;  // C++17

    template <class T, class Container, class Compare>
    void swap(priority_queue<T, Container, Compare>& x,
              priority_queue<T, Container, Compare>& y) noexcept(noexcept(x.swap(y)));

}  // namespace GP

#endif  // QUEUE_HPP
