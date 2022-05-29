#include <stdio.h>
#include <string.h>


int main() {

    char ss [24]= "test1/test2/test3/test4";
    char *istr;
    istr = strtok (ss, "/");
    while (istr != NULL)
   {
      // Вывод очередной выделенной части
      printf("%s\n", istr);
      // Выделение очередной части строки
      istr = strtok (NULL, "/");
   }

    return 0;
}