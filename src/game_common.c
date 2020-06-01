#include "game_common.h"
#include "AI.h"
#include <stdlib.h>

int is_end(CodeUnits* code_units)
{
    if (code_units->match == 0)
        return -1;
    return 0;
}

void step(int take, CodeUnits* code_units)
{
    code_units->match -= take;
    if (is_end(code_units)) {
        return;
    }
    code_units->current_player = 1 - code_units->current_player;
    if (code_units->mode == 1) {
        return;
    }
    if (code_units->mode == 2) {
        take = calculate_normal(code_units->match);
    } else {
        take = calculate_hard(code_units->match);
    }
    code_units->match -= take;
    if (is_end(code_units))
        return;
    code_units->current_player = 1 - code_units->current_player;
}

CodeUnits* creates_game(int mode, char* p1, char* p2)
{
    CodeUnits* game = malloc(sizeof(CodeUnits));
    game->mode = mode;
    game->player_one = p1;
    game->player_two = p2;
    game->match = 100;
    game->current_player = 1;
    return game;
}