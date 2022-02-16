#include <math.h>

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
			printf("val: %f/n", val);
			mat[i + jlen] = s[i + jlen]*(sin(val)*sin(val)-cos(val)*cos(val));
		}
	}
}

