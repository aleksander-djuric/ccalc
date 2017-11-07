/*
 * ccalc.c
 *
 * Description: Complex Calc Example
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <ctype.h>

#include "complex/complex.h"

void term_mode (int mode, struct termios *term)
{
    if (mode) {
	term->c_lflag |= ICANON;
	term->c_lflag |= ECHO;
	tcsetattr(fileno(stdin), TCSANOW, term);
    } else {
	term->c_lflag &= ~ICANON;
	term->c_lflag &= ~ECHO;
	tcsetattr(fileno(stdin), TCSANOW, term);
    }
}

void cfread(_complex *a, _complex *b, struct termios *term)
{
    term_mode(1, term);
    
    printf("Real A: ");
    scanf("%lf", &(a->re));
    printf("Img A: ");
    scanf("%lf", &(a->im));
    
    printf("Real B: ");
    scanf("%lf", &(b->re));
    printf("Img B: ");
    scanf("%lf", &(b->im));
    
    term_mode(0, term);
}

void cprintf(_complex a, char *s) {
    printf("%s = %lf + %lf i\n", s, a.re, a.im);
}


int main(int argc, char *argv[])
{
    struct termios term;
    _complex a, b, c;
    char cmd;

    printf("--------------- Complex Calc Example -----------------\n");
    printf("-- A (Add) * S (Sub) * M (Mul) * D (Div) * Q (Quit) --\n");
    printf("------------------------------------------------------\n");

    tcgetattr(fileno(stdin), &term);
    term_mode(0, &term);

    do {
	cmd = getchar();

	switch (cmd) {
	case 97:	// 'A'
	    printf("\nAdd two complex numbers.\n");
	    cfread(&a, &b, &term);
	    c = cadd(a, b);
	    cprintf(c, "Sum of two complex numbers");
	    break;
	case 115:	// 'S'
	    printf("\nSubtract two complex numbers.\n");
	    cfread(&a, &b, &term);
	    c = csub(a, b);
	    cprintf(c, "Difference of two complex numbers");
	    break;
	case 109:	// 'M'
	    printf("\nMultiply two complex numbers.\n");
	    cfread(&a, &b, &term);
	    c = cmul(a, b);
	    cprintf(c, "Multiplication of two complex numbers");
	    break;
	case 100:	// 'D'
	    printf("\nDivide two complex numbers.\n");
	    cfread(&a, &b, &term);
	    c = cdiv(a, b);
	    cprintf(c, "Division of two complex numbers");
	    break;
	case 113:	// 'Q'
	case 10:	// 'Enter'
	    break;
	default:
	    printf("Command: '%c' is not supported\n", cmd);
	}
    } while (cmd != 113); // 113 = 'Q'

    term_mode(1, &term);

    return 0;
}

