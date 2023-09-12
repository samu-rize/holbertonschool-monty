#include "monty.h"
/**
 * is_number - checks if a given string represents a valid integer.
 * @str: pointer to the string to be checked.
 *
 * Return:  true if the string is a valid integer false otherwise.
 */

bool is_number(const char *str)
{
	if (str == NULL || *str == '\0')
	{
		return (false);
	}

	int i = 0;

	if (str[0] == '-')
	{
		i = 1;
	}
	for (i = 1; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
		{
			return (false);
		}
	}
	return (true);
}
