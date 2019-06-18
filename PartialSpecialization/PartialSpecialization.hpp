#ifndef PARTIALSPECIALIZATION_HPP
#define PARTIALSPECIALIZATION_HPP

#include "Stack.hpp"

namespace GP {

    template <typename T>
    class Stack<T*> {
      public:
        void push(T*);
        T* pop();
        T* top() const;
        bool empty() const;

      private:
        std::vector<T*> elems;
    };

    template <typename T>
    void Stack<T*>::push(T* elem) {
        elems.push_back(elem);
    }

    template <typename T>
    T* Stack<T*>::pop() {
        assert(!elems.empty());
        T* p = elems.back();
        elems.pop_back();
        return p;
    }

    template <typename T>
    T* Stack<T*>::top() const {
        assert(!elems.empty());
        return elems.back();
    }

    template <typename T>
    bool Stack<T*>::empty() const {
        assert(!elems.empty());
        return elems.back();
    }

}  // namespace GP

#endif  // PARTIALSPECIALIZATION_HPP
