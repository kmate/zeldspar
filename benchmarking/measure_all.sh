N=65536
ROUNDS=1
FLAGS="-DN=$N -DROUNDS=$ROUNDS"

echo Running with flags $FLAGS

echo FFTW
gcc -std=gnu99 fftw.c -o fftw -lfftw3 $FLAGS \
    && /usr/bin/time -v ./fftw > fftw_out.txt

echo Textbook
gcc -std=gnu99 nr_fft.c -o nr_fft -lm $FLAGS \
    && /usr/bin/time -v ./nr_fft> nr_fft_out.txt
# diff fftw_out.txt nr_fft_out.txt

echo Feldspar
gcc -std=gnu99 feldspar_fft.c -o feldspar_fft -lm $FLAGS \
    && ulimit -s 10000000 \
    && /usr/bin/time -v ./feldspar_fft > feldspar_fft_out.txt
# diff fftw_out.txt feldspar_fft_out.txt

echo Zeldspar
gcc -std=gnu99 -I../../imperative-edsl/include ../../imperative-edsl/csrc/chan.c zeldspar_fft.c -o zeldspar_fft -lpthread -lm $FLAGS \
    && ulimit -s 10000000 \
    && /usr/bin/time -v ./zeldspar_fft > zeldspar_fft_out.txt

