#include "incs/processLine.hpp"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Correct usage: ./replacement <filename> <str to replace> "
                     "<str to write>\n";
        return 1;
    }

    if (std::string(argv[2]).empty())
    {
        std::cerr << "Error: string to replace must not be empty\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file)
    {
        std::cerr << "Error: cannot open input file '" << argv[1] << "'\n";
        return 1;
    }

    std::string name = argv[1];
	name.append(".replace");
	std::ofstream new_file(name.c_str());
    if (!new_file)
    {
        std::cerr << "Error: cannot create output file '" << name << "'\n";
        return 1;
    }

    std::string str, line;
    while (std::getline(file, str))
    {
        line = process_line(argv, str);
        new_file << line << '\n';
    }

    return 0;
}
