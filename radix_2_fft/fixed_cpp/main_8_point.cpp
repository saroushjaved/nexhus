#include <cstdint>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


struct Complex {
    int16_t real;
    int16_t imag;
};


void bit_reverse_reorder_incr(int *input, int n);

int main(){

    int16_t x[8] = {
     0x0000,  //  0.0000
     0x5A82,  // +0.7071
     0x7FFF,  // +1.0000
     0x5A82,  // +0.7071
     0x0000,  //  0.0000
     0xA57E,  // -0.7071
     0x8000,  // -1.0000
     0xA57E   // -0.7071
    };

    bit_reverse_reorder_incr(x, 8);

    // Stage 1 : Two Point FFTs
    for(int i=0; i<8; i+=2){
        Complex a = {x[i], 0};
        Complex b = {x[i+1], 0};
        two_point_fft(&a, &b);
        x[i]   = a.real;
        x[i+1] = b.real;
    }

}



// Two Point FFT Function (memory in-place)
void two_point_fft(Complex* a, Complex* b) {
    Complex t;
    t.real = a->real + b->real;
    t.imag = a->imag + b->imag;
    b->real = a->real - b->real;
    b->imag = a->imag - b->imag;
    *a = t;
}


// Incremental Bit Reversal Function
template <typename T>
void bit_reverse_reorder_incr(T* x, uint32_t N) {
    // N must be power of 2
    uint32_t j = 0;
    for (uint32_t i = 0; i < N; ++i) {
        if (i < j) std::swap(x[i], x[j]);

        // compute next j in bit-reversed order
        uint32_t bit = N >> 1;
        while (j & bit) {
            j ^= bit;
            bit >>= 1;
        }
        j ^= bit;
    }
}
