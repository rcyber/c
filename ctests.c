#include <stdio.h>
#include <string.h>

int main(void) {

    char text[20] = "test1/test2/test3/";
    char hey[20] = "hi_my_name_is_fox";
    char sep[10] = "_";
    char *yy;
    char *x = strtok(hey, sep);
    printf("%s\n", hey);
    printf("%s\n", x);

    x = strtok(NULL, sep);
    printf("%s\n", hey);
    printf("%s\n", x);
    x = strtok(NULL, sep);
    printf("%s\n", hey);
    printf("x =%s\n", x);
    
    yy = strtok(text, "/");
    printf("%s\n", yy);
    printf("--------\n");
    printf("%s\n", hey);
    printf("%s\n", x);
    printf("--------\n");
    x = strtok(NULL, sep);
    printf("hey : %s\n", hey);
    printf("x : %s\n", x);
    printf("text : %s\n", text);


    return 0;
}