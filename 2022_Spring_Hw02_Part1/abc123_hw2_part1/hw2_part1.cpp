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

	double val;
	
	for (int j = 0; j < length; j ++)
	{
		int jlen = j * length;
		for (int i = 0; i < length; i += 10)
		{
			val1 = round(fmod(v[i],256)); 
			mat[i + jlen] = s[i + jlen]*(getSquaredVal(val1));
			
			val2 = round(fmod(v[i + 1],256)); 
			mat[(i + 1) + jlen] = s[(i + 1) + jlen]*(getSquaredVal(val2));
			
			val3 = round(fmod(v[i + 2],256)); 
			mat[(i + 2) + jlen] = s[(i + 2) + jlen]*(getSquaredVal(val3));
			
			val4 = round(fmod(v[i + 3],256)); 
			mat[(i + 3) + jlen] = s[(i + 3) + jlen]*(getSquaredVal(val4));
			
			val5 = round(fmod(v[i + 4],256)); 
			mat[(i + 4) + jlen] = s[(i + 4) + jlen]*(getSquaredVal(val5));
			
			val6 = round(fmod(v[i + 5],256)); 
			mat[(i + 5) + jlen] = s[(i + 5) + jlen]*(getSquaredVal(val6));
			
			val7 = round(fmod(v[i + 6],256)); 
			mat[(i + 6) + jlen] = s[(i + 6) + jlen]*(getSquaredVal(val7));
			
			val8 = round(fmod(v[i + 7],256)); 
			mat[(i + 7) + jlen] = s[(i + 7) + jlen]*(getSquaredVal(val8));
			
			val9 = round(fmod(v[i + 8],256)); 
			mat[(i + 8) + jlen] = s[(i + 8) + jlen]*(getSquaredVal(val9));
			
			val10 = round(fmod(v[i + 9],256)); 
			mat[(i + 9) + jlen] = s[(i + 9) + jlen]*(getSquaredVal(val10));
		}
	}
}



