#include <stdio.h>
#include <string.h>

int main(void) {
    char mystr[20] = "my_hello_world_21";
    char sep[10] = "_";
    printf("1%s\n", mystr);
    char *x = strtok(mystr, sep);
    printf("2%s\n", x);
    
    

    x = strtok(NULL, sep);
    printf("4%s\n", x);
    
   

x = strtok(NULL, sep);
    printf("6%s\n", x);
    
   
x = strtok(NULL, sep);
    printf("6%s\n", x);
    

x = strtok(NULL, sep);
    printf("6%s\n", x);
    
printf("%s", mystr);




    return 0;
}