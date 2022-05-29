// Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest.
// char *strcat(char *dest, const char *src)

#include <stdio.h>


char *
strncat(char *dest, const char *src, size_t n)
{
    size_t dest_len = strlen(dest);
    size_t i;
    for (i = 0 ; i < n && src[i] != '\0' ; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    return dest;
}

int main() {

    strncat()

    return 0;
}


char *s21_strcat(char *dest, const char *src) {
    s21_size_t size = s21_strlen(dest);
    int i = 0;
    for (; *(src + i) != '\0'; i++) {
        *(dest + size + i) = *(src + i);
    }
    *(dest + size + i) = '\0';
    return dest;