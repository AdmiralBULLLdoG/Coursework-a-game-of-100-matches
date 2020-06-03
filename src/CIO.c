#include <stdio.h>

void cio_read(char* buf)
{
    fgets(buf, sizeof(buf) * 255, stdin);
}