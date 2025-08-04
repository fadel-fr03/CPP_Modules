#include "../incs/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &){}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
    return *this;
}

void ScalarConverter::convert(std::string const &literal)
{
    // char literal (with quotes)
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
    {
        char c = literal[1];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }

    // single char without quotes (also valid)
    if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }

    // float
    char *end;
    float f = std::strtof(literal.c_str(), &end);
    if ((*end == 'f' && *(end + 1) == '\0') || literal == "-inff" || literal == "+inff" || literal == "nanf")
    {
        if (std::isnan(f) || std::isinf(f))
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(f) << std::endl;
            return;
        }

        if (f < 0 || f > 127)
            std::cout << "char: impossible" << std::endl;
        else if (!std::isprint(static_cast<int>(f)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

        if (f < INT_MIN || f > INT_MAX)
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(f) << std::endl;

        if (f == static_cast<int>(f))
            std::cout << "float: " << f << ".0f" << std::endl;
        else
            std::cout << "float: " << f << "f" << std::endl;

        if (static_cast<double>(f) == static_cast<int>(f))
            std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
        else
            std::cout << "double: " << static_cast<double>(f) << std::endl;
        return;
    }

    // double
    double d = std::strtod(literal.c_str(), &end);
    if ((*end == '\0') || literal == "-inf" || literal == "+inf" || literal == "nan")
    {
        if (std::isnan(d) || std::isinf(d))
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
            return;
        }

        if (d < 0 || d > 127)
            std::cout << "char: impossible" << std::endl;
        else if (!std::isprint(static_cast<int>(d)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

        if (d < INT_MIN || d > INT_MAX)
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;

        if (static_cast<float>(d) == static_cast<int>(d))
            std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;

        if (d == static_cast<int>(d))
            std::cout << "double: " << d << ".0" << std::endl;
        else
            std::cout << "double: " << d << std::endl;
        return;
    }

    // int
    long value = std::strtol(literal.c_str(), &end, 10);
    if (*end == '\0' && value <= INT_MAX && value >= INT_MIN)
    {
        int i = static_cast<int>(value);

        if (i < 0 || i > 127)
            std::cout << "char: impossible" << std::endl;
        else if (!std::isprint(i))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
        return;
    }

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;

    return;
}
