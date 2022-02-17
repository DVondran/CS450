/*

AUTHOR: David Vondran
PSU ID: drv5114


*/

#include <math.h>

#include <stdio.h>

//Testing Working

//Mathematics inside the algorithm removed for simplification
double getSquaredVal(double val)
{
	double sinval = sin(val)*sin(val);
	return (sinval - (1 - (sinval)));
}

// complex algorithm for evaluation
void myfunc(double *s, double *mat, int *v, int length)
{
	// this assumes that the two dimensional vector is square 

	//double val;
	double *val = new double[length];
	double *squaredvals = new double[length];
	
	for (int i = 0; i < length; i++)
	{
		val[i] = round(fmod(v[i],256));
		squaredvals[i] = getSquaredVal(val[i]);
	}
	
	for (int j = 0; j < length; j += 5)
	{
		int jlen = j * length;
		int jlen1 = (j+1) * length;
		int jlen2 = (j+2) * length;
		int jlen3 = (j+3) * length;
		int jlen4 = (j+4) * length;
		for (int i = 0; i < length; i +=5)
		{
			mat[i + jlen] = s[i + jlen]*(squaredvals[i]);
			mat[i + jlen1] = s[i + jlen1]*(squaredvals[i]);
			mat[i + jlen2] = s[i + jlen2]*(squaredvals[i]);
			mat[i + jlen3] = s[i + jlen3]*(squaredvals[i]);
			mat[i + jlen4] = s[i + jlen4]*(squaredvals[i]);
		}
	}
}



