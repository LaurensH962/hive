#include "Account.hpp"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

int Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int Account::getNbAccounts( void )
{
    return (_nbAccounts);
}


void	Account::_displayTimestamp( void )
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm* tm_ptr = std::localtime(&now_time);
    std::cout << "["
              << std::put_time(tm_ptr, "%Y%m%d_%H%M%S")
              << "] ";
}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "created"
                << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "closed"
                << std::endl;
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout   << "accounts:" << _nbAccounts << ";"
                << "total:" << _totalAmount << ";"
                << "deposits:" << _totalNbDeposits << ";"
                << "withdrawals:" << _totalNbWithdrawals
                << std::endl;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "deposits:" << _nbDeposits << ";"
                << "withdrawals:" << _nbWithdrawals
                << std::endl;
}


void	Account::makeDeposit( int deposit )
{
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex << ";"
                << "p_amount:" << _amount << ";"
                << "deposit:" << deposit << ";"
                << "amount:" << _amount << ";"
                << "deposits:" << _nbDeposits << ";"
                << "withdrawals:" << _nbWithdrawals
                << std::endl;
}


bool	Account::makeWithdrawal( int withdrawal )
{
    if (checkAmount() >= withdrawal)
    {
        _displayTimestamp();
        std::cout   << "index:" << _accountIndex << ";"
                    << "p_amount:" << _amount << ";"
                    << "withdrawal:" << withdrawal << ";";
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout   << "amount:" << _amount << ";"
                    << "deposits:" << _nbDeposits << ";"
                    << "withdrawals:" << _nbWithdrawals
                    << std::endl; 
        return (true);
    }
    else
    {
        _displayTimestamp();
        std::cout   << "index:" << _accountIndex << ";"
                    << "p_amount:" << _amount << ";"
                    << "withdrawal:" << "refused" << ";"
                    << std::endl;
        return (false);
    }
}

int		Account::checkAmount( void ) const
{
    return(_amount);
}