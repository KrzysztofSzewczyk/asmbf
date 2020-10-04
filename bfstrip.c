
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "config.h"

void process(int c, int type) {
    long i;
    long count = c - type;

	while ((c = getchar()) != EOF) {
		if(!strchr("+-<>[].,", c))
            continue;

		if ((c != type + 1) && (c != type - 1)) {
			ungetc(c, stdin);
			break;
		}

		count += c - type;
	}

    if(c == EOF)
        return;

	if (count < 0)
        for (i = -count; i; i--)
            putchar(type - 1);
    
	if (count > 0)
        for (i = count; i; i--)
            putchar(type + 1);
}

int main(void) {
    int c;

	while ((c = getchar()) != EOF) {
		switch (c) {
			case '<': case '>': process(c, '='); break;
			case '+': case '-': process(c, ','); break;
			case '[': case ']': case ',': case '.': putchar(c); break;
		}
	}
}
