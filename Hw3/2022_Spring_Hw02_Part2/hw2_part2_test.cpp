#include <iostream>
#include <sys/time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits>

#include "hw2_part2.hpp"

void get_walltime(double* wcTime) {

     struct timeval tp;

     gettimeofday(&tp, NULL);

     *wcTime = (double)(tp.tv_sec + tp.tv_usec/1000000.0);

}

// complex algorithm for evaluation
void matrix_mult_orig(double *A, double *B, double *C, int N)
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

void compareOutputs(double *output1, double *output2, int length)
{
	for (int i = 0; i < length; i++)
		for (int j = 0; j < length; j++)
		{
			if (output1[i * length + j] != output2[i * length + j])
			{
				printf("Outputs do not match! (%i, %i) (%f, %f)\n", 
					i, j, 
					output1[i * length + j], output2[i * length + j]);
				return;
			}
		}
	
	printf("Output match, test passed!\n");
						
}


int main(int argc, char *argv[])
{
	
	//int nvals[22] = {100, 300, 500, 700, 900, 1100, 1300, 1500, 1700, 2000, 2200, 2500, 2700, 3000, 3300, 3500, 3700, 4000, 4300, 4500, 4700, 5000};
	int pvals[6] = {2, 4, 5, 10, 15, 20};
	
	for(int tmpint = 0; tmpint < 6; tmpint++)
	{
		int N = 2000;
		//int N = nvals[tmpint];
		//int P = 10;
		int P = pvals[tmpint];

		double d_S, d_E;

		// some declarations
		double *A = new double[N * N];
		double *B = new double[N * N];
		double *C = new double[N * N];
		double *orig_C = new double[N * N];
	

		// populate memory with some random data
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				A[i * N + j] = i * i;
				B[i * N + j] = (double)j / (double) (i + 1);
			}
		}

		double serial_duration, thread_duration;
		
		/*
	
		// start benchmark
		get_walltime(&d_S);

		// run the original for functional verification
		matrix_mult_orig(A, B, orig_C, N);
	
		// end benchmark
		get_walltime(&d_E);
		serial_duration = d_E - d_S;
		
		*/

		// start benchmark
		get_walltime(&d_S);

		// iterative test loop
		matrix_mult(A, B, C, N, P);
	
		// end benchmark
		get_walltime(&d_E);
		thread_duration = d_E - d_S;

		// check the two matrices
		//compareOutputs(orig_C, C, N);
		
		// report results
		//printf("Elapsed time: %f\n", d_E - d_S);
		printf("%i, %f\n", P, thread_duration);
		
		// cleanup!
		delete[] A;
		delete[] B;
		delete[] C;
		delete[] orig_C;
	}

	/*
	int N = 2000;
	int P = 10;

	double d_S, d_E;

	// some declarations
	double *A = new double[N * N];
	double *B = new double[N * N];
	double *C = new double[N * N];
	double *orig_C = new double[N * N];
	

	// populate memory with some random data
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			A[i * N + j] = i * i;
			B[i * N + j] = (double)j / (double) (i + 1);
		}
	}

	double serial_duration, thread_duration;
	
	// start benchmark
	get_walltime(&d_S);

	// run the original for functional verification
	matrix_mult_orig(A, B, orig_C, N);
	
	// end benchmark
	get_walltime(&d_E);
	serial_duration = d_E - d_S;

	// start benchmark
	get_walltime(&d_S);

	// iterative test loop
	matrix_mult(A, B, C, N, P);
	
	// end benchmark
	get_walltime(&d_E);
	thread_duration = d_E - d_S;

	// check the two matrices
	compareOutputs(orig_C, C, N);
		
	// report results
	//printf("Elapsed time: %f\n", d_E - d_S);
	printf("Serial: %f, Threaded: %f\n", serial_duration, thread_duration);

	
	// cleanup!
	delete[] A;
	delete[] B;
	delete[] C;
	delete[] orig_C;
	
	*/

	return 0;
}
