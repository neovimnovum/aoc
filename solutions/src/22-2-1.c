#include "libaoc.h"
#include <stdio.h>

int
main(void)
{
    unsigned int score = 0U;
    unsigned int score_table[3][3] = { { 4U, 8U, 3U }, { 1U, 5U, 9U }, { 7U, 2U, 6U } };
    for (int op_move = getchar(), my_move = getchar(); op_move != EOF && my_move != EOF; op_move = getchar(), my_move = getchar())
    {
        score += score_table[op_move - 'A'][(my_move - 'Y' + (op_move - 'A')) < 0 ? 2 : (my_move - 'Y' + (op_move - 'A')) % 3];
    }
    printf("%u", score);
    return EXIT_SUCCESS;
}
