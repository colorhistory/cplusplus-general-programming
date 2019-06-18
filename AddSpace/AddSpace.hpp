#ifndef ADDSPACE_HPP
#define ADDSPACE_HPP

#include "bits/stdc++.h"

namespace GP {
    template <typename T>
    class AddSpace {
      public:
        AddSpace(const T &r) : ref(r) {
        }

        friend std::ostream &operator<<(std::ostream &os, GP::AddSpace<T> s);

      private:
        const T &ref;
    };

    template <typename T>
    std::ostream &operator<<(std::ostream &os, AddSpace<T> s) {
        os << s.ref << " ";
        return os;
    }

    template <typename... Args>
    void print(Args... args) {
        (std::cout << ... << GP::AddSpace(args)) << std::endl;
    }

}  // namespace GP

#endif  // ADDSPACE_HPP
