// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United            	      //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <stdlib.h>



int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
	time_t timer = time(0);
	tm *time = localtime(&timer);
	 
	std::cout << "[" << time->tm_year + 1900 << time->tm_mon << time->tm_mday << "_" << time->tm_hour << time->tm_min << time->tm_sec << "] ";
}

Account::Account(int init)
{
	this->_amount = init;
	this->_accountIndex = this->_nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_totalAmount += init;
	this->_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "amount:" << this->_amount << ";" << "created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "amount:" << this->_amount << ";" << "closed" << std::endl;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";" << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

int		Account::checkAmount() const
{
	return (this->_amount);
}

void	Account::makeDeposit( int deposit )
{
	int old = this->_amount;

	_displayTimestamp();
	this->_amount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	std::cout << "index:" << this->_accountIndex << ";" << "p_amount:" << old << ";"
		<< "deposit:" << deposit << ";" << "amount:" << this->_amount << ";"
		<< "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int old = this->_amount;

	_displayTimestamp();
	if (withdrawal > old)
	{
		std::cout << "index:" << this->_accountIndex << ";" << "p_amount:" << old << ";"
		<< "withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		this->_totalNbWithdrawals++;
		std::cout << "index:" << this->_accountIndex << ";" << "p_amount:" << old << ";"
			<< "withdrawal:" << withdrawal << ";" << "amount:" << this->_amount << ";"
			<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}


/*
	GETTERS
*/
int	Account::getNbAccounts()
{
	return (_nbAccounts);
}
int	Account::getTotalAmount()
{
	return(_totalAmount);
}
int	Account::getNbDeposits()
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals() << std::endl;
}
