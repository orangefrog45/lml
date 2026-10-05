#pragma once

#include <format>
#include <string>
#include "core.h"

namespace std {
    template <typename T, int N>
    struct formatter<lml::Vec<T, N>> : formatter<string> {
        auto format(const lml::Vec<T, N>& v, format_context& ctx) const {
            string s{"("};
            for (int i = 0; i < N; ++i) {
                s += std::format("{}", v[i]);
                if (i < N - 1)
                    s += ", ";
            }
            s += ")";
            return formatter<string>::format(s, ctx);
        }
    };

    template <typename T, int N>
    struct formatter<lml::Mat<T, N>> : formatter<string> {
        auto format(const lml::Mat<T, N>& m, format_context& ctx) const {
            string s{"Mat" + to_string(N) + "x" + to_string(N) + "("};
            for (int i = 0; i < N; ++i) {
                s += std::format("{}", m[i]);
                if (i < N - 1)
                    s += ", ";
            }
            s += ")";
            return formatter<string>::format(s, ctx);
        }
    };

    template <typename T>
    struct formatter<lml::Quat<T>> : formatter<string> {
        auto format(const lml::Quat<T>& q, format_context& ctx) const {
            string s{std::format("Quat({}, {}, {}, {})", q.x, q.y, q.z, q.w)};
            return formatter<string>::format(s, ctx);
        }
    };
}
