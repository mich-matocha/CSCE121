#include "Customer.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

//MAKE SURE TO RETURN WHEN YOU NEED TO RETURN!
Customer::Customer()
{}

Customer::Customer(int customerID, string customerName, bool cred)
{
	if(customerName == "")
	{
		throw runtime_error("Error: Empty customer name.");
	}
	id = customerID;
	name = customerName;
	credit = cred;
}

int Customer::getID() const
{
	return id;
}

string Customer::getName() const
{
	return name;
}

void Customer::setName(string newName)
{
	if(newName != "")
		name = newName;
	else
		throw runtime_error("Error: Empty name.");
}

bool Customer::getCredit() const
{
	return credit;
}

void Customer::setCredit(bool cred)
{
	credit = cred;
}

double Customer::getBalance() const
{
	return balance;
}

void Customer::processPayment(double amount)
{
	if(amount >= 0)
	{
		balance += amount;
	}
	else
	{
		throw runtime_error("Error: Negative payment.");
	}
}

void Customer::processPurchase(double amount, Product product)
{
	if(amount < 0) //if negative amount
	{
		throw runtime_error("Error: Negative amount.");
	}

	if(credit) //if credit, decrease from balance, because balance is allowed to be negative
	{
		balance -= amount;
	}
	else if (amount <= balance) //if not credit, amount has to be less than balance to be a valid purchase
	{
		balance -= amount;
	}
	else
	{
		throw runtime_error("Error: Invalid purchase.");
	}

	products.push_back(product);
}

string Customer::getProductsPurchased() const //kinda like toString()
{
	string ret = "";
	for(Product product : products)
	{
		ret += product.to_string(product) + "\n";
	}
	return ret;
}

ostream& operator<<(ostream& os, const Customer& c)
{
	os << "Customer Name: " << c.getName() << endl;
	os << "Customer ID: " << c.getID() << endl;
	string creditString = "";

	if(c.getCredit())
		creditString = "true";
	else
		creditString = "false";

	os << "Has Credit: " << creditString << endl;
	os << "Balance: " << c.getBalance() << endl;
	os << "Products Purchased --" << endl << endl;

	os << c.getProductsPurchased();
	return os;
}
