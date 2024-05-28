#include "BitcoinExchange.hpp"

/**Regular functions**/

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	_data = src._data;
}

BitcoinExchange& BitcoinExchange::operator = (const BitcoinExchange &src)
{
	if (this != &src)
		_data = src._data;
	return (*this);
}
BitcoinExchange::~BitcoinExchange() 
{
	_data.clear();
}


/****Program functions*******/

void BitcoinExchange::setDataBase()
{
	std::ifstream ifs("data.csv");
	std::string line;
	std::string date;
	float rate;
	
	if (!ifs.is_open())
		throw BitcoinExchange::ErrorOpeningFileException();
	
	while(std::getline(ifs, line))
	{
		std::istringstream stream(line);

		date = line.erase(10);
		stream.ignore(11);
		stream >> rate;
		_data.insert(std::pair<std::string, float>(date, rate));
	}
}

void BitcoinExchange::processInput(const std::string file)
{
	std::ifstream ifs(file.c_str());
	std::string line;
	std::string date;

	std::getline(ifs, line);

	if (!ifs.is_open())
		throw BitcoinExchange::ErrorOpeningFileException();
	if (line != "date | value")
		throw BitcoinExchange::BadInputException();
	while(std::getline(ifs, line))
	{
		try 
		{
			checkGlobalFormat(line);
			checkDate(line);
			float value = checkValue(line);
			convert(line, value);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what();
			std::string name = e.what();
			if (name == "bad input")
				std::cerr << " => " << line;
			std::cerr << std::endl;
		}
	}
}

/***Conversion functions******/

void BitcoinExchange::convert(std::string line, float value)
{
	std::string date = line.erase(10);
	std::map<std::string, float>::iterator it;
	it = _data.lower_bound(date);
	if (it->first != date && it != _data.begin())
		it--;
	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	
}


/***Input check functions*****/

float BitcoinExchange::checkValue(std::string line)
{
	std::string	value = line.erase(0, 13);

	if (!line.size())
		throw BitcoinExchange::BadInputException();
	int is_float = 0;
	int sign = 0;
	
	if (line[0] == '+' || line[0] == '-')
	{
		sign = 1;
		if (!line[1])
			throw BitcoinExchange::BadInputException();
	}
	for (unsigned int i = 0; i < line.size(); i++)
	{
		if (sign == 1 && i == 0)
			continue ;
		if (line[i] == '.')
			is_float++;
		if (!isdigit(line[i]) && line[i] != '.')
			throw BitcoinExchange::BadInputException();
	}
	if (is_float != 0 && is_float != 1)
		throw BitcoinExchange::BadInputException();
	
	std::istringstream stream(value);
	float nbf;
	stream >> nbf;
	if (nbf < 0.0)
		throw BitcoinExchange::NumberTooLowException();
	if (nbf > 1000.0)
		throw BitcoinExchange::NumberTooHighException();
	return (nbf);
}

void BitcoinExchange::checkDate(std::string line)
{
	std::string	date = line.erase(10);
	std::string str;
	

	str = line.substr(0, 4);
	std::istringstream value_year(str);
	int year;
	value_year >> year;
	if (year < 2009 || year > 2022)
		throw BitcoinExchange::BadInputException();
	
	str = line.substr(5, 2);
	std::istringstream value_month(str);
	int month;
	value_month >> month;
	if (month < 1 || month > 12)
		throw BitcoinExchange::BadInputException();

	str = line.substr(8, 2);
	std::istringstream value_day(str);
	int day;
	value_day >> day;
	if (day < 1 || day > 31)
		throw BitcoinExchange::BadInputException();

	if ((year == 2022 && month > 3) || (year == 2022 && month == 3 && (day == 30 || day == 31)))
		throw BitcoinExchange::BadInputException();

	if (year < 2009 && (month >= 1 && month <= 12) && (day >= 1 && day <= 31))
		throw BitcoinExchange::BadInputException();

	if (year == 2009 && month == 1 && day < 2)
		throw BitcoinExchange::BadInputException();

	if (year % 4 == 0 && month == 2 && day > 29)
		throw BitcoinExchange::BadInputException();

	if (year % 4 != 0 && month == 2 && day > 28)
		throw BitcoinExchange::BadInputException();

	if (month % 2 == 0 && day > 30)
		throw BitcoinExchange::BadInputException();
}

void BitcoinExchange::checkGlobalFormat(std::string line)
{
	if (!line.size() || line.size() < 14)
		throw BitcoinExchange::BadInputException();
	if (line[4] != '-' || line[7] != '-' || line[10] != ' ' || line[12] != ' ' || line[11] != '|')
		throw BitcoinExchange::BadInputException();
	for (int i = 0; i < 11; i++)
	{
		if (!isdigit(line[i]) && ((i >= 0 && i <= 3) ||  i == 5 || i == 6 || i == 8 || i == 9))
			throw BitcoinExchange::BadInputException();
	}
}

/*****EXCEPTIONS******/

const char *BitcoinExchange::ErrorOpeningFileException::what(void) const throw()
{
	return ("could not open file.");
}


const char *BitcoinExchange::NumberTooLowException::what(void) const throw()
{
	return ("not a positive number.");
}

const char *BitcoinExchange::NumberTooHighException::what(void) const throw()
{
	return ("too large a number.");
}

const char *BitcoinExchange::BadInputException::what(void) const throw()
{
	return ("bad input");
}



