#include <stdio.h>  
#include <string.h> 
int main (void)
{    
 
   char str [24]= "test1/test2/test3/test4";  
   char sep [10]= "/";  
   char *istr; // Переменная, в которую будут заноситься начальные адреса частей 

   printf("Исходная строка: %s\n", str);
   printf("Результат разбиения:\n");
   
   istr = strtok (str, sep); // Выделение первой части строки

   while (istr != NULL)  // Выделение последующих частей
   {
      printf("%s\n", istr);  // Вывод очередной выделенной части
      istr = strtok (NULL, sep);  // Выделение очередной части строки
   }

   


   return 0;
}