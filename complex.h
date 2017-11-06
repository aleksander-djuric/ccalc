#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <math.h>

typedef struct {
    double re;
    double im;
} _complex;

_complex cadd (_complex a, _complex b);
_complex csub (_complex a, _complex b);
_complex cmul (_complex a, _complex b);
_complex cdiv (_complex a, _complex b);

#endif // __COMPLEX_H__
