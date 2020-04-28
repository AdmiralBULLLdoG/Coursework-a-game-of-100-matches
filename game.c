int start()
{
    char graphic_mode[];
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
    CLT_start();
}

void step(int take, CodeUnits* code_units)
{
    code_units->match -= take;
    code_units->current_player = 1 - code_units->current_player;
    if (code_units->mode == 1 || is_end(code_units)) {
        return;
    }
    if (code_units->mode == 2) {
        take = light_calculate(CodeUnits * code_units);
    } else {
        take = hard_calculate(take, CodeUnits * code_units);
    }
    code_units->match -= take;
    code_units->current_player = 1 - code_units->current_player;
}

int is_end(CodeUnits* code_units)
{
	if(code_units->match = 0) 
		return -1;
	return 0;
}