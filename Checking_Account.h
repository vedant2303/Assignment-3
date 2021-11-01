/**
 * Checking_Account.h - this header file containes a derived class checking_account inherited from account.
 * Created by: Vedant Patel
 * Date of creation: 29/10/2021
*/
#pragma once
#include "Account.h"
class Checking_Account : public Account
{
public:
	// constror with 2 arguments 
	// one of Customer type and second of int 
    Checking_Account(Customer* newCust, int accNo) : Account(newCust, accNo)
    {

    }
};

