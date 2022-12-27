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
        printf("%d-%d,%d-%d\n", left_a, right_a, left_b, right_b);
        if (left_a <= left_b && right_a >= right_b)
            count++;
        else if (left_b <= left_a && right_b >= right_a)
            count++;
    }
    printf("\n%zu\n", count);
    return EXIT_SUCCESS;
}
