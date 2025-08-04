#include "../incs/PmergeMe.hpp"

const char* PmergeMe::InvalidSequenceException::what() const throw()
{
    return "Error";
}
    
PmergeMe::PmergeMe() : comparisons(0)
{}

PmergeMe::PmergeMe(const std::vector<int>& input_vec, const std::deque<int>& input_deq) : inputVec(input_vec), inputDeq(input_deq), comparisons(0)
{}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &to_copy) : inputVec(to_copy.inputVec), inputDeq(to_copy.inputDeq), comparisons(to_copy.comparisons),
	jacobsthal_cache_vec(to_copy.jacobsthal_cache_vec), jacobsthal_cache_deq(to_copy.jacobsthal_cache_deq)
{}

PmergeMe &PmergeMe::operator=(const PmergeMe &to_copy)
{
	if (this != &to_copy)
	{
		inputVec = to_copy.inputVec;
		comparisons = to_copy.comparisons;
		jacobsthal_cache_vec = to_copy.jacobsthal_cache_vec;
	}
	return *this;
}
    
int PmergeMe::getComparisons() const
{
    return comparisons;
}

// Implementation and utility functions

std::vector<int> parseArguments(int argc, char* argv[])
{
    std::vector<int> result;

    for (int i = 1; i < argc; ++i)
    {
        std::string arg(argv[i]);
        if (arg.empty())
            throw PmergeMe::InvalidSequenceException();

        char *end;
        errno = 0;
        long num = std::strtol(arg.c_str(), &end, 10);
        if (errno == ERANGE || *end != '\0')
            throw PmergeMe::InvalidSequenceException();
        if (num <= 0 || num > INT_MAX)
            throw PmergeMe::InvalidSequenceException();

        result.push_back(static_cast<int>(num));
    }

    return result;
}

void validateSequence(const std::vector<int>& seq)
{
    if (seq.empty())
        throw PmergeMe::InvalidSequenceException();

    for (std::size_t i = 0; i < seq.size(); ++i)
    {
        for (std::size_t j = i + 1; j < seq.size(); ++j)
        {
            if (seq[i] == seq[j])
                throw PmergeMe::InvalidSequenceException();
        }
    }
}

void printVector(const std::vector<int>& vec, const std::string& prefix)
{
    if (!prefix.empty())
		std::cout << prefix;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << (i + 1 < vec.size() ? " " : "");
    }
    std::cout << std::endl;
}

bool isSortedVector(const std::vector<int>& vec)
{
    for (size_t i = 1; i < vec.size(); ++i)
        if (vec[i] < vec[i-1])
            return false;
    return true;
}


std::deque<int> vectorToDeque(const std::vector<int>& vec)
{
    return std::deque<int>(vec.begin(), vec.end());
}

void printDeque(const std::deque<int>& deq, const std::string& prefix)
{
	if (!prefix.empty())
		std::cout << prefix;
    for (size_t i = 0; i < deq.size(); ++i)
    {
        std::cout << deq[i] << (i + 1 < deq.size() ? " " : "");
    }
    std::cout << std::endl;
}

bool isSortedDeque(const std::deque<int>& deq)
{
	for (size_t i = 1; i < deq.size(); ++i)
		if (deq[i] < deq[i-1])
			return false;
	return true;
}

/*

					Vector Implementation
*/

// Precomputes Jacobsthal numbers up to a given maximum size and stores them in a cache
// Jacobsthal numbers are used to determine optimal insertion order in merge-insert sort
// Formula: J(n) = J(n-1) + 2*J(n-2), starting with J(0)=0 and J(1)=1
void PmergeMe::precomputeJacobsthalVector(int max_size)
{
    jacobsthal_cache_vec.clear();
    jacobsthal_cache_vec.push_back(0);  // J(0)
    jacobsthal_cache_vec.push_back(1);  // J(1)
        
    // Generate numbers until we exceed the required maximum size
    while (jacobsthal_cache_vec.back() < max_size)
    {
        int next = jacobsthal_cache_vec.back() + 2 * jacobsthal_cache_vec[jacobsthal_cache_vec.size() - 2];
        jacobsthal_cache_vec.push_back(next);
    }
}

// Finds the index of a given value in a vector (chain)
// Returns -1 if the value is not found
// Linear search is used since the chain may not be fully sorted during the insertion process
int PmergeMe::getIndexInChainVector(const std::vector<int>& chain, int value) const
{
    for (size_t i = 0; i < chain.size(); ++i)
    {
        if (chain[i] == value)
            return i;
    }
    return -1;
}

