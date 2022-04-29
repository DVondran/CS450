#include <iostream>
#include <sys/time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <chrono>

#include "hw2_part2.h"




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

