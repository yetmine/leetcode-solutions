
#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char * s){
	int arr[256];
	int i = 0;
	int max = 0;
	int start = -1;

	memset((void*)arr, -1, 256*sizeof(int));
	while(s[i])
	{
		if (arr[s[i]] > start)
			start = arr[s[i]];
		arr[s[i]] = i;
		max = max > i - start ? max : i - start;
		i++;
	}
	return max;
}

void test(int actual, int expected)
{
	if (actual != expected)
		printf("Test failed: expected %d, got %d", expected, actual);
	else
		printf("Success: expected %d, got %d", expected, actual);
	printf("\n");
}

int main()
{
	char str1[] = "cdd";
	char str2[] = "bbbbb";

	test(lengthOfLongestSubstring(str1), 3);
	test(lengthOfLongestSubstring(str2), 1);
}
