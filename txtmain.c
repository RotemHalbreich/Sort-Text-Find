#include <stdio.h>
#include <string.h>
#include "txtfind.h"

int main()
{
    char w[WORD];
    get_word(w);
    char c = getchar();

    switch (c)
    {
    case 'a':
        print_lines(w);
        break;

    case 'b':
        print_similar_words(w);
        break;

    default:
        printf("Invalid input!\n");
        break;
    }
    return 0;
}