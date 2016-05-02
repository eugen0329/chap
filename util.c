#include "util.h"

int readline(char* to, int max_size)
{
    if (!(fgets(to, max_size, stdin))) {
        return -1;
    } else {
        to[strlen(to) - 1] = '\0';
    }
}
