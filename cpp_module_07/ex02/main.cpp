#include "Array.hpp"

int main()
{
    std::cout << "Testing default constructor..." << std::endl;
    Array<int> defaultArray;
    std::cout << "Size: " << defaultArray.size() << std::endl;

    std::cout << "\nTesting parameterized constructor (Array<int>(5))..." << std::endl;
    Array<int> intArray(5);
    for (unsigned int i = 0; i < intArray.size(); i++)
        intArray[i] = i * 10;

    for (unsigned int i = 0; i < intArray.size(); i++)
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;

    std::cout << "\nTesting copy constructor..." << std::endl;
    Array<int> copyArray(intArray);
    copyArray[0] = 999;

    std::cout << "Original intArray[0]: " << intArray[0] << std::endl;
    std::cout << "Copy copyArray[0]: " << copyArray[0] << std::endl;

    std::cout << "\nTesting assignment operator..." << std::endl;
    Array<int> assignedArray;
    assignedArray = intArray;
    assignedArray[1] = 888;

    std::cout << "Original intArray[1]: " << intArray[1] << std::endl;
    std::cout << "Assigned assignedArray[1]: " << assignedArray[1] << std::endl;

    std::cout << "\nTesting bounds checking (expecting exception)..." << std::endl;
    try
    {
        std::cout << intArray[999] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\nTesting with std::string type..." << std::endl;
    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "Array";
    strArray[2] = "Template";

    for (unsigned int i = 0; i < strArray.size(); i++)
        std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;

    return 0;
}

// #include "Array.hpp"
// #include <cstdlib>
// #include <ctime>


// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }
