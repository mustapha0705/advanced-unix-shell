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

/**
 * _itoa - Converts an integer to a string.
 * @n: The integer to be converted.
 *
 * Return: The string representation of the integer.
 */
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	/* Handle the case when the integer is 0 */
	if (n == 0)
		buffer[i++] = '0';
	else
	{
		/* Convert the integer to a string */
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';
	reverse_string(buffer, i);

	return (strdup(buffer));
}

/**
 * reverse_string - Reverses a string in place.
 * @str: The string to be reversed.
 * @len: The length of the string.
 */
void reverse_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	/* Swap characters from the start and end until they meet in the middle */
	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}