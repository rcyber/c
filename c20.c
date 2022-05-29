#include <stdio.h>
 
char * mystrchr(const char * s, const char c) {
    while ( *s && *s != c )
        ++s;
    return ( *s ) ? (char*) s : NULL;
}
 
char * tiktok(char * str, const char * delim) {
    static char * next;
    
    if ( str ) {
        next = str;
        while ( *next && mystrchr(delim, *next) )
            *next++ = '\0';
    }
    
    if ( ! *next )
        return NULL;
    
    str = next;
    
    while ( *next && ! mystrchr(delim, *next) )
        ++next;
    while ( *next && mystrchr(delim, *next) )
        *next++ = '\0';
    
    return str;
}
 
#define DELIM " \t\n"
 
int main(void) {
    char str [44]= "test1/test2/test3/test4/test5/";  
   char sep [10]= "/";  
   char *istr; // Переменная, в которую будут заноситься начальные адреса частей 

   printf("Исходная строка: %s\n", str);
   printf("Результат разбиения:\n");
   
   istr = tiktok (str, sep); // Выделение первой части строки

   while (istr != NULL)  // Выделение последующих частей
   {
      printf("%s\n", istr);  // Вывод очередной выделенной части
      istr = tiktok (NULL, sep);  // Выделение очередной части строки
   }

    return 0;
}