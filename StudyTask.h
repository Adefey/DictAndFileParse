#pragma once
#include "FileStringProcessing.h"
#include "StringDictionary.h"

void make_general_statistics(char *file_name, int *paragraph_count, int *sentence_count, int *word_count, double *avg_word_count_per_sentence);
void make_char_frequency(char *file_name, struct Node **dict, int *count);
void make_word_frequency(char *file_name, struct Node **dict, int *count);


