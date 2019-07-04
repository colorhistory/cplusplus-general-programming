﻿#ifndef MAP_HPP
#define MAP_HPP

namespace GP {

    /*

        map synopsis

    namespace std
    {

    template <class Key, class T, class Compare = less<Key>,
              class Allocator = allocator<pair<const Key, T>>>
    class map
    {
    public:
        // types:
        typedef Key                                      key_type;
        typedef T                                        mapped_type;
        typedef pair<const key_type, mapped_type>        value_type;
        typedef Compare                                  key_compare;
        typedef Allocator                                allocator_type;
        typedef typename allocator_type::reference       reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer         pointer;
        typedef typename allocator_type::const_pointer   const_pointer;
        typedef typename allocator_type::size_type       size_type;
        typedef typename allocator_type::difference_type difference_type;

        typedef implementation-defined                   iterator;
        typedef implementation-defined                   const_iterator;
        typedef std::reverse_iterator<iterator>          reverse_iterator;
        typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
        typedef unspecified                              node_type;              // C++17
        typedef INSERT_RETURN_TYPE<iterator, node_type>  insert_return_type;     // C++17

        class value_compare
            : public binary_function<value_type, value_type, bool>
        {
            friend class map;
        protected:
            key_compare comp;

            value_compare(key_compare c);
        public:
            bool operator()(const value_type& x, const value_type& y) const;
        };

        // construct/copy/destroy:
        map()
            noexcept(
                is_nothrow_default_constructible<allocator_type>::value &&
                is_nothrow_default_constructible<key_compare>::value &&
                is_nothrow_copy_constructible<key_compare>::value);
        explicit map(const key_compare& comp);
        map(const key_compare& comp, const allocator_type& a);
        template <class InputIterator>
            map(InputIterator first, InputIterator last,
                const key_compare& comp = key_compare());
        template <class InputIterator>
            map(InputIterator first, InputIterator last,
                const key_compare& comp, const allocator_type& a);
        map(const map& m);
        map(map&& m)
            noexcept(
                is_nothrow_move_constructible<allocator_type>::value &&
                is_nothrow_move_constructible<key_compare>::value);
        explicit map(const allocator_type& a);
        map(const map& m, const allocator_type& a);
        map(map&& m, const allocator_type& a);
        map(initializer_list<value_type> il, const key_compare& comp = key_compare());
        map(initializer_list<value_type> il, const key_compare& comp, const allocator_type& a);
        template <class InputIterator>
            map(InputIterator first, InputIterator last, const allocator_type& a)
                : map(first, last, Compare(), a) {}  // C++14
        map(initializer_list<value_type> il, const allocator_type& a)
            : map(il, Compare(), a) {}  // C++14
       ~map();

        map& operator=(const map& m);
        map& operator=(map&& m)
            noexcept(
                allocator_type::propagate_on_container_move_assignment::value &&
                is_nothrow_move_assignable<allocator_type>::value &&
                is_nothrow_move_assignable<key_compare>::value);
        map& operator=(initializer_list<value_type> il);

        // iterators:
              iterator begin() noexcept;
        const_iterator begin() const noexcept;
              iterator end() noexcept;
        const_iterator end()   const noexcept;

              reverse_iterator rbegin() noexcept;
        const_reverse_iterator rbegin() const noexcept;
              reverse_iterator rend() noexcept;
        const_reverse_iterator rend()   const noexcept;

        const_iterator         cbegin()  const noexcept;
        const_iterator         cend()    const noexcept;
        const_reverse_iterator crbegin() const noexcept;
        const_reverse_iterator crend()   const noexcept;

        // capacity:
        bool      empty()    const noexcept;
        size_type size()     const noexcept;
        size_type max_size() const noexcept;

        // element access:
        mapped_type& operator[](const key_type& k);
        mapped_type& operator[](key_type&& k);

              mapped_type& at(const key_type& k);
        const mapped_type& at(const key_type& k) const;

        // modifiers:
        template <class... Args>
            pair<iterator, bool> emplace(Args&&... args);
        template <class... Args>
            iterator emplace_hint(const_iterator position, Args&&... args);
        pair<iterator, bool> insert(const value_type& v);
        pair<iterator, bool> insert(      value_type&& v);                                // C++17
        template <class P>
            pair<iterator, bool> insert(P&& p);
        iterator insert(const_iterator position, const value_type& v);
        iterator insert(const_iterator position,       value_type&& v);                   // C++17
        template <class P>
            iterator insert(const_iterator position, P&& p);
        template <class InputIterator>
            void insert(InputIterator first, InputIterator last);
        void insert(initializer_list<value_type> il);

        node_type extract(const_iterator position);                                       // C++17
        node_type extract(const key_type& x);                                             // C++17
        insert_return_type insert(node_type&& nh);                                        // C++17
        iterator insert(const_iterator hint, node_type&& nh);                             // C++17

        template <class... Args>
            pair<iterator, bool> try_emplace(const key_type& k, Args&&... args);          // C++17
        template <class... Args>
            pair<iterator, bool> try_emplace(key_type&& k, Args&&... args);               // C++17
        template <class... Args>
            iterator try_emplace(const_iterator hint, const key_type& k, Args&&... args); // C++17
        template <class... Args>
            iterator try_emplace(const_iterator hint, key_type&& k, Args&&... args);      // C++17
        template <class M>
            pair<iterator, bool> insert_or_assign(const key_type& k, M&& obj);            // C++17
        template <class M>
            pair<iterator, bool> insert_or_assign(key_type&& k, M&& obj);                 // C++17
        template <class M>
            iterator insert_or_assign(const_iterator hint, const key_type& k, M&& obj);   // C++17
        template <class M>
            iterator insert_or_assign(const_iterator hint, key_type&& k, M&& obj);        // C++17

        iterator  erase(const_iterator position);
        iterator  erase(iterator position); // C++14
        size_type erase(const key_type& k);
        iterator  erase(const_iterator first, const_iterator last);
        void clear() noexcept;

        template<class C2>
          void merge(map<Key, T, C2, Allocator>& source);         // C++17
        template<class C2>
          void merge(map<Key, T, C2, Allocator>&& source);        // C++17
        template<class C2>
          void merge(multimap<Key, T, C2, Allocator>& source);    // C++17
        template<class C2>
          void merge(multimap<Key, T, C2, Allocator>&& source);   // C++17

        void swap(map& m)
            noexcept(allocator_traits<allocator_type>::is_always_equal::value &&
                is_nothrow_swappable<key_compare>::value); // C++17

        // observers:
        allocator_type get_allocator() const noexcept;
        key_compare    key_comp()      const;
        value_compare  value_comp()    const;

        // map operations:
              iterator find(const key_type& k);
        const_iterator find(const key_type& k) const;
        template<typename K>
            iterator find(const K& x);              // C++14
        template<typename K>
            const_iterator find(const K& x) const;  // C++14
        template<typename K>
          size_type count(const K& x) const;        // C++14

        size_type      count(const key_type& k) const;
              iterator lower_bound(const key_type& k);
        const_iterator lower_bound(const key_type& k) const;
        template<typename K>
            iterator lower_bound(const K& x);              // C++14
        template<typename K>
            const_iterator lower_bound(const K& x) const;  // C++14

              iterator upper_bound(const key_type& k);
        const_iterator upper_bound(const key_type& k) const;
        template<typename K>
            iterator upper_bound(const K& x);              // C++14
        template<typename K>
            const_iterator upper_bound(const K& x) const;  // C++14

        pair<iterator,iterator>             equal_range(const key_type& k);
        pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
        template<typename K>
            pair<iterator,iterator>             equal_range(const K& x);        // C++14
        template<typename K>
            pair<const_iterator,const_iterator> equal_range(const K& x) const;  // C++14
    };

    template <class Key, class T, class Compare, class Allocator>
    bool
    operator==(const map<Key, T, Compare, Allocator>& x,
               const map<Key, T, Compare, Allocator>& y);

    template <class Key, class T, class Compare, class Allocator>
    bool
    operator< (const map<Key, T, Compare, Allocator>& x,
               const map<Key, T, Compare, Allocator>& y);

    template <class Key, class T, class Compare, class Allocator>
    bool
    operator!=(const map<Key, T, Compare, Allocator>& x,
               const map<Key, T, Compare, Allocator>& y);

    template <class Key, class T, class Compare, class Allocator>
    bool
    operator> (const map<Key, T, Compare, Allocator>& x,
               const map<Key, T, Compare, Allocator>& y);

    template <class Key, class T, class Compare, class Allocator>
    bool
    operator>=(const map<Key, T, Compare, Allocator>& x,
               const map<Key, T, Compare, Allocator>& y);

    template <class Key, class T, class Compare, class Allocator>
    bool
    operator<=(const map<Key, T, Compare, Allocator>& x,
               const map<Key, T, Compare, Allocator>& y);

    // specialized algorithms:
    template <class Key, class T, class Compare, class Allocator>
    void
    swap(map<Key, T, Compare, Allocator>& x, map<Key, T, Compare, Allocator>& y)
        noexcept(noexcept(x.swap(y)));

    template <class Key, class T, class Compare, class Allocator, class Predicate>
      void erase_if(map<Key, T, Compare, Allocator>& c, Predicate pred);  // C++20


    template <class Key, class T, class Compare = less<Key>,
              class Allocator = allocator<pair<const Key, T>>>
    class multimap
    {
    public:
        // types:
        typedef Key                                      key_type;
        typedef T                                        mapped_type;
        typedef pair<const key_type,mapped_type>         value_type;
        typedef Compare                                  key_compare;
        typedef Allocator                                allocator_type;
        typedef typename allocator_type::reference       reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::size_type       size_type;
        typedef typename allocator_type::difference_type difference_type;
        typedef typename allocator_type::pointer         pointer;
        typedef typename allocator_type::const_pointer   const_pointer;

        typedef implementation-defined                   iterator;
        typedef implementation-defined                   const_iterator;
        typedef std::reverse_iterator<iterator>          reverse_iterator;
        typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
        typedef unspecified                              node_type;              // C++17

        class value_compare
            : public binary_function<value_type,value_type,bool>
        {
            friend class multimap;
        protected:
            key_compare comp;
            value_compare(key_compare c);
        public:
            bool operator()(const value_type& x, const value_type& y) const;
        };

        // construct/copy/destroy:
        multimap()
            noexcept(
                is_nothrow_default_constructible<allocator_type>::value &&
                is_nothrow_default_constructible<key_compare>::value &&
                is_nothrow_copy_constructible<key_compare>::value);
        explicit multimap(const key_compare& comp);
        multimap(const key_compare& comp, const allocator_type& a);
        template <class InputIterator>
            multimap(InputIterator first, InputIterator last, const key_compare& comp);
        template <class InputIterator>
            multimap(InputIterator first, InputIterator last, const key_compare& comp,
                     const allocator_type& a);
        multimap(const multimap& m);
        multimap(multimap&& m)
            noexcept(
                is_nothrow_move_constructible<allocator_type>::value &&
                is_nothrow_move_constructible<key_compare>::value);
        explicit multimap(const allocator_type& a);
        multimap(const multimap& m, const allocator_type& a);
        multimap(multimap&& m, const allocator_type& a);
        multimap(initializer_list<value_type> il, const key_compare& comp = key_compare());
        multimap(initializer_list<value_type> il, const key_compare& comp,
                 const allocator_type& a);
        template <class InputIterator>
            multimap(InputIterator first, InputIterator last, const allocator_type& a)
                : multimap(first, last, Compare(), a) {} // C++14
        multimap(initializer_list<value_type> il, const allocator_type& a)
            : multimap(il, Compare(), a) {} // C++14
        ~multimap();

        multimap& operator=(const multimap& m);
        multimap& operator=(multimap&& m)
            noexcept(
                allocator_type::propagate_on_container_move_assignment::value &&
                is_nothrow_move_assignable<allocator_type>::value &&
                is_nothrow_move_assignable<key_compare>::value);
        multimap& operator=(initializer_list<value_type> il);

        // iterators:
              iterator begin() noexcept;
        const_iterator begin() const noexcept;
              iterator end() noexcept;
        const_iterator end()   const noexcept;

              reverse_iterator rbegin() noexcept;
        const_reverse_iterator rbegin() const noexcept;
              reverse_iterator rend() noexcept;
        const_reverse_iterator rend()   const noexcept;

        const_iterator         cbegin()  const noexcept;
        const_iterator         cend()    const noexcept;
        const_reverse_iterator crbegin() const noexcept;
        const_reverse_iterator crend()   const noexcept;

        // capacity:
        bool      empty()    const noexcept;
        size_type size()     const noexcept;
        size_type max_size() const noexcept;

        // modifiers:
        template <class... Args>
            iterator emplace(Args&&... args);
        template <class... Args>
            iterator emplace_hint(const_iterator position, Args&&... args);
        iterator insert(const value_type& v);
        iterator insert(      value_type&& v);                                            // C++17
        template <class P>
            iterator insert(P&& p);
        iterator insert(const_iterator position, const value_type& v);
        iterator insert(const_iterator position,       value_type&& v);                   // C++17
        template <class P>
            iterator insert(const_iterator position, P&& p);
        template <class InputIterator>
            void insert(InputIterator first, InputIterator last);
        void insert(initializer_list<value_type> il);

        node_type extract(const_iterator position);                                       // C++17
        node_type extract(const key_type& x);                                             // C++17
        iterator insert(node_type&& nh);                                                  // C++17
        iterator insert(const_iterator hint, node_type&& nh);                             // C++17

        iterator  erase(const_iterator position);
        iterator  erase(iterator position); // C++14
        size_type erase(const key_type& k);
        iterator  erase(const_iterator first, const_iterator last);
        void clear() noexcept;

        template<class C2>
          void merge(multimap<Key, T, C2, Allocator>& source);    // C++17
        template<class C2>
          void merge(multimap<Key, T, C2, Allocator>&& source);   // C++17
        template<class C2>
          void merge(map<Key, T, C2, Allocator>& source);         // C++17
        template<class C2>
          void merge(map<Key, T, C2, Allocator>&& source);        // C++17

        void swap(multimap& m)
            noexcept(allocator_traits<allocator_type>::is_always_equal::value &&
                is_nothrow_swappable<key_compare>::value); // C++17

        // observers:
        allocator_type get_allocator() const noexcept;
        key_compare    key_comp()      const;
        value_compare  value_comp()    const;

        // map operations:
              iterator find(const key_type& k);
        const_iterator find(const key_type& k) const;
        template<typename K>
            iterator find(const K& x);              // C++14
        template<typename K>
            const_iterator find(const K& x) const;  // C++14
        template<typename K>
          size_type count(const K& x) const;        // C++14

        size_type      count(const key_type& k) const;
              iterator lower_bound(const key_type& k);
        const_iterator lower_bound(const key_type& k) const;
        template<typename K>
            iterator lower_bound(const K& x);              // C++14
        template<typename K>
            const_iterator lower_bound(const K& x) const;  // C++14

              iterator upper_bound(const key_type& k);
        const_iterator upper_bound(const key_type& k) const;
        template<typename K>
            iterator upper_bound(const K& x);              // C++14
        template<typename K>
            const_iterator upper_bound(const K& x) const;  // C++14

        pair<iterator,iterator>             equal_range(const key_type& k);
        pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
        template<typename K>
            pair<iterator,iterator>             equal_range(const K& x);        // C++14
        template<typename K>
            pair<const_iterator,const_iterator> equal_range(const K& x) const;  // C++14
    };

    template <class Key, class T, class Compare, class Allocator>
    bool
    operator==(const multimap<Key, T, Compare, Allocator>& x,
               const multimap<Key, T, Compare, Allocator>& y);

    template <class Key, class T, class Compare, class Allocator>
    bool
    operator< (const multimap<Key, T, Compare, Allocator>& x,
               const multimap<Key, T, Compare, Allocator>& y);

    template <class Key, class T, class Compare, class Allocator>
    bool
    operator!=(const multimap<Key, T, Compare, Allocator>& x,
               const multimap<Key, T, Compare, Allocator>& y);

    template <class Key, class T, class Compare, class Allocator>
    bool
    operator> (const multimap<Key, T, Compare, Allocator>& x,
               const multimap<Key, T, Compare, Allocator>& y);

    template <class Key, class T, class Compare, class Allocator>
    bool
    operator>=(const multimap<Key, T, Compare, Allocator>& x,
               const multimap<Key, T, Compare, Allocator>& y);

    template <class Key, class T, class Compare, class Allocator>
    bool
    operator<=(const multimap<Key, T, Compare, Allocator>& x,
               const multimap<Key, T, Compare, Allocator>& y);

    // specialized algorithms:
    template <class Key, class T, class Compare, class Allocator>
    void
    swap(multimap<Key, T, Compare, Allocator>& x,
         multimap<Key, T, Compare, Allocator>& y)
        noexcept(noexcept(x.swap(y)));

    template <class Key, class T, class Compare, class Allocator, class Predicate>
      void erase_if(multimap<Key, T, Compare, Allocator>& c, Predicate pred);  // C++20

    }  // std

    */

#include <__config>
#include <__node_handle>
#include <__tree>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <memory>
#include <type_traits>
#include <utility>
#include <version>

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#    pragma GCC system_header
#endif

