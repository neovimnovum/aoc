#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    unsigned long long bitmap_A, bitmap_B, bitmap_C;
    size_t i, len_A, len_B, len_C;

    unsigned int priority = 0U;
    char letter = 'A';
    char *pack_A = fgetln(stdin, &len_A);
    char *pack_B = fgetln(stdin, &len_B);
    char *pack_C = fgetln(stdin, &len_C);
    for (; pack_A;
         letter = 'A',
             pack_A = fgetln(stdin, &len_A),
             pack_B = fgetln(stdin, &len_B),
             pack_C = fgetln(stdin, &len_C))
    {
        bitmap_A = bitmap_B = bitmap_C = 0ULL;
        for (i = 0U; pack_A[i] != '\n' && i < len_A; i++)
            bitmap_A |= (1ULL << (pack_A[i] - 'A'));
        for (i = 0U; pack_B[i] != '\n' && i < len_B; i++)
            bitmap_B |= (1ULL << (pack_B[i] - 'A'));
        for (i = 0U; pack_C[i] != '\n' && i < len_C; i++)
            bitmap_C |= (1ULL << (pack_C[i] - 'A'));
        bitmap_A &= bitmap_B;
        bitmap_A &= bitmap_C;
        bitmap_A &= ~(bitmap_A - 1ULL);
        while (bitmap_A != 1ULL)
        {
            letter++;
            bitmap_A >>= 1;
        }
        if (letter >= 'a')
            priority += (1U + (letter - 'a'));
        else
            priority += (27U + (letter - 'A'));
    }
    printf("%u\n", priority);
    return EXIT_SUCCESS;
}
