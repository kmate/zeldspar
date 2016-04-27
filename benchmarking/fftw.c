// One-dimensional double-precision complex FFT
// reference implementation using FFTW library
// Compile and run with: 
// gcc -std=gnu99 fftw.c -o fftw -lfftw3 && ./fftw > fftw_out.txt
#include <fftw3.h>
#include "benchmark.h"

// #define N (1 << 15)
// #define ROUNDS (1 << 5)

int main(int argc, char **argv) {
    fftw_complex *in, *out;
    fftw_plan p;
    
    in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    
    for (int r = 0; r < ROUNDS; ++r) {
        for (int i = 0; i < N; ++i) {
            in[i][0] = r + i;
            in[i][1] = r - i;
            // fprintf(stderr, "%f %f\n", in[i][0], in[i][1]);
        }

        start_iteration();
        p = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
        fftw_execute(p);
        fftw_destroy_plan(p);
        end_iteration();
    }
    print_time();
    
    for (int i = 0; i < N; ++i) {
        printf("%+10.5f %+10.5f\n", out[i][0], out[i][1]);
    }
    
    fftw_free(in);
    fftw_free(out);
    return 0;
}

