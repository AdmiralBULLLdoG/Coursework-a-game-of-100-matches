#ifndef GAME_H
#define GAME_H

typedef struct {
    int match = 100;
    char player_one[];
    char player_two[];
    int current_player = 0;
    int mode = 0;
} CodeUnits;

int start();
void step(int take, CodeUnits* code_units);
void is_end(CodeUnits* code_units);

#endif