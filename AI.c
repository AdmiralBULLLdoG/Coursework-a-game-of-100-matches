#include "AI.h"
#include <stdlib.h>
#include <time.h>
int calculate_normal(CodeUnits* code_units)
{
    int take = 0;
    srand(time(NULL));
    if (code_units->match <= 10) {
        take = code_units->match;
    } else {
        take = rand() % 10 + 1;
    }
    return take;
}

int calculate_hard(CodeUnits* code_units)
{
    int take = 0;
    srand(time(NULL));
    if (code_units->match % 11 != 0) {
        take = code_units->match % 11;
    } else {
        take = rand() % 10 + 1;
    }
    return take;
}