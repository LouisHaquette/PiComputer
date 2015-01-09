#include "pi.h"

mpz_t * z_fact(mpz_t number)
{
    mpz_t * result = malloc(sizeof(mpz_t));
    mpz_init_set_ui(*result, 1);

    mpz_t i;
    mpz_init_set_ui(i, 1);

    while (mpz_cmp(i, number) <= 0) {
        mpz_mul(*result, *result, i);
        mpz_add_ui(i, i, 1);
    }

    return result;
}

mpz_t * z_pow_i(mpz_t number, unsigned int power)
{
    mpz_t * result = malloc(sizeof(mpz_t));
    mpz_init_set_ui(*result, 1);

    unsigned int i = 1;

    if (!power) {

        while (i <= power) {
            mpz_mul(*result, number, number);
            i++;
        }
    }

    return result;
}
mpz_t * z_si_pow(long int number, mpz_t power)
{
    mpz_t * result = malloc(sizeof(mpz_t));
    mpz_init_set_ui(*result, 1);
    mpz_t sqr_result;
    mpz_init(sqr_result);
    mpz_t i;
    mpz_init_set_ui(i, 1);
    if (mpz_cmp_ui(power, 1) > 0) {
        return result;
    }


    while (mpz_cmp(i, power) <= 0 && !(mpz_cmp_ui(power, 1) > 0)) {
        mpz_set_ui(sqr_result, number * number);
        mpz_mul(*result, *result, sqr_result);
        mpz_add_ui(i, i, 1);
    }

    return result;
}

void piComputing(mpz_t nbr_decemalDigits, mpf_t * pi)
{
    mpz_div_ui(nbr_decemalDigits, nbr_decemalDigits, 14);
    mpz_add_ui(nbr_decemalDigits, nbr_decemalDigits, 1);

    mpf_t a, b, t;
    mpf_init_set_ui(a, 426880);
    mpf_inits(t, b, NULL);

    mpf_sqrt_ui(b, 10005);
    mpf_mul(t, b, a);

    mpz_t k;
    mpz_init(k);

    mpz_t resultA, resultB, resultC, resultA2,
    resultB2, result1, result2;

    mpf_t result, result1F, result2F;

    while (mpz_cmp(k, nbr_decemalDigits) < 0) {

        mpz_inits(resultA, resultB, resultC, resultA2,
        resultB2, result1, result2, NULL);

        mpf_inits(result, result1F, result2F);

        mpz_mul_ui(resultA, k, 6);
        mpz_mul_ui(resultB, k, 545140134);
        mpz_add_ui(resultC, resultB, 13591409);

        mpz_mul(result1, *(z_fact(resultA)), resultC);

        mpz_mul_ui(resultA2, k, 3);

        mpz_mul(resultB2, *(z_fact(resultA2)),
                *(z_pow_i(*(z_fact(k)), 3)));

        mpz_mul(result2, resultB2, *(z_si_pow(-640320, resultA2)));

        mpf_set_str(result1F, mpz_get_str(NULL, 10, result1), 10);
        mpf_set_str(result2F, mpz_get_str(NULL, 10, result2), 10);

        mpf_div(result, result1F, result2F);

        mpf_add(*pi, *pi, result);

        mpz_add_ui(k, k, 1);
    }

    mpf_div(*pi, t, *pi);

    return;
}

void mpf_print(mpf_t * f, char separator)
{
    mp_exp_t exp;
    char *f_str = mpf_get_str(NULL, &exp, 10, 100, *f);
    int i;

    if (!exp) {
        printf("0");
    }

    for (i = 0; i < exp; i++) {
        printf("%c", f_str[i]);
    }

  printf("%c%s\n", separator, f_str + exp);

  free(f_str);

  return;
}
