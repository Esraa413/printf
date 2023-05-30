#include "main.h"

/* PRINT CHAR */
/**
 * print_char - Prints a char
 * @types: List arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates
 * @width: int Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars
 */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/* PRINT A STRING */
/**
* print_string - Prints a string
 * @types: List arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: int width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars
 */

int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(precision);
	UNUSED(size);
	UNUSED(width);
	UNUSED(flags);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[length] != '\0')
	{
		length = precision;
	}

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}

/* PRINT PERCENT SIGN */
/**
 * print_percent - Prints a percent sign
 * @types: Lista arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: int width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars
 */

int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	UNUSED(buffer);
	UNUSED(types);
	UNUSED(precision);
	return (write(1, "%%", 1));
}

/* PRINT INT */

/**
 * print_int - Print int
 * @types: Lista arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: int width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars
 */

int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va}
