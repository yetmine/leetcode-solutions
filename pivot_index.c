
int pivotIndex(int* nums, int numsSize) {
	int left = 0;
	int sum = 0;
	int i = 0;

	while (i < numsSize)
		sum += nums[i++];
	i = -1;
	while (++i < numsSize)
	{
		if (left == sum - nums[i] - left)
			return i;
		left += nums[i];
	}
	return -1;
}

