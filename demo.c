#include <stdio.h>

void addblock(int *p, int len) {
    int newsize = ((len + 1) >> 1) << 1;
    int oldsize = *p & -2;
}