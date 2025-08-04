#include "easyfind.hpp"

int main()
{
    // Test with vector
    std::vector<int> vec;
    for (int i = 1; i <= 5; ++i)
        vec.push_back(i * 10);

    try
	{
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Found in vector: " << *it << std::endl;
    }
	catch (const std::exception &e)
	{
        std::cout << "Vector: " << e.what() << std::endl;
    }

    // Test with list
    std::list<int> lst;
    for (int i = 0; i < 5; ++i)
        lst.push_back(i);

    try
	{
        std::list<int>::iterator it = easyfind(lst, 3);
        std::cout << "Found in list: " << *it << std::endl;
    }
	catch (const std::exception &e)
	{
        std::cout << "List: " << e.what() << std::endl;
    }

    // Test with deque
    std::deque<int> deq;
    for (int i = 5; i >= 1; --i)
        deq.push_back(i);

    try
	{
        std::deque<int>::iterator it = easyfind(deq, 2);
        std::cout << "Found in deque: " << *it << std::endl;
    }
	catch (const std::exception &e)
	{
        std::cout << "Deque: " << e.what() << std::endl;
    }

    // Test with non-existent value
    try
	{
        easyfind(vec, 99);
    }
	catch (const std::exception &e)
	{
        std::cout << "Not found test: " << e.what() << std::endl;
    }

    return 0;
}