#ifndef FRIENDOFTEMPLATE_HPP
#define FRIENDOFTEMPLATE_HPP

#include "bits/stdc++.h"

namespace GP {

    template <typename>
    class Stack;
    template <typename T>
    std::ostream& operator<<(std::ostream&, Stack<T> const&);

    template <typename T>
    class Stack {
        friend std::ostream& operator<<<T>(std::ostream&, const Stack<T>&);

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

    /*!
     * \brief operator <<
     * \param out
     * \param stack
     * \return
     */
    template <typename T>
    std::ostream& operator<<(std::ostream& out, Stack<T> const& stack) {
        for (std::size_t i = 0; i != stack.elems.size(); ++i) {
            out << stack.elems[i] << "   ";
        }
        return out;
    }

}  // namespace GP

#endif  // FRIENDOFTEMPLATE_HPP
