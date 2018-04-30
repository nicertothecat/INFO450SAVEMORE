#pragma once
#include "BAccount.h"
class SAccount :
	public BAccount
{
private:
	//These constants make it easy to keep track of what determines interest rates for savings account and withdrawal fees
	const double BALANCEHIGH = 10000.00;
	const double APRLOW = 0.01;
	const double APRHIGH = 0.02;
	const double WITHDRAWFEE = 2.00;

public:
	SAccount(int accountNumber, double accountBalance);
	void assessInterest();
	//We need to override the normal withdrawal function because interest rates change with balance.
	int withdrawal(double amount);
	//We need to override the normal deposit function becasue interest rates change with balance.
	void deposit(double amount);
	void checkRate();
};