    _LIBCPP_BEGIN_NAMESPACE_STD

    template <class _Key, class _CP, class _Compare, bool = is_empty<_Compare>::value && !__libcpp_is_final<_Compare>::value>
    class __map_value_compare : private _Compare {
      public:
        __map_value_compare() _NOEXCEPT_(is_nothrow_default_constructible<_Compare>::value) : _Compare() {
        }

        __map_value_compare(_Compare c) _NOEXCEPT_(is_nothrow_copy_constructible<_Compare>::value) : _Compare(c) {
        }

        const _Compare& key_comp() const _NOEXCEPT {
            return *this;
        }

        bool operator()(const _CP& __x, const _CP& __y) const {
            return static_cast<const _Compare&>(*this)(__x.__get_value().first, __y.__get_value().first);
        }

        bool operator()(const _CP& __x, const _Key& __y) const {
            return static_cast<const _Compare&>(*this)(__x.__get_value().first, __y);
        }

        bool operator()(const _Key& __x, const _CP& __y) const {
            return static_cast<const _Compare&>(*this)(__x, __y.__get_value().first);
        }
        void swap(__map_value_compare& __y) _NOEXCEPT_(__is_nothrow_swappable<_Compare>::value) {
            using _VSTD::swap;
            swap(static_cast<_Compare&>(*this), static_cast<_Compare&>(__y));
        }

#if _LIBCPP_STD_VER > 11
        template <typename _K2>
        typename enable_if<__is_transparent<_Compare, _K2>::value, bool>::type operator()(const _K2& __x, const _CP& __y) const {
            return static_cast<const _Compare&>(*this)(__x, __y.__get_value().first);
        }

