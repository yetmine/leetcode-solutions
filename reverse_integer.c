#include <limits.h>

int reverse(int x){
	int result = 0;
	int prev;

	while (x) {
		if (result > INT_MAX / 10 || result < INT_MIN /10)
			return 0;
		result = result * 10 + x % 10;
		x /= 10;
	}
	return result;
}
