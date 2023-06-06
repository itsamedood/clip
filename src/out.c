#include <stdio.h>
#include <stdlib.h>
#include "out.h"

void clip_err(char *message, int code)
{
    printf("clip: %serror%s: %s", PRST_ERROR, PRST_RESET, message);
    exit(code);
}
