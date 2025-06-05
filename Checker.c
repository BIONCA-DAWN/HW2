#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Checker.h"

int is_divisible(int dividend, int divisor) {
    return (dividend % divisor == 0);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Checker: Invalid number of arguments.\n");
        return 0;
    }

    int divisor = atoi(argv[1]);
    int dividend = atoi(argv[2]);

    printf("Checker process [%d]: Starting.\n", getpid());

    if (is_divisible(dividend, divisor)) {
        printf("Checker process [%d]: %d *IS* divisible by %d.\n", getpid(), dividend, divisor);
        printf("Checker process [%d]: Returning 1.\n", getpid());
        return 1;
    } else {
        printf("Checker process [%d]: %d *IS NOT* divisible by %d.\n", getpid(), dividend, divisor);
        printf("Checker process [%d]: Returning 0.\n", getpid());
        return 0;
    }
}
