#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// DONOT edit this 
int randint(int min, int max) {
    return rand() % (max - min)  + min;
}

// EDIT this function. DONOT edit the signature of the function
bool is_prime(long n, long* factor_p) {
    //Special case for 1 and 2
    if (n <= 2){
        return (n == 2) ? true : false;
    }
    //Static flag variable for recursion
    static int started = 0;
    if (!started){
        //New n being checked, start factor at 2
        *factor_p = 2;
        started = 1;
    }
    //Divisor with no remainder, that's a factor! Composite!
    if (n % *factor_p == 0){
        started = 0;
        return 0;
    }
    //Only check factors below sqrt(n)
    if (*factor_p * *factor_p > n){
        started = 0;
        return 1;
    }
    //Increment factor
    ++*factor_p;
    return is_prime(n, factor_p);
}

// DONOT edit this function
bool test_prime() {
    long factor;
    int n = rand();
    if (is_prime(n, &factor)) {
        if (n % factor == 0) {
            fprintf(stderr, "Fail for is_prime(%d, %ld)\n", n, factor);
            return false;
        } else {
            return true;
        }
    } else {
        int i;
	// Try 10 random factors
        for (i = 0; i < 20; ++i){
            factor = randint(2, n/2);
            if (n % factor == 0) {
                fprintf(stderr, "Fail for is_prime(%d, %ld)\n", n, factor);
                return false;
            }
        }
        return true;
    }
}

int main(int argc, char** argv) {
  long factor;
#define ARRSIZE 10
  long primes[ARRSIZE] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
  short i;
  for (i = 0; i < ARRSIZE; ++i)
      if (is_prime(primes[i], &factor) != true) 
	  fprintf(stderr, "Fail for is_prime(%ld)\n", primes[i]);
      else
	  printf("Pass\n");

  long composites[ARRSIZE] = {1, 4, 6, 8, 10, 14, 21, 25, 27, 33 };
  for (i = 0; i < ARRSIZE; ++i)
      if (is_prime(composites[i], &factor) != false) 
	  fprintf(stderr, "Fail for is_prime(%ld)\n", composites[i]);
      else
	  printf("Pass\n");

  for (i = 0; i < 10; ++i) {
      if (test_prime()) 
	  printf("%d: pass\n", i);
      else
	  fprintf(stderr, "%d: fail\n", i);
  }
}
