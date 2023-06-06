#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "clip.h"
#include "fs.h"
#include "out.h"

static int get_lines_in_file(char *file)
{
    printf("Opening file: %s\n", file);

    FILE *srcfile = fopen(file, "r");
    if (!srcfile) clip_err("Failed to open file.", 2);

    int lines = 0;
    char line[500];
    while (fgets(line, sizeof(line), srcfile) != NULL) lines++;

    if (fclose(srcfile) != 0) clip_err("Failed to close file.", 2);
    return lines;
}

int get_total_line_count(char *path)
{
    int lines = 0;

    if (exists(path) == 0)
    {
        const int ERR_SIZE = strlen(path) + 14;
        char errmsg[ERR_SIZE];
        snprintf(errmsg, sizeof(errmsg), "'%s' not found.", path);

        clip_err(errmsg, 1);
    }
    else
    {
        DIR *dir = opendir(path);
        if (!dir) clip_err("Failed to open directory.", 3);

        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
        {
            // Check if entry is regular file.
            if (entry->d_type == DT_REG)
            {
                const int PATH_LEN = strlen(path) + strlen(entry->d_name) + 2;
                char pathtofile[PATH_LEN];
                snprintf(pathtofile, sizeof(pathtofile), "%s/%s", path, entry->d_name);

                lines += get_lines_in_file(pathtofile);
            }
        }

        closedir(dir);
    }

    return lines;
}
