#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    int match = 100;
    char player_one[256];
    char player_two[256];
    char num[256];
    int take = 0;
    int count_1 = 0;
    char mode[256];
    int mode_int = 0;

    printf("1. Многопользовательский режим\n2. Игра против ИИ-обычный\n3. Игра "
           "против ИИ-сложный\n");
    printf("Выберите режим игры. Введите цифру от 1 до 3\n");
    fgets(mode, sizeof(mode), stdin);
    mode_int = atoi(mode);
    while (mode_int < 1 || mode_int > 3 || mode_int == 0) {
        printf("\nНекорректный ввод, повторите попытку: ");
        fgets(mode, sizeof(mode), stdin);
        mode_int = atoi(mode);
    }

    if (mode_int == 1) {
        printf("Вы выбрали многопользовательский режим.\n");
        printf("Введите имя первого игрока(не более 255 символов): ");
        fgets(player_one, sizeof(player_one), stdin);
        printf("\n");
        printf("Введите имя второго игрока(не более 255 символов): ");
        fgets(player_two, sizeof(player_two), stdin);
        printf("\nИгра началась\n");
        while (match > 0) {
            if (match < 10) {
                printf("Спичек в куче: %d, ход игрока: %sВведите сколько "
                       "спичек вы "
                       "хотите забрать от 1 до %d : ",
                       match,
                       player_one,
                       match);
                fgets(num, sizeof(num), stdin);
                take = atoi(num);
                while (take < 1 || take > 10 || take == 0 || take > match) {
                    printf("\nНекорректный ввод, повторите попытку: ");
                    fgets(num, sizeof(num), stdin);
                    take = atoi(num);
                }
            } else {
                printf("Спичек в куче: %d, ход игрока: %sВведите сколько "
                       "спичек вы "
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
                printf("\nСпичек в куче: %d, ход игрока: %sВведите сколько "
                       "спичек "
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
                printf("\nСпичек в куче: %d, ход игрока: %sВведите сколько "
                       "спичек "
                       "вы хотите забрать от 1 до 10 : ",
                       match,
                       player_two);
                fgets(num, sizeof(num), stdin);
                take = atoi(num);
                while (take < 1 || take > 10 || take == 0) {
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

    if (mode_int == 2) {
        printf("Вы выбрали игру против ИИ-обычный\n");
        srand(time(NULL));
        printf("Введите имя игрока(не более 255 символов): ");
        fgets(player_one, sizeof(player_one), stdin);
        printf("\nИгра началась\n");
        while (match > 0) {
            if (match < 10) {
                printf("Спичек в куче: %d, ход игрока: %sВведите сколько "
                       "спичек вы "
                       "хотите забрать от 1 до %d : ",
                       match,
                       player_one,
                       match);
                fgets(num, sizeof(num), stdin);
                take = atoi(num);
                while (take < 1 || take > 10 || take == 0 || take > match) {
                    printf("\nНекорректный ввод, повторите попытку: ");
                    fgets(num, sizeof(num), stdin);
                    take = atoi(num);
                }
            } else {
                printf("Спичек в куче: %d, ход игрока: %sВведите сколько "
                       "спичек вы "
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
                printf("\nСпичек в куче: %d, ход ИИ-обычный\nВведите сколько "
                       "спичек "
                       "вы хотите забрать от 1 до %d : ",
                       match,
                       match);
                take = rand() % match + 1;
                printf("%d\n", take);
            } else {
                printf("\nСпичек в куче: %d, ход игрока: ИИ-обычный\nВведите "
                       "сколько "
                       "спичек "
                       "вы хотите забрать от 1 до 10 : ",
                       match);
                take = rand() % 10 + 1;
                printf("%d\n", take);
            }
            count_1 = 0;
            match -= take;
        }
        if (count_1 == 1) {
            printf("Игра окончена. Победитель: %s\n", player_one);
            return 0;
        } else {
            printf("Игра окончена. Победитель: ИИ-обычный\n");
            return 0;
        }
    }

    if (mode_int == 3) {
        printf("Вы выбрали игру против ИИ-сложный\n");
        printf("Введите имя игрока(не более 255 символов): ");
        fgets(player_one, sizeof(player_one), stdin);
        printf("\nИгра началась\n");
        while (match > 0) {
            if (match <= 10) {
                printf("Спичек в куче: %d, ход игрока: ИИ-сложный\nВведите "
                       "сколько "
                       "спичек вы "
                       "хотите забрать от 1 до %d : ",
                       match,
                       match);
                take = match;
                printf("%d\n", take);
            } else {
                printf("Спичек в куче: %d, ход игрока: ИИ-сложный\nВведите "
                       "сколько "
                       "спичек вы "
                       "хотите забрать от 1 до 10 : ",
                       match);
                if (match == 100) {
                    take = 1;
                    printf("%d\n", take);
                } else {
                    take = 11 - take;
                    printf("%d\n", take);
                }
            }
            count_1 = 1;
            match -= take;
            if (match <= 0)
                break;
            if (match < 10) {
                printf("\nСпичек в куче: %d, ход игрока: %sВведите сколько "
                       "спичек вы "
                       "хотите забрать от 1 до %d : ",
                       match,
                       player_one,
                       match);
                fgets(num, sizeof(num), stdin);
                take = atoi(num);
                while (take < 1 || take > 10 || take == 0 || take > match) {
                    printf("\nНекорректный ввод, повторите попытку: ");
                    fgets(num, sizeof(num), stdin);
                    take = atoi(num);
                }
            } else {
                printf("\nСпичек в куче: %d, ход игрока: %sВведите сколько "
                       "спичек вы "
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
            count_1 = 0;
            match -= take;
        }
        if (count_1 == 1) {
            printf("Игра окончена. Победитель: ИИ-сложный\n");
            return 0;
        } else {
            printf("Игра окончена. Победитель: %s\n", player_one);
            return 0;
        }
    }
}
