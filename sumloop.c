// sumloop.c
#include <stdio.h>
int main() {
    volatile long sum = 0;
    for (int i = 0; i < 2000000; i++) {
        sum += i;
        if ((i & 0x3FF) == 0) ; // small conditional to generate branches
    }
    printf("sum=%ld\\n", sum);
    return 0;
}
