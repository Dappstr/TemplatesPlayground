#include <iostream>

template <typename T, typename... Ts>
void someFunc(T& arg, Ts ...args)
{
    std::cout << "Number of arguments: " << sizeof...(args) << "\n\n" << "Arguments: " << '\n';
    ((std::cout << args << '\n'), ...);

    ([&arg, &args]
        {
            if constexpr (sizeof...(args))
            {
                std::cout << "Increasing x for argument: " << args << '\n';
                arg++;
            }
        }
    (), ...);
}

int main()
{
    static int x{ 0 };

    std::string s{ "test" };

    someFunc(x, 'a', 1, 2.5, "hello", s);

    std::cout << "\nValue of x: " << x;

    return 0;
}