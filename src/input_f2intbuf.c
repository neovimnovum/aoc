#include <stdlib.h>
#include <stdio.h>

int *
input_f2intbuf(const char * restrict path, size_t *len_p)
{
        size_t len = *len_p;
        if (len == 0)
        {
                printf("Pass non-zero length to input_f2intbuf \n");
                return NULL;
        }
        FILE *input_fp = fopen(path, "r");
        if (input_fp == NULL)
        {
                printf("Error parsing input path in input_f2intbuf() \n");
                return NULL;
        }
        int *outbuf = (int *)calloc(len, sizeof(*outbuf));
        char temp_buf[20] = "";
        for (size_t i = 0U; i < len; i++)
        {
                fgets(temp_buf, 15, input_fp);
                if (!temp_buf[0])
                {
                        *len_p = i;
                        return outbuf;
                }
                else if ('\n' == temp_buf[0])
                {
                        outbuf[i] = -1;
                }
                else
                {
                        sscanf(temp_buf, "%d", outbuf + i);
                }
        }
        fclose(input_fp);
        return outbuf;
}
