#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T, typename F>
void iter(T* arr, int length, F func)
{
    if (!arr)
        return;
    for (int i = 0; i < length; ++i)
        func(arr[i]);
}

#endif
