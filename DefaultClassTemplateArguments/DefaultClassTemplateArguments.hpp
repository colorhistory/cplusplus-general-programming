#ifndef DEFAULTCLASSTEMPLATEARGUMENTS_HPP
#define DEFAULTCLASSTEMPLATEARGUMENTS_HPP

#include "bits/stdc++.h"

namespace GP {
    template <typename T, typename Cont = std::vector<T>>
    class Stack {
      public:
        void push(const T& elem);
        void pop();
        const T& top() const;
        bool empty() const;

      private:
        Cont elems;
    };

    /*!
     * \brief Stack<T, Cont>::push
     * \param elem
     */
    template <typename T, typename Cont>
    inline void Stack<T, Cont>::push(const T& elem) {
        elems.push_back(elem);
    }

    /*!
     * \brief Stack<T, Cont>::pop
     */
    template <typename T, typename Cont>
    inline void Stack<T, Cont>::pop() {
        assert(!elems.empty());
        elems.pop_back();
    }

    /*!
     * \brief Stack<T, Cont>::top
     * \return
     */
    template <typename T, typename Cont>
    inline const T& Stack<T, Cont>::top() const {
        assert(!elems.empty());
        return elems.back();
    }

    /*!
     * \brief Stack<T, Cont>::empty
     * \return
     */
    template <typename T, typename Cont>
    inline bool Stack<T, Cont>::empty() const {
        return elems.empty();
    }

}  // namespace GP

#endif  // DEFAULTCLASSTEMPLATEARGUMENTS_HPP
