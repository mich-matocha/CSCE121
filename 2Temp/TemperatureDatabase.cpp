#include "TemperatureDatabase.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <tgmath.h>
using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	ifstream inFS;

	inFS.open(filename);
	if(!inFS.is_open())
		cout << "Error: Unable to open " << filename << endl;
	else
	{
		while(!inFS.eof())
		{
			string id = "";
			int year = 0;
			int month = 0;
			double temp = -100;
			string line = "";
			bool valid = true;

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
				//cout << "Error: Invalid temperature " << temp << endl;
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
				this->records.insert(id, year, month, temp);
			}
			//resetting variables
			valid = true;

		}
	}
}

void TemperatureDatabase::performQuery(const string& filename) {
	ifstream inFS;
	ofstream result;
	string line = "";

	inFS.open(filename);
	if(!inFS.is_open())
		throw runtime_error("Unable to open " + filename);

	result.open("result.dat");

	while(!inFS.eof())
	{
		getline(inFS, line);
		istringstream ss(line);

		vector<string> split{istream_iterator<string>{ss}, istream_iterator<string>{}};

		string data = this->records.print();
		istringstream st(data);
		vector<string> datav{istream_iterator<string>{st}, istream_iterator<string>{}};

		string givenLoc = "";
		int startYear = 0;
		int endYear = 0;

		if(datav.size() < 4)
		{
			cout << "Error: Other invalid input" << endl;
		}

		else if(split.at(1) == "AVG")
		{
			double sum = 0;
			int count = 0;
			givenLoc = split.at(0);
			startYear = stoi(split.at(2));
			endYear = stoi(split.at(3));
			int currYear = 0;

			if(startYear <= endYear && startYear >= 1800 && startYear <= 2018 && endYear >=1800 && endYear <= 2018) //ensuring range is acceptable
			{
				for(int i = 0; i < datav.size() - 3; i += 4) // running through each of the locations
				{
					currYear = stoi(datav.at(i + 1)); //year at current data point
					if(givenLoc == datav.at(i) && currYear <= endYear && currYear >= startYear)
					{
						sum += stod(datav.at(i + 3)); //adding temp to sum
						++count; //counting number of data points that fit the criteria to calc
					}
				}

				result << givenLoc << " " << startYear << " " << endYear << " AVG ";
				if(count == 0)
					result << "unknown" << endl;
				else
				 	result << sum / count << endl;
			}
			else
			{
				cout << "Error: Invalid range " << startYear << "-" << endYear << endl;
			}
		}
		else if(split.at(1) == "MODE") //FIXME! calculating mode incorrectly
		{
			givenLoc = split.at(0);
			startYear = stoi(split.at(2));
			endYear = stoi(split.at(3));
			int currTemp = 0;
			int currYear = 0;
			vector<int> values;
			vector<int> frequency;
			bool contains = false;
			//Every time the program encounters a new temp value, it will add it to a list.
			//A parallel list will hold the frequency of each value
			//First looping through data, will look at every relevant point and add/increment value/value count
			//then look to see which count is the largest, then add the result to result file
			if(startYear <= endYear && startYear >= 1800 && startYear <= 2018 && endYear >=1800 && endYear <= 2018) //ensuring range is acceptable
			{
				for(int i = 0; i < datav.size() - 3; i += 4) // running through each of the locations
				{
					currYear = stoi(datav.at(i + 1)); //year at current data point
					if(givenLoc == datav.at(i) && currYear <= endYear && currYear >= startYear) //if location is correct and year is in range
					{
						currTemp = round(stod(datav.at(i + 3))); //setting current temp
						for(int j = 0; j < values.size(); ++j)
						{
							if(values.at(j) == currTemp)
							{
								contains = true;
								++frequency.at(j);
							}
						}
						if(!contains)
						{
							values.push_back(currTemp);
							frequency.push_back(1);
						}
						contains = false;
					}
				}
				int largestIndex = 0;

				//looping through frequency to find the largest value
				for(int k = 0; k < frequency.size(); ++k)
				{
					if(frequency.at(k) >= frequency.at(largestIndex))
						largestIndex = k;
				}

				result << givenLoc << " " << startYear << " " << endYear << " MODE ";

				if(values.size() > 0)
					result << values.at(largestIndex) << endl;
				else
					result << "unknown" << endl;
			}
			else
			{
				cout << "Error: Invalid range " << startYear << "-" << endYear << endl;
			}
		}

		else
		{
			cout << "Error: Unsupported query " << split.at(1) << endl;
		}
	}
	result.close();
}
