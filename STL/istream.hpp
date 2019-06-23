#ifndef ISTREAM_HPP
#define ISTREAM_HPP

#include "bits/stdc++.h"
namespace GP {

    template <class charT, class traits = std::char_traits<charT> >
    class basic_istream : virtual public std::basic_ios<charT, traits> {
      public:
        // types (inherited from basic_ios (27.5.4)):
        typedef charT char_type;
        typedef traits traits_type;
        typedef typename traits_type::int_type int_type;
        typedef typename traits_type::pos_type pos_type;
        typedef typename traits_type::off_type off_type;

        // 27.7.1.1.1 Constructor/destructor:
        explicit basic_istream(std::basic_streambuf<char_type, traits_type>* sb);
        basic_istream(basic_istream&& rhs);
        virtual ~basic_istream();

        // 27.7.1.1.2 Assign/swap:
        basic_istream& operator=(basic_istream&& rhs);
        void swap(basic_istream& rhs);

        // 27.7.1.1.3 Prefix/suffix:
        class sentry;

        // 27.7.1.2 Formatted input:
        basic_istream& operator>>(basic_istream& (*pf)(basic_istream&));
        basic_istream& operator>>(
            std::basic_ios<char_type, traits_type>& (*pf)(std::basic_ios<char_type, traits_type>&));
        basic_istream& operator>>(std::ios_base& (*pf)(std::ios_base&));
        basic_istream& operator>>(std::basic_streambuf<char_type, traits_type>* sb);
        basic_istream& operator>>(bool& n);
        basic_istream& operator>>(short& n);
        basic_istream& operator>>(unsigned short& n);
        basic_istream& operator>>(int& n);
        basic_istream& operator>>(unsigned int& n);
        basic_istream& operator>>(long& n);
        basic_istream& operator>>(unsigned long& n);
        basic_istream& operator>>(long long& n);
        basic_istream& operator>>(unsigned long long& n);
        basic_istream& operator>>(float& f);
        basic_istream& operator>>(double& f);
        basic_istream& operator>>(long double& f);
        basic_istream& operator>>(void*& p);

        // 27.7.1.3 Unformatted input:
        std::streamsize gcount() const;
        int_type get();
        basic_istream& get(char_type& c);
        basic_istream& get(char_type* s, std::streamsize n);
        basic_istream& get(char_type* s, std::streamsize n, char_type delim);
        basic_istream& get(std::basic_streambuf<char_type, traits_type>& sb);
        basic_istream& get(std::basic_streambuf<char_type, traits_type>& sb, char_type delim);

        basic_istream& getline(char_type* s, std::streamsize n);
        basic_istream& getline(char_type* s, std::streamsize n, char_type delim);

        basic_istream& ignore(std::streamsize n = 1, int_type delim = traits_type::eof());
        int_type peek();
        basic_istream& read(char_type* s, std::streamsize n);
        std::streamsize readsome(char_type* s, std::streamsize n);

        basic_istream& putback(char_type c);
        basic_istream& unget();
        int sync();

        pos_type tellg();
        basic_istream& seekg(pos_type);
        basic_istream& seekg(off_type, std::ios_base::seekdir);

      protected:
        basic_istream(const basic_istream& rhs) = delete;
        basic_istream(basic_istream&& rhs);
        // 27.7.2.1.2 Assign/swap:
        basic_istream& operator=(const basic_istream& rhs) = delete;
        basic_istream& operator=(basic_istream&& rhs);
        void swap(basic_istream& rhs);
    };

    // 27.7.1.2.3 character extraction templates:
    template <class charT, class traits>
    basic_istream<charT, traits>& operator>>(basic_istream<charT, traits>&, charT&);

    template <class traits>
    basic_istream<char, traits>& operator>>(basic_istream<char, traits>&, unsigned char&);

    template <class traits>
    basic_istream<char, traits>& operator>>(basic_istream<char, traits>&, signed char&);

    template <class charT, class traits>
    basic_istream<charT, traits>& operator>>(basic_istream<charT, traits>&, charT*);

    template <class traits>
    basic_istream<char, traits>& operator>>(basic_istream<char, traits>&, unsigned char*);

    template <class traits>
    basic_istream<char, traits>& operator>>(basic_istream<char, traits>&, signed char*);

    template <class charT, class traits>
    void swap(basic_istream<charT, traits>& x, basic_istream<charT, traits>& y);

    typedef basic_istream<char> istream;
    typedef basic_istream<wchar_t> wistream;

    template <class charT, class traits = std::char_traits<charT> >
    class basic_iostream : public basic_istream<charT, traits>, public std::basic_ostream<charT, traits> {
      public:
        // types:
        typedef charT char_type;
        typedef traits traits_type;
        typedef typename traits_type::int_type int_type;
        typedef typename traits_type::pos_type pos_type;
        typedef typename traits_type::off_type off_type;

        // constructor/destructor
        explicit basic_iostream(std::basic_streambuf<char_type, traits_type>* sb);
        basic_iostream(basic_iostream&& rhs);
        virtual ~basic_iostream();

        // assign/swap
        basic_iostream& operator=(basic_iostream&& rhs);
        void swap(basic_iostream& rhs);
    };

    template <class charT, class traits>
    void swap(basic_iostream<charT, traits>& x, basic_iostream<charT, traits>& y);

    typedef basic_iostream<char> iostream;
    typedef basic_iostream<wchar_t> wiostream;

    template <class charT, class traits>
    basic_istream<charT, traits>& ws(basic_istream<charT, traits>& is);

    template <class charT, class traits, class T>
    basic_istream<charT, traits>& operator>>(basic_istream<charT, traits>&& is, T& x);

}  // namespace GP

#endif  // ISTREAM_HPP
