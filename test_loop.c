#include <stdio.h>

int main() {
    volatile long sum = 0;
    for (long i = 0; i < 2000000; i++) {
        if (i % 7 == 0) sum += i;   // conditional branch present
        else sum += (i & 3);
    }
    printf("done %ld\n", sum);
    return 0;
}
