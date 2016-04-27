// One-dimensional double-precision complex FFT
// implementation compiled from the Zeldspar example
// Compile and run with: 
// gcc -std=gnu99 -I../../imperative-edsl/include ../../imperative-edsl/csrc/chan.c zeldspar_fft.c -o zeldspar_fft -lpthread -lm && ./zeldspar_fft > zeldspar_fft_out.txt
#include "chan.h"
#include <alloca.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <tgmath.h>
#include "benchmark.h"

// #define N --- fixed to (1 << 15) in this code!
// #define ROUNDS (1 << 5)

void *thread_t4(void *unused);
void *thread_t23(void *unused);
void *thread_t42(void *unused);
void *thread_t61(void *unused);
void *thread_t80(void *unused);
void *thread_t99(void *unused);
void *thread_t118(void *unused);
void *thread_t137(void *unused);
void *thread_t156(void *unused);
void *thread_t175(void *unused);
void *thread_t194(void *unused);
void *thread_t213(void *unused);
void *thread_t232(void *unused);
void *thread_t251(void *unused);
void *thread_t270(void *unused);
void *thread_t289(void *unused);
void *thread_t308(void *unused);
void *thread_t327(void *unused);
void *thread_t346(void *unused);
void *thread_t365(void *unused);
void *thread_t384(void *unused);
void *thread_t403(void *unused);
void *thread_t422(void *unused);
void *thread_t441(void *unused);
void *thread_t460(void *unused);
void *thread_t479(void *unused);
void *thread_t498(void *unused);
void *thread_t517(void *unused);
void *thread_t536(void *unused);
void *thread_t555(void *unused);
void *thread_t574(void *unused);
void *thread_t591(void *unused);
chan_t chan0;
chan_t chan1;
chan_t chan2;
chan_t chan3;
pthread_t t4;
void *thread_t4(void *unused)
{
    uint32_t v5;
    double _Complex *a6;
    bool v7;
    uint32_t r8;
    uint32_t v9;
    double _Complex *a10;
    bool v11;
    bool r12;
    uint32_t r14;
    double _Complex *a15;
    uint32_t v16;
    uint32_t v17;
    uint32_t v18;
    bool v19;
    bool v20;
    
    chan_read(chan0, sizeof(v5), &v5);
    a6 = alloca((uint32_t) v5 * sizeof(double _Complex));
    chan_read(chan1, sizeof(*a6) * (v5 - 0), &a6[0]);
    v7 = chan_last_read_ok(chan1);
    r8 = (uint32_t) v5;
    v9 = r8;
    a10 = alloca(v9 * sizeof(double _Complex));
    memcpy(a10, a6, v9 * sizeof(double _Complex));
    v11 = chan_last_read_ok(chan0);
    if (v11) {
        bool v13;
        
        v13 = chan_last_read_ok(chan1);
        r12 = v13;
    } else {
        r12 = false;
    }
    if (!r12) {
        chan_close(chan2);
        chan_close(chan3);
        pthread_cancel(t4);
        pthread_join(t4, NULL);
    }
    r14 = v9;
    a15 = alloca(v9 * sizeof(double _Complex));
    for (v16 = 0; v16 < v9; v16++) {
        a15[v16] = !((v16 & 32768) == 0) ? exp(I * (-3.141592653589793 *
                                                    (double) (v16 & 32767) /
                                                    32768.0)) * (a10[v16 ^
                                                                     32768] -
                                                                 a10[v16]) : a10[v16] +
            a10[v16 ^ 32768];
    }
    v17 = r14;
    v18 = v17;
    v19 = chan_write(chan2, sizeof(v18), &v18);
    v20 = chan_write(chan3, sizeof(*a15) * ((uint32_t) v17 - 0), &a15[0]);
    if (!v20) {
        chan_close(chan0);
        chan_close(chan1);
        pthread_cancel(t4);
        pthread_join(t4, NULL);
    }
    chan_close(chan0);
    chan_close(chan1);
    chan_close(chan2);
    chan_close(chan3);
    return NULL;
}
chan_t chan21;
chan_t chan22;
pthread_t t23;
void *thread_t23(void *unused)
{
    uint32_t v24;
    double _Complex *a25;
    bool v26;
    uint32_t r27;
    uint32_t v28;
    double _Complex *a29;
    bool v30;
    bool r31;
    uint32_t r33;
    double _Complex *a34;
    uint32_t v35;
    uint32_t v36;
    uint32_t v37;
    bool v38;
    bool v39;
    
    chan_read(chan2, sizeof(v24), &v24);
    a25 = alloca((uint32_t) v24 * sizeof(double _Complex));
    chan_read(chan3, sizeof(*a25) * (v24 - 0), &a25[0]);
    v26 = chan_last_read_ok(chan3);
    r27 = (uint32_t) v24;
    v28 = r27;
    a29 = alloca(v28 * sizeof(double _Complex));
    memcpy(a29, a25, v28 * sizeof(double _Complex));
    v30 = chan_last_read_ok(chan2);
    if (v30) {
        bool v32;
        
        v32 = chan_last_read_ok(chan3);
        r31 = v32;
    } else {
        r31 = false;
    }
    if (!r31) {
        chan_close(chan21);
        chan_close(chan22);
        pthread_cancel(t23);
        pthread_join(t23, NULL);
    }
    r33 = v28;
    a34 = alloca(v28 * sizeof(double _Complex));
    for (v35 = 0; v35 < v28; v35++) {
        a34[v35] = !((v35 & 16384) == 0) ? exp(I * (-3.141592653589793 *
                                                    (double) (v35 & 16383) /
                                                    16384.0)) * (a29[v35 ^
                                                                     16384] -
                                                                 a29[v35]) : a29[v35] +
            a29[v35 ^ 16384];
    }
    v36 = r33;
    v37 = v36;
    v38 = chan_write(chan21, sizeof(v37), &v37);
    v39 = chan_write(chan22, sizeof(*a34) * ((uint32_t) v36 - 0), &a34[0]);
    if (!v39) {
        chan_close(chan2);
        chan_close(chan3);
        pthread_cancel(t23);
        pthread_join(t23, NULL);
    }
    chan_close(chan2);
    chan_close(chan3);
    chan_close(chan21);
    chan_close(chan22);
    return NULL;
}
chan_t chan40;
chan_t chan41;
pthread_t t42;
void *thread_t42(void *unused)
{
    uint32_t v43;
    double _Complex *a44;
    bool v45;
    uint32_t r46;
    uint32_t v47;
    double _Complex *a48;
    bool v49;
    bool r50;
    uint32_t r52;
    double _Complex *a53;
    uint32_t v54;
    uint32_t v55;
    uint32_t v56;
    bool v57;
    bool v58;
    
    chan_read(chan21, sizeof(v43), &v43);
    a44 = alloca((uint32_t) v43 * sizeof(double _Complex));
    chan_read(chan22, sizeof(*a44) * (v43 - 0), &a44[0]);
    v45 = chan_last_read_ok(chan22);
    r46 = (uint32_t) v43;
    v47 = r46;
    a48 = alloca(v47 * sizeof(double _Complex));
    memcpy(a48, a44, v47 * sizeof(double _Complex));
    v49 = chan_last_read_ok(chan21);
    if (v49) {
        bool v51;
        
        v51 = chan_last_read_ok(chan22);
        r50 = v51;
    } else {
        r50 = false;
    }
    if (!r50) {
        chan_close(chan40);
        chan_close(chan41);
        pthread_cancel(t42);
        pthread_join(t42, NULL);
    }
    r52 = v47;
    a53 = alloca(v47 * sizeof(double _Complex));
    for (v54 = 0; v54 < v47; v54++) {
        a53[v54] = !((v54 & 8192) == 0) ? exp(I * (-3.141592653589793 *
                                                   (double) (v54 & 8191) /
                                                   8192.0)) * (a48[v54 ^ 8192] -
                                                               a48[v54]) : a48[v54] +
            a48[v54 ^ 8192];
    }
    v55 = r52;
    v56 = v55;
    v57 = chan_write(chan40, sizeof(v56), &v56);
    v58 = chan_write(chan41, sizeof(*a53) * ((uint32_t) v55 - 0), &a53[0]);
    if (!v58) {
        chan_close(chan21);
        chan_close(chan22);
        pthread_cancel(t42);
        pthread_join(t42, NULL);
    }
    chan_close(chan21);
    chan_close(chan22);
    chan_close(chan40);
    chan_close(chan41);
    return NULL;
}
chan_t chan59;
chan_t chan60;
pthread_t t61;
void *thread_t61(void *unused)
{
    uint32_t v62;
    double _Complex *a63;
    bool v64;
    uint32_t r65;
    uint32_t v66;
    double _Complex *a67;
    bool v68;
    bool r69;
    uint32_t r71;
    double _Complex *a72;
    uint32_t v73;
    uint32_t v74;
    uint32_t v75;
    bool v76;
    bool v77;
    
    chan_read(chan40, sizeof(v62), &v62);
    a63 = alloca((uint32_t) v62 * sizeof(double _Complex));
    chan_read(chan41, sizeof(*a63) * (v62 - 0), &a63[0]);
    v64 = chan_last_read_ok(chan41);
    r65 = (uint32_t) v62;
    v66 = r65;
    a67 = alloca(v66 * sizeof(double _Complex));
    memcpy(a67, a63, v66 * sizeof(double _Complex));
    v68 = chan_last_read_ok(chan40);
    if (v68) {
        bool v70;
        
        v70 = chan_last_read_ok(chan41);
        r69 = v70;
    } else {
        r69 = false;
    }
    if (!r69) {
        chan_close(chan59);
        chan_close(chan60);
        pthread_cancel(t61);
        pthread_join(t61, NULL);
    }
    r71 = v66;
    a72 = alloca(v66 * sizeof(double _Complex));
    for (v73 = 0; v73 < v66; v73++) {
        a72[v73] = !((v73 & 4096) == 0) ? exp(I * (-3.141592653589793 *
                                                   (double) (v73 & 4095) /
                                                   4096.0)) * (a67[v73 ^ 4096] -
                                                               a67[v73]) : a67[v73] +
            a67[v73 ^ 4096];
    }
    v74 = r71;
    v75 = v74;
    v76 = chan_write(chan59, sizeof(v75), &v75);
    v77 = chan_write(chan60, sizeof(*a72) * ((uint32_t) v74 - 0), &a72[0]);
    if (!v77) {
        chan_close(chan40);
        chan_close(chan41);
        pthread_cancel(t61);
        pthread_join(t61, NULL);
    }
    chan_close(chan40);
    chan_close(chan41);
    chan_close(chan59);
    chan_close(chan60);
    return NULL;
}
chan_t chan78;
chan_t chan79;
pthread_t t80;
void *thread_t80(void *unused)
{
    uint32_t v81;
    double _Complex *a82;
    bool v83;
    uint32_t r84;
    uint32_t v85;
    double _Complex *a86;
    bool v87;
    bool r88;
    uint32_t r90;
    double _Complex *a91;
    uint32_t v92;
    uint32_t v93;
    uint32_t v94;
    bool v95;
    bool v96;
    
    chan_read(chan59, sizeof(v81), &v81);
    a82 = alloca((uint32_t) v81 * sizeof(double _Complex));
    chan_read(chan60, sizeof(*a82) * (v81 - 0), &a82[0]);
    v83 = chan_last_read_ok(chan60);
    r84 = (uint32_t) v81;
    v85 = r84;
    a86 = alloca(v85 * sizeof(double _Complex));
    memcpy(a86, a82, v85 * sizeof(double _Complex));
    v87 = chan_last_read_ok(chan59);
    if (v87) {
        bool v89;
        
        v89 = chan_last_read_ok(chan60);
        r88 = v89;
    } else {
        r88 = false;
    }
    if (!r88) {
        chan_close(chan78);
        chan_close(chan79);
        pthread_cancel(t80);
        pthread_join(t80, NULL);
    }
    r90 = v85;
    a91 = alloca(v85 * sizeof(double _Complex));
    for (v92 = 0; v92 < v85; v92++) {
        a91[v92] = !((v92 & 2048) == 0) ? exp(I * (-3.141592653589793 *
                                                   (double) (v92 & 2047) /
                                                   2048.0)) * (a86[v92 ^ 2048] -
                                                               a86[v92]) : a86[v92] +
            a86[v92 ^ 2048];
    }
    v93 = r90;
    v94 = v93;
    v95 = chan_write(chan78, sizeof(v94), &v94);
    v96 = chan_write(chan79, sizeof(*a91) * ((uint32_t) v93 - 0), &a91[0]);
    if (!v96) {
        chan_close(chan59);
        chan_close(chan60);
        pthread_cancel(t80);
        pthread_join(t80, NULL);
    }
    chan_close(chan59);
    chan_close(chan60);
    chan_close(chan78);
    chan_close(chan79);
    return NULL;
}
chan_t chan97;
chan_t chan98;
pthread_t t99;
void *thread_t99(void *unused)
{
    uint32_t v100;
    double _Complex *a101;
    bool v102;
    uint32_t r103;
    uint32_t v104;
    double _Complex *a105;
    bool v106;
    bool r107;
    uint32_t r109;
    double _Complex *a110;
    uint32_t v111;
    uint32_t v112;
    uint32_t v113;
    bool v114;
    bool v115;
    
    chan_read(chan78, sizeof(v100), &v100);
    a101 = alloca((uint32_t) v100 * sizeof(double _Complex));
    chan_read(chan79, sizeof(*a101) * (v100 - 0), &a101[0]);
    v102 = chan_last_read_ok(chan79);
    r103 = (uint32_t) v100;
    v104 = r103;
    a105 = alloca(v104 * sizeof(double _Complex));
    memcpy(a105, a101, v104 * sizeof(double _Complex));
    v106 = chan_last_read_ok(chan78);
    if (v106) {
        bool v108;
        
        v108 = chan_last_read_ok(chan79);
        r107 = v108;
    } else {
        r107 = false;
    }
    if (!r107) {
        chan_close(chan97);
        chan_close(chan98);
        pthread_cancel(t99);
        pthread_join(t99, NULL);
    }
    r109 = v104;
    a110 = alloca(v104 * sizeof(double _Complex));
    for (v111 = 0; v111 < v104; v111++) {
        a110[v111] = !((v111 & 1024) == 0) ? exp(I * (-3.141592653589793 *
                                                      (double) (v111 & 1023) /
                                                      1024.0)) * (a105[v111 ^
                                                                       1024] -
                                                                  a105[v111]) : a105[v111] +
            a105[v111 ^ 1024];
    }
    v112 = r109;
    v113 = v112;
    v114 = chan_write(chan97, sizeof(v113), &v113);
    v115 = chan_write(chan98, sizeof(*a110) * ((uint32_t) v112 - 0), &a110[0]);
    if (!v115) {
        chan_close(chan78);
        chan_close(chan79);
        pthread_cancel(t99);
        pthread_join(t99, NULL);
    }
    chan_close(chan78);
    chan_close(chan79);
    chan_close(chan97);
    chan_close(chan98);
    return NULL;
}
chan_t chan116;
chan_t chan117;
pthread_t t118;
void *thread_t118(void *unused)
{
    uint32_t v119;
    double _Complex *a120;
    bool v121;
    uint32_t r122;
    uint32_t v123;
    double _Complex *a124;
    bool v125;
    bool r126;
    uint32_t r128;
    double _Complex *a129;
    uint32_t v130;
    uint32_t v131;
    uint32_t v132;
    bool v133;
    bool v134;
    
    chan_read(chan97, sizeof(v119), &v119);
    a120 = alloca((uint32_t) v119 * sizeof(double _Complex));
    chan_read(chan98, sizeof(*a120) * (v119 - 0), &a120[0]);
    v121 = chan_last_read_ok(chan98);
    r122 = (uint32_t) v119;
    v123 = r122;
    a124 = alloca(v123 * sizeof(double _Complex));
    memcpy(a124, a120, v123 * sizeof(double _Complex));
    v125 = chan_last_read_ok(chan97);
    if (v125) {
        bool v127;
        
        v127 = chan_last_read_ok(chan98);
        r126 = v127;
    } else {
        r126 = false;
    }
    if (!r126) {
        chan_close(chan116);
        chan_close(chan117);
        pthread_cancel(t118);
        pthread_join(t118, NULL);
    }
    r128 = v123;
    a129 = alloca(v123 * sizeof(double _Complex));
    for (v130 = 0; v130 < v123; v130++) {
        a129[v130] = !((v130 & 512) == 0) ? exp(I * (-3.141592653589793 *
                                                     (double) (v130 & 511) /
                                                     512.0)) * (a124[v130 ^
                                                                     512] -
                                                                a124[v130]) : a124[v130] +
            a124[v130 ^ 512];
    }
    v131 = r128;
    v132 = v131;
    v133 = chan_write(chan116, sizeof(v132), &v132);
    v134 = chan_write(chan117, sizeof(*a129) * ((uint32_t) v131 - 0), &a129[0]);
    if (!v134) {
        chan_close(chan97);
        chan_close(chan98);
        pthread_cancel(t118);
        pthread_join(t118, NULL);
    }
    chan_close(chan97);
    chan_close(chan98);
    chan_close(chan116);
    chan_close(chan117);
    return NULL;
}
chan_t chan135;
chan_t chan136;
pthread_t t137;
void *thread_t137(void *unused)
{
    uint32_t v138;
    double _Complex *a139;
    bool v140;
    uint32_t r141;
    uint32_t v142;
    double _Complex *a143;
    bool v144;
    bool r145;
    uint32_t r147;
    double _Complex *a148;
    uint32_t v149;
    uint32_t v150;
    uint32_t v151;
    bool v152;
    bool v153;
    
    chan_read(chan116, sizeof(v138), &v138);
    a139 = alloca((uint32_t) v138 * sizeof(double _Complex));
    chan_read(chan117, sizeof(*a139) * (v138 - 0), &a139[0]);
    v140 = chan_last_read_ok(chan117);
    r141 = (uint32_t) v138;
    v142 = r141;
    a143 = alloca(v142 * sizeof(double _Complex));
    memcpy(a143, a139, v142 * sizeof(double _Complex));
    v144 = chan_last_read_ok(chan116);
    if (v144) {
        bool v146;
        
        v146 = chan_last_read_ok(chan117);
        r145 = v146;
    } else {
        r145 = false;
    }
    if (!r145) {
        chan_close(chan135);
        chan_close(chan136);
        pthread_cancel(t137);
        pthread_join(t137, NULL);
    }
    r147 = v142;
    a148 = alloca(v142 * sizeof(double _Complex));
    for (v149 = 0; v149 < v142; v149++) {
        a148[v149] = !((v149 & 256) == 0) ? exp(I * (-3.141592653589793 *
                                                     (double) (v149 & 255) /
                                                     256.0)) * (a143[v149 ^
                                                                     256] -
                                                                a143[v149]) : a143[v149] +
            a143[v149 ^ 256];
    }
    v150 = r147;
    v151 = v150;
    v152 = chan_write(chan135, sizeof(v151), &v151);
    v153 = chan_write(chan136, sizeof(*a148) * ((uint32_t) v150 - 0), &a148[0]);
    if (!v153) {
        chan_close(chan116);
        chan_close(chan117);
        pthread_cancel(t137);
        pthread_join(t137, NULL);
    }
    chan_close(chan116);
    chan_close(chan117);
    chan_close(chan135);
    chan_close(chan136);
    return NULL;
}
chan_t chan154;
chan_t chan155;
pthread_t t156;
void *thread_t156(void *unused)
{
    uint32_t v157;
    double _Complex *a158;
    bool v159;
    uint32_t r160;
    uint32_t v161;
    double _Complex *a162;
    bool v163;
    bool r164;
    uint32_t r166;
    double _Complex *a167;
    uint32_t v168;
    uint32_t v169;
    uint32_t v170;
    bool v171;
    bool v172;
    
    chan_read(chan135, sizeof(v157), &v157);
    a158 = alloca((uint32_t) v157 * sizeof(double _Complex));
    chan_read(chan136, sizeof(*a158) * (v157 - 0), &a158[0]);
    v159 = chan_last_read_ok(chan136);
    r160 = (uint32_t) v157;
    v161 = r160;
    a162 = alloca(v161 * sizeof(double _Complex));
    memcpy(a162, a158, v161 * sizeof(double _Complex));
    v163 = chan_last_read_ok(chan135);
    if (v163) {
        bool v165;
        
        v165 = chan_last_read_ok(chan136);
        r164 = v165;
    } else {
        r164 = false;
    }
    if (!r164) {
        chan_close(chan154);
        chan_close(chan155);
        pthread_cancel(t156);
        pthread_join(t156, NULL);
    }
    r166 = v161;
    a167 = alloca(v161 * sizeof(double _Complex));
    for (v168 = 0; v168 < v161; v168++) {
        a167[v168] = !((v168 & 128) == 0) ? exp(I * (-3.141592653589793 *
                                                     (double) (v168 & 127) /
                                                     128.0)) * (a162[v168 ^
                                                                     128] -
                                                                a162[v168]) : a162[v168] +
            a162[v168 ^ 128];
    }
    v169 = r166;
    v170 = v169;
    v171 = chan_write(chan154, sizeof(v170), &v170);
    v172 = chan_write(chan155, sizeof(*a167) * ((uint32_t) v169 - 0), &a167[0]);
    if (!v172) {
        chan_close(chan135);
        chan_close(chan136);
        pthread_cancel(t156);
        pthread_join(t156, NULL);
    }
    chan_close(chan135);
    chan_close(chan136);
    chan_close(chan154);
    chan_close(chan155);
    return NULL;
}
chan_t chan173;
chan_t chan174;
pthread_t t175;
void *thread_t175(void *unused)
{
    uint32_t v176;
    double _Complex *a177;
    bool v178;
    uint32_t r179;
    uint32_t v180;
    double _Complex *a181;
    bool v182;
    bool r183;
    uint32_t r185;
    double _Complex *a186;
    uint32_t v187;
    uint32_t v188;
    uint32_t v189;
    bool v190;
    bool v191;
    
    chan_read(chan154, sizeof(v176), &v176);
    a177 = alloca((uint32_t) v176 * sizeof(double _Complex));
    chan_read(chan155, sizeof(*a177) * (v176 - 0), &a177[0]);
    v178 = chan_last_read_ok(chan155);
    r179 = (uint32_t) v176;
    v180 = r179;
    a181 = alloca(v180 * sizeof(double _Complex));
    memcpy(a181, a177, v180 * sizeof(double _Complex));
    v182 = chan_last_read_ok(chan154);
    if (v182) {
        bool v184;
        
        v184 = chan_last_read_ok(chan155);
        r183 = v184;
    } else {
        r183 = false;
    }
    if (!r183) {
        chan_close(chan173);
        chan_close(chan174);
        pthread_cancel(t175);
        pthread_join(t175, NULL);
    }
    r185 = v180;
    a186 = alloca(v180 * sizeof(double _Complex));
    for (v187 = 0; v187 < v180; v187++) {
        a186[v187] = !((v187 & 64) == 0) ? exp(I * (-3.141592653589793 *
                                                    (double) (v187 & 63) /
                                                    64.0)) * (a181[v187 ^ 64] -
                                                              a181[v187]) : a181[v187] +
            a181[v187 ^ 64];
    }
    v188 = r185;
    v189 = v188;
    v190 = chan_write(chan173, sizeof(v189), &v189);
    v191 = chan_write(chan174, sizeof(*a186) * ((uint32_t) v188 - 0), &a186[0]);
    if (!v191) {
        chan_close(chan154);
        chan_close(chan155);
        pthread_cancel(t175);
        pthread_join(t175, NULL);
    }
    chan_close(chan154);
    chan_close(chan155);
    chan_close(chan173);
    chan_close(chan174);
    return NULL;
}
chan_t chan192;
chan_t chan193;
pthread_t t194;
void *thread_t194(void *unused)
{
    uint32_t v195;
    double _Complex *a196;
    bool v197;
    uint32_t r198;
    uint32_t v199;
    double _Complex *a200;
    bool v201;
    bool r202;
    uint32_t r204;
    double _Complex *a205;
    uint32_t v206;
    uint32_t v207;
    uint32_t v208;
    bool v209;
    bool v210;
    
    chan_read(chan173, sizeof(v195), &v195);
    a196 = alloca((uint32_t) v195 * sizeof(double _Complex));
    chan_read(chan174, sizeof(*a196) * (v195 - 0), &a196[0]);
    v197 = chan_last_read_ok(chan174);
    r198 = (uint32_t) v195;
    v199 = r198;
    a200 = alloca(v199 * sizeof(double _Complex));
    memcpy(a200, a196, v199 * sizeof(double _Complex));
    v201 = chan_last_read_ok(chan173);
    if (v201) {
        bool v203;
        
        v203 = chan_last_read_ok(chan174);
        r202 = v203;
    } else {
        r202 = false;
    }
    if (!r202) {
        chan_close(chan192);
        chan_close(chan193);
        pthread_cancel(t194);
        pthread_join(t194, NULL);
    }
    r204 = v199;
    a205 = alloca(v199 * sizeof(double _Complex));
    for (v206 = 0; v206 < v199; v206++) {
        a205[v206] = !((v206 & 32) == 0) ? exp(I * (-3.141592653589793 *
                                                    (double) (v206 & 31) /
                                                    32.0)) * (a200[v206 ^ 32] -
                                                              a200[v206]) : a200[v206] +
            a200[v206 ^ 32];
    }
    v207 = r204;
    v208 = v207;
    v209 = chan_write(chan192, sizeof(v208), &v208);
    v210 = chan_write(chan193, sizeof(*a205) * ((uint32_t) v207 - 0), &a205[0]);
    if (!v210) {
        chan_close(chan173);
        chan_close(chan174);
        pthread_cancel(t194);
        pthread_join(t194, NULL);
    }
    chan_close(chan173);
    chan_close(chan174);
    chan_close(chan192);
    chan_close(chan193);
    return NULL;
}
chan_t chan211;
chan_t chan212;
pthread_t t213;
void *thread_t213(void *unused)
{
    uint32_t v214;
    double _Complex *a215;
    bool v216;
    uint32_t r217;
    uint32_t v218;
    double _Complex *a219;
    bool v220;
    bool r221;
    uint32_t r223;
    double _Complex *a224;
    uint32_t v225;
    uint32_t v226;
    uint32_t v227;
    bool v228;
    bool v229;
    
    chan_read(chan192, sizeof(v214), &v214);
    a215 = alloca((uint32_t) v214 * sizeof(double _Complex));
    chan_read(chan193, sizeof(*a215) * (v214 - 0), &a215[0]);
    v216 = chan_last_read_ok(chan193);
    r217 = (uint32_t) v214;
    v218 = r217;
    a219 = alloca(v218 * sizeof(double _Complex));
    memcpy(a219, a215, v218 * sizeof(double _Complex));
    v220 = chan_last_read_ok(chan192);
    if (v220) {
        bool v222;
        
        v222 = chan_last_read_ok(chan193);
        r221 = v222;
    } else {
        r221 = false;
    }
    if (!r221) {
        chan_close(chan211);
        chan_close(chan212);
        pthread_cancel(t213);
        pthread_join(t213, NULL);
    }
    r223 = v218;
    a224 = alloca(v218 * sizeof(double _Complex));
    for (v225 = 0; v225 < v218; v225++) {
        a224[v225] = !((v225 & 16) == 0) ? exp(I * (-3.141592653589793 *
                                                    (double) (v225 & 15) /
                                                    16.0)) * (a219[v225 ^ 16] -
                                                              a219[v225]) : a219[v225] +
            a219[v225 ^ 16];
    }
    v226 = r223;
    v227 = v226;
    v228 = chan_write(chan211, sizeof(v227), &v227);
    v229 = chan_write(chan212, sizeof(*a224) * ((uint32_t) v226 - 0), &a224[0]);
    if (!v229) {
        chan_close(chan192);
        chan_close(chan193);
        pthread_cancel(t213);
        pthread_join(t213, NULL);
    }
    chan_close(chan192);
    chan_close(chan193);
    chan_close(chan211);
    chan_close(chan212);
    return NULL;
}
chan_t chan230;
chan_t chan231;
pthread_t t232;
void *thread_t232(void *unused)
{
    uint32_t v233;
    double _Complex *a234;
    bool v235;
    uint32_t r236;
    uint32_t v237;
    double _Complex *a238;
    bool v239;
    bool r240;
    uint32_t r242;
    double _Complex *a243;
    uint32_t v244;
    uint32_t v245;
    uint32_t v246;
    bool v247;
    bool v248;
    
    chan_read(chan211, sizeof(v233), &v233);
    a234 = alloca((uint32_t) v233 * sizeof(double _Complex));
    chan_read(chan212, sizeof(*a234) * (v233 - 0), &a234[0]);
    v235 = chan_last_read_ok(chan212);
    r236 = (uint32_t) v233;
    v237 = r236;
    a238 = alloca(v237 * sizeof(double _Complex));
    memcpy(a238, a234, v237 * sizeof(double _Complex));
    v239 = chan_last_read_ok(chan211);
    if (v239) {
        bool v241;
        
        v241 = chan_last_read_ok(chan212);
        r240 = v241;
    } else {
        r240 = false;
    }
    if (!r240) {
        chan_close(chan230);
        chan_close(chan231);
        pthread_cancel(t232);
        pthread_join(t232, NULL);
    }
    r242 = v237;
    a243 = alloca(v237 * sizeof(double _Complex));
    for (v244 = 0; v244 < v237; v244++) {
        a243[v244] = !((v244 & 8) == 0) ? exp(I * (-3.141592653589793 *
                                                   (double) (v244 & 7) / 8.0)) *
            (a238[v244 ^ 8] - a238[v244]) : a238[v244] + a238[v244 ^ 8];
    }
    v245 = r242;
    v246 = v245;
    v247 = chan_write(chan230, sizeof(v246), &v246);
    v248 = chan_write(chan231, sizeof(*a243) * ((uint32_t) v245 - 0), &a243[0]);
    if (!v248) {
        chan_close(chan211);
        chan_close(chan212);
        pthread_cancel(t232);
        pthread_join(t232, NULL);
    }
    chan_close(chan211);
    chan_close(chan212);
    chan_close(chan230);
    chan_close(chan231);
    return NULL;
}
chan_t chan249;
chan_t chan250;
pthread_t t251;
void *thread_t251(void *unused)
{
    uint32_t v252;
    double _Complex *a253;
    bool v254;
    uint32_t r255;
    uint32_t v256;
    double _Complex *a257;
    bool v258;
    bool r259;
    uint32_t r261;
    double _Complex *a262;
    uint32_t v263;
    uint32_t v264;
    uint32_t v265;
    bool v266;
    bool v267;
    
    chan_read(chan230, sizeof(v252), &v252);
    a253 = alloca((uint32_t) v252 * sizeof(double _Complex));
    chan_read(chan231, sizeof(*a253) * (v252 - 0), &a253[0]);
    v254 = chan_last_read_ok(chan231);
    r255 = (uint32_t) v252;
    v256 = r255;
    a257 = alloca(v256 * sizeof(double _Complex));
    memcpy(a257, a253, v256 * sizeof(double _Complex));
    v258 = chan_last_read_ok(chan230);
    if (v258) {
        bool v260;
        
        v260 = chan_last_read_ok(chan231);
        r259 = v260;
    } else {
        r259 = false;
    }
    if (!r259) {
        chan_close(chan249);
        chan_close(chan250);
        pthread_cancel(t251);
        pthread_join(t251, NULL);
    }
    r261 = v256;
    a262 = alloca(v256 * sizeof(double _Complex));
    for (v263 = 0; v263 < v256; v263++) {
        a262[v263] = !((v263 & 4) == 0) ? exp(I * (-3.141592653589793 *
                                                   (double) (v263 & 3) / 4.0)) *
            (a257[v263 ^ 4] - a257[v263]) : a257[v263] + a257[v263 ^ 4];
    }
    v264 = r261;
    v265 = v264;
    v266 = chan_write(chan249, sizeof(v265), &v265);
    v267 = chan_write(chan250, sizeof(*a262) * ((uint32_t) v264 - 0), &a262[0]);
    if (!v267) {
        chan_close(chan230);
        chan_close(chan231);
        pthread_cancel(t251);
        pthread_join(t251, NULL);
    }
    chan_close(chan230);
    chan_close(chan231);
    chan_close(chan249);
    chan_close(chan250);
    return NULL;
}
chan_t chan268;
chan_t chan269;
pthread_t t270;
void *thread_t270(void *unused)
{
    uint32_t v271;
    double _Complex *a272;
    bool v273;
    uint32_t r274;
    uint32_t v275;
    double _Complex *a276;
    bool v277;
    bool r278;
    uint32_t r280;
    double _Complex *a281;
    uint32_t v282;
    uint32_t v283;
    uint32_t v284;
    bool v285;
    bool v286;
    
    chan_read(chan249, sizeof(v271), &v271);
    a272 = alloca((uint32_t) v271 * sizeof(double _Complex));
    chan_read(chan250, sizeof(*a272) * (v271 - 0), &a272[0]);
    v273 = chan_last_read_ok(chan250);
    r274 = (uint32_t) v271;
    v275 = r274;
    a276 = alloca(v275 * sizeof(double _Complex));
    memcpy(a276, a272, v275 * sizeof(double _Complex));
    v277 = chan_last_read_ok(chan249);
    if (v277) {
        bool v279;
        
        v279 = chan_last_read_ok(chan250);
        r278 = v279;
    } else {
        r278 = false;
    }
    if (!r278) {
        chan_close(chan268);
        chan_close(chan269);
        pthread_cancel(t270);
        pthread_join(t270, NULL);
    }
    r280 = v275;
    a281 = alloca(v275 * sizeof(double _Complex));
    for (v282 = 0; v282 < v275; v282++) {
        a281[v282] = !((v282 & 2) == 0) ? exp(I * (-3.141592653589793 *
                                                   (double) (v282 & 1) / 2.0)) *
            (a276[v282 ^ 2] - a276[v282]) : a276[v282] + a276[v282 ^ 2];
    }
    v283 = r280;
    v284 = v283;
    v285 = chan_write(chan268, sizeof(v284), &v284);
    v286 = chan_write(chan269, sizeof(*a281) * ((uint32_t) v283 - 0), &a281[0]);
    if (!v286) {
        chan_close(chan249);
        chan_close(chan250);
        pthread_cancel(t270);
        pthread_join(t270, NULL);
    }
    chan_close(chan249);
    chan_close(chan250);
    chan_close(chan268);
    chan_close(chan269);
    return NULL;
}
chan_t chan287;
chan_t chan288;
pthread_t t289;
void *thread_t289(void *unused)
{
    uint32_t v290;
    double _Complex *a291;
    bool v292;
    uint32_t r293;
    uint32_t v294;
    double _Complex *a295;
    bool v296;
    bool r297;
    uint32_t r299;
    double _Complex *a300;
    uint32_t v301;
    uint32_t v302;
    uint32_t v303;
    bool v304;
    bool v305;
    
    chan_read(chan268, sizeof(v290), &v290);
    a291 = alloca((uint32_t) v290 * sizeof(double _Complex));
    chan_read(chan269, sizeof(*a291) * (v290 - 0), &a291[0]);
    v292 = chan_last_read_ok(chan269);
    r293 = (uint32_t) v290;
    v294 = r293;
    a295 = alloca(v294 * sizeof(double _Complex));
    memcpy(a295, a291, v294 * sizeof(double _Complex));
    v296 = chan_last_read_ok(chan268);
    if (v296) {
        bool v298;
        
        v298 = chan_last_read_ok(chan269);
        r297 = v298;
    } else {
        r297 = false;
    }
    if (!r297) {
        chan_close(chan287);
        chan_close(chan288);
        pthread_cancel(t289);
        pthread_join(t289, NULL);
    }
    r299 = v294;
    a300 = alloca(v294 * sizeof(double _Complex));
    for (v301 = 0; v301 < v294; v301++) {
        a300[v301] = !((v301 & 1) == 0) ? exp(I * (-3.141592653589793 *
                                                   (double) (v301 & 0) / 1.0)) *
            (a295[v301 ^ 1] - a295[v301]) : a295[v301] + a295[v301 ^ 1];
    }
    v302 = r299;
    v303 = v302;
    v304 = chan_write(chan287, sizeof(v303), &v303);
    v305 = chan_write(chan288, sizeof(*a300) * ((uint32_t) v302 - 0), &a300[0]);
    if (!v305) {
        chan_close(chan268);
        chan_close(chan269);
        pthread_cancel(t289);
        pthread_join(t289, NULL);
    }
    chan_close(chan268);
    chan_close(chan269);
    chan_close(chan287);
    chan_close(chan288);
    return NULL;
}
chan_t chan306;
chan_t chan307;
pthread_t t308;
void *thread_t308(void *unused)
{
    uint32_t v309;
    double _Complex *a310;
    bool v311;
    uint32_t r312;
    uint32_t v313;
    double _Complex *a314;
    bool v315;
    bool r316;
    uint32_t r318;
    double _Complex *a319;
    uint32_t v320;
    uint32_t v321;
    uint32_t v322;
    bool v323;
    bool v324;
    
    chan_read(chan287, sizeof(v309), &v309);
    a310 = alloca((uint32_t) v309 * sizeof(double _Complex));
    chan_read(chan288, sizeof(*a310) * (v309 - 0), &a310[0]);
    v311 = chan_last_read_ok(chan288);
    r312 = (uint32_t) v309;
    v313 = r312;
    a314 = alloca(v313 * sizeof(double _Complex));
    memcpy(a314, a310, v313 * sizeof(double _Complex));
    v315 = chan_last_read_ok(chan287);
    if (v315) {
        bool v317;
        
        v317 = chan_last_read_ok(chan288);
        r316 = v317;
    } else {
        r316 = false;
    }
    if (!r316) {
        chan_close(chan306);
        chan_close(chan307);
        pthread_cancel(t308);
        pthread_join(t308, NULL);
    }
    r318 = v313;
    a319 = alloca(v313 * sizeof(double _Complex));
    for (v320 = 0; v320 < v313; v320++) {
        a319[v320] = a314[(v320 >> 1 >> 1 << 1 | (v320 & 1)) << 1 | (v320 >> 1 &
                                                                     1)];
    }
    v321 = r318;
    v322 = v321;
    v323 = chan_write(chan306, sizeof(v322), &v322);
    v324 = chan_write(chan307, sizeof(*a319) * ((uint32_t) v321 - 0), &a319[0]);
    if (!v324) {
        chan_close(chan287);
        chan_close(chan288);
        pthread_cancel(t308);
        pthread_join(t308, NULL);
    }
    chan_close(chan287);
    chan_close(chan288);
    chan_close(chan306);
    chan_close(chan307);
    return NULL;
}
chan_t chan325;
chan_t chan326;
pthread_t t327;
void *thread_t327(void *unused)
{
    uint32_t v328;
    double _Complex *a329;
    bool v330;
    uint32_t r331;
    uint32_t v332;
    double _Complex *a333;
    bool v334;
    bool r335;
    uint32_t r337;
    double _Complex *a338;
    uint32_t v339;
    uint32_t v340;
    uint32_t v341;
    bool v342;
    bool v343;
    
    chan_read(chan306, sizeof(v328), &v328);
    a329 = alloca((uint32_t) v328 * sizeof(double _Complex));
    chan_read(chan307, sizeof(*a329) * (v328 - 0), &a329[0]);
    v330 = chan_last_read_ok(chan307);
    r331 = (uint32_t) v328;
    v332 = r331;
    a333 = alloca(v332 * sizeof(double _Complex));
    memcpy(a333, a329, v332 * sizeof(double _Complex));
    v334 = chan_last_read_ok(chan306);
    if (v334) {
        bool v336;
        
        v336 = chan_last_read_ok(chan307);
        r335 = v336;
    } else {
        r335 = false;
    }
    if (!r335) {
        chan_close(chan325);
        chan_close(chan326);
        pthread_cancel(t327);
        pthread_join(t327, NULL);
    }
    r337 = v332;
    a338 = alloca(v332 * sizeof(double _Complex));
    for (v339 = 0; v339 < v332; v339++) {
        a338[v339] = a333[(v339 >> 1 >> 2 << 1 | (v339 & 1)) << 2 | (v339 >> 1 &
                                                                     3)];
    }
    v340 = r337;
    v341 = v340;
    v342 = chan_write(chan325, sizeof(v341), &v341);
    v343 = chan_write(chan326, sizeof(*a338) * ((uint32_t) v340 - 0), &a338[0]);
    if (!v343) {
        chan_close(chan306);
        chan_close(chan307);
        pthread_cancel(t327);
        pthread_join(t327, NULL);
    }
    chan_close(chan306);
    chan_close(chan307);
    chan_close(chan325);
    chan_close(chan326);
    return NULL;
}
chan_t chan344;
chan_t chan345;
pthread_t t346;
void *thread_t346(void *unused)
{
    uint32_t v347;
    double _Complex *a348;
    bool v349;
    uint32_t r350;
    uint32_t v351;
    double _Complex *a352;
    bool v353;
    bool r354;
    uint32_t r356;
    double _Complex *a357;
    uint32_t v358;
    uint32_t v359;
    uint32_t v360;
    bool v361;
    bool v362;
    
    chan_read(chan325, sizeof(v347), &v347);
    a348 = alloca((uint32_t) v347 * sizeof(double _Complex));
    chan_read(chan326, sizeof(*a348) * (v347 - 0), &a348[0]);
    v349 = chan_last_read_ok(chan326);
    r350 = (uint32_t) v347;
    v351 = r350;
    a352 = alloca(v351 * sizeof(double _Complex));
    memcpy(a352, a348, v351 * sizeof(double _Complex));
    v353 = chan_last_read_ok(chan325);
    if (v353) {
        bool v355;
        
        v355 = chan_last_read_ok(chan326);
        r354 = v355;
    } else {
        r354 = false;
    }
    if (!r354) {
        chan_close(chan344);
        chan_close(chan345);
        pthread_cancel(t346);
        pthread_join(t346, NULL);
    }
    r356 = v351;
    a357 = alloca(v351 * sizeof(double _Complex));
    for (v358 = 0; v358 < v351; v358++) {
        a357[v358] = a352[(v358 >> 1 >> 3 << 1 | (v358 & 1)) << 3 | (v358 >> 1 &
                                                                     7)];
    }
    v359 = r356;
    v360 = v359;
    v361 = chan_write(chan344, sizeof(v360), &v360);
    v362 = chan_write(chan345, sizeof(*a357) * ((uint32_t) v359 - 0), &a357[0]);
    if (!v362) {
        chan_close(chan325);
        chan_close(chan326);
        pthread_cancel(t346);
        pthread_join(t346, NULL);
    }
    chan_close(chan325);
    chan_close(chan326);
    chan_close(chan344);
    chan_close(chan345);
    return NULL;
}
chan_t chan363;
chan_t chan364;
pthread_t t365;
void *thread_t365(void *unused)
{
    uint32_t v366;
    double _Complex *a367;
    bool v368;
    uint32_t r369;
    uint32_t v370;
    double _Complex *a371;
    bool v372;
    bool r373;
    uint32_t r375;
    double _Complex *a376;
    uint32_t v377;
    uint32_t v378;
    uint32_t v379;
    bool v380;
    bool v381;
    
    chan_read(chan344, sizeof(v366), &v366);
    a367 = alloca((uint32_t) v366 * sizeof(double _Complex));
    chan_read(chan345, sizeof(*a367) * (v366 - 0), &a367[0]);
    v368 = chan_last_read_ok(chan345);
    r369 = (uint32_t) v366;
    v370 = r369;
    a371 = alloca(v370 * sizeof(double _Complex));
    memcpy(a371, a367, v370 * sizeof(double _Complex));
    v372 = chan_last_read_ok(chan344);
    if (v372) {
        bool v374;
        
        v374 = chan_last_read_ok(chan345);
        r373 = v374;
    } else {
        r373 = false;
    }
    if (!r373) {
        chan_close(chan363);
        chan_close(chan364);
        pthread_cancel(t365);
        pthread_join(t365, NULL);
    }
    r375 = v370;
    a376 = alloca(v370 * sizeof(double _Complex));
    for (v377 = 0; v377 < v370; v377++) {
        a376[v377] = a371[(v377 >> 1 >> 4 << 1 | (v377 & 1)) << 4 | (v377 >> 1 &
                                                                     15)];
    }
    v378 = r375;
    v379 = v378;
    v380 = chan_write(chan363, sizeof(v379), &v379);
    v381 = chan_write(chan364, sizeof(*a376) * ((uint32_t) v378 - 0), &a376[0]);
    if (!v381) {
        chan_close(chan344);
        chan_close(chan345);
        pthread_cancel(t365);
        pthread_join(t365, NULL);
    }
    chan_close(chan344);
    chan_close(chan345);
    chan_close(chan363);
    chan_close(chan364);
    return NULL;
}
chan_t chan382;
chan_t chan383;
pthread_t t384;
void *thread_t384(void *unused)
{
    uint32_t v385;
    double _Complex *a386;
    bool v387;
    uint32_t r388;
    uint32_t v389;
    double _Complex *a390;
    bool v391;
    bool r392;
    uint32_t r394;
    double _Complex *a395;
    uint32_t v396;
    uint32_t v397;
    uint32_t v398;
    bool v399;
    bool v400;
    
    chan_read(chan363, sizeof(v385), &v385);
    a386 = alloca((uint32_t) v385 * sizeof(double _Complex));
    chan_read(chan364, sizeof(*a386) * (v385 - 0), &a386[0]);
    v387 = chan_last_read_ok(chan364);
    r388 = (uint32_t) v385;
    v389 = r388;
    a390 = alloca(v389 * sizeof(double _Complex));
    memcpy(a390, a386, v389 * sizeof(double _Complex));
    v391 = chan_last_read_ok(chan363);
    if (v391) {
        bool v393;
        
        v393 = chan_last_read_ok(chan364);
        r392 = v393;
    } else {
        r392 = false;
    }
    if (!r392) {
        chan_close(chan382);
        chan_close(chan383);
        pthread_cancel(t384);
        pthread_join(t384, NULL);
    }
    r394 = v389;
    a395 = alloca(v389 * sizeof(double _Complex));
    for (v396 = 0; v396 < v389; v396++) {
        a395[v396] = a390[(v396 >> 1 >> 5 << 1 | (v396 & 1)) << 5 | (v396 >> 1 &
                                                                     31)];
    }
    v397 = r394;
    v398 = v397;
    v399 = chan_write(chan382, sizeof(v398), &v398);
    v400 = chan_write(chan383, sizeof(*a395) * ((uint32_t) v397 - 0), &a395[0]);
    if (!v400) {
        chan_close(chan363);
        chan_close(chan364);
        pthread_cancel(t384);
        pthread_join(t384, NULL);
    }
    chan_close(chan363);
    chan_close(chan364);
    chan_close(chan382);
    chan_close(chan383);
    return NULL;
}
chan_t chan401;
chan_t chan402;
pthread_t t403;
void *thread_t403(void *unused)
{
    uint32_t v404;
    double _Complex *a405;
    bool v406;
    uint32_t r407;
    uint32_t v408;
    double _Complex *a409;
    bool v410;
    bool r411;
    uint32_t r413;
    double _Complex *a414;
    uint32_t v415;
    uint32_t v416;
    uint32_t v417;
    bool v418;
    bool v419;
    
    chan_read(chan382, sizeof(v404), &v404);
    a405 = alloca((uint32_t) v404 * sizeof(double _Complex));
    chan_read(chan383, sizeof(*a405) * (v404 - 0), &a405[0]);
    v406 = chan_last_read_ok(chan383);
    r407 = (uint32_t) v404;
    v408 = r407;
    a409 = alloca(v408 * sizeof(double _Complex));
    memcpy(a409, a405, v408 * sizeof(double _Complex));
    v410 = chan_last_read_ok(chan382);
    if (v410) {
        bool v412;
        
        v412 = chan_last_read_ok(chan383);
        r411 = v412;
    } else {
        r411 = false;
    }
    if (!r411) {
        chan_close(chan401);
        chan_close(chan402);
        pthread_cancel(t403);
        pthread_join(t403, NULL);
    }
    r413 = v408;
    a414 = alloca(v408 * sizeof(double _Complex));
    for (v415 = 0; v415 < v408; v415++) {
        a414[v415] = a409[(v415 >> 1 >> 6 << 1 | (v415 & 1)) << 6 | (v415 >> 1 &
                                                                     63)];
    }
    v416 = r413;
    v417 = v416;
    v418 = chan_write(chan401, sizeof(v417), &v417);
    v419 = chan_write(chan402, sizeof(*a414) * ((uint32_t) v416 - 0), &a414[0]);
    if (!v419) {
        chan_close(chan382);
        chan_close(chan383);
        pthread_cancel(t403);
        pthread_join(t403, NULL);
    }
    chan_close(chan382);
    chan_close(chan383);
    chan_close(chan401);
    chan_close(chan402);
    return NULL;
}
chan_t chan420;
chan_t chan421;
pthread_t t422;
void *thread_t422(void *unused)
{
    uint32_t v423;
    double _Complex *a424;
    bool v425;
    uint32_t r426;
    uint32_t v427;
    double _Complex *a428;
    bool v429;
    bool r430;
    uint32_t r432;
    double _Complex *a433;
    uint32_t v434;
    uint32_t v435;
    uint32_t v436;
    bool v437;
    bool v438;
    
    chan_read(chan401, sizeof(v423), &v423);
    a424 = alloca((uint32_t) v423 * sizeof(double _Complex));
    chan_read(chan402, sizeof(*a424) * (v423 - 0), &a424[0]);
    v425 = chan_last_read_ok(chan402);
    r426 = (uint32_t) v423;
    v427 = r426;
    a428 = alloca(v427 * sizeof(double _Complex));
    memcpy(a428, a424, v427 * sizeof(double _Complex));
    v429 = chan_last_read_ok(chan401);
    if (v429) {
        bool v431;
        
        v431 = chan_last_read_ok(chan402);
        r430 = v431;
    } else {
        r430 = false;
    }
    if (!r430) {
        chan_close(chan420);
        chan_close(chan421);
        pthread_cancel(t422);
        pthread_join(t422, NULL);
    }
    r432 = v427;
    a433 = alloca(v427 * sizeof(double _Complex));
    for (v434 = 0; v434 < v427; v434++) {
        a433[v434] = a428[(v434 >> 1 >> 7 << 1 | (v434 & 1)) << 7 | (v434 >> 1 &
                                                                     127)];
    }
    v435 = r432;
    v436 = v435;
    v437 = chan_write(chan420, sizeof(v436), &v436);
    v438 = chan_write(chan421, sizeof(*a433) * ((uint32_t) v435 - 0), &a433[0]);
    if (!v438) {
        chan_close(chan401);
        chan_close(chan402);
        pthread_cancel(t422);
        pthread_join(t422, NULL);
    }
    chan_close(chan401);
    chan_close(chan402);
    chan_close(chan420);
    chan_close(chan421);
    return NULL;
}
chan_t chan439;
chan_t chan440;
pthread_t t441;
void *thread_t441(void *unused)
{
    uint32_t v442;
    double _Complex *a443;
    bool v444;
    uint32_t r445;
    uint32_t v446;
    double _Complex *a447;
    bool v448;
    bool r449;
    uint32_t r451;
    double _Complex *a452;
    uint32_t v453;
    uint32_t v454;
    uint32_t v455;
    bool v456;
    bool v457;
    
    chan_read(chan420, sizeof(v442), &v442);
    a443 = alloca((uint32_t) v442 * sizeof(double _Complex));
    chan_read(chan421, sizeof(*a443) * (v442 - 0), &a443[0]);
    v444 = chan_last_read_ok(chan421);
    r445 = (uint32_t) v442;
    v446 = r445;
    a447 = alloca(v446 * sizeof(double _Complex));
    memcpy(a447, a443, v446 * sizeof(double _Complex));
    v448 = chan_last_read_ok(chan420);
    if (v448) {
        bool v450;
        
        v450 = chan_last_read_ok(chan421);
        r449 = v450;
    } else {
        r449 = false;
    }
    if (!r449) {
        chan_close(chan439);
        chan_close(chan440);
        pthread_cancel(t441);
        pthread_join(t441, NULL);
    }
    r451 = v446;
    a452 = alloca(v446 * sizeof(double _Complex));
    for (v453 = 0; v453 < v446; v453++) {
        a452[v453] = a447[(v453 >> 1 >> 8 << 1 | (v453 & 1)) << 8 | (v453 >> 1 &
                                                                     255)];
    }
    v454 = r451;
    v455 = v454;
    v456 = chan_write(chan439, sizeof(v455), &v455);
    v457 = chan_write(chan440, sizeof(*a452) * ((uint32_t) v454 - 0), &a452[0]);
    if (!v457) {
        chan_close(chan420);
        chan_close(chan421);
        pthread_cancel(t441);
        pthread_join(t441, NULL);
    }
    chan_close(chan420);
    chan_close(chan421);
    chan_close(chan439);
    chan_close(chan440);
    return NULL;
}
chan_t chan458;
chan_t chan459;
pthread_t t460;
void *thread_t460(void *unused)
{
    uint32_t v461;
    double _Complex *a462;
    bool v463;
    uint32_t r464;
    uint32_t v465;
    double _Complex *a466;
    bool v467;
    bool r468;
    uint32_t r470;
    double _Complex *a471;
    uint32_t v472;
    uint32_t v473;
    uint32_t v474;
    bool v475;
    bool v476;
    
    chan_read(chan439, sizeof(v461), &v461);
    a462 = alloca((uint32_t) v461 * sizeof(double _Complex));
    chan_read(chan440, sizeof(*a462) * (v461 - 0), &a462[0]);
    v463 = chan_last_read_ok(chan440);
    r464 = (uint32_t) v461;
    v465 = r464;
    a466 = alloca(v465 * sizeof(double _Complex));
    memcpy(a466, a462, v465 * sizeof(double _Complex));
    v467 = chan_last_read_ok(chan439);
    if (v467) {
        bool v469;
        
        v469 = chan_last_read_ok(chan440);
        r468 = v469;
    } else {
        r468 = false;
    }
    if (!r468) {
        chan_close(chan458);
        chan_close(chan459);
        pthread_cancel(t460);
        pthread_join(t460, NULL);
    }
    r470 = v465;
    a471 = alloca(v465 * sizeof(double _Complex));
    for (v472 = 0; v472 < v465; v472++) {
        a471[v472] = a466[(v472 >> 1 >> 9 << 1 | (v472 & 1)) << 9 | (v472 >> 1 &
                                                                     511)];
    }
    v473 = r470;
    v474 = v473;
    v475 = chan_write(chan458, sizeof(v474), &v474);
    v476 = chan_write(chan459, sizeof(*a471) * ((uint32_t) v473 - 0), &a471[0]);
    if (!v476) {
        chan_close(chan439);
        chan_close(chan440);
        pthread_cancel(t460);
        pthread_join(t460, NULL);
    }
    chan_close(chan439);
    chan_close(chan440);
    chan_close(chan458);
    chan_close(chan459);
    return NULL;
}
chan_t chan477;
chan_t chan478;
pthread_t t479;
void *thread_t479(void *unused)
{
    uint32_t v480;
    double _Complex *a481;
    bool v482;
    uint32_t r483;
    uint32_t v484;
    double _Complex *a485;
    bool v486;
    bool r487;
    uint32_t r489;
    double _Complex *a490;
    uint32_t v491;
    uint32_t v492;
    uint32_t v493;
    bool v494;
    bool v495;
    
    chan_read(chan458, sizeof(v480), &v480);
    a481 = alloca((uint32_t) v480 * sizeof(double _Complex));
    chan_read(chan459, sizeof(*a481) * (v480 - 0), &a481[0]);
    v482 = chan_last_read_ok(chan459);
    r483 = (uint32_t) v480;
    v484 = r483;
    a485 = alloca(v484 * sizeof(double _Complex));
    memcpy(a485, a481, v484 * sizeof(double _Complex));
    v486 = chan_last_read_ok(chan458);
    if (v486) {
        bool v488;
        
        v488 = chan_last_read_ok(chan459);
        r487 = v488;
    } else {
        r487 = false;
    }
    if (!r487) {
        chan_close(chan477);
        chan_close(chan478);
        pthread_cancel(t479);
        pthread_join(t479, NULL);
    }
    r489 = v484;
    a490 = alloca(v484 * sizeof(double _Complex));
    for (v491 = 0; v491 < v484; v491++) {
        a490[v491] = a485[(v491 >> 1 >> 10 << 1 | (v491 & 1)) << 10 | (v491 >>
                                                                       1 &
                                                                       1023)];
    }
    v492 = r489;
    v493 = v492;
    v494 = chan_write(chan477, sizeof(v493), &v493);
    v495 = chan_write(chan478, sizeof(*a490) * ((uint32_t) v492 - 0), &a490[0]);
    if (!v495) {
        chan_close(chan458);
        chan_close(chan459);
        pthread_cancel(t479);
        pthread_join(t479, NULL);
    }
    chan_close(chan458);
    chan_close(chan459);
    chan_close(chan477);
    chan_close(chan478);
    return NULL;
}
chan_t chan496;
chan_t chan497;
pthread_t t498;
void *thread_t498(void *unused)
{
    uint32_t v499;
    double _Complex *a500;
    bool v501;
    uint32_t r502;
    uint32_t v503;
    double _Complex *a504;
    bool v505;
    bool r506;
    uint32_t r508;
    double _Complex *a509;
    uint32_t v510;
    uint32_t v511;
    uint32_t v512;
    bool v513;
    bool v514;
    
    chan_read(chan477, sizeof(v499), &v499);
    a500 = alloca((uint32_t) v499 * sizeof(double _Complex));
    chan_read(chan478, sizeof(*a500) * (v499 - 0), &a500[0]);
    v501 = chan_last_read_ok(chan478);
    r502 = (uint32_t) v499;
    v503 = r502;
    a504 = alloca(v503 * sizeof(double _Complex));
    memcpy(a504, a500, v503 * sizeof(double _Complex));
    v505 = chan_last_read_ok(chan477);
    if (v505) {
        bool v507;
        
        v507 = chan_last_read_ok(chan478);
        r506 = v507;
    } else {
        r506 = false;
    }
    if (!r506) {
        chan_close(chan496);
        chan_close(chan497);
        pthread_cancel(t498);
        pthread_join(t498, NULL);
    }
    r508 = v503;
    a509 = alloca(v503 * sizeof(double _Complex));
    for (v510 = 0; v510 < v503; v510++) {
        a509[v510] = a504[(v510 >> 1 >> 11 << 1 | (v510 & 1)) << 11 | (v510 >>
                                                                       1 &
                                                                       2047)];
    }
    v511 = r508;
    v512 = v511;
    v513 = chan_write(chan496, sizeof(v512), &v512);
    v514 = chan_write(chan497, sizeof(*a509) * ((uint32_t) v511 - 0), &a509[0]);
    if (!v514) {
        chan_close(chan477);
        chan_close(chan478);
        pthread_cancel(t498);
        pthread_join(t498, NULL);
    }
    chan_close(chan477);
    chan_close(chan478);
    chan_close(chan496);
    chan_close(chan497);
    return NULL;
}
chan_t chan515;
chan_t chan516;
pthread_t t517;
void *thread_t517(void *unused)
{
    uint32_t v518;
    double _Complex *a519;
    bool v520;
    uint32_t r521;
    uint32_t v522;
    double _Complex *a523;
    bool v524;
    bool r525;
    uint32_t r527;
    double _Complex *a528;
    uint32_t v529;
    uint32_t v530;
    uint32_t v531;
    bool v532;
    bool v533;
    
    chan_read(chan496, sizeof(v518), &v518);
    a519 = alloca((uint32_t) v518 * sizeof(double _Complex));
    chan_read(chan497, sizeof(*a519) * (v518 - 0), &a519[0]);
    v520 = chan_last_read_ok(chan497);
    r521 = (uint32_t) v518;
    v522 = r521;
    a523 = alloca(v522 * sizeof(double _Complex));
    memcpy(a523, a519, v522 * sizeof(double _Complex));
    v524 = chan_last_read_ok(chan496);
    if (v524) {
        bool v526;
        
        v526 = chan_last_read_ok(chan497);
        r525 = v526;
    } else {
        r525 = false;
    }
    if (!r525) {
        chan_close(chan515);
        chan_close(chan516);
        pthread_cancel(t517);
        pthread_join(t517, NULL);
    }
    r527 = v522;
    a528 = alloca(v522 * sizeof(double _Complex));
    for (v529 = 0; v529 < v522; v529++) {
        a528[v529] = a523[(v529 >> 1 >> 12 << 1 | (v529 & 1)) << 12 | (v529 >>
                                                                       1 &
                                                                       4095)];
    }
    v530 = r527;
    v531 = v530;
    v532 = chan_write(chan515, sizeof(v531), &v531);
    v533 = chan_write(chan516, sizeof(*a528) * ((uint32_t) v530 - 0), &a528[0]);
    if (!v533) {
        chan_close(chan496);
        chan_close(chan497);
        pthread_cancel(t517);
        pthread_join(t517, NULL);
    }
    chan_close(chan496);
    chan_close(chan497);
    chan_close(chan515);
    chan_close(chan516);
    return NULL;
}
chan_t chan534;
chan_t chan535;
pthread_t t536;
void *thread_t536(void *unused)
{
    uint32_t v537;
    double _Complex *a538;
    bool v539;
    uint32_t r540;
    uint32_t v541;
    double _Complex *a542;
    bool v543;
    bool r544;
    uint32_t r546;
    double _Complex *a547;
    uint32_t v548;
    uint32_t v549;
    uint32_t v550;
    bool v551;
    bool v552;
    
    chan_read(chan515, sizeof(v537), &v537);
    a538 = alloca((uint32_t) v537 * sizeof(double _Complex));
    chan_read(chan516, sizeof(*a538) * (v537 - 0), &a538[0]);
    v539 = chan_last_read_ok(chan516);
    r540 = (uint32_t) v537;
    v541 = r540;
    a542 = alloca(v541 * sizeof(double _Complex));
    memcpy(a542, a538, v541 * sizeof(double _Complex));
    v543 = chan_last_read_ok(chan515);
    if (v543) {
        bool v545;
        
        v545 = chan_last_read_ok(chan516);
        r544 = v545;
    } else {
        r544 = false;
    }
    if (!r544) {
        chan_close(chan534);
        chan_close(chan535);
        pthread_cancel(t536);
        pthread_join(t536, NULL);
    }
    r546 = v541;
    a547 = alloca(v541 * sizeof(double _Complex));
    for (v548 = 0; v548 < v541; v548++) {
        a547[v548] = a542[(v548 >> 1 >> 13 << 1 | (v548 & 1)) << 13 | (v548 >>
                                                                       1 &
                                                                       8191)];
    }
    v549 = r546;
    v550 = v549;
    v551 = chan_write(chan534, sizeof(v550), &v550);
    v552 = chan_write(chan535, sizeof(*a547) * ((uint32_t) v549 - 0), &a547[0]);
    if (!v552) {
        chan_close(chan515);
        chan_close(chan516);
        pthread_cancel(t536);
        pthread_join(t536, NULL);
    }
    chan_close(chan515);
    chan_close(chan516);
    chan_close(chan534);
    chan_close(chan535);
    return NULL;
}
chan_t chan553;
chan_t chan554;
pthread_t t555;
void *thread_t555(void *unused)
{
    uint32_t v556;
    double _Complex *a557;
    bool v558;
    uint32_t r559;
    uint32_t v560;
    double _Complex *a561;
    bool v562;
    bool r563;
    uint32_t r565;
    double _Complex *a566;
    uint32_t v567;
    uint32_t v568;
    uint32_t v569;
    bool v570;
    bool v571;
    
    chan_read(chan534, sizeof(v556), &v556);
    a557 = alloca((uint32_t) v556 * sizeof(double _Complex));
    chan_read(chan535, sizeof(*a557) * (v556 - 0), &a557[0]);
    v558 = chan_last_read_ok(chan535);
    r559 = (uint32_t) v556;
    v560 = r559;
    a561 = alloca(v560 * sizeof(double _Complex));
    memcpy(a561, a557, v560 * sizeof(double _Complex));
    v562 = chan_last_read_ok(chan534);
    if (v562) {
        bool v564;
        
        v564 = chan_last_read_ok(chan535);
        r563 = v564;
    } else {
        r563 = false;
    }
    if (!r563) {
        chan_close(chan553);
        chan_close(chan554);
        pthread_cancel(t555);
        pthread_join(t555, NULL);
    }
    r565 = v560;
    a566 = alloca(v560 * sizeof(double _Complex));
    for (v567 = 0; v567 < v560; v567++) {
        a566[v567] = a561[(v567 >> 1 >> 14 << 1 | (v567 & 1)) << 14 | (v567 >>
                                                                       1 &
                                                                       16383)];
    }
    v568 = r565;
    v569 = v568;
    v570 = chan_write(chan553, sizeof(v569), &v569);
    v571 = chan_write(chan554, sizeof(*a566) * ((uint32_t) v568 - 0), &a566[0]);
    if (!v571) {
        chan_close(chan534);
        chan_close(chan535);
        pthread_cancel(t555);
        pthread_join(t555, NULL);
    }
    chan_close(chan534);
    chan_close(chan535);
    chan_close(chan553);
    chan_close(chan554);
    return NULL;
}
chan_t chan572;
chan_t chan573;
pthread_t t574;
void *thread_t574(void *unused)
{
    uint32_t v575;
    double _Complex *a576;
    bool v577;
    uint32_t r578;
    uint32_t v579;
    double _Complex *a580;
    bool v581;
    bool r582;
    uint32_t r584;
    double _Complex *a585;
    uint32_t v586;
    uint32_t v587;
    uint32_t v588;
    bool v589;
    bool v590;
    
    chan_read(chan553, sizeof(v575), &v575);
    a576 = alloca((uint32_t) v575 * sizeof(double _Complex));
    chan_read(chan554, sizeof(*a576) * (v575 - 0), &a576[0]);
    v577 = chan_last_read_ok(chan554);
    r578 = (uint32_t) v575;
    v579 = r578;
    a580 = alloca(v579 * sizeof(double _Complex));
    memcpy(a580, a576, v579 * sizeof(double _Complex));
    v581 = chan_last_read_ok(chan553);
    if (v581) {
        bool v583;
        
        v583 = chan_last_read_ok(chan554);
        r582 = v583;
    } else {
        r582 = false;
    }
    if (!r582) {
        chan_close(chan572);
        chan_close(chan573);
        pthread_cancel(t574);
        pthread_join(t574, NULL);
    }
    r584 = v579;
    a585 = alloca(v579 * sizeof(double _Complex));
    for (v586 = 0; v586 < v579; v586++) {
        a585[v586] = a580[(v586 >> 1 >> 15 << 1 | (v586 & 1)) << 15 | (v586 >>
                                                                       1 &
                                                                       32767)];
    }
    v587 = r584;
    v588 = v587;
    v589 = chan_write(chan572, sizeof(v588), &v588);
    v590 = chan_write(chan573, sizeof(*a585) * ((uint32_t) v587 - 0), &a585[0]);
    if (!v590) {
        chan_close(chan553);
        chan_close(chan554);
        pthread_cancel(t574);
        pthread_join(t574, NULL);
    }
    chan_close(chan553);
    chan_close(chan554);
    chan_close(chan572);
    chan_close(chan573);
    return NULL;
}
pthread_t t591;
void *thread_t591(void *unused)
{
    while (1) {
        uint32_t v592;
        double _Complex *a593;
        bool v594;
        uint32_t r595;
        uint32_t v596;
        double _Complex *a597;
        bool v598;
        bool r599;
        uint32_t v601;
        
        chan_read(chan572, sizeof(v592), &v592);
        a593 = alloca((uint32_t) v592 * sizeof(double _Complex));
        chan_read(chan573, sizeof(*a593) * (v592 - 0), &a593[0]);
        v594 = chan_last_read_ok(chan573);
        r595 = (uint32_t) v592;
        v596 = r595;
        a597 = alloca(v596 * sizeof(double _Complex));
        memcpy(a597, a593, v596 * sizeof(double _Complex));
        v598 = chan_last_read_ok(chan572);
        if (v598) {
            bool v600;
            
            v600 = chan_last_read_ok(chan573);
            r599 = v600;
        } else {
            r599 = false;
        }
        if (!r599) {
            pthread_cancel(t591);
            pthread_join(t591, NULL);
        }
        
        end_iteration();

        print_time();
        
        for (v601 = 0; v601 < v596; v601++) {
            fprintf(stdout, "%+10.5f %+10.5f\n", creal(a597[v601]), cimag(a597[v601]));
        }
        if (!true) {
            chan_close(chan572);
            chan_close(chan573);
            pthread_cancel(t591);
            pthread_join(t591, NULL);
        }
    }
    return NULL;
}
int main()
{
    chan0 = chan_new(65536 * sizeof(uint32_t));
    chan1 = chan_new(65536 * sizeof(double _Complex));
    chan2 = chan_new(65536 * sizeof(uint32_t));
    chan3 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t4, NULL, thread_t4, NULL);
    chan21 = chan_new(65536 * sizeof(uint32_t));
    chan22 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t23, NULL, thread_t23, NULL);
    chan40 = chan_new(65536 * sizeof(uint32_t));
    chan41 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t42, NULL, thread_t42, NULL);
    chan59 = chan_new(65536 * sizeof(uint32_t));
    chan60 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t61, NULL, thread_t61, NULL);
    chan78 = chan_new(65536 * sizeof(uint32_t));
    chan79 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t80, NULL, thread_t80, NULL);
    chan97 = chan_new(65536 * sizeof(uint32_t));
    chan98 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t99, NULL, thread_t99, NULL);
    chan116 = chan_new(65536 * sizeof(uint32_t));
    chan117 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t118, NULL, thread_t118, NULL);
    chan135 = chan_new(65536 * sizeof(uint32_t));
    chan136 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t137, NULL, thread_t137, NULL);
    chan154 = chan_new(65536 * sizeof(uint32_t));
    chan155 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t156, NULL, thread_t156, NULL);
    chan173 = chan_new(65536 * sizeof(uint32_t));
    chan174 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t175, NULL, thread_t175, NULL);
    chan192 = chan_new(65536 * sizeof(uint32_t));
    chan193 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t194, NULL, thread_t194, NULL);
    chan211 = chan_new(65536 * sizeof(uint32_t));
    chan212 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t213, NULL, thread_t213, NULL);
    chan230 = chan_new(65536 * sizeof(uint32_t));
    chan231 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t232, NULL, thread_t232, NULL);
    chan249 = chan_new(65536 * sizeof(uint32_t));
    chan250 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t251, NULL, thread_t251, NULL);
    chan268 = chan_new(65536 * sizeof(uint32_t));
    chan269 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t270, NULL, thread_t270, NULL);
    chan287 = chan_new(65536 * sizeof(uint32_t));
    chan288 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t289, NULL, thread_t289, NULL);
    chan306 = chan_new(65536 * sizeof(uint32_t));
    chan307 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t308, NULL, thread_t308, NULL);
    chan325 = chan_new(65536 * sizeof(uint32_t));
    chan326 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t327, NULL, thread_t327, NULL);
    chan344 = chan_new(65536 * sizeof(uint32_t));
    chan345 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t346, NULL, thread_t346, NULL);
    chan363 = chan_new(65536 * sizeof(uint32_t));
    chan364 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t365, NULL, thread_t365, NULL);
    chan382 = chan_new(65536 * sizeof(uint32_t));
    chan383 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t384, NULL, thread_t384, NULL);
    chan401 = chan_new(65536 * sizeof(uint32_t));
    chan402 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t403, NULL, thread_t403, NULL);
    chan420 = chan_new(65536 * sizeof(uint32_t));
    chan421 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t422, NULL, thread_t422, NULL);
    chan439 = chan_new(65536 * sizeof(uint32_t));
    chan440 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t441, NULL, thread_t441, NULL);
    chan458 = chan_new(65536 * sizeof(uint32_t));
    chan459 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t460, NULL, thread_t460, NULL);
    chan477 = chan_new(65536 * sizeof(uint32_t));
    chan478 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t479, NULL, thread_t479, NULL);
    chan496 = chan_new(65536 * sizeof(uint32_t));
    chan497 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t498, NULL, thread_t498, NULL);
    chan515 = chan_new(65536 * sizeof(uint32_t));
    chan516 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t517, NULL, thread_t517, NULL);
    chan534 = chan_new(65536 * sizeof(uint32_t));
    chan535 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t536, NULL, thread_t536, NULL);
    chan553 = chan_new(65536 * sizeof(uint32_t));
    chan554 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t555, NULL, thread_t555, NULL);
    chan572 = chan_new(65536 * sizeof(uint32_t));
    chan573 = chan_new(65536 * sizeof(double _Complex));
    pthread_create(&t574, NULL, thread_t574, NULL);
    pthread_create(&t591, NULL, thread_t591, NULL);

        start_iteration();

        double _Complex _a602[65536];
        double _Complex *a602 = _a602;
        uint32_t v603;
        uint32_t r604;
        double _Complex _a605[65536];
        double _Complex *a605 = _a605;
        uint32_t v606;
        uint32_t v607;
        uint32_t v608;
        bool v609;
        bool v610;
        
        for (v603 = 0; v603 < 65536; v603++) {
            a602[v603] = (double) v603 + I * -((double) v603);
        }
        r604 = 65536;
        for (v606 = 0; v606 < 65536; v606++) {
            a605[v606] = a602[v606];
        }
        v607 = r604;
        v608 = v607;
        v609 = chan_write(chan0, sizeof(v608), &v608);
        v610 = chan_write(chan1, sizeof(*a605) * ((uint32_t) v607 - 0),
                          &a605[0]);

        
    
    chan_close(chan0);
    chan_close(chan1);
    pthread_join(t591, NULL);
    return 0;
}

