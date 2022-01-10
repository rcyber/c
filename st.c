#include <stdio.h>
#define N "_________________________________________________\n"
#define X "********_________________________________________\n"

int main() {
    int x = 0;

printf(N);
while (x<6) { printf(X); x++;}
    x=0;
while (x<6) { printf(N); x++;}

  return 0;
}
