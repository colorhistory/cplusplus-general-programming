#ifndef REGEX_HPP
#define REGEX_HPP

#include "bits/stdc++.h"

namespace GP {

    namespace regex_constants {

        enum syntax_option_type {
            unspecified = 0,
            icase = unspecified,
            nosubs = unspecified,
            optimize = unspecified,
            collate = unspecified,
            ECMAScript = unspecified,
            basic = unspecified,
            extended = unspecified,
            awk = unspecified,
            grep = unspecified,
            egrep = unspecified
        };

        constexpr syntax_option_type operator~(syntax_option_type f);
        constexpr syntax_option_type operator&(syntax_option_type lhs, syntax_option_type rhs);
        constexpr syntax_option_type operator|(syntax_option_type lhs, syntax_option_type rhs);

        enum match_flag_type {
            match_default = 0,
            match_not_bol = unspecified,
            match_not_eol = unspecified,
            match_not_bow = unspecified,
            match_not_eow = unspecified,
            match_any = unspecified,
            match_not_null = unspecified,
            match_continuous = unspecified,
            match_prev_avail = unspecified,
            format_default = 0,
            format_sed = unspecified,
            format_no_copy = unspecified,
            format_first_only = unspecified
        };

        constexpr match_flag_type operator~(match_flag_type f);
        constexpr match_flag_type operator&(match_flag_type lhs, match_flag_type rhs);
        constexpr match_flag_type operator|(match_flag_type lhs, match_flag_type rhs);

        enum error_type {
            error_collate = unspecified,
            error_ctype = unspecified,
            error_escape = unspecified,
            error_backref = unspecified,
            error_brack = unspecified,
            error_paren = unspecified,
            error_brace = unspecified,
            error_badbrace = unspecified,
            error_range = unspecified,
            error_space = unspecified,
            error_badrepeat = unspecified,
            error_complexity = unspecified,
            error_stack = unspecified
        };

    }  // namespace regex_constants

    class regex_error : public std::runtime_error {
      public:
        explicit regex_error(regex_constants::error_type ecode);
        regex_constants::error_type code() const;
    };

    template <class charT>
    struct regex_traits {
      public:
        typedef charT char_type;
        typedef std::basic_string<char_type> string_type;
        typedef std::locale locale_type;
        typedef bitmask_type char_class_type;

        regex_traits();

        static size_t length(const char_type* p);
        charT translate(charT c) const;
        charT translate_nocase(charT c) const;
        template <class ForwardIterator>
        string_type transform(ForwardIterator first, ForwardIterator last) const;
        template <class ForwardIterator>
        string_type transform_primary(ForwardIterator first, ForwardIterator last) const;
        template <class ForwardIterator>
        string_type lookup_collatename(ForwardIterator first, ForwardIterator last) const;
        template <class ForwardIterator>
        char_class_type lookup_classname(ForwardIterator first, ForwardIterator last, bool icase = false) const;
        bool isctype(charT c, char_class_type f) const;
        int value(charT ch, int radix) const;
        locale_type imbue(locale_type l);
        locale_type getloc() const;
    };

    template <class charT, class traits = regex_traits<charT>>
    class basic_regex {
      public:
        // types:
        typedef charT value_type;
        typedef traits traits_type;
        typedef typename traits::string_type string_type;
        typedef regex_constants::syntax_option_type flag_type;
        typedef typename traits::locale_type locale_type;

        // constants:
        static constexpr regex_constants::syntax_option_type icase = regex_constants::icase;
        static constexpr regex_constants::syntax_option_type nosubs = regex_constants::nosubs;
        static constexpr regex_constants::syntax_option_type optimize = regex_constants::optimize;
        static constexpr regex_constants::syntax_option_type collate = regex_constants::collate;
        static constexpr regex_constants::syntax_option_type ECMAScript = regex_constants::ECMAScript;
        static constexpr regex_constants::syntax_option_type basic = regex_constants::basic;
        static constexpr regex_constants::syntax_option_type extended = regex_constants::extended;
        static constexpr regex_constants::syntax_option_type awk = regex_constants::awk;
        static constexpr regex_constants::syntax_option_type grep = regex_constants::grep;
        static constexpr regex_constants::syntax_option_type egrep = regex_constants::egrep;

