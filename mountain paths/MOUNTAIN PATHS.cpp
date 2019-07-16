#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

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
    if(!(rows > 0) || !(cols > 0))
    {
        cout << "Error: Invalid row or column value.";
        return 1;
    }

	cin >> fileName;

    inFS.open(fileName); //attempt to open the file

	if(!inFS.is_open())
	{
		cout << "Error: Couldn't open file!";
		return 1;
	}

	int number = 0;

	//while(!inFS.eof() && data.size() <= cols) //reading the values from the file and inputting them into a 2d vector
	//{
		for(int i = 0; i < rows; i++)
		{
			vector<int> temp;
			for(int j = 0; j < cols; j++)
			{
				inFS >> number;

                if(&number == NULL)
                {
                    cout << "Error: Not enough values in file.";
                }
                /*if(!isdigit(number))
                {
                    cout << "Error: Chars aren't allowed!";
                }*/

				temp.push_back(number);
			}
			data.push_back(temp);
		}
	//}

    if(cols != data[0].size() || rows != data.size())
    {
        cout << "Cols/Rows not equal to vector size. ";
        cout << cols << " " << data.size() << ' ' << rows << ' ' << data[0].size();
        return 1;

    }

	int minElevation = data[0][0];
	int maxElevation = minElevation;

	for(int i = 0; i < rows; i++) //finding the minElevation and maxElevation
	{
		for(int j = 0; j < cols; j++)
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
	double greyShade;

	for(int i = 0; i < rows; i++)
	{
		vector<int> tempR;
		vector<int> tempG;
		vector<int> tempB;

		for(int j = 0; j < cols; j++)
		{
			greyShade = ((data[i][j] - double(minElevation)) / (double(maxElevation) - double(minElevation))) * 255;
			greyShade = round(greyShade);
			tempR.push_back(int(greyShade));
			tempG.push_back(int(greyShade));
			tempB.push_back(int(greyShade));
		}
		valR.push_back(tempR);
		valG.push_back(tempG);
		valB.push_back(tempB);
	}

	int shortestDist = colorPath(data, valR, valG, valB, 252, 25, 63, 0);
	int currDist = -1;
	int index = 0;

	for(int i = 1; i < rows; ++i)
	{
		currDist = colorPath(data, valR, valG, valB, 252, 25, 63, i);

		if(currDist < shortestDist)
		{
			shortestDist = currDist;
			index = i;
		}
	}

	colorPath(data, valR, valG, valB, 31, 253, 13, index);

	ofstream myfile;
	myfile.open(fileName + ".ppm");

	myfile << "P3" << endl << cols << " " << rows << endl;
	myfile << "255" << endl;

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			myfile << valR[i][j] << " " << valG[i][j] << " " << valB[i][j] << " ";
		}
	}

	myfile.close();

	return 0;
}