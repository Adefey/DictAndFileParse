#pragma once
#include <stdbool.h>

 struct Node
 {
     char *key;
     double data;
 };

int find_ind(struct Node *dict, int n, char *data);
void add_node(struct Node **dict, int *n, char *new_key, double data);
double get_data_by_key(struct Node *dict, int n, char *key);
void set_data_by_key(struct Node *dict, int n, char *key, double data);
void inc_data_by_key(struct Node *dict, int n, char *key);
bool has_key(struct Node *dict, int n, char *key);
void add_or_inc(struct Node **dict, int *n, char *new_key);
void add_or_set(struct Node **dict, int *n, char *new_key, double data);
void free_dict(struct Node **dict, int n);
