//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//                           LW: Hadamard matrix                            //
//                           hadamard_matrix.cpp                            //
//                                                                          //
// Written By :                         Environment :                       //
// Date ......:                         Compiler ...:                       //
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//                                #includes                                 //
//////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <math.h>
#include "hadamard_matrix.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////////
//                           function definitions                           //
//////////////////////////////////////////////////////////////////////////////
/*****************************************************************************
*                    vector<vector<bool>> hadamard(int n)                    *
*                                                                            *
*       Description ....:                                                    *
*                                                                            *
*                                                                            *
* Written By :                          Environment :                        *
* Date ......:                          Compiler ...:                        *
*****************************************************************************/
vector<vector<bool>> hadamard(int n)
{
    vector<vector<bool>> v(1, vector<bool>(1));

    v.at(0).at(0) = 1;
    vector<vector<bool>> oldV = v;

    for(int i = 1; i < n; ++i) //looping through all instances
    {
        bool currVal = false;
        int size = v.size(); //setting the size outright forces it to not reset the size each time
        for(int j = 0; j < size; ++j) //looping through rows
        {
            for(int k = 0; k < size; ++k) //looping through columns
            {
                currVal = oldV.at(j).at(k);
                v.at(j).push_back(currVal);
            }
            v.push_back(v.at(j));
            for(int h = 0; h < oldV.size(); ++h)
            {
                v.push_back(oldV.at(h));
                for(int x = 0; x < oldV.size(); ++x)
                {
                    currVal = !oldV.at(h).at(x);
                    v.at(h).push_back(currVal);
                }
            }
        }
    }
    cout << endl;

    /*for(int k = 0; k < size; k++) //k is rows
    {
        if(k < size/2) //top half of matrix
        {
            for (int i = 0; i < size; ++i) //i is columns in top half
            {
                v.at(k).at(i) = 
            }
        }
    } */   
    /*copy the matrix and create top half of new matrix
    which is the old matrix twice.
    bottom left quadrant is copy old matrix
    bottom right matrix is opposite of old matrix
        use for loop to invert each entry.
    */

   

    return v;
}


/*****************************************************************************
*                 void print (vector <vector<bool>> const&v)                 *
*                                                                            *
*       Description ....:                                                    *
*                                                                            *
*                                                                            *
* Written By :                          Environment :                        *
* Date ......:                          Compiler ...:                        *
*****************************************************************************/
void print (vector <vector<bool>> const&v) //going out of bounds?? somehow
{
    for(int i = 0; i < v.size(); ++i)
    {
        for(int j = 0; j < v.at(0).size(); ++j)
        {
            cout << v.at(i).at(j) << " ";
        }
        cout << endl;
    }
}

/*****************************************************************************
*                          int str_to_int(std::string)                       *
*                                                                            *
*       Description ....:                                                    *
*                                                                            *
*                                                                            *
* Written By :                          Environment :                        *
* Date ......:                          Compiler ...:                        *
*****************************************************************************/

int str_to_int(std::string s)
{
    stringstream ss {s}; int val;
    ss >> val;
    if (ss.fail()) {
        ss.ignore(numeric_limits<streamsize>::max(), '\n');
        ss.clear();
        throw runtime_error("Value provided not an integer");
    }

    return val;
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////