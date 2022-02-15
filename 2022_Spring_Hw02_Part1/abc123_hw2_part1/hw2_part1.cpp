#include <math.h>

//Testing

// complex algorithm for evaluation
void myfunc(double *s, double *mat, int *v, int length)
{
	// this assumes that the two dimensional vector is square 

	double val;
	
	for (int j = 0; j < length; j ++)
	{
		for (int i = 0; i < length; i++)
		{
			val = round(fmod(v[i],256)); 
			mat[i + j * length] = s[i + j * length]*(sin(val)*sin(val)-cos(val)*cos(val));
		}
	}
}

