/**
 * Bank.h - this header file containes a class Bank which show the details of Bank account.
 * Created by: Vedant Patel
 * Date of creation: 30/10/2021
*/
#pragma once
#include "Account.h"
#include<vector>
#include<string>
using namespace std;
class Bank
{
	vector<Account*> allAccounts;

public:
	~Bank()
	{
		for (int i = 0; i < allAccounts.size(); i++)
			delete allAccounts[i];
	}

	/** void addAccount(Account* new_acc)
		* Purpose: To add new customer bank account
		* Parameter(s): 
			<1> new_acc : reffer to account of customer with type of Account class.	
		* Precondition: N/A
		* Returns : N/A
		* Side effect: N/A
		*/
	void addAccount(Account* new_acc)
	{
		allAccounts.push_back(new_acc);
	}

	/** void makeDeposit(int accountNO, int deposit_ammount, string Date)
		* Purpose: To add deposit to exsiting bank account
		* Parameter(s): 
			<1> accountNO : reffer to account number of customer with type integer.	
			<2> deposit	_ammount : reffer to deposite ammount with type integer.	
			<3> string_Date : reffer to date of deposite with type of string.	
		* Precondition: N/A
		* Returns : N/A
		* Side effect: N/A
		*/
	void makeDeposit(int accountNO, int deposit_ammount, string Date)
	{
		int cNumber = allAccounts[accountNO]->getCustomer().getCustomerNum();
		Transaction* newTrans = new Transaction(cNumber, "deposit", deposit_ammount, Date);
		allAccounts[accountNO]->addTransaction(newTrans);
		newTrans->setCusBalance(allAccounts[accountNO]->getBalance());
	}

	/** void makeWithdrawl(int accountNO, int withDraw_ammount, string Date)
		* Purpose: To add deposit to exsiting bank account
		* Parameter(s): 
			<1> accountNO : reffer to account number of customer with type integer.	
			<2> withDraw_ammount : reffer to withdrawl ammount with type integer.	
			<3> string_Date : reffer to date of deposite with type of string.	
		* Precondition: N/A
		* Returns : N/A
		* Side effect: N/A
		*/
	void makeWithdrawl(int accountNO, int withDraw_ammount, string Date)
	{
		int cNumber = allAccounts[accountNO]->getCustomer().getCustomerNum();
		Transaction* newTrans = new Transaction(cNumber, "withdraw", withDraw_ammount, Date);
		allAccounts[accountNO]->addTransaction(newTrans);
		newTrans->setCusBalance(allAccounts[accountNO]->getBalance());
	}

	/** int getAccountsCount()
		* Purpose: To display total account counts
		* Parameter(s): N/A	
		* Precondition: N/A
		* Returns : function returning total account counts
		* Side effect: N/A
		*/
	int getAccountsCount()
	{
		return allAccounts.size();

	}
	// function of return type Account
	// getting one parameter of int 
	Account* getAccount(int accountNo)
	{
		return allAccounts[accountNo];
	}

	/** int checkBalance(int accountNo)
		* Purpose: To display balance of particular account number
		* Parameter(s): 
		*		<1> accountNO : reffer to account number of customer with type integer.
		* Precondition: N/A
		* Returns : returning the balance of particular account number
		* Side effect: N/A
		*/
	int checkBalance(int accountNo)
	{
		return allAccounts[accountNo]->getBalance();
	}
};