        template <typename _K2>
        typename enable_if<__is_transparent<_Compare, _K2>::value, bool>::type operator()(const _CP& __x, const _K2& __y) const {
            return static_cast<const _Compare&>(*this)(__x.__get_value().first, __y);
        }
#endif
    };

    template <class _Key, class _CP, class _Compare>
    class __map_value_compare<_Key, _CP, _Compare, false> {
        _Compare comp;

      public:
        __map_value_compare() _NOEXCEPT_(is_nothrow_default_constructible<_Compare>::value) : comp() {
        }

        __map_value_compare(_Compare c) _NOEXCEPT_(is_nothrow_copy_constructible<_Compare>::value) : comp(c) {
        }

        const _Compare& key_comp() const _NOEXCEPT {
            return comp;
        }

        bool operator()(const _CP& __x, const _CP& __y) const {
            return comp(__x.__get_value().first, __y.__get_value().first);
        }

        bool operator()(const _CP& __x, const _Key& __y) const {
            return comp(__x.__get_value().first, __y);
        }

        bool operator()(const _Key& __x, const _CP& __y) const {
            return comp(__x, __y.__get_value().first);
        }
        void swap(__map_value_compare& __y) _NOEXCEPT_(__is_nothrow_swappable<_Compare>::value) {
            using _VSTD::swap;
            swap(comp, __y.comp);
        }

#if _LIBCPP_STD_VER > 11
        template <typename _K2>
        typename enable_if<__is_transparent<_Compare, _K2>::value, bool>::type operator()(const _K2& __x, const _CP& __y) const {
            return comp(__x, __y.__get_value().first);
        }

        template <typename _K2>
        typename enable_if<__is_transparent<_Compare, _K2>::value, bool>::type operator()(const _CP& __x, const _K2& __y) const {
            return comp(__x.__get_value().first, __y);
        }
#endif
    };

    template <class _Key, class _CP, class _Compare, bool __b>
    inline void swap(__map_value_compare<_Key, _CP, _Compare, __b>& __x, __map_value_compare<_Key, _CP, _Compare, __b>& __y)
        _NOEXCEPT_(_NOEXCEPT_(__x.swap(__y))) {
        __x.swap(__y);
    }

    template <class _Allocator>
    class __map_node_destructor {
        typedef _Allocator allocator_type;
        typedef allocator_traits<allocator_type> __alloc_traits;

      public:
        typedef typename __alloc_traits::pointer pointer;

      private:
        allocator_type& __na_;

        __map_node_destructor& operator=(const __map_node_destructor&);

      public:
        bool __first_constructed;
        bool __second_constructed;

        explicit __map_node_destructor(allocator_type& __na) _NOEXCEPT : __na_(__na), __first_constructed(false), __second_constructed(false) {
        }

#ifndef _LIBCPP_CXX03_LANG

        __map_node_destructor(__tree_node_destructor<allocator_type>&& __x) _NOEXCEPT : __na_(__x.__na_),
                                                                                        __first_constructed(__x.__value_constructed),
                                                                                        __second_constructed(__x.__value_constructed) {
            __x.__value_constructed = false;
        }
#endif  // _LIBCPP_CXX03_LANG

        void operator()(pointer __p) _NOEXCEPT {
            if (__second_constructed)
                __alloc_traits::destroy(__na_, _VSTD::addressof(__p->__value_.__get_value().second));
            if (__first_constructed)
                __alloc_traits::destroy(__na_, _VSTD::addressof(__p->__value_.__get_value().first));
            if (__p)
                __alloc_traits::deallocate(__na_, __p, 1);
        }
    };

    template <class _Key, class _Tp, class _Compare, class _Allocator>
    class map;
    template <class _Key, class _Tp, class _Compare, class _Allocator>
    class multimap;
    template <class _TreeIterator>
    class __map_const_iterator;

#ifndef _LIBCPP_CXX03_LANG

    template <class _Key, class _Tp>
    struct __value_type {
        typedef _Key key_type;
        typedef _Tp mapped_type;
        typedef pair<const key_type, mapped_type> value_type;
        typedef pair<key_type&, mapped_type&> __nc_ref_pair_type;
        typedef pair<key_type&&, mapped_type&&> __nc_rref_pair_type;

      private:
        value_type __cc;

      public:
        value_type& __get_value() {
#    if _LIBCPP_STD_VER > 14
            return *_VSTD::launder(_VSTD::addressof(__cc));
#    else
            return __cc;
#    endif
        }

        const value_type& __get_value() const {
#    if _LIBCPP_STD_VER > 14
            return *_VSTD::launder(_VSTD::addressof(__cc));
#    else
            return __cc;
#    endif
        }

        __nc_ref_pair_type __ref() {
            value_type& __v = __get_value();
            return __nc_ref_pair_type(const_cast<key_type&>(__v.first), __v.second);
        }

        __nc_rref_pair_type __move() {
            value_type& __v = __get_value();
            return __nc_rref_pair_type(_VSTD::move(const_cast<key_type&>(__v.first)), _VSTD::move(__v.second));
        }

        __value_type& operator=(const __value_type& __v) {
            __ref() = __v.__get_value();
            return *this;
        }

        __value_type& operator=(__value_type&& __v) {
            __ref() = __v.__move();
            return *this;
        }

        template <class _ValueTp, class = typename enable_if<__is_same_uncvref<_ValueTp, value_type>::value>::type>
        __value_type& operator=(_ValueTp&& __v) {
            __ref() = _VSTD::forward<_ValueTp>(__v);
            return *this;
        }

      private:
        __value_type() _LIBCPP_EQUAL_DELETE;
        ~__value_type() _LIBCPP_EQUAL_DELETE;
        __value_type(const __value_type& __v) _LIBCPP_EQUAL_DELETE;
        __value_type(__value_type&& __v) _LIBCPP_EQUAL_DELETE;
    };

#else

    template <class _Key, class _Tp>
    struct __value_type {
        typedef _Key key_type;
        typedef _Tp mapped_type;
        typedef pair<const key_type, mapped_type> value_type;

      private:
        value_type __cc;

      public:
        value_type& __get_value() {
            return __cc;
        }

        const value_type& __get_value() const {
            return __cc;
        }

      private:
        __value_type();
        __value_type(__value_type const&);
        __value_type& operator=(__value_type const&);
        ~__value_type();
    };

#endif  // _LIBCPP_CXX03_LANG

    template <class _Tp>
    struct __extract_key_value_types;

    template <class _Key, class _Tp>
    struct __extract_key_value_types<__value_type<_Key, _Tp>> {
        typedef _Key const __key_type;
        typedef _Tp __mapped_type;
    };

    template <class _TreeIterator>
    class __map_iterator {
        typedef typename _TreeIterator::_NodeTypes _NodeTypes;
        typedef typename _TreeIterator::__pointer_traits __pointer_traits;

        _TreeIterator __i_;

      public:
        typedef bidirectional_iterator_tag iterator_category;
        typedef typename _NodeTypes::__map_value_type value_type;
        typedef typename _TreeIterator::difference_type difference_type;
        typedef value_type& reference;
        typedef typename _NodeTypes::__map_value_type_pointer pointer;

        __map_iterator() _NOEXCEPT {
        }

        __map_iterator(_TreeIterator __i) _NOEXCEPT : __i_(__i) {
        }

        reference operator*() const {
            return __i_->__get_value();
        }

        pointer operator->() const {
            return pointer_traits<pointer>::pointer_to(__i_->__get_value());
        }

        __map_iterator& operator++() {
            ++__i_;
            return *this;
        }

        __map_iterator operator++(int) {
            __map_iterator __t(*this);
            ++(*this);
            return __t;
        }

        __map_iterator& operator--() {
            --__i_;
            return *this;
        }

        __map_iterator operator--(int) {
            __map_iterator __t(*this);
            --(*this);
            return __t;
        }

        friend bool operator==(const __map_iterator& __x, const __map_iterator& __y) {
            return __x.__i_ == __y.__i_;
        }
        friend bool operator!=(const __map_iterator& __x, const __map_iterator& __y) {
            return __x.__i_ != __y.__i_;
        }

        template <class, class, class, class>
        friend class map;
        template <class, class, class, class>
        friend class multimap;
        template <class>
        friend class __map_const_iterator;
    };

    template <class _TreeIterator>
    class __map_const_iterator {
        typedef typename _TreeIterator::_NodeTypes _NodeTypes;
        typedef typename _TreeIterator::__pointer_traits __pointer_traits;

        _TreeIterator __i_;

