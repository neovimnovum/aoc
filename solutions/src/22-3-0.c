#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    unsigned int priority = 0U;
    unsigned long long bitmap = 0U;
    size_t len = 0U;
    size_t mid = 0U;
    for (char *pack = fgetln(stdin, &len); pack; pack = fgetln(stdin, &len))
    {
        mid = len / 2;
        size_t i = 0U;
        for (; i < mid; i++)
        {
            bitmap |= (1ULL << (pack[i] - 'A'));
        }
        for ( ; i < len; i++ )
        {
            if (bitmap & (1ULL << (pack[i] - 'A')))
            {
                if (pack[i] >= 'a')
                {
                    priority += (1 + (pack[i] - 'a'));
                }
                else
                {
                    priority += (27 + (pack[i] - 'A'));
                }
                break;
            }
        }
        bitmap = 0U;
    }
    printf("%u\n", priority);
    return EXIT_SUCCESS;
}
