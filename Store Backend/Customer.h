#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Product.h"
#include <string>
#include <vector>

class Customer
{
public:
	Customer();
	Customer(int customerID, std::string customerName, bool credit=false);
	int getID() const;
	std::string getName() const;
	void setName(std::string newName);
	bool getCredit() const;
	void setCredit(bool credit);
	double getBalance() const;
	void processPayment(double amount);
	void processPurchase(double amount, Product product);
	std::string getProductsPurchased() const;
private:
	int id = 0;
	std::string name = "";
	bool credit = false;
	double balance = 0.00;
	std::vector<Product> products;
};

std::ostream& operator<<(std::ostream& os, const Customer& c);

#endif