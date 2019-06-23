#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include "bits/stdc++.h"

namespace GP {

    template <class T>
    class complex {
      public:
        typedef T value_type;

        complex(const T& re = T(), const T& im = T());  // constexpr in C++14
        complex(const complex&);                        // constexpr in C++14
        template <class X>
        complex(const complex<X>&);  // constexpr in C++14

        T real() const;  // constexpr in C++14
        T imag() const;  // constexpr in C++14

        void real(T);
        void imag(T);

        complex<T>& operator=(const T&);
        complex<T>& operator+=(const T&);
        complex<T>& operator-=(const T&);
        complex<T>& operator*=(const T&);
        complex<T>& operator/=(const T&);

        complex& operator=(const complex&);
        template <class X>
        complex<T>& operator=(const complex<X>&);
        template <class X>
        complex<T>& operator+=(const complex<X>&);
        template <class X>
        complex<T>& operator-=(const complex<X>&);
        template <class X>
        complex<T>& operator*=(const complex<X>&);
        template <class X>
        complex<T>& operator/=(const complex<X>&);
    };

    template <>
    class complex<float> {
      public:
        typedef float value_type;

        constexpr complex(float re = 0.0f, float im = 0.0f);
        explicit constexpr complex(const complex<double>&);
        explicit constexpr complex(const complex<long double>&);

        constexpr float real() const;
        void real(float);
        constexpr float imag() const;
        void imag(float);

        complex<float>& operator=(float);
        complex<float>& operator+=(float);
        complex<float>& operator-=(float);
        complex<float>& operator*=(float);
        complex<float>& operator/=(float);

        complex<float>& operator=(const complex<float>&);
        template <class X>
        complex<float>& operator=(const complex<X>&);
        template <class X>
        complex<float>& operator+=(const complex<X>&);
        template <class X>
        complex<float>& operator-=(const complex<X>&);
        template <class X>
        complex<float>& operator*=(const complex<X>&);
        template <class X>
        complex<float>& operator/=(const complex<X>&);
    };

    template <>
    class complex<double> {
      public:
        typedef double value_type;

        constexpr complex(double re = 0.0, double im = 0.0);
        constexpr complex(const complex<float>&);
        explicit constexpr complex(const complex<long double>&);

        constexpr double real() const;
        void real(double);
        constexpr double imag() const;
        void imag(double);

        complex<double>& operator=(double);
        complex<double>& operator+=(double);
        complex<double>& operator-=(double);
        complex<double>& operator*=(double);
        complex<double>& operator/=(double);
        complex<double>& operator=(const complex<double>&);

        template <class X>
        complex<double>& operator=(const complex<X>&);
        template <class X>
        complex<double>& operator+=(const complex<X>&);
        template <class X>
        complex<double>& operator-=(const complex<X>&);
        template <class X>
        complex<double>& operator*=(const complex<X>&);
        template <class X>
        complex<double>& operator/=(const complex<X>&);
    };

    template <>
    class complex<long double> {
      public:
        typedef long double value_type;

        constexpr complex(long double re = 0.0L, long double im = 0.0L);
        constexpr complex(const complex<float>&);
        constexpr complex(const complex<double>&);

        constexpr long double real() const;
        void real(long double);
        constexpr long double imag() const;
        void imag(long double);

        complex<long double>& operator=(const complex<long double>&);
        complex<long double>& operator=(long double);
        complex<long double>& operator+=(long double);
        complex<long double>& operator-=(long double);
        complex<long double>& operator*=(long double);
        complex<long double>& operator/=(long double);

        template <class X>
        complex<long double>& operator=(const complex<X>&);
        template <class X>
        complex<long double>& operator+=(const complex<X>&);
        template <class X>
        complex<long double>& operator-=(const complex<X>&);
        template <class X>
        complex<long double>& operator*=(const complex<X>&);
        template <class X>
        complex<long double>& operator/=(const complex<X>&);
    };

