#include "libaoc.h"
#include <stdio.h>
#include <stdlib.h>

#define SWAP(SRC, DST, SWP) (SWP = DST,DST = SRC,SRC = SWP)

int
main(void)
{
        size_t len = 2237U;
        int *buf = input_f2intbuf("input", &len);
        unsigned int first = 0U;
        unsigned int second = 0U;
        unsigned int third = 0U;
        unsigned int swap = 0U;
        unsigned int cur = 0U;
        for ( size_t i = 0U; i <= len; i++ )
        {
                if (i == len || buf[i] == -1)
                {
                        if (buf[i] != -1)
                        {
                                cur += buf[i];
                        }
                        printf("Candidate: %u\n", cur);
                        printf("First: %u\n", first);
                        printf("Second: %u\n", second);
                        printf("Third: %u\n\n", third);
                        if (cur > first)
                        {
                                SWAP(cur, first, swap);
                        }
                        if (cur > second)
                        {
                                SWAP(cur, second, swap);
                        }
                        if (cur > third)
                        {
                                SWAP(cur, third, swap);
                        }
                        printf("First after: %u\n", first);
                        printf("Second after: %u\n", second);
                        printf("Third after: %u\n\n\n", third);
                        cur = 0U;
                }
                else
                {
                        cur += buf[i];
                }
        }
        free(buf);
        printf("%u", first + second + third);
        return EXIT_SUCCESS;
}
