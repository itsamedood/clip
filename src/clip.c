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
    // printf("Opening file: %s\n", file);

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

        printf("Files:");

        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
        {
            int valid = 0;

            /* Check file extension. */
            const char *extension = strrchr(entry->d_name, '.');
            if (!extension) continue;
            else
            {
                char *INVALID_EXTS[] = {
                    ".d",
                    ".o",
                    ".ko",
                    ".obj",
                    ".ilk",
                    ".map"
                    ".exp",
                    ".gch",
                    ".pch",
                    ".lib",
                    ".a",
                    ".la",
                    ".lo",
                    ".dll",
                    ".so",
                    ".dylib",
                    ".exe",
                    ".out",
                    ".app",
                    ".x86_64",
                    ".hex",
                    ".su",
                    ".idb",
                    ".pdb",
                    ".mod",
                    ".cmd",
                    ".DS_Store",
                    NULL
                };

                for (int i = 0; INVALID_EXTS[i] != NULL; i++)
                    if (strcmp(extension, INVALID_EXTS[i]) != 0) continue;
                    else
                    {
                        valid = 1;
                        break;
                    }
            }

            /* Check if entry is regular file. */
            if (entry->d_type == DT_REG && valid == 0)
            {
                printf(" %s ", entry->d_name);
                const int PATH_LEN = strlen(path) + strlen(entry->d_name) + 2;
                char pathtofile[PATH_LEN];
                snprintf(pathtofile, sizeof(pathtofile), "%s/%s", path, entry->d_name);

                lines += get_lines_in_file(pathtofile);
            }
        }
        printf("\n");

        closedir(dir);
    }

    return lines;
}
