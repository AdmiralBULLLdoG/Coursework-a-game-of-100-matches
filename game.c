#include "game.h"
#include "AI.h"
#include "CLI.h"
#include <stdio.h>
#include <stdlib.h>

void start()
{
    char graphic_mode[255];
    int graphic_mode_int = 0;
    printf("Выберите интерфейс, в котором желаете начать игру. Введите цифру "
           "от 1 до 2\n");
    printf("1. CLI(интерфейс командной строки)\n2. GUI(графический интерфейс "
           "пользователя)\n");
    fgets(graphic_mode, sizeof(graphic_mode), stdin);
    graphic_mode_int = atoi(graphic_mode);
    while (graphic_mode_int < 1 || graphic_mode_int > 2
           || graphic_mode_int == 0) {
        printf("\nНекорректный ввод, повторите попытку: ");
        fgets(graphic_mode, sizeof(graphic_mode), stdin);
        graphic_mode_int = atoi(graphic_mode);
    }
    if (graphic_mode_int == 1)
        CLI_start();
    // else
    // 	GUI_start();
}

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
        take = calculate_normal(code_units);
    } else {
        take = calculate_hard(code_units);
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