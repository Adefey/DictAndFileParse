#include "StudyTask.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void make_general_statistics(char *file_name, int *paragraph_count, int *sentence_count, int *word_count, double *avg_word_count_per_sentence)
{
    *paragraph_count=0;
    *sentence_count=0;
    *word_count=0;
    *avg_word_count_per_sentence=0;
    char *s = file_to_string(file_name);
    //find paragraph_count
    {
    char buf[strlen(s)+1];
    strcpy(buf, s);
    char *separators = "\n";
    char **res = separate_string(buf, paragraph_count, separators);
    destroy_strings(&res, *paragraph_count);
    }

    //find word_count
    {
    char buf[strlen(s)+1];
    strcpy(buf, s);
    char *separators = ",. /!?\n";
    char **res = separate_string(buf, word_count, separators);
    destroy_strings(&res, *paragraph_count);
    }

    //find sentence_count and avg_word_count_per_sentence
    {
    char buf[strlen(s)+1];
    strcpy(buf, s);
    char *separators = ".\n&?!";
    char **sentences = separate_string(buf, sentence_count, separators);
    for (int i=0; i<*sentence_count; i++)
    {
        int c = 0;
        char **buf_words = separate_string(sentences[i], &c, ",. /!?\n");
        *avg_word_count_per_sentence += c;
        destroy_strings(&buf_words, c);
    }
    *avg_word_count_per_sentence/=(*sentence_count);
    }
    free(s);
}

void make_char_frequency(char *file_name, struct Node **dict, int *count)
{
    *count = 0;
    char *s = file_to_string(file_name);
    for (int i=0; i<strlen(s); i++)
    {
        char buf[1];
        buf [0] = s[i];
        add_or_inc(dict, count, buf);
    }
    for (int i=0; i<*count; i++)
        (*dict)[i].data/=strlen(s);
}

void make_word_frequency(char *file_name, struct Node **dict, int *count)
{
    int wc = 0;
    char *s = file_to_string(file_name);

    char *separators = ",. /!?\n";
    char **res = separate_string(s, &wc, separators);


    for (int i=0; i<wc; i++)
    {
        add_or_inc(dict, count, res[i]);
    }

    destroy_strings(&res, wc);

    for (int i=0; i<*count; i++)
        (*dict)[i].data/=*count;
}
