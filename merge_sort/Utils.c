#include "Utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const void *NUL = 0;

/**
 * 拼接字符串
 */
char *cat(char *s1, char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); //+1 for the zero-terminator
    //in real code you would check for errors in malloc here
    if (result == NULL)
        exit(1);

    strcpy(result, s1);
    strcat(result, s2);

    return result;
}

/**
 * 错误提示
 */
void Error(char *msg)
{
    fprintf(stderr, "Tatal Error: %s\n\t%s\n", msg, strerror(errno));
}

/**
 * 错误提示
 */
void FatalError(char *msg)
{
    fprintf(stderr, "Tatal Error: %s\n\t%s\n", msg, strerror(errno));
}
