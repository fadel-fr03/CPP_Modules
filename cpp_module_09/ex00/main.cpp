#include "incs/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
	
    const std::string dbFile  = "data.csv";
    const std::string inFile  = argv[1];

    BitcoinExchange btc;
	btc.processInputFile(dbFile, inFile);
    return 0;
}
