#ifndef UTILS_H
#define UTILS_H

#if _win32 || _win64
#define CLEAR_SCREEN() system("cls")
#else
#define CLEAR_SCREEN() system("clear")
#endif

#endif