#include "main.h"

int _fprintf(FILE *stream, const char *format, ...)
{
	int i;

	int printed_chars = 0;

	va_list specifier_args;

	va_start(specifier_args, format);

	(void)stream;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i += 1; /*move to the next character index*/

			if (format[i] == '%')
			{
				_putchar('%');
			}
			else if (format[i] == 'c')
			{
				char c_val = va_arg(specifier_args, int);

				if (c_val)
				{
					_putchar(c_val);
					printed_chars += 1;
				}
				
			}
			else if (format[i] == 's')
			{
				char *str_val = va_arg(specifier_args, char *);

				int str_idx = 0;

				int str_len = 0;

				for (str_idx = 0; str_val[str_idx] != '\0'; str_idx++)
				{
					_putchar(str_val[str_idx]);
				}

				while (*str_val != '\0')
				{
					str_len += 1;

					str_val += 1;
				}

				printed_chars += str_len;
			}
			else if (format[i] == 'd')
			{
				int num_len = 0;

				int dec_val = va_arg(specifier_args, int);

				if (!dec_val)
				{
					return (-1);
				}

				num_len = _integer_length(dec_val);

				print_integer(dec_val);
				printed_chars += num_len;
			}
		}
		else
		{
			_putchar(format[i]);
			printed_chars += 1;
		}
	}

	va_end(specifier_args);

	return (printed_chars);

}