// Generates an optimal insertion order for merge-insert sort using Jacobsthal numbers
// This order minimizes the number of comparisons needed during binary insertion
// The sequence groups elements according to Jacobsthal numbers and processes them in reverse order
std::vector<int> PmergeMe::buildOptimalInsertionOrderVector(int numPairs) const
{
    std::vector<int> order;
    if (numPairs <= 1)
        return order;
        
    // Extract relevant Jacobsthal numbers from cache (starting from index 3)
    std::vector<int> jacobSequence;
    for (size_t k = 3; k < jacobsthal_cache_vec.size() && jacobsthal_cache_vec[k] <= numPairs; ++k)
        jacobSequence.push_back(jacobsthal_cache_vec[k]);
    
    // Track which indices have been scheduled for insertion
    std::vector<bool> inserted(numPairs, false);
    
    // Process each Jacobsthal number to create insertion groups
    for (size_t i = 0; i < jacobSequence.size(); ++i)
    {
        int groupEnd = jacobSequence[i];
        int groupStart = (i == 0) ? 2 : jacobSequence[i-1] + 1;
        
        // Insert group elements in reverse order (optimal for binary insertion)
        for (int idx = groupEnd; idx >= groupStart; --idx)
        {
            if (idx <= numPairs && !inserted[idx-1])
            {
                order.push_back(idx - 1); // Convert to 0-based index
                inserted[idx-1] = true;
            }
        }
    }
    
    // Add any remaining unscheduled indices (those not part of Jacobsthal groups)
    for (int i = 1; i < numPairs; ++i) // Start from 1 since we skip b_1
    {
        if (!inserted[i])
            order.push_back(i);
    }
        
    return order;
}

