#pragma once
#include <iostream>
#include <string>

using namespace std;

class BAccount
{

protected: 
	int acctnum;
	double intRate;
	double balance;


public:
	BAccount(int accountNumber, double accountBalance);
	int withdrawal(double amount);
	void deposit(double amount);
	void display();
};

