#include <iostream>
#include <vector>
#include <cassert>
#include <iostream>
#include "Stack1.h"

template <typename T, typename... Ts>
void someFunc(T& arg, Ts ...args)
{
    std::cout << "Number of arguments: " << sizeof...(args) << "\n\n" << "Arguments: " << '\n';
    ((std::cout << args << '\n'), ...);

    ([&arg, &args]
        {
            if constexpr (sizeof...(args) > 0)
            {
                std::cout << "Increasing x for argument: " << args << '\n';
                arg++;
            }
        }
    (), ...);
}

int main()
{
    
    {
        static int x{ 0 };
        std::string s{ "test" };

        someFunc(x, 'a', 1, 2.5, "hello", s);

        std::cout << "\nValue of x: " << x << "\n\n";
    }

    Stack<int> stackObj{ 2, 3, 4, 5, 6 };
    std::cout << stackObj;

    return 0;
}
