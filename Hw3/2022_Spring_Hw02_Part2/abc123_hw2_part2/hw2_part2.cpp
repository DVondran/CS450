#include <iostream>
#include <sys/time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <chrono>


struct MYPARAM{
	int i_start;
	int i_stop;
	double d_result;
	double *d_min;
	double *d_max;
	};
	
ResultParam* calcSdThread(double *A, long N, int P)
{
    struct ResultParam* res = new ResultParam;
    
    double sd_temp, mean, min, max, sd;
    
    min = RAND_MAX;
    max = 0.0;
    sd = 0;
    sd_temp = 0;
    mean = 0;
	
	std::thread t[P];
	struct MYPARAM *p_params = new struct MYPARAM[P];
	
	//Setting up threads
	for (int i = 0; i < P; i++)
	{
		p_params[i].i_start = i * (N/P);
		p_params[i].i_stop = (i + 1) * (N/P);
		p_params[i].d_result = 0.0;
	}
	
	//Threading for Mean Calculation, also finds min and max values
	for (int i = 0; i < P; i++)
	{
		t[i] = std::thread(meanfunc, &p_params[i], A, i);
	}
	
	for (int i = 0; i < P; i++)
		t[i].join();


	for (int i = 0; i < P; i++)
		mean += p_params[i].d_result;
	mean /= (double) N;
	
	//Threading for sd Calculation
	for (int i = 0; i < P; i++)
	{
		t[i] = std::thread(sdfunc, &p_params[i], A, mean);
	}
	
	for (int i = 0; i < P; i++)
		t[i].join();


	for (int i = 0; i < P; i++)
		sd += p_params[i].d_result;
	
	sd=sqrt(sd/(double)N);
	
	delete[] p_params;
	
	// store off the values to return 
	res->mean = mean;
	res->min = min;
	res->max = max;
	res->stddev = sd;
	
    return res;
}






// complex algorithm for evaluation
void matrix_mult(double *A, double *B, double *C, int N)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			C[i * N + j] = 0;
				for (int k = 0; k < N; k++)
				{
					C[i * N + j] += A[i * N + k] * B[k * N + j];
				}
		}
}

