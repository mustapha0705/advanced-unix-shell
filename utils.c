#include "shell.h"

/**
 * freearray2D - Frees a 2D array of strings.
 * @array: The 2D array to be freed.
 */
void free2Darray(char **array)
{
    int i;

    if (!array)
    {
        return;
    }

    for (i = 0; array[i]; i++)
    {
        free(array[i]);
        array[i] = NULL;
    }

    free(array);
    array = NULL;
}