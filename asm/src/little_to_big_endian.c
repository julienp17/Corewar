/*
** EPITECH PROJECT, 2020
** asm
** File description:
** Swap the endianess of an 32 bit integer from little to big endian
*/

int little_to_big_endian(int nb)
{
    nb = ((nb << 8) & 0xFF00FF00) | ((nb >> 8) & 0x00FF00FF);
    return (nb << 16) | ((nb >> 16) & 0xFFFF);
}