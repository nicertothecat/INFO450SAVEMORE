#include "stdafx.h"
#include "SAccount.h"
#include <iostream>
#include <string>

SAccount::SAccount(int accountNumber, double accountBalance):BAccount(accountNumber, accountBalance)
{
	//This sets the interest rate as appropriate for the starting balance.
	checkRate();
}

int SAccount::withdrawal(double amount)
{
	if ((balance - amount - WITHDRAWFEE) > 0)
	{
		balance -= amount;
		balance -= WITHDRAWFEE;
		//We need to check how much interest should be accruing when the balance changes.
		checkRate();
		//A 0 indicates success.
		return 0;
	}
	else
	{
		//A -1 indicates failure, meaning there was not enough money to withdraw.
		return -1;
	}
}

void SAccount::deposit(double amount)
{
	balance += amount;
	//We have to determine the interest rate again in case the balance crosses the threshold for higher rates.
	checkRate();
}

void SAccount::assessInterest()
{
	//Interest is compounded monhtly so we have to divide the intRate, which is annual, by 12
	balance += (balance * (intRate / 12));
}

//This method can be used to set the appropriate interest rate when balance changes.
void SAccount::checkRate()
{
	if (balance >= BALANCEHIGH)
	{
		intRate = APRHIGH;
	}
	else
	{
		intRate = APRLOW;
	}
}