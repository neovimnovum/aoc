#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    size_t count = 0U;
    int left_a, right_a, left_b, right_b;
    left_a = right_a = left_b = right_b = 0;
    while (scanf("%d-%d,%d-%d\n", &left_a, &right_a, &left_b, &right_b) != EOF)
    {
        if (left_a <= left_b && right_a >= left_b)
            count++;
        else if (left_a >= left_b && left_a <= right_b)
            count++;
    }
    printf("\n%zu\n", count);
    return EXIT_SUCCESS;
}
