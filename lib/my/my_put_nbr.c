/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** print a number
*/

void my_putchar(int c);

void my_put_nbr(int nb)
{
    int count = 1;
    int i = nb;
    int a = nb;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
        i = nb;
    }

    while (i > 10) {
        i = i / 10;
        count = count * 10;
    }
    while (count != 0) {
        a = nb / count;
        my_putchar(48 + a);
        nb = nb % count;
        count = count / 10;
    }
}
