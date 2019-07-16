#include <iostream>
using namespace std;
 int main()
 {
	 double changeAmt;
	 int numQuart = 0;
	 int numDime = 0;
	 int numNick = 0;
	 int numPen = 0;
	 int totCoins = 0;
	 cin >> "Enter dollar amount: " >> changeAmt;
	 changeAmt *= 100;
	 int(changeAmt);
	 numQuart = changeAmt / 25;
	 totCoins += numQuart;
	 changeAmt = changeAmt % 25;
	 if(changeAmt != 0)
	 {
		 numDime = changeAmt / 10;
		 totCoins += numDime;
		 changeAmt = changeAmt % 10;
		 if(changeAmt != 0)
		 {
			 numNick = changeAmt / 5;
			 totCoins += numNick;
			 changeAmt = changeAmt % 5;
			 if(changeAmt != 0)
			 {
				 numPen = changeAmt;
				 totCoins += numPen;
			 }
		 }
	 }
	 cout << "Amount requested: $" << changeAmt << endl;
	 cout << "Quarters: " << numQuart << endl;
	 cout << "Dimes: " << numDime << endl;
	 cout << "Nickels: " << numNick << endl;
	 cout << "Pennies: " << numPen << endl << endl;
	 cout << "Total coins used: " << totCoins << endl;
 }