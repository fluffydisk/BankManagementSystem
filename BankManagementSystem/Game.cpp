#include <iostream>

#include "Game.h"
#include "Log.h"



Game::Game() : accountLoggedIn(nullptr), choice(static_cast<int>(MAIN_MENU::PRINT_OPTIONS)), gameFinished(0) {}
Game::~Game() {}

Log gLog;

void Game::startGame()
{
	while (!gameFinished)
	{
		if (accountLoggedIn == nullptr)
			mainMenu();

		else
			loggedInMenu();
	}
}


void Game::mainMenu()
{
	if (choice == static_cast<int>(MAIN_MENU::EXIT))
	{
		exit();
	}
	else if (choice == static_cast<int> (MAIN_MENU::PRINT_OPTIONS))
	{
		mainMenuPrintOptions();
	}
	else if (choice == static_cast<int> (MAIN_MENU::SIGN_IN))
	{
		signIn();
	}
	else if (choice == static_cast<int> (MAIN_MENU::SIGN_UP))
	{
		signUp();
	}
	else if (choice == static_cast<int>(MAIN_MENU::PRINT_LOGS))
	{
		printGameLogs();
	}
}

void Game::loggedInMenu()
{
	if (choice == static_cast<int>(LOGGED_IN_MENU::EXIT))
	{
		exit();
	}
	else if (choice == static_cast<int>(LOGGED_IN_MENU::PRINT_OPTIONS))
	{
		loggedInMenuPrintOptions();
	}
	else if (choice == static_cast<int>(LOGGED_IN_MENU::SHOW_DETAILS))
	{
		printAccountDetails();
	}
	else if (choice == static_cast<int>(LOGGED_IN_MENU::SEND_MONEY))
	{
		sendMoney();
	}
	else if (choice == static_cast<int>(LOGGED_IN_MENU::SIGN_OUT))
	{
		signOut();
	}
	else if (choice == static_cast<int>(LOGGED_IN_MENU::DELETE_ACCOUNT))
	{
		deleteAccount();
	}
	else if (choice == static_cast<int>(LOGGED_IN_MENU::PRINT_ACCOUNT_LOGS))
	{
		printAccountLogs();
	}
}

BankAccount* Game::findBankAccountByID(int ID)
{
	for (BankAccount* bankAcc : BankAccounts)
	{
		if (bankAcc->getID() == ID)
		{
			return bankAcc;
		}
	}
	return nullptr;
}

void Game::signIn()
{
	system("cls");
	int ID;
	std::string password;
	std::cout << "Please provide the ID for Signing In" << std::endl;
	std::cin >> ID;
	if (findBankAccountByID(ID) == nullptr)
	{
		system("cls");
		std::cout << "The ID you provided is not registred\nPress Enter to continue..." << std::endl;
		std::cin.get();
		std::cin.get();
		system("cls");
		choice = static_cast<int>(MAIN_MENU::PRINT_OPTIONS);
		return;

	}
	accountLoggedIn = findBankAccountByID(ID);

	do
	{
		std::cout << "Please provide the Password " << std::endl;
		std::cin >> password;
		if (password != *accountLoggedIn->getPassword())
			std::cout << "The Password you provided is not correct!" << std::endl;

	} while (password != *accountLoggedIn->getPassword());
	system("cls");
	gLog.createNewLog(accountLoggedIn->Name + " " + accountLoggedIn->Surname + " Signed in to his account");
	std::cout << "Succesfully logged in" << std::endl;
	choice = static_cast<int>(LOGGED_IN_MENU::PRINT_OPTIONS);

}

void Game::signUp()
{
	system("cls");

	std::string name;
	std::string surname;
	std::string password;
	int moneyBalance;
	int ID;

	std::cout << "Please provide a Name for registration" << std::endl;
	std::cin >> name;
	std::cout << "Please provide a Surname for registration" << std::endl;
	std::cin >> surname;
	std::cout << "Please provide the Balance for the Bank Account" << std::endl;
	std::cin >> moneyBalance;


	do
	{
		std::cout << "Please provide an ID for registration" << std::endl;
		std::cin >> ID;

		if (findBankAccountByID(ID) != nullptr)
		{
			std::cout << "This ID is already used. Please enter a different ID." << std::endl;
		}

	} while (findBankAccountByID(ID) != nullptr);

	std::cout << "Please create a password" << std::endl;
	std::cin >> password;

	BankAccount* newAccount = new BankAccount(ID, password, name, surname, moneyBalance);
	BankAccounts.push_back(newAccount);
	system("cls");

	gLog.createNewLog(newAccount->Name + " " + newAccount->Surname + " created a new account");
	std::cout << "Account succesfully created!" << std::endl;
	choice = static_cast<int>(MAIN_MENU::PRINT_OPTIONS);

}

void Game::printGameLogs()
{
	system("cls");
	gLog.printAllLogs();
	std::cout << "Please Enter to continue..." << std::endl;
	std::cin.get();  std::cin.get();
	choice = static_cast<int>(MAIN_MENU::PRINT_OPTIONS);
}
void Game::printAccountLogs()
{
	system("cls");
	accountLoggedIn->printAccountLogs();
	std::cout << "Please Enter to continue..." << std::endl;
	std::cin.get();  std::cin.get();
	choice = static_cast<int>(LOGGED_IN_MENU::PRINT_OPTIONS);
}

