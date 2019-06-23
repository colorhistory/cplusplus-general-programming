#ifndef FSTREAM_HPP
#define FSTREAM_HPP

#include "bits/stdc++.h"
#include "experimental/filesystem"

namespace GP {

    template <class charT, class traits = std::char_traits<charT> >
    class basic_filebuf : public std::basic_streambuf<charT, traits> {
      public:
        typedef charT char_type;
        typedef traits traits_type;
        typedef typename traits_type::int_type int_type;
        typedef typename traits_type::pos_type pos_type;
        typedef typename traits_type::off_type off_type;

        // 27.9.1.2 Constructors/destructor:
        basic_filebuf();
        basic_filebuf(basic_filebuf&& rhs);
        virtual ~basic_filebuf();

        // 27.9.1.3 Assign/swap:
        basic_filebuf& operator=(basic_filebuf&& rhs);
        void swap(basic_filebuf& rhs);

        // 27.9.1.4 Members:
        bool is_open() const;
        basic_filebuf* open(const char* s, std::ios_base::openmode mode);
        basic_filebuf* open(const std::string& s, std::ios_base::openmode mode);
        basic_filebuf* open(const std::experimental::filesystem::v1::path& p,
                            std::ios_base::openmode mode);  // C++17
        basic_filebuf* close();

      protected:
        // 27.9.1.5 Overridden virtual functions:
        virtual std::streamsize showmanyc();
        virtual int_type underflow();
        virtual int_type uflow();
        virtual int_type pbackfail(int_type c = traits_type::eof());
        virtual int_type overflow(int_type c = traits_type::eof());
        virtual std::basic_streambuf<char_type, traits_type>* setbuf(char_type* s, std::streamsize n);
        virtual pos_type seekoff(off_type off, std::ios_base::seekdir way,
                                 std::ios_base::openmode which = std::ios_base::in | std::ios_base::out);
        virtual pos_type seekpos(pos_type sp, std::ios_base::openmode which = std::ios_base::in | std::ios_base::out);
        virtual int sync();
        virtual void imbue(const std::locale& loc);
    };

    template <class charT, class traits>
    void swap(basic_filebuf<charT, traits>& x, basic_filebuf<charT, traits>& y);

    typedef basic_filebuf<char> filebuf;
    typedef basic_filebuf<wchar_t> wfilebuf;

    template <class charT, class traits = std::char_traits<charT> >
    class basic_ifstream : public std::basic_istream<charT, traits> {
      public:
        typedef charT char_type;
        typedef traits traits_type;
        typedef typename traits_type::int_type int_type;
        typedef typename traits_type::pos_type pos_type;
        typedef typename traits_type::off_type off_type;

        basic_ifstream();
        explicit basic_ifstream(const char* s, std::ios_base::openmode mode = std::ios_base::in);
        explicit basic_ifstream(const std::string& s, std::ios_base::openmode mode = std::ios_base::in);
        explicit basic_ifstream(const std::experimental::filesystem::v1::path& p,
                                std::ios_base::openmode mode = std::ios_base::in);  // C++17
        basic_ifstream(basic_ifstream&& rhs);

        basic_ifstream& operator=(basic_ifstream&& rhs);
        void swap(basic_ifstream& rhs);

        basic_filebuf<char_type, traits_type>* rdbuf() const;
        bool is_open() const;
        void open(const char* s, std::ios_base::openmode mode = std::ios_base::in);
        void open(const std::string& s, std::ios_base::openmode mode = std::ios_base::in);
        void open(const std::experimental::filesystem::v1::path& s,
                  std::ios_base::openmode mode = std::ios_base::in);  // C++17

        void close();
    };

    template <class charT, class traits>
    void swap(basic_ifstream<charT, traits>& x, basic_ifstream<charT, traits>& y);

    typedef basic_ifstream<char> ifstream;
    typedef basic_ifstream<wchar_t> wifstream;

    template <class charT, class traits = std::char_traits<charT> >
    class basic_ofstream : public std::basic_ostream<charT, traits> {
      public:
        typedef charT char_type;
        typedef traits traits_type;
        typedef typename traits_type::int_type int_type;
        typedef typename traits_type::pos_type pos_type;
        typedef typename traits_type::off_type off_type;

        basic_ofstream();
        explicit basic_ofstream(const char* s, std::ios_base::openmode mode = std::ios_base::out);
        explicit basic_ofstream(const std::string& s, std::ios_base::openmode mode = std::ios_base::out);
        explicit basic_ofstream(const std::experimental::filesystem::v1::path& p,
                                std::ios_base::openmode mode = std::ios_base::out);  // C++17
        basic_ofstream(basic_ofstream&& rhs);

        basic_ofstream& operator=(basic_ofstream&& rhs);
        void swap(basic_ofstream& rhs);

        basic_filebuf<char_type, traits_type>* rdbuf() const;
        bool is_open() const;
        void open(const char* s, std::ios_base::openmode mode = std::ios_base::out);
        void open(const std::string& s, std::ios_base::openmode mode = std::ios_base::out);
        void open(const std::experimental::filesystem::v1::path& p,
                  std::ios_base::openmode mode = std::ios_base::out);  // C++17

        void close();
    };

    template <class charT, class traits>
    void swap(basic_ofstream<charT, traits>& x, basic_ofstream<charT, traits>& y);

    typedef basic_ofstream<char> ofstream;
    typedef basic_ofstream<wchar_t> wofstream;

    template <class charT, class traits = std::char_traits<charT> >
    class basic_fstream : public std::basic_iostream<charT, traits> {
      public:
        typedef charT char_type;
        typedef traits traits_type;
        typedef typename traits_type::int_type int_type;
        typedef typename traits_type::pos_type pos_type;
        typedef typename traits_type::off_type off_type;

        basic_fstream();
        explicit basic_fstream(const char* s, std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out);
        explicit basic_fstream(const std::string& s,
                               std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out);
        explicit basic_fstream(const std::experimental::filesystem::v1::path& p,
                               std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out);
        basic_fstream(basic_fstream&& rhs);

        basic_fstream& operator=(basic_fstream&& rhs);
        void swap(basic_fstream& rhs);

        basic_filebuf<char_type, traits_type>* rdbuf() const;
        bool is_open() const;
        void open(const char* s, std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out);
        void open(const std::string& s, std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out);
        void open(const std::experimental::filesystem::v1::path& s,
                  std::ios_base::openmode mode = std::ios_base::in | std::ios_base::out);  // C++17

        void close();
    };

    template <class charT, class traits>
    void swap(basic_fstream<charT, traits>& x, basic_fstream<charT, traits>& y);

    typedef basic_fstream<char> fstream;
    typedef basic_fstream<wchar_t> wfstream;

}  // namespace GP

#endif  // FSTREAM_HPP
