#ifndef TEMPLATETEMPLATEPARAMETERS_HPP
#define TEMPLATETEMPLATEPARAMETERS_HPP

#include "bits/stdc++.h"

template <typename T, template <typename Elem, typename Alloc = std::allocator<Elem>> class Cont = std::deque>
class Stack {
    // friend
    template <typename, template <typename, typename> class>
    friend class Stack;

  public:
    void push(const T &elem);
    void pop();
    const T &top() const;
    bool empty() const;

    template <typename T2, template <typename Elem2, typename Alloc2 = std::allocator<Elem2>> class Cont2 = std::deque>
    Stack<T, Cont> &operator=(const Stack<T2, Cont2> &stack);

  private:
    Cont<T> elems;
};

template <typename T, template <typename, typename> class Cont>
void Stack<T, Cont>::push(const T &elem) {
    elems.push_back(elem);
}

template <typename T, template <typename, typename> class Cont>
void Stack<T, Cont>::pop() {
    assert(!elems.empty());
    elems.pop_back();
}

template <typename T, template <typename, typename> class Cont>
const T &Stack<T, Cont>::top() const {
    assert(!elems.empty());
    return elems.back();
}

template <typename T, template <typename, typename> class Cont>
bool Stack<T, Cont>::empty() const {
    return elems.empty();
}

template <typename T, template <typename, typename> class Cont>
template <typename T2, template <typename, typename> class Cont2>
Stack<T, Cont> &Stack<T, Cont>::operator=(const Stack<T2, Cont2> &stack) {
    elems.clear();
    elems.insert(elems.begin(), stack.elems.begin(), stack.elems.end());
    return *this;
}

#endif  // TEMPLATETEMPLATEPARAMETERS_HPP
