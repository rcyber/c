
#include <stdio.h>
int main(void){
  int z = 1/10;
  float x = 1.0/10.0; // scan f
  double y = 1.0/10.0; // scan lf
  
  printf("int:\n%d\n\n", z);
  printf("float:\n4\t--\t%.4f\n10\t--\t%.12f\n16\t--\t%.16f\n\n", x,x,x);
  printf("double:\n4\t--\t%.4f\n10\t--\t%.12f\n16\t--\t%.16f\n", y,y,y);

  return(0);
}

