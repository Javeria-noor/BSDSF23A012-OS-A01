#include <stdio.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    printf("--- Testing String Functions ---\n");
    char a[50] = "Hello";
    char b[50] = "World";

    int len = mystrlen(a);
    printf("strlen(\"%s\") = %d\n", a, len);

    mystrcpy(a, b);
    printf("mystrcpy -> %s\n", a);

    mystrncpy(a, b, 3);
    printf("mystrncpy -> %s\n", a);

    mystrcat(a, b);
    printf("mystrcat -> %s\n", a);

    printf("\n--- Testing File Functions ---\n");
    FILE *fp = fopen("test.txt", "r");
    if(fp) {
        int lines, words, chars;
        wordCount(fp, &lines, &words, &chars);
        printf("Lines: %d Words: %d Chars: %d\n", lines, words, chars);
        fclose(fp);
    } else {
        printf("File not found.\n");
    }

    return 0;
}