      public:
        typedef bidirectional_iterator_tag iterator_category;
        typedef typename _NodeTypes::__map_value_type value_type;
        typedef typename _TreeIterator::difference_type difference_type;
        typedef const value_type& reference;
        typedef typename _NodeTypes::__const_map_value_type_pointer pointer;

        __map_const_iterator() _NOEXCEPT {
        }

        __map_const_iterator(_TreeIterator __i) _NOEXCEPT : __i_(__i) {
        }

        __map_const_iterator(__map_iterator<typename _TreeIterator::__non_const_iterator> __i) _NOEXCEPT : __i_(__i.__i_) {
        }

        reference operator*() const {
            return __i_->__get_value();
        }

        pointer operator->() const {
            return pointer_traits<pointer>::pointer_to(__i_->__get_value());
        }

        __map_const_iterator& operator++() {
            ++__i_;
            return *this;
        }

        __map_const_iterator operator++(int) {
            __map_const_iterator __t(*this);
            ++(*this);
            return __t;
        }

        __map_const_iterator& operator--() {
            --__i_;
            return *this;
        }

        __map_const_iterator operator--(int) {
            __map_const_iterator __t(*this);
            --(*this);
            return __t;
        }

        friend bool operator==(const __map_const_iterator& __x, const __map_const_iterator& __y) {
            return __x.__i_ == __y.__i_;
        }
        friend bool operator!=(const __map_const_iterator& __x, const __map_const_iterator& __y) {
            return __x.__i_ != __y.__i_;
        }

        template <class, class, class, class>
        friend class map;
        template <class, class, class, class>
        friend class multimap;
        template <class, class, class>
        friend class __tree_const_iterator;
    };

    template <class _Key, class _Tp, class _Compare = less<_Key>, class _Allocator = allocator<pair<const _Key, _Tp>>>
    class map {
      public:
        // types:
        typedef _Key key_type;
        typedef _Tp mapped_type;
        typedef pair<const key_type, mapped_type> value_type;
        typedef _Compare key_compare;
        typedef _Allocator allocator_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;

        static_assert(sizeof(__diagnose_non_const_comparator<_Key, _Compare>()), "");
        static_assert((is_same<typename allocator_type::value_type, value_type>::value), "Allocator::value_type must be same type as value_type");

        class value_compare : public binary_function<value_type, value_type, bool> {
            friend class map;

          protected:
            key_compare comp;

            value_compare(key_compare c) : comp(c) {
            }

          public:
            bool operator()(const value_type& __x, const value_type& __y) const {
                return comp(__x.first, __y.first);
            }
        };

      private:
        typedef _VSTD::__value_type<key_type, mapped_type> __value_type;
        typedef __map_value_compare<key_type, __value_type, key_compare> __vc;
        typedef typename __rebind_alloc_helper<allocator_traits<allocator_type>, __value_type>::type __allocator_type;
        typedef __tree<__value_type, __vc, __allocator_type> __base;
        typedef typename __base::__node_traits __node_traits;
        typedef allocator_traits<allocator_type> __alloc_traits;

        __base __tree_;

      public:
        typedef typename __alloc_traits::pointer pointer;
        typedef typename __alloc_traits::const_pointer const_pointer;
        typedef typename __alloc_traits::size_type size_type;
        typedef typename __alloc_traits::difference_type difference_type;
        typedef __map_iterator<typename __base::iterator> iterator;
        typedef __map_const_iterator<typename __base::const_iterator> const_iterator;
        typedef _VSTD::reverse_iterator<iterator> reverse_iterator;
        typedef _VSTD::reverse_iterator<const_iterator> const_reverse_iterator;

#if _LIBCPP_STD_VER > 14
        typedef __map_node_handle<typename __base::__node, allocator_type> node_type;
        typedef __insert_return_type<iterator, node_type> insert_return_type;
#endif

        template <class _Key2, class _Value2, class _Comp2, class _Alloc2>
        friend class map;
        template <class _Key2, class _Value2, class _Comp2, class _Alloc2>
        friend class multimap;

        map() _NOEXCEPT_(is_nothrow_default_constructible<allocator_type>::value&& is_nothrow_default_constructible<key_compare>::value&&
                             is_nothrow_copy_constructible<key_compare>::value)
            : __tree_(__vc(key_compare())) {
        }

        explicit map(const key_compare& __comp)
            _NOEXCEPT_(is_nothrow_default_constructible<allocator_type>::value&& is_nothrow_copy_constructible<key_compare>::value)
            : __tree_(__vc(__comp)) {
        }

        explicit map(const key_compare& __comp, const allocator_type& __a) : __tree_(__vc(__comp), typename __base::allocator_type(__a)) {
        }

        template <class _InputIterator>
        map(_InputIterator __f, _InputIterator __l, const key_compare& __comp = key_compare()) : __tree_(__vc(__comp)) {
            insert(__f, __l);
        }

        template <class _InputIterator>
        map(_InputIterator __f, _InputIterator __l, const key_compare& __comp, const allocator_type& __a)
            : __tree_(__vc(__comp), typename __base::allocator_type(__a)) {
            insert(__f, __l);
        }

#if _LIBCPP_STD_VER > 11
        template <class _InputIterator>
        map(_InputIterator __f, _InputIterator __l, const allocator_type& __a) : map(__f, __l, key_compare(), __a) {
        }
#endif

        map(const map& __m) : __tree_(__m.__tree_) {
            insert(__m.begin(), __m.end());
        }

        map& operator=(const map& __m) {
#ifndef _LIBCPP_CXX03_LANG
            __tree_ = __m.__tree_;
#else
            if (this != &__m) {
                __tree_.clear();
                __tree_.value_comp() = __m.__tree_.value_comp();
                __tree_.__copy_assign_alloc(__m.__tree_);
                insert(__m.begin(), __m.end());
            }
#endif
            return *this;
        }

#ifndef _LIBCPP_CXX03_LANG

        map(map&& __m) _NOEXCEPT_(is_nothrow_move_constructible<__base>::value) : __tree_(_VSTD::move(__m.__tree_)) {
        }

        map(map&& __m, const allocator_type& __a);

        map& operator=(map&& __m) _NOEXCEPT_(is_nothrow_move_assignable<__base>::value) {
            __tree_ = _VSTD::move(__m.__tree_);
            return *this;
        }

        map(initializer_list<value_type> __il, const key_compare& __comp = key_compare()) : __tree_(__vc(__comp)) {
            insert(__il.begin(), __il.end());
        }

        map(initializer_list<value_type> __il, const key_compare& __comp, const allocator_type& __a)
            : __tree_(__vc(__comp), typename __base::allocator_type(__a)) {
            insert(__il.begin(), __il.end());
        }

#    if _LIBCPP_STD_VER > 11

        map(initializer_list<value_type> __il, const allocator_type& __a) : map(__il, key_compare(), __a) {
        }
#    endif

        map& operator=(initializer_list<value_type> __il) {
            __tree_.__assign_unique(__il.begin(), __il.end());
            return *this;
        }

#endif  // _LIBCPP_CXX03_LANG

        explicit map(const allocator_type& __a) : __tree_(typename __base::allocator_type(__a)) {
        }

        map(const map& __m, const allocator_type& __a) : __tree_(__m.__tree_.value_comp(), typename __base::allocator_type(__a)) {
            insert(__m.begin(), __m.end());
        }

        iterator begin() _NOEXCEPT {
            return __tree_.begin();
        }

        const_iterator begin() const _NOEXCEPT {
            return __tree_.begin();
        }

        iterator end() _NOEXCEPT {
            return __tree_.end();
        }

        const_iterator end() const _NOEXCEPT {
            return __tree_.end();
        }

        reverse_iterator rbegin() _NOEXCEPT {
            return reverse_iterator(end());
        }

        const_reverse_iterator rbegin() const _NOEXCEPT {
            return const_reverse_iterator(end());
        }

        reverse_iterator rend() _NOEXCEPT {
            return reverse_iterator(begin());
        }

        const_reverse_iterator rend() const _NOEXCEPT {
            return const_reverse_iterator(begin());
        }

        const_iterator cbegin() const _NOEXCEPT {
            return begin();
        }

        const_iterator cend() const _NOEXCEPT {
            return end();
        }

        const_reverse_iterator crbegin() const _NOEXCEPT {
            return rbegin();
        }

        const_reverse_iterator crend() const _NOEXCEPT {
            return rend();
        }

        _LIBCPP_NODISCARD_AFTER_CXX17 bool empty() const _NOEXCEPT {
            return __tree_.size() == 0;
        }

        size_type size() const _NOEXCEPT {
            return __tree_.size();
        }

        size_type max_size() const _NOEXCEPT {
            return __tree_.max_size();
        }

        mapped_type& operator[](const key_type& __k);
#ifndef _LIBCPP_CXX03_LANG
        mapped_type& operator[](key_type&& __k);
#endif

        mapped_type& at(const key_type& __k);
        const mapped_type& at(const key_type& __k) const;

        allocator_type get_allocator() const _NOEXCEPT {
            return allocator_type(__tree_.__alloc());
        }

        key_compare key_comp() const {
            return __tree_.value_comp().key_comp();
        }

