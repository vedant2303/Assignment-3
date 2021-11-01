/**
* Source.cpp : This file contains the main() function. 
* Purpose: To perform all local bank operations.
* Developed by: Vedant Patel
 * Date of creation: 31/10/2021
*/

// Importing necessary libraries
#include<iostream>
#include<typeinfo>
#include"Bank.h"
#include"Student.h"
#include"Adult.h"
#include"Senior.h"
#include"Checking_Account.h"
#include"Savings_Account.h"
#include"Transaction.h"

using namespace std;

//Prints initial menu and get and validates choice.
void showMenu(int& choice);

//Gets min, max and choice integers and validates that choice is between the given range.
void validateChoice(int min, int max, int& choice);

//handles the operation of adding account to bank Class. Also creates accounts and customer according to 
//requirement.
void addAccount(Bank& myBank);

//Asks the user and then takes input of details of customer.
void getCustomerDetails(string& name, string& address, string& number, int& age);

//Prints a menu and gets a account type from user.
void getAccType(int& accType);

//prints and menu and gets customer type from user.
void getCustType(int& cusType);

//Handles the operation of making deposit to Bank class.
void makeDeposit(Bank& myBank);

//Handles the operation of checking account
void checkAccount(Bank& myBank);

//handles the operation of withdrawing money from account.
void withDrawMoney(Bank& myBank);

/**
 * @info:
 * Contains all the main logic for the given program and is executed first before any other functions.
 * 
 * @explaination:
 * 	- this function calls the operations that are performed in local bank using all classes.
 * 
 * @preconditions:
 * - N/A
 * 
 * @param: - N/A
 * @return: - N/A
 * 
 * @sideeffects: N/A
 */

int main()
{
	Bank myBank;
	int choice = 10;
	do
	{
		showMenu(choice);
		if (choice == 0)
			addAccount(myBank);
		if (choice == 1)
			makeDeposit(myBank);
		if (choice == 2)
			withDrawMoney(myBank);
		if (choice == 3)
			checkAccount(myBank);

	} while (choice != 4);


	//Deallocating memory allocated on heap during the program.
	for (int i = 0; i < myBank.getAccountsCount(); i++)
	{
		delete myBank.getAccount(i)->getCustomerPtr();
		delete myBank.getAccount(i);

	}
	return 0;
}

void showMenu(int& choice)
{
	cout << "\n0: Add Account\n";
	cout << "1: Make Deposit\n";
	cout << "2: Make Withdrawl\n";
	cout << "3. Check Account\n";
	cout << "4. Exit\n";
	cout << ">";
	cin >> choice;
	validateChoice(0, 4, choice);
}

void validateChoice(int min, int max, int& choice)
{
	while (choice < min || choice > max)
	{
		cout << "Invalid Choice\n";
		cout << "Enter Choice between " << min << " and " << max << " : ";
		cin >> choice;
	}
}

void addAccount(Bank& myBank)
{
	string name, address, number;
	int age = -1, accType = -1, custType = -1;
	int custNo;
	Customer* newCustomer = nullptr;
	Account* newAcc = nullptr;

	getCustomerDetails(name, address, number, age);
	getAccType(accType);
	getCustType(custType);

	//Getting Customer Number
	if (myBank.getAccountsCount() != 0)
		custNo = myBank.getAccountsCount();
	else
	{
		custNo = 0;
	}

	//Creating a new customer.
	if (custType == 0)
	{
		newCustomer = new Senior(name, address, age, number, custNo);
	}
	else if (custType == 1)
	{		
		newCustomer = new Adult(name, address, age, number, custNo);
	}
	else if (custType == 2)
	{
	
		newCustomer = new Student(name, address, age, number, custNo);
	}

	if (accType == 0)
	{
		newAcc = new Checking_Account(newCustomer, newCustomer->getCustomerNum());
	}
	else if (accType == 0)
		newAcc = new Savings_Account(newCustomer, newCustomer->getCustomerNum());

	myBank.addAccount(newAcc);

	cout << "\nAccount " << newCustomer->getCustomerNum() << " added.\n";

}

void getCustomerDetails(string& name, string& address, string& number, int& age)
{
	cin.ignore();
	cout << "Enter Customer Name> ";
	getline(cin, name);
	cout << "Enter Customer Adress> ";
	getline(cin, address);
	cout << "Enter customer Age> ";
	cin >> age;
	cin.ignore();
	cout << "Enter customer phone number> ";
	getline(cin, number);
}

void getAccType(int& accType)
{
	cout << "Select:\n";
	cout << "0: checking\n";
	cout << "1: Savings\n";
	cin >> accType;
	validateChoice(0, 1, accType);
}

void getCustType(int& cusType)
{
	cout << "Senior:\n";
	cout << "0: Senior\n";
	cout << "1: Adult\n";
	cout << "2: Student\n";

	cin >> cusType;
	validateChoice(0, 1, cusType);
}

void makeDeposit(Bank& myBank)
{
	int acNo, amount;
	string date;
	
	cout << "Enter Account Number: ";
	cin >> acNo;
	validateChoice(0, myBank.getAccountsCount(), acNo);
	cout << "Enter the amount: ";
	cin >> amount;
	cout << "Enter the date: yyyy-mm-dd: ";
	cin.ignore();
	getline(cin, date);

	myBank.makeDeposit(acNo, amount, date);

	cout << "Deposit in " << acNo << ". Amount: " << amount;
	cout << " on " << date << ". New Balance:" << myBank.getAccount(acNo)->getBalance() << endl;
}

void checkAccount( Bank& myBank)
{
	int acNo;
	cout << "Enter Account Number: ";
	cin >> acNo;
	validateChoice(0, myBank.getAccountsCount(), acNo);

	const Account* cusAccount = myBank.getAccount(acNo);
	cusAccount->displayStatus();

}

void withDrawMoney(Bank& myBank)
{
	int acNo, amount, acBalance;
	string date;

	cout << "Enter Account Number: ";
	cin >> acNo;
	validateChoice(0, myBank.getAccountsCount(), acNo);
	cout << "Enter the amount: ";
	cin >> amount;

	
	acBalance = myBank.checkBalance(acNo);
	if (acBalance < amount)
	{
		cout << "Unable to process Transaction due to low balance\n";
		cout<< "Current Account Balance is: " << acBalance;
		return;
	}
	cout << "Enter the date: yyyy-mm-dd: ";
	cin.ignore();
	getline(cin, date);

	myBank.makeWithdrawl(acNo, amount, date);

}