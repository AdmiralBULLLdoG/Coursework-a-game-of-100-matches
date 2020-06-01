#include "game.h"
#include "CIO.h"
#include "CLI.h"
#include <stdio.h>
#include <stdlib.h>

void start()
{
    char graphic_mode[255] = {0};
    int graphic_mode_int = 0;
    printf("Выберите интерфейс, в котором желаете начать игру. Введите цифру "
           "от 1 до 2\n");
    printf("1. CLI(интерфейс командной строки)\n2. GUI(графический интерфейс "
           "пользователя)\n");
    cio_read(graphic_mode);
    graphic_mode_int = atoi(graphic_mode);
    while (graphic_mode_int < 1 || graphic_mode_int > 2
           || graphic_mode_int == 0) {
        printf("\nНекорректный ввод, повторите попытку: ");
        cio_read(graphic_mode);
        graphic_mode_int = atoi(graphic_mode);
    }
    if (graphic_mode_int == 1)
        CLI_start();
    // else
    // 	GUI_start();
}