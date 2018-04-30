#pragma once
#include "BAccount.h"
class CertDep :
	public BAccount
{
private:
	//These constants help us use the amounts that correspond to long-term interest rates based on years for the certificate.
	const int LONGTERM = 5;
	const double LOWINT = 0.05;
	const double HIGHINT = 0.10;
	int term;

public:
	CertDep(int cdTerm, int accountNumber, double accountBalance);
	void assessInterest();
	//We need to override the normal display function to show the term length for certificates.
	void display();
};