// Performs binary insertion of a value into a chain with a specified search limit
// The search limit restricts the upper bound of the binary search range
// This is crucial for maintaining the Ford-Johnson algorithm's efficiency
void PmergeMe::BinaryInsertVector(std::vector<int>& chain, int value, int searchLimit)
{
    // Handle edge case where search limit is at the beginning
    if (searchLimit <= 0)
    {
        chain.insert(chain.begin(), value);
        return;
    }

    // Calculate the actual high index, ensuring we don't exceed chain bounds
    int actualHigh = std::min(searchLimit, static_cast<int>(chain.size())) - 1;
    if (actualHigh < 0)
    {
        chain.insert(chain.begin(), value);
        return;
    }

    // Binary search within the limited range
    int left = 0;
    int right = actualHigh;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        comparisons++;
        if (value < chain[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    // Insert at the found position
    chain.insert(chain.begin() + left, value);
}

// Specialized sorting function for small input sizes (0-5 elements)
// Uses optimized comparison sequences to minimize the number of comparisons
// For sizes 4 and 5, implements a simplified version of merge-insert sort
std::vector<int> PmergeMe::sortSmallCasesVector(const std::vector<int>& arr)
{
    switch (arr.size())
    {
        case 0:
        case 1:
            return arr;
                
        case 2:
        {
            std::vector<int> result = arr;
            comparisons++;
            if (result[0] > result[1])
                std::swap(result[0], result[1]);
            return result;
        }
            
        case 3:
        {
            std::vector<int> result = arr;
            // Sort first two elements
            comparisons++;
            if (result[0] > result[1])
                std::swap(result[0], result[1]);            
            // Insert third element in correct position
            comparisons++;
            if (result[1] > result[2])
            {
                std::swap(result[1], result[2]);
                    
                comparisons++;
                if (result[0] > result[1])
                    std::swap(result[0], result[1]);
            }
            return result;
        }
            
        case 4:
        {
            std::vector<int> result = arr;
                
            // Sort first pair
            comparisons++;
            if (result[0] > result[1])
                std::swap(result[0], result[1]);
            // Sort second pair
            comparisons++;
            if (result[2] > result[3])
                std::swap(result[2], result[3]);
                
            // Ensure first pair has smaller maximum
            comparisons++;
            if (result[1] > result[3])
            {
                std::swap(result[0], result[2]);
                std::swap(result[1], result[3]);
            }
                
            // Build initial chain with three elements
            std::vector<int> chain;
            chain.push_back(result[0]);  // smallest element
            chain.push_back(result[1]);  // smaller maximum
            chain.push_back(result[3]);  // largest element
                
            // Insert the remaining element with bounded binary search
            BinaryInsertVector(chain, result[2], 2);    
            return chain;
        }
            
        case 5:
        {
            std::vector<int> v(arr);

            // Step 1: Sort first pair (a,b)
            comparisons++;
            if (v[0] > v[1])
                std::swap(v[0], v[1]);

            // Step 2: Sort second pair (c,d)
            comparisons++;
            if (v[2] > v[3])
                std::swap(v[2], v[3]);

            // Step 3: Ensure first pair has smaller maximum
            comparisons++;
            if (v[1] > v[3])
            {
                std::swap(v[0], v[2]);
                std::swap(v[1], v[3]);
            }

            // Step 4: Insert fifth element (e) relative to known elements
            comparisons++;
            if (v[4] < v[1])
            {
                // e is less than b
                comparisons++;
                if (v[4] < v[0])
                {
                    // e is smallest element
                    std::vector<int> chain;
                    chain.push_back(v[4]);
                    chain.push_back(v[0]);
                    chain.push_back(v[1]);
                    BinaryInsertVector(chain, v[2], chain.size());
                    chain.push_back(v[3]);
                    return chain;
                }
                else
                {
                    // e is between a and b
                    std::vector<int> chain;
                    chain.push_back(v[0]);
                    chain.push_back(v[4]);
                    chain.push_back(v[1]);
                    BinaryInsertVector(chain, v[2], chain.size());
                    chain.push_back(v[3]);
                    return chain;
                }
            }
            else
            {
                // e is greater than or equal to b
                comparisons++;
                if (v[4] < v[3])
                {
                    // e is between b and d
                    std::vector<int> chain;
                    chain.push_back(v[0]);
                    chain.push_back(v[1]);
                    chain.push_back(v[4]);
                    BinaryInsertVector(chain, v[2], chain.size());
                    chain.push_back(v[3]);
                    return chain;
                }
                else
                {
                    // e is largest element
                    std::vector<int> chain;
                    chain.push_back(v[0]);
                    chain.push_back(v[1]);
                    chain.push_back(v[3]);
                    BinaryInsertVector(chain, v[2], chain.size());
                    chain.push_back(v[4]);
                    return chain;
                }
            }
        }
    }
        
    return arr;
}
    
// Main merge-insert sort implementation for vectors
// Uses a recursive divide-and-conquer approach with optimal insertion ordering
// Follows the Ford-Johnson algorithm's merge-insertion sort strategy
std::vector<int> PmergeMe::mergeInsertSortVector(const std::vector<int>& chain)
{
    // Base case: use optimized small case sorting
    if (chain.size() <= 5)
        return sortSmallCasesVector(chain);
        
    // Step 1: Form pairs and sort them internally
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> leftovers;
        
    for (size_t i = 0; i + 1 < chain.size(); i += 2)
    {
        comparisons++;
        if (chain[i] > chain[i + 1])
            pairs.push_back(std::make_pair(chain[i], chain[i + 1]));
        else
            pairs.push_back(std::make_pair(chain[i + 1], chain[i]));
    }
        
    // Handle odd-sized input
    if (chain.size() % 2 != 0)
        leftovers.push_back(chain.back());
        
    if (pairs.empty())
        return leftovers;
        
    // Step 2: Recursively sort the larger elements of each pair
    std::vector<int> largerElements;
    for (size_t i = 0; i < pairs.size(); ++i)
        largerElements.push_back(pairs[i].first);
        
    std::vector<int> sortedLarger = mergeInsertSortVector(largerElements);
        
    // Step 3: Rebuild pairs in the order determined by the sorted larger elements
    std::vector<std::pair<int, int> > sortedPairs;
    for (size_t i = 0; i < sortedLarger.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == sortedLarger[i])
            {
                sortedPairs.push_back(pairs[j]);
                break;
            }
        }
    }
    
    // Create pend chain (smaller elements) in the order of their paired larger elements
    std::vector<int> pendChain;
    for (size_t i = 0; i < sortedPairs.size(); ++i)
        pendChain.push_back(sortedPairs[i].second);
    
    // Add leftover element to pend chain if it exists
    if (!leftovers.empty())
        pendChain.push_back(leftovers[0]);
        
    // Initialize main chain with first pend element (b_1)
    std::vector<int> mainChain;
    mainChain.push_back(pendChain[0]);
        
    // Add all sorted larger elements to main chain
    for (size_t i = 0; i < sortedLarger.size(); ++i)
        mainChain.push_back(sortedLarger[i]);
        
    // Step 4: Insert remaining pend elements using optimal Jacobsthal order
    std::vector<int> insertionOrder = buildOptimalInsertionOrderVector(pendChain.size());
        
    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        int idx = insertionOrder[i];
        if (idx < 0 || idx >= static_cast<int>(pendChain.size()))
            continue;
        if (idx == 0)
            continue; // Skip b_1 as it's already inserted
            
        int valueToInsert = pendChain[idx];
        
        // Calculate search limit based on the paired element's position
        int searchLimit = mainChain.size(); // Default to full chain
        
        if (idx < static_cast<int>(sortedPairs.size()))
        {
            // Find the paired larger element for this pend element
            int pairedElement = sortedPairs[idx].first;
            searchLimit = getIndexInChainVector(mainChain, pairedElement);
        }
            
        BinaryInsertVector(mainChain, valueToInsert, searchLimit);
    }
        
    return mainChain;
}
    
