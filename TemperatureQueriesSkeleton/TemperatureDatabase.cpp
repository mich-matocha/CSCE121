#include "TemperatureDatabase.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	ifstream inFS;
	LinkedList ll = LinkedList();

	inFS.open(filename);
	if(!inFS.is_open())
		throw runtime_error("Unable to open " + filename);
	string id = "";
	int year = 0;
	int month = 0;
	double temp = -100;
	string line = "";
	bool valid = true;

	while(!inFS.eof())
	{
		getline(inFS, line);
		istringstream ss(line);

		vector<string> split{istream_iterator<string>{ss}, istream_iterator<string>{}};

		if(split.size() < 4 || split.size() > 4)
		{
			cout << "Error: Other invalid input" << endl;
			valid = false;
		}

		if(valid)
		{
			id = split.at(0);
			try
			{
				year = stoi(split.at(1));
			}
			catch(runtime_error &e)
			{
				cout << "Error: Other invalid input" << endl;
				valid = false;
			}
			try
			{
				month = stoi(split.at(2));
			}
			catch(runtime_error &e)
			{
				cout << "Error: Other invalid input" << endl;
				valid = false;
			}
			try
			{
				temp = stod(split.at(3));
			}
			catch(runtime_error &e)
			{
				cout << "Error: Other invalid input" << endl;
				valid = false;
			}
		}

		//checking values for validity
		if(valid && temp > 50 || temp < -50) //making sure the temp makes sense!
		{
			cout << "Error: Invalid temperature " << temp << endl;
			valid = false;
		}

		else if(valid && month <= 0 || month > 12)
		{
			cout << "Error: Invalid month " << month << endl;
			valid = false;
		}

		if(valid && year > 2018 || year < 1800)
		{
			cout << "Error: Invalid year " << year << endl;
			valid = false;
		}

		if(valid)
		{
			ll.insert(id, year, month, temp);
		}
		//resetting variables
		valid = true;

	}
}

void TemperatureDatabase::performQuery(const string& filename) {
	
}
