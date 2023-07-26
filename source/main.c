/*!
 * @file source/main.c
 *
 * @brief This file contains the main function of the program.
 * 
 *          It is responsible for instantiation of the console context,
 *              as well as deallocation of the console.
 */

#include <stdio.h>                              // printf()

#include "history.h"

int
main ()
{
    history_t * p_hist = history_create(5);
    if (NULL == p_hist)
    {
        printf("create\n");
        return 1;
    }

    if ((-1 == history_push(p_hist, "command 1")) ||
        (-1 == history_push(p_hist, "command 2")) ||
        (-1 == history_push(p_hist, "command 3")) ||
        (-1 == history_push(p_hist, "command 4")) ||
        (-1 == history_push(p_hist, "command 5")) ||
        (-1 == history_push(p_hist, "command 6")))
    {
        printf("push\n");
        return 1;
    }

    for (size_t i = 0; i < p_hist->size; ++i)
    {
        printf("[%lu]: '%s'\n", i, p_hist->pp_data[i]);
    }

    if (-1 == history_destroy(p_hist))
    {
        printf("destroy\n");
        return 1;
    }

    printf("success\n");
    return 0;
}

/***   end of file   ***/
