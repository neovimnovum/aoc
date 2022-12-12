#include "libaoc.h"
#include <stdio.h>

int
main(void)
{
        size_t len = 2237U;
        int *buf = input_f2intbuf("input", &len);
        unsigned int max = 0U;
        unsigned int cur = 0U;
        for ( size_t i = 0U; i < len; i++ )
        {
                if (buf[i] == -1)
                {
                        if (cur > max)
                        {
                                max = cur;
                        }
                        cur = 0U;
                }
                else
                {
                        cur += buf[i];
                }
        }
        free(buf);
        printf("%u", max);
        return EXIT_SUCCESS;
}
