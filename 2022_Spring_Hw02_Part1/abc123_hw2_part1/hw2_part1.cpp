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
	
	for (int j = 0; j < length; j ++)
	{
		int jlen = j * length;
		for (int i = 0; i < length; i ++)
		{
			mat[i + jlen] = s[i + jlen]*(squaredvals[i]);
		}
	}
}



