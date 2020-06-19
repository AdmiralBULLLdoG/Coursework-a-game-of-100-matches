#include "game.h"
#include "mock_CIO.h"
#include "mock_CLI.h"
#include "unity.h"

void test_graphic_mode_int_1()
{
    char buf[255] = {0};

    cio_read_Expect(buf);
    cio_read_ReturnArrayThruPtr_buf("1", 1);

    CLI_start_Expect();
    start();
}

void test_graphic_mode_int_4()
{
    char buf[255] = {0};

    cio_read_Expect(buf);
    cio_read_ReturnArrayThruPtr_buf("4", 1);
    cio_read_ReturnArrayThruPtr_buf("3", 1);
    cio_read_ReturnArrayThruPtr_buf("2", 1);
    cio_read_ReturnArrayThruPtr_buf("1", 1);

    CLI_start_Expect();
    start();
}