        // construct/copy/destroy:
        basic_regex();
        explicit basic_regex(const charT* p, flag_type f = regex_constants::ECMAScript);
        basic_regex(const charT* p, size_t len, flag_type f = regex_constants::ECMAScript);
        basic_regex(const basic_regex&);
        basic_regex(basic_regex&&) noexcept;
        template <class ST, class SA>
        explicit basic_regex(const std::basic_string<charT, ST, SA>& p, flag_type f = regex_constants::ECMAScript);
        template <class ForwardIterator>
        basic_regex(ForwardIterator first, ForwardIterator last, flag_type f = regex_constants::ECMAScript);
        basic_regex(std::initializer_list<charT>, flag_type = regex_constants::ECMAScript);

        ~basic_regex();

        basic_regex& operator=(const basic_regex&);
        basic_regex& operator=(basic_regex&&) noexcept;
        basic_regex& operator=(const charT* ptr);
        basic_regex& operator=(std::initializer_list<charT> il);
        template <class ST, class SA>
        basic_regex& operator=(const std::basic_string<charT, ST, SA>& p);

        // assign:
        basic_regex& assign(const basic_regex& that);
        basic_regex& assign(basic_regex&& that) noexcept;
        basic_regex& assign(const charT* ptr, flag_type f = regex_constants::ECMAScript);
        basic_regex& assign(const charT* p, size_t len, flag_type f);
        template <class string_traits, class A>
        basic_regex& assign(const std::basic_string<charT, string_traits, A>& s,
                            flag_type f = regex_constants::ECMAScript);
        template <class InputIterator>
        basic_regex& assign(InputIterator first, InputIterator last, flag_type f = regex_constants::ECMAScript);
        basic_regex& assign(std::initializer_list<charT>, flag_type = regex_constants::ECMAScript);

        // const operations:
        unsigned mark_count() const;
        flag_type flags() const;

        // locale:
        locale_type imbue(locale_type loc);
        locale_type getloc() const;

        // swap:
        void swap(basic_regex&);
    };

    template <class ForwardIterator>
    basic_regex(ForwardIterator, ForwardIterator,
                regex_constants::syntax_option_type = regex_constants::ECMAScript)
        ->basic_regex<typename std::iterator_traits<ForwardIterator>::value_type>;  // C++17

    typedef basic_regex<char> regex;
    typedef basic_regex<wchar_t> wregex;

    template <class charT, class traits>
    void swap(basic_regex<charT, traits>& e1, basic_regex<charT, traits>& e2);

    template <class BidirectionalIterator>
    class sub_match : public std::pair<BidirectionalIterator, BidirectionalIterator> {
      public:
        typedef typename std::iterator_traits<BidirectionalIterator>::value_type value_type;
        typedef typename std::iterator_traits<BidirectionalIterator>::difference_type difference_type;
        typedef BidirectionalIterator iterator;
        typedef std::basic_string<value_type> string_type;

        bool matched;

        constexpr sub_match();

        difference_type length() const;
        operator string_type() const;
        string_type str() const;

        int compare(const sub_match& s) const;
        int compare(const string_type& s) const;
        int compare(const value_type* s) const;
    };

    typedef sub_match<const char*> csub_match;
    typedef sub_match<const wchar_t*> wcsub_match;
    typedef sub_match<std::string::const_iterator> ssub_match;
    typedef sub_match<std::wstring::const_iterator> wssub_match;

    template <class BiIter>
    bool operator==(const sub_match<BiIter>& lhs, const sub_match<BiIter>& rhs);

    template <class BiIter>
    bool operator!=(const sub_match<BiIter>& lhs, const sub_match<BiIter>& rhs);

    template <class BiIter>
    bool operator<(const sub_match<BiIter>& lhs, const sub_match<BiIter>& rhs);

    template <class BiIter>
    bool operator<=(const sub_match<BiIter>& lhs, const sub_match<BiIter>& rhs);

