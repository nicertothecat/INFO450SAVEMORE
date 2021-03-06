// INFO450SaveMore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include "BAccount.h"
#include "CAccount.h"
#include "SAccount.h"
#include "CertDep.h"
#include <iostream>

using namespace std;
//This method is used to make it easier to ask for info for the accounts.
void inputAccountInfo(int &inAccountNum, double &inBalance);

int main()
{
	//We start my introducing the program and asking for the balance and account number for every account.
	cout << "Welcome to the super complex and definitely realistic bank account simulator! We'll start by making three bank accounts." << endl;
	cout << "The first bank account will be a checking account, which doesn't bear interest." << endl;
	cout << "Please enter some info for account 1 (checking):" << endl;
	BAccount *acct1 = NULL;
	int inputAcctNum = NULL;
	double inputBalance = NULL;
	inputAccountInfo(inputAcctNum, inputBalance);
	acct1 = new CAccount(inputAcctNum, inputBalance);
	cout << "Next, enter the info for account 2 (savings):" << endl;
	BAccount *acct2 = NULL;
	inputAccountInfo(inputAcctNum, inputBalance);
	acct2 = new SAccount(inputAcctNum, inputBalance);
	cout << "Finally, please enter the info for account 3 (Certificate of Deposit):" << endl;
	BAccount *acct3 = NULL;
	int inputTerm = NULL;
	inputAccountInfo(inputAcctNum, inputBalance);
	//Certificates are special because they have a fixed term, so we have to ask for that info here.
	cout << "What is the term for this Certificate of Deposit (in years)?" << endl;
	cin >> inputTerm;
	acct3 = new CertDep(inputTerm, inputAcctNum, inputBalance);
	double inDeposit = NULL;
	//Next we deposit some money into each account. We can use the pointers because this is a function from the base class BAccount.
	cout << "Next, we'll deposit some money into each account. How much do you want to deposit into the checking account?" << endl;
	cin >> inDeposit;
	acct1->deposit(inDeposit);
	cout << "How much do you want to deposit into the savings account?" << endl;
	cin >> inDeposit;
	acct2->deposit(inDeposit);
	cout << "How much do you want to deposit into the Certficate of Deposit?" << endl;
	cin >> inDeposit;
	acct3->deposit(inDeposit);
	cout << "Just to let you know, we're going to accrue interest in the savings account as well as the Certificate. You don't need to do anything." << endl;
	acct2->assessInterest();
	acct3->assessInterest();
	//Then we have the user withdraw some money from each account.
	cout << "Next we will have you withdraw some amount from each account." << endl;
	//This variable is used to store the withdrawal amount.
	double withdrawAmt = NULL;
	cout << "How much do you want to withdraw from the checking account?" << endl;
	cin >> withdrawAmt;
	acct1->withdrawal(withdrawAmt);
	cout << "How much do you want to withdraw from the savings account?" << endl;
	cin >> withdrawAmt;
	acct2->withdrawal(withdrawAmt);
	cout << "How much do you want to withdraw from the CD account?" << endl;
	cin >> withdrawAmt;
	acct3->withdrawal(withdrawAmt);
	//We order some checks from the checking acccount.
	cout << "Just to let you know, we're going to order checks for the checking account. You don't need to do anything." << endl;
	acct1->orderChecks();
	//Then we simply use the display() method to show the contents of each account.
	cout << "Thanks! We'll close by displaying each account." << endl;
	acct1->display();
	cout << "=====================================================" << endl;
	acct2->display();
	cout << "=====================================================" << endl;
	acct3->display();
	delete acct1;
	delete acct2;
	delete acct3;
    return 0;
}

void inputAccountInfo(int &inputAcctNum, double &inputBalance)
{
	cout << "What is the account number?" << endl;
	cin >> inputAcctNum;
	do
	{
		cout << "What is the opening balance?" << endl;
		cin >> inputBalance;
		if (inputBalance < 0) 
		{
			cout << "Sorry, you must enter a positive number for balance." << endl;
		}
	} while (inputBalance < 0);
}
