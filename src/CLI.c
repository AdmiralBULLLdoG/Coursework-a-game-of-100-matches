#include "CLI.h"
#include "CIO.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void winner(CodeUnits* code_units)
{
    if (code_units->current_player == 1) {
        printf("Игра окончена. Победитель: %s\n", code_units->player_one);
        return;
    } else {
        printf("Игра окончена. Победитель: %s\n", code_units->player_two);
        return;
    }
}

int take(CodeUnits* code_units)
{
    int take = 0;
    char num[255] = {0};
    int max = code_units->match > 10 ? 10 : code_units->match;
    if (code_units->current_player == 1) {
        printf("Ход игрока: %s\n", code_units->player_one);
    } else {
        printf("Ход игрока: %s\n", code_units->player_two);
    }
    printf("Спичек в куче: %d, Введите сколько спичек вы хотите забрать от "
           "1 до %d: ",
           code_units->match,
           max);
    cio_read(num);
    take = atoi(num);
    while (take < 1 || take == 0 || take > max) {
        printf("\nНекорректный ввод, повторите попытку: ");
        cio_read(num);
        take = atoi(num);
    }
    return take;
}

void CLI_start()
{
    int mode = 0;
    char mode_char[255] = {0};
    char player_one[255] = {0};
    char player_two[255] = {0};
    char bot_name_ez[] = "ИИ-обычный";
    char bot_name_hard[] = "ИИ-сложный";
    printf("Выберите режим игры. Введите цифру от 1 до 3\n");
    printf("1. Многопользовательский режим\n2. Игра против ИИ-обычный\n3. "
           "Игра "
           "против ИИ-сложный\n");
    cio_read(mode_char);
    mode = atoi(mode_char);
    while (mode < 1 || mode > 3 || mode == 0) {
        printf("\nНекорректный ввод, повторите попытку: ");
        cio_read(mode_char);
        mode = atoi(mode_char);
    }
    if (mode == 1) {
        printf("Вы выбрали многопользовательский режим.\n");
        printf("Введите имя первого игрока(не более 254 символов): ");
        cio_read(player_one);
        printf("\nВведите имя второго игрока(не более 254 символов): ");
        cio_read(player_two);
    }
    if (mode == 2) {
        printf("Вы выбрали игру против ИИ-обычный\n");
        printf("Введите имя игрока(не более 254 символов): ");
        cio_read(player_one);
        strcpy(player_two, bot_name_ez);
    }
    if (mode == 3) {
        printf("Вы выбрали игру против ИИ-сложный\n");
        printf("Введите имя игрока(не более 254 символов): ");
        cio_read(player_one);
        strcpy(player_two, bot_name_hard);
    }
    printf("\nИгра началась\n");
    CodeUnits* game = creates_game(mode, player_one, player_two);
    while (!is_end(game)) {
        int t = take(game);
        step(t, game);
    }
    winner(game);
}