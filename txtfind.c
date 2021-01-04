#include <stdio.h>
#include <string.h>
#include "txtfind.h"

// Get a line from the text by size
int get_line(char s[])
{
    int count = 0;
    char c;

    while (c != '\n' && count < LINE && c != EOF)
    {
        c = getchar();
        if (c != '\n' && count < LINE && c != EOF)
            s[count++] = c;
    }
    s[count] = '\0';

    if (c == EOF)
        return EOF;
    return count;
}

// Get the number of words
int get_word(char w[])
{
    int count = 0;
    char c;

    while (count < WORD && c != EOF && c != '\n' && c != '\t' && c != ' ')
    {
        c = getchar();
        if (count < WORD && c != EOF && c != '\n' && c != '\t' && c != ' ')
            w[count++] = c;
    }
    w[count] = '\0';

    if (c == EOF)
        return EOF;
    return count;
}

// Checks if str2 is a substring of str1
int substring(char *str1, char *str2)
{
    if (strstr(str1, str2) != NULL)
        return TRUE;
    else if (strlen(str2) > strlen(str1))
        return FALSE;
    else
        return FALSE;
}

// Checks for similarity between two strings
int similar(char *s, char *t, int n)
{
    int len_s = strlen(s), len_t = strlen(t);

    if (len_t < len_s)
    {
        int i = 0;
        int j = 0;

        while (j < len_t && i < len_s)
        {
            if (*(t + j) == *(s + i))
            {
                j++;
                i++;
            }
            else
            {
                i++;
                n--;
            }
        }
        if (i < len_s)
        {
            i++;
            n--;
        }
        if (n < 0)
            return FALSE;
        return TRUE;
    }
    else if (len_t == len_s)
    {
        for (int i = 0; i < len_s; i++)
        {
            if (*(t + i) != *(s + i))
                return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

// Prints the lines of the text
void print_lines(char *str)
{
    char arr[LINE];
    int l = get_line(arr);

    while (l != EOF)
    {
        l = get_line(arr);
        if (substring(arr, str))
            printf("%s\n", arr);
    }
}

// Prints similar words
void print_similar_words(char *str)
{
    char s[WORD];
    int l = get_word(s);

    while (l != EOF)
    {
        l = get_word(s);
        if (similar(s, str, 1))
            printf("%s\n", s);
    }
}