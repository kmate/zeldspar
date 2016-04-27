// One-dimensional double-precision complex FFT
// implementation compiled from the Feldspar example
// Compile and run with: 
// gcc -std=gnu99 feldspar_fft.c -o feldspar_fft -lm && ./feldspar_fft > feldspar_fft_out.txt
#include <alloca.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>
#include "benchmark.h"

// #define N (1 << 15)
// #define ROUNDS (1 << 5)

int main()
{
    uint32_t v1;
    double _Complex *a2;
    uint32_t v3;
    uint32_t let6;
    uint32_t let7;
    uint32_t let8;
    uint32_t let9;
    uint32_t let10;
    uint32_t let11;
    uint32_t let12;
    uint32_t let13;
    uint32_t let14;
    uint32_t let15;
    uint32_t let16;
    uint32_t let17;
    uint32_t let18;
    uint32_t let19;
    uint32_t let20;
    uint32_t r21;
    uint32_t r22;
    double _Complex *a23;
    uint32_t v24;
    uint32_t v25;
    uint32_t r29;
    double _Complex *a30;
    uint32_t v31;
    uint32_t v32;
    uint32_t v36;

    v1 = N;
    a2 = alloca(v1 * sizeof(double _Complex));    

    for (int r = 0; r < ROUNDS; ++r) {
        for (int i = 0; i < v1; i++) {
            a2[i] = (r + i) + I * (r - i);
            // fprintf(stderr, "%f %f\n", creal(a2[i]), cimag(a2[i]));
        }
        
        start_iteration();
        
        let6 = v1;
        let7 = 0;
        let8 = (uint32_t) (let6 > 65535) << 4;
        let9 = let6 >> (int32_t) let8;
        let10 = let7 | let8;
        let11 = (uint32_t) (let9 > 255) << 3;
        let12 = let9 >> (int32_t) let11;
        let13 = let10 | let11;
        let14 = (uint32_t) (let12 > 15) << 2;
        let15 = let12 >> (int32_t) let14;
        let16 = let13 | let14;
        let17 = (uint32_t) (let15 > 3) << 1;
        let18 = let15 >> (int32_t) let17;
        let19 = let16 | let17;
        let20 = (uint32_t) (let18 > 1) << 0;
        r21 = (let19 | let20) - 1;
        r22 = v1;
        a23 = alloca(v1 * sizeof(double _Complex));
        
        for (v24 = 0; v24 < v1; v24++) {
            a23[v24] = a2[v24];
        }
        for (v25 = 0; v25 < (uint32_t) (0 < r21 + 1) * (r21 + 1); v25++) {
            uint32_t v26;
            double _Complex *a27;
            uint32_t v28;
            
            v26 = r22;
            a27 = alloca(v26 * sizeof(double _Complex));
            memcpy(a27, a23, v26 * sizeof(double _Complex));
            for (v28 = 0; v28 < v26; v28++) {
                a23[v28] = !((v28 & 1 << (int32_t) (uint32_t) (0 < r21 + 1) *
                              ((int32_t) r21 + 1) - (int32_t) v25 - 1) ==
                             0) ? exp(I * (-3.141592653589793 * (double) (v28 &
                                                                          ~(4294967295 <<
                                                                            (int32_t) (uint32_t) (0 <
                                                                                                  r21 +
                                                                                                  1) *
                                                                            ((int32_t) r21 +
                                                                             1) -
                                                                            (int32_t) v25 -
                                                                            1)) /
                                           (double) (1 << (int32_t) (uint32_t) (0 <
                                                                                r21 +
                                                                                1) *
                                                     ((int32_t) r21 + 1) -
                                                     (int32_t) v25 - 1))) *
                    (a27[v28 ^ 1 << (int32_t) (uint32_t) (0 < r21 + 1) *
                         ((int32_t) r21 + 1) - (int32_t) v25 - 1] -
                     a27[v28]) : a27[v28] + a27[v28 ^ 1 << (int32_t) (uint32_t) (0 <
                                                                                 r21 +
                                                                                 1) *
                                                ((int32_t) r21 + 1) -
                                                (int32_t) v25 - 1];
            }
        }
        r29 = r22;
        a30 = alloca(r22 * sizeof(double _Complex));
        for (v31 = 0; v31 < r22; v31++) {
            a30[v31] = a23[v31];
        }
        for (v32 = 0; v32 < (uint32_t) (1 < r21 + 1) * r21; v32++) {
            uint32_t v33;
            double _Complex *a34;
            uint32_t v35;
            
            v33 = r29;
            a34 = alloca(v33 * sizeof(double _Complex));
            memcpy(a34, a30, v33 * sizeof(double _Complex));
            for (v35 = 0; v35 < v33; v35++) {
                a30[v35] = a34[(v35 >> 1 >> (int32_t) v32 + 1 << 1 | (v35 & 1)) <<
                               (int32_t) v32 + 1 | (v35 >> 1 & ~(4294967295 <<
                                                                 (int32_t) v32 +
                                                                 1))];
            }
        }
        
        end_iteration();
    }
    
    print_time();
    
    for (v36 = 0; v36 < v1; v36++) {
        fprintf(stdout, "%+10.5f %+10.5f\n", creal(a30[v36]), cimag(a30[v36]));
    }
    
    return 0;
}

