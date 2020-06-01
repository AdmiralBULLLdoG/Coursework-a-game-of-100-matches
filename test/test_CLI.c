#include "CLI.h"
#include "mock_CIO.h"
#include "mock_game_common.h"
#include "unity.h"
#include <stdlib.h>

void test_take_match_less10()
{
    CodeUnits* game = malloc(sizeof(CodeUnits));
    game->match = 5;
    char p1[255] = "Qwe";
    char p2[255] = "Ewq";
    game->player_one = p1;
    game->player_two = p2;
    game->current_player = 1;
    char take_char[255] = {0};

    cio_read_Expect(take_char);
    cio_read_ReturnArrayThruPtr_buf("6", 1);
    cio_read_ReturnArrayThruPtr_buf("5", 1);

    int res = take(game);

    TEST_ASSERT_EQUAL_INT(5, res);
}

void test_take_match_more_10()
{
    CodeUnits* game = malloc(sizeof(CodeUnits));
    game->match = 15;
    char p1[255] = "Qwe";
    char p2[255] = "Ewq";
    game->player_one = p1;
    game->player_two = p2;
    game->current_player = 1;
    char take_char[255] = {0};

    cio_read_Expect(take_char);
    cio_read_ReturnArrayThruPtr_buf("11", 1);
    cio_read_ReturnArrayThruPtr_buf("2", 1);

    int res = take(game);

    TEST_ASSERT_EQUAL_INT(2, res);
}

void test_CLI_start_mode_1()
{
    char mode[255] = {0};
    cio_read_Expect(mode);
    cio_read_ReturnArrayThruPtr_buf("1", 1);
    char p1[255] = {0};
    cio_read_Expect(p1);
    cio_read_ReturnArrayThruPtr_buf("Qwe", 3);
    char p2[255] = {0};
    cio_read_Expect(p2);
    cio_read_ReturnArrayThruPtr_buf("Ewq", 3);

    CodeUnits* game = malloc(sizeof(CodeUnits));

    creates_game_ExpectAndReturn(1, "Qwe", "Ewq", game);

    is_end_ExpectAndReturn(game, -1);
    CLI_start();
}

void test_CLI_start_mode_2()
{
    char mode[255] = {0};
    cio_read_Expect(mode);
    cio_read_ReturnArrayThruPtr_buf("2", 1);
    char p1[255] = {0};
    cio_read_Expect(p1);
    cio_read_ReturnArrayThruPtr_buf("Qwe", 3);

    CodeUnits* game = malloc(sizeof(CodeUnits));

    creates_game_ExpectAndReturn(2, "Qwe", "ИИ-обычный", game);

    is_end_ExpectAndReturn(game, -1);
    CLI_start();
}

void test_CLI_start_mode_3()
{
    char mode[255] = {0};
    cio_read_Expect(mode);
    cio_read_ReturnArrayThruPtr_buf("3", 1);
    char p1[255] = {0};
    cio_read_Expect(p1);
    cio_read_ReturnArrayThruPtr_buf("Qwe", 3);

    CodeUnits* game = malloc(sizeof(CodeUnits));

    creates_game_ExpectAndReturn(3, "Qwe", "ИИ-сложный", game);

    is_end_ExpectAndReturn(game, -1);
    CLI_start();
}