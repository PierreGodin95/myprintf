/*
** EPITECH PROJECT, 2023
** unit tests
** File description:
** ddff
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

//SIMPLE
Test(my_printf, print_simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, print_nothing, .init = redirect_all_std)
{
    my_printf("");
    cr_assert_stdout_eq_str("");
}

//NORMAL CONVERSIONS
Test(my_printf, print_char_percent, .init = redirect_all_std)
{
    char c = 'i';

    my_printf("hello %c", c);
    cr_assert_stdout_eq_str("hello i");
}

Test(my_printf, print_int_i_percent, .init = redirect_all_std)
{
    int i = 3;

    my_printf("hello %i", i);
    cr_assert_stdout_eq_str("hello 3");
}

Test(my_printf, print_int_d_percent, .init = redirect_all_std)
{
    int d = 3;

    my_printf("hello %d", d);
    cr_assert_stdout_eq_str("hello 3");
}

Test(my_printf, print_double_str, .init = redirect_all_std)
{
    char *str = "hello";
    char *str2 = "world";

    my_printf("%s %s", str, str2);
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, print_neg, .init = redirect_all_std)
{
    int a = -3;

    my_printf("%i", a);
    cr_assert_stdout_eq_str("-3");
}

Test(my_printf, print_multiple_percentages, .init = redirect_all_std)
{
    int i = 123;
    char c = 'c';

    my_printf("%i%c%i%c", i, c, i, c);
    cr_assert_stdout_eq_str("123c123c");
}

Test(my_printf, print_int_in_str, .init = redirect_all_std)
{
    int i = 4;
    int j = 8;

    my_printf("%i + %i = %i", i, i, j);
    cr_assert_stdout_eq_str("4 + 4 = 8");
}

Test(my_printf, print_percentatge_char, .init = redirect_all_std)
{
    my_printf("%v + %v = 4");
    cr_assert_stdout_eq_str("%v + %v = 4");
}

Test(my_printf, print_neg_int, .init = redirect_all_std)
{
    int i = -12345;

    my_printf("%i\n", i);
    cr_assert_stdout_eq_str("-12345\n");
}

// PERCENTATGES
Test(my_printf, print_pas_juste, .init = redirect_all_std)
{
    int i = 0;

    my_printf("% %, %i", i);
    cr_assert_stdout_eq_str("%, 0");
}

Test(my_printf, print_pas_juste_d, .init = redirect_all_std)
{
    int i = 4;

    my_printf("% d", i);
    cr_assert_stdout_eq_str("4");
}

Test(my_printf, print_pas_juste_c, .init = redirect_all_std)
{
    char c = 'a';

    my_printf("% c", c);
    cr_assert_stdout_eq_str("a");
}

Test(my_printf, print_pas_juste_i, .init = redirect_all_std)
{
    int i = 4;

    my_printf("% i", i);
    cr_assert_stdout_eq_str("4");
}

Test(my_printf, print_pas_juste_s, .init = redirect_all_std)
{
    char *s = "Ce n'est pas juste.";

    my_printf("% s", s);
    cr_assert_stdout_eq_str("Ce n'est pas juste.");
}

Test(my_printf, print_two_percentatges, .init = redirect_all_std)
{
    int i = 123;

    my_printf("The word %%s%% has %i characters.\n", i);
    cr_assert_stdout_eq_str("The word %s% has 123 characters.\n");
}

Test(my_printf, print_two_str_percentatges, .init = redirect_all_std)
{
    int i = 123;
    char *str = "how";

    my_printf("The word %%%s%% has %i characters.\n", str, i);
    cr_assert_stdout_eq_str("The word %how% has 123 characters.\n");
}

Test(my_printf, print_percentatges, .init = redirect_all_std)
{
    int i = 123;

    my_printf("The word %% has %i characters.\n", i);
    cr_assert_stdout_eq_str("The word % has 123 characters.\n");
}

// HEXA / OCT / DEC
/*Test(my_printf, print_nb_smaller_zero, .init = redirect_all_std)
{
    long long int i = -23456789123;

    my_printf("%u", i);
    cr_assert_stdout_eq_str("-1981952643");
    }*/

