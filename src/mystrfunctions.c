#include "../include/mystrfunctions.h"

int mystrlen(const char* s) {
    int len = 0;
    while(s[len]) len++;
    return len;
}

int mystrcpy(char* dest, const char* src) {
    int i = 0;
    while((dest[i] = src[i])) i++;
    return i;
}

int mystrncpy(char* dest, const char* src, int n) {
    int i = 0;
    for(; i<n && src[i]; i++) dest[i] = src[i];
    for(; i<n; i++) dest[i] = '\0';
    return i;
}

int mystrcat(char* dest, const char* src) {
    int i = 0;
    while(dest[i]) i++;
    int j = 0;
    while((dest[i++] = src[j++]));
    return i-1;
}
