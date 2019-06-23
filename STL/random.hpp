﻿#ifndef RANDOM_HPP
#define RANDOM_HPP

#include "bits/stdc++.h"

namespace GP {

    // Engines

    template <class UIntType, UIntType a, UIntType c, UIntType m>
    class linear_congruential_engine {
      public:
        // types
        typedef UIntType result_type;

        // engine characteristics
        static constexpr result_type multiplier = a;
        static constexpr result_type increment = c;
        static constexpr result_type modulus = m;
        static constexpr result_type min() {
            return c == 0u ? 1u : 0u;
        }
        static constexpr result_type max() {
            return m - 1u;
        }
        static constexpr result_type default_seed = 1u;

        // constructors and seeding functions
        explicit linear_congruential_engine(result_type s = default_seed);
        template <class Sseq>
        explicit linear_congruential_engine(Sseq& q);
        void seed(result_type s = default_seed);
        template <class Sseq>
        void seed(Sseq& q);

        // generating functions
        result_type operator()();
        void discard(unsigned long long z);
    };

    template <class UIntType, UIntType a, UIntType c, UIntType m>
    bool operator==(const linear_congruential_engine<UIntType, a, c, m>& x,
                    const linear_congruential_engine<UIntType, a, c, m>& y);

    template <class UIntType, UIntType a, UIntType c, UIntType m>
    bool operator!=(const linear_congruential_engine<UIntType, a, c, m>& x,
                    const linear_congruential_engine<UIntType, a, c, m>& y);

