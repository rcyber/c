#include <stdio.h>
#include <string.h>

int main(void) {

    char text[20] = "hello_world_its_me";
    char sep[20] = "_";
    
    char *temp = strtok(text, sep);
    
    
    
    while (temp != NULL) {
    
    printf("%s\n", temp);
    temp = strtok(NULL, sep);
    }
    
int i = 0;
while(i < 30) {
    printf("%c ",text[i]);
    i++;
}

    return 0;
}