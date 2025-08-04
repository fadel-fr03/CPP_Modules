#include "incs/PmergeMe.hpp"
#include "incs/Timer.hpp"

int main(int argc, char* argv[])
{
    try
    {
        if (argc < 2)
        {
            std::cerr << "Usage: " << argv[0] << " <positive integers>" << std::endl;
            return 1;
        }

        std::vector<int> inputVec = parseArguments(argc, argv);
        validateSequence(inputVec);

		std::deque<int> inputDeq = vectorToDeque(inputVec);

		PmergeMe sorter(inputVec, inputDeq);
        Timer timer;

		std::cout << "Sorting sequence using the std::vector container:" << std::endl;
        printVector(inputVec, "Before: ");

        timer.start();
        std::vector<int> sortedVec = sorter.sortVector();
        double time = timer.elapsedMicrosec();

        printVector(sortedVec, "After:  ");
        std::cout << "Time to process a range of " << inputVec.size()
                  << " elements with std::vector : " << time << " us" << std::endl;
        std::cout << "Comparisons used: " << sorter.getComparisons() << std::endl;

        if (isSortedVector(sortedVec))
            std::cout << "✓ Sequence is correctly sorted!" << std::endl << std::endl;
        else
            std::cout << "✗ ERROR: Sequence is not sorted!" << std::endl << std::endl;



		std::cout << "Sorting sequence using the std::deque container:" << std::endl;
		printDeque(inputDeq, "Before: ");
		timer.start();
        std::deque<int> sortedDeq = sorter.sortDeque();
        time = timer.elapsedMicrosec();

        printDeque(sortedDeq, "After:  ");
        std::cout << "Time to process a range of " << sortedDeq.size()
                  << " elements with std::deque : " << time << " us" << std::endl;
        std::cout << "Comparisons used: " << sorter.getComparisons() << std::endl;

        if (isSortedDeque(sortedDeq))
            std::cout << "✓ Sequence is correctly sorted!" << std::endl;
        else
            std::cout << "✗ ERROR: Sequence is not sorted!" << std::endl;

        return 0;
    }
    catch (const PmergeMe::InvalidSequenceException&)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}