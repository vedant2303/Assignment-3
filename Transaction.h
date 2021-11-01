/**
 * Transaction.h - this header file containes a class Transaction which show the details of each transaction.
 * Created by: Vedant Patel
 * Date of creation: 29/10/2021
*/
#pragma once
#include<string>
#include"Customer.h"
using namespace std;

class Transaction
{
	int customer_number;
	string transaction_type;
	int amount;
	string fees;
	string date;
	int cusBalance;

public:
	// constructor of Transaction having 3 arguments
	// two of string and 2 of int type
	Transaction(int custNo, string type, int tAmount,string tDate)
	{
		customer_number = custNo;
		transaction_type = type;
		amount = tAmount;
		date = tDate;
	}
	// getter of type string returning transaction_type
	/** void getType
		* Purpose: getter to get Type of transaction
		* Parameter(s): N/A	
		* Precondition: N/A
		* Returns : return transaction object
		* Side effect: N/A
		*/
	string getType()
	{
		return transaction_type;
	}
	
	/** void getDate
		* Purpose: getter to get Date of transaction
		* Parameter(s): N/A	
		* Precondition: N/A
		* Returns : return date in form of string type
		* Side effect: N/A
		*/
	string getDate()
	{
		return date;
	}
	// setter of type void setting customer balance
	/** void setCusBalance
		* Purpose: setter to set Balance of customer
		* Parameter(s): 
			<1> balance : reffer to balance of customer by type of integer	
		* Precondition: N/A
		* Returns : N/A
		* Side effect: N/A
		*/
	void setCusBalance(int balance)
	{
		cusBalance = balance;
	}
	// getter of type int returning customer balance

	/** int getCusBalance()
		* Purpose: Getter customer balance
		* Parameter(s): N/A	
		* Precondition: N/A
		* Returns : returning customer balance
		* Side effect: N/A
		*/
	int getCusBalance()
	{
		return cusBalance;
	}
	// getter of type int returning amount

	/** int getAmount()
		* Purpose: Getter amount
		* Parameter(s): N/A	
		* Precondition: N/A
		* Returns : getter of type int returning amount
		* Side effect: N/A
		*/
	int getAmount()
	{
		return amount;

	}
};
