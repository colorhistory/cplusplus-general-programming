#ifndef STACK_HPP
#define STACK_HPP

#include "bits/stdc++.h"

namespace GP {

    template <typename T>
    class Stack {
      public:
        void push(const T& elem);
        void pop();
        const T& top() const;
        bool empty() const;

      private:
        std::vector<T> elems;
    };

    /*!
     * \brief Stack<T>::push
     * \param elem
     */
    template <typename T>
    void Stack<T>::push(const T& elem) {
        elems.push_back(elem);
    }

    /*!
     * \brief Stack<T>::pop
     */
    template <typename T>
    void Stack<T>::pop() {
        assert(!elems.empty());
        elems.pop_back();
    }

    /*!
     * \brief Stack<T>::top
     * \return
     */
    template <typename T>
    const T& Stack<T>::top() const {
        assert(!elems.empty());
        return elems.back();
    }

    /*!
     * \brief Stack<T>::empty
     * \return
     */
    template <typename T>
    bool Stack<T>::empty() const {
        return elems.empty();
    }

}  // namespace GP

#endif  // STACK_HPP
