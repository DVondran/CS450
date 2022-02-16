#include <math.h>

#include <stdio.h>

//Testing Working

// complex algorithm for evaluation
void myfunc(double *s, double *mat, int *v, int length)
{
	// this assumes that the two dimensional vector is square 

	double val;
	
	for (int j = 0; j < length; j ++)
	{
		int jlen = j * length;
		for (int i = 0; i < length; i++)
		{
			val = round(fmod(v[i],256));
			//double sinval = sin(val)*sin(val);
			//double squaredval = sin(val)*sin(val) - (1.0 - sin(val)*sin(val));
			mat[i + jlen] = s[i + jlen]*(sin(val)*sin(val) - (1.0 - sin(val)*sin(val)));
		}
	}
}

