#ifndef ANY_HPP
#define ANY_HPP

#include "bits/stdc++.h"

namespace GP {

    class bad_any_cast : public std::bad_cast {
      public:
        virtual const char* what() const noexcept;
    };

    class any {
      public:
        // 6.3.1 any construct/destruct
        any() noexcept;

        any(const any& other);
        any(any&& other) noexcept;

        template <class ValueType>
        any(ValueType&& value);

        ~any();

        // 6.3.2 any assignments
        any& operator=(const any& rhs);
        any& operator=(any&& rhs) noexcept;

        template <class ValueType>
        any& operator=(ValueType&& rhs);

        // 6.3.3 any modifiers
        template <class ValueType, class... Args>
        std::decay_t<ValueType>& emplace(Args&&... args);
        template <class ValueType, class U, class... Args>
        std::decay_t<ValueType>& emplace(std::initializer_list<U>, Args&&...);
        void reset() noexcept;
        void swap(any& rhs) noexcept;

        // 6.3.4 any observers
        bool has_value() const noexcept;
        const std::type_info& type() const noexcept;
    };

    // 6.4 Non-member functions
    void swap(any& x, any& y) noexcept;

    template <class T, class... Args>
    any make_any(Args&&... args);
    template <class T, class U, class... Args>
    any make_any(std::initializer_list<U>, Args&&... args);

    template <class ValueType>
    ValueType any_cast(const any& operand);
    template <class ValueType>
    ValueType any_cast(any& operand);
    template <class ValueType>
    ValueType any_cast(any&& operand);

    template <class ValueType>
    const ValueType* any_cast(const any* operand) noexcept;
    template <class ValueType>
    ValueType* any_cast(any* operand) noexcept;

}  // namespace GP

#endif  // ANY_HPP
