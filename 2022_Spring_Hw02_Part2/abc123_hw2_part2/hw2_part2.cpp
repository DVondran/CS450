
/*

AUTHOR: David Vondran
PSU ID: drv5114

*/

// complex algorithm for evaluation
void matrix_mult(double *A, double *B, double *C, int N)
{
	/*
	double *Anew = double[N*N]
	//getting Anew mapped in n^2 time
	for (int i = 0; i < N; i ++)
	{
		int inew = i * N;
		for (int j = 0; j < N; j++)
		{
			Anew[i] = A[inew + k];
		}
	}
	*/
	for (int i = 0; i < N; i+= 5)
	{
		for (int j = 0; j < N; j++)
		{
			//C[i * N + j] = 0;
			for (int k = 0; k < N; k++)
			{
				C[i * N + j] += A[i * N + k] * B[k * N + j];
				C[(i + 1) * N + j] += A[(i + 1) * N + k] * B[k * N + j];
				C[(i + 2) * N + j] += A[(i + 2) * N + k] * B[k * N + j];
				C[(i + 3) * N + j] += A[(i + 3) * N + k] * B[k * N + j];
				C[(i + 4) * N + j] += A[(i + 4) * N + k] * B[k * N + j];
			}
		}
	}
}
