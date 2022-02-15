#pragma once
#include <stdio.h>
#include "StringDictionary.h"

void print_dict(struct Node *dict, int n);
void print_strings(char **chrs, int n);
void print_all_data_to_file(char *file_name, int pc, int sc, int wc, double awcps, struct Node *char_freq, int l1, struct Node *word_freq, int l2);
void get_all_data_from_file(char *file_name, int pc, int sc, int wc, double awcps, struct Node *char_freq, int l1, struct Node *word_freq, int l2);
