#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <sstream>
#include <cctype>

class BitcoinExchange
{
	private:
	std::map<std::string, float> _data;

	


	public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange& operator = (const BitcoinExchange &src);
	~BitcoinExchange();

	void setDataBase();
	void processInput(const std::string file);

	void checkGlobalFormat(std::string line);

	void checkDate(std::string line);



	/******EXCEPTIONS********/

	class ErrorOpeningFileException : public std::exception
	{
		public:
		const char* what(void) const throw();
	};

	class ErrorInputFileFormatException : public std::exception
	{
		public:
		const char* what(void) const throw();
	};

	class ErrorDateFormatException : public std::exception
	{
		public:
		const char* what(void) const throw();
	};

};

#endif
