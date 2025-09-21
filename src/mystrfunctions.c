#include <stddef.h>
#include "../include/mystrfunctions.h"

int mystrlen(const char* s) {
    const char* p = s;
    if (!s) return 0;
    while (*p) ++p;
    return (int)(p - s);
}

int mystrcpy(char* dest, const char* src) {
    char* d = dest;
    const char* s = src;
    if (!dest || !src) return -1;
    while ((*d++ = *s++));
    return mystrlen(dest);
}

int mystrncpy(char* dest, const char* src, int n) {
    if (!dest || !src || n <= 0) return -1;
    int i = 0;
    while (i < n-1 && src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return i;
}

int mystrcat(char* dest, const char* src) {
    if (!dest || !src) return -1;
    int len = mystrlen(dest);
    int i = 0;
    while (src[i]) {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return len + i;
}
