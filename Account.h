#pragma once
#include<string>
#include<iostream>
using namespace std;

class Account
{
	int accountNumber;              //account number
	int code;                       // 4 digit code
	double balance;                   //the money in the account 
	string  mail;                          // the email
	static float sum_Withdraw;                       // a static counter to count 
	static float sum_Deposit;                     // a static counter to the	Deposites

public:
	//set methood
	void setBalance(float newBalance);
	void setMail(string newMail);
	Account() { accountNumber = 0, code = 0, balance = 0, mail ; }
	Account(int accountNumber, int _code, double _balance, char* _mail);

	//get methood 
	int  getAccountNumber() const { return accountNumber; };
	int  getCode() const { return code; };
	double getBalance() const { return balance; };
	string getMail() const { return mail; };

	//functiones
	void withdraw(float nis);   //cash withdrawal
	void deposit(float cheacSum);      // Deposit of checks

	//freind function for cin and cout 
	friend std::istream& operator>>(std::istream& in, Account&);

	//static func
	static float getSumWithdraw() { return sum_Withdraw; };
	static float  getSumDeposit() { return sum_Deposit; };
};


