#pragma once
#include "BaseRunner.h"
#include <iostream>
#include "Haversine.h"

class HaversineRunner : public BaseRunner
{
public:
	void Run() 
	{
		std::cout << "\nHaversine Test:\n";
		double lat1Deg = 40.7128;
		double lat2Deg = 51.5074;
		double long1Deg = -74.0060; //west of the prime meridian gets negative value
		double long2Deg = 0.1278;

		std::cout << "Result = " << Haversine::HaversineDistance(lat1Deg, lat2Deg, long1Deg, long2Deg);

	}
};