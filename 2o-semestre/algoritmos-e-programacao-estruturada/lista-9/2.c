#include <stdio.h>
void main(void) {
char *a = (char*) 0x1000;                  // Um char mede 1 byte
int *b = (int*) 0x1000;                    // Um int mede 4 bytes
float *c = (float *) 0x1000;               // Um float mede 4 bytes
double *d = (double *) 0x1000;             // Um double mede 8 bytes
printf("%p %p %p %p", a+1, b+1, c+1, d+1); // Saída: 1001 1004 1004 1008
}