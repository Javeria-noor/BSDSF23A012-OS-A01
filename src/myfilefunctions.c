#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/myfilefunctions.h"

int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (!file || !lines || !words || !chars) return -1;
    rewind(file);
    *lines = *words = *chars = 0;
    int in_word = 0;
    int c;
    while ((c = fgetc(file)) != EOF) {
        (*chars)++;
        if (c == '\n') (*lines)++;
        if (isspace(c)) {
            in_word = 0;
        } else {
            if (!in_word) {
                (*words)++;
                in_word = 1;
            }
        }
    }
    return 0;
}

int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (!fp || !search_str || !matches) return -1;
    rewind(fp);
    size_t capacity = 8;
    size_t count = 0;
    char** arr = malloc(capacity * sizeof(char*));
    if (!arr) return -1;

    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, search_str) != NULL) {
            if (count == capacity) {
                capacity *= 2;
                char** tmp = realloc(arr, capacity * sizeof(char*));
                if (!tmp) {
                    for (size_t i=0;i<count;i++) free(arr[i]);
                    free(arr);
                    free(line);
                    return -1;
                }
                arr = tmp;
            }
            arr[count++] = strdup(line);
        }
    }
    free(line);
    if (count == 0) {
        free(arr);
        *matches = NULL;
        return 0;
    }
    *matches = arr;
    return (int)count;
}
