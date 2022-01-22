#include "internals.h"

void vprintf_color(char* color, char* msg, va_list args)
{
    printf("%s", color);
    vprintf(msg, args);
    printf(ANSI_CODE_RESET);
}

void printf_bl(char* msg, ...)
{
    va_list args;
    va_start(args, msg);
    vprintf_color(ANSI_CODE_BG_BLUE, msg, args);
}

void printf_gr(char* msg, ...)
{
    va_list args;
    va_start(args, msg);
    vprintf_color(ANSI_CODE_BG_GREY, msg, args);
}
