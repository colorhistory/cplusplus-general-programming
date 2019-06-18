#ifndef NONTYPECLASSTEMPLATE_HPP
#define NONTYPECLASSTEMPLATE_HPP

#include "bits/stdc++.h"

namespace GP {

    template <typename T, std::size_t MaxSize>
    class Stack {
      public:
        Stack();

        // ADT
        void push(const T& elem);
        void pop();

        const T& top() const;

        bool empty() const;
        std::size_t size() const;

      private:
        std::array<T, MaxSize> elems;
        std::size_t numElems;
    };

    /*!
     * \brief Stack<T, MaxSize>::Stack
     */
    template <typename T, std::size_t MaxSize>
    Stack<T, MaxSize>::Stack() : numElems{0} {
    }

    /*!
     * \brief Stack<T, MaxSize>::push
     * \param elem
     */
    template <typename T, std::size_t MaxSize>
    void Stack<T, MaxSize>::push(const T& elem) {
        assert(numElems < MaxSize);
        elems[numElems] = elem;
        ++numElems;
    }

    /*!
     * \brief Stack<T, MaxSize>::pop
     */
    template <typename T, std::size_t MaxSize>
    void Stack<T, MaxSize>::pop() {
        assert(!elems.empty());
        --numElems;
    }

    /*!
     * \brief Stack<T, MaxSize>::top
     * \return
     */
    template <typename T, std::size_t MaxSize>
    const T& Stack<T, MaxSize>::top() const {
        assert(!elems.empty());
        return elems[numElems - 1];
    }

    /*!
     * \brief Stack<T, MaxSize>::empty
     * \return
     */
    template <typename T, std::size_t MaxSize>
    bool Stack<T, MaxSize>::empty() const {
        return numElems == 0;
    }

    /*!
     * \brief Stack<T, MaxSize>::size
     * \return
     */
    template <typename T, std::size_t MaxSize>
    std::size_t Stack<T, MaxSize>::size() const {
        return numElems;
    }

}  // namespace GP

#endif  // NONTYPECLASSTEMPLATE_HPP
