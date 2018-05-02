#include "stdafx.h"
#include "BAccount.h"
#include <iostream>
#include <string>

BAccount::BAccount(int accountNumber, double accountBalance)
{
	acctnum = accountNumber;
	balance = accountBalance;
}

int BAccount::withdrawal(double amount)
{
	if ((balance - amount) > 0)
	{
		balance -= amount;
		return 0;
	}
	else
	{
		return -1;
	}
}

void BAccount::deposit(double amount)
{
	balance += amount;
}

void BAccount::display()
{
	cout << "Account number: " << acctnum << endl;
	cout << "Balance: " << balance << endl;
	cout << "Interest rate: " << intRate << endl;
}

int BAccount::orderChecks()
{
	return -1;
}