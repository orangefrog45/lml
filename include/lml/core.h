#pragma once

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
#elif defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable: 4505) // 4505: unreferenced function with internal linkage
#pragma warning(disable: 4068) // 4068: unknown pragma
#endif

#include <stdint.h>
#include <math.h>

#ifdef __host__
#define LML_QUALIFIER __host__ __device__
#else
#define LML_QUALIFIER
#endif

#define LML_INLINE inline

namespace lml {
    template<typename T, typename U>
    struct is_same {
        static constexpr bool value = false;
    };

    template<typename T>
    struct is_same<T, T> {
        static constexpr bool value = true;
    };

    template<typename T, typename U>
    constexpr bool is_same_v = is_same<T, U>::value;

    template<typename T>
    struct is_floating_point {
        static constexpr bool value = false;
    };

    template<>
    struct is_floating_point<float> {
        static constexpr bool value = true;
    };

    template<>
    struct is_floating_point<double> {
        static constexpr bool value = true;
    };

    template<typename T>
    constexpr bool is_floating_point_v = is_floating_point<T>::value;

    template<typename T>
    struct is_integral {
        static constexpr bool value = false;
    };

    template<>
    struct is_integral<int> {
        static constexpr bool value = true;
    };

    template<>
    struct is_integral<bool> {
        static constexpr bool value = true;
    };

    template<>
    struct is_integral<uint32_t> {
        static constexpr bool value = true;
    };