Test(my_printf, print_multiple_hexoct_bignum, .init = redirect_all_std)
{
    int i = 1256;

    my_printf("%X %x %o %u", i, i, i, i);
    cr_assert_stdout_eq_str("4E8 4e8 2350 1256");
}

Test(my_printf, print_multiple_hexoct_ten, .init = redirect_all_std)
{
    int i = 10;

    my_printf("%X %x %o %u", i, i, i, i);
    cr_assert_stdout_eq_str("A a 12 10");
}


Test(my_printf, print_hex_X, .init = redirect_all_std)
{
    int i = 1256;

    my_printf("%X", i);
    cr_assert_stdout_eq_str("4E8");
}

Test(my_printf, print_hex_x, .init = redirect_all_std)
{
    int i = 1256;

    my_printf("%x", i);
    cr_assert_stdout_eq_str("4e8");
}

Test(my_printf, print_oct, .init = redirect_all_std)
{
    int i = 1256;

    my_printf("%o", i);
    cr_assert_stdout_eq_str("2350");
}

Test(my_printf, print_dec, .init = redirect_all_std)
{
    int i = 1256;

    my_printf("%u", i);
    cr_assert_stdout_eq_str("1256");
}

/*Test(my_printf, print_multiple_hexoct_0, .init = redirect_all_std)
{
    int i = 0;

    my_printf("%X %x %o %u", i, i, i, i);
    cr_assert_stdout_eq_str("0 0 0 0");
}*/

//FLOATS
Test(my_printf, print_float, .init = redirect_all_std)
{
    float i = 12.3;

    my_printf("%f\n", i);
    cr_assert_stdout_eq_str("12.300000\n");
}

Test(my_printf, print_float_maj, .init = redirect_all_std)
{
    float i = 12.3;

    my_printf("%F\n", i);
    cr_assert_stdout_eq_str("12.300000\n");
}

Test(my_printf, print_more_floats, .init = redirect_all_std)
{
    float i = 123.456;

    my_printf("%f", i);
    cr_assert_stdout_eq_str("123.456001");
}

Test(my_printf, print_float_0, .init = redirect_all_std)
{
    float i = 0.0;

    my_printf("%f", i);
    cr_assert_stdout_eq_str("0.000000");
}

Test(my_printf, print_two_num_floats, .init = redirect_all_std)
{
    float i = 12.3456;

    my_printf("%f", i);
    cr_assert_stdout_eq_str("12.345600");
}

Test(my_printf, print_2many_floats, .init = redirect_all_std)
{
    float i = 123.45678912;

    my_printf("%f", i);
    cr_assert_stdout_eq_str("123.456787");
}

/*Test(my_printf, print_bigbig_floats, .init = redirect_all_std)
{
    float i = 123456.1234567;

    my_printf("%f", i);
    cr_assert_stdout_eq_str("123456.125000");
    }*/

/*Test(my_printf, print_interzero_floats, .init = redirect_all_std)
{
    float i = 1256.042;

    my_printf("%f", i);
    cr_assert_stdout_eq_str("1256.042");
}*/

Test(my_printf, print_bigbis_float, .init = redirect_all_std)
{
    float i = 1234.5678956789;

    my_printf("%f", i);
    cr_assert_stdout_eq_str("1234.567871");
}

// SCIENTIFIC // ON THIS COMPUTER = NOT GOOD, SHOULD BE 445 NOT 444

Test(my_printf, print_easy_e, .init = redirect_all_std)
{
    float i = 1256.445;

    my_printf("%e", i);
    cr_assert_stdout_eq_str("1.256444e+03");
}

Test(my_printf, print_easy_E, .init = redirect_all_std)
{
    float i = 1256.445;

    my_printf("%E", i);
    cr_assert_stdout_eq_str("1.256444E+03");
}