    // 26.3.6 operators:
    template <class T>
    complex<T> operator+(const complex<T>&, const complex<T>&);
    template <class T>
    complex<T> operator+(const complex<T>&, const T&);
    template <class T>
    complex<T> operator+(const T&, const complex<T>&);
    template <class T>
    complex<T> operator-(const complex<T>&, const complex<T>&);
    template <class T>
    complex<T> operator-(const complex<T>&, const T&);
    template <class T>
    complex<T> operator-(const T&, const complex<T>&);
    template <class T>
    complex<T> operator*(const complex<T>&, const complex<T>&);
    template <class T>
    complex<T> operator*(const complex<T>&, const T&);
    template <class T>
    complex<T> operator*(const T&, const complex<T>&);
    template <class T>
    complex<T> operator/(const complex<T>&, const complex<T>&);
    template <class T>
    complex<T> operator/(const complex<T>&, const T&);
    template <class T>
    complex<T> operator/(const T&, const complex<T>&);
    template <class T>
    complex<T> operator+(const complex<T>&);
    template <class T>
    complex<T> operator-(const complex<T>&);
    template <class T>
    bool operator==(const complex<T>&, const complex<T>&);  // constexpr in C++14
    template <class T>
    bool operator==(const complex<T>&, const T&);  // constexpr in C++14
    template <class T>
    bool operator==(const T&, const complex<T>&);  // constexpr in C++14
    template <class T>
    bool operator!=(const complex<T>&, const complex<T>&);  // constexpr in C++14
    template <class T>
    bool operator!=(const complex<T>&, const T&);  // constexpr in C++14
    template <class T>
    bool operator!=(const T&, const complex<T>&);  // constexpr in C++14

    template <class T, class charT, class traits>
    std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>&, complex<T>&);
    template <class T, class charT, class traits>
    std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>&, const complex<T>&);

    // 26.3.7 values:

    template <class T>
    T real(const complex<T>&);      // constexpr in C++14
    long double real(long double);  // constexpr in C++14
    double real(double);            // constexpr in C++14
    template <Integral T>
    double real(T);     // constexpr in C++14
    float real(float);  // constexpr in C++14

    template <class T>
    T imag(const complex<T>&);      // constexpr in C++14
    long double imag(long double);  // constexpr in C++14
    double imag(double);            // constexpr in C++14
    template <Integral T>
    double imag(T);     // constexpr in C++14
    float imag(float);  // constexpr in C++14

    template <class T>
    T abs(const complex<T>&);

    template <class T>
    T arg(const complex<T>&);
    long double arg(long double);
    double arg(double);
    template <Integral T>
    double arg(T);
    float arg(float);

    template <class T>
    T norm(const complex<T>&);
    long double norm(long double);
    double norm(double);
    template <Integral T>
    double norm(T);
    float norm(float);

    template <class T>
    complex<T> conj(const complex<T>&);
    complex<long double> conj(long double);
    complex<double> conj(double);
    template <Integral T>
    complex<double> conj(T);
    complex<float> conj(float);

    template <class T>
    complex<T> proj(const complex<T>&);
    complex<long double> proj(long double);
    complex<double> proj(double);
    template <Integral T>
    complex<double> proj(T);
    complex<float> proj(float);

    template <class T>
    complex<T> polar(const T&, const T& = T());

    // 26.3.8 transcendentals:
    template <class T>
    complex<T> acos(const complex<T>&);
    template <class T>
    complex<T> asin(const complex<T>&);
    template <class T>
    complex<T> atan(const complex<T>&);
    template <class T>
    complex<T> acosh(const complex<T>&);
    template <class T>
    complex<T> asinh(const complex<T>&);
    template <class T>
    complex<T> atanh(const complex<T>&);
    template <class T>
    complex<T> cos(const complex<T>&);
    template <class T>
    complex<T> cosh(const complex<T>&);
    template <class T>
    complex<T> exp(const complex<T>&);
    template <class T>
    complex<T> log(const complex<T>&);
    template <class T>
    complex<T> log10(const complex<T>&);

    template <class T>
    complex<T> pow(const complex<T>&, const T&);
    template <class T>
    complex<T> pow(const complex<T>&, const complex<T>&);
    template <class T>
    complex<T> pow(const T&, const complex<T>&);

    template <class T>
    complex<T> sin(const complex<T>&);
    template <class T>
    complex<T> sinh(const complex<T>&);
    template <class T>
    complex<T> sqrt(const complex<T>&);
    template <class T>
    complex<T> tan(const complex<T>&);
    template <class T>
    complex<T> tanh(const complex<T>&);

    template <class T, class charT, class traits>
    basic_istream<charT, traits>& operator>>(basic_istream<charT, traits>& is, complex<T>& x);

    template <class T, class charT, class traits>
    basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>& o, const complex<T>& x);

}  // namespace GP

#endif  // COMPLEX_HPP
