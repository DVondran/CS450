///////////////////////////////////////////////////////////////////////
//
// CMPSC450 
//
// Benchmark Template
// 
// Author: Mr. Seisler
//
// compile line:
// g++ -o bench_tmp benchmark_template.cpp -O3
//
///////////////////////////////////////////////////////////////////////
#include <sys/time.h>
#include <stdio.h>

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

///////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{

	// Initialize stuff here...
	double d_S,d_E;
	int N = 1000;
	int R = 1000000;
	double *A = new double[N];
	double *B = new double[N];
	double *C = new double[N];
	double *D = new double[N];


	get_walltime(&d_S);  // get start time
	// place test code here
	for(int i = 0; i < N - 1; i++){
		if(C[i] < 0.0){
			A[i] = B[i] - C[i] * D[i];
		}
		else{
			A[i] = B[i] + C[i] * D[i];
		}
	}


	get_walltime(&d_E); // get end time stamp

	// report results here
	int MFLOPS = (double)R*(double)*2/((d_E - d_S)*1.0e6);
	printf("Elapsed time: %f\n", d_E - d_S);
	printf("MFLOPS: %f\n", MFLOPS);
	
	
	// perform cleanup here
	


	return 0;
}

