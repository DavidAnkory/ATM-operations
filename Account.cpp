#include "Account.h"
#include<string>
using namespace std;


float Account::sum_Deposit = 0;
float Account::sum_Withdraw = 0;

Account::Account(int _accountNumber, int _code, double _balance, char* _mail)
{
	accountNumber = _accountNumber;
	code = _code;
	balance = _balance;
	mail.assign(_mail);
}
// set methoodes 
void Account::setBalance(float newBalance)
{
	balance = newBalance;
}
void Account::setMail(string newMail)
{
	mail = newMail;
}


void Account::withdraw(float nis)  // //cash withdrawal
{
	float temp = balance - nis;
	if (nis > 2500)
		throw 1;
	if (temp < -6000)
		throw 1.0;
	balance = temp;
	sum_Withdraw += nis;

}

void Account::deposit(float cheacSum)   // sumDeposit 
{
	if (cheacSum > 10000)
		throw 1;
	balance += cheacSum;
	sum_Deposit  += cheacSum;

}

std::istream& operator>>(std::istream& in, Account& b)
{

	in >> b.accountNumber >> b.code;
	if (b.code == 1)
	{
		in >> b.code;
	}
	if (b.code < 1000 || b.code>9999)
	{
		in.ignore(256, '\n');
		throw 1;
	}
	in >> b.mail;
	if ((b.mail.find('@') != b.mail.rfind('@')))
		throw "ERROR: wrong email\n";

	if ((b.mail.find('@') == -1))
		throw 0.2;	// Float

	if ((b.mail.find(".com", b.mail.find('@')) == -1) && ((b.mail.find(".co.il", b.mail.find('@')) == -1)))
		throw 'E';


	return in;
}
