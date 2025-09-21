#include "../include/myfilefunctions.h"
#include <stdlib.h>
#include <string.h>

int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if(!file) return -1;
    *lines = *words = *chars = 0;
    char c, last = ' ';
    while((c = fgetc(file)) != EOF) {
        (*chars)++;
        if(c == '\n') (*lines)++;
        if((c==' '||c=='\n'||c=='\t') && !(last==' '||last=='\n'||last=='\t')) (*words)++;
        last = c;
    }
    if(last != ' ' && last != '\n' && last != '\t') (*words)++;
    return 0;
}

int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if(!fp || !search_str) return -1;
    char line[1024];
    int count = 0, size = 10;
    *matches = malloc(sizeof(char*) * size);
    while(fgets(line, sizeof(line), fp)) {
        if(strstr(line, search_str)) {
            if(count >= size) {
                size *= 2;
                *matches = realloc(*matches, sizeof(char*) * size);
            }
            (*matches)[count] = strdup(line);
            count++;
        }
    }
    return count;
}
