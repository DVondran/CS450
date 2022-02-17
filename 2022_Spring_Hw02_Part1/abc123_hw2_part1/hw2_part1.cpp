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
			mat[i + 1 + jlen1] = s[i + 1 + jlen1]*(squaredvals[i + 1]);
			mat[i + 2 + jlen2] = s[i + 2 + jlen2]*(squaredvals[i + 2]);
			mat[i + 3 + jlen3] = s[i + 3 + jlen3]*(squaredvals[i + 3]);
			mat[i + 4 + jlen4] = s[i + 4 + jlen4]*(squaredvals[i + 4]);
		}
	}
}



