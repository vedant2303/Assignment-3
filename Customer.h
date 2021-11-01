/**
 * Customer.h - this header file containes a class customer which show the details of customers
 * Created by: Vedant Patel
 * Date of creation: 29/10/2021
*/
#pragma once
#include <string>
using namespace std;

class Customer
{
	string name;
	string address;
	int age;
	string telephoneNumber;
	int customerNumber;

public:
	// constructor
	Customer(string cName, string cAddress, int cAge, string cTel, int custNo)
	{
		name = cName;
		address = cAddress;
		age = cAge;
		telephoneNumber = cTel;
		customerNumber = custNo;
	}
	/** String getName
		
		* Purpose: Display the name.
		* Parameter(s): N/A
		* Precondition(s): N/A
		* Returns: function returning the name of return type string
		* Side effect: N/A
		*/
	string getName()
	{
		return name;
	}
	/** String getAdress()
		
		* Purpose: Display the address
		* Parameter(s): N/A
		* Precondition(s): N/A
		* Returns: function returning the address of return type string
		* Side effect: N/A
		*/
	string getAdress()
	{
		return address;
	}
	/** int getAge()
		
		* Purpose: Display the age
		* Parameter(s): N/A
		* Precondition(s): N/A
		* Returns: function returning the age of return type int
		* Side effect: N/A
		*/
	int getAge()
	{
		return age;
	}
	/** string getTelephone()
		
		* Purpose: Display the telephone number
		* Parameter(s): N/A
		* Precondition(s): N/A
		* Returns: function returning the telephone number of return type string
		* Side effect: N/A
		*/
	string getTelephone()
	{
		return telephoneNumber;
	}
	/** int getCustomerNum()
		
		* Purpose: Display the customerNumber
		* Parameter(s): N/A
		* Precondition(s): N/A
		* Returns: function returning the customerNumber of return type int
		* Side effect: N/A
		*/
	int getCustomerNum()
	{
		return customerNumber;
	}

	// function returning nothing of returning type void
	// setter for setting the name

	/** void setName(string nameOfCust)
		
		* Purpose: to set the name
		* Parameter(s): 
				<1> nameofCust : reffer to name of customer by type of string
		* Precondition(s): N/A
		* Returns: N/A
		* Side effect: N/A
		*/
	void setName(string nameOfCust)
	{
		name = nameOfCust;
	}
	// function returning nothing of returning type void
	// setter for setting the address

	/** void setAdress(string adressOfCust)
		
		* Purpose: to set the address
		* Parameter(s): 
				<1> adressOfCust : reffer to address of customer by type of string
		* Precondition(s): N/A
		* Returns: N/A
		* Side effect: N/A
		*/
	void setAdress(string adressOfCust)
	{
		address = adressOfCust;
	}
	// function returning nothing of returning type void
	// setter for setting the telephone number

	/** void setTelephone(string telephoneOfCust)
		
		* Purpose: to set the telephone number.
		* Parameter(s): 
				<1> telephoneOfCust : reffer to telephone number of customer by type of string
		* Precondition(s): N/A
		* Returns: N/A
		* Side effect: N/A
		*/
	void setTelephone(string telephoneOfCust)
	{
		telephoneNumber = telephoneOfCust;
	}
	// function returning nothing of returning type void
	// setter for setting the age

	/** void setAge(int ageOfCust)
		
		* Purpose: to set the age.
		* Parameter(s): 
				<1> ageOfCust : reffer to age of customer by type of int
		* Precondition(s): N/A
		* Returns: N/A
		* Side effect: N/A
		*/
	void setAge(int ageOfCust)
	{
		age = ageOfCust;
	}
	// function returning nothing of returning type void
	// setter for setting the customer number

	/** void setCustomerNum(int numOfCust)
		
		* Purpose: to set the customer number.
		* Parameter(s): 
				<1> numOfCust : reffer to customer number by type of int
		* Precondition(s): N/A
		* Returns: N/A
		* Side effect: N/A
		*/
	void setCustomerNum(int numOfCust)
	{
		customerNumber = numOfCust;
	}

};

