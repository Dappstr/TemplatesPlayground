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


int main()
{

    return 0;
}
