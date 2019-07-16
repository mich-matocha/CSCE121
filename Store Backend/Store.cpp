#include "Store.h"
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace std;

//MAKE SURE TO RETURN WHEN YOU NEED TO RETURN!

Store::Store()
{}

Store::Store(string n)
{
	name = n;
}

string Store::getName() const
{
	return name;
}

void Store::setName(string newName)
{
	name = newName;
}

void Store::addProduct(int productID, string productName)
{
	Product p(productID, productName);
	bool found = false;
	for (Product product : products)
	{
		if(product.getID() == productID)
		{
			found = true;
		}
	}
	if(found)
	{
		throw runtime_error("Error: Product already exists.");
	}
	else
	{
		products.push_back(p);
	}
}

Product& Store::getProduct(int productID) //returning copy of object rather than og object
{
	for(int i = 0; i < products.size(); ++i)
	{
		if(products.at(i).getID() == productID)
		{
			return products.at(i);
		}
	}

	throw runtime_error("Error: Product not found.");
}

void Store::addCustomer(int customerID, string customerName, bool credit = false)
{
	Customer c(customerID, customerName, credit);
	bool found = false;
	for (Customer customer : customers)
	{
		if(customer.getID() == customerID)
		{
			found = true;
		}
	}
	if(found)
	{
		throw runtime_error("Error: Customer already exists.");
	}
	else
	{
		customers.push_back(c);
	}
}

Customer& Store::getCustomer(int customerID) //going to have the same problem here as with product
{
	for (int i = 0; i < customers.size(); ++i)
	{
		if(customers.at(i).getID() == customerID)
		{
			return customers.at(i);
		}
	}
	throw runtime_error("Error: Customer not found.");
}

void Store::takeShipment(int productID, int quantity, double cost)
{
	getProduct(productID).addShipment(quantity, cost);
}

void Store::takePayment(int customerID, int amount)
{
	try
	{
		getCustomer(customerID);
	}
	catch(runtime_error &e)
	{
		cout << "Error: Customer not found." << endl;
	}
	getCustomer(customerID).processPayment(amount);
}

void Store::sellProduct(int customerID, int productID, int quantity)
{
	if(quantity < 0)
	{
		throw runtime_error("Error: Negative quantity.");
	}

	getProduct(productID);
	getCustomer(customerID);
	
	try
	{
		Product p = getProduct(productID);
		double price = p.getPrice();
		double amount = price * quantity;
		getProduct(productID).reduceInventory(quantity);
		getCustomer(customerID).processPurchase(amount, getProduct(productID));
	}
	catch(runtime_error &e)
	{
		cout << "Error: Unable to process transaction." << endl;
	}
}

string Store::listProducts() const 
{
	stringstream ret;
	for (Product p : products)
	{
		ret << p << endl;
	}
	return ret.str();
}

string Store::listCustomers() const
{
	stringstream ret;
	for (Customer c : customers)
	{
		ret << c << endl;
	}
	return ret.str();
}
