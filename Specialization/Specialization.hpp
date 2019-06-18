#ifndef SPECIALIZATION_HPP
#define SPECIALIZATION_HPP

#include "Stack.hpp"

namespace GP {

    template <>
    class Stack<std::string> {
      public:
        void push(const std::string &str);
        void pop();
        const std::string &top() const;
        bool empty() const;

      private:
        std::deque<std::string> elems;
    };

    void Stack<std::string>::push(const std::string &str) {
        elems.push_back(str);
        std::cout << "specialization..." << std::endl;
    }

    void Stack<std::string>::pop() {
        assert(!elems.empty());
        elems.pop_back();
        std::cout << "specialization..." << std::endl;
    }

    const std::string &Stack<std::string>::top() const {
        assert(!elems.empty());
        std::cout << "specialization..." << std::endl;
        return elems.back();
    }

    bool Stack<std::string>::empty() const {
        std::cout << "specialization..." << std::endl;
        return elems.empty();
    }

}  // namespace GP

#endif  // SPECIALIZATION_HPP
