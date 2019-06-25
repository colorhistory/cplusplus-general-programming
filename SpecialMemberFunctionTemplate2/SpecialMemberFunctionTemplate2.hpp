#ifndef SPECIALMEMBERFUNCTIONTEMPLATE2_HPP
#define SPECIALMEMBERFUNCTIONTEMPLATE2_HPP

#include "bits/stdc++.h"

class Person {
  public:
    template <typename STR>
    explicit Person(STR &&n) : name(std::forward<STR>(n)) {
        std::cout << "TMPL-CONSTR for " << name << std::endl;
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

#endif  // SPECIALMEMBERFUNCTIONTEMPLATE2_HPP