    template <class charT, class traits, class UIntType, UIntType a, UIntType c, UIntType m>
    std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                  const linear_congruential_engine<UIntType, a, c, m>& x);

    template <class charT, class traits, class UIntType, UIntType a, UIntType c, UIntType m>
    std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                  linear_congruential_engine<UIntType, a, c, m>& x);

    template <class UIntType, size_t w, size_t n, size_t m, size_t r, UIntType a, size_t u, UIntType d, size_t s,
              UIntType b, size_t t, UIntType c, size_t l, UIntType f>
    class mersenne_twister_engine {
      public:
        // types
        typedef UIntType result_type;

        // engine characteristics
        static constexpr size_t word_size = w;
        static constexpr size_t state_size = n;
        static constexpr size_t shift_size = m;
        static constexpr size_t mask_bits = r;
        static constexpr result_type xor_mask = a;
        static constexpr size_t tempering_u = u;
        static constexpr result_type tempering_d = d;
        static constexpr size_t tempering_s = s;
        static constexpr result_type tempering_b = b;
        static constexpr size_t tempering_t = t;
        static constexpr result_type tempering_c = c;
        static constexpr size_t tempering_l = l;
        static constexpr result_type initialization_multiplier = f;
        static constexpr result_type min() {
            return 0;
        }
        static constexpr result_type max() {
            return 2 ^ w - 1;
        }
        static constexpr result_type default_seed = 5489u;

        // constructors and seeding functions
        explicit mersenne_twister_engine(result_type value = default_seed);
        template <class Sseq>
        explicit mersenne_twister_engine(Sseq& q);
        void seed(result_type value = default_seed);
        template <class Sseq>
        void seed(Sseq& q);

        // generating functions
        result_type operator()();
        void discard(unsigned long long z);
    };

    template <class UIntType, size_t w, size_t n, size_t m, size_t r, UIntType a, size_t u, UIntType d, size_t s,
              UIntType b, size_t t, UIntType c, size_t l, UIntType f>
    bool operator==(const mersenne_twister_engine<UIntType, w, n, m, r, a, u, d, s, b, t, c, l, f>& x,
                    const mersenne_twister_engine<UIntType, w, n, m, r, a, u, d, s, b, t, c, l, f>& y);

    template <class UIntType, size_t w, size_t n, size_t m, size_t r, UIntType a, size_t u, UIntType d, size_t s,
              UIntType b, size_t t, UIntType c, size_t l, UIntType f>
    bool operator!=(const mersenne_twister_engine<UIntType, w, n, m, r, a, u, d, s, b, t, c, l, f>& x,
                    const mersenne_twister_engine<UIntType, w, n, m, r, a, u, d, s, b, t, c, l, f>& y);

    template <class charT, class traits, class UIntType, size_t w, size_t n, size_t m, size_t r, UIntType a, size_t u,
              UIntType d, size_t s, UIntType b, size_t t, UIntType c, size_t l, UIntType f>
    std::basic_ostream<charT, traits>& operator<<(
        std::basic_ostream<charT, traits>& os,
        const mersenne_twister_engine<UIntType, w, n, m, r, a, u, d, s, b, t, c, l, f>& x);

    template <class charT, class traits, class UIntType, size_t w, size_t n, size_t m, size_t r, UIntType a, size_t u,
              UIntType d, size_t s, UIntType b, size_t t, UIntType c, size_t l, UIntType f>
    std::basic_istream<charT, traits>& operator>>(
        std::basic_istream<charT, traits>& is,
        mersenne_twister_engine<UIntType, w, n, m, r, a, u, d, s, b, t, c, l, f>& x);

    template <class UIntType, size_t w, size_t s, size_t r>
    class subtract_with_carry_engine {
      public:
        // types
        typedef UIntType result_type;

        // engine characteristics
        static constexpr size_t word_size = w;
        static constexpr size_t short_lag = s;
        static constexpr size_t long_lag = r;
        static constexpr result_type min() {
            return 0;
        }
        static constexpr result_type max() {
            return w - 1;
        }
        static constexpr result_type default_seed = 19780503u;

        // constructors and seeding functions
        explicit subtract_with_carry_engine(result_type value = default_seed);
        template <class Sseq>
        explicit subtract_with_carry_engine(Sseq& q);
        void seed(result_type value = default_seed);
        template <class Sseq>
        void seed(Sseq& q);

        // generating functions
        result_type operator()();
        void discard(unsigned long long z);
    };

    template <class UIntType, size_t w, size_t s, size_t r>
    bool operator==(const subtract_with_carry_engine<UIntType, w, s, r>& x,
                    const subtract_with_carry_engine<UIntType, w, s, r>& y);

    template <class UIntType, size_t w, size_t s, size_t r>
    bool operator!=(const subtract_with_carry_engine<UIntType, w, s, r>& x,
                    const subtract_with_carry_engine<UIntType, w, s, r>& y);

    template <class charT, class traits, class UIntType, size_t w, size_t s, size_t r>
    std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                  const subtract_with_carry_engine<UIntType, w, s, r>& x);

    template <class charT, class traits, class UIntType, size_t w, size_t s, size_t r>
    std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                  subtract_with_carry_engine<UIntType, w, s, r>& x);

    template <class Engine, size_t p, size_t r>
    class discard_block_engine {
      public:
        // types
        typedef typename Engine::result_type result_type;

        // engine characteristics
        static constexpr size_t block_size = p;
        static constexpr size_t used_block = r;
        static constexpr result_type min() {
            return Engine::min();
        }
        static constexpr result_type max() {
            return Engine::max();
        }

        // constructors and seeding functions
        discard_block_engine();
        explicit discard_block_engine(const Engine& e);
        explicit discard_block_engine(Engine&& e);
        explicit discard_block_engine(result_type s);
        template <class Sseq>
        explicit discard_block_engine(Sseq& q);
        void seed();
        void seed(result_type s);
        template <class Sseq>
        void seed(Sseq& q);

        // generating functions
        result_type operator()();
        void discard(unsigned long long z);

        // property functions
        const Engine& base() const noexcept;
    };

    template <class Engine, size_t p, size_t r>
    bool operator==(const discard_block_engine<Engine, p, r>& x, const discard_block_engine<Engine, p, r>& y);

    template <class Engine, size_t p, size_t r>
    bool operator!=(const discard_block_engine<Engine, p, r>& x, const discard_block_engine<Engine, p, r>& y);

    template <class charT, class traits, class Engine, size_t p, size_t r>
    std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                  const discard_block_engine<Engine, p, r>& x);

    template <class charT, class traits, class Engine, size_t p, size_t r>
    std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                  discard_block_engine<Engine, p, r>& x);

    template <class Engine, size_t w, class UIntType>
    class independent_bits_engine {
      public:
        // types
        typedef UIntType result_type;

        // engine characteristics
        static constexpr result_type min() {
            return 0;
        }
        static constexpr result_type max() {
            return 2 ^ w - 1;
        }

        // constructors and seeding functions
        independent_bits_engine();
        explicit independent_bits_engine(const Engine& e);
        explicit independent_bits_engine(Engine&& e);
        explicit independent_bits_engine(result_type s);
        template <class Sseq>
        explicit independent_bits_engine(Sseq& q);
        void seed();
        void seed(result_type s);
        template <class Sseq>
        void seed(Sseq& q);

        // generating functions
        result_type operator()();
        void discard(unsigned long long z);

        // property functions
        const Engine& base() const noexcept;
    };

    template <class Engine, size_t w, class UIntType>
    bool operator==(const independent_bits_engine<Engine, w, UIntType>& x,
                    const independent_bits_engine<Engine, w, UIntType>& y);

    template <class Engine, size_t w, class UIntType>
    bool operator!=(const independent_bits_engine<Engine, w, UIntType>& x,
                    const independent_bits_engine<Engine, w, UIntType>& y);

    template <class charT, class traits, class Engine, size_t w, class UIntType>
    std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                  const independent_bits_engine<Engine, w, UIntType>& x);

    template <class charT, class traits, class Engine, size_t w, class UIntType>
    std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                  independent_bits_engine<Engine, w, UIntType>& x);

    template <class Engine, size_t k>
    class shuffle_order_engine {
      public:
        // types
        typedef typename Engine::result_type result_type;

        // engine characteristics
        static constexpr size_t table_size = k;
        static constexpr result_type min() {
            return Engine::min;
        }
        static constexpr result_type max() {
            return Engine::max;
        }

        // constructors and seeding functions
        shuffle_order_engine();
        explicit shuffle_order_engine(const Engine& e);
        explicit shuffle_order_engine(Engine&& e);
        explicit shuffle_order_engine(result_type s);
        template <class Sseq>
        explicit shuffle_order_engine(Sseq& q);
        void seed();
        void seed(result_type s);
        template <class Sseq>
        void seed(Sseq& q);

        // generating functions
        result_type operator()();
        void discard(unsigned long long z);

        // property functions
        const Engine& base() const noexcept;
    };

    template <class Engine, size_t k>
    bool operator==(const shuffle_order_engine<Engine, k>& x, const shuffle_order_engine<Engine, k>& y);

    template <class Engine, size_t k>
    bool operator!=(const shuffle_order_engine<Engine, k>& x, const shuffle_order_engine<Engine, k>& y);

    template <class charT, class traits, class Engine, size_t k>
    std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                  const shuffle_order_engine<Engine, k>& x);

    template <class charT, class traits, class Engine, size_t k>
    std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                  shuffle_order_engine<Engine, k>& x);

    typedef linear_congruential_engine<uint_fast32_t, 16807, 0, 2147483647> minstd_rand0;
    typedef linear_congruential_engine<uint_fast32_t, 48271, 0, 2147483647> minstd_rand;
    typedef mersenne_twister_engine<uint_fast32_t, 32, 624, 397, 31, 0x9908b0df, 11, 0xffffffff, 7, 0x9d2c5680, 15,
                                    0xefc60000, 18, 1812433253>
        mt19937;
    typedef mersenne_twister_engine<uint_fast64_t, 64, 312, 156, 31, 0xb5026f5aa96619e9, 29, 0x5555555555555555, 17,
                                    0x71d67fffeda60000, 37, 0xfff7eee000000000, 43, 6364136223846793005>
        mt19937_64;
    typedef subtract_with_carry_engine<uint_fast32_t, 24, 10, 24> ranlux24_base;
    typedef subtract_with_carry_engine<uint_fast64_t, 48, 5, 12> ranlux48_base;
    typedef discard_block_engine<ranlux24_base, 223, 23> ranlux24;
    typedef discard_block_engine<ranlux48_base, 389, 11> ranlux48;
    typedef shuffle_order_engine<minstd_rand0, 256> knuth_b;
    typedef minstd_rand default_random_engine;

    // Generators

    class random_device {
      public:
        // types
        typedef unsigned int result_type;

        // generator characteristics
        static constexpr result_type min() {
            return std::numeric_limits<result_type>::min();
        }
        static constexpr result_type max() {
            return std::numeric_limits<result_type>::max();
        }

        // constructors
        explicit random_device(const std::string& token = "/dev/urandom");

        // generating functions
        result_type operator()();

        // property functions
        double entropy() const noexcept;

        // no copy functions
        random_device(const random_device&) = delete;
        void operator=(const random_device&) = delete;
    };

    // Utilities

    class seed_seq {
      public:
        // types
        typedef uint_least32_t result_type;

        // constructors
        seed_seq();
        template <class T>
        seed_seq(std::initializer_list<T> il);
        template <class InputIterator>
        seed_seq(InputIterator begin, InputIterator end);

        // generating functions
        template <class RandomAccessIterator>
        void generate(RandomAccessIterator begin, RandomAccessIterator end);

        // property functions
        size_t size() const;
        template <class OutputIterator>
        void param(OutputIterator dest) const;

        // no copy functions
        seed_seq(const seed_seq&) = delete;
        void operator=(const seed_seq&) = delete;
    };

    template <class RealType, size_t bits, class URNG>
    RealType generate_canonical(URNG& g);

    // Distributions

    template <class IntType = int>
    class uniform_int_distribution {
      public:
        // types
        typedef IntType result_type;

        class param_type {
          public:
            typedef uniform_int_distribution distribution_type;

            explicit param_type(IntType a = 0, IntType b = std::numeric_limits<IntType>::max());

            result_type a() const;
            result_type b() const;

            friend bool operator==(const param_type& x, const param_type& y);
            friend bool operator!=(const param_type& x, const param_type& y);
        };

        // constructors and reset functions
        explicit uniform_int_distribution(IntType a = 0, IntType b = std::numeric_limits<IntType>::max());
        explicit uniform_int_distribution(const param_type& parm);
        void reset();

        // generating functions
        template <class URNG>
        result_type operator()(URNG& g);
        template <class URNG>
        result_type operator()(URNG& g, const param_type& parm);

        // property functions
        result_type a() const;
        result_type b() const;

        param_type param() const;
        void param(const param_type& parm);

        result_type min() const;
        result_type max() const;

        friend bool operator==(const uniform_int_distribution& x, const uniform_int_distribution& y);
        friend bool operator!=(const uniform_int_distribution& x, const uniform_int_distribution& y);

        template <class charT, class traits>
        friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                             const uniform_int_distribution& x);

        template <class charT, class traits>
        friend std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                             uniform_int_distribution& x);
    };

    template <class RealType = double>
    class uniform_real_distribution {
      public:
        // types
        typedef RealType result_type;

        class param_type {
          public:
            typedef uniform_real_distribution distribution_type;

            explicit param_type(RealType a = 0, RealType b = 1);

            result_type a() const;
            result_type b() const;

            friend bool operator==(const param_type& x, const param_type& y);
            friend bool operator!=(const param_type& x, const param_type& y);
        };

        // constructors and reset functions
        explicit uniform_real_distribution(RealType a = 0.0, RealType b = 1.0);
        explicit uniform_real_distribution(const param_type& parm);
        void reset();

        // generating functions
        template <class URNG>
        result_type operator()(URNG& g);
        template <class URNG>
        result_type operator()(URNG& g, const param_type& parm);

        // property functions
        result_type a() const;
        result_type b() const;

        param_type param() const;
        void param(const param_type& parm);

        result_type min() const;
        result_type max() const;

        friend bool operator==(const uniform_real_distribution& x, const uniform_real_distribution& y);
        friend bool operator!=(const uniform_real_distribution& x, const uniform_real_distribution& y);

        template <class charT, class traits>
        friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                             const uniform_real_distribution& x);

        template <class charT, class traits>
        friend std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                             uniform_real_distribution& x);
    };

    class bernoulli_distribution {
      public:
        // types
        typedef bool result_type;

        class param_type {
          public:
            typedef bernoulli_distribution distribution_type;

            explicit param_type(double p = 0.5);

            double p() const;

            friend bool operator==(const param_type& x, const param_type& y);
            friend bool operator!=(const param_type& x, const param_type& y);
        };

        // constructors and reset functions
        explicit bernoulli_distribution(double p = 0.5);
        explicit bernoulli_distribution(const param_type& parm);
        void reset();

        // generating functions
        template <class URNG>
        result_type operator()(URNG& g);
        template <class URNG>
        result_type operator()(URNG& g, const param_type& parm);

        // property functions
        double p() const;

        param_type param() const;
        void param(const param_type& parm);

        result_type min() const;
        result_type max() const;

        friend bool operator==(const bernoulli_distribution& x, const bernoulli_distribution& y);
        friend bool operator!=(const bernoulli_distribution& x, const bernoulli_distribution& y);

        template <class charT, class traits>
        friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                             const bernoulli_distribution& x);

        template <class charT, class traits>
        friend std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                             bernoulli_distribution& x);
    };

    template <class IntType = int>
    class binomial_distribution {
      public:
        // types
        typedef IntType result_type;

        class param_type {
          public:
            typedef binomial_distribution distribution_type;

            explicit param_type(IntType t = 1, double p = 0.5);

            IntType t() const;
            double p() const;

            friend bool operator==(const param_type& x, const param_type& y);
            friend bool operator!=(const param_type& x, const param_type& y);
        };

        // constructors and reset functions
        explicit binomial_distribution(IntType t = 1, double p = 0.5);
        explicit binomial_distribution(const param_type& parm);
        void reset();

        // generating functions
        template <class URNG>
        result_type operator()(URNG& g);
        template <class URNG>
        result_type operator()(URNG& g, const param_type& parm);

        // property functions
        IntType t() const;
        double p() const;

        param_type param() const;
        void param(const param_type& parm);

        result_type min() const;
        result_type max() const;

        friend bool operator==(const binomial_distribution& x, const binomial_distribution& y);
        friend bool operator!=(const binomial_distribution& x, const binomial_distribution& y);

        template <class charT, class traits>
        friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                             const binomial_distribution& x);

        template <class charT, class traits>
        friend std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                             binomial_distribution& x);
    };

    template <class IntType = int>
    class geometric_distribution {
      public:
        // types
        typedef IntType result_type;

        class param_type {
          public:
            typedef geometric_distribution distribution_type;

            explicit param_type(double p = 0.5);

            double p() const;

            friend bool operator==(const param_type& x, const param_type& y);
            friend bool operator!=(const param_type& x, const param_type& y);
        };

        // constructors and reset functions
        explicit geometric_distribution(double p = 0.5);
        explicit geometric_distribution(const param_type& parm);
        void reset();

        // generating functions
        template <class URNG>
        result_type operator()(URNG& g);
        template <class URNG>
        result_type operator()(URNG& g, const param_type& parm);

        // property functions
        double p() const;

        param_type param() const;
        void param(const param_type& parm);

        result_type min() const;
        result_type max() const;

        friend bool operator==(const geometric_distribution& x, const geometric_distribution& y);
        friend bool operator!=(const geometric_distribution& x, const geometric_distribution& y);

        template <class charT, class traits>
        friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                             const geometric_distribution& x);

        template <class charT, class traits>
        friend std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                             geometric_distribution& x);
    };

    template <class IntType = int>
    class negative_binomial_distribution {
      public:
        // types
        typedef IntType result_type;

        class param_type {
          public:
            typedef negative_binomial_distribution distribution_type;

            explicit param_type(result_type k = 1, double p = 0.5);

            result_type k() const;
            double p() const;

            friend bool operator==(const param_type& x, const param_type& y);
            friend bool operator!=(const param_type& x, const param_type& y);
        };

        // constructor and reset functions
        explicit negative_binomial_distribution(result_type k = 1, double p = 0.5);
        explicit negative_binomial_distribution(const param_type& parm);
        void reset();

        // generating functions
        template <class URNG>
        result_type operator()(URNG& g);
        template <class URNG>
        result_type operator()(URNG& g, const param_type& parm);

        // property functions
        result_type k() const;
        double p() const;

        param_type param() const;
        void param(const param_type& parm);

        result_type min() const;
        result_type max() const;

        friend bool operator==(const negative_binomial_distribution& x, const negative_binomial_distribution& y);
        friend bool operator!=(const negative_binomial_distribution& x, const negative_binomial_distribution& y);

        template <class charT, class traits>
        friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                             const negative_binomial_distribution& x);

        template <class charT, class traits>
        friend std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                             negative_binomial_distribution& x);
    };

    template <class IntType = int>
    class poisson_distribution {
      public:
        // types
        typedef IntType result_type;

        class param_type {
          public:
            typedef poisson_distribution distribution_type;

            explicit param_type(double mean = 1.0);

            double mean() const;

            friend bool operator==(const param_type& x, const param_type& y);
            friend bool operator!=(const param_type& x, const param_type& y);
        };

        // constructors and reset functions
        explicit poisson_distribution(double mean = 1.0);
        explicit poisson_distribution(const param_type& parm);
        void reset();

        // generating functions
        template <class URNG>
        result_type operator()(URNG& g);
        template <class URNG>
        result_type operator()(URNG& g, const param_type& parm);

        // property functions
        double mean() const;

        param_type param() const;
        void param(const param_type& parm);

        result_type min() const;
        result_type max() const;

        friend bool operator==(const poisson_distribution& x, const poisson_distribution& y);
        friend bool operator!=(const poisson_distribution& x, const poisson_distribution& y);

        template <class charT, class traits>
        friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                             const poisson_distribution& x);

        template <class charT, class traits>
        friend std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                             poisson_distribution& x);
    };

    template <class RealType = double>
    class exponential_distribution {
      public:
        // types
        typedef RealType result_type;

        class param_type {
          public:
            typedef exponential_distribution distribution_type;

            explicit param_type(result_type lambda = 1.0);

            result_type lambda() const;

            friend bool operator==(const param_type& x, const param_type& y);
            friend bool operator!=(const param_type& x, const param_type& y);
        };

        // constructors and reset functions
        explicit exponential_distribution(result_type lambda = 1.0);
        explicit exponential_distribution(const param_type& parm);
        void reset();

        // generating functions
        template <class URNG>
        result_type operator()(URNG& g);
        template <class URNG>
        result_type operator()(URNG& g, const param_type& parm);

        // property functions
        result_type lambda() const;

        param_type param() const;
        void param(const param_type& parm);

        result_type min() const;
        result_type max() const;

        friend bool operator==(const exponential_distribution& x, const exponential_distribution& y);
        friend bool operator!=(const exponential_distribution& x, const exponential_distribution& y);

        template <class charT, class traits>
        friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                             const exponential_distribution& x);

        template <class charT, class traits>
        friend std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                             exponential_distribution& x);
    };

    template <class RealType = double>
    class gamma_distribution {
      public:
        // types
        typedef RealType result_type;

        class param_type {
          public:
            typedef gamma_distribution distribution_type;

            explicit param_type(result_type alpha = 1, result_type beta = 1);

            result_type alpha() const;
            result_type beta() const;

            friend bool operator==(const param_type& x, const param_type& y);
            friend bool operator!=(const param_type& x, const param_type& y);
        };

        // constructors and reset functions
        explicit gamma_distribution(result_type alpha = 1, result_type beta = 1);
        explicit gamma_distribution(const param_type& parm);
        void reset();

        // generating functions
        template <class URNG>
        result_type operator()(URNG& g);
        template <class URNG>
        result_type operator()(URNG& g, const param_type& parm);

        // property functions
        result_type alpha() const;
        result_type beta() const;

        param_type param() const;
        void param(const param_type& parm);

        result_type min() const;
        result_type max() const;

        friend bool operator==(const gamma_distribution& x, const gamma_distribution& y);
        friend bool operator!=(const gamma_distribution& x, const gamma_distribution& y);

        template <class charT, class traits>
        friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                             const gamma_distribution& x);

        template <class charT, class traits>
        friend std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                             gamma_distribution& x);
    };

    template <class RealType = double>
    class weibull_distribution {
      public:
        // types
        typedef RealType result_type;

        class param_type {
          public:
            typedef weibull_distribution distribution_type;

            explicit param_type(result_type alpha = 1, result_type beta = 1);

            result_type a() const;
            result_type b() const;

            friend bool operator==(const param_type& x, const param_type& y);
            friend bool operator!=(const param_type& x, const param_type& y);
        };

        // constructor and reset functions
        explicit weibull_distribution(result_type a = 1, result_type b = 1);
        explicit weibull_distribution(const param_type& parm);
        void reset();

        // generating functions
        template <class URNG>
        result_type operator()(URNG& g);
        template <class URNG>
        result_type operator()(URNG& g, const param_type& parm);

        // property functions
        result_type a() const;
        result_type b() const;

        param_type param() const;
        void param(const param_type& parm);

        result_type min() const;
        result_type max() const;

        friend bool operator==(const weibull_distribution& x, const weibull_distribution& y);
        friend bool operator!=(const weibull_distribution& x, const weibull_distribution& y);

        template <class charT, class traits>
        friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                             const weibull_distribution& x);

        template <class charT, class traits>
        friend std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                             weibull_distribution& x);
    };

    template <class RealType = double>
    class extreme_value_distribution {
      public:
        // types
        typedef RealType result_type;

        class param_type {
          public:
            typedef extreme_value_distribution distribution_type;

            explicit param_type(result_type a = 0, result_type b = 1);

            result_type a() const;
            result_type b() const;

            friend bool operator==(const param_type& x, const param_type& y);
            friend bool operator!=(const param_type& x, const param_type& y);
        };

        // constructor and reset functions
        explicit extreme_value_distribution(result_type a = 0, result_type b = 1);
        explicit extreme_value_distribution(const param_type& parm);
        void reset();

        // generating functions
        template <class URNG>
        result_type operator()(URNG& g);
        template <class URNG>
        result_type operator()(URNG& g, const param_type& parm);

        // property functions
        result_type a() const;
        result_type b() const;

        param_type param() const;
        void param(const param_type& parm);

        result_type min() const;
        result_type max() const;

        friend bool operator==(const extreme_value_distribution& x, const extreme_value_distribution& y);
        friend bool operator!=(const extreme_value_distribution& x, const extreme_value_distribution& y);

        template <class charT, class traits>
        friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                             const extreme_value_distribution& x);

        template <class charT, class traits>
        friend std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                             extreme_value_distribution& x);
    };

    template <class RealType = double>
    class normal_distribution {
      public:
        // types
        typedef RealType result_type;

        class param_type {
          public:
            typedef normal_distribution distribution_type;

            explicit param_type(result_type mean = 0, result_type stddev = 1);

            result_type mean() const;
            result_type stddev() const;

            friend bool operator==(const param_type& x, const param_type& y);
            friend bool operator!=(const param_type& x, const param_type& y);
        };

        // constructors and reset functions
        explicit normal_distribution(result_type mean = 0, result_type stddev = 1);
        explicit normal_distribution(const param_type& parm);
        void reset();

        // generating functions
        template <class URNG>
        result_type operator()(URNG& g);
        template <class URNG>
        result_type operator()(URNG& g, const param_type& parm);

        // property functions
        result_type mean() const;
        result_type stddev() const;

        param_type param() const;
        void param(const param_type& parm);

        result_type min() const;
        result_type max() const;

        friend bool operator==(const normal_distribution& x, const normal_distribution& y);
        friend bool operator!=(const normal_distribution& x, const normal_distribution& y);

        template <class charT, class traits>
        friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                             const normal_distribution& x);

        template <class charT, class traits>
        friend std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                             normal_distribution& x);
    };

    template <class RealType = double>
    class lognormal_distribution {
      public:
        // types
        typedef RealType result_type;

        class param_type {
          public:
            typedef lognormal_distribution distribution_type;

            explicit param_type(result_type m = 0, result_type s = 1);

            result_type m() const;
            result_type s() const;

            friend bool operator==(const param_type& x, const param_type& y);
            friend bool operator!=(const param_type& x, const param_type& y);
        };

        // constructor and reset functions
        explicit lognormal_distribution(result_type m = 0, result_type s = 1);
        explicit lognormal_distribution(const param_type& parm);
        void reset();

        // generating functions
        template <class URNG>
        result_type operator()(URNG& g);
        template <class URNG>
        result_type operator()(URNG& g, const param_type& parm);

        // property functions
        result_type m() const;
        result_type s() const;

        param_type param() const;
        void param(const param_type& parm);

        result_type min() const;
        result_type max() const;

        friend bool operator==(const lognormal_distribution& x, const lognormal_distribution& y);
        friend bool operator!=(const lognormal_distribution& x, const lognormal_distribution& y);

        template <class charT, class traits>
        friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                             const lognormal_distribution& x);

        template <class charT, class traits>
        friend std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                             lognormal_distribution& x);
    };

    template <class RealType = double>
    class chi_squared_distribution {
      public:
        // types
        typedef RealType result_type;

        class param_type {
          public:
            typedef chi_squared_distribution distribution_type;

            explicit param_type(result_type n = 1);

            result_type n() const;

            friend bool operator==(const param_type& x, const param_type& y);
            friend bool operator!=(const param_type& x, const param_type& y);
        };

        // constructor and reset functions
        explicit chi_squared_distribution(result_type n = 1);
        explicit chi_squared_distribution(const param_type& parm);
        void reset();

        // generating functions
        template <class URNG>
        result_type operator()(URNG& g);
        template <class URNG>
        result_type operator()(URNG& g, const param_type& parm);

        // property functions
        result_type n() const;

        param_type param() const;
        void param(const param_type& parm);

        result_type min() const;
        result_type max() const;

        friend bool operator==(const chi_squared_distribution& x, const chi_squared_distribution& y);
        friend bool operator!=(const chi_squared_distribution& x, const chi_squared_distribution& y);

        template <class charT, class traits>
        friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                             const chi_squared_distribution& x);

        template <class charT, class traits>
        friend std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                             chi_squared_distribution& x);
    };

    template <class RealType = double>
    class cauchy_distribution {
      public:
        // types
        typedef RealType result_type;

        class param_type {
          public:
            typedef cauchy_distribution distribution_type;

            explicit param_type(result_type a = 0, result_type b = 1);

            result_type a() const;
            result_type b() const;

            friend bool operator==(const param_type& x, const param_type& y);
            friend bool operator!=(const param_type& x, const param_type& y);
        };

        // constructor and reset functions
        explicit cauchy_distribution(result_type a = 0, result_type b = 1);
        explicit cauchy_distribution(const param_type& parm);
        void reset();

        // generating functions
        template <class URNG>
        result_type operator()(URNG& g);
        template <class URNG>
        result_type operator()(URNG& g, const param_type& parm);

        // property functions
        result_type a() const;
        result_type b() const;

        param_type param() const;
        void param(const param_type& parm);

        result_type min() const;
        result_type max() const;

        friend bool operator==(const cauchy_distribution& x, const cauchy_distribution& y);
        friend bool operator!=(const cauchy_distribution& x, const cauchy_distribution& y);

        template <class charT, class traits>
        friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                             const cauchy_distribution& x);

        template <class charT, class traits>
        friend std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                             cauchy_distribution& x);
    };

    template <class RealType = double>
    class fisher_f_distribution {
      public:
        // types
        typedef RealType result_type;

        class param_type {
          public:
            typedef fisher_f_distribution distribution_type;

            explicit param_type(result_type m = 1, result_type n = 1);

            result_type m() const;
            result_type n() const;

            friend bool operator==(const param_type& x, const param_type& y);
            friend bool operator!=(const param_type& x, const param_type& y);
        };

        // constructor and reset functions
        explicit fisher_f_distribution(result_type m = 1, result_type n = 1);
        explicit fisher_f_distribution(const param_type& parm);
        void reset();

        // generating functions
        template <class URNG>
        result_type operator()(URNG& g);
        template <class URNG>
        result_type operator()(URNG& g, const param_type& parm);

        // property functions
        result_type m() const;
        result_type n() const;

        param_type param() const;
        void param(const param_type& parm);

        result_type min() const;
        result_type max() const;

        friend bool operator==(const fisher_f_distribution& x, const fisher_f_distribution& y);
        friend bool operator!=(const fisher_f_distribution& x, const fisher_f_distribution& y);

        template <class charT, class traits>
        friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                             const fisher_f_distribution& x);

        template <class charT, class traits>
        friend std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                             fisher_f_distribution& x);
    };

    template <class RealType = double>
    class student_t_distribution {
      public:
        // types
        typedef RealType result_type;

        class param_type {
          public:
            typedef student_t_distribution distribution_type;

            explicit param_type(result_type n = 1);

            result_type n() const;

            friend bool operator==(const param_type& x, const param_type& y);
            friend bool operator!=(const param_type& x, const param_type& y);
        };

        // constructor and reset functions
        explicit student_t_distribution(result_type n = 1);
        explicit student_t_distribution(const param_type& parm);
        void reset();

        // generating functions
        template <class URNG>
        result_type operator()(URNG& g);
        template <class URNG>
        result_type operator()(URNG& g, const param_type& parm);

        // property functions
        result_type n() const;

        param_type param() const;
        void param(const param_type& parm);

        result_type min() const;
        result_type max() const;

        friend bool operator==(const student_t_distribution& x, const student_t_distribution& y);
        friend bool operator!=(const student_t_distribution& x, const student_t_distribution& y);

        template <class charT, class traits>
        friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                             const student_t_distribution& x);

        template <class charT, class traits>
        friend std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                             student_t_distribution& x);
    };

    template <class IntType = int>
    class discrete_distribution {
      public:
        // types
        typedef IntType result_type;

        class param_type {
          public:
            typedef discrete_distribution distribution_type;

            param_type();
            template <class InputIterator>
            param_type(InputIterator firstW, InputIterator lastW);
            param_type(std::initializer_list<double> wl);
            template <class UnaryOperation>
            param_type(size_t nw, double xmin, double xmax, UnaryOperation fw);

            std::vector<double> probabilities() const;

            friend bool operator==(const param_type& x, const param_type& y);
            friend bool operator!=(const param_type& x, const param_type& y);
        };

        // constructor and reset functions
        discrete_distribution();
        template <class InputIterator>
        discrete_distribution(InputIterator firstW, InputIterator lastW);
        discrete_distribution(std::initializer_list<double> wl);
        template <class UnaryOperation>
        discrete_distribution(size_t nw, double xmin, double xmax, UnaryOperation fw);
        explicit discrete_distribution(const param_type& parm);
        void reset();

        // generating functions
        template <class URNG>
        result_type operator()(URNG& g);
        template <class URNG>
        result_type operator()(URNG& g, const param_type& parm);

        // property functions
        std::vector<double> probabilities() const;

        param_type param() const;
        void param(const param_type& parm);

        result_type min() const;
        result_type max() const;

        friend bool operator==(const discrete_distribution& x, const discrete_distribution& y);
        friend bool operator!=(const discrete_distribution& x, const discrete_distribution& y);

        template <class charT, class traits>
        friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                             const discrete_distribution& x);

        template <class charT, class traits>
        friend std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                             discrete_distribution& x);
    };

    template <class RealType = double>
    class piecewise_constant_distribution {
        // types
        typedef RealType result_type;

        class param_type {
          public:
            typedef piecewise_constant_distribution distribution_type;

            param_type();
            template <class InputIteratorB, class InputIteratorW>
            param_type(InputIteratorB firstB, InputIteratorB lastB, InputIteratorW firstW);
            template <class UnaryOperation>
            param_type(std::initializer_list<result_type> bl, UnaryOperation fw);
            template <class UnaryOperation>
            param_type(size_t nw, result_type xmin, result_type xmax, UnaryOperation fw);

            std::vector<result_type> intervals() const;
            std::vector<result_type> densities() const;

            friend bool operator==(const param_type& x, const param_type& y);
            friend bool operator!=(const param_type& x, const param_type& y);
        };

        // constructor and reset functions
        piecewise_constant_distribution();
        template <class InputIteratorB, class InputIteratorW>
        piecewise_constant_distribution(InputIteratorB firstB, InputIteratorB lastB, InputIteratorW firstW);
        template <class UnaryOperation>
        piecewise_constant_distribution(std::initializer_list<result_type> bl, UnaryOperation fw);
        template <class UnaryOperation>
        piecewise_constant_distribution(size_t nw, result_type xmin, result_type xmax, UnaryOperation fw);
        explicit piecewise_constant_distribution(const param_type& parm);
        void reset();

        // generating functions
        template <class URNG>
        result_type operator()(URNG& g);
        template <class URNG>
        result_type operator()(URNG& g, const param_type& parm);

        // property functions
        std::vector<result_type> intervals() const;
        std::vector<result_type> densities() const;

        param_type param() const;
        void param(const param_type& parm);

        result_type min() const;
        result_type max() const;

        friend bool operator==(const piecewise_constant_distribution& x, const piecewise_constant_distribution& y);
        friend bool operator!=(const piecewise_constant_distribution& x, const piecewise_constant_distribution& y);

        template <class charT, class traits>
        friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                             const piecewise_constant_distribution& x);

        template <class charT, class traits>
        friend std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                             piecewise_constant_distribution& x);
    };

    template <class RealType = double>
    class piecewise_linear_distribution {
        // types
        typedef RealType result_type;

        class param_type {
          public:
            typedef piecewise_linear_distribution distribution_type;

            param_type();
            template <class InputIteratorB, class InputIteratorW>
            param_type(InputIteratorB firstB, InputIteratorB lastB, InputIteratorW firstW);
            template <class UnaryOperation>
            param_type(std::initializer_list<result_type> bl, UnaryOperation fw);
            template <class UnaryOperation>
            param_type(size_t nw, result_type xmin, result_type xmax, UnaryOperation fw);

            std::vector<result_type> intervals() const;
            std::vector<result_type> densities() const;

            friend bool operator==(const param_type& x, const param_type& y);
            friend bool operator!=(const param_type& x, const param_type& y);
        };

        // constructor and reset functions
        piecewise_linear_distribution();
        template <class InputIteratorB, class InputIteratorW>
        piecewise_linear_distribution(InputIteratorB firstB, InputIteratorB lastB, InputIteratorW firstW);

        template <class UnaryOperation>
        piecewise_linear_distribution(std::initializer_list<result_type> bl, UnaryOperation fw);

        template <class UnaryOperation>
        piecewise_linear_distribution(size_t nw, result_type xmin, result_type xmax, UnaryOperation fw);

        explicit piecewise_linear_distribution(const param_type& parm);
        void reset();

        // generating functions
        template <class URNG>
        result_type operator()(URNG& g);
        template <class URNG>
        result_type operator()(URNG& g, const param_type& parm);

        // property functions
        std::vector<result_type> intervals() const;
        std::vector<result_type> densities() const;

        param_type param() const;
        void param(const param_type& parm);

        result_type min() const;
        result_type max() const;

        friend bool operator==(const piecewise_linear_distribution& x, const piecewise_linear_distribution& y);
        friend bool operator!=(const piecewise_linear_distribution& x, const piecewise_linear_distribution& y);

        template <class charT, class traits>
        friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os,
                                                             const piecewise_linear_distribution& x);

        template <class charT, class traits>
        friend std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits>& is,
                                                             piecewise_linear_distribution& x);
    };

}  // namespace GP

#endif  // RANDOM_HPP
