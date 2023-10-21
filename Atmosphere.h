#include <iostream>
#include <Math.h>
#define M_PI 3.14159265358979323846
using namespace std;

class Atmosphere
{
private:
	
public:
	
	double get_temperature(double H)
	{
		H /= 1000;
		double T;
		if ((H >= 0) && (H < 10))
			T =  20 * (1 - H / 10) - 60 * H / 10 ;
		if ((H >= 10) && (H < 20))
			T = -60;
		if ((H >= 20) && (H < 46))
		{
			H -= 20;
			T = -60 * (1 - H / 26);
		}
		if ((H >= 46) && (H < 55))
			T = 0;
		if ((H >= 55) && (H < 84))
		{
			H -= 55;
			T = ( - 90 * H / 29);
		}
		if ((H >= 84) && (H < 94))
			T = -90;

		if (H >= 94)
		{
			H -= 94;
			T = -90 * (1 - H / 51) + 50 * H / 51;
		}

		
		return T;

	}
	double get_density(double H)
	{
		double T = get_temperature(H)+273.15;
		double g = 9.81;
		double M = 0.029;
		double R = 8.31;
		double P0 = 1e5;
		double P = P0 * exp(-M * g * H / (R * T));
		double ro = P * M / (R * T);
		return ro;
	}
	double get_speed_of_sound(double H)
	{
		double T = get_temperature(H) + 273.15;
		double c = 20.055 * sqrt(T);
		return c;
	}



};