// Public interface for sorting the input vector
// Initializes comparison count and selects appropriate sorting strategy
std::vector<int> PmergeMe::sortVector()
{
    comparisons = 0;

    if (inputVec.size() <= 5)
        return sortSmallCasesVector(inputVec);

    // Precompute Jacobsthal numbers for optimal insertion order
    precomputeJacobsthalVector(inputVec.size());
    return mergeInsertSortVector(inputVec);
}


/*

					Deque Implementation
*/


// Precomputes Jacobsthal numbers up to a given maximum size and stores them in a deque cache
// Jacobsthal numbers are used to determine optimal insertion order in merge-insert sort
// Formula: J(n) = J(n-1) + 2*J(n-2), starting with J(0)=0 and J(1)=1
// This version uses deque instead of vector for potential performance benefits with large sequences
void PmergeMe::precomputeJacobsthalDeque(int max_size)
{
    jacobsthal_cache_deq.clear();
    jacobsthal_cache_deq.push_back(0);  // J(0)
    jacobsthal_cache_deq.push_back(1);  // J(1)
        
    // Generate numbers until we exceed the required maximum size
    while (jacobsthal_cache_deq.back() < max_size)
    {
        int next = jacobsthal_cache_deq.back() + 2 * jacobsthal_cache_deq[jacobsthal_cache_deq.size() - 2];
        jacobsthal_cache_deq.push_back(next);
    }
}

// Finds the index of a given value in a deque (chain)
// Returns -1 if the value is not found
// Uses linear search since the chain may not be fully sorted during insertion process
// Deque version provides similar functionality to vector version but with deque containers
int PmergeMe::getIndexInChainDeque(const std::deque<int>& chain, int value) const
{
    for (size_t i = 0; i < chain.size(); ++i)
    {
        if (chain[i] == value)
            return i;
    }
    return -1;
}

// Generates an optimal insertion order for merge-insert sort using Jacobsthal numbers
// This deque version mirrors the vector implementation but uses deque containers
// The order minimizes comparisons during binary insertion by grouping elements according to Jacobsthal numbers
std::deque<int> PmergeMe::buildOptimalInsertionOrderDeque(int numPairs) const
{
    std::deque<int> order;
    if (numPairs <= 1)
        return order;
        
    // Extract relevant Jacobsthal numbers from deque cache (starting from index 3)
    std::deque<int> jacobSequence;
    for (size_t k = 3; k < jacobsthal_cache_deq.size() && jacobsthal_cache_deq[k] <= numPairs; ++k)
        jacobSequence.push_back(jacobsthal_cache_deq[k]);
    
    // Track which indices have been scheduled for insertion
    std::deque<bool> inserted(numPairs, false);
    
    // Process each Jacobsthal number to create insertion groups
    for (size_t i = 0; i < jacobSequence.size(); ++i)
    {
        int groupEnd = jacobSequence[i];
        int groupStart = (i == 0) ? 2 : jacobSequence[i-1] + 1;
        
        // Insert group elements in reverse order (optimal for binary insertion)
        for (int idx = groupEnd; idx >= groupStart; --idx)
        {
            if (idx <= numPairs && !inserted[idx-1])
            {
                order.push_back(idx - 1); // Convert to 0-based index
                inserted[idx-1] = true;
            }
        }
    }
    
    // Add any remaining unscheduled indices (those not part of Jacobsthal groups)
    for (int i = 1; i < numPairs; ++i) // Start from 1 since we skip b_1
    {
        if (!inserted[i])
            order.push_back(i);
    }
        
    return order;
}

