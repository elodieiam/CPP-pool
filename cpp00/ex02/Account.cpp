/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:55:41 by elrichar          #+#    #+#             */
/*   Updated: 2024/03/06 13:02:14 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <string>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp( void )
{
	time_t	now = time(0);

	tm	*info = localtime(&now);
	std::cout << "[" << info->tm_year + 1900;
	if (info->tm_mon < 10)
		std::cout << "0";
	std::cout << info->tm_mon + 1; 
	if (info->tm_mon < 10)
		std::cout << "0";
	std::cout << info->tm_mday << "_";
	if (info->tm_hour < 10)
		std::cout << "0";
	std::cout << info->tm_hour;
	if (info->tm_min < 10)
		std::cout << "0";
	 std::cout << info->tm_min;
	 if (info->tm_sec < 10)
		std::cout << "0";
	std::cout << info->tm_sec << "]";
}

int	Account::getNbAccounts( void ){ return (_nbAccounts); }

int	Account::getTotalAmount( void ) { return (_totalAmount);}

int	Account::getNbDeposits( void ){ return (_totalNbDeposits);}

int	Account::getNbWithdrawals( void ){return (_totalNbWithdrawals);}
	
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit )
	{
		_nbAccounts++;
		_totalAmount += initial_deposit;
		this->_amount = initial_deposit;
		this->_accountIndex = _nbAccounts - 1;
		this->_nbDeposits = 0;
		this->_nbWithdrawals = 0;
		_displayTimestamp();
		std::cout << " index:" << this->_accountIndex;
		std::cout <<";amount:" << initial_deposit << ";created" <<std::endl; 
	}
	
Account::~Account( void )
	{
		_displayTimestamp();
		std::cout << " index:" << this->_accountIndex;
		std::cout << ";amount:" << this->_amount;
		std::cout << ";closed" << std::endl;
	}

void	Account::makeDeposit( int deposit )
{
	_totalNbDeposits++;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	this->_amount += deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
	
}
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (withdrawal <= this->_amount)
	{
		_totalNbWithdrawals++;
		this->_nbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << ";withdrawal:" << withdrawal;
		this->_amount -= withdrawal;
		std::cout << ";amount:" << checkAmount();
		std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
	std::cout << ";withdrawal:refused" << std::endl;
	return (false);
}

int		Account::checkAmount( void ) const { return (this->_amount);}
	
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}