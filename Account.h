/**
 * Account.h - this header file containes a class account which creates account and manipulate it
 * Created by: Vedant Patel
 * Date of creation: 29/10/2021
*/
#pragma once

//importing libraries
#include "Customer.h"
#include "Transaction.h"
#include <vector>
#include<iostream>
#include<iomanip>
#include <typeinfo>

using namespace std;
class Account
{
	Customer* cust;
	int balance;
	int accountNum;
	vector<Transaction*> transactionList;

	public:
	// constructor 
		Account(Customer* newCust, int accNo)
		{
			cust = newCust;
			balance = 0;
			accountNum = accNo;
		}
	// destructor 
		~Account()
		{
			for (int i = 0; i < transactionList.size(); i++)
				delete transactionList[i];
		}
	/** getBalance 
		
		* Purpose:  returns value of current balance 
		* Parameter(s): N/A
		* Precondition(s): N/A
		* Returns: signed interger value of balance
		* Side effect: N/A
		*/
		int getBalance()
		{
			return balance;
		}
	/** addTransaction
		
		* Purpose:   performs the transaction either amount deposited or withdrawn
		* Parameter(s): 
		* 		<1> newTrans : reffer to transaction with type transaction class
		* Precondition(s): N/A
		* Returns: signed interger value of balance
		* Side effect: N/A
		*/
		void addTransaction(Transaction* newTrans)
		{
			if (newTrans->getType() == "deposit")
				balance += newTrans->getAmount();
			else if (newTrans->getType() == "withdraw")
				balance -= newTrans->getAmount();
			transactionList.push_back(newTrans);
		}
		
	/** Customer getCustomer
		
		* Purpose: to get object of Customer 
		* Parameter(s): N/A
		* Precondition(s): N/A
		* Returns: Returns Cutomer class' object
		* Side effect: N/A
		*/
		Customer getCustomer()
		{
			return *cust;
		}
		Customer* getCustomerPtr()
		{
			return cust;
		}
	
	// void displayStatus()
		/**
		* Purpose: to display account infromation of customerto display account infromation of customer
		* Parameter(s): N/A
		* Precondition(s): N/A
		* Returns: N/A
		* Side effect: N/A
		*/
		void displayStatus() const
		{
			cout << "Account: " << accountNum;
			cout << "\nOwner: " << cust->getName();
			cout << "\nType of customer: " << typeid(*cust).name();
			cout << "\nBalance: " << balance;
			for (int i = 0; i < transactionList.size(); i++)
			{
				cout << "\n        ";
				cout << setw(10) << left << transactionList[i]->getType();
				cout << setw(15) << left << transactionList[i]->getDate();
				cout << setw(10) << left << " $ " << transactionList[i]->getAmount();
				cout << setw(3) << left << " $ " << transactionList[i]->getCusBalance();
			}
			cout << endl;
		}
	/** void setCustomer
		
		* Purpose: create new customer object
		* Parameter(s): 
		*		newCust : reffer to new customer with type Customer	
		* Precondition(s): N/A
		* Returns: N/A
		* Side effect: N/A
		*/
		void setCustomer(Customer* newCust)
		{
			cust = newCust;
		}
	/** setter to set balance
	 void set_Balance
		* Purpose: setter to set balance
		* Parameter(s): 
		*		newBalance : reffer to new balance with type interger	
		* Precondition: N/A
		* Returns: N/A
		* Side effect: N/A
		*/
		void set_balance(int newBalance)
		{
			balance = newBalance;
		}
};

