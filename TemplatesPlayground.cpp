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
requires std::same_as<std::decay_t<F<int>>, std::function<void()>>
void for_each(it* begin, it* end, F<int>) {
    for(auto indx = 0; begin < end; begin++) {

    }
}

int main()
{

    return 0;
}
