#ifndef VARIADICBASECLASS_HPP
#define VARIADICBASECLASS_HPP

#include "bits/stdc++.h"

namespace GP {

    class Customer {
      public:
        Customer(const std::string &n) : name{n} {
        }
        std::string getName() const {
            return name;
        }

      private:
        std::string name;
    };

    struct CustomerEq {
        bool operator()(const Customer &c1, const Customer &c2) const {
            return c1.getName() == c2.getName();
        }
    };

    struct CustomerHash {
        std::size_t operator()(Customer const &c) const {
            return std::hash<std::string>()(c.getName());
        }
    };

    template <typename... Bases>
    struct Overloader : Bases... {
        using Bases::operator()...;
    };

}  // namespace GP
#endif  // VARIADICBASECLASS_HPP
