#include "stdafx.h"
#include "CertDep.h"


CertDep::CertDep(int cdTerm, int accountNumber, double accountBalance):BAccount(accountNumber, accountBalance)
{
	if (cdTerm >= 5)
	{
		intRate = HIGHINT;
	}
	else
	{
		intRate = LOWINT;
	}
}

void CertDep::assessInterest()
{
	balance += (balance * (intRate / 12));
}

void CertDep::display()
{
	cout << "Account number: " << acctnum << endl;
	cout << "Balance: " << balance << endl;
	cout << "Interest rate: " << intRate << endl;
	cout << "Term length: " << term << endl;
}