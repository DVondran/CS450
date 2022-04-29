#include <iostream>
#include <sys/time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <chrono>

#include "hw2_part2.hpp"

struct MYPARAM{
	int i_start;
	int i_stop;
	};
	
void inner_matrix_mult(struct MYPARAM *p_params, double *A, double *B, double *C, int N)
{
	int i = p_params->i_start;
	
	for (int j = p_params->i_start; j < p_params->i_stop; j++)
	{
		C[i * N + j] = 0;
		for (int k = 0; k < N; k++)
		{
			C[i * N + j] += A[i * N + k] * B[k * N + j];
		}
	}
	
	N++;
}


// complex algorithm for evaluation
void matrix_mult(double *A, double *B, double *C, int N, int P)
{
	std::thread t[P];
	struct MYPARAM *p_params = new struct MYPARAM[P];
	
	//Setting up threads
	for (int i = 0; i < P; i++)
	{
		p_params[i].i_start = i * (N/P);
		p_params[i].i_stop = (i + 1) * (N/P);
	}
	
	//Running the inner method on the threads
	for (int i = 0; i < P; i++)
	{
		t[i] = std::thread(inner_matrix_mult, &p_params[i], A, B, C, N);
	}
	
	//Joining threads
	for (int i = 0; i < P; i++)
		t[i].join();
}

