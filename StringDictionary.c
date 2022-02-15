#include "StringDictionary.h"
#include "string.h"
#include <stdlib.h>
#include <stdio.h>

int find_ind(struct Node *dict, int n, char *data)
{
    int low, high, middle;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (strcmp(data, dict[middle].key) < 0)
            high = middle - 1;
        else if (strcmp(data, dict[middle].key) > 0)
            low = middle + 1;
        else
            return middle;
    }
    return high+1;
}

void add_node(struct Node **dict, int *n, char *new_key, double data)
{
    int ind = find_ind(*dict, *n, new_key);
    (*n)++;
    *dict = (struct Node*) realloc(*dict, sizeof(struct Node)*(*n));
    for (int i = *n-1; i>ind; i--)
    {
        (*dict)[i]=(*dict)[i-1];
    }
    //printf("ind: %d\npastring: %s\nlength: %d\n", ind, new_key, *n);
    (*dict)[ind].key = (char*)malloc(sizeof(char)*(1+strlen(new_key)));
    strcpy((*dict)[ind].key, new_key);
    (*dict)[ind].data = data;
}

double get_data_by_key(struct Node *dict, int n, char *key)
{
    return dict[find_ind(dict, n, key)].data;
}

void set_data_by_key(struct Node *dict, int n, char *key, double data)
{
    dict[find_ind(dict, n, key)].data = data;
}

void inc_data_by_key(struct Node *dict, int n, char *key)
{
    dict[find_ind(dict, n, key)].data = dict[find_ind(dict, n, key)].data + 1;
}

bool has_key(struct Node *dict, int n, char *key)
{
    for (int i = 0; i<n; i++)
        if (strcmp(dict[i].key, key)==0) return true;
    return false;
}

void add_or_inc(struct Node **dict, int *n, char *new_key)
{
    if (has_key(*dict, *n, new_key))
        inc_data_by_key(*dict, *n, new_key);
    else
        add_node(dict, n, new_key, 1);
}

void add_or_set(struct Node **dict, int *n, char *new_key, double data)
{
    if (has_key(*dict, *n, new_key))
        set_data_by_key(*dict, *n, new_key, data);
    else
        add_node(dict, n, new_key, data);
}

void free_dict(struct Node **dict, int n)
{
    for (int i=0; i<n; i++)
    {
        free((*dict)[i].key);
    }
    free(*dict);
}
