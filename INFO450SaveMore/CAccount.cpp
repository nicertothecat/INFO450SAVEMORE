#include "stdafx.h"
#include "CAccount.h"


CAccount::CAccount(int accountNumber, double accountBalance):BAccount(accountNumber, accountBalance)
{
	//Checking accounts do not accrue interest per functional requirements.
	intRate = 0;
}

int CAccount::orderChecks()
{
	//We want to make sure the account actually has money to order checks of course.
	if ((balance - CHECKFEE) > 0)
	{
		balance -= CHECKFEE;
		checkLowBal();
	//A 0 indicates success.
		return 0;
	}
	else
	{
		//A -1 indicates failure.
		return -1;
	}
}

int CAccount::withdrawal(double amount)
{
	//We want to make sure the withdrawal does not bring us in to the negatives.
	if ((balance - amount) > 0)
	{
		balance -= amount;
		//We have to check the balance in case the withdrawal incurs a low balance fee.
		checkLowBal();
		//A 0 indicates success.
		return 0;
	}
	else
	{
		//A -1 indicates failure.
		return -1;
	}
}

//If checking accounts go below 500 dollars, they incur a fee. This checks for that and incurs the fee if necessary.
void CAccount::checkLowBal()
{
	if (balance < 500)
	{
		balance -= CHECKFEE;
	}
}