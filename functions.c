#include "main.h"

/**** PRINTS CHAR *****/

/**
 * print_char - print char
 * @types: list of arguments
 * @buffer: buffer array that handles print
 * @flags: calculates active flags
 * @width: width
 * @size: size specifier
 * Return: number of chars printed
 */

int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)

{
	char c = va_arg(types, int);
	return(handle_write_char(c, buffer, flags, width, precision, size));
}

/**** print a string ****/

/**
 * print_string - prints a string
 * @types: list of arguments
 * @buffer: buffer array that handles print
 * @flags: calculates active flags
 * @width: width
 * @size: size specifier
 * Return: number of chars printed
 */

int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)

{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = " ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0]. length);
			for (i = width - length; i > 0; i--)
				write(1, "", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, "", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}

/**** PRINT PERCENTAGE SIGN ****/

/**
 * print_percent - prints a percent sign
 * @types: list of arguments
 * @buffer: buffer array that handles print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: number of chars printed
 */

int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)

{
       	UNUSED(buffer);
       	UNUSED(flags);
       	UNUSED(width);
       	UNUSED(precision);
	UNUSED(size);
	UNUSED(types);
	return (write(1, "%%", 1));
}

/**** PRINT INT ****/

/**
 * print_int - print int
 * @types: list of arguments
 * @buffer: buffer array that handles print
 * @flags: claculates active flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: number of chars printed
 */

int print_int(va_list types. char buffer[],
		int flags. int width, int precision, int size)

{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '\0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
