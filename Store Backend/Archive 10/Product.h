#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

//using namespace std;

class Product
{
public:
	Product();
	Product(int productID, std::string productName);
	int getID() const;
	std::string getName() const;
	void setName(std::string newName);
	std::string getDescription() const;
	void setDescription(std::string newDescription);
	int getNumberSold() const;
	double getTotalPaid() const;
	int getInventoryCount() const;
	double getPrice() const;
	void addShipment(int quantity, double cost);
	void reduceInventory(int quantity);
	std::string to_string(const Product& p) const;
private:
	int id = -1;
	std::string name = "";
	std::string description = "";
	int inventory = 0;
	int numSold = 0;
	double totalPaid = 0;
};

std::ostream& operator<<(std::ostream& os, const Product& p);

#endif