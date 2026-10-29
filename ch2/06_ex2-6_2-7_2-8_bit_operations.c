/*
 * ch2 / 2.9 Bitwise Operators
 * getbits(x, p, n): the n-bit field of x that begins at position p (from K&R).
 * Ex 2-6: setbits(x, p, n, y) returns x with the n bits that begin at
 *         position p set to the rightmost n bits of y.
 * Ex 2-7: invert(x, p, n) returns x with the n bits that begin at
 *         position p inverted (1 -> 0, 0 -> 1).
 * Ex 2-8: rightrot(x, n) returns x rotated to the right by n bit positions.
 * Bit positions are counted from 0 at the right; p is the leftmost bit
 * of the field, so the field is bits p..p-n+1.
 */
#include <stdio.h>
#include <limits.h>

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0u << n);
}

/* setbits: x with bits p..p-n+1 replaced by the rightmost n bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned mask = ~(~0u << n) << (p + 1 - n);   /* 1s on the field */
    return (x & ~mask) | ((y << (p + 1 - n)) & mask);
}

/* invert: x with bits p..p-n+1 flipped (XOR with 1 inverts a bit) */
unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~(~0u << n) << (p + 1 - n));
}

/* rightrot: rotate x right by n bits; bits shifted out re-enter on the left */
unsigned rightrot(unsigned x, int n)
{
    int wordlen = (int)(sizeof(x) * CHAR_BIT);

    n = n % wordlen;
    if (n == 0)
        return x;
    return (x >> n) | (x << (wordlen - n));
}

/* printbin: print the low 8 bits of x in binary */
void printbin(unsigned x)
{
    int i;

    for (i = 7; i >= 0; i--)
        putchar((x >> i) & 1 ? '1' : '0');
}

int main(void)
{
    unsigned x = 0xAA;   /* 1010 1010 */
    unsigned y = 0x07;   /* 0000 0111 */

    printf("x                 = "); printbin(x); printf("\n");
    printf("getbits(x,4,3)    = "); printbin(getbits(x, 4, 3)); printf("\n");
    printf("setbits(x,4,3,y)  = "); printbin(setbits(x, 4, 3, y)); printf("\n");
    printf("invert(x,4,3)     = "); printbin(invert(x, 4, 3)); printf("\n");
    printf("rightrot(0x%X, 4) = 0x%X\n", 0x12345678u, rightrot(0x12345678u, 4));
    return 0;
}
