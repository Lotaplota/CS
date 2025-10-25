#include <stdio.h>
void main(void) {
int *p = (int *) 0x1000; // Um int mede 4 bytes, então a aritmética funciona em incrementos de 4
p++; printf("%p ", p );  // Saída: 1004
p-=3; printf("%p ", p ); // Saída: 0FF8
p+=2; printf("%p ", p ); // Saída: 1000
p--; printf("%p ", p );  // Saída: 0FFC
}