#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

#include "bits/stdc++.h"

namespace GP {

    template <typename T>
    using EnableIfString = typename std::enable_if<std::is_convertible<T, std::string>::value>::type;

    class Person {
      public:
        template <typename STR, typename = EnableIfString<STR>>
        explicit Person(STR &&n) : name(std::forward<STR>(n)) {
            std::cout << "TMPL-CONSTR for " << name << std::endl;
        }

        Person(Person const &p) : name(p.name) {
            std::cout << "COPY-CONSTR Person " << name << std::endl;
        }

        Person(Person &&p) : name(std::move(p.name)) {
            std::cout << "MOVE-CONSTR Person " << name << std::endl;
        }

      private:
        std::string name;
    };

}  // namespace GP
#endif  // ENABLE_IF_HPP
