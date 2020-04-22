#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int match = 100;
    printf("Введите имя первого игрока(не более 255 символов): ");
    char player_one[256];
    fgets(player_one, sizeof(player_one), stdin);
    printf("\n");
    printf("Введите имя второго игрока(не более 255 символов): ");
    char player_two[256];
    fgets(player_two, sizeof(player_two), stdin);
    printf("\nИгра началась\n");
    char num[256];
    int take = 0;
    int count_1 = 0;
    while (match > 0) {
        if (match < 10) {
            printf("Спичек в куче: %d, ход игрока: %sВведите сколько спичек вы "
                   "хотите забрать от 1 до %d : ",
                   match,
                   player_one,
                   match);
            fgets(num, sizeof(num), stdin);
            take = atoi(num);
            while (take < 1 || take > 10 || take == 0) {
                printf("\nНекорректный ввод, повторите попытку: ");
                fgets(num, sizeof(num), stdin);
                take = atoi(num);
            }
        } else {
            printf("Спичек в куче: %d, ход игрока: %sВведите сколько спичек вы "
                   "хотите забрать от 1 до 10 : ",
                   match,
                   player_one);
            fgets(num, sizeof(num), stdin);
            take = atoi(num);
            while (take < 1 || take > 10 || take == 0) {
                printf("\nНекорректный ввод, повторите попытку: ");
                fgets(num, sizeof(num), stdin);
                take = atoi(num);
            }
        }
        count_1 = 1;
        match -= take;
        if (match <= 0)
            break;
        if (match < 10) {
            printf("\nСпичек в куче: %d, ход игрока: %sВведите сколько спичек "
                   "вы хотите забрать от 1 до %d : ",
                   match,
                   player_two,
                   match);
            fgets(num, sizeof(num), stdin);
            take = atoi(num);
            while (take < 1 || take > 10 || take == 0 || take > match) {
                printf("\nНекорректный ввод, повторите попытку: ");
                fgets(num, sizeof(num), stdin);
                take = atoi(num);
            }
        } else {
            printf("\nСпичек в куче: %d, ход игрока: %sВведите сколько спичек "
                   "вы хотите забрать от 1 до 10 : ",
                   match,
                   player_two);
            fgets(num, sizeof(num), stdin);
            take = atoi(num);
            while (take < 1 || take > 10 || take == 0 || take > match) {
                printf("\nНекорректный ввод, повторите попытку: ");
                fgets(num, sizeof(num), stdin);
                take = atoi(num);
            }
        }
        count_1 = 0;
        match -= take;
    }
    if (count_1 == 1) {
        printf("Игра окончена. Победитель: %s\n", player_one);
        return 0;
    } else {
        printf("Игра окончена. Победитель: %s\n", player_two);
        return 0;
    }
}