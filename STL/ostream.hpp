#ifndef OSTREAM_HPP
#define OSTREAM_HPP

#include "bits/stdc++.h"

namespace GP {

    template <class charT, class traits = std::char_traits<charT> >
    class basic_ostream : virtual public std::basic_ios<charT, traits> {
      public:
        // types (inherited from basic_ios (27.5.4)):
        typedef charT char_type;
        typedef traits traits_type;
        typedef typename traits_type::int_type int_type;
        typedef typename traits_type::pos_type pos_type;
        typedef typename traits_type::off_type off_type;

        // 27.7.2.2 Constructor/destructor:
        explicit basic_ostream(std::basic_streambuf<char_type, traits>* sb);
        basic_ostream(basic_ostream&& rhs);
        virtual ~basic_ostream();

        // 27.7.2.3 Assign/swap
        basic_ostream& operator=(const basic_ostream& rhs) = delete;  // C++14
        basic_ostream& operator=(basic_ostream&& rhs);
        void swap(basic_ostream& rhs);

        // 27.7.2.4 Prefix/suffix:
        class sentry;

        // 27.7.2.6 Formatted output:
        basic_ostream& operator<<(basic_ostream& (*pf)(basic_ostream&));
        basic_ostream& operator<<(std::basic_ios<charT, traits>& (*pf)(std::basic_ios<charT, traits>&));
        basic_ostream& operator<<(std::ios_base& (*pf)(std::ios_base&));
        basic_ostream& operator<<(bool n);
        basic_ostream& operator<<(short n);
        basic_ostream& operator<<(unsigned short n);
        basic_ostream& operator<<(int n);
        basic_ostream& operator<<(unsigned int n);
        basic_ostream& operator<<(long n);
        basic_ostream& operator<<(unsigned long n);
        basic_ostream& operator<<(long long n);
        basic_ostream& operator<<(unsigned long long n);
        basic_ostream& operator<<(float f);
        basic_ostream& operator<<(double f);
        basic_ostream& operator<<(long double f);
        basic_ostream& operator<<(const void* p);
        basic_ostream& operator<<(std::basic_streambuf<char_type, traits>* sb);

        // 27.7.2.7 Unformatted output:
        basic_ostream& put(char_type c);
        basic_ostream& write(const char_type* s, std::streamsize n);
        basic_ostream& flush();

        // 27.7.2.5 seeks:
        pos_type tellp();
        basic_ostream& seekp(pos_type);
        basic_ostream& seekp(off_type, std::ios_base::seekdir);

      protected:
        basic_ostream(const basic_ostream& rhs) = delete;
        basic_ostream(basic_ostream&& rhs);
        // 27.7.3.3 Assign/swap
        basic_ostream& operator=(basic_ostream& rhs) = delete;
        basic_ostream& operator=(const basic_ostream&& rhs);
        void swap(basic_ostream& rhs);
    };

    // 27.7.2.6.4 character inserters

    template <class charT, class traits>
    basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>&, charT);

    template <class charT, class traits>
    basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>&, char);

    template <class traits>
    basic_ostream<char, traits>& operator<<(basic_ostream<char, traits>&, char);

    // signed and unsigned

    template <class traits>
    basic_ostream<char, traits>& operator<<(basic_ostream<char, traits>&, signed char);

    template <class traits>
    basic_ostream<char, traits>& operator<<(basic_ostream<char, traits>&, unsigned char);

    // NTBS
    template <class charT, class traits>
    basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>&, const charT*);

    template <class charT, class traits>
    basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>&, const char*);

    template <class traits>
    basic_ostream<char, traits>& operator<<(basic_ostream<char, traits>&, const char*);

    // signed and unsigned
    template <class traits>
    basic_ostream<char, traits>& operator<<(basic_ostream<char, traits>&, const signed char*);

    template <class traits>
    basic_ostream<char, traits>& operator<<(basic_ostream<char, traits>&, const unsigned char*);

    // swap:
    template <class charT, class traits>
    void swap(basic_ostream<charT, traits>& x, basic_ostream<charT, traits>& y);

    template <class charT, class traits>
    basic_ostream<charT, traits>& endl(basic_ostream<charT, traits>& os);

    template <class charT, class traits>
    basic_ostream<charT, traits>& ends(basic_ostream<charT, traits>& os);

    template <class charT, class traits>
    basic_ostream<charT, traits>& flush(basic_ostream<charT, traits>& os);

    // rvalue stream insertion
    template <class charT, class traits, class T>
    basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>&& os, const T& x);

}  // namespace GP

#endif  // OSTREAM_HPP
