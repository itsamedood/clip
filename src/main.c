#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clip.h"
#include "main.h"

void print_help()
{
    const int VTXT_LEN = strlen(VERSION) + 9;
    char vtxt[VTXT_LEN];
    snprintf(vtxt, sizeof(vtxt), "clip - v%s", VERSION);

    char *help[] = {
        vtxt,
        "Usage: clip <folder>",
        NULL
    };

    for (int i = 0; help[i] != NULL; i++) printf("%s\n", help[i]);
}

int main(int argc, char *argv[])
{
    if (argc < 2) print_help();
    else
    {
        int tlc = get_total_line_count(argv[1]);
        printf("Total lines in '%s': %i\n", argv[1], tlc);
    }
    return 0;
}
