/*

AUTHOR: David Vondran
PSU ID: drv5114


*/

#include <math.h>

#include <stdio.h>

//Testing Working

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
	
	for (int i = 0; i < length; i++)
	{
		val[i] = round(fmod(v[i],256));
	}
	
	for (int j = 0; j < length; j += 5)
	{
		int jlen = j * length;
		for (int i = 0; i < length; i ++)
		{
			mat[i + jlen] = s[i + jlen]*(getSquaredVal(val[i]));
			mat[i + jlen + 2*length] = s[i + jlen + 2*length]*(getSquaredVal(val[i]));
			mat[i + jlen + 3*length] = s[i + jlen + 3*length]*(getSquaredVal(val[i]));
			mat[i + jlen + 4*length] = s[i + jlen + 4*length]*(getSquaredVal(val[i]));
			mat[i + jlen + 5*length] = s[i + jlen + 5*length]*(getSquaredVal(val[i]));
		}
	}
}



