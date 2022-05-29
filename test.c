#include <stdio.h>
#include <string.h>

int main(void) {



    char text[12] = "hello_world";
    
    
    char *x = text;
    
    printf("%s\n", x);
    x[0] = 45 ;
    printf("%s\n", text);
    return 0;
}