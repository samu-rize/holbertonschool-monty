#include "monty.h"
/**
 * main - entry point.
 * @argc: argument counter.
 * @argv: argument vector.
 *
 * Return: 0 on success.
*/
char *arg;
int main(int argc, char **argv)
{


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	FILE *fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	/*Initialize  stack*/
	stack_t *stack = NULL;

	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_number = 0;

	while ((nread = getline(&line, &len, fd)) != -1)
	{
		line_number++;

		/*Tokenize the line into opcode and arguments*/
		char *opcode = strtok(line, DELIM);

		arg = strtok(NULL, DELIM);

		if (opcode != NULL)
		{
			/*Call the appropriate function to execute the instruction*/
			void (*op_func)(stack_t **, unsigned int) = get_op_func(opcode);

			if (op_func != NULL)
			{
				if (strcmp(opcode, "push") == 0)
				{
					if (arg == NULL || !is_number(arg))
					{
						fprintf(stderr, "L%u: usage: push integer\n", line_number);
						fclose(fd);
						free(line);
						free_dlistint(stack);
						return (EXIT_FAILURE);
					}

					op_func(&stack, line_number);
				}
				else
				{
					op_func(&stack, line_number);
				}
			}
			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				fclose(fd);
				free(line);
				free_dlistint(stack);
				return (EXIT_FAILURE);
			}
		}
	}

	/*Cleanup and close the file*/
	fclose(fd);
	free(line);
	free_dlistint(stack);

	return (EXIT_SUCCESS);
}
