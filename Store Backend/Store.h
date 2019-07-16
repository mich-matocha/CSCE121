#ifndef STORE_H
#define STORE_H

#include "Product.h"
#include "Customer.h"
#include <string>
#include <vector>

using namespace std;

class Store
{
public:
	Store();
	Store(string name);
	string getName() const;
	void setName(string newName);
	void addProduct(int productID, string productName);
	Product& getProduct(int productID);
	void addCustomer(int customerID, string customerName, bool credit);
	Customer& getCustomer(int customerID);
	void takeShipment(int productID, int quantity, double cost);
	void takePayment(int customerID, int amount);
	void sellProduct(int customerID, int productID, int quantity);
	string listProducts() const;
	string listCustomers() const;
private:
	string name = "";
	vector<Product> products;
	vector<Customer> customers;
};

#endif