N=65536
ROUNDS=10
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
    && /usr/bin/time -v ./feldspar_fft > feldspar_fft_out.txt
# diff fftw_out.txt feldspar_fft_out.txt

