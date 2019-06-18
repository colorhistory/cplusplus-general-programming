#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include "bits/stdc++.h"

namespace GP {

    template <auto T>
    class Message {
      public:
        void print();
    };

    /*!
     * \brief Message<T>::print
     */
    template <auto T>
    void Message<T>::print() {
        std::cout << T << std::endl;
    }

}  // namespace GP

#endif  // MESSAGE_HPP
