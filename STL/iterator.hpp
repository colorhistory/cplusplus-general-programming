#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "bits/stdc++.h"

namespace GP {

    template <class Iterator>
    struct iterator_traits {
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
        typedef typename Iterator::iterator_category iterator_category;
    };

    template <class T>
    struct iterator_traits<T*> {
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
    struct iterator {
        typedef T value_type;
        typedef Distance difference_type;
        typedef Pointer pointer;
        typedef Reference reference;
        typedef Category iterator_category;
    };

    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

    // 27.4.3, iterator operations
    // extension: second argument not conforming to C++03
    template <class InputIterator>  // constexpr in C++17
    constexpr void advance(InputIterator& i, typename iterator_traits<InputIterator>::difference_type n);

    template <class InputIterator>  // constexpr in C++17
    constexpr typename iterator_traits<InputIterator>::difference_type distance(InputIterator first,
                                                                                InputIterator last);

    template <class InputIterator>  // constexpr in C++17
    constexpr InputIterator next(InputIterator x, typename iterator_traits<InputIterator>::difference_type n = 1);

    template <class BidirectionalIterator>  // constexpr in C++17
    constexpr BidirectionalIterator prev(BidirectionalIterator x,
                                         typename iterator_traits<BidirectionalIterator>::difference_type n = 1);

    template <class Iterator>
    class reverse_iterator
        : public iterator<typename iterator_traits<Iterator>::iterator_category,
                          typename iterator_traits<Iterator>::value_type,
                          typename iterator_traits<Iterator>::difference_type,
                          typename iterator_traits<Iterator>::pointer, typename iterator_traits<Iterator>::reference> {
      protected:
        Iterator current;

      public:
        typedef Iterator iterator_type;
        typedef typename iterator_traits<Iterator>::difference_type difference_type;
        typedef typename iterator_traits<Iterator>::reference reference;
        typedef typename iterator_traits<Iterator>::pointer pointer;

        constexpr reverse_iterator();
        constexpr explicit reverse_iterator(Iterator x);
        template <class U>
        constexpr reverse_iterator(const reverse_iterator<U>& u);
        template <class U>
        constexpr reverse_iterator& operator=(const reverse_iterator<U>& u);
        constexpr Iterator base() const;
        constexpr reference operator*() const;
        constexpr pointer operator->() const;
        constexpr reverse_iterator& operator++();
        constexpr reverse_iterator operator++(int);
        constexpr reverse_iterator& operator--();
        constexpr reverse_iterator operator--(int);
        constexpr reverse_iterator operator+(difference_type n) const;
        constexpr reverse_iterator& operator+=(difference_type n);
        constexpr reverse_iterator operator-(difference_type n) const;
        constexpr reverse_iterator& operator-=(difference_type n);
        constexpr reference operator[](difference_type n) const;
    };

    template <class Iterator1, class Iterator2>
    constexpr bool  // constexpr in C++17
    operator==(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y);

    template <class Iterator1, class Iterator2>
    constexpr bool  // constexpr in C++17
    operator<(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y);

    template <class Iterator1, class Iterator2>
    constexpr bool  // constexpr in C++17
    operator!=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y);

    template <class Iterator1, class Iterator2>
    constexpr bool  // constexpr in C++17
    operator>(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y);

