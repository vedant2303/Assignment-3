/**
 * Savings_Account.h - this header file containes a derived class savings_account inherited from account
 * Created by: Vedant Patel
 * Date of creation: 29/10/2021
*/
#pragma once
#include "Account.h"
class Savings_Account : public Account
{
public:
	// constror with 2 arguments 
	// one of Customer type and second of int 
	Savings_Account(Customer* newCust, int accNo) : Account(newCust, accNo)
	{

	}
	
};

