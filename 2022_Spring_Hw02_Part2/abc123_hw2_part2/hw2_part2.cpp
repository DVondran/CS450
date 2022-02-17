
// complex algorithm for evaluation
void matrix_mult(double *A, double *B, double *C, int N)
{
	for (int i = 0; i < N; i++)
		inval = i * N;
		for (int j = 0; j < N; j++)
		{
			C[i * N + j] = 0;
				for (int k = 0; k < N; k++)
				{
					C[inval + j] += A[inval + k] * B[k * N + j];
				}
		}
}

