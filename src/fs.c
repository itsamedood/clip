#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "fs.h"
#include "out.h"

int exists(char *path) { return access(path, F_OK) == 0; }

char *get_full_file_path(char *path)
{
    char *pwd = getenv("PWD");

    /* Construct file path. */
    const int FP_LEN = strlen(pwd) + strlen(path) + 2;
    char *filepath = malloc(FP_LEN * sizeof(char));

    snprintf(filepath, sizeof(filepath), "%s/%s", pwd, path);
    return filepath;
}


