#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <set>
#include <climits>
#include <cerrno>
#include <cstdlib>
#include <cmath>
#include <deque>

// Implementation and utility functions
std::vector<int> parseArguments(int argc, char* argv[]);

void validateSequence(const std::vector<int>& seq);

void printVector(const std::vector<int>& vec, const std::string& prefix = "");

bool isSortedVector(const std::vector<int>& vec);

std::deque<int> vectorToDeque(const std::vector<int>& vec);

void printDeque(const std::deque<int>& deq, const std::string& prefix);

bool isSortedDeque(const std::deque<int>& deq);

class PmergeMe
{
    private:
            std::vector<int> inputVec;
			std::deque<int> inputDeq;
            int comparisons;
            std::vector<int> jacobsthal_cache_vec;
			std::deque<int> jacobsthal_cache_deq;
    
			// Vector functions
            void precomputeJacobsthalVector(int max_size);
            std::vector<int> buildOptimalInsertionOrderVector(int numPairs) const;
            void BinaryInsertVector(std::vector<int>& chain, int value, int searchLimit);
            std::vector<int> sortSmallCasesVector(const std::vector<int>& arr);
            std::vector<int> mergeInsertSortVector(const std::vector<int>& chain);
			int getIndexInChainVector(const std::vector<int>& chain, int value) const;


			// Deque functions
			void precomputeJacobsthalDeque(int max_size);
			std::deque<int> buildOptimalInsertionOrderDeque(int numPairs) const;
			void BinaryInsertDeque(std::deque<int>& chain, int value, int searchLimit);
			std::deque<int> sortSmallCasesDeque(const std::deque<int>& arr);
			std::deque<int> mergeInsertSortDeque(const std::deque<int>& chain);
			int getIndexInChainDeque(const std::deque<int>& chain, int value) const;


			PmergeMe();
			PmergeMe(const PmergeMe &to_copy);
			PmergeMe &operator=(const PmergeMe &to_copy);

    public:
            class InvalidSequenceException : public std::exception
            {
                public:
                    virtual const char* what() const throw();
            };

			~PmergeMe();
            PmergeMe(const std::vector<int>& input_vec, const std::deque<int>& input_deq);
    
            int getComparisons() const;
    
            std::vector<int> sortVector();

			std::deque<int> sortDeque();
};

#endif