#pragma once

char* file_to_string(char *file_name);
char** separate_string(char *str, int *n, char *separators);
void destroy_strings(char ***str, int n);
