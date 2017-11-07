#include "complex.h"

_complex cadd(_complex a, _complex b) {
    _complex res;
    res.re = a.re + b.re;
    res.im = a.im + b.im;
    return res;
}

_complex csub(_complex a, _complex b) { 
    _complex res;
    res.re = a.re - b.re;
    res.im = a.im - b.im;
    return res;
}

_complex cmul(_complex a, _complex b) {
    _complex res;
    res.re = a.re * b.re - a.im * b.im;
    res.im = a.re * b.im + a.im * b.re;
    return res;
}

_complex cdiv(_complex a, _complex b) {
    _complex res;
    double ratio, denom;

    if (fabs(b.re) >= fabs(b.im)) {
	ratio = b.im / b.re;
	denom = b.re + ratio * b.im;
	res.re = (a.re + ratio * a.im) / denom;
	res.im = (a.im - ratio * a.re) / denom;
    } else {
	ratio = b.re / b.im;
	denom = b.im + ratio * b.re;
	res.re = (ratio * a.re + a.im) / denom;
	res.im = (ratio * a.im - a.re) / denom;
    }

    return res;
}
