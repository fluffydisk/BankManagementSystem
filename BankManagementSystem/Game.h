#pragma once

#include <vector>
#include <utility>
#include "BankAccount.h"
#include "Log.h"

class Game
{
public:
	Game();
	~Game();
	void startGame();
	void endGame();
	bool gameFinished;
private:
	int choice;

	enum class MAIN_MENU { EXIT, SIGN_IN, SIGN_UP, PRINT_LOGS, PRINT_OPTIONS };
	enum class LOGGED_IN_MENU { SIGN_OUT = 9, EXIT = 0, SHOW_DETAILS, SEND_MONEY, DELETE_ACCOUNT, PRINT_ACCOUNT_LOGS, PRINT_OPTIONS };

	BankAccount* findBankAccountByID(int ID);

	void mainMenu();
	void loggedInMenu();

	void signIn();
	void signUp();

	void printAccountDetails();

	void mainMenuPrintOptions();
	void loggedInMenuPrintOptions();

	void sendMoney();

	void printGameLogs();
	void printAccountLogs();

	void deleteAccount();
	void signOut();
	void exit();

	BankAccount* accountLoggedIn;
	std::vector<BankAccount*> BankAccounts;
};

