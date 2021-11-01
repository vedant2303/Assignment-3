/**
 * Adult.h - this header file containes a derived class adult inherited from customer
 * Created by: Vedant Patel
 * Date of creation: 30/10/2021
*/
#pragma once
#include "Customer.h"
class Adult :
    public Customer
{
public:
	// constructor of class Adult passing5 arguments
	// three of string type and 2 of int type
    Adult(string name, string address, int age, string telephone, int custNo)
        :Customer(name, address, age, telephone, custNo)
    {

    }

};

