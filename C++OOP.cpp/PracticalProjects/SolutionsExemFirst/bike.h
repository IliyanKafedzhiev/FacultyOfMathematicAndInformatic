#ifndef BIKE_H
#define BIKE_H
#include "Part.h"
#include "Bike.h"
class bike:public Part
{
public:
	bike(void);
	~bike(void);
private:
	Part *parts;
	double bikePrice();
	char* bikeName;
};
#endif  BIKE_H

