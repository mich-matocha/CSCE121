/*
 * TemperatureData.cpp
 *
 *  Created on: Jul 16, 2018
 *      Author: Michaela Matocha
*/

#include "TemperatureData.h"
using namespace std;

TemperatureData::TemperatureData()
{id = ""; year = 1800; month = 1; temperature = 0;} //initialize everything

TemperatureData::TemperatureData(string id, int year, int month, double temperature)
{this->id = id; this->year = year; this->month = month; this->temperature = temperature;} //initialize everything


TemperatureData::~TemperatureData() {} // You should not need to implement this

bool TemperatureData::operator<(const TemperatureData& b) { //maybe this is actually what's going wrong??

	if(id < b.id)
	{
		return true;
	}

	if(id == b.id && year < b.year)
		return true;

	if(id == b.id && year == b.year && month < b.month)
		return true;

	if(id == b.id && year == b.year && month == b.month && temperature < b.temperature)
		return true;

	return false;
}
