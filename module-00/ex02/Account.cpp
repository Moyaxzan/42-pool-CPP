#include <ctime>
#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void) {
	time_t	currTime = time(0);
	tm		*infTime = localtime(&currTime);

	std::cout << "[" << infTime->tm_year + 1900; //tm_year : years since 1900
	if (infTime->tm_mon < 9) {					 // < 9 because we +1 the month [0-11]
		std::cout << "0";
	}
	std::cout << infTime->tm_mon + 1;
	if (infTime->tm_mday < 10) {
		std::cout << "0";
	}
	std::cout << infTime->tm_mday << "_";
	if (infTime->tm_hour < 10) {
		std::cout << "0";
	}
	std::cout << infTime->tm_hour;
	if (infTime->tm_min < 10) {
		std::cout << "0";
	}
	std::cout << infTime->tm_min;
	if (infTime->tm_sec < 10) {
		std::cout << "0";
	}
	std::cout << infTime->tm_sec << "]";
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit) {
	_totalAmount += initial_deposit;
	this->_amount = initial_deposit;
	_totalNbDeposits = 0;
	_totalNbWithdrawals = 0;
	this->_nbWithdrawals = 0;
	this->_nbDeposits = 0;
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << " index" << this->_accountIndex;
	std::cout << ";amount:" << initial_deposit;
	std::cout << ";created" << std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;
}

int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}
int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

void	Account::makeDeposit(int deposit) {
	_totalNbDeposits += 1;
	this->_nbDeposits += 1;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	_totalAmount += deposit;
	this->_amount += deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (withdrawal > this->_amount) {
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_totalNbWithdrawals += 1;
	this->_nbWithdrawals += 1;
	_totalAmount -= withdrawal;
	this->_amount -= withdrawal;
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int	Account::checkAmount(void) const {
	return (this->_amount);
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
