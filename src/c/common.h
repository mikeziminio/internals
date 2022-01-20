#ifndef PIN_COMMON_H
#define PIN_COMMON_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define printf_no printf

void vprintf_color(char* color, char* msg, va_list args);

void printf_bl(char* msg, ...);

void printf_gr(char* msg, ...);

#endif
