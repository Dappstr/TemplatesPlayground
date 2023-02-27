#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>
#include <numeric>
#include <vector>

template <typename First, typename... Ts>
void someFunc(First first, Ts ...args)
{
    int arg = first;

    ([&arg, &args]
        {
            if constexpr (sizeof...(args) > 0)
            {
                std::cout << "Increasing arg for argument: " << args << '\n';
                arg+=args;
            }
        }
    (), ...);
        
    std::cout << arg;

}

template <typename T, typename... Ts>
concept something = requires (T arg, Ts... args) {
    requires sizeof... (args) > 1;
    // Needs fixing { (... + args) } noexcept -> std::is_same_v<std::conjunction_v<T, Ts>...>;
};

template <typename T, typename... Ts,
typename = std::enable_if_t<
                            std::conjunction_v<
                            std::is_same<
                            std::decay_t<T>, std::decay_t<Ts>>...>>>
void acc(T first, Ts... args) {

}

template <typename X>
struct C {
    X x {};
    C() = default;

    template <int N>
    void f() {
        std::cout << N << '\n';
    }
};

template <typename X, int N>
void print(const C<X>& c) {
    c.template f<N>();
}

//in progress, just testing
template <template <typename FRT> typename F, typename it>
requires std::same_as<std::decay_t<F<void>>, std::function<void()>>
auto for_each(it begin, it end, F<int> f) -> decltype(auto) {
    for(; begin != end; begin++) {
        f(*begin);
    }
    return f;
}

class S {
    private:
        std::vector<int> v{1, 2, 3, 4, 5};
    public:
        S() = default;
        auto begin() {
            return v.begin();
        }
        auto end() {
            return v.end();
        }
        auto print() {
            for_each(v.begin(), v.end(), [](int x) { std::cout << x << ' ';});
        }

        template <int N>
        auto ret_indx() {
            return v.at(N);
        }
};

template <typename T, int N>
auto printindx(T& t) {
    return t.template ret_indx<N>();
}

int main() {

    S s;
    for_each(s.begin(), s.end(), [&s] (int& x) mutable {x++;});
    s.print();
    std::cout << printindx<S, 3>(s);

  return 0;
}
