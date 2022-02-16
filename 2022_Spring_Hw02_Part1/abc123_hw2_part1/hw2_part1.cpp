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
		int jlen1 = (j+1) * length;
		int jlen2 = (j+2) * length;
		int jlen3 = (j+3) * length;
		int jlen4 = (j+4) * length;
		for (int i = 0; i < length; i ++)
		{
			mat[i + jlen] = s[i + jlen]*(getSquaredVal(val[i]));
			mat[i + jlen1] = s[i + jlen1]*(getSquaredVal(val[i]));
			mat[i + jlen2] = s[i + jlen2]*(getSquaredVal(val[i]));
			mat[i + jlen3] = s[i + jlen3]*(getSquaredVal(val[i]));
			mat[i + jlen4] = s[i + jlen4]*(getSquaredVal(val[i]));
		}
	}
}



