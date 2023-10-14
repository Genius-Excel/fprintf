#include "main.h"
#include <stdio.h>
int main(void)
{
	int real_printf;

	int cust_printf;

	char *message = "Welcome to the world of programming.";

	real_printf = fprintf(stdout, "%s\n %d\n", message, 356);

	cust_printf = _fprintf(stdout, "%s\n %d\n", message, 356);

	printf("Real: %d\n Cust: %d\n", real_printf, cust_printf);

	return (0);
}
