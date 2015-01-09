#ifndef PI_H_INCLUDED
#define PI_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include <gmp.h>

mpz_t * z_fact(mpz_t number);

mpz_t * z_pow_i(mpz_t number, unsigned int power);
mpz_t * z_si_pow(long int number, mpz_t power);

void piComputing(mpz_t nbr_decemalDigits, mpf_t * pi);

void mpf_print(mpf_t * f, char separator);

#endif // PI_H_INCLUDED
