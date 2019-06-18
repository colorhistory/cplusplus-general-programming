#ifndef PRINTCOLL_HPP
#define PRINTCOLL_HPP

#include "bits/stdc++.h"

namespace GP {

    template <typename T>
    void printColl(const T &coll) {
        using const_iterator = typename T::const_iterator;
        const_iterator iter, end(coll.end());

        for (iter = coll.begin(); iter != end; ++iter) {
            std::cout << *iter << " ";
        }

        std::cout << std::endl;
    }

}  // namespace GP

#endif  // PRINTCOLL_HPP
