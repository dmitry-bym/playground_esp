#ifndef LOG_H
#define LOG_H

#include <stdio.h>

// ==============
// CONFIG
// ==============
#define APP_LOG_LEVEL_NONE  0
#define APP_LOG_LEVEL_ERROR 1
#define APP_LOG_LEVEL_WARN  2
#define APP_LOG_LEVEL_INFO  3
#define APP_LOG_LEVEL_DEBUG 4

#ifdef _DEBUG
#define APP_LOG_LEVEL APP_LOG_LEVEL_DEBUG
#else
#define APP_LOG_LEVEL APP_LOG_LEVEL_INFO
#endif
// ==============
// ANSI Colors
// ==============
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// ==============
// Macros
// ==============
#if APP_LOG_LEVEL >= APP_LOG_LEVEL_ERROR
#define APP_LOG_ERROR(fmt, ...) \
    printf(ANSI_COLOR_RED "[APP][ERROR] " fmt ANSI_COLOR_RESET "\n", ##__VA_ARGS__)
#else
#define APP_LOG_ERROR(fmt, ...)
#endif

#if APP_LOG_LEVEL >= APP_LOG_LEVEL_WARN
#define APP_LOG_WARN(fmt, ...) \
    printf(ANSI_COLOR_YELLOW "[APP][WARN]  " fmt ANSI_COLOR_RESET "\n", ##__VA_ARGS__)
#else
#define APP_LOG_WARN(fmt, ...)
#endif

#if APP_LOG_LEVEL >= APP_LOG_LEVEL_INFO
#define APP_LOG_INFO(fmt, ...) \
    printf(ANSI_COLOR_GREEN "[APP][INFO]  " fmt ANSI_COLOR_RESET "\n", ##__VA_ARGS__)
#else
#define APP_LOG_INFO(fmt, ...)
#endif

#if APP_LOG_LEVEL >= APP_LOG_LEVEL_DEBUG
#define APP_LOG_DEBUG(fmt, ...) \
    printf(ANSI_COLOR_CYAN "[APP][DEBUG] " fmt ANSI_COLOR_RESET "\n", ##__VA_ARGS__)
#else
#define APP_LOG_DEBUG(fmt, ...)
#endif

#endif /* LOG_H */
