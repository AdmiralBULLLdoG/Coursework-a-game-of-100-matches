#include <stdio.h>

void cio_read(char* buf)
{
    fgets(buf, 255, stdin);
}