void Game::mainMenuPrintOptions()
{
	system("cls");
	std::cout
		<< "1 - SIGN IN\n"
		<< "2 - SIGN UP\n"
		<< "3 - PRINT SYSTEM LOGS\n"
		<< "0 - EXIT" << std::endl;
	std::cin >> choice;

	// Ensure the input is within valid range before casting
	while (!(choice >= 0 && choice <= 4))  // assuming there are 3 valid options in MAIN_MENU
	{
		std::cout << "Invalid option, please try again." << std::endl;
		std::cin >> choice;
	}
}

void Game::loggedInMenuPrintOptions()
{
	system("cls");
	std::cout
		<< "WELCOME " << accountLoggedIn->Name << " " << accountLoggedIn->Surname
		<< "\n1 - See account details"
		<< "\n2 - Send Money"
		<< "\n3 - Delete Account"
		<< "\n4 - Print Account Logs"
		<< "\n9 - Sign out"
		<< "\n0 - Exit"
		<< std::endl;
	std::cin >> choice;
}

void Game::printAccountDetails()
{
	gLog.createNewLog(accountLoggedIn->Name + " " + accountLoggedIn->Surname + " printed account details");
	accountLoggedIn->printAccountDetails();
	std::cout << "Press OK to continue...";
	std::cin.get();
	std::cin.get();
	choice = static_cast<int>(LOGGED_IN_MENU::PRINT_OPTIONS);
}

void Game::sendMoney()
{
	system("cls");
	int moneyAmount;
	int accountID = NULL;
	int tryNum = 0;
	do
	{
		system("cls");
		std::cout << "Please enter the ID of the person you want to send the money to: ";
		std::cin >> accountID;


		if (findBankAccountByID(accountID) == nullptr)
		{
			std::cout << "The account ID does not exist. Please try again.\nPress Enter to continue" << std::endl;
			tryNum++;
			std::cin.get(); std::cin.get();
			continue;
		}


		if (accountID == accountLoggedIn->getID())
		{
			std::cout << "You cannot send money to yourself. Please enter a different ID.\nPress Enter to continue" << std::endl;
			std::cin.get(); std::cin.get();
			continue;
		}

		break;

	} while (tryNum < 4);

	if (!(tryNum < 4))
	{
		system("cls");
		std::cout << "Maximum try number exceted!" << std::endl;
		std::cin.get();
		choice = static_cast<int>(LOGGED_IN_MENU::PRINT_OPTIONS);
		return;
	}

	do
	{
		system("cls");
		std::cout << "Please enter the amount of the money you want to send to " << findBankAccountByID(accountID)->Name << " " << findBankAccountByID(accountID)->Surname << ": ";
		std::cin >> moneyAmount;
		//std::cout << accountID << " " << accountLoggedIn->getID() << std::endl;
		if (accountLoggedIn->Balance < moneyAmount)
		{
			std::cout << "You dont have enough balance\nPress Enter to continue..." << std::endl;
			std::cin.get(); std::cin.get();
			continue;
		}

		if (moneyAmount < 0)
		{
			std::cout << "Please enter a valid value\nPress Enter to continue..." << std::endl;
			std::cin.get(); std::cin.get();
			continue;
		}

		accountLoggedIn->sendMoney(findBankAccountByID(accountID), moneyAmount);

		break;


	} while (true);
	gLog.createNewLog(accountLoggedIn->Name + " " + accountLoggedIn->Surname + " sent money to " + findBankAccountByID(accountID)->Name + " " + findBankAccountByID(accountID)->Surname);
	std::cout << "Money succesfully sent to " << findBankAccountByID(accountID)->Name << " " << findBankAccountByID(accountID)->Surname << std::endl;
	choice = static_cast<int>(LOGGED_IN_MENU::PRINT_OPTIONS);
}

void Game::deleteAccount()
{
	gLog.createNewLog(accountLoggedIn->Name + accountLoggedIn->Surname + " has deleted account");
	system("cls");
	BankAccounts.erase(std::find(BankAccounts.begin(), BankAccounts.end(), accountLoggedIn));
	accountLoggedIn = nullptr;
	std::cout << "Account deleted succesfully\nPress Enter to continue..." << std::endl;
	std::cin.get(); std::cin.get();
	choice = static_cast<int>(MAIN_MENU::PRINT_OPTIONS);
}

void Game::signOut()
{
	gLog.createNewLog(accountLoggedIn->Name + " " + accountLoggedIn->Surname + " Signed out from his account");
	choice = static_cast<int>(MAIN_MENU::PRINT_OPTIONS);
	accountLoggedIn = nullptr;
	return;
}

void Game::exit()
{
	endGame();
	return;
}

void Game::endGame()
{
	gameFinished = true;
	accountLoggedIn = nullptr;
	for (BankAccount* bankAcc : BankAccounts)
	{
		delete bankAcc;
	}
	BankAccounts.clear();
}

