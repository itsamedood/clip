#ifndef OUT_H
#define OUT_H
/* Text styles */
#define STYLE_NORMAL    "\033[0m"
#define STYLE_BOLD      "\033[1m"
#define STYLE_LIGHT     "\033[2m"
#define STYLE_ITALIC    "\033[3m"
#define STYLE_UNDERLINE "\033[4m"
#define STYLE_BLINK     "\033[5m"

/* Text colors */
#define COLOR_BLACK  "\033[0;30m"
#define COLOR_RED    "\033[0;31m"
#define COLOR_GREEN  "\033[0;32m"
#define COLOR_YELLOW "\033[0;33m"
#define COLOR_BLUE   "\033[0;34m"
#define COLOR_PURPLE "\033[0;35m"
#define COLOR_CYAN   "\033[0;36m"
#define COLOR_WHITE  "\033[0;37m"

/* Background colors */
#define BG_BLACK  "\033[0;40m"
#define BG_RED    "\033[0;41m"
#define BG_GREEN  "\033[0;42m"
#define BG_YELLOW "\033[0;43m"
#define BG_BLUE   "\033[0;44m"
#define BG_PURPLE "\033[0;45m"
#define BG_CYAN   "\033[0;46m"
#define BG_WHITE  "\033[0;47m"

/* Special / presets */
#define PRST_SUCCESS "\033[1;32m"
#define PRST_WARNING "\033[1;33m"
#define PRST_ERROR   "\033[1;31m"
#define PRST_RESET   "\033[0;0;0m"

extern void clip_err(char *message, int code);
#endif