    template <class Iterator1, class Iterator2>
    constexpr bool  // constexpr in C++17
    operator>=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y);

    template <class Iterator1, class Iterator2>
    constexpr bool  // constexpr in C++17
    operator<=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y);

    template <class Iterator1, class Iterator2>
    constexpr auto operator-(const reverse_iterator<Iterator1>& __x, const reverse_iterator<Iterator2>& __y)
        -> decltype(__y.base() - __x.base());  // constexpr in C++17

    template <class Iterator>
    constexpr reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
                                                   const reverse_iterator<Iterator>& x);  // constexpr in C++17

    template <class Iterator>
    constexpr reverse_iterator<Iterator> make_reverse_iterator(Iterator i);  // C++14, constexpr in C++17

    template <class Container>
    class back_insert_iterator {
      protected:
        Container* container;

      public:
        typedef Container container_type;
        typedef void value_type;
        typedef void difference_type;
        typedef void reference;
        typedef void pointer;

        explicit back_insert_iterator(Container& x);
        back_insert_iterator& operator=(const typename Container::value_type& value);
        back_insert_iterator& operator*();
        back_insert_iterator& operator++();
        back_insert_iterator operator++(int);
    };

    template <class Container>
    back_insert_iterator<Container> back_inserter(Container& x);

    template <class Container>
    class front_insert_iterator {
      protected:
        Container* container;

      public:
        typedef Container container_type;
        typedef void value_type;
        typedef void difference_type;
        typedef void reference;
        typedef void pointer;

        explicit front_insert_iterator(Container& x);
        front_insert_iterator& operator=(const typename Container::value_type& value);
        front_insert_iterator& operator*();
        front_insert_iterator& operator++();
        front_insert_iterator operator++(int);
    };

    template <class Container>
    front_insert_iterator<Container> front_inserter(Container& x);

    template <class Container>
    class insert_iterator {
      protected:
        Container* container;
        typename Container::iterator iter;

      public:
        typedef Container container_type;
        typedef void value_type;
        typedef void difference_type;
        typedef void reference;
        typedef void pointer;

        insert_iterator(Container& x, typename Container::iterator i);
        insert_iterator& operator=(const typename Container::value_type& value);
        insert_iterator& operator*();
        insert_iterator& operator++();
        insert_iterator& operator++(int);
    };

    template <class Container, class Iterator>
    insert_iterator<Container> inserter(Container& x, Iterator i);

    template <class Iterator>
    class move_iterator {
      public:
        typedef Iterator iterator_type;
        typedef typename iterator_traits<Iterator>::difference_type difference_type;
        typedef Iterator pointer;
        typedef typename iterator_traits<Iterator>::value_type value_type;
        typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
        typedef value_type&& reference;

        constexpr move_iterator();  // all the constexprs are in C++17
        constexpr explicit move_iterator(Iterator i);
        template <class U>
        constexpr move_iterator(const move_iterator<U>& u);
        template <class U>
        constexpr move_iterator& operator=(const move_iterator<U>& u);
        constexpr iterator_type base() const;
        constexpr reference operator*() const;
        constexpr pointer operator->() const;
        constexpr move_iterator& operator++();
        constexpr move_iterator operator++(int);
        constexpr move_iterator& operator--();
        constexpr move_iterator operator--(int);
        constexpr move_iterator operator+(difference_type n) const;
        constexpr move_iterator& operator+=(difference_type n);
        constexpr move_iterator operator-(difference_type n) const;
        constexpr move_iterator& operator-=(difference_type n);
        constexpr unspecified operator[](difference_type n) const;

      private:
        Iterator current;  // exposition only
    };

    template <class Iterator1, class Iterator2>
    constexpr bool  // constexpr in C++17
    operator==(const move_iterator<Iterator1>& x, const move_iterator<Iterator2>& y);

    template <class Iterator1, class Iterator2>
    constexpr bool  // constexpr in C++17
    operator!=(const move_iterator<Iterator1>& x, const move_iterator<Iterator2>& y);

    template <class Iterator1, class Iterator2>
    constexpr bool  // constexpr in C++17
    operator<(const move_iterator<Iterator1>& x, const move_iterator<Iterator2>& y);

    template <class Iterator1, class Iterator2>
    constexpr bool  // constexpr in C++17
    operator<=(const move_iterator<Iterator1>& x, const move_iterator<Iterator2>& y);

    template <class Iterator1, class Iterator2>
    constexpr bool  // constexpr in C++17
    operator>(const move_iterator<Iterator1>& x, const move_iterator<Iterator2>& y);

    template <class Iterator1, class Iterator2>
    constexpr bool  // constexpr in C++17
    operator>=(const move_iterator<Iterator1>& x, const move_iterator<Iterator2>& y);

    template <class Iterator1, class Iterator2>
    constexpr auto  // constexpr in C++17
    operator-(const move_iterator<Iterator1>& x, const move_iterator<Iterator2>& y) -> decltype(x.base() - y.base());

    template <class Iterator>
    constexpr move_iterator<Iterator> operator+(  // constexpr in C++17
        typename move_iterator<Iterator>::difference_type n, const move_iterator<Iterator>& x);

    template <class Iterator>  // constexpr in C++17
    constexpr move_iterator<Iterator> make_move_iterator(const Iterator& i);

    template <class T, class charT = char, class traits = std::char_traits<charT>, class Distance = ptrdiff_t>
    class istream_iterator : public iterator<input_iterator_tag, T, Distance, const T*, const T&> {
      public:
        typedef charT char_type;
        typedef traits traits_type;
        typedef std::basic_istream<charT, traits> istream_type;

        constexpr istream_iterator();
        istream_iterator(istream_type& s);
        istream_iterator(const istream_iterator& x);
        ~istream_iterator();

        const T& operator*() const;
        const T* operator->() const;
        istream_iterator& operator++();
        istream_iterator operator++(int);
    };

    template <class T, class charT, class traits, class Distance>
    bool operator==(const istream_iterator<T, charT, traits, Distance>& x,
                    const istream_iterator<T, charT, traits, Distance>& y);
    template <class T, class charT, class traits, class Distance>
    bool operator!=(const istream_iterator<T, charT, traits, Distance>& x,
                    const istream_iterator<T, charT, traits, Distance>& y);

    template <class T, class charT = char, class traits = std::char_traits<charT> >
    class ostream_iterator : public iterator<output_iterator_tag, void, void, void, void> {
      public:
        typedef charT char_type;
        typedef traits traits_type;
        typedef std::basic_ostream<charT, traits> ostream_type;

        ostream_iterator(ostream_type& s);
        ostream_iterator(ostream_type& s, const charT* delimiter);
        ostream_iterator(const ostream_iterator& x);
        ~ostream_iterator();
        ostream_iterator& operator=(const T& value);

        ostream_iterator& operator*();
        ostream_iterator& operator++();
        ostream_iterator& operator++(int);
    };

    template <class charT, class traits = std::char_traits<charT> >
    class istreambuf_iterator
        : public iterator<input_iterator_tag, charT, typename traits::off_type, unspecified, charT> {
      public:
        typedef charT char_type;
        typedef traits traits_type;
        typedef typename traits::int_type int_type;
        typedef std::basic_streambuf<charT, traits> streambuf_type;
        typedef std::basic_istream<charT, traits> istream_type;

        istreambuf_iterator() noexcept;
        istreambuf_iterator(istream_type& s) noexcept;
        istreambuf_iterator(streambuf_type* s) noexcept;
        istreambuf_iterator(a - private - type) noexcept;

        charT operator*() const;
        pointer operator->() const;
        istreambuf_iterator& operator++();
        a - private - type operator++(int);

        bool equal(const istreambuf_iterator& b) const;
    };

    template <class charT, class traits>
    bool operator==(const istreambuf_iterator<charT, traits>& a, const istreambuf_iterator<charT, traits>& b);
    template <class charT, class traits>
    bool operator!=(const istreambuf_iterator<charT, traits>& a, const istreambuf_iterator<charT, traits>& b);

    template <class charT, class traits = std::char_traits<charT> >
    class ostreambuf_iterator : public iterator<output_iterator_tag, void, void, void, void> {
      public:
        typedef charT char_type;
        typedef traits traits_type;
        typedef std::basic_streambuf<charT, traits> streambuf_type;
        typedef std::basic_ostream<charT, traits> ostream_type;

        ostreambuf_iterator(ostream_type& s) noexcept;
        ostreambuf_iterator(streambuf_type* s) noexcept;
        ostreambuf_iterator& operator=(charT c);
        ostreambuf_iterator& operator*();
        ostreambuf_iterator& operator++();
        ostreambuf_iterator& operator++(int);
        bool failed() const noexcept;
    };

    template <class C>
    constexpr auto begin(C& c) -> decltype(c.begin());
    template <class C>
    constexpr auto begin(const C& c) -> decltype(c.begin());
    template <class C>
    constexpr auto end(C& c) -> decltype(c.end());
    template <class C>
    constexpr auto end(const C& c) -> decltype(c.end());
    template <class T, size_t N>
    constexpr T* begin(T (&array)[N]);
    template <class T, size_t N>
    constexpr T* end(T (&array)[N]);

    template <class C>
    auto constexpr cbegin(const C& c) -> decltype(std::begin(c));  // C++14
    template <class C>
    auto constexpr cend(const C& c) -> decltype(std::end(c));  // C++14
    template <class C>
    auto constexpr rbegin(C& c) -> decltype(c.rbegin());  // C++14
    template <class C>
    auto constexpr rbegin(const C& c) -> decltype(c.rbegin());  // C++14
    template <class C>
    auto constexpr rend(C& c) -> decltype(c.rend());  // C++14
    template <class C>
    constexpr auto rend(const C& c) -> decltype(c.rend());  // C++14
    template <class E>
    reverse_iterator<const E*> constexpr rbegin(std::initializer_list<E> il);  // C++14
    template <class E>
    reverse_iterator<const E*> constexpr rend(std::initializer_list<E> il);  // C++14
    template <class T, size_t N>
    reverse_iterator<T*> constexpr rbegin(T (&array)[N]);  // C++14
    template <class T, size_t N>
    reverse_iterator<T*> constexpr rend(T (&array)[N]);  // C++14
    template <class C>
    constexpr auto crbegin(const C& c) -> decltype(std::rbegin(c));  // C++14
    template <class C>
    constexpr auto crend(const C& c) -> decltype(std::rend(c));  // C++14

    // 24.8, container access:
    template <class C>
    constexpr auto size(const C& c) -> decltype(c.size());  // C++17
    template <class T, size_t N>
    constexpr size_t size(const T (&array)[N]) noexcept;  // C++17
    template <class C>
    constexpr auto empty(const C& c) -> decltype(c.empty());  // C++17
    template <class T, size_t N>
    constexpr bool empty(const T (&array)[N]) noexcept;  // C++17
    template <class E>
    constexpr bool empty(std::initializer_list<E> il) noexcept;  // C++17
    template <class C>
    constexpr auto data(C& c) -> decltype(c.data());  // C++17
    template <class C>
    constexpr auto data(const C& c) -> decltype(c.data());  // C++17
    template <class T, size_t N>
    constexpr T* data(T (&array)[N]) noexcept;  // C++17
    template <class E>
    constexpr const E* data(std::initializer_list<E> il) noexcept;  // C++17

}  // namespace GP

#endif  // ITERATOR_HPP
