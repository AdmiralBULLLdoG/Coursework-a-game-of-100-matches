#include "AI.h"
#include <stdlib.h>
#include <time.h>
int calculate_normal(int match)
{
    int take = 0;
    srand(time(NULL));
    if (match <= 10) {
        take = match;
    } else {
        take = rand() % 10 + 1;
    }
    return take;
}

int calculate_hard(int match)
{
    int take = 0;
    srand(time(NULL));
    if (match % 11 != 0) {
        take = match % 11;
    } else {
        take = rand() % 10 + 1;
    }
    return take;
}