    template <class BiIter>
    bool operator>=(const sub_match<BiIter>& lhs, const sub_match<BiIter>& rhs);

    template <class BiIter>
    bool operator>(const sub_match<BiIter>& lhs, const sub_match<BiIter>& rhs);

    template <class BiIter, class ST, class SA>
    bool operator==(const std::basic_string<typename std::iterator_traits<BiIter>::value_type, ST, SA>& lhs,
                    const sub_match<BiIter>& rhs);

    template <class BiIter, class ST, class SA>
    bool operator!=(const std::basic_string<typename std::iterator_traits<BiIter>::value_type, ST, SA>& lhs,
                    const sub_match<BiIter>& rhs);

    template <class BiIter, class ST, class SA>
    bool operator<(const std::basic_string<typename std::iterator_traits<BiIter>::value_type, ST, SA>& lhs,
                   const sub_match<BiIter>& rhs);

    template <class BiIter, class ST, class SA>
    bool operator>(const std::basic_string<typename std::iterator_traits<BiIter>::value_type, ST, SA>& lhs,
                   const sub_match<BiIter>& rhs);

    template <class BiIter, class ST, class SA>
    bool operator>=(const std::basic_string<typename std::iterator_traits<BiIter>::value_type, ST, SA>& lhs,
                    const sub_match<BiIter>& rhs);

    template <class BiIter, class ST, class SA>
    bool operator<=(const std::basic_string<typename std::iterator_traits<BiIter>::value_type, ST, SA>& lhs,
                    const sub_match<BiIter>& rhs);

    template <class BiIter, class ST, class SA>
    bool operator==(const sub_match<BiIter>& lhs,
                    const std::basic_string<typename std::iterator_traits<BiIter>::value_type, ST, SA>& rhs);

    template <class BiIter, class ST, class SA>
    bool operator!=(const sub_match<BiIter>& lhs,
                    const std::basic_string<typename std::iterator_traits<BiIter>::value_type, ST, SA>& rhs);

    template <class BiIter, class ST, class SA>
    bool operator<(const sub_match<BiIter>& lhs,
                   const std::basic_string<typename std::iterator_traits<BiIter>::value_type, ST, SA>& rhs);

    template <class BiIter, class ST, class SA>
    bool operator>(const sub_match<BiIter>& lhs,
                   const std::basic_string<typename std::iterator_traits<BiIter>::value_type, ST, SA>& rhs);

    template <class BiIter, class ST, class SA>
    bool operator>=(const sub_match<BiIter>& lhs,
                    const std::basic_string<typename std::iterator_traits<BiIter>::value_type, ST, SA>& rhs);

    template <class BiIter, class ST, class SA>
    bool operator<=(const sub_match<BiIter>& lhs,
                    const std::basic_string<typename std::iterator_traits<BiIter>::value_type, ST, SA>& rhs);

    template <class BiIter>
    bool operator==(typename std::iterator_traits<BiIter>::value_type const* lhs, const sub_match<BiIter>& rhs);

    template <class BiIter>
    bool operator!=(typename std::iterator_traits<BiIter>::value_type const* lhs, const sub_match<BiIter>& rhs);

    template <class BiIter>
    bool operator<(typename std::iterator_traits<BiIter>::value_type const* lhs, const sub_match<BiIter>& rhs);

    template <class BiIter>
    bool operator>(typename std::iterator_traits<BiIter>::value_type const* lhs, const sub_match<BiIter>& rhs);

    template <class BiIter>
    bool operator>=(typename std::iterator_traits<BiIter>::value_type const* lhs, const sub_match<BiIter>& rhs);

    template <class BiIter>
    bool operator<=(typename std::iterator_traits<BiIter>::value_type const* lhs, const sub_match<BiIter>& rhs);

    template <class BiIter>
    bool operator==(const sub_match<BiIter>& lhs, typename std::iterator_traits<BiIter>::value_type const* rhs);

    template <class BiIter>
    bool operator!=(const sub_match<BiIter>& lhs, typename std::iterator_traits<BiIter>::value_type const* rhs);

