#ifndef SPAGHETTI_H
#define SPAGHETTI_H

#include <stdio.h>

size_t spaghetti_do(FILE *in, FILE *out);
size_t spaghetti_undo(FILE *in, FILE *out);
void spaghetti_print(FILE *out);

#endif

