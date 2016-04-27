// One-dimensional double-precision complex FFT
// FFT code from the book Numerical Recipes in C
// Visit www.nr.com for the licence.
// Compile and run with: 
// gcc -std=gnu99 nr_fft.c -o nr_fft -lm && ./nr_fft > nr_fft_out.txt

// The following line must be defined before including math.h to correctly define M_PI
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "benchmark.h"

// #define N (1 << 15)
// #define ROUNDS (1 << 5)

#define PI	M_PI	/* pi to machine precision, defined in math.h */
#define TWOPI	(2.0*PI)

/*
 FFT/IFFT routine. (see pages 507-508 of Numerical Recipes in C)

 Inputs:
	data[] : array of complex* data points of size 2*NFFT+1.
		data[0] is unused,
		* the n'th complex number x(n), for 0 <= n <= length(x)-1, is stored as:
			data[2*n+1] = real(x(n))
			data[2*n+2] = imag(x(n))
		if length(Nx) < NFFT, the remainder of the array must be padded with zeros

	nn : FFT order NFFT. This MUST be a power of 2 and >= length(x).
	isign:  if set to 1, 
				computes the forward FFT
			if set to -1, 
				computes Inverse FFT - in this case the output values have
				to be manually normalized by multiplying with 1/NFFT.
 Outputs:
	data[] : The FFT or IFFT results are stored in data, overwriting the input.
*/

void four1(double data[], int nn, int isign)
{
    int n, mmax, m, j, istep, i;
    double wtemp, wr, wpr, wpi, wi, theta;
    double tempr, tempi;
    
    n = nn << 1;
    j = 1;
    for (i = 1; i < n; i += 2) {
	if (j > i) {
	    tempr = data[j];     data[j] = data[i];     data[i] = tempr;
	    tempr = data[j+1]; data[j+1] = data[i+1]; data[i+1] = tempr;
	}
	m = n >> 1;
	while (m >= 2 && j > m) {
	    j -= m;
	    m >>= 1;
	}
	j += m;
    }
    mmax = 2;
    while (n > mmax) {
	istep = 2*mmax;
	theta = TWOPI/(isign*mmax);
	wtemp = sin(0.5*theta);
	wpr = -2.0*wtemp*wtemp;
	wpi = sin(theta);
	wr = 1.0;
	wi = 0.0;
	for (m = 1; m < mmax; m += 2) {
	    for (i = m; i <= n; i += istep) {
		j =i + mmax;
		tempr = wr*data[j]   - wi*data[j+1];
		tempi = wr*data[j+1] + wi*data[j];
		data[j]   = data[i]   - tempr;
		data[j+1] = data[i+1] - tempi;
		data[i] += tempr;
		data[i+1] += tempi;
	    }
	    wr = (wtemp = wr)*wpr - wi*wpi + wr;
	    wi = wi*wpr + wtemp*wpi + wi;
	}
	mmax = istep;
    }
}

int main(int argc, char *argv[])
{
	int i;
	double *X;
    
    for (int r = 0; r < ROUNDS; ++r) {
	    /* allocate memory for N complex numbers (note the +1) */
	    X = (double *) malloc((2*N+1) * sizeof(double));
	    for(i=0; i<N; i++)
	    {
		    X[2*i+1] = r + i;
		    X[2*i+2] = r - i;
		    // fprintf(stderr, "%f %f\n", X[2*i+1], X[2*i+2] = r - i);
	    }
        
        start_iteration();
	    four1(X, N, 1);
	    end_iteration();
    }
    print_time();
    
	for(i=0; i<N; i++)
	{
        printf("%+10.5f %+10.5f\n", -X[2*i+2], -X[2*i+1]);
	}
    
    return 0;
}

