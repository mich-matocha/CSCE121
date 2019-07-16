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
	products.push_back(p); 
}

Product& Store::getProduct(int productID) const //returning copy of object rather than og object
{
	for(static Product product: products)
	{
		if(product.getID() == productID)
		{
			return product;
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

Customer& Store::getCustomer(int customerID) const //going to have the same problem here as with product
{
	for (static Customer customer : customers)
	{
		if(customer.getID() == customerID)
		{
			return customer;
		}
	}
	throw runtime_error("Error: Customer not found.");
}

void Store::takeShipment(int productID, int quantity, double cost)
{
	Product p;
	p = getProduct(productID);
	p.addShipment(quantity, cost);
}

void Store::takePayment(int customerID, int amount)
{
	Customer c;
	try
	{
		c = getCustomer(customerID);
	}
	catch(runtime_error &e)
	{
		cout << "Error: Customer not found." << endl;
	}
	c.processPayment(amount);
}

void Store::sellProduct(int customerID, int productID, int quantity)
{
	try
	{
		Product p = getProduct(productID);
		double price = p.getPrice();
		double amount = price * quantity;
		p.reduceInventory(quantity);
		Customer c = getCustomer(customerID);
		c.processPurchase(amount, p);
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