    template<typename T>
    constexpr bool is_integral_v = is_integral<T>::value;

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T pi() {
        return static_cast<T>(3.141592653589793238462643383279502);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T add(T a, T b) {
        return a + b;
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T subtract(T a, T b) {
        return a - b;
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T multiply(T a, T b) {
        return a * b;
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T multiplyAdd(T a, T b, T c) {
        return a * b + c;
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T multiplyMultiply(T a, T b, T c) {
        return c * a * b;
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T divide(T a, T b) {
        return a / b;
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T sin(T a) {
        return ::sin(a);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T cos(T a) {
        return ::cos(a);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T tan(T a) {
        return ::tan(a);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T asin(T a) {
        return ::asin(a);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T acos(T a) {
        return ::acos(a);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T atan(T a) {
        return ::atan(a);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T atan2(T y, T x) {
        return ::atan2(y, x);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T radians(T degrees) {
        return degrees * static_cast<T>(0.01745329251994329576923690768489);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T degrees(T radians) {
        return radians * static_cast<T>(57.295779513082320876798154814105);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T pow(T x, T y) {
        return ::pow(x, y);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T exp(T a) {
        return ::exp(a);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T log(T a) {
        return ::log(a);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T log2(T a) {
        return ::log2(a);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T sqrt(T a) {
        return ::sqrt(a);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T inversesqrt(T a) {
        return static_cast<T>(1) / sqrt(a);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T mod(T x, T y) {
        return x - y * floor(x / y);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T step(T edge, T x) {
        return x < edge ? static_cast<T>(0) : static_cast<T>(1);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T round(T a) {
        return ::round(a);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T floor(T a) {
        return ::floor(a);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T ceil(T a) {
        return ::ceil(a);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T fract(T a) {
        return a - floor(a);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T abs(T a) {
        if constexpr (is_floating_point_v<T>) {
            return ::fabs(a);
        } else {
            return a < 0 ? -a : a;
        }
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T sign(T a) {
        return a < static_cast<T>(0) ? static_cast<T>(-1) : (a > static_cast<T>(0) ? static_cast<T>(1) : static_cast<T>(0));
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T min(T a, T b) {
        return a < b ? a : b;
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T max(T a, T b) {
        return a > b ? a : b;
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T clamp(T a, T b, T c) {
        return min(max(a, b), c);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T mix(T x, T y, T a) {
        return x * (static_cast<T>(1) - a) + y * a;
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T smoothstep(T edge0, T edge1, T x) {
        T t = clamp((x - edge0) / (edge1 - edge0), static_cast<T>(0), static_cast<T>(1));
        return t * t * (static_cast<T>(3) - static_cast<T>(2) * t);
    }

    template<typename T, int N>
    struct VecBase {
        T data[N];
    };

    template<typename T>
    struct VecBase<T, 1> {
        union {
            T data[1];
            struct { T x; };
            struct { T r; };
            struct { T s; };
        };
    };

    template<typename T>
    struct VecBase<T, 2> {
        union {
            T data[2];
            struct { T x, y; };
            struct { T r, g; };
            struct { T s, t; };
        };
    };

    template<typename T>
    struct VecBase<T, 3> {
        union {
            T data[3];
            struct { T x, y, z; };
            struct { T r, g, b; };
            struct { T s, t, p; };
        };
    };

    template<typename T>
    struct VecBase<T, 4> {
        union {
            T data[4];
            struct { T x, y, z, w; };
            struct { T r, g, b, a; };
            struct { T s, t, p, q; };
        };
    };

    template<typename T, int N>
    struct Vec : public VecBase<T, N> {
        static_assert(is_same_v<T, float>
            || is_same_v<T, double>
            || is_same_v<T, int32_t>
            || is_same_v<T, uint32_t>
            || is_same_v<T, bool>,
            "Vec only supports float, double, int, uint32_t, and bool");

        using VecBase<T, N>::data;

        LML_QUALIFIER Vec() {
            for (int i = 0; i < N; ++i) data[i] = static_cast<T>(0);
        }
        LML_QUALIFIER explicit Vec(T scalar) {
            for (int i = 0; i < N; ++i) data[i] = scalar;
        }
        LML_QUALIFIER Vec(T x, T y) {
            if constexpr (N >= 1) data[0] = x;
            if constexpr (N >= 2) data[1] = y;
            for (int i = 2; i < N; ++i) data[i] = static_cast<T>(0);
        }
        LML_QUALIFIER Vec(T x, T y, T z) {
            if constexpr (N >= 1) data[0] = x;
            if constexpr (N >= 2) data[1] = y;
            if constexpr (N >= 3) data[2] = z;
            for (int i = 3; i < N; ++i) data[i] = static_cast<T>(0);
        }
        LML_QUALIFIER Vec(T x, T y, T z, T w) {
            if constexpr (N >= 1) data[0] = x;
            if constexpr (N >= 2) data[1] = y;
            if constexpr (N >= 3) data[2] = z;
            if constexpr (N >= 4) data[3] = w;
            for (int i = 4; i < N; ++i) data[i] = static_cast<T>(0);
        }

        LML_QUALIFIER T& operator[](int i) { return data[i]; }
        LML_QUALIFIER const T& operator[](int i) const { return data[i]; }

        LML_QUALIFIER Vec& operator+=(const Vec& other) { for (int i = 0; i < N; ++i) data[i] += other.data[i]; return *this; }
        LML_QUALIFIER Vec& operator-=(const Vec& other) { for (int i = 0; i < N; ++i) data[i] -= other.data[i]; return *this; }
        LML_QUALIFIER Vec& operator*=(const Vec& other) { for (int i = 0; i < N; ++i) data[i] *= other.data[i]; return *this; }
        LML_QUALIFIER Vec& operator/=(const Vec& other) { for (int i = 0; i < N; ++i) data[i] /= other.data[i]; return *this; }

        LML_QUALIFIER Vec& operator+=(T scalar) { for (int i = 0; i < N; ++i) data[i] += scalar; return *this; }
        LML_QUALIFIER Vec& operator-=(T scalar) { for (int i = 0; i < N; ++i) data[i] -= scalar; return *this; }
        LML_QUALIFIER Vec& operator*=(T scalar) { for (int i = 0; i < N; ++i) data[i] *= scalar; return *this; }
        LML_QUALIFIER Vec& operator/=(T scalar) { for (int i = 0; i < N; ++i) data[i] /= scalar; return *this; }

        LML_QUALIFIER Vec operator-() const { Vec res; for (int i = 0; i < N; ++i) res.data[i] = -data[i]; return res; }

        // Bitwise operators
        LML_QUALIFIER Vec& operator&=(const Vec& other) { static_assert(is_integral_v<T>, "Bitwise operators only support integral types"); for (int i = 0; i < N; ++i) data[i] &= other.data[i]; return *this; }
        LML_QUALIFIER Vec& operator|=(const Vec& other) { static_assert(is_integral_v<T>, "Bitwise operators only support integral types"); for (int i = 0; i < N; ++i) data[i] |= other.data[i]; return *this; }
        LML_QUALIFIER Vec& operator^=(const Vec& other) { static_assert(is_integral_v<T>, "Bitwise operators only support integral types"); for (int i = 0; i < N; ++i) data[i] ^= other.data[i]; return *this; }
        LML_QUALIFIER Vec& operator<<=(const Vec& other) { static_assert(is_integral_v<T>, "Bitwise operators only support integral types"); for (int i = 0; i < N; ++i) data[i] <<= other.data[i]; return *this; }
        LML_QUALIFIER Vec& operator>>=(const Vec& other) { static_assert(is_integral_v<T>, "Bitwise operators only support integral types"); for (int i = 0; i < N; ++i) data[i] >>= other.data[i]; return *this; }

        LML_QUALIFIER Vec& operator&=(T scalar) { static_assert(is_integral_v<T>, "Bitwise operators only support integral types"); for (int i = 0; i < N; ++i) data[i] &= scalar; return *this; }
        LML_QUALIFIER Vec& operator|=(T scalar) { static_assert(is_integral_v<T>, "Bitwise operators only support integral types"); for (int i = 0; i < N; ++i) data[i] |= scalar; return *this; }
        LML_QUALIFIER Vec& operator^=(T scalar) { static_assert(is_integral_v<T>, "Bitwise operators only support integral types"); for (int i = 0; i < N; ++i) data[i] ^= scalar; return *this; }
        LML_QUALIFIER Vec& operator<<=(T scalar) { static_assert(is_integral_v<T>, "Bitwise operators only support integral types"); for (int i = 0; i < N; ++i) data[i] <<= scalar; return *this; }
        LML_QUALIFIER Vec& operator>>=(T scalar) { static_assert(is_integral_v<T>, "Bitwise operators only support integral types"); for (int i = 0; i < N; ++i) data[i] >>= scalar; return *this; }

        LML_QUALIFIER Vec operator~() const { static_assert(is_integral_v<T>, "Bitwise operators only support integral types"); Vec res; for (int i = 0; i < N; ++i) res.data[i] = ~data[i]; return res; }
    };

    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator+(Vec<T, N> a, const Vec<T, N>& b) { return a + b; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator-(Vec<T, N> a, const Vec<T, N>& b) { return a - b; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator*(Vec<T, N> a, const Vec<T, N>& b) { return a * b; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator/(Vec<T, N> a, const Vec<T, N>& b) { return a / b; }

    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator+(Vec<T, N> a, T b) { return a + b; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator-(Vec<T, N> a, T b) { return a - b; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator*(Vec<T, N> a, T b) { return a * b; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator/(Vec<T, N> a, T b) { return a / b; }

    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator+(T a, Vec<T, N> b) { return b + a; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator-(T a, const Vec<T, N>& b) { Vec<T, N> res; for (int i = 0; i < N; ++i) res[i] = a - b[i]; return res; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator*(T a, Vec<T, N> b) { return b * a; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator/(T a, const Vec<T, N>& b) { Vec<T, N> res; for (int i = 0; i < N; ++i) res[i] = a / b[i]; return res; }

    // Bitwise binary operators
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator&(Vec<T, N> a, const Vec<T, N>& b) { return a & b; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator|(Vec<T, N> a, const Vec<T, N>& b) { return a | b; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator^(Vec<T, N> a, const Vec<T, N>& b) { return a ^ b; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator<<(Vec<T, N> a, const Vec<T, N>& b) { return a << b; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator>>(Vec<T, N> a, const Vec<T, N>& b) { return a >> b; }

    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator&(Vec<T, N> a, T b) { return a & b; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator|(Vec<T, N> a, T b) { return a | b; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator^(Vec<T, N> a, T b) { return a ^ b; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator<<(Vec<T, N> a, T b) { return a << b; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator>>(Vec<T, N> a, T b) { return a >> b; }

    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator&(T a, Vec<T, N> b) { return b & a; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator|(T a, Vec<T, N> b) { return b | a; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator^(T a, Vec<T, N> b) { return b ^ a; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator<<(T a, const Vec<T, N>& b) { Vec<T, N> res; if constexpr (is_same_v<T, int>) { for (int i = 0; i < N; ++i) res[i] = a << b[i]; } return res; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator>>(T a, const Vec<T, N>& b) { Vec<T, N> res; if constexpr (is_same_v<T, int>) { for (int i = 0; i < N; ++i) res[i] = a >> b[i]; } return res; }

    // Comparison operators
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<bool, N> operator==(const Vec<T, N>& a, const Vec<T, N>& b) { Vec<bool, N> res; for (int i = 0; i < N; ++i) res[i] = a[i] == b[i]; return res; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<bool, N> operator!=(const Vec<T, N>& a, const Vec<T, N>& b) { Vec<bool, N> res; for (int i = 0; i < N; ++i) res[i] = a[i] != b[i]; return res; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<bool, N> operator<(const Vec<T, N>& a, const Vec<T, N>& b)  { Vec<bool, N> res; for (int i = 0; i < N; ++i) res[i] = a[i] < b[i];  return res; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<bool, N> operator>(const Vec<T, N>& a, const Vec<T, N>& b)  { Vec<bool, N> res; for (int i = 0; i < N; ++i) res[i] = a[i] > b[i];  return res; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<bool, N> operator<=(const Vec<T, N>& a, const Vec<T, N>& b) { Vec<bool, N> res; for (int i = 0; i < N; ++i) res[i] = a[i] <= b[i]; return res; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<bool, N> operator>=(const Vec<T, N>& a, const Vec<T, N>& b) { Vec<bool, N> res; for (int i = 0; i < N; ++i) res[i] = a[i] >= b[i]; return res; }

    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<bool, N> operator==(const Vec<T, N>& a, T b) { Vec<bool, N> res; for (int i = 0; i < N; ++i) res[i] = a[i] == b; return res; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<bool, N> operator!=(const Vec<T, N>& a, T b) { Vec<bool, N> res; for (int i = 0; i < N; ++i) res[i] = a[i] != b; return res; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<bool, N> operator<(const Vec<T, N>& a, T b)  { Vec<bool, N> res; for (int i = 0; i < N; ++i) res[i] = a[i] < b;  return res; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<bool, N> operator>(const Vec<T, N>& a, T b)  { Vec<bool, N> res; for (int i = 0; i < N; ++i) res[i] = a[i] > b;  return res; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<bool, N> operator<=(const Vec<T, N>& a, T b) { Vec<bool, N> res; for (int i = 0; i < N; ++i) res[i] = a[i] <= b; return res; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<bool, N> operator>=(const Vec<T, N>& a, T b) { Vec<bool, N> res; for (int i = 0; i < N; ++i) res[i] = a[i] >= b; return res; }

    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<bool, N> operator==(T a, const Vec<T, N>& b) { Vec<bool, N> res; for (int i = 0; i < N; ++i) res[i] = a == b[i]; return res; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<bool, N> operator!=(T a, const Vec<T, N>& b) { Vec<bool, N> res; for (int i = 0; i < N; ++i) res[i] = a != b[i]; return res; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<bool, N> operator<(T a, const Vec<T, N>& b)  { Vec<bool, N> res; for (int i = 0; i < N; ++i) res[i] = a < b[i];  return res; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<bool, N> operator>(T a, const Vec<T, N>& b)  { Vec<bool, N> res; for (int i = 0; i < N; ++i) res[i] = a > b[i];  return res; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<bool, N> operator<=(T a, const Vec<T, N>& b) { Vec<bool, N> res; for (int i = 0; i < N; ++i) res[i] = a <= b[i]; return res; }
    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<bool, N> operator>=(T a, const Vec<T, N>& b) { Vec<bool, N> res; for (int i = 0; i < N; ++i) res[i] = a >= b[i]; return res; }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> sin(Vec<T, N> v) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = sin(v[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> cos(Vec<T, N> v) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = cos(v[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> tan(Vec<T, N> v) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = tan(v[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> asin(Vec<T, N> v) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = asin(v[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> acos(Vec<T, N> v) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = acos(v[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> atan(Vec<T, N> v) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = atan(v[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> atan2(Vec<T, N> y, Vec<T, N> x) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = atan2(y[i], x[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> pow(Vec<T, N> x, Vec<T, N> y) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = pow(x[i], y[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> exp(Vec<T, N> v) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = exp(v[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> log(Vec<T, N> v) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = log(v[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> log2(Vec<T, N> v) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = log2(v[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> sqrt(Vec<T, N> v) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = sqrt(v[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> inversesqrt(Vec<T, N> v) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = inversesqrt(v[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> mod(Vec<T, N> x, Vec<T, N> y) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = mod(x[i], y[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> mod(Vec<T, N> x, T y) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = mod(x[i], y);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> radians(Vec<T, N> v) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = radians(v[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> degrees(Vec<T, N> v) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = degrees(v[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> step(Vec<T, N> edge, Vec<T, N> x) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = step(edge[i], x[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> step(T edge, Vec<T, N> x) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = step(edge, x[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> round(Vec<T, N> v) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = round(v[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> floor(Vec<T, N> v) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = floor(v[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> ceil(Vec<T, N> v) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = ceil(v[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> fract(Vec<T, N> v) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = fract(v[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> abs(Vec<T, N> v) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = abs(v[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> sign(Vec<T, N> v) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = sign(v[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> min(Vec<T, N> a, Vec<T, N> b) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = min(a[i], b[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> max(Vec<T, N> a, Vec<T, N> b) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = max(a[i], b[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> clamp(Vec<T, N> x, Vec<T, N> min_val, Vec<T, N> max_val) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = clamp(x[i], min_val[i], max_val[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> mix(Vec<T, N> x, Vec<T, N> y, Vec<T, N> a) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = mix(x[i], y[i], a[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> smoothstep(Vec<T, N> edge0, Vec<T, N> edge1, Vec<T, N> x) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = smoothstep(edge0[i], edge1[i], x[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE T distance(Vec<T, N> p0, Vec<T, N> p1) {
        return length(p0 - p1);
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE T dot(Vec<T, N> a, Vec<T, N> b) {
        T res = 0;
        for (int i = 0; i < N; ++i) res += a[i] * b[i];
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE T length(Vec<T, N> v) {
        return sqrt(dot(v, v));
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> normalize(Vec<T, N> v) {
        return v / length(v);
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> reflect(Vec<T, N> i, Vec<T, N> n) {
        return i - static_cast<T>(2) * dot(n, i) * n;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> refract(Vec<T, N> i, Vec<T, N> n, T eta) {
        T dot_ni = dot(n, i);
        T k = static_cast<T>(1) - eta * eta * (static_cast<T>(1) - dot_ni * dot_ni);
        if (k < static_cast<T>(0)) return Vec<T, N>{};
        return eta * i - (eta * dot_ni + sqrt(k)) * n;
    }

    template<typename T>
    LML_QUALIFIER LML_INLINE Vec<T, 3> cross(Vec<T, 3> a, Vec<T, 3> b) {
        return Vec<T, 3>(
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x
        );
    }

    template<typename T, int N>
    struct Mat {
        Vec<T, N> columns[N];

        LML_QUALIFIER Mat() {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    columns[i][j] = static_cast<T>(0);
                }
            }
        }

        LML_QUALIFIER explicit Mat(T scalar) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    columns[i][j] = (i == j) ? scalar : static_cast<T>(0);
                }
            }
        }

        LML_QUALIFIER Mat(Vec<T, N> c0, Vec<T, N> c1) {
            columns[0] = c0;
            columns[1] = c1;
        }

        LML_QUALIFIER Mat(Vec<T, N> c0, Vec<T, N> c1, Vec<T, N> c2) {
            columns[0] = c0;
            columns[1] = c1;
            columns[2] = c2;
        }

        LML_QUALIFIER Mat(Vec<T, N> c0, Vec<T, N> c1, Vec<T, N> c2, Vec<T, N> c3) {
            columns[0] = c0;
            columns[1] = c1;
            columns[2] = c2;
            columns[3] = c3;
        }

        LML_QUALIFIER Mat(T m00, T m01, T m10, T m11) {
            static_assert(N == 2, "Matrix dimension must be 2");
            columns[0][0] = m00; columns[0][1] = m01;
            columns[1][0] = m10; columns[1][1] = m11;
        }

        LML_QUALIFIER Mat(T m00, T m01, T m02, T m10, T m11, T m12, T m20, T m21, T m22) {
            static_assert(N == 3, "Matrix dimension must be 3");
            columns[0][0] = m00; columns[0][1] = m01; columns[0][2] = m02;
            columns[1][0] = m10; columns[1][1] = m11; columns[1][2] = m12;
            columns[2][0] = m20; columns[2][1] = m21; columns[2][2] = m22;
        }

        LML_QUALIFIER Mat(T m00, T m01, T m02, T m03, T m10, T m11, T m12, T m13, T m20, T m21, T m22, T m23, T m30, T m31, T m32, T m33) {
            static_assert(N == 4, "Matrix dimension must be 4");
            columns[0][0] = m00; columns[0][1] = m01; columns[0][2] = m02; columns[0][3] = m03;
            columns[1][0] = m10; columns[1][1] = m11; columns[1][2] = m12; columns[1][3] = m13;
            columns[2][0] = m20; columns[2][1] = m21; columns[2][2] = m22; columns[2][3] = m23;
            columns[3][0] = m30; columns[3][1] = m31; columns[3][2] = m32; columns[3][3] = m33;
        }

        LML_QUALIFIER Vec<T, N>& operator[](int i) { return columns[i]; }
        LML_QUALIFIER const Vec<T, N>& operator[](int i) const { return columns[i]; }

        LML_QUALIFIER Mat& operator*=(const Mat& other);
    };

    template<typename T, int N>
    LML_QUALIFIER Mat<T, N>& Mat<T, N>::operator*=(const Mat<T, N>& other) {
        *this = *this * other;
        return *this;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Mat<T, N> transpose(const Mat<T, N>& m) {
        Mat<T, N> result;
        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < N; ++i) {
                result[j][i] = m[i][j];
            }
        }
        return result;
    }

    template<typename T, int N>
    LML_QUALIFIER
    LML_INLINE Vec<T, N> multiply(const Mat<T, N>& m, const Vec<T, N>& v) {
        Vec<T, N> result = {};
        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < N; ++i) {
                result[i] += m[j][i] * v[j];
            }
        }
        return result;
    }

    template<typename T>
    struct Quat {
        T x, y, z, w;

        LML_QUALIFIER Quat() : x(0), y(0), z(0), w(1) {}
        LML_QUALIFIER Quat(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}
        LML_QUALIFIER Quat(T angle, Vec<T, 3> axis) {
            T s = sin(angle * static_cast<T>(0.5));
            x = axis.x * s;
            y = axis.y * s;
            z = axis.z * s;
            w = cos(angle * static_cast<T>(0.5));
        }

        LML_QUALIFIER Quat& operator*=(const Quat& q) {
            T nx = w * q.x + x * q.w + y * q.z - z * q.y;
            T ny = w * q.y + y * q.w + z * q.x - x * q.z;
            T nz = w * q.z + z * q.w + x * q.y - y * q.x;
            T nw = w * q.w - x * q.x - y * q.y - z * q.z;
            x = nx; y = ny; z = nz; w = nw;
            return *this;
        }
    };

    template<typename T>
    LML_QUALIFIER LML_INLINE Quat<T> operator*(Quat<T> q1, const Quat<T>& q2) {
        return q1 *= q2;
    }

    template<typename T>
    LML_QUALIFIER LML_INLINE T dot(const Quat<T>& q1, const Quat<T>& q2) {
        return q1.x * q2.x + q1.y * q2.y + q1.z * q2.z + q1.w * q2.w;
    }

    template<typename T>
    LML_QUALIFIER LML_INLINE Quat<T> conjugate(const Quat<T>& q) {
        return Quat<T>(-q.x, -q.y, -q.z, q.w);
    }

    template<typename T>
    LML_QUALIFIER LML_INLINE Quat<T> inverse(const Quat<T>& q) {
        T d = dot(q, q);
        Quat<T> c = conjugate(q);
        return Quat<T>(c.x / d, c.y / d, c.z / d, c.w / d);
    }

    template<typename T>
    LML_QUALIFIER LML_INLINE Vec<T, 3> operator*(const Quat<T>& q, const Vec<T, 3>& v) {
        Vec<T, 3> qv(q.x, q.y, q.z);
        Vec<T, 3> uv = cross(qv, v);
        Vec<T, 3> uuv = cross(qv, uv);
        return v + ((uv * q.w) + uuv) * static_cast<T>(2);
    }

    template<typename T>
    LML_QUALIFIER LML_INLINE Quat<T> angleAxis(T angle, const Vec<T, 3>& axis) {
        return Quat<T>(angle, axis);
    }

    template<typename T, int N> LML_QUALIFIER LML_INLINE Vec<T, N> operator*(const Mat<T, N>& m, const Vec<T, N>& v) { return multiply(m, v); }

    template<typename T, int N>
    LML_QUALIFIER
    LML_INLINE Mat<T, N> multiply(const Mat<T, N>& m1, const Mat<T, N>& m2) {
        Mat<T, N> result = {};
        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < N; ++i) {
                for (int k = 0; k < N; ++k) {
                    result[j][i] += m1[k][i] * m2[j][k];
                }
            }
        }
        return result;
    }

    template<typename T, int N> LML_QUALIFIER LML_INLINE Mat<T, N> operator*(const Mat<T, N>& m1, const Mat<T, N>& m2) { return multiply(m1, m2); }

    LML_QUALIFIER
    LML_INLINE float det(const Mat<float, 2>& m) {
        return m[0][0] * m[1][1] - m[1][0] * m[0][1];
    }

    LML_QUALIFIER
    LML_INLINE float det(const Mat<float, 3>& m) {
        return m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2])
             - m[1][0] * (m[0][1] * m[2][2] - m[2][1] * m[0][2])
             + m[2][0] * (m[0][1] * m[1][2] - m[1][1] * m[0][2]);
    }

    LML_QUALIFIER
    LML_INLINE float det(const Mat<float, 4>& m) {
        float sub_factor_00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
        float sub_factor_01 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
        float sub_factor_02 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
        float sub_factor_03 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
        float sub_factor_04 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
        float sub_factor_05 = m[2][0] * m[3][1] - m[3][0] * m[2][1];

        Vec<float, 4> det_cof(
            + (m[1][1] * sub_factor_00 - m[1][2] * sub_factor_01 + m[1][3] * sub_factor_02),
            - (m[1][0] * sub_factor_00 - m[1][2] * sub_factor_03 + m[1][3] * sub_factor_04),
            + (m[1][0] * sub_factor_01 - m[1][1] * sub_factor_03 + m[1][3] * sub_factor_05),
            - (m[1][0] * sub_factor_02 - m[1][1] * sub_factor_04 + m[1][2] * sub_factor_05)
        );

        return m[0][0] * det_cof[0] + m[0][1] * det_cof[1] + m[0][2] * det_cof[2] + m[0][3] * det_cof[3];
    }

    LML_QUALIFIER
    LML_INLINE Mat<float, 2> inverse(const Mat<float, 2>& m) {
        float one_over_determinant = 1.0f / det(m);
        Mat<float, 2> result;
        result[0][0] = +m[1][1] * one_over_determinant;
        result[1][0] = -m[1][0] * one_over_determinant;
        result[0][1] = -m[0][1] * one_over_determinant;
        result[1][1] = +m[0][0] * one_over_determinant;
        return result;
    }

    LML_QUALIFIER
    LML_INLINE Mat<float, 3> inverse(const Mat<float, 3>& m) {
        float one_over_determinant = 1.0f / det(m);
        Mat<float, 3> result;
        result[0][0] = + (m[1][1] * m[2][2] - m[2][1] * m[1][2]) * one_over_determinant;
        result[1][0] = - (m[1][0] * m[2][2] - m[2][0] * m[1][2]) * one_over_determinant;
        result[2][0] = + (m[1][0] * m[2][1] - m[2][0] * m[1][1]) * one_over_determinant;
        result[0][1] = - (m[0][1] * m[2][2] - m[2][1] * m[0][2]) * one_over_determinant;
        result[1][1] = + (m[0][0] * m[2][2] - m[2][0] * m[0][2]) * one_over_determinant;
        result[2][1] = - (m[0][0] * m[2][1] - m[2][0] * m[0][1]) * one_over_determinant;
        result[0][2] = + (m[0][1] * m[1][2] - m[1][1] * m[0][2]) * one_over_determinant;
        result[1][2] = - (m[0][0] * m[1][2] - m[1][0] * m[0][2]) * one_over_determinant;
        result[2][2] = + (m[0][0] * m[1][1] - m[1][0] * m[0][1]) * one_over_determinant;
        return result;
    }

    LML_QUALIFIER
    LML_INLINE Mat<float, 4> inverse(const Mat<float, 4>& m) {
        float coef_00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
        float coef_02 = m[1][2] * m[3][3] - m[3][2] * m[1][3];
        float coef_03 = m[1][2] * m[2][3] - m[2][2] * m[1][3];

        float coef_04 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
        float coef_06 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
        float coef_07 = m[1][1] * m[2][3] - m[2][1] * m[1][3];

        float coef_08 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
        float coef_10 = m[1][1] * m[3][2] - m[3][1] * m[1][2];
        float coef_11 = m[1][1] * m[2][2] - m[2][1] * m[1][2];

        float coef_12 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
        float coef_14 = m[1][0] * m[3][3] - m[3][0] * m[1][3];
        float coef_15 = m[1][0] * m[2][3] - m[2][0] * m[1][3];

        float coef_16 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
        float coef_18 = m[1][0] * m[3][2] - m[3][0] * m[1][2];
        float coef_19 = m[1][0] * m[2][2] - m[2][0] * m[1][2];

        float coef_20 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
        float coef_22 = m[1][0] * m[3][1] - m[3][0] * m[1][1];
        float coef_23 = m[1][0] * m[2][1] - m[2][0] * m[1][1];

        Vec<float, 4> fac0(coef_00, coef_00, coef_02, coef_03);
        Vec<float, 4> fac1(coef_04, coef_04, coef_06, coef_07);
        Vec<float, 4> fac2(coef_08, coef_08, coef_10, coef_11);
        Vec<float, 4> fac3(coef_12, coef_12, coef_14, coef_15);
        Vec<float, 4> fac4(coef_16, coef_16, coef_18, coef_19);
        Vec<float, 4> fac5(coef_20, coef_20, coef_22, coef_23);

        Vec<float, 4> v_0(m[1][0], m[0][0], m[0][0], m[0][0]);
        Vec<float, 4> v_1(m[1][1], m[0][1], m[0][1], m[0][1]);
        Vec<float, 4> v_2(m[1][2], m[0][2], m[0][2], m[0][2]);
        Vec<float, 4> v_3(m[1][3], m[0][3], m[0][3], m[0][3]);

        Vec<float, 4> inv_0(v_1[0] * fac0[0] - v_2[0] * fac1[0] + v_3[0] * fac2[0], v_1[1] * fac0[1] - v_2[1] * fac1[1] + v_3[1] * fac2[1], v_1[2] * fac0[2] - v_2[2] * fac1[2] + v_3[2] * fac2[2], v_1[3] * fac0[3] - v_2[3] * fac1[3] + v_3[3] * fac2[3]);
        Vec<float, 4> inv_1(v_0[0] * fac0[0] - v_2[0] * fac3[0] + v_3[0] * fac4[0], v_0[1] * fac0[1] - v_2[1] * fac3[1] + v_3[1] * fac4[1], v_0[2] * fac0[2] - v_2[2] * fac3[2] + v_3[2] * fac4[2], v_0[3] * fac0[3] - v_2[3] * fac3[3] + v_3[3] * fac4[3]);
        Vec<float, 4> inv_2(v_0[0] * fac1[0] - v_1[0] * fac3[0] + v_3[0] * fac5[0], v_0[1] * fac1[1] - v_1[1] * fac3[1] + v_3[1] * fac5[1], v_0[2] * fac1[2] - v_1[2] * fac3[2] + v_3[2] * fac5[2], v_0[3] * fac1[3] - v_1[3] * fac3[3] + v_3[3] * fac5[3]);
        Vec<float, 4> inv_3(v_0[0] * fac2[0] - v_1[0] * fac4[0] + v_2[0] * fac5[0], v_0[1] * fac2[1] - v_1[1] * fac4[1] + v_2[1] * fac5[1], v_0[2] * fac2[2] - v_1[2] * fac4[2] + v_2[2] * fac5[2], v_0[3] * fac2[3] - v_1[3] * fac4[3] + v_2[3] * fac5[3]);

        Vec<float, 4> sign_a(+1, -1, +1, -1);
        Vec<float, 4> sign_b(-1, +1, -1, +1);
        Mat<float, 4> inv_mat;
        for(int i = 0; i < 4; i++) {
            inv_mat[0][i] = inv_0[i] * sign_a[i];
            inv_mat[1][i] = inv_1[i] * sign_b[i];
            inv_mat[2][i] = inv_2[i] * sign_a[i];
            inv_mat[3][i] = inv_3[i] * sign_b[i];
        }

        float det_val = m[0][0] * inv_mat[0][0] + m[0][1] * inv_mat[1][0] + m[0][2] * inv_mat[2][0] + m[0][3] * inv_mat[3][0];

        float one_over_determinant = 1.0f / det_val;

        for(int j = 0; j < 4; j++) {
            for(int i = 0; i < 4; i++) {
                inv_mat[j][i] *= one_over_determinant;
            }
        }

        return inv_mat;
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T bitwiseAnd(T a, T b) {
        return a & b;
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T bitwiseOr(T a, T b) {
        return a | b;
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T bitwiseXor(T a, T b) {
        return a ^ b;
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T bitshiftLeft(T a, T b) {
        return a << b;
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T bitshiftRight(T a, T b) {
        return a >> b;
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T flipBits(T a) {
        return ~a;
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE int not_val(T a) {
        return static_cast<int>(!static_cast<bool>(a));
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T negate(T a) {
        return -a;
    }

    template<typename T, int N>
    LML_QUALIFIER
    LML_INLINE Vec<bool, N> lessThan(Vec<T, N> a, Vec<T, N> b) {
        return a < b;
    }

    template<typename T, int N>
    LML_QUALIFIER
    LML_INLINE Vec<bool, N> lessThanEqual(Vec<T, N> a, Vec<T, N> b) {
        return a <= b;
    }

    template<typename T, int N>
    LML_QUALIFIER
    LML_INLINE Vec<bool, N> greaterThan(Vec<T, N> a, Vec<T, N> b) {
        return a > b;
    }

    template<typename T, int N>
    LML_QUALIFIER
    LML_INLINE Vec<bool, N> greaterThanEqual(Vec<T, N> a, Vec<T, N> b) {
        return a >= b;
    }

    template<typename T, int N>
    LML_QUALIFIER
    LML_INLINE Vec<bool, N> equal(Vec<T, N> a, Vec<T, N> b) {
        return a == b;
    }

    template<typename T, int N>
    LML_QUALIFIER
    LML_INLINE Vec<bool, N> notEqual(Vec<T, N> a, Vec<T, N> b) {
        return a != b;
    }

    template<int N>
    LML_QUALIFIER
    LML_INLINE bool any(Vec<bool, N> v) {
        bool res = false;
        for (int i = 0; i < N; ++i) res = res || v[i];
        return res;
    }

    template<int N>
    LML_QUALIFIER
    LML_INLINE bool all(Vec<bool, N> v) {
        bool res = true;
        for (int i = 0; i < N; ++i) res = res && v[i];
        return res;
    }

    template<int N>
    LML_QUALIFIER
    LML_INLINE Vec<bool, N> not_val(Vec<bool, N> v) {
        Vec<bool, N> res;
        for (int i = 0; i < N; ++i) res[i] = !v[i];
        return res;
    }

    LML_QUALIFIER
    LML_INLINE uint32_t floatBitsToUint(float v) {
        union { float f; uint32_t u; } u;
        u.f = v;
        return u.u;
    }

    LML_QUALIFIER
    LML_INLINE float uintBitsToFloat(uint32_t v) {
        union { float f; uint32_t u; } u;
        u.u = v;
        return u.f;
    }

    template<typename T, int N>
    LML_QUALIFIER
    LML_INLINE Vec<uint32_t, N> floatBitsToUint(Vec<float, N> v) {
        Vec<uint32_t, N> res;
        for (int i = 0; i < N; ++i) res[i] = floatBitsToUint(v[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER
    LML_INLINE Vec<float, N> uintBitsToFloat(Vec<uint32_t, N> v) {
        Vec<float, N> res;
        for (int i = 0; i < N; ++i) res[i] = uintBitsToFloat(v[i]);
        return res;
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE int greaterEqual(T a, T b) {
        return static_cast<int>(a >= b);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE int greaterThan(T a, T b) {
        return static_cast<int>(a > b);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE int equal(T a, T b) {
        return static_cast<int>(a == b);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE int notEqual(T a, T b) {
        return static_cast<int>(a != b);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE int lessThan(T a, T b) {
        return static_cast<int>(a < b);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE int lessEqual(T a, T b) {
        return static_cast<int>(a <= b);
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE int epsilonEqual(T a, T b, T epsilon) {
        return static_cast<int>(abs(a - b) <= epsilon);
    }

    template<typename T, int N>
    LML_QUALIFIER
    LML_INLINE Vec<bool, N> epsilonEqual(Vec<T, N> a, Vec<T, N> b, T epsilon) {
        Vec<bool, N> result;
        for (int i = 0; i < N; ++i) {
            result[i] = abs(a[i] - b[i]) <= epsilon;
        }
        return result;
    }

    template<typename T, int N>
    LML_QUALIFIER
    LML_INLINE Vec<bool, N> epsilonEqual(Vec<T, N> a, Vec<T, N> b, Vec<T, N> epsilon) {
        Vec<bool, N> result;
        for (int i = 0; i < N; ++i) {
            result[i] = abs(a[i] - b[i]) <= epsilon[i];
        }
        return result;
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T floorMultiple(T value, T multiple) {
        if constexpr (is_integral_v<T>) {
            return (value / multiple) * multiple;
        } else {
            return floor(value / multiple) * multiple;
        }
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T ceilMultiple(T value, T multiple) {
        if constexpr (is_integral_v<T>) {
            return ((value + multiple - 1) / multiple) * multiple;
        } else {
            return ceil(value / multiple) * multiple;
        }
    }

    template<typename T>
    LML_QUALIFIER
    LML_INLINE T roundMultiple(T value, T multiple) {
        if constexpr (is_integral_v<T>) {
            return ((value + multiple / 2) / multiple) * multiple;
        } else {
            return round(value / multiple) * multiple;
        }
    }

    LML_QUALIFIER
    constexpr int ceilMultiplePow2(int value, int multiple) {
        return (value + multiple - 1) & ~(multiple - 1);
    }

    LML_QUALIFIER
    constexpr int ceilMultipleOffsetPow2(int value, int multiple) {
        return (-value) & (multiple - 1);
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> floorMultiple(Vec<T, N> v, Vec<T, N> multiple) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = floorMultiple(v[i], multiple[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> floorMultiple(Vec<T, N> v, T multiple) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = floorMultiple(v[i], multiple);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> ceilMultiple(Vec<T, N> v, Vec<T, N> multiple) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = ceilMultiple(v[i], multiple[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> ceilMultiple(Vec<T, N> v, T multiple) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = ceilMultiple(v[i], multiple);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> roundMultiple(Vec<T, N> v, Vec<T, N> multiple) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = roundMultiple(v[i], multiple[i]);
        return res;
    }

    template<typename T, int N>
    LML_QUALIFIER LML_INLINE Vec<T, N> roundMultiple(Vec<T, N> v, T multiple) {
        Vec<T, N> res;
        for (int i = 0; i < N; ++i) res[i] = roundMultiple(v[i], multiple);
        return res;
    }

    using vec2 = Vec<float, 2>;
    using vec3 = Vec<float, 3>;
    using vec4 = Vec<float, 4>;

    using dvec2 = Vec<double, 2>;
    using dvec3 = Vec<double, 3>;
    using dvec4 = Vec<double, 4>;

    using bvec2 = Vec<bool, 2>;
    using bvec3 = Vec<bool, 3>;
    using bvec4 = Vec<bool, 4>;

    using ivec2 = Vec<int32_t, 2>;
    using ivec3 = Vec<int32_t, 3>;
    using ivec4 = Vec<int32_t, 4>;

    using uvec2 = Vec<uint32_t, 2>;
    using uvec3 = Vec<uint32_t, 3>;
    using uvec4 = Vec<uint32_t, 4>;

    using mat2 = Mat<float, 2>;
    using mat3 = Mat<float, 3>;
    using mat4 = Mat<float, 4>;

    using quat = Quat<float>;
    using dquat = Quat<double>;
}

#ifdef __clang__
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif
