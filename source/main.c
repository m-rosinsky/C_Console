/*!
 * @file source/main.c
 *
 * @brief This file contains the main function of the program.
 * 
 *          It is responsible for instantiation of the console context,
 *              as well as deallocation of the console.
 */

#include <stdio.h>                              // printf()

#include "console.h"

#define HISTORY_MAX 5

int
main ()
{
    // Create the console context.
    console_t * p_console = console_create(HISTORY_MAX);
    if (NULL == p_console)
    {
        printf("Failed to instantiate console\n");
        return 1;
    }

    // Run the console context.
    console_run(p_console);

    // Deallocate the console context.
    if (-1 == console_destroy(p_console))
    {
        printf("Failed to destroy console\n");
        return 1;
    }

    printf("Exited with success\n");
    return 0;
}

/***   end of file   ***/
