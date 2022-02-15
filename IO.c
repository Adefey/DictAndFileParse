#include "IO.h"
#include "StringDictionary.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_dict(struct Node *dict, int n)
{
    for (int i=0; i<n; i++)
        {
            printf("%s : %lf\n", dict[i].key, dict[i].data);
        }
}

void print_strings(char **chrs, int n)
{
    for (int i=0; i<n; i++)
        printf("%d : %s\n",i, chrs[i]);
}

void print_all_data_to_file(char *file_name, int pc, int sc, int wc, double awcps, struct Node *char_freq, int l1, struct Node *word_freq, int l2)
{
    FILE *f;
    f = fopen(file_name, "w");
    fprintf(f, "Paragraphs: %d\nSentences: %d\nWords: %d\nAverage words per sentence: %lf\n", pc, sc, wc, awcps);
    fprintf(f, "%s\n", "Char analysis");
    for (int i=0; i<l1; i++)
    {
        fprintf(f, "%s : %lf\n", char_freq[i].key, char_freq[i].data);
    }
    fprintf(f, "%s\n", "Words analysis");
    for (int i=0; i<l2; i++)
    {
        fprintf(f, "%s : %lf\n", word_freq[i].key, word_freq[i].data);
    }
    fclose(f);
}
