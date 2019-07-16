#include <iostream>
#include "TemperatureData.h"
#include "TemperatureDatabase.h"
#include "Node.h"
#include "LinkedList.h"

using namespace std;

int main(int argc, char **argv)
{
	TemperatureDatabase td = TemperatureDatabase();
	td.loadData(argv[1]);
	td.performQuery(argv[2]);

}