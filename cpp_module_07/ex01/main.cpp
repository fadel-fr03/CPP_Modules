#include "iter.hpp"

// ==== Function Templates From ex00 ====

template <typename T>
T &min(T &a, T &b)
{
    if (a < b)
        return a;
    
    return b;
}

template <typename T>
T &max(T &a, T &b)
{
    if (a > b)
        return a;
    
    return b;
}

// ==== Utility to pass into iter ====

template <typename T>
void print(const T &elem)
{
    std::cout << elem << " ";
}

// ==== cap each element to at most 5 (uses min<T>) ====

template <typename T>
void capToFive(T &elem)
{
    T limit = (T)5;
    elem = ::min(elem, limit);
}

// ==== raise each element to at least 3 (uses max<T>) ====

template <typename T>
void floorToThree(T &elem)
{
    T limit = (T)3;
    elem = ::max(elem, limit);
}

int main()
{
    // ———— Test iter() on an int array ————
    int numbers[] = {5, 2, 8, 1, 9};
    int lenNums = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Original: ";
    iter(numbers, lenNums, print<int>);
    std::cout << std::endl;

    std::cout << "Cap to five via iter:  ";
    iter(numbers, lenNums, capToFive<int>);
    iter(numbers, lenNums, print<int>);
    std::cout << std::endl;

    std::cout << "Floor to three via iter:";
    iter(numbers, lenNums, floorToThree<int>);
    iter(numbers, lenNums, print<int>);
    std::cout << std::endl << std::endl;

    // ———— Test iter() on a std::string array ————

    std::string words[] = {"zebra", "apple", "banana", "mango"};
    int lenWords = sizeof(words) / sizeof(words[0]);

    std::cout << "Strings original: ";
    iter(words, lenWords, print<std::string>);
    std::cout << std::endl;

    return 0;
}