    template <class BiIter>
    bool operator<(const sub_match<BiIter>& lhs, typename std::iterator_traits<BiIter>::value_type const* rhs);

    template <class BiIter>
    bool operator>(const sub_match<BiIter>& lhs, typename std::iterator_traits<BiIter>::value_type const* rhs);

    template <class BiIter>
    bool operator>=(const sub_match<BiIter>& lhs, typename std::iterator_traits<BiIter>::value_type const* rhs);

    template <class BiIter>
    bool operator<=(const sub_match<BiIter>& lhs, typename std::iterator_traits<BiIter>::value_type const* rhs);

    template <class BiIter>
    bool operator==(typename std::iterator_traits<BiIter>::value_type const& lhs, const sub_match<BiIter>& rhs);

    template <class BiIter>
    bool operator!=(typename std::iterator_traits<BiIter>::value_type const& lhs, const sub_match<BiIter>& rhs);

    template <class BiIter>
    bool operator<(typename std::iterator_traits<BiIter>::value_type const& lhs, const sub_match<BiIter>& rhs);

    template <class BiIter>
    bool operator>(typename std::iterator_traits<BiIter>::value_type const& lhs, const sub_match<BiIter>& rhs);

    template <class BiIter>
    bool operator>=(typename std::iterator_traits<BiIter>::value_type const& lhs, const sub_match<BiIter>& rhs);

    template <class BiIter>
    bool operator<=(typename std::iterator_traits<BiIter>::value_type const& lhs, const sub_match<BiIter>& rhs);

    template <class BiIter>
    bool operator==(const sub_match<BiIter>& lhs, typename std::iterator_traits<BiIter>::value_type const& rhs);

    template <class BiIter>
    bool operator!=(const sub_match<BiIter>& lhs, typename std::iterator_traits<BiIter>::value_type const& rhs);

    template <class BiIter>
    bool operator<(const sub_match<BiIter>& lhs, typename std::iterator_traits<BiIter>::value_type const& rhs);

    template <class BiIter>
    bool operator>(const sub_match<BiIter>& lhs, typename std::iterator_traits<BiIter>::value_type const& rhs);

    template <class BiIter>
    bool operator>=(const sub_match<BiIter>& lhs, typename std::iterator_traits<BiIter>::value_type const& rhs);

    template <class BiIter>
    bool operator<=(const sub_match<BiIter>& lhs, typename std::iterator_traits<BiIter>::value_type const& rhs);

    template <class charT, class ST, class BiIter>
    std::basic_ostream<charT, ST>& operator<<(std::basic_ostream<charT, ST>& os, const sub_match<BiIter>& m);

    template <class BidirectionalIterator, class Allocator = std::allocator<sub_match<BidirectionalIterator>>>
    class match_results {
      public:
        typedef sub_match<BidirectionalIterator> value_type;
        typedef const value_type& const_reference;
        typedef value_type& reference;
        typedef value_type* const_iterator;
        typedef const_iterator iterator;
        typedef typename std::iterator_traits<BidirectionalIterator>::difference_type difference_type;
        typedef typename std::allocator_traits<Allocator>::size_type size_type;
        typedef Allocator allocator_type;
        typedef typename std::iterator_traits<BidirectionalIterator>::value_type char_type;
        typedef std::basic_string<char_type> string_type;

        // construct/copy/destroy:
        explicit match_results(const Allocator& a = Allocator());
        match_results(const match_results& m);
        match_results(match_results&& m) noexcept;
        match_results& operator=(const match_results& m);
        match_results& operator=(match_results&& m);
        ~match_results();

        bool ready() const;

        // size:
        size_type size() const;
        size_type max_size() const;
        bool empty() const;

        // element access:
        difference_type length(size_type sub = 0) const;
        difference_type position(size_type sub = 0) const;
        string_type str(size_type sub = 0) const;
        const_reference operator[](size_type n) const;

        const_reference prefix() const;
        const_reference suffix() const;

