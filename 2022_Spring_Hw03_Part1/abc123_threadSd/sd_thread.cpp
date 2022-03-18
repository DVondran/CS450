#include <iostream>
#include <sys/time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread>

#include "sd_thread.h"

using namespace std;

struct MYPARAM{
	int i_start;
	int i_stop;
	//double d_step;
	double d_result;
	};
	
double meanfunc(struct MYPARAM *p_params, double *A){
	double tmpmean = 0;
	for(long i = p_params->i_start; i < p_params->i_stop; i++)
	{
		tmpmean = tmpmean+A[i];
	}
	return tmpmean;
}

STDDEV_RESULT* calcSdThread(double *A, long N, int P)
{
    struct STDDEV_RESULT* res = new STDDEV_RESULT;
    
    double sd_temp, mean, min, max, sd;
    
    min = RAND_MAX;
    max = 0.0;
    sd = 0;
    sd_temp = 0;
    mean = 0;
	
	std::thread t[P];
	struct MYPARAM *p_params = new struct MYPARAM[P];
	
	for (int i = 0; i < P; i++)
	{
		p_params[i].i_start = i * (N/P);
		p_params[i].i_stop = (i + 1) * (N/P);
		//p_params[i].d_step = 1.0 / (double) NUMSTEPS;
		p_params[i].d_result = 0.0;	
	}
	
	for (int i = 0; i < P; i++)
	{
		t[i] = std::thread(meanfunc, &p_params[i]);
	}
	
	// perform the summation for the mean
	
	/*
	for(long i = 0; i < N; i++)
	{
		mean = mean+A[i];
	}
	*/
	
	mean /= (double) N;

	// perform the summation for the std_dev
	for(long i = 0; i < N; i++)
	{
		sd_temp += (A[i] - mean) * (A[i] - mean);
	}	
	sd=sqrt(sd_temp/(double)N);
	
	// find min and max
	for(long i = 0; i < N; i++)
	{
		if(max < A[i])
		{
			max = A[i];
		}
		if(min > A[i])
		{
			min = A[i];
		}
	}
	
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
	for (long i=0; i < N; i++)
	{
		if (A[i] > T)
			c++;
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
