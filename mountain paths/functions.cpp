#include<vector>
#include <climits>
#include "functions.h"
#include <cmath>
#include <iostream>

using namespace std;

int colorPath(const vector<vector<int>>& heightMap, vector<vector<int>>& r, vector<vector<int>>& g, vector<vector<int>>& b, int color_r, int color_g,
	int color_b, int start_row)
{
	int rows = heightMap.size();
	int cols = (heightMap.at(0)).size();
	int dist = 0;
	//int initHeight = -1; //this is the height at the start of the path
	int currHeight = -1;
	int southEast = -1; //southeast option for the path
	int east = -1; //east option for the path
	int northEast = -1; //northeast option for the path
	int eastDiff = 0;
	int southEastDiff = 0;
	int northEastDiff = 0;

	int x = start_row;
	int y = 0;

	//initHeight = (heightMap.at(x)).at(y); 

	(r.at(x)).at(y) = color_r; //changing color of the first step of the path
	(g.at(x)).at(y) = color_g;
	(b.at(x)).at(y) = color_b;

	for(int y = 0; y < cols - 1; ++y) //looping through the rows
	{
		currHeight = (heightMap.at(x)).at(y);

		if(x == 0) //if top row
		{
			east = (heightMap.at(x)).at(y + 1);
			southEast = (heightMap.at(x + 1)).at(y + 1);
			northEast = INT_MAX;
		}

		else if(x == rows - 1) //if bottom row
		{
			northEast = (heightMap.at(x - 1)).at(y + 1);
			east = (heightMap.at(x)).at(y + 1);
			southEast = INT_MAX;
		}

		else //anywhere else in the map
		{
			east = (heightMap.at(x)).at(y + 1);
			northEast = (heightMap.at(x - 1)).at(y + 1);
			southEast = (heightMap.at(x + 1)).at(y + 1);
		}

		eastDiff = abs(east - currHeight); //calculating possible distances
		southEastDiff = abs(southEast - currHeight);
		northEastDiff = abs(northEast - currHeight);

		if(eastDiff <= southEastDiff && eastDiff <= northEastDiff) //finding which distance is the smallest
		{
			dist += eastDiff; //if east is the smallest or equal distance to both SE and NE
			currHeight = east;
			(r.at(x)).at(y + 1) = color_r; //changing color of the next step of the path
			(g.at(x)).at(y + 1) = color_g;
			(b.at(x)).at(y + 1) = color_b;
		}

		else if(southEastDiff <= northEastDiff) //if SE is the smallest distance
		{
			dist += southEastDiff;
			currHeight = southEast;
			++x;
			(r.at(x)).at(y + 1) = color_r; //changing color of the next step of the path
			(g.at(x)).at(y + 1) = color_g;
			(b.at(x)).at(y + 1) = color_b;
		}

		else //NE is the smallest distance
		{
			dist += northEastDiff;
			currHeight = northEast;
			--x;
			(r.at(x)).at(y + 1) = color_r; //changing color of the next step of the path
			(g.at(x)).at(y + 1) = color_g;
			(b.at(x)).at(y + 1) = color_b;
		}
	}

	return dist;
}
