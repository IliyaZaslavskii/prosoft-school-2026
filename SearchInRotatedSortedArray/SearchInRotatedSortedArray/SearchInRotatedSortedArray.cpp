
#include <iostream>
#include <vector>

int SearchInRotatedSortedArray(std::vector<int>& nums, int target)
{
	int left = 0;
	int n = nums.size();
	int right = n - 1;
	int idx = 0;
	if (nums[right] < nums[left]) {
		int i = 0;
		while (i < right && nums[i] < nums[i + 1]) {
			++i;
		}
		idx = i + 1;
		// Разворачиваем массив
		std::rotate(nums.begin(), nums.begin() + idx, nums.end());
	}
	// Бинарный поиск
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
			// Переводим индекс обратно в индекс исходного массива делением с целочисленным остатком
			return (mid + idx) % n;
		else if (nums[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
};