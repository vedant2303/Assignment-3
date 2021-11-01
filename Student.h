/**
 * Student.h - this header file containes a derived class student inherited from customer
 * Created by: Vedant Patel
 * Date of creation: 29/10/2021
*/
#pragma once
#include "Customer.h"
class Student :
    public Customer
{
public:
	// constructor of class Student passing 5 arguments
	// three of string type and 2 of int type
    Student(string name, string address, int age, string telephone, int custNo)
        :Customer(name, address, age, telephone, custNo)
    {

    }
};

