#include <iostream>

bool isPower(int n)
{
    if (n == 0)
        return false;
    while (n != 1)
    {
        if (n % 2 != 0)
            return false;
        n = n / 2;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    if (isPower(34))
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    if (isPower(32))
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    return 0;
}
