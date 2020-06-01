#include "AI.h"
#include "game_common.h"
#include "mock_AI.h"
#include "unity.h"
#include <stdlib.h>

void test_step_endgame()
{
    CodeUnits* game = malloc(sizeof(CodeUnits));
    game->match = 1;
    game->current_player = 1;

    step(1, game);

    TEST_ASSERT_EQUAL_INT(0, game->match);
    TEST_ASSERT_EQUAL_INT(1, game->current_player);
}

void test_step_ai_normal()
{
    CodeUnits* game = malloc(sizeof(CodeUnits));
    game->match = 15;
    game->current_player = 1;
    game->mode = 2;

    calculate_normal_ExpectAndReturn(14, 5);

    step(1, game);

    TEST_ASSERT_EQUAL_INT(9, game->match);
    TEST_ASSERT_EQUAL_INT(1, game->current_player);
}

void test_step_ai_hard()
{
    CodeUnits* game = malloc(sizeof(CodeUnits));
    game->match = 15;
    game->current_player = 1;
    game->mode = 3;

    calculate_hard_ExpectAndReturn(14, 5);

    step(1, game);

    TEST_ASSERT_EQUAL_INT(9, game->match);
    TEST_ASSERT_EQUAL_INT(1, game->current_player);
}

void test_step_multiplayer()
{
    CodeUnits* game = malloc(sizeof(CodeUnits));
    game->mode = 1;
    game->current_player = 1;
    game->match = 15;

    step(1, game);

    TEST_ASSERT_EQUAL_INT(14, game->match);
    TEST_ASSERT_EQUAL_INT(1, game->mode);
    TEST_ASSERT_EQUAL_INT(0, game->current_player);
}

void test_is_end_match_0()
{
    CodeUnits* game = malloc(sizeof(CodeUnits));
    game->match = 0;

    int res = is_end(game);

    TEST_ASSERT_TRUE(res);
}

void test_is_end_match_not_0()
{
    CodeUnits* game = malloc(sizeof(CodeUnits));
    game->match = 34;

    int res = is_end(game);

    TEST_ASSERT_FALSE(res);
}

void test_creates_game()
{
    CodeUnits* res = creates_game(2, "Qwe", "Ewq");

    TEST_ASSERT_EQUAL_INT(100, res->match);
    TEST_ASSERT_EQUAL_INT(2, res->mode);
    TEST_ASSERT_EQUAL_INT(1, res->current_player);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("Qwe", res->player_one, 3);
    TEST_ASSERT_EQUAL_CHAR_ARRAY("Ewq", res->player_two, 3);
}

// void test_cio()
// {
//     char buf[255];

//     cio_read_Expect(buf);
//     cio_read_ReturnArrayThruPtr_buf("Qwe", 3);

//     cio_read(buf);

//     TEST_ASSERT_EQUAL_CHAR_ARRAY("Qwee", buf, 3);
// }