        const_iterator begin() const;
        const_iterator end() const;
        const_iterator cbegin() const;
        const_iterator cend() const;

        // format:
        template <class OutputIter>
        OutputIter format(OutputIter out, const char_type* fmt_first, const char_type* fmt_last,
                          regex_constants::match_flag_type flags = regex_constants::format_default) const;
        template <class OutputIter, class ST, class SA>
        OutputIter format(OutputIter out, const std::basic_string<char_type, ST, SA>& fmt,
                          regex_constants::match_flag_type flags = regex_constants::format_default) const;
        template <class ST, class SA>
        std::basic_string<char_type, ST, SA> format(
            const std::basic_string<char_type, ST, SA>& fmt,
            regex_constants::match_flag_type flags = regex_constants::format_default) const;
        string_type format(const char_type* fmt,
                           regex_constants::match_flag_type flags = regex_constants::format_default) const;

        // allocator:
        allocator_type get_allocator() const;

        // swap:
        void swap(match_results& that);
    };

    typedef match_results<const char*> cmatch;
    typedef match_results<const wchar_t*> wcmatch;
    typedef match_results<std::string::const_iterator> smatch;
    typedef match_results<std::wstring::const_iterator> wsmatch;

    template <class BidirectionalIterator, class Allocator>
    bool operator==(const match_results<BidirectionalIterator, Allocator>& m1,
                    const match_results<BidirectionalIterator, Allocator>& m2);

    template <class BidirectionalIterator, class Allocator>
    bool operator!=(const match_results<BidirectionalIterator, Allocator>& m1,
                    const match_results<BidirectionalIterator, Allocator>& m2);

    template <class BidirectionalIterator, class Allocator>
    void swap(match_results<BidirectionalIterator, Allocator>& m1, match_results<BidirectionalIterator, Allocator>& m2);

    template <class BidirectionalIterator, class Allocator, class charT, class traits>
    bool regex_match(BidirectionalIterator first, BidirectionalIterator last,
                     match_results<BidirectionalIterator, Allocator>& m, const basic_regex<charT, traits>& e,
                     regex_constants::match_flag_type flags = regex_constants::match_default);

    template <class BidirectionalIterator, class charT, class traits>
    bool regex_match(BidirectionalIterator first, BidirectionalIterator last, const basic_regex<charT, traits>& e,
                     regex_constants::match_flag_type flags = regex_constants::match_default);

    template <class charT, class Allocator, class traits>
    bool regex_match(const charT* str, match_results<const charT*, Allocator>& m, const basic_regex<charT, traits>& e,
                     regex_constants::match_flag_type flags = regex_constants::match_default);

    template <class ST, class SA, class Allocator, class charT, class traits>
    bool regex_match(const std::basic_string<charT, ST, SA>& s,
                     match_results<typename std::basic_string<charT, ST, SA>::const_iterator, Allocator>& m,
                     const basic_regex<charT, traits>& e,
                     regex_constants::match_flag_type flags = regex_constants::match_default);

    template <class ST, class SA, class Allocator, class charT, class traits>
    bool regex_match(const std::basic_string<charT, ST, SA>&& s,
                     match_results<typename std::basic_string<charT, ST, SA>::const_iterator, Allocator>& m,
                     const basic_regex<charT, traits>& e,
                     regex_constants::match_flag_type flags = regex_constants::match_default) = delete;  // C++14

    template <class charT, class traits>
    bool regex_match(const charT* str, const basic_regex<charT, traits>& e,
                     regex_constants::match_flag_type flags = regex_constants::match_default);

    template <class ST, class SA, class charT, class traits>
    bool regex_match(const std::basic_string<charT, ST, SA>& s, const basic_regex<charT, traits>& e,
                     regex_constants::match_flag_type flags = regex_constants::match_default);

    template <class BidirectionalIterator, class Allocator, class charT, class traits>
    bool regex_search(BidirectionalIterator first, BidirectionalIterator last,
                      match_results<BidirectionalIterator, Allocator>& m, const basic_regex<charT, traits>& e,
                      regex_constants::match_flag_type flags = regex_constants::match_default);

