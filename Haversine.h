#pragma once
const float  PI_F = 3.14159265358979f;
#include <math.h>

class Haversine
{
public:
	static double HaversineDistance(double latDeg1, double latDeg2, double longDeg1, double longDeg2, double radiusOfSphereKM = 6371)
	{
		double latRad1 = latDeg1 * (PI_F / 180);
		double latRad2 = latDeg2 * (PI_F / 180);
		double longRad1 = longDeg1 * (PI_F / 180);
		double longRad2 = longDeg2 * (PI_F / 180);

		double deltaLat = latRad2 - latRad1;
		double deltaLong = longRad2 - longRad1;

		double scale = std::pow(10.0, 3);
		deltaLat = std::round(deltaLat * scale) / scale;
		deltaLong = std::round(deltaLong * scale) / scale;

		double sinLat = sin((deltaLat/ 2));
		double sinLong = sin((deltaLong / 2));

		double powSinLat = pow(sinLat, 2);
		double powSinLong = pow(sinLong, 2);

		double cosLatRad1 = cos(latRad1);
		double cosLatRad2 = cos(latRad2);

		double a = powSinLat + cosLatRad1 * cosLatRad2 * powSinLong;

		double sq1 = sqrt(a);
		double sq2 = sqrt(1-a);
		double c1 = atan2(sq1, sq2);
		double c = 2.0 * c1;

		double distanceBetweenTwoPointsOnSphere = radiusOfSphereKM * c;
		return distanceBetweenTwoPointsOnSphere;
	}
};