        value_compare value_comp() const {
            return value_compare(__tree_.value_comp().key_comp());
        }

#ifndef _LIBCPP_CXX03_LANG
        template <class... _Args>
        pair<iterator, bool> emplace(_Args&&... __args) {
            return __tree_.__emplace_unique(_VSTD::forward<_Args>(__args)...);
        }

        template <class... _Args>
        iterator emplace_hint(const_iterator __p, _Args&&... __args) {
            return __tree_.__emplace_hint_unique(__p.__i_, _VSTD::forward<_Args>(__args)...);
        }

        template <class _Pp, class = typename enable_if<is_constructible<value_type, _Pp>::value>::type>
        pair<iterator, bool> insert(_Pp&& __p) {
            return __tree_.__insert_unique(_VSTD::forward<_Pp>(__p));
        }

        template <class _Pp, class = typename enable_if<is_constructible<value_type, _Pp>::value>::type>
        iterator insert(const_iterator __pos, _Pp&& __p) {
            return __tree_.__insert_unique(__pos.__i_, _VSTD::forward<_Pp>(__p));
        }

#endif  // _LIBCPP_CXX03_LANG

        pair<iterator, bool> insert(const value_type& __v) {
            return __tree_.__insert_unique(__v);
        }

        iterator insert(const_iterator __p, const value_type& __v) {
            return __tree_.__insert_unique(__p.__i_, __v);
        }

#ifndef _LIBCPP_CXX03_LANG

        pair<iterator, bool> insert(value_type&& __v) {
            return __tree_.__insert_unique(_VSTD::move(__v));
        }

        iterator insert(const_iterator __p, value_type&& __v) {
            return __tree_.__insert_unique(__p.__i_, _VSTD::move(__v));
        }

        void insert(initializer_list<value_type> __il) {
            insert(__il.begin(), __il.end());
        }
#endif

        template <class _InputIterator>
        void insert(_InputIterator __f, _InputIterator __l) {
            for (const_iterator __e = cend(); __f != __l; ++__f) insert(__e.__i_, *__f);
        }

#if _LIBCPP_STD_VER > 14

        template <class... _Args>
        pair<iterator, bool> try_emplace(const key_type& __k, _Args&&... __args) {
            return __tree_.__emplace_unique_key_args(__k, _VSTD::piecewise_construct, _VSTD::forward_as_tuple(__k),
                                                     _VSTD::forward_as_tuple(_VSTD::forward<_Args>(__args)...));
        }

        template <class... _Args>
        pair<iterator, bool> try_emplace(key_type&& __k, _Args&&... __args) {
            return __tree_.__emplace_unique_key_args(__k, _VSTD::piecewise_construct, _VSTD::forward_as_tuple(_VSTD::move(__k)),
                                                     _VSTD::forward_as_tuple(_VSTD::forward<_Args>(__args)...));
        }

        template <class... _Args>
        iterator try_emplace(const_iterator __h, const key_type& __k, _Args&&... __args) {
            return __tree_.__emplace_hint_unique_key_args(__h.__i_, __k, _VSTD::piecewise_construct, _VSTD::forward_as_tuple(__k),
                                                          _VSTD::forward_as_tuple(_VSTD::forward<_Args>(__args)...));
        }

        template <class... _Args>
        iterator try_emplace(const_iterator __h, key_type&& __k, _Args&&... __args) {
            return __tree_.__emplace_hint_unique_key_args(__h.__i_, __k, _VSTD::piecewise_construct, _VSTD::forward_as_tuple(_VSTD::move(__k)),
                                                          _VSTD::forward_as_tuple(_VSTD::forward<_Args>(__args)...));
        }

        template <class _Vp>
        pair<iterator, bool> insert_or_assign(const key_type& __k, _Vp&& __v) {
            iterator __p = lower_bound(__k);
            if (__p != end() && !key_comp()(__k, __p->first)) {
                __p->second = _VSTD::forward<_Vp>(__v);
                return _VSTD::make_pair(__p, false);
            }
            return _VSTD::make_pair(emplace_hint(__p, __k, _VSTD::forward<_Vp>(__v)), true);
        }

        template <class _Vp>
        pair<iterator, bool> insert_or_assign(key_type&& __k, _Vp&& __v) {
            iterator __p = lower_bound(__k);
            if (__p != end() && !key_comp()(__k, __p->first)) {
                __p->second = _VSTD::forward<_Vp>(__v);
                return _VSTD::make_pair(__p, false);
            }
            return _VSTD::make_pair(emplace_hint(__p, _VSTD::move(__k), _VSTD::forward<_Vp>(__v)), true);
        }

        template <class _Vp>
        iterator insert_or_assign(const_iterator __h, const key_type& __k, _Vp&& __v) {
            iterator __p = lower_bound(__k);
            if (__p != end() && !key_comp()(__k, __p->first)) {
                __p->second = _VSTD::forward<_Vp>(__v);
                return __p;
            }
            return emplace_hint(__h, __k, _VSTD::forward<_Vp>(__v));
        }

        template <class _Vp>
        iterator insert_or_assign(const_iterator __h, key_type&& __k, _Vp&& __v) {
            iterator __p = lower_bound(__k);
            if (__p != end() && !key_comp()(__k, __p->first)) {
                __p->second = _VSTD::forward<_Vp>(__v);
                return __p;
            }
            return emplace_hint(__h, _VSTD::move(__k), _VSTD::forward<_Vp>(__v));
        }

#endif  // _LIBCPP_STD_VER > 14

        iterator erase(const_iterator __p) {
            return __tree_.erase(__p.__i_);
        }

        iterator erase(iterator __p) {
            return __tree_.erase(__p.__i_);
        }

        size_type erase(const key_type& __k) {
            return __tree_.__erase_unique(__k);
        }

        iterator erase(const_iterator __f, const_iterator __l) {
            return __tree_.erase(__f.__i_, __l.__i_);
        }

        void clear() _NOEXCEPT {
            __tree_.clear();
        }

#if _LIBCPP_STD_VER > 14

        insert_return_type insert(node_type&& __nh) {
            _LIBCPP_ASSERT(__nh.empty() || __nh.get_allocator() == get_allocator(), "node_type with incompatible allocator passed to map::insert()");
            return __tree_.template __node_handle_insert_unique<node_type, insert_return_type>(_VSTD::move(__nh));
        }

        iterator insert(const_iterator __hint, node_type&& __nh) {
            _LIBCPP_ASSERT(__nh.empty() || __nh.get_allocator() == get_allocator(), "node_type with incompatible allocator passed to map::insert()");
            return __tree_.template __node_handle_insert_unique<node_type>(__hint.__i_, _VSTD::move(__nh));
        }

        node_type extract(key_type const& __key) {
            return __tree_.template __node_handle_extract<node_type>(__key);
        }

        node_type extract(const_iterator __it) {
            return __tree_.template __node_handle_extract<node_type>(__it.__i_);
        }
        template <class _Compare2>
        void merge(map<key_type, mapped_type, _Compare2, allocator_type>& __source) {
            _LIBCPP_ASSERT(__source.get_allocator() == get_allocator(), "merging container with incompatible allocator");
            __tree_.__node_handle_merge_unique(__source.__tree_);
        }
        template <class _Compare2>
        void merge(map<key_type, mapped_type, _Compare2, allocator_type>&& __source) {
            _LIBCPP_ASSERT(__source.get_allocator() == get_allocator(), "merging container with incompatible allocator");
            __tree_.__node_handle_merge_unique(__source.__tree_);
        }
        template <class _Compare2>
        void merge(multimap<key_type, mapped_type, _Compare2, allocator_type>& __source) {
            _LIBCPP_ASSERT(__source.get_allocator() == get_allocator(), "merging container with incompatible allocator");
            __tree_.__node_handle_merge_unique(__source.__tree_);
        }
        template <class _Compare2>
        void merge(multimap<key_type, mapped_type, _Compare2, allocator_type>&& __source) {
            _LIBCPP_ASSERT(__source.get_allocator() == get_allocator(), "merging container with incompatible allocator");
            __tree_.__node_handle_merge_unique(__source.__tree_);
        }
#endif

        void swap(map& __m) _NOEXCEPT_(__is_nothrow_swappable<__base>::value) {
            __tree_.swap(__m.__tree_);
        }

        iterator find(const key_type& __k) {
            return __tree_.find(__k);
        }

        const_iterator find(const key_type& __k) const {
            return __tree_.find(__k);
        }
#if _LIBCPP_STD_VER > 11
        template <typename _K2>
        typename enable_if<__is_transparent<_Compare, _K2>::value, iterator>::type find(const _K2& __k) {
            return __tree_.find(__k);
        }
        template <typename _K2>
        typename enable_if<__is_transparent<_Compare, _K2>::value, const_iterator>::type find(const _K2& __k) const {
            return __tree_.find(__k);
        }
#endif

        size_type count(const key_type& __k) const {
            return __tree_.__count_unique(__k);
        }
#if _LIBCPP_STD_VER > 11
        template <typename _K2>
        typename enable_if<__is_transparent<_Compare, _K2>::value, size_type>::type count(const _K2& __k) const {
            return __tree_.__count_multi(__k);
        }
#endif

        iterator lower_bound(const key_type& __k) {
            return __tree_.lower_bound(__k);
        }

