#ifndef PIN_COMMON_H
#define PIN_COMMON_H

#define printf_no printf

void vprintf_color(char* color, char* msg, va_list args);

void printf_bl(char* msg, ...);

void printf_gr(char* msg, ...);

#endif
