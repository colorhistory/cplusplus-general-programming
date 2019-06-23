#ifndef IOSTREAM_HPP
#define IOSTREAM_HPP

#include <ios>
#include <istream>
#include <ostream>
#include <streambuf>

namespace GP {

    extern std::istream cin;
    extern std::ostream cout;
    extern std::ostream cerr;
    extern std::ostream clog;
    extern std::wistream wcin;
    extern std::wostream wcout;
    extern std::wostream wcerr;
    extern std::wostream wclog;

}  // namespace GP

#endif  // IOSTREAM_HPP
