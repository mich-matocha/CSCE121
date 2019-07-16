#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <limits>
#include <cstddef>

using namespace std;

int main(int argv, char* argc[])
{
    if (argv != 2) {
        cerr << "Usage: ./a.out filename.dat" << endl;
        return 1;
    }
    string inputFile = argc[1];
    cout << "File with input data : " << inputFile << endl;

    ifstream inFS;
    string fileNum;
    inFS.open(inputFile);
    vector<int> x(0);
    vector<int> y(0);
    vector<int> z(0);
    int readX = 0;
    int readY = 0;
    char skipC = -1;

    if(!inFS.is_open())
    {
        cout << "error..." << endl;
    }
    while(!inFS.eof())
    {
        inFS >> readX >> skipC >> readY;
        x.push_back(readX);
        y.push_back(readY);
    }
 
    double smallDistIndex = -1;
    
    for(int i = 0; i < x.size(); i++)
    {
        double smallDist = numeric_limits<double>::max();
        for(int j = 0; j < y.size(); j++)
            if(j != i)
            {
                double dist = sqrt(pow(x.at(j) - x.at(i), 2) + (pow(y.at(j) - y.at(i), 2)));
                if(dist < smallDist)
                {
                    smallDist = dist;
                    smallDistIndex = j;
                }
            }
        z.push_back(smallDistIndex);
    }

    /*for(int i = 0; i < x.size(); i++)
    {
        cout << x.at(i) << " " << y.at(i) << " " << z.at(i) << endl;
    }*/

    ofstream myfile;
    myfile.open("output.txt");
    for(int k = 0; k < z.size(); k++)
    {
        myfile << x.at(k) << "," << y.at(k) << "," << z.at(k);
        myfile << "\r\n";
    }
    myfile.close();

    return 0;
}