#include <stdio.h>

int main(void){

int x,y,z;
char str[10];

printf("Whats youre name?\n");
scanf("%s",str);

printf(" Hello %s!\nEnter number\n> ",str);
scanf("%i", &x);

printf("+\n> ");
scanf("%i",&y);

printf("----------------------\n");
printf("%i+%i=%i\n",x,y,x+y);
printf("%s\n",str);



    return 0;

}
