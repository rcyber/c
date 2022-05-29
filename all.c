#include "s21_string.h"
#include <float.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
​
​
​
s21_size_t s21_strlen(const char *str) {
    return (*str) ? s21_strlen(++str) + 1 : 0;
}
​
void *s21_memchr(const void *str, int c, s21_size_t n) {
    char *ch = s21_NULL;
    for (s21_size_t i = 0; i < n; i++) {
        if (*((char *)str + i) == c) {
            ch = (char *)str + i;
            break;
        }
    }
    return ch;
}
​
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    int ch = 0;
    for (s21_size_t i = 0; i < n; i++) {
        if (*((char *)str1 + i) != *((char *)str2 + i)) {
            ch = *((char *)str1 + i) - *((char *)str2 + i);
            break;
        }
    }
    return ch;
}
​
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    for (s21_size_t i = 0; i < n; i++) {
        *((char *)dest + i) = *((char *)src + i);
    }
    return dest;
}
​
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    char *buff = (char *)calloc(n, sizeof(char));
    s21_memcpy(buff, src, n);
    s21_memcpy(dest, buff, n);
    free(buff);
    return dest;
}
​
void *s21_memset(void *str, int c, s21_size_t n) {
    for (s21_size_t i = 0; i < n; i++) {
        *((char *)str + i) = c;
    }
    return str;
}
​
char *s21_strcat(char *dest, const char *src) {
    s21_size_t size = s21_strlen(dest);
    int i = 0;
    for (; *(src + i) != '\0'; i++) {
        *(dest + size + i) = *(src + i);
    }
    *(dest + size + i) = '\0';
    return dest;
}
​
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    char *start = dest;
    dest += s21_strlen(dest);
    for (; (n != 0 && *src != '\0'); n--) {
        *dest = *src;
        src++;
        dest++;
    }
    if (*(dest - 1) != '\0') {
        *dest = '\0';
    }
    return start;
}
​
char *s21_strchr(const char *str, int c) {
    char *result_adrr = s21_NULL;
    s21_size_t i;
    for (i = 0; i < s21_strlen(str); i++) {
        if (*((char *)str + i) == c) {
            result_adrr = (char *)str + i;
            break;
        } else {
            result_adrr = 0;
        }
    }
    return (result_adrr != 0) ? result_adrr : (char *)s21_NULL;
}
​
int s21_strcmp(const char *str1, const char *str2) {
    int result = 0;
    for (int i = 0; *((char *)str1 + i) != '\0' || *((char *)str2 + i) != '\0'; i++) {
        result = *(str1 + i) - *(str2 + i);
        if (result != 0) {
            break;
        }
    }
    return (result);
}
​
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    int result = 0;
    for (int i = 0; (*((char *)str1 + i) != '\0' || *((char *)str2 + i) != '\0') && i < (int)n; i++) {
        result = *(str1 + i) - *(str2 + i);
        if (result != 0) {
            break;
        }
    }
    return (result);
}
​
char *s21_strcpy(char *dest, const char *src) {
    char *r = dest;
    while ((*dest++ = *src++)) {
    }
    return r;
}
​
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    s21_size_t i = 0;
    int size = s21_strlen(dest);
    for (int j = 0; j < size; j++) {
        *(dest + j) = 0;
    }
    do {
        if (i < n) {
            *(dest + i) = *(src + i);
            i++;
        } else {
            break;
        }
    } while (*((char *)src + i) != '\0');
    return (dest);
}
​
s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t i = 0;
    while (i < s21_strlen(str1)) {
        if (s21_memchr(str2, *(str1 + i), s21_strlen(str2)) == s21_NULL) {
            i++;
        } else {
            break;
        }
    }
    return (i);
}
​
char *s21_strerror(int errnum) {
    char *out = (char *)calloc(50, sizeof(char));
    int err_p_max = 107;
    #if MACOS == 1
    err_p_max = 132;
    #endif
    #if LINUX == 1
    err_p_max = 107;
    #endif
    if (errnum < 0 || errnum > err_p_max) {
        #if MACOS == 1
        s21_sprintf(out, "Unknown error: %d", errnum);
        #endif
        #if LINUX == 1
        s21_sprintf(out, "No error information");
        #endif
    } else {
         #if MACOS == 1
        s21_sprintf(out, "%s", ErrorNames1[errnum]);
         #endif
         #if LINUX ==1
        s21_sprintf(out, "%s", ErrorNames[errnum]);
        #endif
    }
    out = (char *)realloc(out, s21_strlen(out));
    return (out);
}
​
char *s21_strpbrk(const char *str1, const char *str2) {
    s21_size_t i = 0;
    char *ch;
    while (*(str1 + i) && s21_strchr(str2, *(str1 + i)) == s21_NULL) i++;
    ch = *(str1 + i) ? (char *)(str1 + i) : s21_NULL;
    return (ch);
}
​
char *s21_strrchr(const char *str, int c) {
    char *ch = s21_NULL;
    for (int i = s21_strlen(str); i >= 0; i--)
        if (str[i] == c) {
            ch = (char *)str + i;
            break;
        }
    return ch;
}
​
s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t i, j;
    for (i = 0; str1[i] != '\0'; i++) {
        for (j = 0; str2[j] != str1[i]; j++) {
            if (str2[j] == '\0')
                return i;
        }
    }
    return i;
}
​
char *s21_strstr(const char *haystack, const char *needle) {
    int flag;
​
    for (int i = 0; haystack[i] != '\0'; i++) {
        if (haystack[i] == needle[0])
            flag = 0;
        for (int j = 0; needle[j] != '\0'; j++) {
            if (haystack[i + j] != needle[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            return (char *)haystack + i;
    }
    return s21_NULL;
}
​
char *s21_strtok(char *str, const char *delim) {
    static char *buffer;
    char *token = s21_NULL;
    if (str) {
        buffer = str;
        while (*buffer && s21_strchr(delim, *buffer)) {
            *buffer++ = '\0';
        }
    }
    if (buffer && *buffer) {
        str = buffer;
        while (*buffer && !s21_strchr(delim, *buffer)) {
            ++buffer;
        }
        while (*buffer && s21_strchr(delim, *buffer)) {
            *buffer++ = '\0';
        }
        token = str;
    }
    return token;
}
​
void *s21_to_upper(const char *str) {
    char *new_string = (char *)calloc(s21_strlen(str), sizeof(char));
    if (str != s21_NULL) {
        s21_strcpy(new_string, str);
        s21_size_t i = 0;
        for (; i < s21_strlen(new_string); i++) {
            if (new_string[i] >= 97 && new_string[i] <= 122) {
                new_string[i] = new_string[i] - 32;
            }
        }
    } else {
        free(new_string);
        new_string = s21_NULL;
    }
    return new_string;
}
​
void *s21_to_lower(const char *str) {
    char *new_string = (char *)calloc(s21_strlen(str), sizeof(char));
    if (str != s21_NULL) {
        s21_strcpy(new_string, str);
        s21_size_t i = 0;
        for (; i < s21_strlen(new_string); i++) {
            if (new_string[i] >= 65 && new_string[i] <= 90) {
                new_string[i] = new_string[i] + 32;
            }
        }
    } else {
        free(new_string);
        new_string = s21_NULL;
    }
    return new_string;
}
​
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char *new_string = s21_NULL;
    if (src && str && s21_strlen(src) >= start_index) {
        new_string = (char *)calloc((s21_strlen(src) + s21_strlen(str)), sizeof(char));
        s21_strncpy(new_string, src, start_index);
        new_string[start_index] = '\0';
        s21_strcat(new_string, str);
        s21_strcat(new_string, src + start_index);
    }
    return new_string;
}
​
void clean_str(char *str, int size_str) {
    if (size_str > 0) {
        for (int j = 0; j < size_str; j++) {
            *(str + j) = 0;
        }
    }
}
​
int s21_sprintf(char *str, const char *format, ...) {
    parcer_t spec[20];
    char *res = (char *)calloc(1000, sizeof(char));
    parcer(format, spec);
    va_list temp;
    va_start(temp, format);
    int size_format = s21_strlen(format);
    int i = 0;
    for (int j = 0; j < size_format; j++) {
        if (*(format + j) == '%' && spec[i].spec_pos == j) {
            if (spec[i].width_arg_flag == 1) {
                spec[i].width = va_arg(temp, int);
            }
            if (spec[i].accur_arg_flag == 1) {
                spec[i].accur = va_arg(temp, int);
            }
            if (spec[i].specif == 'c') {
                check_ch(&(spec[i]), res, va_arg(temp, int));
            } else if (spec[i].specif == 'd' || spec[i].specif == 'i' || spec[i].specif == 'u') {
                long int ld;
                short int sd;
                unsigned long int uld;
                unsigned short int usd;
                unsigned int ud;
                int d;
​
                switch (spec[i].lenght) {
                    case 'h': {
                        if (spec[i].specif == 'u') {
                            usd = va_arg(temp, unsigned int);
                            ld = (long int)usd;
                        } else {
                            sd = va_arg(temp, int);
                            ld = (long int)sd;
                        }
                        break;
                    }
                    case 'l': {
                        if (spec->specif == 'u') {
                            uld = (long int)va_arg(temp, unsigned long int);
                            ld = (long int)uld;
​
                        } else {
                            ld = va_arg(temp, long int);
                        }
                        break;
                    }
                    default: {
                        if (spec->specif == 'u') {
                            ud = (long int)va_arg(temp, unsigned int);
                            ld = (long int)ud;
​
                        } else {
                            d = (long int)va_arg(temp, int);
                            ld = (long int)d;
                        }
                        break;
                    }
                }
​
                d_to_str(res, &spec[i], ld);
            } else if (s21_strchr("feE", spec[i].specif) != s21_NULL) {
                long double d_arg;
                if (spec[i].lenght == 'L') {
                    d_arg = va_arg(temp, long double);
                } else {
                    d_arg = (long double)va_arg(temp, double);
                }
                float_e_to_str(&(spec[i]), d_arg, res, spec[i].specif);
            } else if (spec[i].specif == 'x' || spec[i].specif == 'X') {
                int_to_oct_hex_str(&(spec[i]), va_arg(temp, long long int), res, 16);
            } else if (spec[i].specif == 'o') {
                int_to_oct_hex_str(&(spec[i]), va_arg(temp, long long int), res, 8);
            } else if (spec[i].specif == 'g' || spec[i].specif == 'G') {
                g_to_str(&(spec[i]), res, temp);
            } else if (spec[i].specif == 'p') {
                pnt_to_str(&(spec[i]), va_arg(temp, long long int), res);
            } else if (spec[i].specif == '%') {
                s21_strcat(res, "%");
            } else if (spec[i].specif == 'n') {
                int *d = va_arg(temp, int *);
                *d = (int)s21_strlen(res);
            } else if (spec[i].specif == 's') {
                str_to_res_str(&(spec[i]), va_arg(temp, char *), res);
            }
            j += spec[i].size_format - 1;
            i++;
        } else {
            *(res + s21_strlen(res)) = *(format + j);
        }
    }
    va_end(temp);
    s21_size_t res_len = s21_strlen(res);
    s21_strcpy(str, res);
    free(res);
    *(str + res_len) = '\0';
    return (int)res_len;
}
​
void check_ch(parcer_t *spec, char *str, int ch) {
    char *temp_str = (char *)calloc(50, sizeof(char));
    char c = ch;
    if (spec->width != 0) {
        char empty = (s21_strchr(spec->flag, '0') == s21_NULL) ? ' ' : '0';
        if (s21_strchr(spec->flag, '-') != s21_NULL) {
            temp_str[0] = c;
            for (int i = 1; i < spec->width; i++)
                *(temp_str + i) = empty;
        } else {
            for (int i = 0; i < spec->width - 1; i++)
                *(temp_str + i) = empty;
            temp_str[spec->width - 1] = c;
        }
    } else {
        temp_str[0] = c;
    }
    s21_strcat(str, temp_str);
    free(temp_str);
}
​
int int_to_str(char *str, long int d) {
    long temp = d;
    int...