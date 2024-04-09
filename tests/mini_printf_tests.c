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

Test(my_printf, print_simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

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

/*Test(my_printf, print_complex, .init = redirect_all_std)
{
    int num = 12345.6789;

    my_printf("%+#12.3Le\n", num);
    cr_assert_stdout_eq_str("+1.235e+04");
}

Test(my_printf, print_long_num, .init = redirect_all_std)
{
    long int long_num = 123456789;

    my_printf("%ld\n", long_num);
    cr_assert_stdout_eq_str("123456789\n");
}

Test(my_printf, print_precision, .init = redirect_all_std)
{
    my_printf("%.3s\n", "abcdef");
    cr_assert_stdout_eq_str("abc\n");
}

Test(my_printf, print_float_precision, .init = redirect_all_std)
{
    my_printf(".1f\n", 12.3456);
    cr_assert_stdout_eq_str("12.3");
}
*/
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

Test(my_printf, print_nothing, .init = redirect_all_std)
{
    my_printf("");
    cr_assert_stdout_eq_str("");
}

Test(my_printf, print_neg, .init = redirect_all_std)
{
    int a = -3;

    my_printf("%i", a);
    cr_assert_stdout_eq_str("-3");
}

Test(my_printf, print_multiple_hexoct, .init = redirect_all_std)
{
    int i = 1256;

    my_printf("%X %x %o %u", i, i, i, i);
    cr_assert_stdout_eq_str("4E8 4e8 2350 1256");
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
Test(my_printf, print_multiple_hexoct_0, .init = redirect_all_std)
{
    int i = 0;

    my_printf("%X %x %o %u", i, i, i, i);
    cr_assert_stdout_eq_str("0 0 0 0");
}

Test(my_printf, change_int_str, .init = redirect_all_std)
{
    int i = 12345;

    my_printf("%i\n", i);
    cr_assert_stdout_eq_str("12345\n");
}

Test(my_printf, change_neg_int_str, .init = redirect_all_std)
{
    int i = -12345;

    my_printf("%i\n", i);
    cr_assert_stdout_eq_str("-12345\n");
}

Test(my_printf, print_float, .init = redirect_all_std)
{
    float i = 123.456;

    my_printf("%f\n", i);
    cr_assert_stdout_eq_str("123.456000");
}
