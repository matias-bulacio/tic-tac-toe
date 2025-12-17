#include <include/z-libs/zstr.h>
#include <include/term/term.h>
#include <stdlib.h>

zstr term_set_cursor(size_t line, size_t column) {
	zstr ret = zstr_init();
	int written = zstr_fmt(&ret, "%s%zu;%zuH", TERM_CSI, line, column);

	if (written >= 0) return ret; // Sucess

	// Failure
	zstr_clear(&ret);
	zstr_free(&ret);
	return ret;
}

zstr term_move_cursor(int line, int column) {
	zstr ret = zstr_init();

	// Line
	int written = zstr_fmt(&ret, "%s%d%c", TERM_CSI, abs(line), line > 0 ? 'A': 'B');
	if (written < 0) goto fail;

	// Column
	written = zstr_fmt(&ret, "%s%d%c", TERM_CSI, abs(column), column > 0 ? 'C': 'D');
	if (written < 0) goto fail;

	return ret;
fail:
	zstr_clear(&ret);
	zstr_free(&ret);
	return ret;
}
