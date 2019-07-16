#include "Product.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <sstream>

using namespace std;

//MAKE SURE TO RETURN WHEN YOU NEED TO RETURN!
Product::Product()
{}

Product::Product(int productID, string productName)
{
	if(productName == "")
	{
		throw runtime_error("Error: Empty product name.");
	}
	else
	{
		id = productID;
		name = productName;
	}
}

int Product::getID() const
{
	return id;
}

string Product::getName() const
{
	return name;
}

void Product::setName(string newName)
{
	if(newName != "")
		this->name = newName;
	else
		throw runtime_error("Error: Empty name.");
}

string Product::getDescription() const
{
	return description;
}

void Product::setDescription(string newDescription)
{
	//cout << "\"" << newDescription << "\"" << endl;
	this->description = newDescription;
	//cout << "\"" << description << "\"" << endl;
}

int Product::getNumberSold() const
{
	return numSold;
}

double Product::getTotalPaid() const
{
	return totalPaid;
}

int Product::getInventoryCount() const
{
	return inventory;
}

double Product::getPrice() const
{
	double price = 0.0;

	if((inventory + numSold) == 0)
	{
		throw runtime_error("Error: Unable to calculate price.");
	}

	price = (totalPaid / double(inventory + numSold)) * 1.25;

	return price;
}

void Product::addShipment(int purchaseQuantity, double cost)
{
	if(purchaseQuantity < 0 || cost < 0)
	{
		throw runtime_error("Error: Negative input.");
	}
	else
	{
		inventory += purchaseQuantity;
		totalPaid += cost;
	}
}

void Product::reduceInventory(int purchaseQuantity)
{
	if(inventory < purchaseQuantity)
	{
		throw runtime_error("Error: Insufficient inventory.");
	}
	else if (purchaseQuantity < 0)
	{
		throw runtime_error("Error: Negative purchase quantity.");
	}
	else
	{
		inventory -= purchaseQuantity;
		numSold += purchaseQuantity;
	}
}

string Product::to_string(const Product& p) const
{
	stringstream ret;
	ret << "Product Name: " << p.getName() << "\n";
	ret << "Product ID: " << p.getID() << "\n";
	return ret.str();
}

ostream& operator<<(ostream& os, const Product& p)
{
	os << p.to_string(p);
	os << "Description: " << p.getDescription() << endl;
	os << "Inventory: " << p.getInventoryCount() << endl;
	os << "Number Sold: " << p.getNumberSold() << endl;
	os << "Total Paid: " << p.getTotalPaid() << endl;

	stringstream priceString;
	double price = 0.0;
	try
	{
		price = p.getPrice();
	}
	catch(runtime_error &e)
	{
		priceString << "Unavailable";
	}

	if(price > 0)
		priceString << price; //not printing the right thing

	os << "Price: " << priceString.str() << endl;

	return os;
}
