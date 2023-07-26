/*!
 * @file source/main.c
 *
 * @brief This file contains the main function of the program.
 * 
 *          It is responsible for instantiation of the console context,
 *              as well as deallocation of the console.
 */

#include <stdio.h>                              // printf()

#include "common/queue.h"

int
main ()
{
    queue_t * p_q = queue_create();
    if (NULL == p_q)
    {
        printf("create\n");
        return 1;
    }

    int nums[5] = {1,2,3,4,5};
    for (size_t i = 0; i < 5; ++i)
    {
        if (-1 == queue_enq(p_q, nums + i))
        {
            printf("enq\n");
            return 1;
        }
    }

    int * p_i = NULL;
    printf("[");
    while (0 != p_q->size)
    {
        p_i = queue_deq(p_q);
        if (NULL == p_i)
        {
            printf("deq\n");
            return 1;
        }
        printf("%d", *p_i);
        if (0 != p_q->size)
        {
            printf(", ");
        }
    }
    printf("]\n");

    if (-1 == queue_destroy(p_q))
    {
        printf("destroy\n");
        return 1;
    }
    p_q = NULL;

    printf("success\n");
    return 0;
}

/***   end of file   ***/
