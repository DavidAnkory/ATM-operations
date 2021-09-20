#include <iostream>
#include "Clock.h"
#include "Account.h"
using namespace std;
enum action
{
	stop,
	balance,
	deposit,
	withdraw,
	sumDeposit,
	sumWithdraw
};
action menu()
{
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all withdraws" << endl;
	cout << "enter 5 to see the sum of all Deposits" << endl;
	cout << "enter 0 to stop" << endl << endl;
	int x;
	cin >> x;
	return (action)x;
}
int findAccount(Account* bank, int size)
{
	int number, code;
	cout << "please enter account number: " << endl;
	cin >> number;
	int i = 0;
	while (i < size && bank[i].getAccountNumber() != number)
	{
		i++;
		if (i == size)
			throw "ERROR: no such account number!\n";
	}
	cout << "please enter the code: " << endl;
	cin >> code;
	if (bank[i].getCode() == code)
		return i;
	throw "ERROR: wrong code!";
}
void printTransaction(Account a, action ac, Clock& c)
{
	cout << c << "\t";
	;
	switch (ac)
	{
	case balance: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "balance: " << a.getBalance() << endl;
		break;
	case deposit:
	case withdraw: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case sumDeposit:
		cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
		break;
	case sumWithdraw:
		cout << "sum of all withdraws: " << Account::getSumWithdraw() << endl;
		break;
	}
}
void getBalance(Account* bank, int size, Clock& c)
{
	try
	{
		int i = findAccount(bank, size);
		c += 20;
		printTransaction(bank[i], balance, c);
	}
	catch (const char* msg)   //error finding acount
	{
		cout << c << '\t' << msg;
	}

}

void cashDeposit(Account* bank, int size, Clock& c)
{
	try
	{
		int i = findAccount(bank, size);
		float amount;
		cout << "enter the amount of the check:" << endl;
		try                                               //check if the sum to deposit is less than 10000
		{
			cin >> amount;
			bank[i].deposit(amount);
			c += 30;
			printTransaction(bank[i], deposit, c);
		}
		catch (int num)
		{
			cout << c << "        " << "ERROR: cannot deposit more than 10000 NIS!" << endl;
		}

	}
	catch (const char* msg) {
		cout << c << '\t' << msg;

	}
}
void cashWithdraw(Account* bank, int size, Clock& c)
{
	try
	{
		int i = findAccount(bank, size);
		float amount;
		cout << "enter the amount of money to withdraw:" << endl;
		try                                                           // chec if the withbraw is less than 2500 and the balance is not less than -6000
		{
			cin >> amount;
			bank[i].withdraw(amount);
			c += 50;
			printTransaction(bank[i], withdraw, c);

		}
		catch (double num2)
		{
			cout << c << "        " << "ERROR: cannot have less than - 6000 NIS!" << endl;
		}
		catch (int num)
		{
			cout << c << "        " << "ERROR: cannot withdraw more than 2500 NIS!" << endl;
		}
	}
	catch (const char* msg) {
		cout << c << '\t' << msg;

	}
}
int main()
{
	Clock c(8);
	Account bank[10];

	cout << "enter account number, code and email for 10 accounts:" << endl << endl;
	for (int i = 0; i < 10; i++)
	{
		try
		{
			try
			{                        //try yo get the acoountes details, throw a error if needs                                   
				cin >> bank[i];
			}
			catch (double t)
			{
				cout << c << '\t' << "ERROR: wrong code!\n" << endl;
				i--;
			}
			catch (int x)
			{
				cout << c << "        " << "ERROR: code must be of 4 digits!" << endl;
				i--;
			}
			catch (float y) {
				cout << c << '\t' << "ERROR: email must contain @!" << endl;
				i--;
			}
			catch (const char msg) {
				cout << c << '\t' << "ERROR: email must end at.com or .co.il!" << endl << endl;
				i--;
			}
			for (int j = 0; j < i; j++)
				if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
					throw "ERROR: account number must be unique!\n";
		}
		catch (const char* msg)
		{
			cout << c << '\t' << msg;
			i--;
		}

	}
	action ac = menu();
	while (ac)
	{
		switch (ac)
		{
		case balance: getBalance(bank, 10, c);
			break;
		case withdraw:cashWithdraw(bank, 10, c);
			break;
		case deposit:cashDeposit(bank, 10, c);
			break;
		case sumDeposit:c += 60;
			printTransaction(bank[0], sumDeposit, c);
			break;
		case sumWithdraw:   c += 60;
			printTransaction(bank[0], sumWithdraw, c);

		}
		ac = menu();
	}
	return 0;
}
/*
enter account number, code and email for 10 accounts:

1 1111 aaa@gmail.com
2 2222 aaa@gmail.com
3 3333 bbb@gmail.com
4 4444 ccc@gmail.com
5 5555 ddd@gmail.com
6 6666 eee@gmail.com
7 7777 fff@gmail.com
8 8888 ggg@gmail.com
9 9999 hhh@gmail.com
10 1010 iii@gmail.com
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

5
08:01:00
		sum of all withdraws: 0
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

3
please enter account number:
1
please enter the code:
1111
enter the amount of money to withdraw:
5000
08:01:00
		ERROR: cannot withdraw more than 2500 NIS!
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop

0

C:\Users\ankor\Documents\מדעי המחשב- שנה א\סמסטר ב\סדנה C++\exercice4\Debug\exercice4.exe (process 1404) exited with code 0.
Press any key to close this window . . .
*/