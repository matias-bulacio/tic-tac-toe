#ifndef _TERM_H
#define _TERM_H

#include <stddef.h>
#include <include/z-libs/zstr.h>


#define TERM_DEBUG_ESCAPE 0
#if TERM_DEBUG_ESCAPE
#define TERM_ESC "\\x1B"
#else
#define TERM_ESC "\x1B"
#endif

#define TERM_CSI TERM_ESC	"["
#define TERM_DCS TERM_ESC 	"P"
#define TERM_OSC TERM_ESC 	"]"

#define TERM_BELL		"\a"
#define TERM_BACKSPACE	"\b"
#define TERM_HTAB		"\t"
#define TERM_VTAB		"\v"
#define TERM_NEWLINE	"\n"
#define TERM_NEWPAGE	"\f"
#define TERM_CR			"\r"

#define TERM_DEL ((char)127)

#define TERM_STR_CLEAR_ALL TERM_CSI "2J"

zstr term_set_cursor(size_t line, size_t column);
zstr term_move_cursor(int line, int column);

#endif // _TERM_H
