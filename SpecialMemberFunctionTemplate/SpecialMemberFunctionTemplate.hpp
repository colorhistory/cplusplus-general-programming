#ifndef SPECIALMEMBERFUNCTIONTEMPLATE_HPP
#define SPECIALMEMBERFUNCTIONTEMPLATE_HPP

#include "bits/stdc++.h"

namespace GP {

    class Person {
      public:
        explicit Person(const std::string &n) : name(n) {
            std::cout << "copying string-CONSTR for " << name << std::endl;
        }

        explicit Person(std::string &&n) : name(std::move(n)) {
            std::cout << "moving string-CONSTR for " << name << std::endl;
        }

        Person(const Person &p) : name(p.name) {
            std::cout << "COPY-CONSTR Person " << name << std::endl;
        }

        Person(Person &&p) : name(std::move(p.name)) {
            std::cout << "MOVE-CONSTR Person " << name << std::endl;
        }

      private:
        std::string name;
    };

}  // namespace GP

#endif  // SPECIALMEMBERFUNCTIONTEMPLATE_HPP
