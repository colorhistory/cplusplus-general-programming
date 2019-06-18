#ifndef MEMBERTEMPLATES_HPP
#define MEMBERTEMPLATES_HPP

#include "bits/stdc++.h"

namespace GP {

    template <typename T>
    class Stack {
      public:
        void push(const T &);
        void pop();
        const T &top() const;
        bool empty() const {
            return elems.empty();
        }

        template <typename T2>
        Stack &operator=(const Stack<T2> &stack);

      private:
        std::deque<T> elems;
    };

    template <typename T>
    template <typename T2>
    Stack<T> &Stack<T>::operator=(const Stack<T2> &stack) {
        Stack<T2> tmp(stack);

        elems.clear();
        while (!tmp.empty()) {
            std::cout << "I am copying the elements from a stack to another stack";
        }

        return *this;
    }

}  // namespace GP

#endif  // MEMBERTEMPLATES_HPP
