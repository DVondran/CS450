///////////////////////////////////////////////////////////////////////
//
// CMPSC450 
//
// Benchmark Template
// 
// Author: David Vondran
//
// compile line:
// g++ -o bench_tmp benchmark_template.cpp -O3
//
///////////////////////////////////////////////////////////////////////
#include <sys/time.h>
#include <stdio.h>
#include <math.h>

///////////////////////////////////////////////////////////////////////
// A simple subroutine to get the current wall time.
//
// Assigns wcTime the value of time in seconds
///////////////////////////////////////////////////////////////////////
void get_walltime(double* wcTime) {

     struct timeval tp;

     gettimeofday(&tp, NULL);

     *wcTime = (double)(tp.tv_sec + tp.tv_usec/1000000.0);

}

void dummy(double* one, double* two, double* three, double* four){
	;
}

void benchmark(int N_in, int R_in){
	// Initialize stuff here...
	int N = N_in;
	int R = R_in;
	double d_S,d_E;
	double *A = new double[N];
	double *B = new double[N];
	double *C = new double[N];
	double *D = new double[N];
	
	for(int i = 0; i < N; i++){
		A[i] = 0e0;
		B[i] = 1e0;
		C[i] = 2e0;
		D[i] = 3e0;
	}


	get_walltime(&d_S);  // get start time
	// place test code here
	
	for(int i = 0; i < R; i++){
		for(int j=0; j < N; j++){
			A[j] = B[j] + C[j] * D[j];
		}
		if(A[2] < 0){
			dummy(A, B, C, D);
		}
	}


	get_walltime(&d_E); // get end time stamp

	// report results here
	double MFLOPS = (double)R*(double)N*2e0/((d_E - d_S)*1e6);
	//printf("Elapsed time: %f\n", d_E - d_S);
	//printf("MFLOPS: %f\n", MFLOPS);
	printf("%i, %i, %f, %f\n", R, N, d_E-d_S, MFLOPS);
}

///////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
	/*
	for(double i = 0; i < 7; i += .10){
		int N = pow(10, i);
		int R = 100000000 / N;
		benchmark(N, R);
	}
	*/
	
	int N = 1000;
	int R = 1000000;
	
	benchmark(N,R);
	
	
	
	// perform cleanup here
	

	return 0;
}

