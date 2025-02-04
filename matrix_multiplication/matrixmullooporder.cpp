#include <iostream>
#include <iomanip>
#include <sys/time.h>

using namespace std;

#define n 4096

double A[n][n], B[n][n], C[n][n];

int main() { 
    
    
    // Initialize Matrices
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        {
            A[i][j] = (double)rand()/ (double)RAND_MAX;
	    B[i][j] = (double)rand()/ (double)RAND_MAX;
	    C[i][j] = 0;
        }

    struct timeval start, end; 
  
    // start timer. 
    gettimeofday(&start, NULL); 
  
    // unsync the I/O of C and C++. 
    ios_base::sync_with_stdio(false);

    // Matrix multiplication
    for(int i = 0; i < n; ++i) {
        for(int k = 0; k < n; ++k) {
      for(int j = 0; j < n; ++j)
	    {
                C[i][j] += A[i][k] * B[k][j];
            }
	}
    }
    
    gettimeofday(&end, NULL);

    // Calculating total time taken by the program.
    double time_taken;

    time_taken = (end.tv_sec - start.tv_sec) * 1e6;
    time_taken = (time_taken + (end.tv_usec -
                              start.tv_usec)) * 1e-6;

    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(6);
    cout << " sec" << endl;  

    return 0;
}
