#include "spaghetti.h"

#include <wchar.h>
#include <locale.h>

static const wchar_t *orig = L";aABcCeEgHiIjKMNoOpPsSTxXyYZëËïÏöÖ";
static const wchar_t *repl = L";аАВϲСеЕɡНіΙϳКМΝоОрРѕЅТхХуΥΖёЁїЇӧӦ";

static size_t helper(FILE *in, FILE* out,
	const wchar_t *from, const wchar_t *to) {

	setlocale(LC_ALL,"");
	size_t len = wcslen(orig);
	size_t counter = 0;
	wint_t c;
	while ((c = fgetwc(in)) != WEOF) {
		for (int i = 0 ; i < len ; i++) {
			if (c == from[i]) {
				c = to[i];
				++counter;
			}
		}
		fputwc((wchar_t)c, out);
	}
	return counter;
}

size_t spaghetti_do(FILE *in, FILE *out) {
	return helper(in, out, orig, repl);
}

size_t spaghetti_undo(FILE *in, FILE *out) {
	return helper(in, out, repl, orig);
}

void spaghetti_print(FILE *out) {
	setlocale(LC_ALL,"");
	size_t len = wcslen(orig);
	for (size_t i = 0 ; i < len ; i++) {
		fwprintf(out, L"%lc (%02X): %lc (%02X)\n",
			orig[i], orig[i], repl[i], repl[i]);
	}
}
