#include "bits/stdc++.h"

namespace GP {

    template <class charT, class traits = std::char_traits<charT>, class Allocator = std::allocator<charT> >
    class basic_stringbuf : public std::basic_streambuf<charT, traits> {
      public:
        typedef charT char_type;
        typedef traits traits_type;
        typedef typename traits_type::int_type int_type;
        typedef typename traits_type::pos_type pos_type;
        typedef typename traits_type::off_type off_type;
        typedef Allocator allocator_type;

        // 27.8.1.1 Constructors:
        explicit basic_stringbuf(std::ios_base::openmode which = std::ios_base::in | std::ios_base::out);
        explicit basic_stringbuf(const std::basic_string<char_type, traits_type, allocator_type>& str,
                                 std::ios_base::openmode which = std::ios_base::in | std::ios_base::out);
        basic_stringbuf(basic_stringbuf&& rhs);

        // 27.8.1.2 Assign and swap:
        basic_stringbuf& operator=(basic_stringbuf&& rhs);
        void swap(basic_stringbuf& rhs);

        // 27.8.1.3 Get and set:
        std::basic_string<char_type, traits_type, allocator_type> str() const;
        void str(const std::basic_string<char_type, traits_type, allocator_type>& s);

      protected:
        // 27.8.1.4 Overridden virtual functions:
        virtual int_type underflow();
        virtual int_type pbackfail(int_type c = traits_type::eof());
        virtual int_type overflow(int_type c = traits_type::eof());
        virtual std::basic_streambuf<char_type, traits_type>* setbuf(char_type*, std::streamsize);
        virtual pos_type seekoff(off_type off, std::ios_base::seekdir way,
                                 std::ios_base::openmode which = std::ios_base::in | std::ios_base::out);
        virtual pos_type seekpos(pos_type sp, std::ios_base::openmode which = std::ios_base::in | std::ios_base::out);
    };

    template <class charT, class traits, class Allocator>
    void swap(basic_stringbuf<charT, traits, Allocator>& x, basic_stringbuf<charT, traits, Allocator>& y);

    typedef basic_stringbuf<char> stringbuf;
    typedef basic_stringbuf<wchar_t> wstringbuf;

    template <class charT, class traits = std::char_traits<charT>, class Allocator = std::allocator<charT> >
    class basic_istringstream : public std::basic_istream<charT, traits> {
      public:
        typedef charT char_type;
        typedef traits traits_type;
        typedef typename traits_type::int_type int_type;
        typedef typename traits_type::pos_type pos_type;
        typedef typename traits_type::off_type off_type;
        typedef Allocator allocator_type;

        // 27.8.2.1 Constructors:
        explicit basic_istringstream(std::ios_base::openmode which = std::ios_base::in);
        explicit basic_istringstream(const std::basic_string<char_type, traits_type, allocator_type>& str,
                                     std::ios_base::openmode which = std::ios_base::in);
        basic_istringstream(basic_istringstream&& rhs);

        // 27.8.2.2 Assign and swap:
        basic_istringstream& operator=(basic_istringstream&& rhs);
        void swap(basic_istringstream& rhs);

        // 27.8.2.3 Members:
        basic_stringbuf<char_type, traits_type, allocator_type>* rdbuf() const;
        std::basic_string<char_type, traits_type, allocator_type> str() const;
        void str(const std::basic_string<char_type, traits_type, allocator_type>& s);
    };

    template <class charT, class traits, class Allocator>
    void swap(basic_istringstream<charT, traits, Allocator>& x, basic_istringstream<charT, traits, Allocator>& y);

    typedef basic_istringstream<char> istringstream;
    typedef basic_istringstream<wchar_t> wistringstream;

    template <class charT, class traits = std::char_traits<charT>, class Allocator = std::allocator<charT> >
    class basic_ostringstream : public std::basic_ostream<charT, traits> {
      public:
        // types:
        typedef charT char_type;
        typedef traits traits_type;
        typedef typename traits_type::int_type int_type;
        typedef typename traits_type::pos_type pos_type;
        typedef typename traits_type::off_type off_type;
        typedef Allocator allocator_type;

        // 27.8.3.1 Constructors/destructor:
        explicit basic_ostringstream(std::ios_base::openmode which = std::ios_base::out);
        explicit basic_ostringstream(const std::basic_string<char_type, traits_type, allocator_type>& str,
                                     std::ios_base::openmode which = std::ios_base::out);
        basic_ostringstream(basic_ostringstream&& rhs);

        // 27.8.3.2 Assign/swap:
        basic_ostringstream& operator=(basic_ostringstream&& rhs);
        void swap(basic_ostringstream& rhs);

        // 27.8.3.3 Members:
        basic_stringbuf<char_type, traits_type, allocator_type>* rdbuf() const;
        std::basic_string<char_type, traits_type, allocator_type> str() const;
        void str(const std::basic_string<char_type, traits_type, allocator_type>& s);
    };

    template <class charT, class traits, class Allocator>
    void swap(basic_ostringstream<charT, traits, Allocator>& x, basic_ostringstream<charT, traits, Allocator>& y);

    typedef basic_ostringstream<char> ostringstream;
    typedef basic_ostringstream<wchar_t> wostringstream;

    template <class charT, class traits = std::char_traits<charT>, class Allocator = std::allocator<charT> >
    class basic_stringstream : public std::basic_iostream<charT, traits> {
      public:
        // types:
        typedef charT char_type;
        typedef traits traits_type;
        typedef typename traits_type::int_type int_type;
        typedef typename traits_type::pos_type pos_type;
        typedef typename traits_type::off_type off_type;
        typedef Allocator allocator_type;

        // constructors/destructor
        explicit basic_stringstream(std::ios_base::openmode which = std::ios_base::out | std::ios_base::in);
        explicit basic_stringstream(const std::basic_string<char_type, traits_type, allocator_type>& str,
                                    std::ios_base::openmode which = std::ios_base::out | std::ios_base::in);
        basic_stringstream(basic_stringstream&& rhs);

        // 27.8.5.1 Assign/swap:
        basic_stringstream& operator=(basic_stringstream&& rhs);
        void swap(basic_stringstream& rhs);

        // Members:
        basic_stringbuf<char_type, traits_type, allocator_type>* rdbuf() const;
        std::basic_string<char_type, traits_type, allocator_type> str() const;
        void str(const std::basic_string<char_type, traits_type, allocator_type>& str);
    };

    template <class charT, class traits, class Allocator>
    void swap(basic_stringstream<charT, traits, Allocator>& x, basic_stringstream<charT, traits, Allocator>& y);

    typedef basic_stringstream<char> stringstream;
    typedef basic_stringstream<wchar_t> wstringstream;

}  // namespace GP
