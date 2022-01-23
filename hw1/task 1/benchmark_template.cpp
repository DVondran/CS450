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


	get_walltime(&d_S);  // get start time
	// place test code here


	get_walltime(&d_E); // get end time stamp

	// report results here
	printf("Elapsed time: %f\n", d_E - d_S);
	
	
	// perform cleanup here
	


	return 0;
}

