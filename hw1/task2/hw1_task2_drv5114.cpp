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
#include <stdlib.h>

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

void benchmark(int state){
	// Initialize stuff here...
	double d_S,d_E;
	int N = 1000;
	int R = 1000000;
	double *A = new double[N];
	double *B = new double[N];
	double *C = new double[N];
	double *D = new double[N];
	
	for(int i = 0; i < N; i++){
		A[i] = 0e0;
		B[i] = 1e0;
		D[i] = 3e0;
	}
	
	if(state == 0){
		for(int i = 0; i < N; i++){
			C[i] = 1e0;
		}
	}
	else if(state == 1){
		for(int i = 0; i < N; i++){
			C[i] = -(1e0);
		} 
	}
	else{
		for(int i = 0; i < N; i++){
			C[i] = (rand() % 2) - 1;
		}
	}
	
	get_walltime(&d_S);  // get start time
	// place test code here
	for(int j = 0; j < R; j++){
		for(int i = 0; i < N; i++){
			if(C[i] < 0e0){
				A[i] = B[i] - C[i] * D[i];
			}
			else{
				A[i] = B[i] + C[i] * D[i];
			}
		}
	}


	get_walltime(&d_E); // get end time stamp

	// report results here
	double MFLOPS = (double)R*(double)N*2e0/((d_E - d_S)*1.0e6);
	printf("Elapsed time: %f\n", d_E - d_S);
	printf("MFLOPS: %f\n", MFLOPS);
	
}

///////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
	int vals[3] = {0, 1, 2};
	for(int i = 0; i < 3; i++){
		benchmark(i);
	}
	
	// perform cleanup here
	


	return 0;
}