        const_iterator lower_bound(const key_type& __k) const {
            return __tree_.lower_bound(__k);
        }
#if _LIBCPP_STD_VER > 11
        template <typename _K2>
        typename enable_if<__is_transparent<_Compare, _K2>::value, iterator>::type lower_bound(const _K2& __k) {
            return __tree_.lower_bound(__k);
        }

        template <typename _K2>
        typename enable_if<__is_transparent<_Compare, _K2>::value, const_iterator>::type lower_bound(const _K2& __k) const {
            return __tree_.lower_bound(__k);
        }
#endif

        iterator upper_bound(const key_type& __k) {
            return __tree_.upper_bound(__k);
        }

        const_iterator upper_bound(const key_type& __k) const {
            return __tree_.upper_bound(__k);
        }
#if _LIBCPP_STD_VER > 11
        template <typename _K2>
        typename enable_if<__is_transparent<_Compare, _K2>::value, iterator>::type upper_bound(const _K2& __k) {
            return __tree_.upper_bound(__k);
        }
        template <typename _K2>
        typename enable_if<__is_transparent<_Compare, _K2>::value, const_iterator>::type upper_bound(const _K2& __k) const {
            return __tree_.upper_bound(__k);
        }
#endif

        pair<iterator, iterator> equal_range(const key_type& __k) {
            return __tree_.__equal_range_unique(__k);
        }

        pair<const_iterator, const_iterator> equal_range(const key_type& __k) const {
            return __tree_.__equal_range_unique(__k);
        }
#if _LIBCPP_STD_VER > 11
        template <typename _K2>
        typename enable_if<__is_transparent<_Compare, _K2>::value, pair<iterator, iterator>>::type equal_range(const _K2& __k) {
            return __tree_.__equal_range_multi(__k);
        }
        template <typename _K2>
        typename enable_if<__is_transparent<_Compare, _K2>::value, pair<const_iterator, const_iterator>>::type equal_range(const _K2& __k) const {
            return __tree_.__equal_range_multi(__k);
        }
#endif

      private:
        typedef typename __base::__node __node;
        typedef typename __base::__node_allocator __node_allocator;
        typedef typename __base::__node_pointer __node_pointer;
        typedef typename __base::__node_base_pointer __node_base_pointer;
        typedef typename __base::__parent_pointer __parent_pointer;

        typedef __map_node_destructor<__node_allocator> _Dp;
        typedef unique_ptr<__node, _Dp> __node_holder;

#ifdef _LIBCPP_CXX03_LANG
        __node_holder __construct_node_with_key(const key_type& __k);
#endif
    };

#ifndef _LIBCPP_CXX03_LANG
    template <class _Key, class _Tp, class _Compare, class _Allocator>
    map<_Key, _Tp, _Compare, _Allocator>::map(map&& __m, const allocator_type& __a)
        : __tree_(_VSTD::move(__m.__tree_), typename __base::allocator_type(__a)) {
        if (__a != __m.get_allocator()) {
            const_iterator __e = cend();
            while (!__m.empty()) __tree_.__insert_unique(__e.__i_, __m.__tree_.remove(__m.begin().__i_)->__value_.__move());
        }
    }

    template <class _Key, class _Tp, class _Compare, class _Allocator>
    _Tp& map<_Key, _Tp, _Compare, _Allocator>::operator[](const key_type& __k) {
        return __tree_.__emplace_unique_key_args(__k, _VSTD::piecewise_construct, _VSTD::forward_as_tuple(__k), _VSTD::forward_as_tuple())
            .first->__get_value()
            .second;
    }

    template <class _Key, class _Tp, class _Compare, class _Allocator>
    _Tp& map<_Key, _Tp, _Compare, _Allocator>::operator[](key_type&& __k) {
        return __tree_
            .__emplace_unique_key_args(__k, _VSTD::piecewise_construct, _VSTD::forward_as_tuple(_VSTD::move(__k)), _VSTD::forward_as_tuple())
            .first->__get_value()
            .second;
    }

#else  // _LIBCPP_CXX03_LANG

    template <class _Key, class _Tp, class _Compare, class _Allocator>
    typename map<_Key, _Tp, _Compare, _Allocator>::__node_holder map<_Key, _Tp, _Compare, _Allocator>::__construct_node_with_key(
        const key_type& __k) {
        __node_allocator& __na = __tree_.__node_alloc();
        __node_holder __h(__node_traits::allocate(__na, 1), _Dp(__na));
        __node_traits::construct(__na, _VSTD::addressof(__h->__value_.__get_value().first), __k);
        __h.get_deleter().__first_constructed = true;
        __node_traits::construct(__na, _VSTD::addressof(__h->__value_.__get_value().second));
        __h.get_deleter().__second_constructed = true;
        return _LIBCPP_EXPLICIT_MOVE(__h);  // explicitly moved for C++03
    }

    template <class _Key, class _Tp, class _Compare, class _Allocator>
    _Tp& map<_Key, _Tp, _Compare, _Allocator>::operator[](const key_type& __k) {
        __parent_pointer __parent;
        __node_base_pointer& __child = __tree_.__find_equal(__parent, __k);
        __node_pointer __r = static_cast<__node_pointer>(__child);
        if (__child == nullptr) {
            __node_holder __h = __construct_node_with_key(__k);
            __tree_.__insert_node_at(__parent, __child, static_cast<__node_base_pointer>(__h.get()));
            __r = __h.release();
        }
        return __r->__value_.__get_value().second;
    }

#endif  // _LIBCPP_CXX03_LANG

    template <class _Key, class _Tp, class _Compare, class _Allocator>
    _Tp& map<_Key, _Tp, _Compare, _Allocator>::at(const key_type& __k) {
        __parent_pointer __parent;
        __node_base_pointer& __child = __tree_.__find_equal(__parent, __k);
#ifndef _LIBCPP_NO_EXCEPTIONS
        if (__child == nullptr)
            throw out_of_range("map::at:  key not found");
#endif  // _LIBCPP_NO_EXCEPTIONS
        return static_cast<__node_pointer>(__child)->__value_.__get_value().second;
    }

    template <class _Key, class _Tp, class _Compare, class _Allocator>
    const _Tp& map<_Key, _Tp, _Compare, _Allocator>::at(const key_type& __k) const {
        __parent_pointer __parent;
        __node_base_pointer __child = __tree_.__find_equal(__parent, __k);
#ifndef _LIBCPP_NO_EXCEPTIONS
        if (__child == nullptr)
            throw out_of_range("map::at:  key not found");
#endif  // _LIBCPP_NO_EXCEPTIONS
        return static_cast<__node_pointer>(__child)->__value_.__get_value().second;
    }

    template <class _Key, class _Tp, class _Compare, class _Allocator>
    inline bool operator==(const map<_Key, _Tp, _Compare, _Allocator>& __x, const map<_Key, _Tp, _Compare, _Allocator>& __y) {
        return __x.size() == __y.size() && _VSTD::equal(__x.begin(), __x.end(), __y.begin());
    }

    template <class _Key, class _Tp, class _Compare, class _Allocator>
    inline bool operator<(const map<_Key, _Tp, _Compare, _Allocator>& __x, const map<_Key, _Tp, _Compare, _Allocator>& __y) {
        return _VSTD::lexicographical_compare(__x.begin(), __x.end(), __y.begin(), __y.end());
    }

    template <class _Key, class _Tp, class _Compare, class _Allocator>
    inline bool operator!=(const map<_Key, _Tp, _Compare, _Allocator>& __x, const map<_Key, _Tp, _Compare, _Allocator>& __y) {
        return !(__x == __y);
    }

    template <class _Key, class _Tp, class _Compare, class _Allocator>
    inline bool operator>(const map<_Key, _Tp, _Compare, _Allocator>& __x, const map<_Key, _Tp, _Compare, _Allocator>& __y) {
        return __y < __x;
    }

    template <class _Key, class _Tp, class _Compare, class _Allocator>
    inline bool operator>=(const map<_Key, _Tp, _Compare, _Allocator>& __x, const map<_Key, _Tp, _Compare, _Allocator>& __y) {
        return !(__x < __y);
    }

    template <class _Key, class _Tp, class _Compare, class _Allocator>
    inline bool operator<=(const map<_Key, _Tp, _Compare, _Allocator>& __x, const map<_Key, _Tp, _Compare, _Allocator>& __y) {
        return !(__y < __x);
    }

    template <class _Key, class _Tp, class _Compare, class _Allocator>
    inline void swap(map<_Key, _Tp, _Compare, _Allocator>& __x, map<_Key, _Tp, _Compare, _Allocator>& __y) _NOEXCEPT_(_NOEXCEPT_(__x.swap(__y))) {
        __x.swap(__y);
    }

#if _LIBCPP_STD_VER > 17
    template <class _Key, class _Tp, class _Compare, class _Allocator, class _Predicate>
    inline void erase_if(map<_Key, _Tp, _Compare, _Allocator>& __c, _Predicate __pred) {
        __libcpp_erase_if_container(__c, __pred);
    }
#endif

    template <class _Key, class _Tp, class _Compare = less<_Key>, class _Allocator = allocator<pair<const _Key, _Tp>>>
    class multimap {
      public:
        // types:
        typedef _Key key_type;
        typedef _Tp mapped_type;
        typedef pair<const key_type, mapped_type> value_type;
        typedef _Compare key_compare;
        typedef _Allocator allocator_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;

