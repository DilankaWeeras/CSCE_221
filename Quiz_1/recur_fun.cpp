#include <iostream>


void Recur_fun(int n)
{
    if(n > 0)
    {
        Recur_fun(n-1);
        std::cout << n << std::endl;
        Recur_fun(n-1);
    }
}

int main()
{
    int n = 0;
    Recur_fun(n);
    return 0;
}