#pragma once
// Coded by DosX
// GitHub: https://github.com/DosX-dev
// Windows console colors module for TinySnake

// Foreground text colors
#define FOREGROUND_BLACK 0x00
#define FOREGROUND_BLUE 0x01
#define FOREGROUND_GREEN 0x02
#define FOREGROUND_RED 0x04
#define FOREGROUND_GRAY 0x08
#define FOREGROUND_CYAN (FOREGROUND_GREEN | FOREGROUND_BLUE)
#define FOREGROUND_MAGENTA (FOREGROUND_RED | FOREGROUND_BLUE)
#define FOREGROUND_YELLOW (FOREGROUND_RED | FOREGROUND_GREEN)
#define FOREGROUND_WHITE (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)
#define FOREGROUND_LIGHT_BLUE (FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define FOREGROUND_LIGHT_GREEN (FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define FOREGROUND_LIGHT_CYAN (FOREGROUND_CYAN | FOREGROUND_INTENSITY)
#define FOREGROUND_LIGHT_RED (FOREGROUND_RED | FOREGROUND_INTENSITY)
#define FOREGROUND_LIGHT_MAGENTA (FOREGROUND_MAGENTA | FOREGROUND_INTENSITY)
#define FOREGROUND_LIGHT_YELLOW (FOREGROUND_YELLOW | FOREGROUND_INTENSITY)
#define FOREGROUND_BRIGHT_WHITE (FOREGROUND_WHITE | FOREGROUND_INTENSITY)

// Background colors
#define BACKGROUND_BLACK 0x00
#define BACKGROUND_BLUE 0x10
#define BACKGROUND_GREEN 0x20
#define BACKGROUND_RED 0x40
#define BACKGROUND_GRAY 0x80
#define BACKGROUND_CYAN (BACKGROUND_GREEN | BACKGROUND_BLUE)
#define BACKGROUND_MAGENTA (BACKGROUND_RED | BACKGROUND_BLUE)
#define BACKGROUND_YELLOW (BACKGROUND_RED | BACKGROUND_GREEN)
#define BACKGROUND_WHITE (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE)
#define BACKGROUND_LIGHT_BLUE (BACKGROUND_BLUE | BACKGROUND_INTENSITY)
#define BACKGROUND_LIGHT_GREEN (BACKGROUND_GREEN | BACKGROUND_INTENSITY)
#define BACKGROUND_LIGHT_CYAN (BACKGROUND_CYAN | BACKGROUND_INTENSITY)
#define BACKGROUND_LIGHT_RED (BACKGROUND_RED | BACKGROUND_INTENSITY)
#define BACKGROUND_LIGHT_MAGENTA (BACKGROUND_MAGENTA | BACKGROUND_INTENSITY)
#define BACKGROUND_LIGHT_YELLOW (BACKGROUND_YELLOW | BACKGROUND_INTENSITY)
#define BACKGROUND_BRIGHT_WHITE (BACKGROUND_WHITE | BACKGROUND_INTENSITY)