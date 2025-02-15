#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cont;
} FibonacciCount;

int fibonacci(int n, FibonacciCount *counter) {
    counter->cont++;
    if (n == 0 || n == 1)
        return n;
    else
        return fibonacci(n - 1, counter) + fibonacci(n - 2, counter);
}

int main() {
    int n, fib;
    int result;
    scanf("%d", &n);

    while (n--) {
        FibonacciCount counter = {0}; 
        scanf("%d", &fib);
        
        result = fibonacci(fib, &counter);
        
        printf("fib(%d) = %d calls = %d\n", fib, counter.cont - 1, result);
    }

    return 0;
}
