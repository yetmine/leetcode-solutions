
#include <limits.h>

int myAtoi(char * str){
	long res = 0;
	int sign = 1;
	int n;

	while (*str == ' ')
		str++;

	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	else if (*str == '+')
		str++;

	while (*str >= '0' && *str <= '9')
	{
		n = *str - '0';
		res = res * 10 + n;
		str++;
		if (res * sign > INT_MAX)
			return INT_MAX;
		if (res * sign < INT_MIN)
			return INT_MIN;
	}
	return sign * res;
}
