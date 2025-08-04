#include "../incs/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &to_copy)
{
    (void)to_copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &to_copy)
{
    (void)to_copy;
    return *this;
}


bool BitcoinExchange::isValidDateLogic(const std::string &date)
{
    int days_in_month[12] = { 31, 28, 31, 30, 31, 30,
                              31, 31, 30, 31, 30, 31 };

    std::stringstream ss(date);
    std::string year_str, month_str, day_str;

    if (!(std::getline(ss, year_str, '-') &&
          std::getline(ss, month_str, '-') &&
          std::getline(ss, day_str)))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }

    int year = std::atoi(year_str.c_str());
    int month = std::atoi(month_str.c_str());
    int day = std::atoi(day_str.c_str());

    if (year < 0 || month < 1 || month > 12)
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }

    if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
        days_in_month[1] = 29;

    if (day < 1 || day > days_in_month[month - 1])
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }

    return true;
}


bool BitcoinExchange::isValidDateFormat(const std::string &date)
{
    if (date.length() < 8 || date.length() > 10)
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }

    std::stringstream ss(date);
    std::string year_str, month_str, day_str;

    if (!(std::getline(ss, year_str, '-') &&
          std::getline(ss, month_str, '-') &&
          std::getline(ss, day_str)))
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }

    if (year_str.length() != 4 || month_str.length() == 0 || day_str.length() == 0)
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }

    for (size_t i = 0; i < year_str.length(); ++i)
        if (!std::isdigit(year_str[i]))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            return false;
        }

    for (size_t i = 0; i < month_str.length(); ++i)
        if (!std::isdigit(month_str[i]))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            return false;
        }

    for (size_t i = 0; i < day_str.length(); ++i)
        if (!std::isdigit(day_str[i]))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            return false;
        }

    return true;
}


bool BitcoinExchange::isValidValue(const std::string &valueStr, float &value)
{
	if (valueStr.empty())
    {
        std::cerr << "Error: bad input => " << valueStr << std::endl;
        return false;
    }
	if (valueStr.find("0x") != std::string::npos || 
        valueStr.find("0X") != std::string::npos)
    {
        std::cerr << "Error: bad input => " << valueStr << std::endl;
        return false;
    }

    char *end;
	value = std::strtof(valueStr.c_str(), &end);

	if (!(*end == '\0') && !(*end == 'f' && *(end + 1) == '\0') && !(*end == 'F' && *(end + 1) == '\0'))
	{
		std::cerr << "Error: bad input => " << valueStr << std::endl;
        return false;
    }

    if (value < 0.0)
    {
        std::cerr << "Error: not a positive number => " << value << std::endl;
        return false;
    }

    if (value > 1000.0)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }

    return true;
}

std::string BitcoinExchange::trim(const std::string &str)
{
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == std::string::npos)
		return "";

    size_t end = str.find_last_not_of(" \t\n\r");
    return str.substr(start, end - start + 1);
}

void BitcoinExchange::processLine(const std::string &line, const std::map<std::string, float> &db)
{
    std::stringstream ss(line);
    std::string date;
    std::string str_num;

    if (std::getline(ss, date, '|') && std::getline(ss, str_num))
    {
        date = trim(date);
        str_num = trim(str_num);

        if (!isValidDateFormat(date) || !isValidDateLogic(date))
        {
            return;
        }

        float value;

        if (!isValidValue(str_num, value))
        {
            return;
        }

        std::map<std::string, float>::const_iterator it = db.lower_bound(date);

        if (it == db.end() || it->first > date)
        {
            if (it != db.begin())
                --it;
        }

        if (it == db.begin() && it->first > date)
        {
            std::cerr << "Error: no valid date less or equal found => " << date << std::endl;
            return;
        }

        float result = value * it->second;

        std::cout << date << " => " << value << " = " << result << std::endl;

    }
	else
	{
		std::cerr << "Error: bad input => " << line << std::endl;
	}
}

std::map<std::string, float> BitcoinExchange::getDbData(const std::string &fileName)
{
	std::map<std::string, float> db;
	std::ifstream file(fileName.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return db;
	}

	std::string line;
	std::getline(file, line); // Skip header line

	while (std::getline(file, line))
	{
		std::string date;
		std::string str_val;
		std::stringstream ss(line);

		if (std::getline(ss, date, ',') && std::getline(ss, str_val))
		{
			char *end;
			float value = std::strtof(str_val.c_str(), &end);

			if ((*end == '\0') || (*end == 'f' && *(end + 1) == '\0') || (*end == 'F' && *(end + 1) == '\0'))
			{
				db[date] = value;
			}
			else
			{
				std::cerr << "Warning: invalid value on line: " << line << std::endl;
			}
		}
		else
		{
			std::cerr << "Warning: invalid line format: " << line << std::endl;
		}
	}

	file.close();

	if (db.empty())
    {
        std::cerr << "Error: empty or invalid database file." << std::endl;
    }

	return db;
}

void BitcoinExchange::processInputFile(const std::string dbFile, const std::string &inFile)
{
    std::map<std::string, float> db;
	std::ifstream file(inFile.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: could not open input file." << std::endl;
		return;
	}

    db = getDbData(dbFile);

    std::string line;
	std::getline(file, line); // Skip header line
    if (trim(line) != "date | value")
    {
        std::cerr << "Error: Invalid input file header." << std::endl;
        return;
    }

    while (std::getline(file, line))
    {
        // empty line
        if (line.empty())
        {
            std::cerr << "Error: Empty line in input file." << std::endl;
            continue;
        }

        processLine(line, db);
    }
}