    template <class BidirectionalIterator, class charT, class traits>
    bool regex_search(BidirectionalIterator first, BidirectionalIterator last, const basic_regex<charT, traits>& e,
                      regex_constants::match_flag_type flags = regex_constants::match_default);

    template <class charT, class Allocator, class traits>
    bool regex_search(const charT* str, match_results<const charT*, Allocator>& m, const basic_regex<charT, traits>& e,
                      regex_constants::match_flag_type flags = regex_constants::match_default);

    template <class charT, class traits>
    bool regex_search(const charT* str, const basic_regex<charT, traits>& e,
                      regex_constants::match_flag_type flags = regex_constants::match_default);

    template <class ST, class SA, class charT, class traits>
    bool regex_search(const std::basic_string<charT, ST, SA>& s, const basic_regex<charT, traits>& e,
                      regex_constants::match_flag_type flags = regex_constants::match_default);

    template <class ST, class SA, class Allocator, class charT, class traits>
    bool regex_search(const std::basic_string<charT, ST, SA>& s,
                      match_results<typename std::basic_string<charT, ST, SA>::const_iterator, Allocator>& m,
                      const basic_regex<charT, traits>& e,
                      regex_constants::match_flag_type flags = regex_constants::match_default);

    template <class ST, class SA, class Allocator, class charT, class traits>
    bool regex_search(const std::basic_string<charT, ST, SA>&& s,
                      match_results<typename std::basic_string<charT, ST, SA>::const_iterator, Allocator>& m,
                      const basic_regex<charT, traits>& e,
                      regex_constants::match_flag_type flags = regex_constants::match_default) = delete;  // C++14

    template <class OutputIterator, class BidirectionalIterator, class traits, class charT, class ST, class SA>
    OutputIterator regex_replace(OutputIterator out, BidirectionalIterator first, BidirectionalIterator last,
                                 const basic_regex<charT, traits>& e, const std::basic_string<charT, ST, SA>& fmt,
                                 regex_constants::match_flag_type flags = regex_constants::match_default);

    template <class OutputIterator, class BidirectionalIterator, class traits, class charT>
    OutputIterator regex_replace(OutputIterator out, BidirectionalIterator first, BidirectionalIterator last,
                                 const basic_regex<charT, traits>& e, const charT* fmt,
                                 regex_constants::match_flag_type flags = regex_constants::match_default);

    template <class traits, class charT, class ST, class SA, class FST, class FSA>
    std::basic_string<charT, ST, SA> regex_replace(
        const std::basic_string<charT, ST, SA>& s, const basic_regex<charT, traits>& e,
        const std::basic_string<charT, FST, FSA>& fmt,
        regex_constants::match_flag_type flags = regex_constants::match_default);

    template <class traits, class charT, class ST, class SA>
    std::basic_string<charT, ST, SA> regex_replace(
        const std::basic_string<charT, ST, SA>& s, const basic_regex<charT, traits>& e, const charT* fmt,
        regex_constants::match_flag_type flags = regex_constants::match_default);

    template <class traits, class charT, class ST, class SA>
    std::basic_string<charT> regex_replace(const charT* s, const basic_regex<charT, traits>& e,
                                           const std::basic_string<charT, ST, SA>& fmt,
                                           regex_constants::match_flag_type flags = regex_constants::match_default);

    template <class traits, class charT>
    std::basic_string<charT> regex_replace(const charT* s, const basic_regex<charT, traits>& e, const charT* fmt,
                                           regex_constants::match_flag_type flags = regex_constants::match_default);

    template <class BidirectionalIterator,
              class charT = typename std::iterator_traits<BidirectionalIterator>::value_type,
              class traits = regex_traits<charT>>
    class regex_iterator {
      public:
        typedef basic_regex<charT, traits> regex_type;
        typedef match_results<BidirectionalIterator> value_type;
        typedef ptrdiff_t difference_type;
        typedef const value_type* pointer;
        typedef const value_type& reference;
        typedef std::forward_iterator_tag iterator_category;

