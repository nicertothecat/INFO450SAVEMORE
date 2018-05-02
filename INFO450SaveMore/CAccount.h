#pragma once
#include "BAccount.h"
class CAccount :
	public BAccount
{
private:
	//These constants make it easy to use the variables that determine if a low balance fee will be incurred and how much it costs to order a check.
	const double BALANCELOW = 500.00;
	const double LOWBALFEE = 5.00;
	const double CHECKFEE = 15.00;

public:
	CAccount(int accountNumber, double accountBalance);
	int orderChecks();
	//We need to override the normal withdrawal function because a checking acount can incur a balance fee.
	int withdrawal(double amount);
	void checkLowBal();
};

