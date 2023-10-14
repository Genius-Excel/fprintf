#include "main.h"

int _putchar(char c)
{
	return (write(1, &c, 1));
}

void print_integer(int val)
{
	int buf_idx = 0;

	int i;

	char buffer[12];

	if (val < 0)
	{
		_putchar('-');
		val = -(val);
	}

	if (val == 0)
	{
		_putchar('0');
		return;
	}

	while (val > 0)
	{
		buffer[buf_idx] = '0' + (val % 10);

		val /= 10;

		buf_idx += 1;
	}

	for (i = buf_idx - 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
	}
}


int _integer_length(int integer)
{
	int actual_length = 0;

	if (integer == 0)
	{
		return (1);
	}

	if (integer < 0)
	{
		actual_length += 1;
		integer = -(integer);
	}

	do {
		actual_length += 1;
		integer /= 10;
	} while (integer > 0);

	return (actual_length);
}
