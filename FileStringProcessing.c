#include "FileStringProcessing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* file_to_string(char *file_name)
{
    FILE *f;
    f = fopen(file_name, "r");
    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    char *res = (char*)malloc(size/sizeof(char));
    char *buf = (char*)malloc(size/sizeof(char));
    rewind(f);
    strcpy(res, "");
    while (fgets(buf, size/sizeof(char), f) != NULL)
    {
        strcat(res, buf);
    }
    fclose(f);
    free(buf);
    res[strlen(res)-1]='\0';
    return res;
}

char** separate_string(char *str, int *n, char *separators)
{
    *n = 0;
    char **res = (char**)malloc((*n)*sizeof(char*));
    char *buf;
    buf = strtok(str, separators);
    while (buf != NULL)
    {
        (*n)++;
        res = (char**)realloc(res, (*n) * sizeof(char*));
        res[(*n)-1] = (char*)malloc((1+strlen(buf))*sizeof(char));
        strcpy(res[(*n)-1], buf);
        buf = strtok(NULL, separators);
    }
    return res;
}

void destroy_strings(char ***str, int n)
{
    for (int i=0; i<n; i++)
        free((*str)[i]);
    free(*str);
}
