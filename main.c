#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StringDictionary.h"
#include "FileStringProcessing.h"
#include "IO.h"
#include "StudyTask.h"

int show_menu_dialog();

int main(int argc,char **argv)
{
    while (true)
    {
        switch (show_menu_dialog())
        {
            case 1:
            {
                int pc=0, sc=0, wc=0;
                double awcps=0;
                printf("%s > ", "Enter the file name");
                char file_name[100];
                scanf("%s", file_name);
                make_general_statistics(file_name, &pc, &sc, &wc, &awcps);
                printf("There are %d paragraphs, %d sentences, %d words and %lf words per sentence\n", pc, sc, wc, awcps);
                break;
            }
            case 2:
            {
                int size = 0;
                struct Node *dict = (struct Node*)malloc(size);
                printf("%s > ", "Enter the file name");
                char file_name[100];
                scanf("%s", file_name);
                make_char_frequency(file_name, &dict, &size);
                print_dict(dict, size);
                free_dict(&dict, size);
                break;
            }
            case 3:
            {
                int size = 0;
                struct Node *dict = (struct Node*)malloc(size);
                printf("%s > ", "Enter the file name");
                char file_name[100];
                scanf("%s", file_name);
                make_word_frequency(file_name, &dict, &size);
                print_dict(dict, size);
                free_dict(&dict, size);
                break;
            }
            case 4:
            {
                printf("%s > ", "Enter the file name of initial file");
                char file_name1[100];
                scanf("%s", file_name1);
                printf("%s > ", "Enter the file name of result file");
                char file_name2[100];
                scanf("%s", file_name2);
                int pc=0, sc=0, wc=0, size1=0, size2=0;
                double awcps=0;
                struct Node *cf = (struct Node*)malloc(size1);
                struct Node *wf = (struct Node*)malloc(size2);
                make_general_statistics(file_name1, &pc, &sc, &wc, &awcps);
                make_char_frequency(file_name1, &cf, &size1);
                make_word_frequency(file_name1, &wf, &size2);
                print_all_data_to_file(file_name2, pc, sc, wc, awcps, cf, size1, wf, size2);
                break;
            }
            case 7:
            {
                return 0;
            }
        }
    }
    return 0;
}

int show_menu_dialog()
{
    printf("%s\n", "__!!MENU!!__");
    printf("%s\n", "1 - General statistics");
    printf("%s\n", "2 - Chars frequency");
    printf("%s\n", "3 - Words frequency");
    printf("%s\n", "4 - Write all to file");
    printf("%s\n", "5 - Update file");
    printf("%s\n", "6 - Find words");
    printf("%s\n", "7 - Exit");
    int res;
    scanf("%d", &res);
    return res;
}

/*
    Небольшой тест работоспособности (как же долго я писал этот словарь,
    наслаждайтесь теперь, он полностью автоматический, то есть
    вы можете писать туда значения по ключу, не задумываясь,
    есть такой ключ или нет. Если есть, то значение запишется
    в нужную ячейку, если нет, то сделается новая ячейка с вашим ключом
    и туда запишется значение. Разумеется, словарь сам динамический.
    Хоть щас в прод отправляй)
    int size = 0;
    struct Node *dict = (struct Node*)malloc(size);
    int word_count = 0;
    char *r = file_to_string("file.txt");

    char separators[10] = " .,?!\n\0";
    printf("Starting string from file: %s\n",r);
    char **words = separate_string(r, &word_count, separators);
    print_strings(words, word_count);
    destroy_strings(&words, &word_count);

    add_node(&dict, &size, "d", 0);
    add_node(&dict, &size, "a", 0);
    add_node(&dict, &size, "c", 0);
    add_node(&dict, &size, "b", 8);
    add_node(&dict, &size, "e", 0);
    add_node(&dict, &size, "f", 0);
    add_or_inc(&dict, &size, "c");
    add_or_inc(&dict, &size, "g");
    add_or_set(&dict, &size, "h", 5);
    add_or_set(&dict, &size, "a", 10);
    print_dict(dict, size);
    printf("%lf\n", get_data_by_key(dict, size, "c"));
    set_data_by_key(dict, size, "c", 14565);
    inc_data_by_key(dict, size, "c");
    printf("%lf\n", get_data_by_key(dict, size, "c"));
    printf("%d\n", has_key(dict, size, "e"));
    printf("%d\n", has_key(dict, size, "i"));

    free_dict(&dict, &size);
    free(r);
    */