// Performs binary insertion of a value into a deque chain with a specified search limit
// The search limit restricts the upper bound of the binary search range
// Deque version provides similar functionality to vector version but with deque operations
void PmergeMe::BinaryInsertDeque(std::deque<int>& chain, int value, int searchLimit)
{
    // Handle edge case where search limit is at the beginning
    if (searchLimit <= 0)
    {
        chain.insert(chain.begin(), value);
        return;
    }

    // Calculate the actual high index, ensuring we don't exceed chain bounds
    int actualHigh = std::min(searchLimit, static_cast<int>(chain.size())) - 1;
    if (actualHigh < 0)
    {
        chain.insert(chain.begin(), value);
        return;
    }

    // Binary search within the limited range
    int left = 0;
    int right = actualHigh;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        comparisons++;
        if (value < chain[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    // Insert at the found position
    chain.insert(chain.begin() + left, value);
}

// Specialized sorting function for small input sizes (0-5 elements) using deque
// Uses optimized comparison sequences to minimize the number of comparisons
// For sizes 4 and 5, implements a simplified version of merge-insert sort with deque
std::deque<int> PmergeMe::sortSmallCasesDeque(const std::deque<int>& arr)
{
    switch (arr.size())
    {
        case 0:
        case 1:
            return arr;
                
        case 2:
        {
            std::deque<int> result = arr;
            comparisons++;
            if (result[0] > result[1])
                std::swap(result[0], result[1]);
            return result;
        }
            
        case 3:
        {
            std::deque<int> result = arr;
            // Sort first two elements
            comparisons++;
            if (result[0] > result[1])
                std::swap(result[0], result[1]);            
            // Insert third element in correct position
            comparisons++;
            if (result[1] > result[2])
            {
                std::swap(result[1], result[2]);
                    
                comparisons++;
                if (result[0] > result[1])
                    std::swap(result[0], result[1]);
            }
            return result;
        }
            
        case 4:
        {
            std::deque<int> result = arr;
                
            // Sort first pair
            comparisons++;
            if (result[0] > result[1])
                std::swap(result[0], result[1]);
            // Sort second pair
            comparisons++;
            if (result[2] > result[3])
                std::swap(result[2], result[3]);
                
            // Ensure first pair has smaller maximum
            comparisons++;
            if (result[1] > result[3])
            {
                std::swap(result[0], result[2]);
                std::swap(result[1], result[3]);
            }
                
            // Build initial chain with three elements
            std::deque<int> chain;
            chain.push_back(result[0]);  // smallest element
            chain.push_back(result[1]);  // smaller maximum
            chain.push_back(result[3]);  // largest element
                
            // Insert the remaining element with bounded binary search
            BinaryInsertDeque(chain, result[2], 2);    
            return chain;
        }
            
        case 5:
        {
            std::deque<int> v(arr);

            // Step 1: Sort first pair (a,b)
            comparisons++;
            if (v[0] > v[1])
                std::swap(v[0], v[1]);

            // Step 2: Sort second pair (c,d)
            comparisons++;
            if (v[2] > v[3])
                std::swap(v[2], v[3]);

            // Step 3: Ensure first pair has smaller maximum
            comparisons++;
            if (v[1] > v[3])
            {
                std::swap(v[0], v[2]);
                std::swap(v[1], v[3]);
            }

            // Step 4: Insert fifth element (e) relative to known elements
            comparisons++;
            if (v[4] < v[1])
            {
                // e is less than b
                comparisons++;
                if (v[4] < v[0])
                {
                    // e is smallest element
                    std::deque<int> chain;
                    chain.push_back(v[4]);
                    chain.push_back(v[0]);
                    chain.push_back(v[1]);
                    BinaryInsertDeque(chain, v[2], chain.size());
                    chain.push_back(v[3]);
                    return chain;
                }
                else
                {
                    // e is between a and b
                    std::deque<int> chain;
                    chain.push_back(v[0]);
                    chain.push_back(v[4]);
                    chain.push_back(v[1]);
                    BinaryInsertDeque(chain, v[2], chain.size());
                    chain.push_back(v[3]);
                    return chain;
                }
            }
            else
            {
                // e is greater than or equal to b
                comparisons++;
                if (v[4] < v[3])
                {
                    // e is between b and d
                    std::deque<int> chain;
                    chain.push_back(v[0]);
                    chain.push_back(v[1]);
                    chain.push_back(v[4]);
                    BinaryInsertDeque(chain, v[2], chain.size());
                    chain.push_back(v[3]);
                    return chain;
                }
                else
                {
                    // e is largest element
                    std::deque<int> chain;
                    chain.push_back(v[0]);
                    chain.push_back(v[1]);
                    chain.push_back(v[3]);
                    BinaryInsertDeque(chain, v[2], chain.size());
                    chain.push_back(v[4]);
                    return chain;
                }
            }
        }
    }
        
    return arr;
}
    
// Main merge-insert sort implementation for deques
// Uses a recursive divide-and-conquer approach with optimal insertion ordering
// Follows the Ford-Johnson algorithm's merge-insertion sort strategy using deque containers
std::deque<int> PmergeMe::mergeInsertSortDeque(const std::deque<int>& chain)
{
    // Base case: use optimized small case sorting
    if (chain.size() <= 5)
        return sortSmallCasesDeque(chain);
        
    // Step 1: Form pairs and sort them internally
    std::deque<std::pair<int, int> > pairs;
    std::deque<int> leftovers;
        
    for (size_t i = 0; i + 1 < chain.size(); i += 2)
    {
        comparisons++;
        if (chain[i] > chain[i + 1])
            pairs.push_back(std::make_pair(chain[i], chain[i + 1]));
        else
            pairs.push_back(std::make_pair(chain[i + 1], chain[i]));
    }
        
    // Handle odd-sized input
    if (chain.size() % 2 != 0)
        leftovers.push_back(chain.back());
        
    if (pairs.empty())
        return leftovers;
        
    // Step 2: Recursively sort the larger elements of each pair
    std::deque<int> largerElements;
    for (size_t i = 0; i < pairs.size(); ++i)
        largerElements.push_back(pairs[i].first);
        
    std::deque<int> sortedLarger = mergeInsertSortDeque(largerElements);
        
    // Step 3: Rebuild pairs in the order determined by the sorted larger elements
    std::deque<std::pair<int, int> > sortedPairs;
    for (size_t i = 0; i < sortedLarger.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == sortedLarger[i])
            {
                sortedPairs.push_back(pairs[j]);
                break;
            }
        }
    }
    
    // Create pend chain (smaller elements) in the order of their paired larger elements
    std::deque<int> pendChain;
    for (size_t i = 0; i < sortedPairs.size(); ++i)
        pendChain.push_back(sortedPairs[i].second);
    
    // Add leftover element to pend chain if it exists
    if (!leftovers.empty())
        pendChain.push_back(leftovers[0]);
        
    // Initialize main chain with first pend element (b_1)
    std::deque<int> mainChain;
    mainChain.push_back(pendChain[0]);
        
    // Add all sorted larger elements to main chain
    for (size_t i = 0; i < sortedLarger.size(); ++i)
        mainChain.push_back(sortedLarger[i]);
        
    // Step 4: Insert remaining pend elements using optimal Jacobsthal order
    std::deque<int> insertionOrder = buildOptimalInsertionOrderDeque(pendChain.size());
        
    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        int idx = insertionOrder[i];
        if (idx < 0 || idx >= static_cast<int>(pendChain.size()))
            continue;
        if (idx == 0)
            continue; // Skip b_1 as it's already inserted
            
        int valueToInsert = pendChain[idx];
        
        // Calculate search limit based on the paired element's position
        int searchLimit = mainChain.size(); // Default to full chain
        
        if (idx < static_cast<int>(sortedPairs.size()))
        {
            // Find the paired larger element for this pend element
            int pairedElement = sortedPairs[idx].first;
            searchLimit = getIndexInChainDeque(mainChain, pairedElement);
        }
            
        BinaryInsertDeque(mainChain, valueToInsert, searchLimit);
    }
        
    return mainChain;
}
    
// Public interface for sorting the input deque
// Initializes comparison count and selects appropriate sorting strategy
std::deque<int> PmergeMe::sortDeque()
{
    comparisons = 0;

    if (inputDeq.size() <= 5)
        return sortSmallCasesDeque(inputDeq);

    // Precompute Jacobsthal numbers for optimal insertion order
    precomputeJacobsthalDeque(inputDeq.size());
    return mergeInsertSortDeque(inputDeq);
}