        regex_iterator();
        regex_iterator(BidirectionalIterator a, BidirectionalIterator b, const regex_type& re,
                       regex_constants::match_flag_type m = regex_constants::match_default);
        regex_iterator(BidirectionalIterator __a, BidirectionalIterator __b, const regex_type&& __re,
                       regex_constants::match_flag_type __m = regex_constants::match_default) = delete;  // C++14
        regex_iterator(const regex_iterator&);
        regex_iterator& operator=(const regex_iterator&);

        bool operator==(const regex_iterator&) const;
        bool operator!=(const regex_iterator&) const;

        const value_type& operator*() const;
        const value_type* operator->() const;

        regex_iterator& operator++();
        regex_iterator operator++(int);
    };

    typedef regex_iterator<const char*> cregex_iterator;
    typedef regex_iterator<const wchar_t*> wcregex_iterator;
    typedef regex_iterator<std::string::const_iterator> sregex_iterator;
    typedef regex_iterator<std::wstring::const_iterator> wsregex_iterator;

    template <class BidirectionalIterator,
              class charT = typename std::iterator_traits<BidirectionalIterator>::value_type,
              class traits = regex_traits<charT>>
    class regex_token_iterator {
      public:
        typedef basic_regex<charT, traits> regex_type;
        typedef sub_match<BidirectionalIterator> value_type;
        typedef ptrdiff_t difference_type;
        typedef const value_type* pointer;
        typedef const value_type& reference;
        typedef std::forward_iterator_tag iterator_category;

        regex_token_iterator();
        regex_token_iterator(BidirectionalIterator a, BidirectionalIterator b, const regex_type& re, int submatch = 0,
                             regex_constants::match_flag_type m = regex_constants::match_default);
        regex_token_iterator(BidirectionalIterator a, BidirectionalIterator b, const regex_type&& re, int submatch = 0,
                             regex_constants::match_flag_type m = regex_constants::match_default) = delete;  // C++14
        regex_token_iterator(BidirectionalIterator a, BidirectionalIterator b, const regex_type& re,
                             const std::vector<int>& submatches,
                             regex_constants::match_flag_type m = regex_constants::match_default);
        regex_token_iterator(BidirectionalIterator a, BidirectionalIterator b, const regex_type&& re,
                             const std::vector<int>& submatches,
                             regex_constants::match_flag_type m = regex_constants::match_default) = delete;  // C++14
        regex_token_iterator(BidirectionalIterator a, BidirectionalIterator b, const regex_type& re,
                             std::initializer_list<int> submatches,
                             regex_constants::match_flag_type m = regex_constants::match_default);
        regex_token_iterator(BidirectionalIterator a, BidirectionalIterator b, const regex_type&& re,
                             std::initializer_list<int> submatches,
                             regex_constants::match_flag_type m = regex_constants::match_default) = delete;  // C++14
        template <size_t N>
        regex_token_iterator(BidirectionalIterator a, BidirectionalIterator b, const regex_type& re,
                             const int (&submatches)[N],
                             regex_constants::match_flag_type m = regex_constants::match_default);
        template <size_t N>
        regex_token_iterator(BidirectionalIterator a, BidirectionalIterator b, const regex_type& re,
                             const int (&submatches)[N],
                             regex_constants::match_flag_type m = regex_constants::match_default) = delete  // C++14;
            regex_token_iterator(const regex_token_iterator&);
        regex_token_iterator& operator=(const regex_token_iterator&);

        bool operator==(const regex_token_iterator&) const;
        bool operator!=(const regex_token_iterator&) const;

        const value_type& operator*() const;
        const value_type* operator->() const;

        regex_token_iterator& operator++();
        regex_token_iterator operator++(int);
    };

    typedef regex_token_iterator<const char*> cregex_token_iterator;
    typedef regex_token_iterator<const wchar_t*> wcregex_token_iterator;
    typedef regex_token_iterator<std::string::const_iterator> sregex_token_iterator;
    typedef regex_token_iterator<std::wstring::const_iterator> wsregex_token_iterator;

}  // namespace GP

#endif  // REGEX_HPP
