#ifndef BTC_HPP
# define BTC_HPP

#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

class BitcoinExchange
{
	private:
		BitcoinExchange(const BitcoinExchange &to_copy);
		BitcoinExchange &operator=(const BitcoinExchange &to_copy);

		static bool isValidDateFormat(const std::string &date);
		static bool isValidDateLogic(const std::string &date);
		static bool isValidValue(const std::string &valueStr, float &value);
		static std::string trim(const std::string &str);
		static void processLine(const std::string &line, const std::map<std::string, float> &db);
		static std::map<std::string, float> getDbData(const std::string &fileName);

	public:
		BitcoinExchange();
		~BitcoinExchange();
		void processInputFile(const std::string dbFile, const std::string &inFile);
};

#endif