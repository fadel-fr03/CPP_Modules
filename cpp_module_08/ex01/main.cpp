#include "incs/Span.hpp"

int main()
{
    try
    {
        // Basic test (should output: 2 and 14)
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // Stress test with 15000 numbers
        Span bigSpan(15000);
        std::vector<int> bigVec;

        std::srand(static_cast<unsigned int>(std::time(NULL)));
        for (int i = 0; i < 15000; ++i)
            bigVec.push_back(std::rand());

        bigSpan.addRange(bigVec.begin(), bigVec.end());

        std::cout << "\n[15000 Numbers Test]" << std::endl;
        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;

        // Exception: Adding more than capacity
        std::cout << "\n[Exception Test: VectorIsFullException]" << std::endl;
        sp.addNumber(42);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        // Exception: Calling span functions with <2 elements
        std::cout << "\n[Exception Test: NeedMoreElementsException]" << std::endl;
        Span s(1);
        s.addNumber(5);
        std::cout << s.shortestSpan() << std::endl; // Should throw
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
