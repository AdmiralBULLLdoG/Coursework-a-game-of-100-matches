#include "AI.h"
#include "unity.h"

void test_calculate_normal_for_last_10_matches()
{
    int result = calculate_normal(5);

    TEST_ASSERT_EQUAL_INT(5, result);
}

void test_calculate_normal_for_any_matches_more_then_10()
{
    int result = calculate_normal(15);

    TEST_ASSERT_LESS_THAN_INT(11, result);
    TEST_ASSERT_GREATER_THAN_INT(0, result);
}

void test_calculate_hard_for_matches_are_not_divided_by_11()
{
    int result = calculate_hard(15);

    TEST_ASSERT_EQUAL_INT(4, result);
}

void test_calculate_hard_for_matches_divided_by_11()
{
    int result = calculate_hard(22);

    TEST_ASSERT_LESS_THAN_INT(11, result);
    TEST_ASSERT_GREATER_THAN_INT(0, result);
}
