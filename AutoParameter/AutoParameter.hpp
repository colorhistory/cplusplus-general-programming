#ifndef AUTOPARAMETER_HPP
#define AUTOPARAMETER_HPP

#include "bits/stdc++.h"

namespace GP {

    template <typename T, auto MaxSize>
    class Stack {
      public:
        using size_type = decltype(MaxSize);

        Stack();
        void push(const T& elem);
        void pop();
        const T& top() const;
        bool empty() const;
        size_type size() const;

      private:
        std::array<T, MaxSize> elems;
        size_type numElems;
    };

    /*!
     * \brief Stack<T, MaxSize>::Stack
     */
    template <typename T, auto MaxSize>
    Stack<T, MaxSize>::Stack() : numElems{0} {
    }

    /*!
     * \brief Stack<T, MaxSize>::push
     * \param elem
     */
    template <typename T, auto MaxSize>
    void Stack<T, MaxSize>::push(const T& elem) {
        assert(numElems < MaxSize);
        elems[numElems] = elem;
        ++numElems;
    }

    /*!
     * \brief Stack<T, MaxSize>::pop
     */
    template <typename T, auto MaxSize>
    void Stack<T, MaxSize>::pop() {
        assert(!elems.empty());
        --numElems;
    }

    /*!
     * \brief Stack<T, MaxSize>::top
     * \return
     */
    template <typename T, auto MaxSize>
    const T& Stack<T, MaxSize>::top() const {
        assert(!elems.empty());
        return elems[numElems - 1];
    }

    /*!
     * \brief Stack<T, MaxSize>::empty
     * \return
     */
    template <typename T, auto MaxSize>
    bool Stack<T, MaxSize>::empty() const {
        return numElems == 0;
    }

    /*!
     * \brief Stack<T, MaxSize>::size
     * \return
     */
    template <typename T, auto MaxSize>
    typename Stack<T, MaxSize>::size_type Stack<T, MaxSize>::size() const {
        return numElems;
    }

}  // namespace GP

#endif  // AUTOPARAMETER_HPP
