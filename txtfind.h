#ifndef TXTFIND_H
#define TXTFIND_H

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define LINE 256
#define WORD 30

int get_line(char s[]);

int get_word(char w[]);

int substring(char *str1, char *str2);

int similar(char *s, char *t, int n);

void print_lines(char *str);

void print_similar_words(char *str);

#endif