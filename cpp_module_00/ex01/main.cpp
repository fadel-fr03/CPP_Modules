#include "incs/PhoneBook.hpp"

static int      is_valid_number(std::string number)
{
    int i;

    i = 0;
    while (number[i])
    {
        if (number[i] == ' ')
        {
            i++;
            continue;
        }
        if (number[i] < '0' || number[i] > '9')
                return (0);
        i++;
    }
    return (1);
}

int main()
{
	PhoneBook	phonebook;
	std::string	data[5];
	std::string	input;
	int 		index;

	while (1)
	{
		std::cout << "PhoneBook>";
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			std::cout << "\nEnter Contact Information" << std::endl;
			std::cout << "First Name: ";
			std::getline(std::cin, data[0]);
			std::cout << "Last Name: ";
			std::getline(std::cin, data[1]);
			std::cout << "NickName: ";
			std::getline(std::cin, data[2]);
			do
			{
				std::cout << "Phone Number: ";
				std::getline(std::cin, data[3]);
				if (is_valid_number(data[3]))
					break;
				std::cout << "Please input a valid number" << std::endl;
			} while (!is_valid_number(data[3]));
			std::cout << "Darkest Secret: ";
			std::getline(std::cin, data[4]);
			phonebook.add_contact(data);
			std::cout << "Contact Added Successfully!\n" << std::endl;
		}
		else if (input == "SEARCH")
		{
			phonebook.display_phonebook();
			std::cout << "\nInsert Index: ";
			std::cin >> index;
			if (std::cin.fail() || index < 0 || index >= phonebook.get_size())
			{
				std::cout << "Invalid Index!\n" << std::endl;
				std::cin.clear();
				std::getline(std::cin, input);
				continue;
			}
			phonebook.display_contact(index);
			std::cin.clear();
			std::getline(std::cin, input);
			continue;
		}
		else if (input == "EXIT")
			break;
		else
			std::cout << "Invalid command\n" << std::endl;
	}
}