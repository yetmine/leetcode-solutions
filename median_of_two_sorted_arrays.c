#include <limits.h>

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int min(int a, int b)
{
	return (a < b) ? a : b;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
	int low;
	int high;
	int maxLeftX;
	int minRightX;
	int maxLeftY;
	int minRightY;
	int partitionX;
	int partitionY;

	if (nums1Size > nums2Size)
		return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);

	low = 0;
	high = nums1Size;

	while (low <= high)
	{
		partitionX = (low + high) / 2;
		partitionY = (nums1Size + nums2Size + 1) / 2 - partitionX;

		maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
		minRightX = (partitionX == nums1Size) ? INT_MAX : nums1[partitionX];

		maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
		minRightY = (partitionY == nums2Size) ? INT_MAX : nums2[partitionY];

		if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
			if ((nums1Size + nums2Size) % 2 == 0) {
				return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
			} else {
				return (double)max(maxLeftX, maxLeftY);
			}
		} else if (maxLeftX > minRightY) {
			high = partitionX - 1;
		} else {
			low = partitionX + 1;
		}
	}
    return 0;
}
