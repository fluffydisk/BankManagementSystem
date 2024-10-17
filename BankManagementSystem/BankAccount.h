#pragma once
#include<string>
#include "Log.h"
enum changeBalanceOptions { INCREASE_BALANCE, DECREASE_BALANCE };
class BankAccount
{
public:
	BankAccount(int id, std::string password, std::string name, std::string surname, int moneyBalance);
	~BankAccount();

	std::string Name;
	std::string Surname;

	int Balance;

	void changeBalance(changeBalanceOptions type, int amount);
	void sendMoney(BankAccount* reciever, int amount);
	void printAccountDetails();
	void printAccountLogs();
	int getID();
	std::string* getPassword();
private:
	Log accountLogs;
	int ID;
	std::string Password;
};
