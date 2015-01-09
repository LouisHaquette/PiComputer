#include <stdlib.h>

#include <gmp.h>

#include "pi.h"

int main()
{
    mpf_t * pi = malloc(sizeof(mpf_t));
    mpf_init(*pi);

    mpz_t digits;
    mpz_init_set_ui(digits, 14);

    piComputing(digits, pi);

    mpf_print(pi, ',');

    return 0;
}
