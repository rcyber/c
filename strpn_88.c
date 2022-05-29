#include <stdio.h>
#include <string.h>

int main(void) {

    char text[] = "--3476235723fdfdfdfdf";
    char num[] = "-";
    
    int pos = strspn(text, num );

    printf("%d", pos);

    return 0;
}