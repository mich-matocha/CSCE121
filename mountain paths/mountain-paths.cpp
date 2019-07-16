#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

/*void push_back(vector<int> v, vector<int> temp)
{
	v.at(v.size() - 1) = temp;
}
*/
int main()
{
	ifstream inFS;

	vector<vector<int>> data;

	int cols = 0;
	int rows = 0;
	string fileName;

	cin >> rows; //reading in row and column values as well as what file will be opened
	cin >> cols;
	cin >> fileName;

	inFS.open(fileName);

	if(!inFS.is_open())
	{
		cout << "Couldn't open file!";
		return 1;
	}

	int number = 0;

	while(!inFS.eof()) //reading the values from the file and inputting them into a 2d vector
	{
		for(int i = 0; i < cols; i++)
		{
			vector<int> temp;
			for(int j = 0; j < rows; j++)
			{
				inFS >> number;
				temp.push_back(number);
			}
			data.push_back(temp);
		}
	}

	int minElevation = data[0][0];
	int maxElevation = minElevation;

	for(int i = 0; i < cols; i++) //finding the minElevation and maxElevation
	{
		for(int j = 0; j < rows; j++)
		{
			if(data[i][j] < minElevation)
			{
				minElevation = data[i][j];
			}
			if(data[i][j] > maxElevation)
			{
				maxElevation = data[i][j];
			}
		}
	}

	vector<vector<int>> valR; //vectors that will hold the RGB values for each elevation
	vector<vector<int>> valG;
	vector<vector<int>> valB;
	double greyShade = 0;

	for(int i = 0; i < cols; i++)
	{
		vector<int> tempR;
		vector<int> tempG;
		vector<int> tempB;

		for(int j = 0; j < rows; j++)
		{
			greyShade = (data[i][j] - minElevation) / (maxElevation - minElevation) * 255;
			greyShade = round(greyShade);
			tempR.push_back(greyShade);
			tempG.push_back(greyShade);
			tempB.push_back(greyShade);
		}
		valR.push_back(tempR);
		valG.push_back(tempG);
		valB.push_back(tempB);
	}

	ofstream myfile;
	myfile.open(fileName + ".ppm");

	myfile << "P3" << endl << cols << " " << rows << endl;
	myfile << "255" << endl;

	for(int i = 0; i < cols; i++)
	{
		for(int j = 0; j < rows; j++)
		{
			myfile << valR[i][j] << " " << valG[i][j] << " " << valB[i][j] << " ";
		}
	}

	myfile.close();

	return 0;
}