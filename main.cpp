#include <iostream>
#include <fstream>
#include "Aerodynamics.h"
#include "Atmosphere.h"
#define M_PI 3.14159265358979323846
using namespace std;

int main()
{

	Aerodynamics aero;
	Atmosphere atmo;

	double Vr = 0;
	double Vphi = 7544.6;
	double r = 6771000;
	double phi = 0;
	double h = 1;
	double T = 0;
	double dr, dphi, dvr, dvphi, Cx;

	double const mu = 3.986 * 1e14;
	ofstream file;
	file.open("results.csv");
	while ( r > 6371000)
	{
		double H = r / 1000 - 6371;

		double ro = atmo.get_density(r - 6371000);

		if (H < 7)
		{
			Cx = 21;
		}	
		else
		{
			Cx = 1.5;
		}

		if (H < 100)
		{
			cout << H <<"       " << sqrt(Vr * Vr + Vphi * Vphi) / atmo.get_speed_of_sound(H) << endl;
		}

		double Fx = Cx*15 * ro * Vphi * abs(Vphi) / 2;
		double acc = Fx / 19500;

		dr = Vr;
		dphi = Vphi / r;
		dvr = pow(Vphi,2) / r - mu / (r * r);
		dvphi = -Vr * Vphi / r - acc;

		


		r += dr * h;
		phi += dphi * h;
		Vr += dvr * h;
		Vphi += dvphi * h;
		T += h;
		file << phi << ";" << H << ";"<< sqrt(Vr*Vr+Vphi*Vphi) << endl;

	}

	
	
	
	return 0;
}