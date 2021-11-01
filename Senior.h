/**
 * Senior.h - this header file contains a derived class senior inherited from customer
 * Created by: Vedant Patel
 * Date of creation: 29/10/2021
*/
#pragma once
#include "Customer.h"
class Senior :
    public Customer
{
public:
	// constructor of class Senior passing 5 arguments
	// three of string type and 2 of int type
    Senior(string name, string address, int age, string telephone, int custNo)
        :Customer(name, address, age, telephone, custNo)
    {

    }
};

