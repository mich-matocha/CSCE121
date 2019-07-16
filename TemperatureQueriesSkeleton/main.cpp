#include "TemperatureDatabase.h"


#include <iostream>
#include <string>
using namespace std;

int main(/*int argc, char** argv*/) {
	LinkedList ll;

	//insert into empty list
	ll.insert("mac", 2015, 7, 22.3);
	cout << "inserted mac" << endl;
	cout << ll.print();

	// insert new Head
	ll.insert("abe", 2017, 6, 18.5);
	cout << ll.print();

	// insert in middle
	ll.insert("kev", 2013, 5, 19.2);
	cout << ll.print();


	// insert in middle
	ll.insert("zeb", 1995, 2, 5);
	cout << ll.print();

	/*if (argc < 3) {
		cout << "Usage: " << argv[0] << " data_file query_file" << endl;
		return 1;
	} else {
		TemperatureDatabase database;
		database.loadData(argv[1]);
		database.performQuery(argv[2]); // Will be done in Part 2
	}*/
}