        static_assert(sizeof(__diagnose_non_const_comparator<_Key, _Compare>()), "");
        static_assert((is_same<typename allocator_type::value_type, value_type>::value), "Allocator::value_type must be same type as value_type");

        class value_compare : public binary_function<value_type, value_type, bool> {
            friend class multimap;

          protected:
            key_compare comp;

            value_compare(key_compare c) : comp(c) {
            }

          public:
            bool operator()(const value_type& __x, const value_type& __y) const {
                return comp(__x.first, __y.first);
            }
        };

      private:
        typedef _VSTD::__value_type<key_type, mapped_type> __value_type;
        typedef __map_value_compare<key_type, __value_type, key_compare> __vc;
        typedef typename __rebind_alloc_helper<allocator_traits<allocator_type>, __value_type>::type __allocator_type;
        typedef __tree<__value_type, __vc, __allocator_type> __base;
        typedef typename __base::__node_traits __node_traits;
        typedef allocator_traits<allocator_type> __alloc_traits;

        __base __tree_;

      public:
        typedef typename __alloc_traits::pointer pointer;
        typedef typename __alloc_traits::const_pointer const_pointer;
        typedef typename __alloc_traits::size_type size_type;
        typedef typename __alloc_traits::difference_type difference_type;
        typedef __map_iterator<typename __base::iterator> iterator;
        typedef __map_const_iterator<typename __base::const_iterator> const_iterator;
        typedef _VSTD::reverse_iterator<iterator> reverse_iterator;
        typedef _VSTD::reverse_iterator<const_iterator> const_reverse_iterator;

#if _LIBCPP_STD_VER > 14
        typedef __map_node_handle<typename __base::__node, allocator_type> node_type;
#endif

        template <class _Key2, class _Value2, class _Comp2, class _Alloc2>
        friend class map;
        template <class _Key2, class _Value2, class _Comp2, class _Alloc2>
        friend class multimap;

        multimap() _NOEXCEPT_(is_nothrow_default_constructible<allocator_type>::value&& is_nothrow_default_constructible<key_compare>::value&&
                                  is_nothrow_copy_constructible<key_compare>::value)
            : __tree_(__vc(key_compare())) {
        }

        explicit multimap(const key_compare& __comp)
            _NOEXCEPT_(is_nothrow_default_constructible<allocator_type>::value&& is_nothrow_copy_constructible<key_compare>::value)
            : __tree_(__vc(__comp)) {
        }

        explicit multimap(const key_compare& __comp, const allocator_type& __a) : __tree_(__vc(__comp), typename __base::allocator_type(__a)) {
        }

        template <class _InputIterator>
        multimap(_InputIterator __f, _InputIterator __l, const key_compare& __comp = key_compare()) : __tree_(__vc(__comp)) {
            insert(__f, __l);
        }

        template <class _InputIterator>
        multimap(_InputIterator __f, _InputIterator __l, const key_compare& __comp, const allocator_type& __a)
            : __tree_(__vc(__comp), typename __base::allocator_type(__a)) {
            insert(__f, __l);
        }

#if _LIBCPP_STD_VER > 11
        template <class _InputIterator>
        multimap(_InputIterator __f, _InputIterator __l, const allocator_type& __a) : multimap(__f, __l, key_compare(), __a) {
        }
#endif

        multimap(const multimap& __m)
            : __tree_(__m.__tree_.value_comp(), __alloc_traits::select_on_container_copy_construction(__m.__tree_.__alloc())) {
            insert(__m.begin(), __m.end());
        }

        multimap& operator=(const multimap& __m) {
#ifndef _LIBCPP_CXX03_LANG
            __tree_ = __m.__tree_;
#else
            if (this != &__m) {
                __tree_.clear();
                __tree_.value_comp() = __m.__tree_.value_comp();
                __tree_.__copy_assign_alloc(__m.__tree_);
                insert(__m.begin(), __m.end());
            }
#endif
            return *this;
        }

#ifndef _LIBCPP_CXX03_LANG

        multimap(multimap&& __m) _NOEXCEPT_(is_nothrow_move_constructible<__base>::value) : __tree_(_VSTD::move(__m.__tree_)) {
        }

        multimap(multimap&& __m, const allocator_type& __a);

        multimap& operator=(multimap&& __m) _NOEXCEPT_(is_nothrow_move_assignable<__base>::value) {
            __tree_ = _VSTD::move(__m.__tree_);
            return *this;
        }

        multimap(initializer_list<value_type> __il, const key_compare& __comp = key_compare()) : __tree_(__vc(__comp)) {
            insert(__il.begin(), __il.end());
        }

        multimap(initializer_list<value_type> __il, const key_compare& __comp, const allocator_type& __a)
            : __tree_(__vc(__comp), typename __base::allocator_type(__a)) {
            insert(__il.begin(), __il.end());
        }

#    if _LIBCPP_STD_VER > 11

        multimap(initializer_list<value_type> __il, const allocator_type& __a) : multimap(__il, key_compare(), __a) {
        }
#    endif

        multimap& operator=(initializer_list<value_type> __il) {
            __tree_.__assign_multi(__il.begin(), __il.end());
            return *this;
        }

#endif  // _LIBCPP_CXX03_LANG

        explicit multimap(const allocator_type& __a) : __tree_(typename __base::allocator_type(__a)) {
        }

        multimap(const multimap& __m, const allocator_type& __a) : __tree_(__m.__tree_.value_comp(), typename __base::allocator_type(__a)) {
            insert(__m.begin(), __m.end());
        }

        iterator begin() _NOEXCEPT {
            return __tree_.begin();
        }

        const_iterator begin() const _NOEXCEPT {
            return __tree_.begin();
        }

        iterator end() _NOEXCEPT {
            return __tree_.end();
        }

        const_iterator end() const _NOEXCEPT {
            return __tree_.end();
        }

        reverse_iterator rbegin() _NOEXCEPT {
            return reverse_iterator(end());
        }

        const_reverse_iterator rbegin() const _NOEXCEPT {
            return const_reverse_iterator(end());
        }

        reverse_iterator rend() _NOEXCEPT {
            return reverse_iterator(begin());
        }

        const_reverse_iterator rend() const _NOEXCEPT {
            return const_reverse_iterator(begin());
        }

        const_iterator cbegin() const _NOEXCEPT {
            return begin();
        }

        const_iterator cend() const _NOEXCEPT {
            return end();
        }

        const_reverse_iterator crbegin() const _NOEXCEPT {
            return rbegin();
        }

        const_reverse_iterator crend() const _NOEXCEPT {
            return rend();
        }

        _LIBCPP_NODISCARD_AFTER_CXX17 bool empty() const _NOEXCEPT {
            return __tree_.size() == 0;
        }

        size_type size() const _NOEXCEPT {
            return __tree_.size();
        }

        size_type max_size() const _NOEXCEPT {
            return __tree_.max_size();
        }

        allocator_type get_allocator() const _NOEXCEPT {
            return allocator_type(__tree_.__alloc());
        }

        key_compare key_comp() const {
            return __tree_.value_comp().key_comp();
        }

        value_compare value_comp() const {
            return value_compare(__tree_.value_comp().key_comp());
        }

#ifndef _LIBCPP_CXX03_LANG

        template <class... _Args>
        iterator emplace(_Args&&... __args) {
            return __tree_.__emplace_multi(_VSTD::forward<_Args>(__args)...);
        }

        template <class... _Args>
        iterator emplace_hint(const_iterator __p, _Args&&... __args) {
            return __tree_.__emplace_hint_multi(__p.__i_, _VSTD::forward<_Args>(__args)...);
        }

        template <class _Pp, class = typename enable_if<is_constructible<value_type, _Pp>::value>::type>
        iterator insert(_Pp&& __p) {
            return __tree_.__insert_multi(_VSTD::forward<_Pp>(__p));
        }

        template <class _Pp, class = typename enable_if<is_constructible<value_type, _Pp>::value>::type>
        iterator insert(const_iterator __pos, _Pp&& __p) {
            return __tree_.__insert_multi(__pos.__i_, _VSTD::forward<_Pp>(__p));
        }

        iterator insert(value_type&& __v) {
            return __tree_.__insert_multi(_VSTD::move(__v));
        }

        iterator insert(const_iterator __p, value_type&& __v) {
            return __tree_.__insert_multi(__p.__i_, _VSTD::move(__v));
        }

        void insert(initializer_list<value_type> __il) {
            insert(__il.begin(), __il.end());
        }

#endif  // _LIBCPP_CXX03_LANG

        iterator insert(const value_type& __v) {
            return __tree_.__insert_multi(__v);
        }

        iterator insert(const_iterator __p, const value_type& __v) {
            return __tree_.__insert_multi(__p.__i_, __v);
        }

        template <class _InputIterator>
        void insert(_InputIterator __f, _InputIterator __l) {
            for (const_iterator __e = cend(); __f != __l; ++__f) __tree_.__insert_multi(__e.__i_, *__f);
        }

        iterator erase(const_iterator __p) {
            return __tree_.erase(__p.__i_);
        }

        iterator erase(iterator __p) {
            return __tree_.erase(__p.__i_);
        }

