#include <stdio.h>

int main(void) 
{
 
 char name[10];
 int age ;
 printf("Hello. What is youre name?\n");
 scanf("%s", &name);
 printf("Ok %s. How old are you?\n", name);
 scanf("%d", &age);

 if (age >= 18) { 
     printf("\nWelcome %s!  Youre age %d", name, age);}
 else { 
     printf("Go fuck %s...", name);}

  return 0;
}
