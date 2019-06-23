#ifndef IOS_HPP
#define IOS_HPP

#include "bits/stdc++.h"

namespace GP {

    typedef OFF_T streamoff;
    typedef SZ_T streamsize;
    template <class stateT>
    class fpos;

    class ios_base {
      public:
        class failure;

        typedef T1 fmtflags;
        static constexpr fmtflags boolalpha;
        static constexpr fmtflags dec;
        static constexpr fmtflags fixed;
        static constexpr fmtflags hex;
        static constexpr fmtflags internal;
        static constexpr fmtflags left;
        static constexpr fmtflags oct;
        static constexpr fmtflags right;
        static constexpr fmtflags scientific;
        static constexpr fmtflags showbase;
        static constexpr fmtflags showpoint;
        static constexpr fmtflags showpos;
        static constexpr fmtflags skipws;
        static constexpr fmtflags unitbuf;
        static constexpr fmtflags uppercase;
        static constexpr fmtflags adjustfield;
        static constexpr fmtflags basefield;
        static constexpr fmtflags floatfield;

        typedef T2 iostate;
        static constexpr iostate badbit;
        static constexpr iostate eofbit;
        static constexpr iostate failbit;
        static constexpr iostate goodbit;

        typedef T3 openmode;
        static constexpr openmode app;
        static constexpr openmode ate;
        static constexpr openmode binary;
        static constexpr openmode in;
        static constexpr openmode out;
        static constexpr openmode trunc;

        typedef T4 seekdir;
        static constexpr seekdir beg;
        static constexpr seekdir cur;
        static constexpr seekdir end;

        class Init;

        // 27.5.2.2 fmtflags state:
        fmtflags flags() const;
        fmtflags flags(fmtflags fmtfl);
        fmtflags setf(fmtflags fmtfl);
        fmtflags setf(fmtflags fmtfl, fmtflags mask);
        void unsetf(fmtflags mask);

        streamsize precision() const;
        streamsize precision(streamsize prec);
        streamsize width() const;
        streamsize width(streamsize wide);

        // 27.5.2.3 locales:
        locale imbue(const locale& loc);
        locale getloc() const;

        // 27.5.2.5 storage:
        static int xalloc();
        long& iword(int index);
        void*& pword(int index);

        // destructor
        virtual ~ios_base();

        // 27.5.2.6 callbacks;
        enum event { erase_event, imbue_event, copyfmt_event };
        typedef void (*event_callback)(event, ios_base&, int index);
        void register_callback(event_callback fn, int index);

        ios_base(const ios_base&) = delete;
        ios_base& operator=(const ios_base&) = delete;

        static bool sync_with_stdio(bool sync = true);

      protected:
        ios_base();
    };

    template <class charT, class traits = char_traits<charT> >
    class basic_ios : public ios_base {
      public:
        // types:
        typedef charT char_type;
        typedef typename traits::int_type int_type;  // removed in C++17
        typedef typename traits::pos_type pos_type;  // removed in C++17
        typedef typename traits::off_type off_type;  // removed in C++17
        typedef traits traits_type;

        operator unspecified - bool - type() const;
        bool operator!() const;
        iostate rdstate() const;
        void clear(iostate state = goodbit);
        void setstate(iostate state);
        bool good() const;
        bool eof() const;
        bool fail() const;
        bool bad() const;

        iostate exceptions() const;
        void exceptions(iostate except);

        // 27.5.4.1 Constructor/destructor:
        explicit basic_ios(basic_streambuf<charT, traits>* sb);
        virtual ~basic_ios();

        // 27.5.4.2 Members:
        basic_ostream<charT, traits>* tie() const;
        basic_ostream<charT, traits>* tie(basic_ostream<charT, traits>* tiestr);

        basic_streambuf<charT, traits>* rdbuf() const;
        basic_streambuf<charT, traits>* rdbuf(basic_streambuf<charT, traits>* sb);

        basic_ios& copyfmt(const basic_ios& rhs);

        char_type fill() const;
        char_type fill(char_type ch);

        locale imbue(const locale& loc);

        char narrow(char_type c, char dfault) const;
        char_type widen(char c) const;

        basic_ios(const basic_ios&) = delete;
        basic_ios& operator=(const basic_ios&) = delete;

      protected:
        basic_ios();
        void init(basic_streambuf<charT, traits>* sb);
        void move(basic_ios& rhs);
        void swap(basic_ios& rhs) noexcept;
        void set_rdbuf(basic_streambuf<charT, traits>* sb);
    };

    // 27.5.5, manipulators:
    ios_base& boolalpha(ios_base& str);
    ios_base& noboolalpha(ios_base& str);
    ios_base& showbase(ios_base& str);
    ios_base& noshowbase(ios_base& str);
    ios_base& showpoint(ios_base& str);
    ios_base& noshowpoint(ios_base& str);
    ios_base& showpos(ios_base& str);
    ios_base& noshowpos(ios_base& str);
    ios_base& skipws(ios_base& str);
    ios_base& noskipws(ios_base& str);
    ios_base& uppercase(ios_base& str);
    ios_base& nouppercase(ios_base& str);
    ios_base& unitbuf(ios_base& str);
    ios_base& nounitbuf(ios_base& str);

    // 27.5.5.2 adjustfield:
    ios_base& internal(ios_base& str);
    ios_base& left(ios_base& str);
    ios_base& right(ios_base& str);

    // 27.5.5.3 basefield:
    ios_base& dec(ios_base& str);
    ios_base& hex(ios_base& str);
    ios_base& oct(ios_base& str);

    // 27.5.5.4 floatfield:
    ios_base& fixed(ios_base& str);
    ios_base& scientific(ios_base& str);
    ios_base& hexfloat(ios_base& str);
    ios_base& defaultfloat(ios_base& str);

    // 27.5.5.5 error reporting:
    enum class io_errc { stream = 1 };

    concept_map ErrorCodeEnum<io_errc>{};
    error_code make_error_code(io_errc e) noexcept;
    error_condition make_error_condition(io_errc e) noexcept;
    storage - class - specifier const error_category& iostream_category() noexcept;

}  // namespace GP

#endif  // IOS_HPP
