/*
 * TemperatureData.h
 *
 *  Created on: Jul 16, 2018
 *      Author: Michaela Matocha
 */

#ifndef TEMPERATUREDATA
#define TEMPERATUREDATA

#include <string>

struct TemperatureData {
	std::string id;
	int year;
	int month;
	double temperature;
	TemperatureData();
	TemperatureData(std::string id, int year, int month, double temperature);
	virtual ~TemperatureData();
	bool operator<(const TemperatureData& b);
	
};

#endif /* TEMPERATUREDATA */
