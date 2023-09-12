#include "monty.h"

/**
 * error_exit_s - functin that exit code
 * @message: message
 * @extra_info: extra_info
 * @code: code exit
*/
void error_exit_s(const char *message, const char *extra_info, int code)
{
	dprintf(STDERR_FILENO, message, extra_info);
	exit(code);
}
/**
 * error_exit_d - functin that exit code
 * @message: message
 * @extra_info: extra_info
 * @code: code exit
*/
void error_exit_d(const char *message, const int extra_info, int code)
{
	dprintf(STDERR_FILENO, message, extra_info);
	exit(code);
}
/**
 * invalid_opcode - functin that exit if the instruction is invalide
 * @line:line number
 * @opcode: opcode
*/
void invalid_opcode(const int line, const char *opcode)
{
	dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line, opcode);
	exit(EXIT_FAILURE);
}