        size_type erase(const key_type& __k) {
            return __tree_.__erase_multi(__k);
        }

        iterator erase(const_iterator __f, const_iterator __l) {
            return __tree_.erase(__f.__i_, __l.__i_);
        }

#if _LIBCPP_STD_VER > 14

        iterator insert(node_type&& __nh) {
            _LIBCPP_ASSERT(__nh.empty() || __nh.get_allocator() == get_allocator(),
                           "node_type with incompatible allocator passed to multimap::insert()");
            return __tree_.template __node_handle_insert_multi<node_type>(_VSTD::move(__nh));
        }

        iterator insert(const_iterator __hint, node_type&& __nh) {
            _LIBCPP_ASSERT(__nh.empty() || __nh.get_allocator() == get_allocator(),
                           "node_type with incompatible allocator passed to multimap::insert()");
            return __tree_.template __node_handle_insert_multi<node_type>(__hint.__i_, _VSTD::move(__nh));
        }

        node_type extract(key_type const& __key) {
            return __tree_.template __node_handle_extract<node_type>(__key);
        }

        node_type extract(const_iterator __it) {
            return __tree_.template __node_handle_extract<node_type>(__it.__i_);
        }
        template <class _Compare2>
        void merge(multimap<key_type, mapped_type, _Compare2, allocator_type>& __source) {
            _LIBCPP_ASSERT(__source.get_allocator() == get_allocator(), "merging container with incompatible allocator");
            return __tree_.__node_handle_merge_multi(__source.__tree_);
        }
        template <class _Compare2>
        void merge(multimap<key_type, mapped_type, _Compare2, allocator_type>&& __source) {
            _LIBCPP_ASSERT(__source.get_allocator() == get_allocator(), "merging container with incompatible allocator");
            return __tree_.__node_handle_merge_multi(__source.__tree_);
        }
        template <class _Compare2>
        void merge(map<key_type, mapped_type, _Compare2, allocator_type>& __source) {
            _LIBCPP_ASSERT(__source.get_allocator() == get_allocator(), "merging container with incompatible allocator");
            return __tree_.__node_handle_merge_multi(__source.__tree_);
        }
        template <class _Compare2>
        void merge(map<key_type, mapped_type, _Compare2, allocator_type>&& __source) {
            _LIBCPP_ASSERT(__source.get_allocator() == get_allocator(), "merging container with incompatible allocator");
            return __tree_.__node_handle_merge_multi(__source.__tree_);
        }
#endif

        void clear() _NOEXCEPT {
            __tree_.clear();
        }

        void swap(multimap& __m) _NOEXCEPT_(__is_nothrow_swappable<__base>::value) {
            __tree_.swap(__m.__tree_);
        }

        iterator find(const key_type& __k) {
            return __tree_.find(__k);
        }

        const_iterator find(const key_type& __k) const {
            return __tree_.find(__k);
        }
#if _LIBCPP_STD_VER > 11
        template <typename _K2>
        typename enable_if<__is_transparent<_Compare, _K2>::value, iterator>::type find(const _K2& __k) {
            return __tree_.find(__k);
        }
        template <typename _K2>
        typename enable_if<__is_transparent<_Compare, _K2>::value, const_iterator>::type find(const _K2& __k) const {
            return __tree_.find(__k);
        }
#endif

        size_type count(const key_type& __k) const {
            return __tree_.__count_multi(__k);
        }
#if _LIBCPP_STD_VER > 11
        template <typename _K2>
        typename enable_if<__is_transparent<_Compare, _K2>::value, size_type>::type count(const _K2& __k) const {
            return __tree_.__count_multi(__k);
        }
#endif

        iterator lower_bound(const key_type& __k) {
            return __tree_.lower_bound(__k);
        }

        const_iterator lower_bound(const key_type& __k) const {
            return __tree_.lower_bound(__k);
        }
#if _LIBCPP_STD_VER > 11
        template <typename _K2>
        typename enable_if<__is_transparent<_Compare, _K2>::value, iterator>::type lower_bound(const _K2& __k) {
            return __tree_.lower_bound(__k);
        }

        template <typename _K2>
        typename enable_if<__is_transparent<_Compare, _K2>::value, const_iterator>::type lower_bound(const _K2& __k) const {
            return __tree_.lower_bound(__k);
        }
#endif

        iterator upper_bound(const key_type& __k) {
            return __tree_.upper_bound(__k);
        }

        const_iterator upper_bound(const key_type& __k) const {
            return __tree_.upper_bound(__k);
        }
#if _LIBCPP_STD_VER > 11
        template <typename _K2>
        typename enable_if<__is_transparent<_Compare, _K2>::value, iterator>::type upper_bound(const _K2& __k) {
            return __tree_.upper_bound(__k);
        }
        template <typename _K2>
        typename enable_if<__is_transparent<_Compare, _K2>::value, const_iterator>::type upper_bound(const _K2& __k) const {
            return __tree_.upper_bound(__k);
        }
#endif

        pair<iterator, iterator> equal_range(const key_type& __k) {
            return __tree_.__equal_range_multi(__k);
        }

        pair<const_iterator, const_iterator> equal_range(const key_type& __k) const {
            return __tree_.__equal_range_multi(__k);
        }
#if _LIBCPP_STD_VER > 11
        template <typename _K2>
        typename enable_if<__is_transparent<_Compare, _K2>::value, pair<iterator, iterator>>::type equal_range(const _K2& __k) {
            return __tree_.__equal_range_multi(__k);
        }
        template <typename _K2>
        typename enable_if<__is_transparent<_Compare, _K2>::value, pair<const_iterator, const_iterator>>::type equal_range(const _K2& __k) const {
            return __tree_.__equal_range_multi(__k);
        }
#endif

      private:
        typedef typename __base::__node __node;
        typedef typename __base::__node_allocator __node_allocator;
        typedef typename __base::__node_pointer __node_pointer;

        typedef __map_node_destructor<__node_allocator> _Dp;
        typedef unique_ptr<__node, _Dp> __node_holder;
    };

#ifndef _LIBCPP_CXX03_LANG
    template <class _Key, class _Tp, class _Compare, class _Allocator>
    multimap<_Key, _Tp, _Compare, _Allocator>::multimap(multimap&& __m, const allocator_type& __a)
        : __tree_(_VSTD::move(__m.__tree_), typename __base::allocator_type(__a)) {
        if (__a != __m.get_allocator()) {
            const_iterator __e = cend();
            while (!__m.empty()) __tree_.__insert_multi(__e.__i_, _VSTD::move(__m.__tree_.remove(__m.begin().__i_)->__value_.__move()));
        }
    }
#endif

    template <class _Key, class _Tp, class _Compare, class _Allocator>
    inline bool operator==(const multimap<_Key, _Tp, _Compare, _Allocator>& __x, const multimap<_Key, _Tp, _Compare, _Allocator>& __y) {
        return __x.size() == __y.size() && _VSTD::equal(__x.begin(), __x.end(), __y.begin());
    }

    template <class _Key, class _Tp, class _Compare, class _Allocator>
    inline bool operator<(const multimap<_Key, _Tp, _Compare, _Allocator>& __x, const multimap<_Key, _Tp, _Compare, _Allocator>& __y) {
        return _VSTD::lexicographical_compare(__x.begin(), __x.end(), __y.begin(), __y.end());
    }

    template <class _Key, class _Tp, class _Compare, class _Allocator>
    inline bool operator!=(const multimap<_Key, _Tp, _Compare, _Allocator>& __x, const multimap<_Key, _Tp, _Compare, _Allocator>& __y) {
        return !(__x == __y);
    }

    template <class _Key, class _Tp, class _Compare, class _Allocator>
    inline bool operator>(const multimap<_Key, _Tp, _Compare, _Allocator>& __x, const multimap<_Key, _Tp, _Compare, _Allocator>& __y) {
        return __y < __x;
    }

    template <class _Key, class _Tp, class _Compare, class _Allocator>
    inline bool operator>=(const multimap<_Key, _Tp, _Compare, _Allocator>& __x, const multimap<_Key, _Tp, _Compare, _Allocator>& __y) {
        return !(__x < __y);
    }

    template <class _Key, class _Tp, class _Compare, class _Allocator>
    inline bool operator<=(const multimap<_Key, _Tp, _Compare, _Allocator>& __x, const multimap<_Key, _Tp, _Compare, _Allocator>& __y) {
        return !(__y < __x);
    }

    template <class _Key, class _Tp, class _Compare, class _Allocator>
    inline void swap(multimap<_Key, _Tp, _Compare, _Allocator>& __x, multimap<_Key, _Tp, _Compare, _Allocator>& __y)
        _NOEXCEPT_(_NOEXCEPT_(__x.swap(__y))) {
        __x.swap(__y);
    }

#if _LIBCPP_STD_VER > 17
    template <class _Key, class _Tp, class _Compare, class _Allocator, class _Predicate>
    inline void erase_if(multimap<_Key, _Tp, _Compare, _Allocator>& __c, _Predicate __pred) {
        __libcpp_erase_if_container(__c, __pred);
    }
#endif

    _LIBCPP_END_NAMESPACE_STD

}  // namespace GP

#endif  // MAP_HPP
