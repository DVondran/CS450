#include <iostream>
#include <sys/time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// complex algorithm for evaluation
void matrix_mult(double *A, double *B, double *C, int N)
{
	#pragma omp parallel num_threads(10)
	{
		#pragma omp for
		for (int i = 0; i < N; i++)
			#pragma omp for
			for (int j = 0; j < N; j++)
			{
				C[i * N + j] = 0;
					#pragma omp for
					for (int k = 0; k < N; k++)
					{
						C[i * N + j] += A[i * N + k] * B[k * N + j];
					}
		}
	}
}

