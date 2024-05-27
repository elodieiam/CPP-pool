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
		throw ErrorOpeningFileException();
	
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
		throw ErrorOpeningFileException();
	if (line != "date | value")
		throw ErrorInputFileFormatException();
	while(std::getline(ifs, line))
	{
		try 
		{
			checkGlobalFormat(line);
			checkDate(line);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			break ;
		}
	}

}

/***Input check functions*****/

void BitcoinExchange::checkDate(std::string line)
{
	std::string	date = line.erase(10);
	std::string str;
	

	str = line.substr(0, 4);
	std::istringstream value_year(str);
	int year;
	value_year >> year;
	if (year < 2009 || year > 2022)
		throw ErrorDateFormatException();
	
	str = line.substr(5, 2);
	std::istringstream value_month(str);
	int month;
	value_month >> month;
	if (month < 1 || month > 12)
		throw ErrorDateFormatException();

	str = line.substr(8, 2);
	std::istringstream value_day(str);
	int day;
	value_day >> day;
	if (day < 1 || day > 31)
		throw ErrorDateFormatException();

	if ((year == 2022 && month > 3) || (year == 2022 && month == 3 && (day == 30 || day == 31)))
		throw ErrorDateFormatException();

	if (year % 4 == 0 && month == 2 && day > 29)
		throw ErrorDateFormatException();

	if (year % 4 != 0 && month == 2 && day > 28)
		throw ErrorDateFormatException();

	if (month % 2 == 0 && day > 30)
		throw ErrorDateFormatException();
}

void BitcoinExchange::checkGlobalFormat(std::string line)
{
	if (!line.size() || line.size() < 14)
		throw ErrorInputFileFormatException();
	if (line[4] != '-' || line[7] != '-' || line[10] != ' ' || line[12] != ' ' || line[11] != '|')
		throw ErrorInputFileFormatException();
	for (int i = 0; i < 11; i++)
	{
		if (!isdigit(line[i]) && ((i >= 0 && i <= 3) || i == 5 || i == 6 || i == 8 || i == 9))
			throw ErrorInputFileFormatException();
	}
}

/*****EXCEPTIONS******/

const char *BitcoinExchange::ErrorOpeningFileException::what(void) const throw()
{
	return ("[ERROR] when opening file");
}

const char *BitcoinExchange::ErrorInputFileFormatException::what(void) const throw()
{
	return ("[ERROR] in input file format");
}

const char *BitcoinExchange::ErrorDateFormatException::what(void) const throw()
{
	return ("[ERROR] in date format");
}

