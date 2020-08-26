#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;

int arrayMax(int array[], int size)
{
    if(array == nullptr)
    {
        return -1;
    }
    else if(size == 0)
    {
        return 0;
    }
    else if(size == 1)
    {
        return array[0];
    }
    return max(array[size-1], arrayMax(array, size-1));
}

int main ()
{
    int array1[] = {1,2,3,5,6,8,3,8,3,2};
    int array2[] = {123,6232,64,54,73,2345};
    cout << arrayMax(array1, 10) << endl;
    cout << arrayMax(array2, 6) << endl;
    
    return 0;
}