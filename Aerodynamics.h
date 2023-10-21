#include <iostream>
#include <fstream>
#include <sstream>
#define M_PI 3.14159265358979323846
using namespace std;

class Aerodynamics
{
public:
    Aerodynamics()
    {
        

        ifstream file("CX.dat");
        
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 11; j++)
                file >> Cx[j][i];

        ifstream file2("CY.dat");

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 11; j++)
                file2 >> Cy[j][i];



    }
	
    double get_CX(double M, double a)
    {
        double out = 0;
        
        for (int n = 0; n < 3; n++)
            for (int m = 0; m < 11; m++)
            {
                double val=1;
                    for (int i = 0; i < 3; i++)
                        if (i != n)
                            for (int j = 0; j < 11; j++)
                                if (m != j)
                                    val *= ((M - Mah[j]) * (a - alfa[i])) / ((Mah[m] - Mah[j]) * (alfa[n] - alfa[i]));  
                out += (Cx[m][n] * val);
            }
        return out;
    }
    double get_CY(double M, double a)
    {
        double out = 0;

        for (int n = 0; n < 3; n++)
            for (int m = 0; m < 11; m++)
            {
                double val = 1;
                for (int i = 0; i < 3; i++)
                    if (i != n)
                        for (int j = 0; j < 11; j++)
                            if (m != j)
                                val *= ((M - Mah[j]) * (a - alfa[i])) / ((Mah[m] - Mah[j]) * (alfa[n] - alfa[i]));
                out += (Cy[m][n] * val);
            }
        return out;
    }




private:
    
    int i = 0;
    double alfa[3] = { M_PI / 18, M_PI / 9, M_PI / 6 };
    double Mah[11] = { 0.3, 0.6, 0.9, 1, 1.3, 1.5, 2, 3, 4, 6, 10 };
    double Cx[11][3];
    double Cy[11][3];
};



