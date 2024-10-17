#include "BankAccount.h"
#include<iostream>
BankAccount::BankAccount(int id, std::string password, std::string name, std::string surname, int moneyBalance) : ID(id), Password(password), Name(name), Surname(surname), Balance(moneyBalance)
{
	accountLogs.createNewLog("Account created");
}
BankAccount::~BankAccount()
{
	std::cout << "Bank Account deleted succesfully" << std::endl;
}

void BankAccount::sendMoney(BankAccount* reciever, int amount)
{
	accountLogs.createNewLog("You sent money to " + reciever->Name + " " + reciever->Surname);
	this->changeBalance(DECREASE_BALANCE, amount);
	reciever->changeBalance(INCREASE_BALANCE, amount);
	accountLogs.createNewLog("");
}

void BankAccount::printAccountDetails()
{
	accountLogs.createNewLog("You printed account details");
	system("cls");
	std::cout
		<< "ID: " << this->ID
		<< "\nName: " << this->Name
		<< "\nSurname: " << this->Surname
		<< "\nBalance: " << this->Balance
		<< "\nPassword: " << this->Password << std::endl;
}

int BankAccount::getID()
{
	accountLogs.createNewLog("Your ID accesed from another source");
	return ID;
}
std::string* BankAccount::getPassword()
{
	accountLogs.createNewLog("Your Pasword accesed from another source");
	std::string* Pass = &Password;
	return Pass;
}

void BankAccount::printAccountLogs()
{
	this->accountLogs.printAllLogs();
}

void BankAccount::changeBalance(changeBalanceOptions type, int amount)
{
	int oldBalance = this->Balance;
	if (type == INCREASE_BALANCE)this->Balance += amount;
	else if (type == DECREASE_BALANCE) this->Balance -= amount;
	accountLogs.createNewLog("Your balance has been changed " + std::to_string(oldBalance) + " -> " + std::to_string(this->Balance));
}