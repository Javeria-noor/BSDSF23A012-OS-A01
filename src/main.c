#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main(void) {
    printf("--- Testing String Functions ---\\n");
    char a[200] = "Hello";
    int len = mystrlen(a);
    printf("strlen(\\"%s\\") = %d\\n", a, len);

    mystrcpy(a, "Hello");
    mystrcat(a, ", world!");
    printf("After strcat: %s (len=%d)\\n", a, mystrlen(a));

    char b[20];
    mystrncpy(b, "abcdef", 4);
    printf("mystrncpy -> \\"%s\\"\\n", b);

    printf("\\n--- Testing File Functions ---\\n");
    FILE* fp = fopen("test_input.txt", "w+");
    if (!fp) {
        perror("fopen");
        return 1;
    }
    fprintf(fp, "Hello world\\nThis is a test\\nhello world\\n");
    fflush(fp);

    int lines, words, chars;
    if (wordCount(fp, &lines, &words, &chars) == 0) {
        printf("Lines=%d Words=%d Chars=%d\\n", lines, words, chars);
    } else {
        printf("wordCount failed\\n");
    }

    char** matches = NULL;
    int mcount = mygrep(fp, "hello", &matches);
    printf("mygrep found %d matches for \\"hello\\"\\n", mcount);
    for (int i=0;i<mcount;i++) {
        printf("MATCH %d: %s", i+1, matches[i]);
        free(matches[i]);
    }
    free(matches);

    fclose(fp);
    return 0;
}
