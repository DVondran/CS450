#include <iostream>
#include <sys/time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "sd_thread.h"

using namespace std;

STDDEV_RESULT* calcSdThread(double *A, long N, int P)
{
    struct STDDEV_RESULT* res = new STDDEV_RESULT;
    
    double sd_temp, mean, min, max, sd;
    
    min = RAND_MAX;
    max = 0.0;
    sd = 0;
    sd_temp = 0;
    mean = 0;

	#pragma omp parallel num_threads(P)
	{
		// perform the summation for the mean
		#pragma omp for reduction(+:mean)
			for(long i = 0; i < N; i++)
			{
				mean = mean+A[i];
				if(max < A[i])
				{
					max = A[i];
				}
				if(min > A[i])
				{
					min = A[i];
				}
			}
	}

	mean /= (double) N;

	#pragma omp parallel num_threads(P)
	{
		// perform the summation for the std_dev
		#pragma omp for reduction(+:sd_temp)
			for(long i = 0; i < N; i++)
			{
				sd_temp += (A[i] - mean) * (A[i] - mean);
			}	
	}
	
	sd=sqrt(sd_temp/(double)N);
	
	// store off the values to return 
	res->mean = mean;
	res->min = min;
	res->max = max;
	res->stddev = sd;
	
    return res;
}

THRESH_RESULT *findThreshValuesThread(double *A, long N, double T, int P)
{
	THRESH_RESULT *p_tmpResult = new THRESH_RESULT;
	
	// traverse the list once to find the count of values over threshold
	long c = 0;
	#pragma ompparallel for
	{
		for (long i=0; i < N; i++)
		{
			if (A[i] > T)
				c++;
		}
	}

	
	// store the count and allocate an array to store the results
	p_tmpResult->li_threshCount = c;
	p_tmpResult->pli_list = new long[c];
	c = 0;
	
	// store the index locations of the values over threshold
	for (long i=0; i < N; i++){
		if (A[i] > T){
			p_tmpResult->pli_list[c] = i;
			c++;
		}
	}
	
	return p_tmpResult;
}
