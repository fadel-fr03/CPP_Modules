#include "MutantStack.hpp"

void printDivider(const std::string &label)
{
	std::cout << "\n=== " << label << " ===" << std::endl;
}

int main()
{
	MutantStack<int> mstack;

	printDivider("Basic Operations");
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	mstack.push(-6);
	mstack.push(-21);
	mstack.push(98);
	mstack.push(101);
	mstack.push(1582);
	mstack.push(55);

	printDivider("Iterator (non-const)");
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	for (; it != ite; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	printDivider("Const Iterator");
	const MutantStack<int> const_mstack = mstack;
	MutantStack<int>::const_iterator cit = const_mstack.begin();
	MutantStack<int>::const_iterator cite = const_mstack.end();
	for (; cit != cite; ++cit)
		std::cout << *cit << " ";
	std::cout << std::endl;

	printDivider("Reverse Iterator");
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	++rite;
	--rite;
	for (; rit != rite; ++rit)
		std::cout << *rit << " ";
	std::cout << std::endl;

	printDivider("Const Reverse Iterator");
	MutantStack<int>::const_reverse_iterator crit = const_mstack.rbegin();
	MutantStack<int>::const_reverse_iterator crite = const_mstack.rend();
	for (; crit != crite; ++crit)
		std::cout << *crit << " ";
	std::cout << std::endl;

	printDivider("Copy Constructor");
	MutantStack<int> copyStack(mstack);
	for (MutantStack<int>::iterator it = copyStack.begin(); it != copyStack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	printDivider("Assignment Operator");
	MutantStack<int> assignedStack;
	assignedStack = mstack;
	for (MutantStack<int>::iterator it = assignedStack.begin(); it != assignedStack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	printDivider("Comparison with std::list");
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	lst.push_back(-6);
	lst.push_back(-21);
	lst.push_back(98);
	lst.push_back(101);
	lst.push_back(1582);
	lst.push_back(55);

	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	return 0;
}
